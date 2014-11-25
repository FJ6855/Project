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
	static SystemState systemState;
	SystemModule();
	~SystemModule();
};

#endif
