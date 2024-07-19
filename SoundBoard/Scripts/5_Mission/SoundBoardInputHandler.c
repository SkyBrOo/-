class SoundBoardInputHandler
{
    private ref SoundBoardSettings m_Settings;
    
    void SoundBoardInputHandler()
    {
        m_Settings = new SoundBoardSettings();
        m_Settings.LoadSettings();
        
        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }
    
    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
    {
        if (rpc_type == ERPCs.RPC_SOUND_BOARD_TOGGLE)
        {
            ToggleSoundBoardMenu();
        }
    }
    
    bool OnKeyPress(int key)
    {
        if (!GetGame().IsServer() && GetGame().GetUIManager().GetMenu() == NULL)
        {
            if (key == m_Settings.GetToggleKey())
            {
                GetRPCManager().SendRPC("SoundBoard", "ToggleSoundBoard", null, true);
                return true;
            }
            else if (key == m_Settings.GetNextSongKey())
            {
                GetRPCManager().SendRPC("SoundBoard", "NextSong", null, true);
                return true;
            }
            else if (key == m_Settings.GetPreviousSongKey())
            {
                GetRPCManager().SendRPC("SoundBoard", "PreviousSong", null, true);
                return true;
            }
        }
        return false;
    }
    
    void ToggleSoundBoardMenu()
    {
        if (!GetGame().GetUIManager().IsMenuOpen(MENU_SOUND_BOARD))
        {
            GetGame().GetUIManager().ShowScriptedMenu(new SoundBoardMenu(), NULL);
        }
        else
        {
            GetGame().GetUIManager().CloseMenu(MENU_SOUND_BOARD);
        }
    }
}