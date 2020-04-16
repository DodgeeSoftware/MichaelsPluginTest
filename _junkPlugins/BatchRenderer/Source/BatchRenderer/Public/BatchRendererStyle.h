// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

#pragma once

// UNREAL ENGINE INCLUDES
#include <CoreMinimal.h>
#include <Styling/SlateStyle.h>

/** ??? */
class FBatchRendererStyle
{
	// *******************
	// * GENERAL METHODS *
	// *******************
	public:
		//! Initialize
		static void Initialize();
		//! Shutdown
		static void Shutdown();
		//! reloads textures used by slate renderer
		static void ReloadTextures();
		//! @return The Slate style set for the Shooter game
		static const ISlateStyle& Get();
		//! GetStyleSetName
		static FName GetStyleSetName();

	protected:
		// Create Fucntion
		static TSharedRef< class FSlateStyleSet > Create();

	protected:
		// StyleInstance
		static TSharedPtr< class FSlateStyleSet > StyleInstance;
};