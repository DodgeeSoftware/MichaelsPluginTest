// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

#pragma once

// UNREAL ENGINE Includes
#include <AssetTypeActions_Base.h>
#include <Templates/SharedPointer.h>
#include <Framework/MultiBox/MultiBoxBuilder.h>
#include <Styling/SlateStyle.h>

// PLUGIN Includes
#include "XMLAsset.h"

class ISlateStyle;

/* The FXMLAssetActions Class is used to tell 
	the unreal editor what to do with a particular
	asset. This covers what the colour of the icons 
	will be in the Asset Editor, which (if any) editor
	will be used when the user double clicks on the
	asset in the content browser and what category
	the asset should be added to in the Content Browser.
	It also adds functions to the content menu when the
	user selects a bunch of assets and right clicks.
	NOTE: This class is paired with the AssetTools Module.
	*/
class FXMLAssetActions : public FAssetTypeActions_Base
{
	// *****************************
	// * CONSTRUCTORS / DESTRUCTOR *
	// *****************************
	
	public:
		// Constructor
		FXMLAssetActions(const TSharedRef<ISlateStyle>& InStyle);
		// Destructor
		virtual ~FXMLAssetActions();

	protected:
		// Members and Methods

	// *******************************
	// * FASSETTYPEACTIONS OVERRIDES *
	// *******************************
	
	public:
		// Returns true if this class can be used as a filter in the Content Browser	
		virtual bool CanFilter() override;
		// Generate the Context Menu When Right Clicking the Asset in the Content Browser
		virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;
		// Returns Flags for which categories the XMLAsset will appear in the Content Browser
		virtual uint32 GetCategories() override;
		// The value returned by GetName returns the name of the Asset in the Content Browser for this asset
		virtual FText GetName() const override;
		// TODO: There is no documentation on what this does. Need to look into it
		virtual UClass* GetSupportedClass() const override;
		// The value returned by GetTypeColor returns the colour of the icon in the Content Browser for this asset
		virtual FColor GetTypeColor() const override;
		// TODO: There is no documentation on what this does. Need to look into it
		virtual bool HasActions(const TArray<UObject*>& InObjects) const override;
		// Implementing this function Overrides the Default Asset Editor
		virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;

	//public:
		//// This function can be used to render an animated ThumbNail
		//virtual class UThumbnailInfo* GetThumbnailInfo(UObject* Asset) const override { return 0; }

	protected:
		// Pointer to the style set to use for toolkits
		TSharedRef<ISlateStyle> Style;
	
	// *****************	
	// * ASSET ACTIONS *
	// *****************
	/* NOTE: IN this section we use our functions which perform various processes on 
		our XMLAsset */

	public:
		// Pefrom a simple Action on the Incoming XMLAsset
		virtual void Reverse(const TWeakObjectPtr<UXMLAsset, FWeakObjectPtr> XMLAssetIn);
		// Pefrom a simple Action on the Incoming XMLAsset
		virtual void Clear(const TWeakObjectPtr<UXMLAsset, FWeakObjectPtr> XMLAssetIn);

	protected:
		// Members and methods
};
