// Copyright Input Eater Creations, LLC

#include "IET_StdLibBPLibrary.h"
#include "IET_StdLib.h"
//#include "Widgets/SWidget.h"

UIET_StdLibBPLibrary::UIET_StdLibBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

/*
float UIET_StdLibBPLibrary::IETSL_SampleFunction(float Param) {
	return -1;
}
*/

FVector UIET_StdLibBPLibrary::IETSL_WorldToLocalSpace(FVector WorldVector, FRotator WorldRotation) {
	FVector LocalVector = WorldRotation.GetInverse().RotateVector(WorldVector);
	return LocalVector;
}

int32 UIET_StdLibBPLibrary::IETSL_GetIntArraySum(TArray<int32> IntArray) {
	int32 Count = 0;
	for (auto& IntElem : IntArray) {
		Count += IntElem;
	}
	return Count;
}

float UIET_StdLibBPLibrary::IETSL_GetFloatArraySum(TArray<float> FloatArray) {
	float Count = 0.f;
	for (auto& FloatElem : FloatArray) {
		Count += FloatElem;
	}
	return Count;
}

float UIET_StdLibBPLibrary::IETSL_GetFloatArrayAverage(TArray<float> FloatArray) {
	float Total = 0.f;
	for (auto& FloatElem : FloatArray) {
		Total += FloatElem;
	}
	return Total / FloatArray.Num();
}

FVector UIET_StdLibBPLibrary::IETSL_GetMidpoint(FVector A, FVector B) {
	FVector Difference = B - A;
	return A + (Difference.GetSafeNormal(0.001f) * (Difference.Size() / 2));
}

int32 UIET_StdLibBPLibrary::IETSL_GetRandomSeedFromVector(FTransform InTransform) {
	float Total = 
		InTransform.GetRotation().W + 
		InTransform.GetRotation().X + 
		InTransform.GetRotation().Y + 
		InTransform.GetRotation().Z + 
		InTransform.GetTranslation().X + 
		InTransform.GetTranslation().Y + 
		InTransform.GetTranslation().Z + 
		InTransform.GetScale3D().X + 
		InTransform.GetScale3D().Y + 
		InTransform.GetScale3D().Z;
	return FMath::RoundHalfFromZero(Total);
}

FVector UIET_StdLibBPLibrary::IETSL_CalculateVelocity(FVector CurrentPosition, FVector PreviousFramePosition, float DeltaTime) {
	FVector Difference = CurrentPosition - PreviousFramePosition;
	return Difference / DeltaTime;
}

int32 UIET_StdLibBPLibrary::IETSL_GetIndexStep(int32 CurrentIndex, int32 MinIndex, int32 MaxIndex, bool StepBackwards, bool WillCycle) {
	if (CurrentIndex == MinIndex) {
		if (StepBackwards) {
			if (WillCycle) { return MaxIndex; }
			else { return CurrentIndex; }
		}
		else {
			return CurrentIndex + 1;
		}
	}
	else if (CurrentIndex == MaxIndex) {
		if (StepBackwards) {
			return CurrentIndex - 1;
		}
		else {
			if (WillCycle) { return MinIndex; }
			else { return CurrentIndex; }
		}
	}
	else {
		if (StepBackwards) {
			return CurrentIndex - 1;
		}
		else {
			return CurrentIndex + 1;
		}
	}
	return -1;
}

FVector UIET_StdLibBPLibrary::IET_ApplyGravityToVelocityVector(FVector Velocity, float Gravity, float WorldDeltaSeconds) {
	return FVector(Velocity.X, Velocity.Y, Velocity.Z - (Gravity * WorldDeltaSeconds));
}

float UIET_StdLibBPLibrary::IETSL_GetVectorAverage(FVector InVector) {
	return ((InVector.X + InVector.Y + InVector.Z) / 3.f);
}

FVector UIET_StdLibBPLibrary::IETSL_ClampVectorComponents(FVector InVector, FVector Min, FVector Max) {
	return FVector(
		FMath::Clamp(InVector.X, Min.X, Max.X),
		FMath::Clamp(InVector.Y, Min.Y, Max.Y),
		FMath::Clamp(InVector.Z, Min.Z, Max.Z)
	);
}

FVector2D UIET_StdLibBPLibrary::IETSL_ClampVector2DComponents(FVector2D InVector, FVector2D Min, FVector2D Max) {
	return FVector2D(
		FMath::Clamp(InVector.X, Min.X, Max.X),
		FMath::Clamp(InVector.Y, Min.Y, Max.Y)
	);
}

FTransform UIET_StdLibBPLibrary::IETSL_DeltaTransform(FTransform A, FTransform B) {
	return FTransform(FRotator(0.f,0.f,0.f),FVector(0.f,0.f,0.f),FVector(0.f,0.f,0.f));
}

FTransform UIET_StdLibBPLibrary::IETSL_DiscardTransformScale(FTransform InTransform) {
	return FTransform(
		InTransform.GetRotation(),
		InTransform.GetTranslation(),
		FVector(1.f,1.f,1.f)
	);
}

FVector UIET_StdLibBPLibrary::IETSL_ProjectPositionWithVelocityAndTime(FVector Position, FVector Velocity, float Time) {
	return Position + (Velocity * Time);
}

float UIET_StdLibBPLibrary::IETSL_CalculateTimeFromPositionsAndSpeed(float Speed, FVector Start, FVector Destination) {
	return (Destination - Start).Size() / Speed;
}

FVector UIET_StdLibBPLibrary::IETSL_CalculateShotVector(FVector TargetPosition, FVector TargetVelocity, FVector OwnPosition, FVector OwnVelocity, float ProjectileSpeed, int32 Iterations, float LeadMultiplier) {
	FVector CurrentProjectedVector = TargetPosition;
	float CurrentTimeTaken = 0.f;
	for (int32 i = 1; i <= Iterations; i++) {
		CurrentTimeTaken = UIET_StdLibBPLibrary::IETSL_CalculateTimeFromPositionsAndSpeed(ProjectileSpeed, OwnPosition, CurrentProjectedVector) * LeadMultiplier;
		CurrentProjectedVector = UIET_StdLibBPLibrary::IETSL_ProjectPositionWithVelocityAndTime(TargetPosition, TargetVelocity, CurrentTimeTaken);
	}
	return CurrentProjectedVector;
}

/*
void UIET_StdLibBPLibrary::IETSL_SwitchMenuByWidget(TArray<SWidget*> AllWidgetsArray) {
	UWidget* test = nullptr;
	return;
}
*/

/*
float UIET_StdLibBPLibrary::IETSL_GetWorldGravity() {
	return GetWorld()->GetWorldSettings()->GetGravityZ();
}
*/