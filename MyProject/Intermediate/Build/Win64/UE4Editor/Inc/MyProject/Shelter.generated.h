// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MYPROJECT_Shelter_generated_h
#error "Shelter.generated.h already included, missing '#pragma once' in Shelter.h"
#endif
#define MYPROJECT_Shelter_generated_h

#define MyProject_Source_MyProject_Shelter_h_15_RPC_WRAPPERS
#define MyProject_Source_MyProject_Shelter_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define MyProject_Source_MyProject_Shelter_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAShelter(); \
	friend struct Z_Construct_UClass_AShelter_Statics; \
public: \
	DECLARE_CLASS(AShelter, APathNode, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(AShelter)


#define MyProject_Source_MyProject_Shelter_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAShelter(); \
	friend struct Z_Construct_UClass_AShelter_Statics; \
public: \
	DECLARE_CLASS(AShelter, APathNode, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(AShelter)


#define MyProject_Source_MyProject_Shelter_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AShelter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AShelter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShelter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShelter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShelter(AShelter&&); \
	NO_API AShelter(const AShelter&); \
public:


#define MyProject_Source_MyProject_Shelter_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AShelter() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShelter(AShelter&&); \
	NO_API AShelter(const AShelter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShelter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShelter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AShelter)


#define MyProject_Source_MyProject_Shelter_h_15_PRIVATE_PROPERTY_OFFSET
#define MyProject_Source_MyProject_Shelter_h_12_PROLOG
#define MyProject_Source_MyProject_Shelter_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Source_MyProject_Shelter_h_15_PRIVATE_PROPERTY_OFFSET \
	MyProject_Source_MyProject_Shelter_h_15_RPC_WRAPPERS \
	MyProject_Source_MyProject_Shelter_h_15_INCLASS \
	MyProject_Source_MyProject_Shelter_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProject_Source_MyProject_Shelter_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Source_MyProject_Shelter_h_15_PRIVATE_PROPERTY_OFFSET \
	MyProject_Source_MyProject_Shelter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProject_Source_MyProject_Shelter_h_15_INCLASS_NO_PURE_DECLS \
	MyProject_Source_MyProject_Shelter_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProject_Source_MyProject_Shelter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
