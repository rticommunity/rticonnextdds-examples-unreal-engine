// Fill out your copyright notice in the Description page of Project Settings.

using System;
using System.IO;

using UnrealBuildTool;

public class ConnextExample : ModuleRules
{
	public ConnextExample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "ChaosVehicles" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		string nddshome = Environment.GetEnvironmentVariable("NDDSHOME");
        PrivateIncludePaths.Add(Path.Combine(nddshome, "include"));
        PrivateIncludePaths.Add(Path.Combine(nddshome, "include/ndds"));

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            // Use if you want to statically link RTI Connext libraries
            PrivateDefinitions.Add("WIN32");
            PrivateDefinitions.Add("RTI_STATIC");
            PrivateDefinitions.Add("WIN32_LEAN_AND_MEAN");
            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscppz.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscz.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscorez.lib"));

            // Uncomment to use dynamically link RTI Connext Libraries
            //PrivateDefinitions.Add("WIN32");
            //PrivateDefinitions.Add("NDDS_DLL_VARIABLE");
            //PrivateDefinitions.Add("WIN32_LEAN_AND_MEAN");
            //PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscppd.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscd.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscored.lib"));

            //RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscppd.dll"));
            //RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscd.dll"));
            //RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscored.dll"));

            // Needed since generated type support code uses exceptions
            // bEnableExceptions = true; 
        }
        else if (Target.Platform == UnrealTargetPlatform.Linux)
        {
            // Use if you want to statically link RTI Connext libraries
            PrivateDefinitions.Add("RTI_LINUX");
            PrivateDefinitions.Add("RTI_UNIX");
            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscppz.a"));
            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscz.a"));
            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscorez.a"));

            // Uncomment to use dynamically link RTI Connext Libraries
            //PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscpp.so"));
            //PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddsc.so"));
            //PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscore.so"));
            //RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscpp.so"));
            //RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddsc.so"));
            //RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscore.so"));

            // Needed since generated type support code uses exceptions
            // bEnableExceptions = true; 
        }

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
