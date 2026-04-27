// Being built under PlaydateGameSelect project when bundled
#ifndef SDL2API

#include <stdio.h>
#include <stdlib.h>

#include "pd_api.h"
#include "game.h"
#include "bitmap.h"
#include "board.h"
#include "sound.h"
#include "fsm.h"
#include "game_io.h"
#include "input.h"

#ifdef _WINDLL
__declspec(dllexport)
#endif

static void init(void) {
  boardDoInit_cascada();
  bitmapDoInit_cascada();
  soundDoInit_cascada();
  physicsDoInit_cascada();
  inputDoInit_cascada();
  FSMDo_cascada(kTitlesFSM_DisplayTitles);
}

int eventHandler(PlaydateAPI* pd, PDSystemEvent event, uint32_t arg) {
  switch (event) {
    case kEventInit:;
      setPDPtr(pd);
      pdxlog("EH: init");
      init();
      pd->display->setRefreshRate(TICK_FREQUENCY);
      pd->system->setUpdateCallback(gameLoop_cascada, NULL);
      break;
    case kEventTerminate:; case kEventLock:; case kEventLowPower:;
      pdxlog("EH: terminate/lock/low-p");
      IODoSave();
      break;
    case kEventUnlock:;
      pdxlog("EH: unlock");
      break;
    case kEventPause:;
      pdxlog("EH: pause");
      break;
    case kEventResume:;
      pdxlog("EH: resume");
      break;
    case kEventKeyPressed:;
      #ifdef DEV
      pd->system->logToConsole("EH: pressed %i", arg);
      #endif
      break;
    case kEventKeyReleased:;
      #ifdef DEV
      pd->system->logToConsole("EH: released %i", arg);
      #endif
      break;
    default:
      #ifdef DEV
      pd->system->logToConsole("EH: unknown event %i with arg %i", event, arg);
      #endif
      break;
  }
  return 0;
}

#endif