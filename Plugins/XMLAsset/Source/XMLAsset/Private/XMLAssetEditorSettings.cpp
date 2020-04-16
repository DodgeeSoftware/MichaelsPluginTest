// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

#include "XMLAssetEditorSettings.h"

UXMLAssetEditorSettings::UXMLAssetEditorSettings()
	: BackgroundColor(FLinearColor::White)
	, ForegroundColor(FLinearColor::Black)
	, Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/DroidSansMono.ttf"), 10))
	, Margin(4.0f)
{

}