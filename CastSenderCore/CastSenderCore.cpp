#include "CastSenderCore.h"
#include "../LogModule/Loglib.h"
extern "C" {
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
#include "libavutil/avutil.h"
}


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