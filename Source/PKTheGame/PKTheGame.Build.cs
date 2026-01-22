// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PKTheGame : ModuleRules
{
	public PKTheGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"PKTheGame",
			"PKTheGame/Variant_Platforming",
			"PKTheGame/Variant_Platforming/Animation",
			"PKTheGame/Variant_Combat",
			"PKTheGame/Variant_Combat/AI",
			"PKTheGame/Variant_Combat/Animation",
			"PKTheGame/Variant_Combat/Gameplay",
			"PKTheGame/Variant_Combat/Interfaces",
			"PKTheGame/Variant_Combat/UI",
			"PKTheGame/Variant_SideScrolling",
			"PKTheGame/Variant_SideScrolling/AI",
			"PKTheGame/Variant_SideScrolling/Gameplay",
			"PKTheGame/Variant_SideScrolling/Interfaces",
			"PKTheGame/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
