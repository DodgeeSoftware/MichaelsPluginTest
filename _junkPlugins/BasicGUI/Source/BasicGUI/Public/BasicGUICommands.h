// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "BasicGUIStyle.h"

class FBasicGUICommands : public TCommands<FBasicGUICommands>
{
public:

	FBasicGUICommands()
		: TCommands<FBasicGUICommands>(TEXT("BasicGUI"), NSLOCTEXT("Contexts", "BasicGUI", "BasicGUI Plugin"), NAME_None, FBasicGUIStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};