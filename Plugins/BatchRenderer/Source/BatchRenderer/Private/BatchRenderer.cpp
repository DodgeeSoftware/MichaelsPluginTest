// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.
// Author: Shem Taylor

// MY PLUGIN INCLUDES
// NOTE: Unreal forces the header contraining the Module be the first include
#include "BatchRenderer.h" 
#include "BatchRendererStyle.h"
#include "BatchRendererCommands.h"

// UNREAL ENGINE INCLUDES
// Slate
#include <Widgets/Docking/SDockTab.h>
#include <Widgets/Layout/SBox.h>
#include <Widgets/Layout/SGridPanel.h>
#include <Widgets/Text/STextBlock.h>
#include <Widgets/Input/SButton.h>
#include <Widgets/Input/SComboBox.h>
#include <Widgets/Input/SEditableTextBox.h>
#include <Widgets/Views/SListView.h>
#include <Widgets/Layout/SScrollBox.h>
#include <LevelEditor.h>

// FrameWork
#include <Framework/MultiBox/MultiBoxBuilder.h>

static const FName BatchRendererTabName("BatchRenderer");

#define LOCTEXT_NAMESPACE "FBatchRendererModule"

FBatchRendererModule::FBatchRendererModule() : IModuleInterface()
{
	// Initialise Class Members
	this->savedFlag = true;
	this->projectFilename = FString();
	this->PluginCommands = 0;
	this->EngineTextBox = 0;
	this->ProjectTextBox = 0;
	this->ShotNameTextBox = 0;
}

FBatchRendererModule::~FBatchRendererModule()
{
	// Destructor
}

void FBatchRendererModule::StartupModule()
{
	// STYLES (Associative arrays with Fonts, Images used by the GUI)
	// Initialise the SlateStyle
	FBatchRendererStyle::Initialize();
	// Load the Textures for the Slate Style
	FBatchRendererStyle::ReloadTextures();

	// COMMANDS
	// Register our BatchRendererCommands
	FBatchRendererCommands::Register();
	// Make a new Shareable FUICommandList Object called PluginCommands
	this->PluginCommands = MakeShareable(new FUICommandList);
	// Map an Action to our PluginCommands
	this->PluginCommands->MapAction(
		FBatchRendererCommands::Get().OpenPluginWindow, // OpenPluginWindow is a Command We created
		FExecuteAction::CreateRaw(this, &FBatchRendererModule::BatchRendererPluginButtonClicked), // This is a c++ delegate / function pointer to the local method BatchRendererPluginButtonClicked
		FCanExecuteAction() // ??
	);
	/* NOTE: I tried experimenting by adding new MapActions to the PluginCommands to find no change
				- Shem Taylor */

	// ADD PLUGIN TO THE MENUS AND TOOLBARS
	// Grab the LevelEditorModule
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	/* Ok, this code here adds an option to the 'Window' DropDown menu 
		in the Editor*/
	{
		/* TSharedPtr is a SmartPointer Datatype here we create a new FExtender and use
			the MakeShareable Method to create a SharedPoiter to the new FExtender*/
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
			// Add a MenuExtension to the MenuExtender
			MenuExtender->AddMenuExtension("WindowLayout", // This is the name of an interface hook, which is a text based position to place a new widget
										   EExtensionHook::After, // This is the hook location either before or after
										   this->PluginCommands, //
										   FMenuExtensionDelegate::CreateRaw(this, &FBatchRendererModule::AddBatchRendererMenuExtension) // This is a delegate, it's a c++ style function pointer to the local member function AddBatchRendererMenuExtension
			);
		//  Grab the LevelEditorModule's MenuExtensibilityManager and add the MenuExtender
		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	// Ok, this code here adds an option to the ToolBar 	
	{
		/* TSharedPtr is a SmartPointer Datatype here we create a new FExtender and use
			the MakeShareable Method to create a SharedPoiter to the new FExtender*/
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", // This is the name of an interface hook, which is a text based position to place a new widget
											 EExtensionHook::After, // This is the hook location either before or after
											 this->PluginCommands, // 
											 FToolBarExtensionDelegate::CreateRaw(this, &FBatchRendererModule::AddBatchRendererToolbarExtension) // This is a delegate, it's a c++ style function pointer to the local member function AddBatchRendererToolbarExtension
		);
		
		//  Grab the LevelEditorModule's ToolBarExtensibilityManager and add the ToolbarExtender
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
	
	// 88888888888888888888888888
	// NOTE: This code came from the Boiler Plate I kept it for reference only
	///* Grab the FGlobalTabmanager Singleton and Register a TabSpawner */
	//FTabSpawnerEntry& TabSpawnerEntry = FGlobalTabmanager::Get()->RegisterNomadTabSpawner(BatchRendererTabName, FOnSpawnTab::CreateRaw(this, &FBatchRendererModule::OnSpawnPluginTab));
	//	// Set the DisplayName of the TabSpawnerEntry
	//	TabSpawnerEntry.SetDisplayName(LOCTEXT("FBatchRendererTabTitle", "BatchRenderer"));
	//	// Set the Type of the TabSpawnerEntry
	//	TabSpawnerEntry.SetMenuType(ETabSpawnerMenuType::Hidden);
	// 88888888888888888888888888
}

void FBatchRendererModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
	// Shutdown the Slate Style
	FBatchRendererStyle::Shutdown();
	// Deregister Commands
	FBatchRendererCommands::Unregister();

	// 888888888888888888
	// NOTE: This code came from the Template I kept it for reference
	//// Unregister the TabSpawner
	//FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(BatchRendererTabName);
	// 888888888888888888
}


void FBatchRendererModule::NewProject()
{
	// Send a message to the Console
	GLog->Log("************************************************ NEW PROJECT");
	// TODO: Implement me
}

bool FBatchRendererModule::LoadProject(FString filename)
{
	// Send a message to the Console
	GLog->Log("************************************************ LOAD PROJECT");

	// TODO: Implement me

	// Success
	return true;
}

bool FBatchRendererModule::SaveProject()
{
	// Send a message to the Console
	GLog->Log("************************************************ SAVE PROJECT");

	// TODO: Implement me

	// Success
	return true;
}

bool FBatchRendererModule::SaveProjectAs(FString filename)
{
	// Send a message to the Console
	GLog->Log("************************************************ SAVE PROJECT AS");

	// TODO: Implement me

	// Success
	return true;
}

void FBatchRendererModule::Quit()
{
	// Send a message to the Console
	GLog->Log("************************************************ QUIT");
	// TODO: Implement me
}

// 8888888888888
// NOTE: This code came from the Tempalte kept for reference
//TSharedRef<SDockTab> FBatchRendererModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
//{
//	FText WidgetText = FText::Format(
//		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
//		FText::FromString(TEXT("FBasicGUIModule::OnSpawnPluginTab")),
//		FText::FromString(TEXT("BasicGUI.cpp"))
//		);
//
//	return SNew(SDockTab)
//		.TabRole(ETabRole::NomadTab)
//		[
//			// Put your tab content here!
//			SNew(SVerticalBox)
//			+ SVerticalBox::Slot()
//			.AutoHeight()
//			.MaxHeight(408.f)
//			.VAlign(VAlign_Bottom)
//			[
//				SNew(STextBlock)
//				.Text(WidgetText)
//			]
//			+ SVerticalBox::Slot()
//			.AutoHeight()
//			.FillHeight(30.f)
//			[
//				SNew(STextBlock)
//				.Text(WidgetText)
//			]
//			+ SVerticalBox::Slot()
//			.AutoHeight()
//			.FillHeight(30.f)
//			[
//				SNew(SButton)
//				.Text(FText::FromString("Hello World"))
//				.DesiredSizeScale(FVector2D(100.0f, 60.0f))
//				.OnClicked_Raw(this, &FBatchRendererModule::OnButtonClicked)
//				//SNew(SEditableTextBox)
//			]
//			+ SVerticalBox::Slot()
//			.AutoHeight()
//			.FillHeight(30.f)
//			[
//				SNew(SEditableTextBox)
//			]
//		];
//}
// 888888888888

void FBatchRendererModule::BatchRendererPluginButtonClicked()
{
	// 888888888888888
	// NOTE: Came From the template kept for reference
	//// Open's a Tab named with the String BatchRendererTabName
	//FGlobalTabmanager::Get()->InvokeTab(BatchRendererTabName);
	// 888888888888888

	// Create a MenuBar Builder
	FMenuBarBuilder MenuBarBuilder(this->PluginCommands);
        MenuBarBuilder.AddPullDownMenu(FText::FromString("File"),FText::GetEmpty(),FNewMenuDelegate::CreateRaw(this, &FBatchRendererModule::FileEntries));
		MenuBarBuilder.AddPullDownMenu(FText::FromString("About"),FText::GetEmpty(),FNewMenuDelegate::CreateRaw(this, &FBatchRendererModule::HelpMenuEntries));
        //MenuBarBuilder.SetStyle(&FBatchRendererStyle::Get(),"BatchRenderer.MenuStyle"); // I commented out, still experimenting with styles, macro errors atm - Shem Taylor

	// Grab the SlateApplication
	FSlateApplication& SlateApplication = FSlateApplication::Get();

	// Create A Window
	/* NOTE: There are two layouts used here SVerticalBox and SHorizontalBox and they can be 'nested' i.e. placed inside
		eachother, to add content to a SVerticalBox you use the Syntax "+ SVerticalBox::Slot()" followed by square brakets
		which contrain your new Controls. To add content to a SHorizontalBox you use the Sytnax "+ SVerticalBox::Slot() followed
		by square brakets which contain your new Controls. You make a new contol using the SNew command which returns a reference
		to an object. You can then use the '.' Operator to manipulate the properties of your new object adding text and callback/delegates
		for button handling . See below for an excellent reference. It is also very important to notice here that I start off
		with the .Content(). This is the location of the root Object of the Window that we attach everything else too"*/
	TSharedRef<SWindow> Window = TSharedRef<SWindow>(SNew(SWindow)
								.Title(FText::FromString(TEXT("Batch Renderer"))) // Window Caption
								.CreateTitleBar(true) // Will the Window have a title Bar?
								.ScreenPosition(FVector2D(0, 0)) // Position of the Window
								.ClientSize(FVector2D(500, 800)) // The Size of the Window								
								.SizingRule(ESizingRule::UserSized) // Set the Sizing Rule for the Window
								.SupportsMaximize(false) // Will the window support Maximizing
								.SupportsMinimize(true) // Will the Window support Minimizing
								.HasCloseButton(true) // Will the window have a close button
								.Content()
								[
									SNew(SVerticalBox) // Use a Vertical Layout
									// Add a new slot to the Vertical Layout
									+ SVerticalBox::Slot()
									.AutoHeight() // This slot should set it's own height
									[
										// Make the Window's DropDown Menu
										/* NOTE: This object is instantiated above and uses delegates to create itself. 
											Yes this is very messy and awkward but heck this is slate, so why make anything easy.
											The Author would rather build them without delegates, like directly, because the delgates
											are only used the one time and for the one specific thing and having functions in the class
											that do that is wasteful and stupid */
										MenuBarBuilder.MakeWidget() 
									]
									// Add a new slot to the Vertical Layout
									+ SVerticalBox::Slot()
									.AutoHeight() // This slot should set it's own height
									[
										SNew(SHorizontalBox) // Use a horizontal Layout
										+ SHorizontalBox::Slot() // Add a new slot to the horizonal layout
										[
											SNew(STextBlock) // Make a Label
											.Text(FText::FromString("Engine")) // Set the Text on the Label
										]
										+ SHorizontalBox::Slot() // Add a new slot to the horizonal layout
										[
											/* NOTE: Notice how I use SAssigNew here instead of SNew, this
												is so that we can create the Object and assign a local (class member)
												reference to it. This allows us to query its value
												during onclick events etc */
											SAssignNew(this->EngineTextBox, SEditableTextBox) // Make a TextBox
											.Text(FText::FromString(FPaths::EngineDir())) // Set the TextBox to use the EngineDir text
											
										]
										+ SHorizontalBox::Slot() // Add a new slot to the horizonal layout
										[
											SNew(SButton) // Make a Button
											.Text(FText::FromString("...")) // Set the text on the button 
											.OnClicked_Raw(this, &FBatchRendererModule::OnButtonClicked) // OnClick Delegate Function / Callback
										]
									]
									+ SVerticalBox::Slot()
									.AutoHeight() // This slot should set it's own height
									[
										SNew(SHorizontalBox) // Use a horizontal Layout
										+ SHorizontalBox::Slot()
										[
											SNew(STextBlock) // Make a Label
											.Text(FText::FromString("Project")) // Label Text
											//// Commented this out, this works though, its here for an example of hard coding the font
											//.Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 20)) // Example of setting the Font
											//.Font(FBatchRendererStyle::Get().GetFontStyle(FName("BatchRenderer.MyStyle"))) // Example of setting the Font using the StyleClass Method
										]
										+ SHorizontalBox::Slot()
										[
											/* NOTE: Notice how I use SAssigNew here instead of SNew, this
												is so that we can create the Object and assign a local (class member)
												reference to it. This allows us to query its value
												during onclick events etc */
											SAssignNew(this->ProjectTextBox, SEditableTextBox) // Make a TextBox
											.Text(FText::FromString(FPaths::ProjectDir())) // Set the TextBox value to the ProjectDirectory										
										]
										+ SHorizontalBox::Slot()
										[
											SNew(SButton) // Make a Button
											.Text(FText::FromString("...")) // Text on the button
											.OnClicked_Raw(this, &FBatchRendererModule::OnButtonClicked) // OnClick Delegate Function / Callback
										]
									]
									//// NOTE: Thus far I have been unsuccessful in implementing a SListView, so I commented this out
									//+ SVerticalBox::Slot()
									//[
									//	SNew(SListView< TSharedPtr<UObject> >)
									//	// TODO: Look into implementing these
									//	.ListItemsSource(&ShotList)
									//	// TODO: This function 
									//	.OnGenerateRow(this, &FBatchRendererModule::OnGenerateRowForShotList)
									//	.ItemHeight(24)
									//	.HeaderRow
									//	(
									//		SNew(SHeaderRow)
									//		+ SHeaderRow::Column("Column1")
									//		[
									//			SNew(SBorder)
									////			.Padding(5)
									////			.Content()
									//			[
									//				SNew(STextBlock)
									//				.Text(FText::FromString("Name"))
									//			]
									//		]
									////		+ SHeaderRow::Column("Number") .DefaultLabel(TEXT("Number"))
									////		+ SHeaderRow::Column("TextField") .DefaultLabel(TEXT("Text Field"))
									////		+ SHeaderRow::Column("TextBlock") .DefaultLabel(TEXT("Text Block"))
									////		+ SHeaderRow::Column("AddChild") .DefaultLabel(TEXT("Add Child"))
									//	)
									//]
									+ SVerticalBox::Slot()
									[
										SNew(SEditableTextBox)
									]
									+ SVerticalBox::Slot()
									.AutoHeight() // This slot should set it's own height
									[
										SNew(SHorizontalBox)
										+ SHorizontalBox::Slot()
										[
											SNew(SButton) // Make a Button
											.Text(FText::FromString("Add Shot")) // Text on the button
											.OnClicked_Raw(this, &FBatchRendererModule::AddShotClicked) // OnClick Delegate Function / Callback
										]
										+ SHorizontalBox::Slot()
										[
											SNew(SButton) // Make a Button
											.Text(FText::FromString("Edit Shot")) // Text on the button
											.OnClicked_Raw(this, &FBatchRendererModule::EditShotClicked) // OnClick Delegate Function / Callback
										]
										+ SHorizontalBox::Slot()
										[
											SNew(SButton) // Make a Button
											.Text(FText::FromString("Remove Shot")) // Text on the button
											.OnClicked_Raw(this, &FBatchRendererModule::RemoveShotsClicked) // OnClick Delegate Function / Callback
										]
									]
									+ SVerticalBox::Slot()
									.AutoHeight() // This slot should set it's own height
									[
										SNew(SHorizontalBox) // Add a New Horizontal Box
										+ SHorizontalBox::Slot() // Add a Slot to our horizontal box
										[
											SNew(SButton) // Make a Button
											.Text(FText::FromString("Rename Shot")) // Text on the button
											.OnClicked_Raw(this, &FBatchRendererModule::RenameShotClicked) // OnClick Delegate Function / Callback
										]
										+ SHorizontalBox::Slot() // Add a Slot to our horizontal box
										[
											SNew(SButton) // Make a Button
											.Text(FText::FromString("Render Shots")) // Text on the button
											.OnClicked_Raw(this, &FBatchRendererModule::RenderShotsClicked) // OnClick Delegate Function / Callback
										] 
										+ SHorizontalBox::Slot() // Add a Slot to our horizontal box
										[
											SNew(SButton) // Make a Button
											.Text(FText::FromString("Render All"))  // Text on the button
											.OnClicked_Raw(this, &FBatchRendererModule::RenderAllClicked) // OnClick Delegate Function / Callback
										]
									]
								]
	);

	// Add an OnWindowClosed callback to our Window
	Window.Get().SetOnWindowClosed(FOnWindowClosed::CreateRaw(this, &FBatchRendererModule::WindowClosed));
	// Add the Window to the Slate Application (i.e. this function  makes the Window Appear)
	SlateApplication.AddWindow(Window);
}

void FBatchRendererModule::AddBatchRendererMenuExtension(FMenuBuilder& Builder)
{
	// Add Menu Entry
	Builder.AddMenuEntry(FBatchRendererCommands::Get().OpenPluginWindow);
}

void FBatchRendererModule::AddBatchRendererToolbarExtension(FToolBarBuilder& Builder)
{
	// Add ToolBar Button
	Builder.AddToolBarButton(FBatchRendererCommands::Get().OpenPluginWindow);
}

void FBatchRendererModule::FileEntries(FMenuBuilder& MenuBuilder)
{
	// BUILD THE FILE MENU

	// Add Entry to the Menu
	MenuBuilder.AddMenuEntry(FText::FromString(FString("New")), // The name of the entry in the Help Menu
							 FText::FromString(FString("New Project File")), // The text when the Mouse Hovers over the item in the menu
							 FSlateIcon(), 
							 FUIAction(FExecuteAction::CreateRaw(this, &FBatchRendererModule::NewMenuItemClicked)) // The delegate called when the item is clicked (a c++ style function pointer)
	);

	// Add Entry to the Menu
	MenuBuilder.AddMenuEntry(FText::FromString(FString("Open")), // The name of the entry in the Help Menu
							 FText::FromString(FString("Open a Project File")), // The text when the Mouse Hovers over the item in the menu
							 FSlateIcon(), 
							 FUIAction(FExecuteAction::CreateRaw(this, &FBatchRendererModule::OpenMenuItemClicked)) // The delegate called when the item is clicked (a c++ style function pointer)
	);
	// Add Entry to the Menu
	MenuBuilder.AddMenuEntry(FText::FromString(FString("Save")), // The name of the entry in the Help Menu
							 FText::FromString(FString("Save a Project File")), // The text when the Mouse Hovers over the item in the menu
							 FSlateIcon(), 
							 FUIAction(FExecuteAction::CreateRaw(this, &FBatchRendererModule::SaveMenuItemClicked)) // The delegate called when the item is clicked (a c++ style function pointer)
	);
	// Add Entry to the Menu
	MenuBuilder.AddMenuEntry(FText::FromString(FString("Save As")), // The name of the entry in the Help Menu
							 FText::FromString(FString("Save As a Project File")), // The text when the Mouse Hovers over the item in the menu
							 FSlateIcon(), 
							 FUIAction(FExecuteAction::CreateRaw(this, &FBatchRendererModule::SaveAsMenuItemClicked)) // The delegate called when the item is clicked (a c++ style function pointer)
	);
	// Add Entry to the Menu
	MenuBuilder.AddMenuEntry(FText::FromString(FString("Quit")), // The name of the entry in the Help Menu
							 FText::FromString(FString("Quit the Batch Renderer")), // The text when the Mouse Hovers over the item in the menu
							 FSlateIcon(),
							 FUIAction(FExecuteAction::CreateRaw(this, &FBatchRendererModule::QuitMenuItemClicked)) // The delegate called when the item is clicked (a c++ style function pointer)
	);
       
	//MenuBuilder.SetStyle(&FBatchRendererStyle::Get(), "BatchRenderer.MenuStyle"); // I Commented this out
}

void FBatchRendererModule::HelpMenuEntries(FMenuBuilder& MenuBuilder)
{
	// BUILD THE HELP MENU
	
	// Add Entry to the Menu
	MenuBuilder.AddMenuEntry(FText::FromString(FString("About")), // The name of the entry in the Help Menu
							 FText::FromString(FString("About the Batch Renderer")), // The text when the Mouse Hovers over the item in the menu
							 FSlateIcon(),
							 FUIAction(FExecuteAction::CreateRaw(this, &FBatchRendererModule::HelpMenuItemClicked)) // The delegate called when the item is clicked (a c++ style function pointer)
	);
}

void FBatchRendererModule::HelpMenuItemClicked()
{
	// Send a message to the Console
	GLog->Log("************************************************ ABOUT MENU ITEM CLICKED");
	// Create a 'modal' textbox
	FMessageDialog::Open(EAppMsgType::Ok, // Set the Type of message bos
						 FText::FromString("(c) Dodgee Software 2018") // Set the text of the message Box
	);
}


void FBatchRendererModule::NewMenuItemClicked()
{
	// Send a message to the Console
	GLog->Log("************************************************ NEW MENU ITEM CLICKED");
	// Start a New Project
	this->NewProject();
}

void FBatchRendererModule::OpenMenuItemClicked()
{
	// Send a message to the Console
	GLog->Log("************************************************ OPEN MENU ITEM CLICKED");
	// TODO: Grab the FileName implement success and fail conditions
	FString filename;
	if (this->LoadProject(filename) == false)
	{
		// Failure
		return;
	}
	else
	{
		// Success
		return;
	}
}

void FBatchRendererModule::SaveMenuItemClicked()
{
	// Send a message to the Console
	GLog->Log("************************************************ SAVE MENU ITEM CLICKED");
	if (this->SaveProject() == false)
	{
		// Failure
		return;
	}
	else
	{
		// Success
		return;
	}
}

void FBatchRendererModule::SaveAsMenuItemClicked()
{
	// Send a message to the Console
	GLog->Log("************************************************ SAVEAS MENU ITEM CLICKED");
	// TODO: Grab the FileName implement success and fail conditions
	FString filename;
	if (this->SaveProjectAs(filename) == false)
	{
		// Failure
		return;
	}
	else
	{
		// Success
		return;
	}
}

void FBatchRendererModule::QuitMenuItemClicked()
{
	// Send a message to the Console
	GLog->Log("************************************************ QUIT MENU ITEM CLICKED");
	// TODO: Close the Window
}

FReply FBatchRendererModule::AddShotClicked()
{
	// Send a message to the Console
	GLog->Log("************************************************ ADD SHOT CLICKED");
	GLog->Log("Value of Engine Text Box is: ");
	GLog->Log(this->EngineTextBox->GetText());
	GLog->Log(this->ProjectTextBox->GetText());

	// Grab the Slate Application
	FSlateApplication& SlateApplication = FSlateApplication::Get();

	// Make a Window
	TSharedRef<SWindow> Window = TSharedRef<SWindow>(SNew(SWindow)
								//.
								.Title(FText::FromString(TEXT("Add Shot"))) // Window Caption
								.ScreenPosition(FVector2D(0, 0)) // Screen position
								.ClientSize(FVector2D(500, 250)) // Desired Size
								.CreateTitleBar(true) // Will there be a title bar
								.SizingRule(ESizingRule::UserSized) // Sizing rules
								.SupportsMaximize(false) // Will the window support maximisation
								.SupportsMinimize(true) // Will the window support minimisation
								.HasCloseButton(true) // Will the button have a close button
								.Content() // Start at the root of the window
								[
									SNew(SVerticalBox) // Make a SVertical Box
									+ SVerticalBox::Slot() // Add a New slot to our vertical Box
									[
										SNew(SHorizontalBox)
										+ SHorizontalBox::Slot()
										[
											SNew(STextBlock) // Make a New Label
											.Text(FText::FromString("Shot Name")) // Set the Text for the Label
										]
										+ SHorizontalBox::Slot()
										[
											/* NOTE: Notice how I use SAssigNew here instead of SNew, this
												is so that we can create the Object and assign a local (class member)
												reference to it. This allows us to query its value
												during onclick events etc */
											SAssignNew(this->ShotNameTextBox, SEditableTextBox) // Assign the local ShotNameTextBox
										]
									]
									+ SVerticalBox::Slot() // Add a New slot to our vertical Box
									[
										SNew(SHorizontalBox)
										+ SHorizontalBox::Slot()
										[
											SNew(SButton)
											.Text(FText::FromString("Ok"))
											.OnClicked_Raw(this, &FBatchRendererModule::AddShotOkButtonClicked) // OnClick Delegate Function / Callback
										]
										+ SHorizontalBox::Slot()
										[
											SNew(SButton)
											.Text(FText::FromString("Cancel"))
											.OnClicked_Raw(this, &FBatchRendererModule::AddShotCancelButtonClicked) // OnClick Delegate Function / Callback
										]
									]
								]
	);
	// Add the Window to the Slate Application (i.e. make it appear)
	SlateApplication.AddModalWindow(Window, SlateApplication.GetActiveTopLevelWindow());
	// Return that the Button Was Handled
	return FReply::Handled();
}

FReply FBatchRendererModule::EditShotClicked()
{
	// Send a message to the Console
	GLog->Log("************************************************ EDIT SHOT CLICKED");
	// TODO: Create the Edit Shot Window and Add it to the Slate Application
	// Return that the Button Was Handled
	return FReply::Handled();
}

FReply FBatchRendererModule::RemoveShotsClicked()
{
	// Send a message to the Console
	GLog->Log("************************************************ REMOVE SHOT CLICKED");

	/* TODO: We need to make a remove shot's method
		of some kind to remove the shots requested from a selected
		list */

	// Return that the Button Was Handled
	return FReply::Handled();
}

FReply FBatchRendererModule::RenameShotClicked()
{
	// Send a message to the Console
	GLog->Log("************************************************ RENAME SHOT CLICKED");
	
	/* TODO: We need a Rename shot method
		to rename a specific shot */

	// Return that the Button Was Handled
	return FReply::Handled();
}

FReply FBatchRendererModule::RenderShotsClicked()
{
	// Send a message to the Console
	GLog->Log("************************************************ RENDER SHOTS CLICKED");

	/* TODO: This is the Meat of our plugin where all the rendering instructions
		are converted into console commands. We need to implement this.
		Probably make a renderShot function then go through a list of shots */

	// Return that the Button Was Handled
	return FReply::Handled();
}

FReply FBatchRendererModule::RenderAllClicked()
{
	// Send a message to the Console
	GLog->Log("************************************************ RENDER ALL SHOT CLICKED");
	
	/* TODO: This is the Meat of our plugin where all the rendering instructions
		are converted into console commands. We need to implement this.
		Probably make a renderShot function then go through a list of shots */

	// Return that the Button Was Handled
	return FReply::Handled();
}

//// NOTE: At the moment this is experimental Code
//TSharedRef<ITableRow> FBatchRendererModule::OnGenerateRowForShotList(TSharedPtr<UObject> Item, const TSharedRef<STableViewBase>& OwnerTable)
//{
//     //Create the row
//     return SNew(STableRow< TSharedPtr<UObject> >, OwnerTable)
//         .Padding(2.0f)
//         [
//             SNew(STextBlock).Text(*Item.Get())
//         ];
//}

void FBatchRendererModule::WindowClosed(const TSharedRef<SWindow>& WindowBeingClosed)
{
	// Send Messages to the Console
	GLog->Log(FText::FromString("Closing the Window Named: "));
	GLog->Log(WindowBeingClosed.Get().GetTitle());
	
	// TODO: Close the Window
}

FReply FBatchRendererModule::AddShotOkButtonClicked()
{
	// Send a message to the Console
	GLog->Log("************************************************ ADDSHOTWINDOW OK BUTTON CLICKED");
	
	// TODO: Add shot function and add the shot

	// Return that the Button Was Handled
	return FReply::Handled();
}

FReply FBatchRendererModule::AddShotCancelButtonClicked()
{
	// Send a message to the Console
	GLog->Log("************************************************ ADDSHOTWINDOW CANCEL BUTTON CLICKED");
	
	// TODO: Close the Window

	// Return that the Button Was Handled
	return FReply::Handled();
}

FReply FBatchRendererModule::OnButtonClicked()
{
	// A SIMPLE TEST BUTTON CLICK FUNCTION USED WHEN MAKING THE INTERFACES

	// Send some Text to the Console
	GLog->Log("************************************************");

	// Grab the Slate Application
	FSlateApplication& SlateApplication = FSlateApplication::Get();

	// Make a Window
	TSharedRef<SWindow> Window = TSharedRef<SWindow>(SNew(SWindow)
								.Title(FText::FromString(TEXT("Button Click Test Window"))) // Window Caption
								.ScreenPosition(FVector2D(0, 0)) // Screen position
								.ClientSize(FVector2D(500, 250)) // Desired Size
								.CreateTitleBar(true) // Will there be a title bar
								.SizingRule(ESizingRule::UserSized) // Sizing rules
								.SupportsMaximize(false) // Will the window support maximisation
								.SupportsMinimize(true) // Will the window support minimisation
								.HasCloseButton(true) // Will the button have a close button
								.Content() // Start at the root of the window
								[
									SNew(SVerticalBox) // Make a SVertical Box
									+ SVerticalBox::Slot() // Add a New slot to our vertical Box
									.AutoHeight() // The Slot will size itself
									.Padding(20) // Padding to the slot on the left and right hand side
									.HAlign(HAlign_Center) // Set Horizontal Alignment of the Vertical Box
									[
										SNew(STextBlock) // Make a New Label
										.Text(FText::FromString("You managed to open a new window! Congratulations please enjoy this test Window")) // Set the Text for the Label
									]
								]
	);
	// Add the Window to the Slate Application (i.e. make it appear)
	SlateApplication.AddWindow(Window);
	// Return that the Button Was Handled
	return FReply::Handled();
}

void FBatchRendererModule::MenuItemClicked()
{
	// Send a message to the Console
	GLog->Log("************************************************ MENU ITEM CLICKED");
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FBatchRendererModule, BatchRenderer)