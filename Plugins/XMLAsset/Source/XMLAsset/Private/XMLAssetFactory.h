// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

#pragma once

// UNREAL ENGINE Includes
#include <Factories/Factory.h>
#include <UObject/ObjectMacros.h>

// Boiler Plate Includes
#include "XMLAssetFactory.generated.h"

/* UXMLAssetFactory class enables the Content Browser 
	inside the Unreal editor to create an
	instance of an XMLAsset */
UCLASS()
class UXMLAssetFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
 
	// **********************
	// * UFACTORY INTERFACE *
	// **********************
	public:
		// Create a New Instance of the UXMLAsset class
		virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
		
	public:
		// Returns true if this factory should be shown in the New Asset menu (by default calls CanCreateNew).
		virtual bool ShouldShowInNewMenu() const override;
};