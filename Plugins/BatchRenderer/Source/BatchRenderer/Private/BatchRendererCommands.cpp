// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.
// Author: Shem Taylor

#include "BatchRendererCommands.h"

#define LOCTEXT_NAMESPACE "FBatchRendererModule"

void FBatchRendererCommands::RegisterCommands()
{
	// Open The Plugin Window
	UI_COMMAND(this->OpenPluginWindow,
			   "BatchRenderer", // This becomes the name of the button added to the Unreal Engine ToolBar and the Window menu Item
			   "Bring up BatchRenderer window", // This is the ToolTip when we hover over the Unreal Engine Toolbar button or the item in the WindowMenu
			   EUserInterfaceActionType::Button, // EUserInterfaceActionType::Button seems to be the only valid type which adds content to the Toobar
			   FInputGesture() // ??
	);
	//// MyTestCommand
	//UI_COMMAND(this->MyTestCommand, // Local Command Variable
	//		   "NotSureWhatThisIs1", // This becomes the name of the button added to the Unreal Engine ToolBar and the Window menu Item
	//		   "NotSureWhatThisIs2", // This is the ToolTip when we hover over the Unreal Engine Toolbar button or the item in the WindowMenu
	//		   EUserInterfaceActionType::Button, // EUserInterfaceActionType::Button seems to be the only valid type which adds content to the Toobar
	//		   FInputGesture() // ??
	//);
}

#undef LOCTEXT_NAMESPACE
