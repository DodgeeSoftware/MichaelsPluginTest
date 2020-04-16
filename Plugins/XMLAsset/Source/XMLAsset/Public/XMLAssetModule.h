// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

#pragma once

// UNREAL ENGINE Includes
#include <CoreMinimal.h>
#include <ModuleManager.h>
#include <IAssetTools.h>
#include <AssetToolsModule.h>
#include <Containers/Array.h>
#include <ISettingsModule.h>
#include <ISettingsSection.h>
#include <Modules/ModuleInterface.h>
#include <Modules/ModuleManager.h>
#include <Templates/SharedPointer.h>
#include <Toolkits/AssetEditorToolkit.h>

// PLUGIN Includes
#include "XMLAssetActions.h"
#include "XMLAssetStyle.h"
#include "XMLAssetEditorSettings.h"

#define LOCTEXT_NAMESPACE "FXMLAssetEditorModule"

/* The FXMLAssetModule is the core Module of our XML Plugin */
class FXMLAssetModule : public IModuleInterface
{
	// ********************
	// * IMODULEINTERFACE *
	// ********************

	public:
		// Startup function called when starting our Module
		virtual void StartupModule() override;
		// Called just before the Module has been unloaded
		virtual void PreUnloadCallback();
		// Called after the module has been reloaded
		virtual void PostLoadCallback();
		// Shutdown Module called when shutting down our Module
		virtual void ShutdownModule() override;

	public:
		// This function returns true because I want to allow loading and unloading at any time
		virtual bool SupportsDynamicReloading() { return true; }
		// The plugin should shutdown on exit
		virtual bool SupportsAutomaticShutdown() { return true; }
		// Returns true if this module contains gameplay code
		virtual bool IsGameModule() const { return false; }

	protected:
		// Members and Methods

	// ************
	// * SETTINGS *
	// ************
	
	public:
		// Add the XMLAssetSettings Panel to the Editor Settings Panel
		void RegisterSettings();
		// Remove the XMLAssetSettings Panel from the Editor Settings Panel
		void UnregisterSettings();
		// Get Settings
		TWeakObjectPtr<UXMLAssetEditorSettings> GetSettings() { return this->Settings; }

	protected:
		// Settings Panel
		TWeakObjectPtr<UXMLAssetEditorSettings> Settings;

	// *****************
	// * ASSET ACTIONS *
	// *****************

	public:
		// Registers asset tool actions
		void RegisterAssetTools();
		// Unregister Asset tool actions
		void UnregisterAssetTools();

	protected:
		// A list of AssetActions we Registered with AssetTools
		TArray<TSharedRef<IAssetTypeActions>> RegisteredAssetTypeActions;

	// *********
	// * STYLE *
	// *********

	public:
		// Get Style
		TSharedPtr<ISlateStyle>& GetStyle() { return this->Style; };

	protected:
		// Style
		TSharedPtr<ISlateStyle> Style;
};

#undef LOCTEXT_NAMESPACE