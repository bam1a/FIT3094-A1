// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/Creature.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCreature() {}
// Cross Module References
	MYPROJECT_API UClass* Z_Construct_UClass_ACreature_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_ACreature();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_MyProject();
	MYPROJECT_API UClass* Z_Construct_UClass_Agenerator_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_APathfind_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void ACreature::StaticRegisterNativesACreature()
	{
	}
	UClass* Z_Construct_UClass_ACreature_NoRegister()
	{
		return ACreature::StaticClass();
	}
	struct Z_Construct_UClass_ACreature_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_cGenerator_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_cGenerator;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_cPathfinder_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_cPathfinder;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_cPathlist_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_cPathlist;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_cPathlist_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_cPathlistID_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_cPathlistID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_cHP_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_cHP;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Mesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACreature_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACreature_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Creature.h" },
		{ "ModuleRelativePath", "Creature.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACreature_Statics::NewProp_cGenerator_MetaData[] = {
		{ "Category", "Creature" },
		{ "ModuleRelativePath", "Creature.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACreature_Statics::NewProp_cGenerator = { UE4CodeGen_Private::EPropertyClass::Object, "cGenerator", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000020001, 1, nullptr, STRUCT_OFFSET(ACreature, cGenerator), Z_Construct_UClass_Agenerator_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACreature_Statics::NewProp_cGenerator_MetaData, ARRAY_COUNT(Z_Construct_UClass_ACreature_Statics::NewProp_cGenerator_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACreature_Statics::NewProp_cPathfinder_MetaData[] = {
		{ "Category", "pathFinding" },
		{ "ModuleRelativePath", "Creature.h" },
		{ "ToolTip", "int cTargetNodeID;" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACreature_Statics::NewProp_cPathfinder = { UE4CodeGen_Private::EPropertyClass::Object, "cPathfinder", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000020001, 1, nullptr, STRUCT_OFFSET(ACreature, cPathfinder), Z_Construct_UClass_APathfind_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACreature_Statics::NewProp_cPathfinder_MetaData, ARRAY_COUNT(Z_Construct_UClass_ACreature_Statics::NewProp_cPathfinder_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACreature_Statics::NewProp_cPathlist_MetaData[] = {
		{ "Category", "Creature" },
		{ "ModuleRelativePath", "Creature.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ACreature_Statics::NewProp_cPathlist = { UE4CodeGen_Private::EPropertyClass::Array, "cPathlist", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000000001, 1, nullptr, STRUCT_OFFSET(ACreature, cPathlist), METADATA_PARAMS(Z_Construct_UClass_ACreature_Statics::NewProp_cPathlist_MetaData, ARRAY_COUNT(Z_Construct_UClass_ACreature_Statics::NewProp_cPathlist_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ACreature_Statics::NewProp_cPathlist_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "cPathlist", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACreature_Statics::NewProp_cPathlistID_MetaData[] = {
		{ "Category", "Creature" },
		{ "ModuleRelativePath", "Creature.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ACreature_Statics::NewProp_cPathlistID = { UE4CodeGen_Private::EPropertyClass::Int, "cPathlistID", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000020001, 1, nullptr, STRUCT_OFFSET(ACreature, cPathlistID), METADATA_PARAMS(Z_Construct_UClass_ACreature_Statics::NewProp_cPathlistID_MetaData, ARRAY_COUNT(Z_Construct_UClass_ACreature_Statics::NewProp_cPathlistID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACreature_Statics::NewProp_cHP_MetaData[] = {
		{ "Category", "Creature" },
		{ "ModuleRelativePath", "Creature.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ACreature_Statics::NewProp_cHP = { UE4CodeGen_Private::EPropertyClass::Int, "cHP", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000000001, 1, nullptr, STRUCT_OFFSET(ACreature, cHP), METADATA_PARAMS(Z_Construct_UClass_ACreature_Statics::NewProp_cHP_MetaData, ARRAY_COUNT(Z_Construct_UClass_ACreature_Statics::NewProp_cHP_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACreature_Statics::NewProp_Mesh_MetaData[] = {
		{ "Category", "Creature" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Creature.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACreature_Statics::NewProp_Mesh = { UE4CodeGen_Private::EPropertyClass::Object, "Mesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000080009, 1, nullptr, STRUCT_OFFSET(ACreature, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACreature_Statics::NewProp_Mesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_ACreature_Statics::NewProp_Mesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACreature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACreature_Statics::NewProp_cGenerator,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACreature_Statics::NewProp_cPathfinder,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACreature_Statics::NewProp_cPathlist,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACreature_Statics::NewProp_cPathlist_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACreature_Statics::NewProp_cPathlistID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACreature_Statics::NewProp_cHP,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACreature_Statics::NewProp_Mesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACreature_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACreature>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACreature_Statics::ClassParams = {
		&ACreature::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_ACreature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ACreature_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ACreature_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ACreature_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACreature()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACreature_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACreature, 550211233);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACreature(Z_Construct_UClass_ACreature, &ACreature::StaticClass, TEXT("/Script/MyProject"), TEXT("ACreature"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACreature);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
