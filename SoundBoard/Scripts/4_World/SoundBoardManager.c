class SoundBoardManager
{
    private ref SoundBoardSettings m_Settings;
    private const string MUSIC_PATH = "$CurrentDir:SoundBoard/Music/";
    private ref array<string> m_SongList;
    private ref array<string> m_CurrentPlaylist;
    private int m_CurrentSongIndex;
    
    void SoundBoardManager()
    {
        m_Settings = new SoundBoardSettings();
        m_Settings.LoadSettings();
        m_SongList = new array<string>;
        m_CurrentPlaylist = new array<string>;
        m_CurrentSongIndex = 0;
        LoadSongList();
        
        // Enregistrement des RPCs
        GetRPCManager().AddRPC("SoundBoard", "PlaySong", this, SingleplayerExecutionType.Server);
        GetRPCManager().AddRPC("SoundBoard", "NextSong", this, SingleplayerExecutionType.Server);
        GetRPCManager().AddRPC("SoundBoard", "PreviousSong", this, SingleplayerExecutionType.Server);
        
        // Enregistrement de l'événement de démarrage du serveur
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.OnServerStart, 1000, false);
    }
    
    void LoadSongList()
    {
        m_SongList.Clear();
        string fileName;
        FileAttr fileAttr;
        FindFileHandle fileHandle = FindFile(MUSIC_PATH + "*.ogg", fileName, fileAttr, FindFileFlags.ALL);
        
        if (fileHandle != 0)
        {
            do
            {
                if (fileName != "." && fileName != "..")
                {
                    m_SongList.Insert(fileName);
                }
            } while (FindNextFile(fileHandle, fileName, fileAttr));
            
            CloseFindFile(fileHandle);
        }
        else
        {
            Print("SoundBoard: Error - Unable to open directory: " + MUSIC_PATH);
        }
    }
    
    void PlaySong(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Param2<string, array<string>> data;
        if (!ctx.Read(data)) return;
        
        string songName = data.param1;
        array<string> playerNames = data.param2;
        
        if (m_SongList.Find(songName) == -1)
        {
            Print("SoundBoard: Song not found in the list - " + songName);
            return;
        }
        
        float distance = m_Settings.GetSoundDistance();
        float volume = m_Settings.GetVolume();
        
        foreach (string playerName : playerNames)
        {
            PlayerBase player = PlayerBase.Cast(GetPlayerByName(playerName));
            if (player)
            {
                GetGame().GetSoundScene().PlaySound(songName, player.GetPosition(), distance, volume);
            }
        }
        
        m_CurrentPlaylist = playerNames;
        m_CurrentSongIndex = m_SongList.Find(songName);
    }
    
    void NextSong(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (m_CurrentPlaylist.Count() == 0) return;
        
        m_CurrentSongIndex++;
        if (m_CurrentSongIndex >= m_SongList.Count())
        {
            m_CurrentSongIndex = 0;
        }
        
        PlaySong(CallType.Server, null, null, null);
    }
    
    void PreviousSong(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (m_CurrentPlaylist.Count() == 0) return;
        
        m_CurrentSongIndex--;
        if (m_CurrentSongIndex < 0)
        {
            m_CurrentSongIndex = m_SongList.Count() - 1;
        }
        
        PlaySong(CallType.Server, null, null, null);
    }
    
    array<string> GetSongList()
    {
        return m_SongList;
    }
    
    array<string> GetPlayerList()
    {
        array<string> playerNames = new array<string>;
        array<Man> players = new array<Man>;
        GetGame().GetPlayers(players);
        
        foreach (Man player : players)
        {
            playerNames.Insert(player.GetIdentity().GetName());
        }
        
        return playerNames;
    }
    
    void OnServerStart()
    {
        Print("SoundBoard mod initialized.");
        SoundBoardVersion.LogVersion();
    }
    
    // Fonction utilitaire pour obtenir un joueur par son nom
    private PlayerBase GetPlayerByName(string name)
    {
        array<Man> players = new array<Man>;
        GetGame().GetPlayers(players);
        
        foreach (Man man : players)
        {
            PlayerBase player = PlayerBase.Cast(man);
            if (player && player.GetIdentity().GetName() == name)
            {
                return player;
            }
        }
        
        return null;
    }
}