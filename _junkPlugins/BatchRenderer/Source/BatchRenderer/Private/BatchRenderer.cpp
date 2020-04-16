// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

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
#include <LevelEditor.h>
// FrameWork
#include <Framework/MultiBox/MultiBoxBuilder.h>

#define LOCTEXT_NAMESPACE "FBatchRendererModule"

void FBatchRendererModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	
	
	// STYLE
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
		FExecuteAction::CreateRaw(this, &FBatchRendererModule::PluginButtonClicked), // This is a c++ delegate / function pointer to the local method PluginButtonClicked
		FCanExecuteAction());
		
	// Grab the LevelEditorModule
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	// ADD PLUGIN TO THE MENUS AND TOOLBARS
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
										   FMenuExtensionDelegate::CreateRaw(this, &FBatchRendererModule::AddMenuExtension) // This is a delegate, it's a c++ style function pointer to the local member function AddMenuExtension
			);
		//  Grab the LevelEditorModule's MenuExtensibilityManager and add the MenuExtender
		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	/* Ok, this code here adds an option to the ToolBar 	
	{
		/* TSharedPtr is a SmartPointer Datatype here we create a new FExtender and use
			the MakeShareable Method to create a SharedPoiter to the new FExtender*/
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", // This is the name of an interface hook, which is a text based position to place a new widget
											 EExtensionHook::After, // This is the hook location either before or after
											 this->PluginCommands, // 
											 FToolBarExtensionDelegate::CreateRaw(this, &FBatchRendererModule::AddToolbarExtension) // This is a delegate, it's a c++ style function pointer to the local member function AddToolbarExtension
		);
		
		//  Grab the LevelEditorModule's ToolBarExtensibilityManager and add the ToolbarExtender
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
	
	/* Grab the FGlobalTabmanager Singleton and Register a TabSpawner */
	FTabSpawnerEntry& TabSpawnerEntry = FGlobalTabmanager::Get()->RegisterNomadTabSpawner(BatchRendererTabName, FOnSpawnTab::CreateRaw(this, &FBatchRendererModule::OnSpawnPluginTab));
		// Set the DisplayName of the TabSpawnerEntry
		TabSpawnerEntry.SetDisplayName(LOCTEXT("FBatchRendererTabTitle", "BatchRenderer"));
		// Set the Type of the TabSpawnerEntry
		TabSpawnerEntry.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FBatchRendererModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
	// Shutdown the Slate Style
	FBatchRendererStyle::Shutdown();
	// Deregister Commands
	FBatchRendererCommands::Unregister();

	// Unregister the TabSpawner
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(FBatchRendererModule::BatchRendererTabName);
}

TSharedRef<SDockTab> FBatchRendererModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FBasicGUIModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("BasicGUI.cpp"))
		);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			.MaxHeight(408.f)
			.VAlign(VAlign_Bottom)
			[
				SNew(STextBlock)
				.Text(WidgetText)
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.FillHeight(30.f)
			[
				SNew(STextBlock)
				.Text(WidgetText)
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.FillHeight(30.f)
			[
				SNew(SButton)
				.Text(FText::FromString("Hello World"))
				.DesiredSizeScale(FVector2D(100.0f, 60.0f))
				.OnClicked_Raw(this, &FBatchRendererModule::OnButtonClicked)
				//SNew(SEditableTextBox)
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.FillHeight(30.f)
			[
				SNew(SEditableTextBox)
			]
		];
}

void FBatchRendererModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->InvokeTab(BatchRendererTabName);
}

void FBatchRendererModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FBatchRendererCommands::Get().OpenPluginWindow);
}

void FBatchRendererModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FBatchRendererCommands::Get().OpenPluginWindow);
}

FReply FBatchRendererModule::OnButtonClicked()
{
	GLog->Log("************************************************");

	FSlateApplication& slateApplication = FSlateApplication::Get();

	slateApplication.AddWindow(TSharedRef<SWindow>(SNew(SWindow)
								.Title(FText::FromString(TEXT("Control Window")))
								.ScreenPosition(FVector2D(0, 0))
								.ClientSize(FVector2D(500, 800))
								.CreateTitleBar(true)
								.SizingRule(ESizingRule::UserSized)
								.SupportsMaximize(false)
								.SupportsMinimize(true)
								.HasCloseButton(true)
								.Content()
								[
									SNew(SVerticalBox)
									+ SVerticalBox::Slot().AutoHeight().Padding(20).HAlign(HAlign_Center)
									[
									SNew(STextBlock).Text(FText::FromString("Hello World"))
									]
								]
	));

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FBatchRendererModule, BatchRenderer)