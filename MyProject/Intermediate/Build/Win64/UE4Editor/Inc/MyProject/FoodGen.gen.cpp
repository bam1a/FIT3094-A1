// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/FoodGen.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFoodGen() {}
// Cross Module References
	MYPROJECT_API UClass* Z_Construct_UClass_AFoodGen_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_AFoodGen();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MyProject();
// End Cross Module References
	void AFoodGen::StaticRegisterNativesAFoodGen()
	{
	}
	UClass* Z_Construct_UClass_AFoodGen_NoRegister()
	{
		return AFoodGen::StaticClass();
	}
	struct Z_Construct_UClass_AFoodGen_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_randomTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_randomTime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_defaultTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_defaultTime;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFoodGen_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFoodGen_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FoodGen.h" },
		{ "ModuleRelativePath", "FoodGen.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFoodGen_Statics::NewProp_randomTime_MetaData[] = {
		{ "Category", "FoodGen" },
		{ "ModuleRelativePath", "FoodGen.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFoodGen_Statics::NewProp_randomTime = { UE4CodeGen_Private::EPropertyClass::Float, "randomTime", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000020001, 1, nullptr, STRUCT_OFFSET(AFoodGen, randomTime), METADATA_PARAMS(Z_Construct_UClass_AFoodGen_Statics::NewProp_randomTime_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFoodGen_Statics::NewProp_randomTime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFoodGen_Statics::NewProp_defaultTime_MetaData[] = {
		{ "Category", "FoodGen" },
		{ "ModuleRelativePath", "FoodGen.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFoodGen_Statics::NewProp_defaultTime = { UE4CodeGen_Private::EPropertyClass::Float, "defaultTime", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000000001, 1, nullptr, STRUCT_OFFSET(AFoodGen, defaultTime), METADATA_PARAMS(Z_Construct_UClass_AFoodGen_Statics::NewProp_defaultTime_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFoodGen_Statics::NewProp_defaultTime_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFoodGen_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFoodGen_Statics::NewProp_randomTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFoodGen_Statics::NewProp_defaultTime,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFoodGen_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFoodGen>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFoodGen_Statics::ClassParams = {
		&AFoodGen::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_AFoodGen_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AFoodGen_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AFoodGen_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AFoodGen_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFoodGen()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFoodGen_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFoodGen, 1136533925);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFoodGen(Z_Construct_UClass_AFoodGen, &AFoodGen::StaticClass, TEXT("/Script/MyProject"), TEXT("AFoodGen"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFoodGen);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
