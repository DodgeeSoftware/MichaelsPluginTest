// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

#include "XMLAssetEditorToolkit.h"

#include <Editor.h>
#include <EditorReimportHandler.h>
#include <EditorStyleSet.h>
#include <UObject/NameTypes.h>
#include <Widgets/Docking/SDockTab.h>

#include "SXMLAssetEditor.h"
#include "XMLAsset.h"


#define LOCTEXT_NAMESPACE "FXMLAssetEditorToolkit"

DEFINE_LOG_CATEGORY_STATIC(LogTextAssetEditor, Log, All);

namespace XMLAssetEditor
{
	static const FName AppIdentifier("XMLAssetEditorApp");
	static const FName TabId("XMLEditor");
}

FXMLAssetEditorToolkit::FXMLAssetEditorToolkit(const TSharedRef<ISlateStyle>& InStyle)
	: XMLAsset(nullptr)
	, Style(InStyle)
{

}

FXMLAssetEditorToolkit::~FXMLAssetEditorToolkit()
{
	FReimportManager::Instance()->OnPreReimport().RemoveAll(this);
	FReimportManager::Instance()->OnPostReimport().RemoveAll(this);

	GEditor->UnregisterForUndo(this);
}

void FXMLAssetEditorToolkit::Initialize(UXMLAsset* InXMLAsset, const EToolkitMode::Type InMode, const TSharedPtr<IToolkitHost>& InToolkitHost)
{
	this->XMLAsset = InXMLAsset;

	// Support undo/redo
	this->XMLAsset->SetFlags(RF_Transactional);
	GEditor->RegisterForUndo(this);

	// create tab layout
	const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("Standalone_XMLAssetEditor");
		// Commented out Shem Taylor
		//->AddArea
		//(
		//	FTabManager::NewPrimaryArea()
		//		->SetOrientation(Orient_Horizontal)
		//		->Split
		//		(
		//			FTabManager::NewSplitter()
		//				//->SetOrientation(Orient_Vertical)
		//				//->SetSizeCoefficient(0.66f)
		//				//->Split
		//				//(
		//				//	FTabManager::NewStack()
		//				//		->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
		//				//		->SetHideTabWell(true)
		//				//		->SetSizeCoefficient(0.1f)
		//				//		
		//				//)
		//				//->Split
		//				//(
		//				//	FTabManager::NewStack()
		//				//		->AddTab(XMLAssetEditor::TabId, ETabState::OpenedTab)
		//				//		->SetHideTabWell(true)
		//				//		->SetSizeCoefficient(0.9f)
		//				//)
		//		)
		//);

	FAssetEditorToolkit::InitAssetEditor(
		InMode,
		InToolkitHost,
		XMLAssetEditor::AppIdentifier,
		Layout,
		true /*bCreateDefaultStandaloneMenu*/,
		true /*bCreateDefaultToolbar*/,
		InXMLAsset
	);

	RegenerateMenusAndToolbars();
}

FString FXMLAssetEditorToolkit::GetDocumentationLink() const
{
	/* When the user has the editor for the asset open (by double
		clicking it in the content broswer) in the editors help menu
		there is a help option the string here is the URL the 
		editor will send to the default browser */
	return FString(TEXT("https://github.com/ue4plugins/TextAsset"));
}

void FXMLAssetEditorToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_XMLAssetEditor", "XML Asset Editor"));
	auto WorkspaceMenuCategoryRef = WorkspaceMenuCategory.ToSharedRef();

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(XMLAssetEditor::TabId, FOnSpawnTab::CreateSP(this, &FXMLAssetEditorToolkit::HandleTabManagerSpawnTab, XMLAssetEditor::TabId))
		.SetDisplayName(LOCTEXT("XMLEditorTabName", "XML Editor"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Viewports"));
}

void FXMLAssetEditorToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(XMLAssetEditor::TabId);
}

FText FXMLAssetEditorToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "XML Asset Editor");
}

FName FXMLAssetEditorToolkit::GetToolkitFName() const
{
	return FName("XMLAssetEditor");
}

FLinearColor FXMLAssetEditorToolkit::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0.3f, 0.2f, 0.5f, 0.5f);
}

FString FXMLAssetEditorToolkit::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "XMLAsset ").ToString();
}

void FXMLAssetEditorToolkit::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(XMLAsset);
}
	
void FXMLAssetEditorToolkit::PostUndo(bool bSuccess)
{

}

void FXMLAssetEditorToolkit::PostRedo(bool bSuccess)
{
	PostUndo(bSuccess);
}

TSharedRef<SDockTab> FXMLAssetEditorToolkit::HandleTabManagerSpawnTab(const FSpawnTabArgs& Args, FName TabIdentifier)
{
	TSharedPtr<SWidget> TabWidget = SNullWidget::NullWidget;

	if (TabIdentifier == XMLAssetEditor::TabId)
	{
		TabWidget = SNew(SXMLAssetEditor, XMLAsset, Style);
	}

	return SNew(SDockTab)
		.TabRole(ETabRole::PanelTab)
		[
			TabWidget.ToSharedRef()
		];
}

#undef LOCTEXT_NAMESPACE