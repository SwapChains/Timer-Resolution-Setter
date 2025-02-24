#include "TimerRes.h"

ULONG TimerResolution::MaxResolution;
ULONG TimerResolution::MinResolution;
ULONG TimerResolution::OldResolution;
ULONG TimerResolution::CurResolution;

void TimerResolution::InitQuery()
{
    NtQueryTimerResolution(&MaxResolution, &MinResolution, &OldResolution);
}

ULONG TimerResolution::SetToMinimum()
{
    NtSetTimerResolution(MinResolution, TRUE, &CurResolution);
    return CurResolution;
}

ULONG TimerResolution::SetToMaximum()
{
    NtSetTimerResolution(MaxResolution, TRUE, &CurResolution);
    return CurResolution;
}