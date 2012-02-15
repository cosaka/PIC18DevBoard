/*
   File:   hardware_profile.h
   Author: Cesar Osaka

   Created on 11 de Janeiro de 2012, 10:10
 */

#ifndef HARDWARE_PROFILE_H
#define HARDWARE_PROFILE_H

#if defined _HARDWARE_PIC18DEVBOARD
#include "hardware_PIC18DevBoard.h"
#elif defined _HARDWARE_PICKIT3DEBUGEXPRESS
#include "hardware_PICkit3DebugExpress.h"
#endif

void hw_basic_setup(void);

#endif // HARDWARE_PROFILE_H
