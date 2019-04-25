// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/PathNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePathNode() {}
// Cross Module References
	MYPROJECT_API UClass* Z_Construct_UClass_APathNode_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_APathNode();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MyProject();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void APathNode::StaticRegisterNativesAPathNode()
	{
	}
	UClass* Z_Construct_UClass_APathNode_NoRegister()
	{
		return APathNode::StaticClass();
	}
	struct Z_Construct_UClass_APathNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_neighbourNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_neighbourNode;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_neighbourNode_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Mesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APathNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PathNode.h" },
		{ "ModuleRelativePath", "PathNode.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathNode_Statics::NewProp_neighbourNode_MetaData[] = {
		{ "Category", "NodeSettings" },
		{ "ModuleRelativePath", "PathNode.h" },
		{ "ToolTip", "connected path of the node(can be keep cognito if no neighbour.)" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APathNode_Statics::NewProp_neighbourNode = { UE4CodeGen_Private::EPropertyClass::Array, "neighbourNode", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000000001, 1, nullptr, STRUCT_OFFSET(APathNode, neighbourNode), METADATA_PARAMS(Z_Construct_UClass_APathNode_Statics::NewProp_neighbourNode_MetaData, ARRAY_COUNT(Z_Construct_UClass_APathNode_Statics::NewProp_neighbourNode_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathNode_Statics::NewProp_neighbourNode_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "neighbourNode", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_APathNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathNode_Statics::NewProp_Mesh_MetaData[] = {
		{ "Category", "PathNode" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "PathNode.h" },
		{ "ToolTip", "the bounding box mesh(if have)" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathNode_Statics::NewProp_Mesh = { UE4CodeGen_Private::EPropertyClass::Object, "Mesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000080009, 1, nullptr, STRUCT_OFFSET(APathNode, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APathNode_Statics::NewProp_Mesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_APathNode_Statics::NewProp_Mesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APathNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathNode_Statics::NewProp_neighbourNode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathNode_Statics::NewProp_neighbourNode_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathNode_Statics::NewProp_Mesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APathNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APathNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APathNode_Statics::ClassParams = {
		&APathNode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_APathNode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_APathNode_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_APathNode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_APathNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APathNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APathNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APathNode, 2664186528);
	static FCompiledInDefer Z_CompiledInDefer_UClass_APathNode(Z_Construct_UClass_APathNode, &APathNode::StaticClass, TEXT("/Script/MyProject"), TEXT("APathNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APathNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
