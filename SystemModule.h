#ifndef SYSTEMMODULE_H
#define SYSTEMMODULE_H

enum SystemState
{
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
    
    static SystemState systemState; 
};

#endif
