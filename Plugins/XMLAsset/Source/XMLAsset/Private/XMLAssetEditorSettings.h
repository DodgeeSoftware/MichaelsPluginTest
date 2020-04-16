// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

#pragma once

// UNREAL ENGINE Includes
#include <Fonts/SlateFontInfo.h>
#include <Styling/SlateColor.h>
#include <UObject/ObjectMacros.h>

// BOILER PLATE
#include "XMLAssetEditorSettings.generated.h"

UCLASS(config=Editor)
class XMLASSET_API UXMLAssetEditorSettings : public UObject
{
	// BOILER PLATE
	GENERATED_BODY()

	// *****************************
	// * CONSTRUCTORS / DESTRUCTOR *
	// *****************************
	
	public:
		/** Default constructor. */
		UXMLAssetEditorSettings();

	protected:
		// Members and methods

	// ************
	// * SETTINGS *
	// ************

	public:
		/** Color of the TextAsset editor's background. */
		UPROPERTY(config, EditAnywhere, Category=Appearance)
		FSlateColor BackgroundColor;

		/** Color of the TextAsset editor's text. */
		UPROPERTY(config, EditAnywhere, Category=Appearance)
		FSlateColor ForegroundColor;

		/** The font to use in the TextAsset editor window. */
		UPROPERTY(config, EditAnywhere, Category=Appearance)
		FSlateFontInfo Font;

		/** The margin around the TextAsset editor window (in pixels). */
		UPROPERTY(config, EditAnywhere, Category=Appearance)
		float Margin;

	protected:
		// Members and methods
};

