// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "IET_StdLib.h"

#define LOCTEXT_NAMESPACE "FIET_StdLibModule"

void FIET_StdLibModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FIET_StdLibModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FIET_StdLibModule, IET_StdLib)