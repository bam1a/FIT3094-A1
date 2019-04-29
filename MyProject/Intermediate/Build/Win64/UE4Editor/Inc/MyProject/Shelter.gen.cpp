// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/Shelter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShelter() {}
// Cross Module References
	MYPROJECT_API UClass* Z_Construct_UClass_AShelter_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_AShelter();
	MYPROJECT_API UClass* Z_Construct_UClass_APathNode();
	UPackage* Z_Construct_UPackage__Script_MyProject();
// End Cross Module References
	void AShelter::StaticRegisterNativesAShelter()
	{
	}
	UClass* Z_Construct_UClass_AShelter_NoRegister()
	{
		return AShelter::StaticClass();
	}
	struct Z_Construct_UClass_AShelter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShelter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APathNode,
		(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShelter_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Shelter.h" },
		{ "ModuleRelativePath", "Shelter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShelter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShelter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AShelter_Statics::ClassParams = {
		&AShelter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AShelter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AShelter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AShelter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AShelter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AShelter, 3516552138);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShelter(Z_Construct_UClass_AShelter, &AShelter::StaticClass, TEXT("/Script/MyProject"), TEXT("AShelter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShelter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
