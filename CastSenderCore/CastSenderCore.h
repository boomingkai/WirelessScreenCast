#pragma once

#ifdef CASTSENDERCORE_EXPORTS
#define CASTSENDERCORE_API __declspec(dllexport)
#else
#define CASTSENDERCORE_API __declspec(dllimport)
#endif

extern "C" {

    CASTSENDERCORE_API bool Init();
    CASTSENDERCORE_API bool UnInit();
}