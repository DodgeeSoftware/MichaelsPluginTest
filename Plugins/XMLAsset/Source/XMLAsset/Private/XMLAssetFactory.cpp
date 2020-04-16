// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

// XMLAsset Plugin Includes
#include "XMLAssetFactory.h"
#include "XMLAsset.h"

UXMLAssetFactory::UXMLAssetFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	this->bCreateNew = true;
	this->bEditAfterNew = true;
	this->SupportedClass = UXMLAsset::StaticClass();
}
 
UObject* UXMLAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	//UXMLAsset* XMLAsset = ConstructObject(Class, InParent, Name, Flags | RF_Transactional);
	UXMLAsset* XMLAsset = NewObject<UXMLAsset>(InParent, Class, Name, Flags);
	return XMLAsset;
}

bool UXMLAssetFactory::ShouldShowInNewMenu() const
{
	return true;
}