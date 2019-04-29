// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MYPROJECT_FoodGen_generated_h
#error "FoodGen.generated.h already included, missing '#pragma once' in FoodGen.h"
#endif
#define MYPROJECT_FoodGen_generated_h

#define MyProject_Source_MyProject_FoodGen_h_13_RPC_WRAPPERS
#define MyProject_Source_MyProject_FoodGen_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define MyProject_Source_MyProject_FoodGen_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFoodGen(); \
	friend struct Z_Construct_UClass_AFoodGen_Statics; \
public: \
	DECLARE_CLASS(AFoodGen, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(AFoodGen)


#define MyProject_Source_MyProject_FoodGen_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAFoodGen(); \
	friend struct Z_Construct_UClass_AFoodGen_Statics; \
public: \
	DECLARE_CLASS(AFoodGen, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(AFoodGen)


#define MyProject_Source_MyProject_FoodGen_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFoodGen(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFoodGen) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFoodGen); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFoodGen); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFoodGen(AFoodGen&&); \
	NO_API AFoodGen(const AFoodGen&); \
public:


#define MyProject_Source_MyProject_FoodGen_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFoodGen(AFoodGen&&); \
	NO_API AFoodGen(const AFoodGen&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFoodGen); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFoodGen); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFoodGen)


#define MyProject_Source_MyProject_FoodGen_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__defaultTime() { return STRUCT_OFFSET(AFoodGen, defaultTime); } \
	FORCEINLINE static uint32 __PPO__randomTime() { return STRUCT_OFFSET(AFoodGen, randomTime); }


#define MyProject_Source_MyProject_FoodGen_h_10_PROLOG
#define MyProject_Source_MyProject_FoodGen_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Source_MyProject_FoodGen_h_13_PRIVATE_PROPERTY_OFFSET \
	MyProject_Source_MyProject_FoodGen_h_13_RPC_WRAPPERS \
	MyProject_Source_MyProject_FoodGen_h_13_INCLASS \
	MyProject_Source_MyProject_FoodGen_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProject_Source_MyProject_FoodGen_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Source_MyProject_FoodGen_h_13_PRIVATE_PROPERTY_OFFSET \
	MyProject_Source_MyProject_FoodGen_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProject_Source_MyProject_FoodGen_h_13_INCLASS_NO_PURE_DECLS \
	MyProject_Source_MyProject_FoodGen_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProject_Source_MyProject_FoodGen_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
