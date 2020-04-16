// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

#include "XMLAssetActions.h"
#include "XMLAssetEditorToolkit.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"

FXMLAssetActions::FXMLAssetActions(const TSharedRef<ISlateStyle>& InStyle) : Style(InStyle)
{
	/* NOTE: I prefer not to use initialisation lists 
		when I can avoid it but the Unreal Design here 
		prevents me from doing the following 
		
		this->Style = InStyle;

		*/
	
}

FXMLAssetActions::~FXMLAssetActions()
{
	// Destructor
}

bool FXMLAssetActions::CanFilter()
{
	// Return true if this Asset Can be Used as a filter in the Content Browser
	return true;
}

void FXMLAssetActions::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
	// TODO: Figure out what this does
	FAssetTypeActions_Base::GetActions(InObjects, MenuBuilder);
	/* Convert the income UObject Array into an XMLAssets Array.
		The Reason this is an array is because the user may have selected
		multiple objects in the Content Browser before right clicking
		to open the context menu.*/
	auto XMLAssets = GetTypedWeakObjectPtrs<UXMLAsset>(InObjects);
	// TODO: Experiment -> Can I select multiple objects of different types to execute a command on?

	/* NOTE: When you right mouse clck on the asset in the content browser,
		the code below adds meu items the user can click on. It also 
		adds the logic that makes the function work. In this case
		reverse the Text Property of the XMLAsset */
	MenuBuilder.AddMenuEntry(
		LOCTEXT("XMLAsset_Action1", "Action 1"),
		LOCTEXT("XMLAsset_Action1ToolTip", "This is a placeholder for Action1"),
		FSlateIcon(),
		FUIAction(
			// Here we Use a Lambda to generate an anonymous function to reverse the String
			FExecuteAction::CreateLambda([=]{
				for (auto& XMLAsset : XMLAssets)
				{
					if (XMLAsset.IsValid() && !XMLAsset->Text.IsEmpty())
					{
						XMLAsset->Text = FText::FromString(XMLAsset->Text.ToString().Reverse());
						XMLAsset->PostEditChange();
						XMLAsset->MarkPackageDirty();
					}
				}
			}),
			// I think this code here determines if we can use the Lambda
			FCanExecuteAction::CreateLambda([=] {
				for (auto& XMLAsset : XMLAssets)
				{
					if (XMLAsset.IsValid() && !XMLAsset->Text.IsEmpty())
					{
						return true;
					}
				}
				return false;
			})
		)
	);


	MenuBuilder.AddMenuEntry(
		LOCTEXT("XMLAsset_Action2", "Action2"),
		LOCTEXT("XMLAsset_Action2ToolTip", "This is a placeholder for Action2"),
		FSlateIcon(),
		FUIAction(
			// Here we Use a Lambda to generate an anonymous function to reverse the String
			FExecuteAction::CreateLambda([=]{
				for (auto& XMLAsset : XMLAssets)
				{
					if (XMLAsset.IsValid() && !XMLAsset->Text.IsEmpty())
					{
						
						this->Clear(XMLAsset);

						XMLAsset->PostEditChange();
						XMLAsset->MarkPackageDirty();
					}
				}
			}),
			// I think this code here determines if we can use the Lambda
			FCanExecuteAction::CreateLambda([=] {
				for (auto& XMLAsset : XMLAssets)
				{
					if (XMLAsset.IsValid() && !XMLAsset->Text.IsEmpty())
					{
						return true;
					}
				}
				return false;
			})
		)
	);
}

uint32 FXMLAssetActions::GetCategories()
{
	/* NOTE: When you right click on the content browser to 
		create a new instance of this Asset, this code places
		the item into the desired category */	
	//return EAssetTypeCategories::Media;
	//return EAssetTypeCategories::Misc | EAssetTypeCategories::Media;
	//return EAssetTypeCategories::Misc;
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();	
	return AssetTools.FindAdvancedAssetCategory("DodgeeSoftware");
}

FText FXMLAssetActions::GetName() const
{
	// Return the Name of the Asset how it will appear in the Content Browser
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_XMLAsset", "XML Asset");
}

UClass* FXMLAssetActions::GetSupportedClass() const
{
	// TODO: Still not sure what this does ?? 
	return UXMLAsset::StaticClass();
}

FColor FXMLAssetActions::GetTypeColor() const
{
	// The colour of the default Icon (when no image is defined in the Style using the ClassThumbnail.XMLAsset style)
	return FColor::Red;	
}

bool FXMLAssetActions::HasActions(const TArray<UObject*>& InObjects) const
{
	// TODO: Still not sure what this does ?? 
	return true;
}

void FXMLAssetActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	// TODO: Implement me

	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid()
		? EToolkitMode::WorldCentric
		: EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto XMLAsset = Cast<UXMLAsset>(*ObjIt);

		if (XMLAsset != nullptr)
		{
			TSharedRef<FXMLAssetEditorToolkit> EditorToolkit = MakeShareable(new FXMLAssetEditorToolkit(Style));
			EditorToolkit->Initialize(XMLAsset, Mode, EditWithinLevelEditor);
		}
	}
}

void FXMLAssetActions::Reverse(const TWeakObjectPtr<UXMLAsset, FWeakObjectPtr> XMLAssetIn)
{
	if (XMLAssetIn == nullptr)
		return;
	XMLAssetIn->Text = FText::FromString(XMLAssetIn->Text.ToString().Reverse());
}

void FXMLAssetActions::Clear(const TWeakObjectPtr<UXMLAsset, FWeakObjectPtr> XMLAssetIn)
{
	if (XMLAssetIn == nullptr)
		return;
	XMLAssetIn->Text = FText::FromString("");
}

#undef LOCTEXT_NAMESPACE