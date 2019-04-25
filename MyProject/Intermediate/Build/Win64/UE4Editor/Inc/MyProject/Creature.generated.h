// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MYPROJECT_Creature_generated_h
#error "Creature.generated.h already included, missing '#pragma once' in Creature.h"
#endif
#define MYPROJECT_Creature_generated_h

#define MyProject_Source_MyProject_Creature_h_17_RPC_WRAPPERS
#define MyProject_Source_MyProject_Creature_h_17_RPC_WRAPPERS_NO_PURE_DECLS
#define MyProject_Source_MyProject_Creature_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACreature(); \
	friend struct Z_Construct_UClass_ACreature_Statics; \
public: \
	DECLARE_CLASS(ACreature, APawn, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(ACreature)


#define MyProject_Source_MyProject_Creature_h_17_INCLASS \
private: \
	static void StaticRegisterNativesACreature(); \
	friend struct Z_Construct_UClass_ACreature_Statics; \
public: \
	DECLARE_CLASS(ACreature, APawn, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(ACreature)


#define MyProject_Source_MyProject_Creature_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACreature(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACreature) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACreature); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACreature); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACreature(ACreature&&); \
	NO_API ACreature(const ACreature&); \
public:


#define MyProject_Source_MyProject_Creature_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACreature(ACreature&&); \
	NO_API ACreature(const ACreature&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACreature); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACreature); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACreature)


#define MyProject_Source_MyProject_Creature_h_17_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh() { return STRUCT_OFFSET(ACreature, Mesh); }


#define MyProject_Source_MyProject_Creature_h_14_PROLOG
#define MyProject_Source_MyProject_Creature_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Source_MyProject_Creature_h_17_PRIVATE_PROPERTY_OFFSET \
	MyProject_Source_MyProject_Creature_h_17_RPC_WRAPPERS \
	MyProject_Source_MyProject_Creature_h_17_INCLASS \
	MyProject_Source_MyProject_Creature_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProject_Source_MyProject_Creature_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Source_MyProject_Creature_h_17_PRIVATE_PROPERTY_OFFSET \
	MyProject_Source_MyProject_Creature_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProject_Source_MyProject_Creature_h_17_INCLASS_NO_PURE_DECLS \
	MyProject_Source_MyProject_Creature_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProject_Source_MyProject_Creature_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
