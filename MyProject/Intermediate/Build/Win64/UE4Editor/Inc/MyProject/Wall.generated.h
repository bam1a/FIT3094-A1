// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MYPROJECT_Wall_generated_h
#error "Wall.generated.h already included, missing '#pragma once' in Wall.h"
#endif
#define MYPROJECT_Wall_generated_h

#define MyProject_Source_MyProject_Wall_h_12_RPC_WRAPPERS
#define MyProject_Source_MyProject_Wall_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define MyProject_Source_MyProject_Wall_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWall(); \
	friend struct Z_Construct_UClass_AWall_Statics; \
public: \
	DECLARE_CLASS(AWall, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(AWall)


#define MyProject_Source_MyProject_Wall_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAWall(); \
	friend struct Z_Construct_UClass_AWall_Statics; \
public: \
	DECLARE_CLASS(AWall, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(AWall)


#define MyProject_Source_MyProject_Wall_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWall(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AWall) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWall); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWall); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWall(AWall&&); \
	NO_API AWall(const AWall&); \
public:


#define MyProject_Source_MyProject_Wall_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWall(AWall&&); \
	NO_API AWall(const AWall&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWall); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWall); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWall)


#define MyProject_Source_MyProject_Wall_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh() { return STRUCT_OFFSET(AWall, Mesh); }


#define MyProject_Source_MyProject_Wall_h_9_PROLOG
#define MyProject_Source_MyProject_Wall_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Source_MyProject_Wall_h_12_PRIVATE_PROPERTY_OFFSET \
	MyProject_Source_MyProject_Wall_h_12_RPC_WRAPPERS \
	MyProject_Source_MyProject_Wall_h_12_INCLASS \
	MyProject_Source_MyProject_Wall_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProject_Source_MyProject_Wall_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Source_MyProject_Wall_h_12_PRIVATE_PROPERTY_OFFSET \
	MyProject_Source_MyProject_Wall_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProject_Source_MyProject_Wall_h_12_INCLASS_NO_PURE_DECLS \
	MyProject_Source_MyProject_Wall_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProject_Source_MyProject_Wall_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
