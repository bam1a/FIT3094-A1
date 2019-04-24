// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MYPROJECT_PathNode_generated_h
#error "PathNode.generated.h already included, missing '#pragma once' in PathNode.h"
#endif
#define MYPROJECT_PathNode_generated_h

#define MyProject_Source_MyProject_PathNode_h_12_RPC_WRAPPERS
#define MyProject_Source_MyProject_PathNode_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define MyProject_Source_MyProject_PathNode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPathNode(); \
	friend struct Z_Construct_UClass_APathNode_Statics; \
public: \
	DECLARE_CLASS(APathNode, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(APathNode)


#define MyProject_Source_MyProject_PathNode_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAPathNode(); \
	friend struct Z_Construct_UClass_APathNode_Statics; \
public: \
	DECLARE_CLASS(APathNode, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(APathNode)


#define MyProject_Source_MyProject_PathNode_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APathNode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APathNode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APathNode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APathNode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APathNode(APathNode&&); \
	NO_API APathNode(const APathNode&); \
public:


#define MyProject_Source_MyProject_PathNode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APathNode(APathNode&&); \
	NO_API APathNode(const APathNode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APathNode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APathNode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APathNode)


#define MyProject_Source_MyProject_PathNode_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh() { return STRUCT_OFFSET(APathNode, Mesh); } \
	FORCEINLINE static uint32 __PPO__neighbourNode() { return STRUCT_OFFSET(APathNode, neighbourNode); } \
	FORCEINLINE static uint32 __PPO__nValidRadius() { return STRUCT_OFFSET(APathNode, nValidRadius); }


#define MyProject_Source_MyProject_PathNode_h_9_PROLOG
#define MyProject_Source_MyProject_PathNode_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Source_MyProject_PathNode_h_12_PRIVATE_PROPERTY_OFFSET \
	MyProject_Source_MyProject_PathNode_h_12_RPC_WRAPPERS \
	MyProject_Source_MyProject_PathNode_h_12_INCLASS \
	MyProject_Source_MyProject_PathNode_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProject_Source_MyProject_PathNode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Source_MyProject_PathNode_h_12_PRIVATE_PROPERTY_OFFSET \
	MyProject_Source_MyProject_PathNode_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProject_Source_MyProject_PathNode_h_12_INCLASS_NO_PURE_DECLS \
	MyProject_Source_MyProject_PathNode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProject_Source_MyProject_PathNode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
