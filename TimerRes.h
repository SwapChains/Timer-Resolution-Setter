#pragma once

#include <windows.h>
#include <winternl.h>

#pragma comment(lib, "ntdll.lib")

extern "C" NTSYSAPI NTSTATUS NTAPI NtSetTimerResolution(ULONG DesiredResolution, BOOLEAN SetResolution, PULONG CurrentResolution);

class TimerResolution
{
public:
    static ULONG MaxResolution;
    static ULONG MinResolution;
    static ULONG OldResolution;
    static ULONG CurResolution;

    static void InitQuery();

    static ULONG SetToMinimum();

    static ULONG SetToMaximum();
};