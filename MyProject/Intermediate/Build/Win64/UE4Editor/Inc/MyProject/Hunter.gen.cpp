// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/Hunter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHunter() {}
// Cross Module References
	MYPROJECT_API UClass* Z_Construct_UClass_AHunter_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_AHunter();
	MYPROJECT_API UClass* Z_Construct_UClass_ACreature();
	UPackage* Z_Construct_UPackage__Script_MyProject();
// End Cross Module References
	void AHunter::StaticRegisterNativesAHunter()
	{
	}
	UClass* Z_Construct_UClass_AHunter_NoRegister()
	{
		return AHunter::StaticClass();
	}
	struct Z_Construct_UClass_AHunter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHunter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACreature,
		(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHunter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Hunter.h" },
		{ "ModuleRelativePath", "Hunter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHunter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHunter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHunter_Statics::ClassParams = {
		&AHunter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AHunter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AHunter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHunter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHunter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHunter, 3053183840);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHunter(Z_Construct_UClass_AHunter, &AHunter::StaticClass, TEXT("/Script/MyProject"), TEXT("AHunter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHunter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
