// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

#pragma once

#include "IPluginManager.h"
#include "Brushes/SlateImageBrush.h"
#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"

#define IMAGE_BRUSH(RelativePath, ...) FSlateImageBrush(RootToContentDir(RelativePath, TEXT(".png")), __VA_ARGS__)
#define BOX_BRUSH(RelativePath, ...) FSlateBoxBrush(RootToContentDir(RelativePath, TEXT(".png")), __VA_ARGS__)
#define BORDER_BRUSH(RelativePath, ...) FSlateBorderBrush(RootToContentDir(RelativePath, TEXT(".png")), __VA_ARGS__)
#define TTF_FONT(RelativePath, ...) FSlateFontInfo(RootToContentDir(RelativePath, TEXT(".ttf")), __VA_ARGS__)
#define OTF_FONT(RelativePath, ...) FSlateFontInfo(RootToContentDir(RelativePath, TEXT(".otf")), __VA_ARGS__)

/* The FXMLAssetStyle defines the Style
	we want to use in the Editor. It is basically
	an associative array mapping fonts, brushes
	to an underlying asset */
class FXMLAssetStyle : public FSlateStyleSet
{
	// *****************************
	// * CONSTRUCTORS / DESTRUCTOR *
	// *****************************

	public:
		// Constructor
		FXMLAssetStyle() : FSlateStyleSet("XMLAssetEditorStyle")
		{
			// Send a message to the console
			GLog->Log("%%% FXMLAssetStyle() : FSlateStyleSet(XMLAssetEditorStyle) - start");

			// Make some useful vectors to size images we load in
			const FVector2D Icon16x16(16.0f, 16.0f);
			const FVector2D Icon20x20(20.0f, 20.0f);
			const FVector2D Icon40x40(40.0f, 40.0f);
			const FVector2D Icon128x128(128.0f, 128.0f);
			const FVector2D Icon256x256(256.0f, 256.0f);

			// SET THE DIRECTORY OUR HELPER MACROS WILL USE
			const FString BaseDir = IPluginManager::Get().FindPlugin("XMLAsset")->GetBaseDir();
			SetContentRoot(BaseDir / TEXT("Content"));

			// This Set the Icon for XMLAsset Class in the Content Browser
			Set("ClassIcon.XMLAsset", new IMAGE_BRUSH(TEXT("XMLIcon16x16"),Icon16x16));
			Set("ClassThumbnail.XMLAsset", new IMAGE_BRUSH(TEXT("XMLIcon128x128"),Icon128x128)); 

			// Register this style with the SlateStyleRegistry
			FSlateStyleRegistry::RegisterSlateStyle(*this);

			// Send a message to the console
			GLog->Log("%%% FXMLAssetStyle() : FSlateStyleSet(XMLAssetEditorStyle) - finish");
		}
		// Destructor
		virtual ~FXMLAssetStyle()
		{
			FSlateStyleRegistry::UnRegisterSlateStyle(*this);
		}

	protected:
		// Members and Methods
};

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH
#undef TTF_FONT
#undef OTF_FONT