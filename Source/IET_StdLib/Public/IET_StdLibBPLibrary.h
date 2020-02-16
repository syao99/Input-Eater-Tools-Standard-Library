// Copyright Input Eater Creations, LLC

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
//#include "Widgets/SWidget.h"

#include "IET_StdLibBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class UIET_StdLibBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/*
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "IET_StdLib sample test testing"), Category = "IET_StdLibTesting")
	static float IETSL_SampleFunction(float Param);
	*/

	UFUNCTION(BlueprintPure, meta = (DisplayName = "World Space to Local Space", Keywords = "IET_StdLib world local space vector rotator"), Category = "Math | Vector")
	static FVector IETSL_WorldToLocalSpace(FVector WorldVector, FRotator WorldRotation);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Sum of Int Array", Keywords = "IET_StdLib int array sum"), Category = "Math | Integer")
	static int32 IETSL_GetIntArraySum(TArray<int32> IntArray);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Sum of Float Array", Keywords = "IET_StdLib int array sum"), Category = "Math | Float")
	static float IETSL_GetFloatArraySum(TArray<float> FloatArray);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Average of Float Array", Keywords = "IET_StdLib get average float array"), Category = "Math | Float")
	static float IETSL_GetFloatArrayAverage(TArray<float> FloatArray);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Midpoint", Keywords = "IET_StdLib get midpoint mid point between vector"), Category = "Math | Vector")
	static FVector IETSL_GetMidpoint(FVector A, FVector B);
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Random Seed From Transform", Keywords = "IET_StdLib get random seed int from transform"), Category = "Math | Random")
	static int32 IETSL_GetRandomSeedFromVector(FTransform InTransform);
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Calculate Velocity", Keywords = "IET_StdLib calculate get velocity vector"), Category = "Utilities | Kinematics")
	static FVector IETSL_CalculateVelocity(FVector CurrentPosition, FVector PreviousFramePosition, float DeltaTime);
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Index Step", Keywords = "IET_StdLib get index step ui select option"), Category = "Math | Integer")
	static int32 IETSL_GetIndexStep(int32 CurrentIndex, int32 MinIndex, int32 MaxIndex, bool StepBackwards, bool WillCycle);
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Apply Gravity to Velocity Vector", Keywords = "IET_StdLib gravity velocity vector"), Category = "Utilities | Kinematics")
	static FVector IET_ApplyGravityToVelocityVector(FVector Velocity, float Gravity, float WorldDeltaSeconds);
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Vector Average", Keywords = "IET_StdLib get uniform scale average vector"), Category = "Math | Vector")
	static float IETSL_GetVectorAverage(FVector Vector);
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Clamp Vector Components", Keywords = "IET_StdLib clamp vector components float"), Category = "Math | Vector")
	static FVector IETSL_ClampVectorComponents(FVector InVector, FVector Min, FVector Max);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Clamp Vector2D Components", Keywords = "IET_StdLib clamp vector vector2d 2d components float"), Category = "Math | Vector")
	static FVector2D IETSL_ClampVector2DComponents(FVector2D InVector, FVector2D Min, FVector2D Max);
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Delta (Transform)", Keywords = "IET_StdLib delta subtract minus transform"), Category = "Math | Transform")
	static FTransform IETSL_DeltaTransform(FTransform A, FTransform B);
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Discard Transform Scale", Keywords = "IET_StdLib discard remove transform scale component"), Category = "Math | Transform")
	static FTransform IETSL_DiscardTransformScale(FTransform InTransform);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Project Position with Velocity and Time", Keywords = "IET_StdLib project position velocity time delta"), Category = "Math | Vector")
	static FVector IETSL_ProjectPositionWithVelocityAndTime(FVector Position, FVector Velocity, float Time);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Calculate Time from Positions and Speed", Keywords = "IET_StdLib calculate get time position speed vector"), Category = "Math | Vector")
	static float IETSL_CalculateTimeFromPositionsAndSpeed(float Speed, FVector Start, FVector Destination);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Calculate Shot Vector", Keywords = "IET_StdLib calculate suggest shot vector direction velocity"), Category = "Math | Vector")
	static FVector IETSL_CalculateShotVector(FVector TargetPosition, FVector TargetVelocity, FVector OwnPosition, FVector OwnVelocity, float ProjectileSpeed, int32 Iterations, float LeadMultiplier);

	//UFUNCTION(BlueprintCallable, meta = (DisplayName = "Switch Menu By Widget", Keywords = "IET_StdLib switch menu by widget"), Category = "Widget")
	//static void IETSL_SwitchMenuByWidget(TArray<SWidget*> AllWidgetsArray);

	//UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get World Gravity", Keywords = "IET_StdLib get world gravity"), Category = "World")
	//float IETSL_GetWorldGravity();
};