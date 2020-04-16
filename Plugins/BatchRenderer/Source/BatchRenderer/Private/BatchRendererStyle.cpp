// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.
// Author: Shem Taylor

#include "BatchRendererStyle.h"
#include <Styling/SlateStyleRegistry.h>
#include <Framework/Application/SlateApplication.h>
#include <SlateGameResources.h>
#include <IPluginManager.h>

TSharedPtr< FSlateStyleSet > FBatchRendererStyle::StyleInstance = NULL;

void FBatchRendererStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FBatchRendererStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FBatchRendererStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("BatchRendererStyle"));
	return StyleSetName;
}

// Handy Loading Macros (Only available in this cpp file undefined at the bottom)
#define IMAGE_BRUSH( RelativePath, ... ) FSlateImageBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BOX_BRUSH( RelativePath, ... ) FSlateBoxBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BORDER_BRUSH( RelativePath, ... ) FSlateBorderBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define TTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".ttf") ), __VA_ARGS__ )
#define OTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".otf") ), __VA_ARGS__ )

// Useful variables for loading Icons of certain sizes
const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon40x40(40.0f, 40.0f);

TSharedRef<FSlateStyleSet> FBatchRendererStyle::Create()
{
	// Make a Shared Reference to a Slate Style
	TSharedRef<FSlateStyleSet> Style = MakeShareable(new FSlateStyleSet("BatchRendererStyle"));
	
	// Set the Root Directory for the Assets the Style will Use.
	/* NOTE: If you wish to use another directory you can change this here */
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("BatchRenderer")->GetBaseDir() / TEXT("Resources"));

	// IMAGES
	// NOTE: There is no Constructor for this method, hence this is broken via Epic.... -> Shem Taylor
	Style->Set("BatchRenderer.OpenPluginWindow", new IMAGE_BRUSH(TEXT("ButtonIcon_40x"), Icon40x40));	

	// BOXBRUSHES
	// Styles go here

	// BORDERBRUSHES
	// Styles go here

	// FONTS
	// Associated the style "BatchRenderer.MyStyle" with a Font of a certain size
	Style->Set("BatchRenderer.MyStyle", TTF_FONT( FString("001SystemAnalysisBold"), (uint16)24) ); // NOTE: Added by Shem Taylor
	
	// Return the Newly created Style
	return Style;
}

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH
#undef TTF_FONT
#undef OTF_FONT

void FBatchRendererStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FBatchRendererStyle::Get()
{
	return *StyleInstance;
}
