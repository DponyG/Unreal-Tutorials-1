// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class ExcapeFromRoom2Target : TargetRules
{
	public ExcapeFromRoom2Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "ExcapeFromRoom2" } );
	}
}
