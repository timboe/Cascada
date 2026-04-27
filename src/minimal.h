#pragma once

enum FSM_t {
  kFSM_INITIAL,
  kTitlesFSM_DisplayTitles,
  kTitlesFSM_DisplayTitlesWFadeIn,
  kTitlesFSM_TitlesToChoosePlayer,
  kTitlesFSM_ChoosePlayer,
  kTitlesFSM_ChoosePlayerToChooseLevel,
  kTitlesFSM_ChooseLevel,
  kTitlesFSM_ChooseLevelToChooseHole,
  kTitlesFSM_ChooseLevelToChoosePlayer,
  kTitlesFSM_ChooseHole,
  kTitlesFSM_ChooseHoleWFadeIn,
  kTitlesFSM_ChooseHoleToLevelTitle,
  kTitlesFSM_ChooseHoleToChooseLevel,
  kTitlesFSM_ToTitleCreditsTitle,
  kFSM_SPLIT_TitlesGame,
  kGameFSM_DisplayLevelTitle,
  kGameFSM_DisplayLevelTitleWFadeIn,
  kGameFSM_LevelTitleToStart,
  kGameFSM_TutorialScrollDown,
  kGameFSM_TutorialScrollUp,
  kGameFSM_TutorialFireMarble,
  kGameFSM_TutorialGetSpecial,
  kGameFSM_TutorialGetRequired,
  kGameFSM_GameFadeOutQuit,
  kGameFSM_GameFadeOutReset,
  kGameFSM_AimMode,
  kGameFSM_AimModeScrollToTop,
  kGameFSM_BallInPlay, // START OF BALL-IN-PLAY
  kGameFSM_PlayCredits, // Place after BallInPlay 
  kGameFSM_BallStuck,
  kGameFSM_CloseUp,
  kGameFSM_WinningToastA,
  kGameFSM_WinningToastB,
  kGameFSM_BallGutter, // END OF BALL-IN-PLAY
  kGameFSM_GutterToTurret,
  kGameFSM_TurretLower,
  kGameFSM_GutterToScores,
  kGameFSM_ScoresAnimationA,
  kGameFSM_ScoresAnimationB,
  kGameFSM_DisplayScores,
  kGameFSM_ScoresToTryAgain,
  kGameFSM_ScoresToSplash,
  kGameFSM_ToGameCreditsTitle,
  kNFSMModes
};


void boardDoInit_cascada(void);
void bitmapDoInit_cascada(void);
void soundDoInit_cascada(void);
void physicsDoInit_cascada(void);
void inputDoInit_cascada(void);

int gameLoop_cascada(void* data);

void FSMDo_cascada(const enum FSM_t transitionTo);