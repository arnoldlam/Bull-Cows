// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to the Bull Cows game!"));
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver == true)
    {
        ClearScreen();
        SetupGame();
    }
    else 
    {
        CheckGuess(Input);
    }     
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("lakes"); 
    HiddenWordLength = HiddenWord.Len();
    Lives = HiddenWordLength;
    bGameOver = false; 

    PrintLine(TEXT("Guess the %i-letter word press enter."), HiddenWordLength);
}

void UBullCowCartridge::EndGame() 
{
    bGameOver = true;
    PrintLine(TEXT("Please press enter to play again..."));
}

void UBullCowCartridge::CheckGuess(FString Guess)
{
    int32 GuessLength = Guess.Len();

    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You won!"));
        EndGame();
        return;
    }
    
    --Lives;

    if (Lives == 0)
    {
        PrintLine(TEXT("You ran out of lives. You lost."));
        EndGame();
        return;
    }
    // Check letters
    if (GuessLength != HiddenWordLength)
    {
        PrintLine(TEXT("The hidden word is %i characters long."), HiddenWordLength);
    }
    PrintLine(TEXT("Please try again. You have %i lives left."), Lives);
}