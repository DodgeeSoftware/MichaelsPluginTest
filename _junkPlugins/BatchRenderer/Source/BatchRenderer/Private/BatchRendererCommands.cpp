// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

#include "BatchRendererCommands.h"

#define LOCTEXT_NAMESPACE "FBatchRendererModule"

void FBatchRendererCommands::RegisterCommands()
{
	// Open The Plugin Window
	UI_COMMAND(this->OpenPluginWindow, "BatchRenderer", "Bring up BatchRenderer window", EUserInterfaceActionType::Button, FInputGesture());
	// MyTestCommand
	UI_COMMAND(this->MyTestCommand, // Local Command Variable
			   "NotSureWhatThisIs1", // ??
			   "NotSureWhatThisIs2", // ??
			   EUserInterfaceActionType::Button, // Type of Action ?? Not sure why this is relevent
			   FInputGesture() // ??
	);
}

#undef LOCTEXT_NAMESPACE
