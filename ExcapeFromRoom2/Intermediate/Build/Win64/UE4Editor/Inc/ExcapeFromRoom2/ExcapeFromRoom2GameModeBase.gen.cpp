// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ExcapeFromRoom2GameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExcapeFromRoom2GameModeBase() {}
// Cross Module References
	EXCAPEFROMROOM2_API UClass* Z_Construct_UClass_AExcapeFromRoom2GameModeBase_NoRegister();
	EXCAPEFROMROOM2_API UClass* Z_Construct_UClass_AExcapeFromRoom2GameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ExcapeFromRoom2();
// End Cross Module References
	void AExcapeFromRoom2GameModeBase::StaticRegisterNativesAExcapeFromRoom2GameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AExcapeFromRoom2GameModeBase_NoRegister()
	{
		return AExcapeFromRoom2GameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_AExcapeFromRoom2GameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_ExcapeFromRoom2,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "ExcapeFromRoom2GameModeBase.h" },
				{ "ModuleRelativePath", "ExcapeFromRoom2GameModeBase.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AExcapeFromRoom2GameModeBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AExcapeFromRoom2GameModeBase::StaticClass,
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
	IMPLEMENT_CLASS(AExcapeFromRoom2GameModeBase, 845557815);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AExcapeFromRoom2GameModeBase(Z_Construct_UClass_AExcapeFromRoom2GameModeBase, &AExcapeFromRoom2GameModeBase::StaticClass, TEXT("/Script/ExcapeFromRoom2"), TEXT("AExcapeFromRoom2GameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AExcapeFromRoom2GameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
