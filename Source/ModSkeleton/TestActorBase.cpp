// Copyright 2017 Smogworks.

#include "ModSkeleton.h"
#include "TestActorBase.h"

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

#include "Runtime/AssetRegistry/Public/ARFilter.h"

#include "AssetRegistryModule.h"

// Sets default values
ATestActorBase::ATestActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AssetRegistrySearchGroup = "TestActorBase";
}

// Called when the game starts or when spawned
void ATestActorBase::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(ModSkeletonLog, Warning, TEXT("TestActorBase.cpp::BeginPlay()"));
}

// Called every frame
void ATestActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<UClass*> ATestActorBase::FindAllTestActors()
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TArray<FAssetData> AssetData;
	FARFilter Filter;
	//Filter.bRecursiveClasses = true;
	//Filter.ClassNames.Add(ATestActorBase::StaticClass()->GetFName());
	Filter.TagsAndValues.Add("AssetRegistrySearchGroup", "TestActorBase");

	AssetRegistryModule.Get().GetAssets(Filter, AssetData);

	UE_LOG(ModSkeletonLog, Warning, TEXT("Beginning: AssetRegistrySearch"));
	for (int32 i = 0; i < AssetData.Num(); ++i)
	{
		UE_LOG(ModSkeletonLog, Warning, TEXT("AssetRegistrySearch: %s"), *AssetData[i].ObjectPath.ToString());
		UClass* Found = AssetData[i].GetClass();
		if (Found->ImplementsInterface(UTestActorInterface::StaticClass()))
		{
			UE_LOG(ModSkeletonLog, Warning, TEXT(" - UsesIface!"));
		}
		else
		{
			UE_LOG(ModSkeletonLog, Warning, TEXT(" - No Iface : ("));
		}
	}

	TArray<UClass*> out;
	return out;
}

FString ATestActorBase::GetTestString_Implementation()
{
	return TEXT("StringFrom(TestActorBase)");
}