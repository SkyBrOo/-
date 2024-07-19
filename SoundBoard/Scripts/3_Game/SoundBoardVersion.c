class SoundBoardVersion
{
    const static string VERSION = "6.0";
    
    static void LogVersion()
    {
        Print("SoundBoard Mod Version: " + VERSION);
    }
    
    static bool IsVersionCompatible(string clientVersion)
    {
        return clientVersion == VERSION;
    }
}