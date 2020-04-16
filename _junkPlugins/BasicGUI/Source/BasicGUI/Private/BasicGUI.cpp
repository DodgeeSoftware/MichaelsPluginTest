// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "BasicGUI.h"
#include "BasicGUIStyle.h"
#include "BasicGUICommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SGridPanel.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

static const FName BasicGUITabName("BasicGUI");

#define LOCTEXT_NAMESPACE "FBasicGUIModule"

void FBasicGUIModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FBasicGUIStyle::Initialize();
	FBasicGUIStyle::ReloadTextures();

	FBasicGUICommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList); // MakeShareable makes a smart pointer

	PluginCommands->MapAction(
		FBasicGUICommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FBasicGUIModule::PluginButtonClicked), // NOTE: FExecuteAction defines a Delegate (a special type of function pointer)
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FBasicGUIModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FBasicGUIModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(BasicGUITabName, FOnSpawnTab::CreateRaw(this, &FBasicGUIModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FBasicGUITabTitle", "BasicGUI"))
		.SetMenuType(ETabSpawnerMenuType::Hidden)
		.SetMenuType(ETabSpawnerMenuType::Enabled);


	//GEngine->AddOnScreenDebugMessage( -1, 5.f, FColor::Green, FString::FString("deedeedee") );
}

void FBasicGUIModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FBasicGUIStyle::Shutdown();

	FBasicGUICommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(BasicGUITabName);
}

TSharedRef<SDockTab> FBasicGUIModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
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
				.OnClicked_Raw(this, &FBasicGUIModule::OnButtonClicked)
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

void FBasicGUIModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->InvokeTab(BasicGUITabName);
}

void FBasicGUIModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FBasicGUICommands::Get().OpenPluginWindow);
}

void FBasicGUIModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FBasicGUICommands::Get().OpenPluginWindow);
}

FReply FBasicGUIModule::OnButtonClicked()
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
	
IMPLEMENT_MODULE(FBasicGUIModule, BasicGUI)