// Copyright 2018 Dodgee Software, Inc. All Rights Reserved.

#pragma once

// UNREAL ENGINE Includes
#include <Internationalization/Text.h>
#include <UObject/Object.h>
#include <UObject/ObjectMacros.h>

// Boiler Plate Includes
#include "XMLAsset.generated.h"

/* The UXMLAsset class defines an asset
	how it should appear in the Content Browser */
UCLASS(BlueprintType, hidecategories=(Object))
class XMLASSET_API UXMLAsset : public UObject
{
	GENERATED_BODY()
	
	// *********************
	// * ASSET PROPERTIES *
	// *********************
	public:

		/** Holds the stored text. */
		UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="XMLAsset")
		FText Text;
};
