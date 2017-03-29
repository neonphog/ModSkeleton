// Copyright 2017 Smogworks.

#pragma once

#include "TestActorInterface.h"

#include "GameFramework/Actor.h"
#include "TestActorBase.generated.h"

UCLASS()
class MODSKELETON_API ATestActorBase : public AActor, public ITestActorInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActorBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable, Category = "ModSkeleton")
	FString AssetRegistrySearchGroup;

	UFUNCTION(BlueprintCallable, Category = "ModSkeleton")
	static TArray<UClass*> FindAllTestActors();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ModSkeleton")
	FString GetTestString();
	virtual FString GetTestString_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
