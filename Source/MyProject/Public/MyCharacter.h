// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"


#include "SlateApplication.h"

#include "Voice.h"
#include "OnlineSubsystemUtils.h"
#include "Sound/SoundWaveProcedural.h"
#include "MyCharacter.generated.h"

UCLASS()
class MYPROJECT_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()



public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
		float VoiceCaptureVolume;

	UPROPERTY()
		bool VoiceCaptureTest;
	UPROPERTY()
		bool PlayVoiceCaptureFlag;

	UPROPERTY()
		FTimerHandle VoiceCaptureTickTimer;
	UPROPERTY()
		FTimerHandle PlayVoiceCaptureTimer;

	TSharedPtr<class IVoiceCapture> VoiceCapture;

	UPROPERTY()
		USoundWaveProcedural* VoiceCaptureSoundWaveProcedural;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		UAudioComponent* VoiceCaptureAudioComponent;

	UPROPERTY()
		TArray<uint8> VoiceCaptureBuffer;

	UFUNCTION()
		void VoiceCaptureTick();

	UFUNCTION()
		void PlayVoiceCapture();
	
	
};
