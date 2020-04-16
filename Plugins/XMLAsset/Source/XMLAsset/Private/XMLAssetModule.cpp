// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

#include "XMLAssetModule.h"

#define LOCTEXT_NAMESPACE "FXMLAssetModule"

void FXMLAssetModule::StartupModule()
{
	// Send a message to the console
	UE_LOG(LogTemp, Display, TEXT("%%% FXMLAssetModule StartupModule()"));
	
	// Create our Style (this is a smart pointer no need to clean up)
	this->Style = MakeShareable(new FXMLAssetStyle());

	// Grab Asset Tools Module
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	// **************************
	// * REGISTER ASSET ACTIONS *
	// **************************

	/* NOTE: This step is very important. The AssetActions class 
		tells the editor important information such as what category
		an asset should occur in the content browser, what colour the default 
		icon should be, what the name of the asset should appear as. It adds
		menu items for when the user selects a group of assets and wishes to
		perform a common action on those assets. It also allows you to override
		the default editor when the user double clicks on an asset in the content
		browser */
	this->RegisterAssetTools();

	// *********************************************
	// * ADD SETTINGS TO THE EDITOR SETTINGS PANEL *
	// *********************************************

	/* Register the Settings Panel (XMLAssetEditorSettings) 
		with the Editor Settings Panel */
	this->RegisterSettings();

	// *****************************************************
	// * REGISTER YOUR OWN CATEGORY IN THE CONTENT BROWSER *
	// *****************************************************
	/* NOTE: This allows you to create your own category in the content browser to 
		add new assets too. Code as follows:

		AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("DodgeeSoftware")),LOCTEXT("DodgeeSoftware","DodgeeSoftware"));

		To Add the asset to the Content Browser context menu you'd put the following in the 'GetCategories'
		method in your AssetActions class:
		
		MyAssett::GetCategories()
		{
			IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();	
			return AssetTools.FindAdvancedAssetCategory("DodgeeSoftware"); 
		}
	*/
    // Add the New Asset Category
	AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("DodgeeSoftware")),LOCTEXT("DodgeeSoftware","DodgeeSoftware"));
}

void FXMLAssetModule::PreUnloadCallback()
{
	// Send a message to the console
	UE_LOG(LogTemp, Display, TEXT("%%% FXMLAssetModule PreUnloadCallback()"));
}

void FXMLAssetModule::PostLoadCallback()
{
	// Send a message to the console
	UE_LOG(LogTemp, Display, TEXT("%%% FXMLAssetModule PostLoadCallBack()"));
}

void FXMLAssetModule::ShutdownModule()
{
	// Send a message to the console
	UE_LOG(LogTemp, Display, TEXT("%%% FXMLAssetModule ShutdownModule()"));
	// Unregister Asset Tools
	this->UnregisterAssetTools();
	// Remove the Asset Settings from the Project Settings Panel
	this->UnregisterSettings();
}

void FXMLAssetModule::RegisterSettings()
{
	// Grab the Settings Module
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	// If we have a valid SettingsModule
	if (SettingsModule != nullptr)
	{
		// Create the Instance of our Settings
		this->Settings  = GetMutableDefault<UXMLAssetEditorSettings>();
		// Register the XMLAssetSettingsPanel on the Editor Settings Window
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Editor", "Plugins", "XMLAsset",
			LOCTEXT("XMLAssetSettingsName", "XML Asset"),
			LOCTEXT("XMLAssetSettingsDescription", "Configure the XML Asset plug-in."),
			this->Settings
		);
	}
}

void FXMLAssetModule::UnregisterSettings()
{
	// Grab the SettingsModule
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	// If the SettingsModule is valud
	if (SettingsModule != nullptr)
	{
		// Unregister the Panel we added to EditorSettings
		SettingsModule->UnregisterSettings("Editor", "Plugins", "XMLAsset");
	}
}

void FXMLAssetModule::RegisterAssetTools()
{
	// Grab Asset Tools
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();	
	// Make our new Asset Action	
	TSharedRef<IAssetTypeActions> XMLAssetAction = MakeShareable(new FXMLAssetActions(Style.ToSharedRef()));
	// Register the New Asset Action with Asset Tools
	AssetTools.RegisterAssetTypeActions(XMLAssetAction);

	/* We add our action here to a local list so that we know which 
		actions our module registered to clean up in the shutdown.
		The module can be randomly shutdown so we don't assume the
		only case shutdown will be called is when the editor is shutdown.
		Meaning we need to keep tabs of certain things */
	this->RegisteredAssetTypeActions.Add(XMLAssetAction);
}

void FXMLAssetModule::UnregisterAssetTools()
{
	// Grab Asset Tools Module
	FAssetToolsModule* AssetToolsModule = FModuleManager::GetModulePtr<FAssetToolsModule>("AssetTools");
	// If the AssetToolsModule is valdid
	if (AssetToolsModule != nullptr)
	{
		// Grab the Asset Tools from the AssetToolsModule
		IAssetTools& AssetTools = AssetToolsModule->Get();
		// Go through each action we registered
		for (auto Action : this->RegisteredAssetTypeActions)
		{
			// Unregister Each Action
			AssetTools.UnregisterAssetTypeActions(Action);
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FXMLAssetModule, XMLAsset)