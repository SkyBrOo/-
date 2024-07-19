class SoundBoardMenu extends UIScriptedMenu
{
    private Widget m_Root;
    private ButtonWidget m_PlayButton;
    private ButtonWidget m_NextButton;
    private ButtonWidget m_PreviousButton;
    private TextListboxWidget m_SongList;
    private TextListboxWidget m_PlayerList;
    
    private ref SoundBoardManager m_Manager;
    
    void SoundBoardMenu()
    {
        m_Manager = new SoundBoardManager();
    }
    
    override Widget Init()
    {
        m_Root = GetGame().GetWorkspace().CreateWidgets("SoundBoard/gui/layouts/SoundBoardMenu.layout");
        
        m_PlayButton = ButtonWidget.Cast(m_Root.FindAnyWidget("PlayButton"));
        m_NextButton = ButtonWidget.Cast(m_Root.FindAnyWidget("NextButton"));
        m_PreviousButton = ButtonWidget.Cast(m_Root.FindAnyWidget("PreviousButton"));
        m_SongList = TextListboxWidget.Cast(m_Root.FindAnyWidget("SongList"));
        m_PlayerList = TextListboxWidget.Cast(m_Root.FindAnyWidget("PlayerList"));
        
        UpdateSongList();
        UpdatePlayerList();
        
        return m_Root;
    }
    
    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (w == m_PlayButton)
        {
            PlaySelectedSong();
            return true;
        }
        else if (w == m_NextButton)
        {
            GetRPCManager().SendRPC("SoundBoard", "NextSong", null, true);
            return true;
        }
        else if (w == m_PreviousButton)
        {
            GetRPCManager().SendRPC("SoundBoard", "PreviousSong", null, true);
            return true;
        }
        return super.OnClick(w, x, y, button);
    }
    
    void UpdateSongList()
    {
        m_SongList.ClearItems();
        array<string> songs = m_Manager.GetSongList();
        foreach (string song : songs)
        {
            m_SongList.AddItem(song, NULL, 0);
        }
    }
    
    void UpdatePlayerList()
    {
        m_PlayerList.ClearItems();
        array<string> players = m_Manager.GetPlayerList();
        foreach (string player : players)
        {
            m_PlayerList.AddItem(player, NULL, 0);
        }
    }
    
    void PlaySelectedSong()
    {
        string selectedSong = m_SongList.GetSelectedRow();
        array<string> selectedPlayers = new array<string>;
        
        for (int i = 0; i < m_PlayerList.GetNumItems(); i++)
        {
            if (m_PlayerList.IsSelected(i))
            {
                selectedPlayers.Insert(m_PlayerList.GetItem(i));
            }
        }
        
        if (selectedSong && selectedPlayers.Count() > 0)
        {
            GetRPCManager().SendRPC("SoundBoard", "PlaySong", new Param2<string, array<string>>(selectedSong, selectedPlayers), true);
        }
    }
}