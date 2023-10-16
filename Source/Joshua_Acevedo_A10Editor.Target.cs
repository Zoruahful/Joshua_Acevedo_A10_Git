// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Joshua_Acevedo_A10EditorTarget : TargetRules
{
	public Joshua_Acevedo_A10EditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "Joshua_Acevedo_A10" } );
	}
}
