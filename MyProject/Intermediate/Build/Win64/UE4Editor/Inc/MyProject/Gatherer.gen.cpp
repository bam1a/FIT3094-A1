// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/Gatherer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGatherer() {}
// Cross Module References
	MYPROJECT_API UClass* Z_Construct_UClass_AGatherer_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_AGatherer();
	MYPROJECT_API UClass* Z_Construct_UClass_ACreature();
	UPackage* Z_Construct_UPackage__Script_MyProject();
// End Cross Module References
	void AGatherer::StaticRegisterNativesAGatherer()
	{
	}
	UClass* Z_Construct_UClass_AGatherer_NoRegister()
	{
		return AGatherer::StaticClass();
	}
	struct Z_Construct_UClass_AGatherer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGatherer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACreature,
		(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGatherer_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Gatherer.h" },
		{ "ModuleRelativePath", "Gatherer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGatherer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGatherer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGatherer_Statics::ClassParams = {
		&AGatherer::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AGatherer_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AGatherer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGatherer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGatherer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGatherer, 3384510858);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGatherer(Z_Construct_UClass_AGatherer, &AGatherer::StaticClass, TEXT("/Script/MyProject"), TEXT("AGatherer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGatherer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
