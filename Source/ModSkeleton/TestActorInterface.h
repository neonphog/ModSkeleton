// Copyright 2017 Smogworks.

#pragma once

#include "TestActorInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTestActorInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

/**
 * 
 */
class MODSKELETON_API ITestActorInterface
{
	GENERATED_IINTERFACE_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ModSkeleton")
	FString GetTestString();
};
