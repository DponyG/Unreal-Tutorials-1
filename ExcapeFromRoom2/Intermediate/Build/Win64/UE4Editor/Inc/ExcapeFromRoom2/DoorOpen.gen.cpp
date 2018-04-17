// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "DoorOpen.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDoorOpen() {}
// Cross Module References
	EXCAPEFROMROOM2_API UClass* Z_Construct_UClass_UDoorOpen_NoRegister();
	EXCAPEFROMROOM2_API UClass* Z_Construct_UClass_UDoorOpen();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_ExcapeFromRoom2();
// End Cross Module References
	void UDoorOpen::StaticRegisterNativesUDoorOpen()
	{
	}
	UClass* Z_Construct_UClass_UDoorOpen_NoRegister()
	{
		return UDoorOpen::StaticClass();
	}
	UClass* Z_Construct_UClass_UDoorOpen()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UActorComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_ExcapeFromRoom2,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "ClassGroupNames", "Custom" },
				{ "IncludePath", "DoorOpen.h" },
				{ "ModuleRelativePath", "DoorOpen.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UDoorOpen>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UDoorOpen::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B00080u,
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
	IMPLEMENT_CLASS(UDoorOpen, 3524435724);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UDoorOpen(Z_Construct_UClass_UDoorOpen, &UDoorOpen::StaticClass, TEXT("/Script/ExcapeFromRoom2"), TEXT("UDoorOpen"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDoorOpen);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
