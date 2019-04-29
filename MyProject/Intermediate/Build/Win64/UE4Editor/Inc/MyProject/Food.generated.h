// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MYPROJECT_Food_generated_h
#error "Food.generated.h already included, missing '#pragma once' in Food.h"
#endif
#define MYPROJECT_Food_generated_h

#define MyProject_Source_MyProject_Food_h_15_RPC_WRAPPERS
#define MyProject_Source_MyProject_Food_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define MyProject_Source_MyProject_Food_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFood(); \
	friend struct Z_Construct_UClass_AFood_Statics; \
public: \
	DECLARE_CLASS(AFood, APathNode, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(AFood)


#define MyProject_Source_MyProject_Food_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAFood(); \
	friend struct Z_Construct_UClass_AFood_Statics; \
public: \
	DECLARE_CLASS(AFood, APathNode, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(AFood)


#define MyProject_Source_MyProject_Food_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFood(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFood) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFood); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFood); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFood(AFood&&); \
	NO_API AFood(const AFood&); \
public:


#define MyProject_Source_MyProject_Food_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFood(AFood&&); \
	NO_API AFood(const AFood&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFood); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFood); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFood)


#define MyProject_Source_MyProject_Food_h_15_PRIVATE_PROPERTY_OFFSET
#define MyProject_Source_MyProject_Food_h_12_PROLOG
#define MyProject_Source_MyProject_Food_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Source_MyProject_Food_h_15_PRIVATE_PROPERTY_OFFSET \
	MyProject_Source_MyProject_Food_h_15_RPC_WRAPPERS \
	MyProject_Source_MyProject_Food_h_15_INCLASS \
	MyProject_Source_MyProject_Food_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProject_Source_MyProject_Food_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Source_MyProject_Food_h_15_PRIVATE_PROPERTY_OFFSET \
	MyProject_Source_MyProject_Food_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProject_Source_MyProject_Food_h_15_INCLASS_NO_PURE_DECLS \
	MyProject_Source_MyProject_Food_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProject_Source_MyProject_Food_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
