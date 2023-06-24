// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class MVaniaSkills426 : ModuleRules
{
	public MVaniaSkills426(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG" });
		PublicDependencyModuleNames.AddRange(new string[] { "Blutility", "EditorScriptingUtilities", "UnrealEd", "MaterialEditor", "CascadeToNiagaraConverter" });
		PublicDependencyModuleNames.AddRange(new string[] { "SlateCore", "NavigationSystem" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
		MinFilesUsingPrecompiledHeaderOverride = 1;
		bFasterWithoutUnity = true;
		PrivateIncludePaths.AddRange(new string[] { System.IO.Path.GetFullPath(Target.RelativeEnginePath) + "Source/Editor/Blutility/Private" });
		// Uncomment if you are using Slate UIMVAuto
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
