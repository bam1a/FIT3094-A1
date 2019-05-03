// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/generator.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodegenerator() {}
// Cross Module References
	MYPROJECT_API UClass* Z_Construct_UClass_Agenerator_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_Agenerator();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MyProject();
// End Cross Module References
	void Agenerator::StaticRegisterNativesAgenerator()
	{
	}
	UClass* Z_Construct_UClass_Agenerator_NoRegister()
	{
		return Agenerator::StaticClass();
	}
	struct Z_Construct_UClass_Agenerator_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HiderCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_HiderCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GathererCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_GathererCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HunterCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_HunterCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_genTimer_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_genTimer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_genTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_genTime;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_Agenerator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Agenerator_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "generator.h" },
		{ "ModuleRelativePath", "generator.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Agenerator_Statics::NewProp_HiderCount_MetaData[] = {
		{ "Category", "InitialGeneratingSettings" },
		{ "ModuleRelativePath", "generator.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_Agenerator_Statics::NewProp_HiderCount = { UE4CodeGen_Private::EPropertyClass::Int, "HiderCount", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000000001, 1, nullptr, STRUCT_OFFSET(Agenerator, HiderCount), METADATA_PARAMS(Z_Construct_UClass_Agenerator_Statics::NewProp_HiderCount_MetaData, ARRAY_COUNT(Z_Construct_UClass_Agenerator_Statics::NewProp_HiderCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Agenerator_Statics::NewProp_GathererCount_MetaData[] = {
		{ "Category", "InitialGeneratingSettings" },
		{ "ModuleRelativePath", "generator.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_Agenerator_Statics::NewProp_GathererCount = { UE4CodeGen_Private::EPropertyClass::Int, "GathererCount", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000000001, 1, nullptr, STRUCT_OFFSET(Agenerator, GathererCount), METADATA_PARAMS(Z_Construct_UClass_Agenerator_Statics::NewProp_GathererCount_MetaData, ARRAY_COUNT(Z_Construct_UClass_Agenerator_Statics::NewProp_GathererCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Agenerator_Statics::NewProp_HunterCount_MetaData[] = {
		{ "Category", "InitialGeneratingSettings" },
		{ "ModuleRelativePath", "generator.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_Agenerator_Statics::NewProp_HunterCount = { UE4CodeGen_Private::EPropertyClass::Int, "HunterCount", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000000001, 1, nullptr, STRUCT_OFFSET(Agenerator, HunterCount), METADATA_PARAMS(Z_Construct_UClass_Agenerator_Statics::NewProp_HunterCount_MetaData, ARRAY_COUNT(Z_Construct_UClass_Agenerator_Statics::NewProp_HunterCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Agenerator_Statics::NewProp_genTimer_MetaData[] = {
		{ "Category", "InitialGeneratingSettings" },
		{ "ModuleRelativePath", "generator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_Agenerator_Statics::NewProp_genTimer = { UE4CodeGen_Private::EPropertyClass::Float, "genTimer", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000020001, 1, nullptr, STRUCT_OFFSET(Agenerator, genTimer), METADATA_PARAMS(Z_Construct_UClass_Agenerator_Statics::NewProp_genTimer_MetaData, ARRAY_COUNT(Z_Construct_UClass_Agenerator_Statics::NewProp_genTimer_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Agenerator_Statics::NewProp_genTime_MetaData[] = {
		{ "Category", "InitialGeneratingSettings" },
		{ "ModuleRelativePath", "generator.h" },
		{ "ToolTip", "variables\ngenTime: the time for spawning food\ngenTimer: the time incementer for detemine spawn food or not" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_Agenerator_Statics::NewProp_genTime = { UE4CodeGen_Private::EPropertyClass::Float, "genTime", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000020001, 1, nullptr, STRUCT_OFFSET(Agenerator, genTime), METADATA_PARAMS(Z_Construct_UClass_Agenerator_Statics::NewProp_genTime_MetaData, ARRAY_COUNT(Z_Construct_UClass_Agenerator_Statics::NewProp_genTime_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_Agenerator_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Agenerator_Statics::NewProp_HiderCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Agenerator_Statics::NewProp_GathererCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Agenerator_Statics::NewProp_HunterCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Agenerator_Statics::NewProp_genTimer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Agenerator_Statics::NewProp_genTime,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_Agenerator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Agenerator>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_Agenerator_Statics::ClassParams = {
		&Agenerator::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_Agenerator_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_Agenerator_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_Agenerator_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_Agenerator_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_Agenerator()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_Agenerator_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(Agenerator, 850400514);
	static FCompiledInDefer Z_CompiledInDefer_UClass_Agenerator(Z_Construct_UClass_Agenerator, &Agenerator::StaticClass, TEXT("/Script/MyProject"), TEXT("Agenerator"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(Agenerator);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
