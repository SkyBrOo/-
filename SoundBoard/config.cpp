class CfgPatches
{
    class SoundBoard
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgMods
{
    class SoundBoard
    {
        dir = "SoundBoard";
        picture = "SoundBoard/gui/images/logo.paa";
        action = "";
        hideName = 0;
        hidePicture = 0;
        name = "SoundBoard";
        credits = "🆅🅴🅶🅰🆂";
        author = "🆅🅴🅶🅰🆂";
        authorID = "76561199088185222";
        version = "6.1";
        extra = 0;
        type = "mod";
        
        dependencies[] = {"Game", "World", "Mission"};
        
        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = {"SoundBoard/Scripts/3_Game"};
            };
            class worldScriptModule
            {
                value = "";
                files[] = {"SoundBoard/Scripts/4_World"};
            };
            class missionScriptModule
            {
                value = "";
                files[] = {"SoundBoard/Scripts/5_Mission"};
            };
        };
    };
};