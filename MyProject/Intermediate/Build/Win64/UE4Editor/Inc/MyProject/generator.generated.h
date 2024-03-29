// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MYPROJECT_generator_generated_h
#error "generator.generated.h already included, missing '#pragma once' in generator.h"
#endif
#define MYPROJECT_generator_generated_h

#define MyProject_Source_MyProject_generator_h_12_RPC_WRAPPERS
#define MyProject_Source_MyProject_generator_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define MyProject_Source_MyProject_generator_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAgenerator(); \
	friend struct Z_Construct_UClass_Agenerator_Statics; \
public: \
	DECLARE_CLASS(Agenerator, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(Agenerator)


#define MyProject_Source_MyProject_generator_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAgenerator(); \
	friend struct Z_Construct_UClass_Agenerator_Statics; \
public: \
	DECLARE_CLASS(Agenerator, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(Agenerator)


#define MyProject_Source_MyProject_generator_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API Agenerator(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(Agenerator) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, Agenerator); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(Agenerator); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API Agenerator(Agenerator&&); \
	NO_API Agenerator(const Agenerator&); \
public:


#define MyProject_Source_MyProject_generator_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API Agenerator(Agenerator&&); \
	NO_API Agenerator(const Agenerator&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, Agenerator); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(Agenerator); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(Agenerator)


#define MyProject_Source_MyProject_generator_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__genTime() { return STRUCT_OFFSET(Agenerator, genTime); } \
	FORCEINLINE static uint32 __PPO__genTimer() { return STRUCT_OFFSET(Agenerator, genTimer); } \
	FORCEINLINE static uint32 __PPO__foodGenCount() { return STRUCT_OFFSET(Agenerator, foodGenCount); } \
	FORCEINLINE static uint32 __PPO__HunterCount() { return STRUCT_OFFSET(Agenerator, HunterCount); } \
	FORCEINLINE static uint32 __PPO__GathererCount() { return STRUCT_OFFSET(Agenerator, GathererCount); } \
	FORCEINLINE static uint32 __PPO__HiderCount() { return STRUCT_OFFSET(Agenerator, HiderCount); }


#define MyProject_Source_MyProject_generator_h_9_PROLOG
#define MyProject_Source_MyProject_generator_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Source_MyProject_generator_h_12_PRIVATE_PROPERTY_OFFSET \
	MyProject_Source_MyProject_generator_h_12_RPC_WRAPPERS \
	MyProject_Source_MyProject_generator_h_12_INCLASS \
	MyProject_Source_MyProject_generator_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProject_Source_MyProject_generator_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Source_MyProject_generator_h_12_PRIVATE_PROPERTY_OFFSET \
	MyProject_Source_MyProject_generator_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProject_Source_MyProject_generator_h_12_INCLASS_NO_PURE_DECLS \
	MyProject_Source_MyProject_generator_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProject_Source_MyProject_generator_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
