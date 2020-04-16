// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/XMLAssetFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeXMLAssetFactory() {}
// Cross Module References
	XMLASSET_API UClass* Z_Construct_UClass_UXMLAssetFactory_NoRegister();
	XMLASSET_API UClass* Z_Construct_UClass_UXMLAssetFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_XMLAsset();
// End Cross Module References
	void UXMLAssetFactory::StaticRegisterNativesUXMLAssetFactory()
	{
	}
	UClass* Z_Construct_UClass_UXMLAssetFactory_NoRegister()
	{
		return UXMLAssetFactory::StaticClass();
	}
	UClass* Z_Construct_UClass_UXMLAssetFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UFactory,
				(UObject* (*)())Z_Construct_UPackage__Script_XMLAsset,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "XMLAssetFactory.h" },
				{ "ModuleRelativePath", "Private/XMLAssetFactory.h" },
				{ "ToolTip", "UXMLAssetFactory class enables the Content Browser\n      inside the Unreal editor to create an\n      instance of an XMLAsset" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UXMLAssetFactory>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UXMLAssetFactory::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00000080u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UXMLAssetFactory, 221975236);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UXMLAssetFactory(Z_Construct_UClass_UXMLAssetFactory, &UXMLAssetFactory::StaticClass, TEXT("/Script/XMLAsset"), TEXT("UXMLAssetFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UXMLAssetFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
