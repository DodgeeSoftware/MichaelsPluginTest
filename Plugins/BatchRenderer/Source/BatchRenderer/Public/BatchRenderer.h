// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.
// Author: Shem Taylor

#pragma once

// UNREAL ENGINE INCLUDES
#include <CoreMinimal.h>
#include <ModuleManager.h>
#include <Runtime/Core/Public/Misc/MessageDialog.h>

class FToolBarBuilder;
class FMenuBuilder;

/* 
	DEVELOPER'S NOTES:
	I plan on including TinyXML as a third party library for this plugin
	this is because the default XML handling capabilities of Unreal are
	lousy to the present day. Most developer's dont use it because its
	designed for parsing rather then writing and is pretty poorly designed

	WHAT DOES THIS PLUGIN DO?
	It adds an Item to the Windows menu in the editor and it adds a button
	to the editor toolbar called 'Batch Rendering'. I have partially implemented
	feed back to the interaces and a few small subwindows. This project is for
	demonstration only as part of the bidding process

	TASKS
	I have marked tasks with the TODO notation
	Broader tasks involve renaming delegate functions to be prefixed with the window to 
	which they belong so there is some kind of standard
	As this project is simply a submission as part of a project bidding process
	this is not built according to a specification and is lacking core functionality.
	That functionality is marked with place holders
*/

/* The FBatchRendererModule Implments the IModuleInterface and 
 * is the module class driving our BatchRenderer Plugin */
class FBatchRendererModule : public IModuleInterface
{
	// *****************************
	// * CONSTRUCTORS / DESTRUCTOR *
	// *****************************
	/* NOTE: This section is where we imlpement
		constructors and the destructor*/
	public:
		// Constructor
		FBatchRendererModule();
		// Destructor
		virtual ~FBatchRendererModule();

	protected:
		// Methods and members

	// ************************
	// * OVERLOADED OPERATORS *
	// ************************
	/* NOTE: This section is where we implement 
		the overloaded operators */

	public:
		// Methods and members

	protected:
		// Methods and members

	// ********************
	// * IMODULEINTERFACE *
	// ********************
	/* NOTE: This section implements the base 
		interface IModuleInterface */

	public:
		//! StartupModule (Called at Startup when this is called is specified in the .uplugin file per-module)
		virtual void StartupModule() override;
		//! ShutdownModule (Called at Shutdown)
		virtual void ShutdownModule() override;

	protected:
		// Members and Methods

	// ***********
	// * GENERAL *
	// ***********
	/* NOTE: This section contains the logical core of
		the plugin loading, saving and starting new rendering projects */

	public:
		//! Start a newProject
		void NewProject();
		//! Load Project
		bool LoadProject(FString filename);
		//! Save Project
		bool SaveProject();
		//! Save Project As
		bool SaveProjectAs(FString filename);
		//! Quit the Batch Renderer
		void Quit();

	public:
		//! Is Saved
		bool isSaved() { return this->savedFlag; }

	protected:
		// Project Filename
		FString projectFilename;
		// Saved Flag
		bool savedFlag;

	// ********************
	// * EDITOR TO PLUGIN *
	// ********************
	/* NOTE: This section contains the functionality  
		to Connect the plugin to the editor*/

	public:
		// Boilder Plate
		//// OnSpawnPluginTab
		//TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);
	
	protected:
		// This function will be bound to Command (by default it will bring up plugin window)
		void BatchRendererPluginButtonClicked();
		// AddBatchRendererToolbarExtension
		void AddBatchRendererToolbarExtension(FToolBarBuilder& Builder);
		// AddBatchRendererMenuExtension
		void AddBatchRendererMenuExtension(FMenuBuilder& Builder);

	protected:
		// PluginCommands
		TSharedPtr<class FUICommandList> PluginCommands;

	// ***************
	// * MAIN WINDOW *
	// ***************
	/* NOTE: This section contrains the Main Plugin Window*/
	
	// WINDOW
	public:
		// On Window Closed Callback	
		void WindowClosed(const TSharedRef<SWindow>& WindowBeingClosed);

	// DROP DOWN WINDOW
	public:
		// Build FileMenu 
		void FileEntries(FMenuBuilder& MenuBuilder);
		// Build HelpMenu
		void HelpMenuEntries(FMenuBuilder& MenuBuilder);
		//! Called when OpenMenu Item Clicked
		void OpenMenuItemClicked();
		//! Called when Save MenuItem Clicked
		void SaveMenuItemClicked();
		//! Called when Save As MenuItem Clicked
		void SaveAsMenuItemClicked();
		//! Called when the User clicks Quit
		void QuitMenuItemClicked();
		//! Called when the HelpMenuItem is Clicked
		void HelpMenuItemClicked();
		//! Default Menu Item Callback
		void MenuItemClicked();

	// FUNCTION BUTTONS
	public:
		// Called when the User Clicks Add Shot
		FReply AddShotClicked();
		// Called when the User Clicks Edit Shot
		FReply EditShotClicked();
		// Called when the User Clicks Remove Shots
		FReply RemoveShotsClicked();
		// Called when the User Clicks Rename Shot
		FReply RenameShotClicked();
		// Called when the User Clicks Render Shots
		FReply RenderShotsClicked();
		// Called when the User Clicks Render All
		FReply RenderAllClicked();

	// CONTROLS
	public:
		// TextBox Containing the Engine's Path
		TSharedPtr<SEditableTextBox> EngineTextBox;
		// TextBox Containing the Project's Path
		TSharedPtr<SEditableTextBox> ProjectTextBox;
		//// TODO: Comment Me
		//TSharedRef<ITableRow> OnGenerateRowForShotList(TSharedPtr<UObject> Item, const TSharedRef<STableViewBase>& OwnerTable);

	protected:
		//// ShotList
		//TArray<TSharedPtr<UObject>> ShotList;
	
	// *******************
	// * ADD SHOT WINDOW *
	// *******************
	// NOTE: This Section Contains information for the AddShot Modal Window
	
	public:
		//! Called when the User Clicks Ok on the Add Shot Window
		FReply AddShotOkButtonClicked();
		//! Called when the User Clicks Cancel on the Add Shot Window
		FReply AddShotCancelButtonClicked();

	protected:
		// TextBox Containing the Engine's Path
		TSharedPtr<SEditableTextBox> ShotNameTextBox;

	// ********************
	// * EDIT SHOT WINDOW *
	// ********************
	/* NOTE: This section contains information for the Edit Shot Window */

	public:
		// Members and Methods

	protected:
		// Members and Methods

	// **********************
	// * RENAME SHOT WINDOW *
	// **********************
	/* NOTE: This section contains information for the Rename Shot Window */

	public:
		// Members and Methods

	protected:
		// Members and Methods

	// *********************
	// * INTERFACE TESTING *
	// *********************
	/* NOTE: This section contains small callbacks
		for testing parts of the interface*/
	
	public:
		// OnButtonClicked 
		FReply OnButtonClicked();
		//! Called when New Menu Item Clicked
		void NewMenuItemClicked();

	protected:
		// Members and Methods
};