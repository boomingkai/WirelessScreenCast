#include "CastSenderCore.h"
#include "../LogModule/Loglib.h"

bool Init()
{
    InitLogger("../../log.txt");
    return true;
}

bool UnInit()
{
    ShutdownLogger();
    return true;
}