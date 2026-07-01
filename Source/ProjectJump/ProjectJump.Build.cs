// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProjectJump : ModuleRules
{
	public ProjectJump(ReadOnlyTargetRules Target) : base(Target)
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
			"ProjectJump",
			"ProjectJump/Variant_Platforming",
			"ProjectJump/Variant_Platforming/Animation",
			"ProjectJump/Variant_Combat",
			"ProjectJump/Variant_Combat/AI",
			"ProjectJump/Variant_Combat/Animation",
			"ProjectJump/Variant_Combat/Gameplay",
			"ProjectJump/Variant_Combat/Interfaces",
			"ProjectJump/Variant_Combat/UI",
			"ProjectJump/Variant_SideScrolling",
			"ProjectJump/Variant_SideScrolling/AI",
			"ProjectJump/Variant_SideScrolling/Gameplay",
			"ProjectJump/Variant_SideScrolling/Interfaces",
			"ProjectJump/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
