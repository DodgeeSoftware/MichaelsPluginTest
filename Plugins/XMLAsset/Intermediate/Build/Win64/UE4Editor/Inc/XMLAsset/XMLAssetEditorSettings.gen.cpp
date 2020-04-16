// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/XMLAssetEditorSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeXMLAssetEditorSettings() {}
// Cross Module References
	XMLASSET_API UClass* Z_Construct_UClass_UXMLAssetEditorSettings_NoRegister();
	XMLASSET_API UClass* Z_Construct_UClass_UXMLAssetEditorSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_XMLAsset();
	SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateFontInfo();
	SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateColor();
// End Cross Module References
	void UXMLAssetEditorSettings::StaticRegisterNativesUXMLAssetEditorSettings()
	{
	}
	UClass* Z_Construct_UClass_UXMLAssetEditorSettings_NoRegister()
	{
		return UXMLAssetEditorSettings::StaticClass();
	}
	UClass* Z_Construct_UClass_UXMLAssetEditorSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UObject,
				(UObject* (*)())Z_Construct_UPackage__Script_XMLAsset,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "XMLAssetEditorSettings.h" },
				{ "ModuleRelativePath", "Private/XMLAssetEditorSettings.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Margin_MetaData[] = {
				{ "Category", "Appearance" },
				{ "ModuleRelativePath", "Private/XMLAssetEditorSettings.h" },
				{ "ToolTip", "The margin around the TextAsset editor window (in pixels)." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Margin = { UE4CodeGen_Private::EPropertyClass::Float, "Margin", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000004001, 1, nullptr, STRUCT_OFFSET(UXMLAssetEditorSettings, Margin), METADATA_PARAMS(NewProp_Margin_MetaData, ARRAY_COUNT(NewProp_Margin_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Font_MetaData[] = {
				{ "Category", "Appearance" },
				{ "ModuleRelativePath", "Private/XMLAssetEditorSettings.h" },
				{ "ToolTip", "The font to use in the TextAsset editor window." },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Font = { UE4CodeGen_Private::EPropertyClass::Struct, "Font", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000004001, 1, nullptr, STRUCT_OFFSET(UXMLAssetEditorSettings, Font), Z_Construct_UScriptStruct_FSlateFontInfo, METADATA_PARAMS(NewProp_Font_MetaData, ARRAY_COUNT(NewProp_Font_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ForegroundColor_MetaData[] = {
				{ "Category", "Appearance" },
				{ "ModuleRelativePath", "Private/XMLAssetEditorSettings.h" },
				{ "ToolTip", "Color of the TextAsset editor's text." },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ForegroundColor = { UE4CodeGen_Private::EPropertyClass::Struct, "ForegroundColor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000004001, 1, nullptr, STRUCT_OFFSET(UXMLAssetEditorSettings, ForegroundColor), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(NewProp_ForegroundColor_MetaData, ARRAY_COUNT(NewProp_ForegroundColor_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BackgroundColor_MetaData[] = {
				{ "Category", "Appearance" },
				{ "ModuleRelativePath", "Private/XMLAssetEditorSettings.h" },
				{ "ToolTip", "Color of the TextAsset editor's background." },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_BackgroundColor = { UE4CodeGen_Private::EPropertyClass::Struct, "BackgroundColor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000004001, 1, nullptr, STRUCT_OFFSET(UXMLAssetEditorSettings, BackgroundColor), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(NewProp_BackgroundColor_MetaData, ARRAY_COUNT(NewProp_BackgroundColor_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Margin,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Font,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ForegroundColor,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BackgroundColor,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UXMLAssetEditorSettings>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UXMLAssetEditorSettings::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100084u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				"Editor",
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UXMLAssetEditorSettings, 2250300097);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UXMLAssetEditorSettings(Z_Construct_UClass_UXMLAssetEditorSettings, &UXMLAssetEditorSettings::StaticClass, TEXT("/Script/XMLAsset"), TEXT("UXMLAssetEditorSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UXMLAssetEditorSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
