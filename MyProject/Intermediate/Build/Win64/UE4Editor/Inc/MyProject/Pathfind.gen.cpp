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
	const FCppClassTypeInfoStatic Z_Construct_UClass_APathfind_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APathfind>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APathfind_Statics::ClassParams = {
		&APathfind::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
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
	IMPLEMENT_CLASS(APathfind, 3058855105);
	static FCompiledInDefer Z_CompiledInDefer_UClass_APathfind(Z_Construct_UClass_APathfind, &APathfind::StaticClass, TEXT("/Script/MyProject"), TEXT("APathfind"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APathfind);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
