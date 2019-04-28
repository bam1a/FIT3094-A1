// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/Pathfind.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePathfind() {}
// Cross Module References
	MYPROJECT_API UClass* Z_Construct_UClass_APathfind_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_APathfind();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MyProject();
	MYPROJECT_API UClass* Z_Construct_UClass_APathNode_NoRegister();
// End Cross Module References
	void APathfind::StaticRegisterNativesAPathfind()
	{
	}
	UClass* Z_Construct_UClass_APathfind_NoRegister()
	{
		return APathfind::StaticClass();
	}
	struct Z_Construct_UClass_APathfind_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NodeArray4Show_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_NodeArray4Show;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NodeArray4Show_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_endNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_endNode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_startNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_startNode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APathfind_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfind_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Pathfind.h" },
		{ "ModuleRelativePath", "Pathfind.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfind_Statics::NewProp_NodeArray4Show_MetaData[] = {
		{ "Category", "Pathfind" },
		{ "ModuleRelativePath", "Pathfind.h" },
		{ "ToolTip", "function for external classes use\nnodeArray: the array which contains all the path nodes\nGeneratePath: generate the path for each" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APathfind_Statics::NewProp_NodeArray4Show = { UE4CodeGen_Private::EPropertyClass::Array, "NodeArray4Show", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000020001, 1, nullptr, STRUCT_OFFSET(APathfind, NodeArray4Show), METADATA_PARAMS(Z_Construct_UClass_APathfind_Statics::NewProp_NodeArray4Show_MetaData, ARRAY_COUNT(Z_Construct_UClass_APathfind_Statics::NewProp_NodeArray4Show_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathfind_Statics::NewProp_NodeArray4Show_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "NodeArray4Show", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000020000, 1, nullptr, 0, Z_Construct_UClass_APathNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfind_Statics::NewProp_endNode_MetaData[] = {
		{ "Category", "Pathfind" },
		{ "ModuleRelativePath", "Pathfind.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathfind_Statics::NewProp_endNode = { UE4CodeGen_Private::EPropertyClass::Object, "endNode", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000020001, 1, nullptr, STRUCT_OFFSET(APathfind, endNode), Z_Construct_UClass_APathNode_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APathfind_Statics::NewProp_endNode_MetaData, ARRAY_COUNT(Z_Construct_UClass_APathfind_Statics::NewProp_endNode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfind_Statics::NewProp_startNode_MetaData[] = {
		{ "Category", "Pathfind" },
		{ "ModuleRelativePath", "Pathfind.h" },
		{ "ToolTip", "variable for searching\nstartNode: the starting node when searching\nendNode: the goal node when searching\nstartPt: the start location\nendPt: the goal position\nisFound: the switch which determines the path is found or not." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathfind_Statics::NewProp_startNode = { UE4CodeGen_Private::EPropertyClass::Object, "startNode", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000020001, 1, nullptr, STRUCT_OFFSET(APathfind, startNode), Z_Construct_UClass_APathNode_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APathfind_Statics::NewProp_startNode_MetaData, ARRAY_COUNT(Z_Construct_UClass_APathfind_Statics::NewProp_startNode_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APathfind_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfind_Statics::NewProp_NodeArray4Show,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfind_Statics::NewProp_NodeArray4Show_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfind_Statics::NewProp_endNode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfind_Statics::NewProp_startNode,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APathfind_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APathfind>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APathfind_Statics::ClassParams = {
		&APathfind::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_APathfind_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_APathfind_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_APathfind_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_APathfind_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APathfind()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APathfind_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APathfind, 4167478234);
	static FCompiledInDefer Z_CompiledInDefer_UClass_APathfind(Z_Construct_UClass_APathfind, &APathfind::StaticClass, TEXT("/Script/MyProject"), TEXT("APathfind"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APathfind);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
