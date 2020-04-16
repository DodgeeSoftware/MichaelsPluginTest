// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.
// Author: Shem Taylor

#pragma once

// UNREAL ENGINE INCLUDES
#include <CoreMinimal.h>
#include <Framework/Commands/Commands.h>

// MYPLUGIN INCLUDES
#include "BatchRendererStyle.h"

/* ??? */
class FBatchRendererCommands : public TCommands<FBatchRendererCommands>
{
	// ******************************
	// * CONSTRUCTORS / DESTRUCTORS *
	// ******************************
	public:
		//! Constructor
		FBatchRendererCommands()
			: TCommands<FBatchRendererCommands>(TEXT("BatchRenderer"), // Context Name
												NSLOCTEXT("Contexts", "BatchRenderer", "BatchRenderer Plugin"), // Context Description
												NAME_None, // Context Parent
												FBatchRendererStyle::GetStyleSetName() // Style Name
												)
		{

		}
	
	protected:
		// Methods and Members

	// *************************
	// * TCOMMANDS<> INTERFACE *
	// *************************
	public:
		//! A function which registers our Commands
		virtual void RegisterCommands() override;

	// List of Commands [These are used externally and need to be public]
	public:
		// OpenPluginWindow
		TSharedPtr<FUICommandInfo> OpenPluginWindow;
		//// MyTestCommand
		//TSharedPtr<FUICommandInfo> MyTestCommand;

	protected:
		// Methods and Members
};