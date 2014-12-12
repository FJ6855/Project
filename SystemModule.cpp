#include "SystemModule.h"

SystemState SystemModule::systemState = STARTMENU;
SystemState SystemModule::lastSystemState = STARTMENU;

SystemState SystemModule::getState()
{
    return systemState;
}

void SystemModule::setState(SystemState newSystemState)
{
    lastSystemState = systemState;
    systemState = newSystemState;
}
