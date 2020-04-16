// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "BasicGUICommands.h"

#define LOCTEXT_NAMESPACE "FBasicGUIModule"

void FBasicGUICommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "BasicGUI", "Bring up BasicGUI window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
