// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MYPROJECT_Hunter_generated_h
#error "Hunter.generated.h already included, missing '#pragma once' in Hunter.h"
#endif
#define MYPROJECT_Hunter_generated_h

#define MyProject_Source_MyProject_Hunter_h_16_RPC_WRAPPERS
#define MyProject_Source_MyProject_Hunter_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define MyProject_Source_MyProject_Hunter_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHunter(); \
	friend struct Z_Construct_UClass_AHunter_Statics; \
public: \
	DECLARE_CLASS(AHunter, ACreature, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(AHunter)


#define MyProject_Source_MyProject_Hunter_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAHunter(); \
	friend struct Z_Construct_UClass_AHunter_Statics; \
public: \
	DECLARE_CLASS(AHunter, ACreature, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(AHunter)


#define MyProject_Source_MyProject_Hunter_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AHunter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AHunter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHunter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHunter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHunter(AHunter&&); \
	NO_API AHunter(const AHunter&); \
public:


#define MyProject_Source_MyProject_Hunter_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHunter(AHunter&&); \
	NO_API AHunter(const AHunter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHunter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHunter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AHunter)


#define MyProject_Source_MyProject_Hunter_h_16_PRIVATE_PROPERTY_OFFSET
#define MyProject_Source_MyProject_Hunter_h_13_PROLOG
#define MyProject_Source_MyProject_Hunter_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Source_MyProject_Hunter_h_16_PRIVATE_PROPERTY_OFFSET \
	MyProject_Source_MyProject_Hunter_h_16_RPC_WRAPPERS \
	MyProject_Source_MyProject_Hunter_h_16_INCLASS \
	MyProject_Source_MyProject_Hunter_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProject_Source_MyProject_Hunter_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Source_MyProject_Hunter_h_16_PRIVATE_PROPERTY_OFFSET \
	MyProject_Source_MyProject_Hunter_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProject_Source_MyProject_Hunter_h_16_INCLASS_NO_PURE_DECLS \
	MyProject_Source_MyProject_Hunter_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProject_Source_MyProject_Hunter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
