// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

#pragma once

// UNREAL ENGINE INCLUDES
#include <CoreMinimal.h>
#include <ModuleManager.h>

class FToolBarBuilder;
class FMenuBuilder;

static FName BatchRendererTabName = FName("BatchRenderer");

/* The FBatchRendererModule Implments the IModuleInterface and 
 * is the module class driving our BatchRenderer Plugin */
class FBatchRendererModule : public IModuleInterface
{
	// ********************
	// * IMODULEINTERFACE *
	// ********************
	public:
		//! StartupModule (Called at Startup)
		virtual void StartupModule() override;
		//! ShutdownModule (Called at Shutdown)
		virtual void ShutdownModule() override;
	
	protected:
		// BatchRendererTabName
		FName BatchRendererTabName;
	
	// *****************
	// * GUI CALLBACKS *
	// *****************
	public:
		// OnSpawnPluginTab
		TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);
	
	protected:
		// This function will be bound to Command (by default it will bring up plugin window)
		void PluginButtonClicked();
		// AddToolbarExtension
		void AddToolbarExtension(FToolBarBuilder& Builder);
		// AddMenuExtension
		void AddMenuExtension(FMenuBuilder& Builder);
		// OnButtonClicked 
		FReply OnButtonClicked();


	// *******
	// * ??? *
	// *******
	public:
		// Members and Methods

	protected:
		// PluginCommands
		TSharedPtr<class FUICommandList> PluginCommands;
};