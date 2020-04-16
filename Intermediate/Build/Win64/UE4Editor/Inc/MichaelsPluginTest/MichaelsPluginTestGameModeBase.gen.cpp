// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "MichaelsPluginTestGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMichaelsPluginTestGameModeBase() {}
// Cross Module References
	MICHAELSPLUGINTEST_API UClass* Z_Construct_UClass_AMichaelsPluginTestGameModeBase_NoRegister();
	MICHAELSPLUGINTEST_API UClass* Z_Construct_UClass_AMichaelsPluginTestGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_MichaelsPluginTest();
// End Cross Module References
	void AMichaelsPluginTestGameModeBase::StaticRegisterNativesAMichaelsPluginTestGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AMichaelsPluginTestGameModeBase_NoRegister()
	{
		return AMichaelsPluginTestGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_AMichaelsPluginTestGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_MichaelsPluginTest,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "MichaelsPluginTestGameModeBase.h" },
				{ "ModuleRelativePath", "MichaelsPluginTestGameModeBase.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AMichaelsPluginTestGameModeBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AMichaelsPluginTestGameModeBase::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900288u,
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
	IMPLEMENT_CLASS(AMichaelsPluginTestGameModeBase, 531440891);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMichaelsPluginTestGameModeBase(Z_Construct_UClass_AMichaelsPluginTestGameModeBase, &AMichaelsPluginTestGameModeBase::StaticClass, TEXT("/Script/MichaelsPluginTest"), TEXT("AMichaelsPluginTestGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMichaelsPluginTestGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
