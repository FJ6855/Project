#ifndef SYSTEMMODULE_H
#define SYSTEMMODULE_H

enum SystemState
{
    START_GAME,
    PLAY,
    PAUSE,
    WRITENAMEMENU,
    DEAD,
    STARTMENU,
    HIGHSCORE,
    HELP,
    QUIT
};

class SystemModule
{
public:
    SystemModule() {}   
    
    ~SystemModule() = default;
    
    SystemState getState();
    void setState(SystemState newSystemState);

    static SystemState lastSystemState; 
    static SystemState systemState; 
};

#endif
