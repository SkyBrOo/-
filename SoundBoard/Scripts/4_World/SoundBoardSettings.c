class SoundBoardSettings
{
    [Serialized] private float m_SoundDistance;
    [Serialized] private float m_Volume;
    [Serialized] private int m_ToggleKey;
    [Serialized] private int m_NextSongKey;
    [Serialized] private int m_PreviousSongKey;
    
    void SoundBoardSettings()
    {
        SetDefaultValues();
    }
    
    private void SetDefaultValues()
    {
        m_SoundDistance = 100.0;
        m_Volume = 1.0;
        m_ToggleKey = KeyCode.KC_K;
        m_NextSongKey = KeyCode.KC_RIGHT;
        m_PreviousSongKey = KeyCode.KC_LEFT;
    }
    
    float GetSoundDistance() { return m_SoundDistance; }
    void SetSoundDistance(float distance) { m_SoundDistance = distance; }
    
    float GetVolume() { return m_Volume; }
    void SetVolume(float volume) { m_Volume = volume; }
    
    int GetToggleKey() { return m_ToggleKey; }
    void SetToggleKey(int key) { m_ToggleKey = key; }
    
    int GetNextSongKey() { return m_NextSongKey; }
    void SetNextSongKey(int key) { m_NextSongKey = key; }
    
    int GetPreviousSongKey() { return m_PreviousSongKey; }
    void SetPreviousSongKey(int key) { m_PreviousSongKey = key; }
    
    void SaveSettings()
    {
        JsonFileLoader<SoundBoardSettings>.JsonSaveFile("$profile:SoundBoard/settings.json", this);
    }
    
    void LoadSettings()
    {
        if (!JsonFileLoader<SoundBoardSettings>.JsonLoadFile("$profile:SoundBoard/settings.json", this))
        {
            Print("SoundBoard: Configuration file not found. Using default values.");
            SetDefaultValues();
        }
    }
}