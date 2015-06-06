// Copyright Fortune Studios 2014-2015. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class SOSEditorTarget : TargetRules
{
	public SOSEditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
	}

	//
	// TargetRules interface.
	//

	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.AddRange( new string[] { "SOS" } );
	}
}
