#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	int i;
	char SeedInput[20];
	int StartingSeed=0;
	printf("Let's Make a Deal");
	printf("\n=================");
	printf("\nFor MATH 525 - Section 10468\nPlease Enter a starting Seed (starting point for random numbers)(any REAL #):");
	fgets(SeedInput, 20, stdin);
	for(i=0;i<20;i++){
		if(SeedInput[i]=='\n'){
			SeedInput[i]='\0';
		}
	}
	StartingSeed=atoi(SeedInput);
	srand(StartingSeed);
	int PrizeDoorChoice,UserChoice,AlwaysChangeChoice,ShownLoserDoorChoice;
	//	int FirstOrSecondLoserDoor,
	int PrizeDoorCounter1,PrizeDoorCounter2,PrizeDoorCounter3;
	int UserChoiceCounter1,UserChoiceCounter2,UserChoiceCounter3;
	int AlwaysChangeChoiceCounter1,AlwaysChangeChoiceCounter2,AlwaysChangeChoiceCounter3;	
	//int FirstOrSecondLoserDoorCounter1,FirstOrSecondLoserDoorCounter2;
	int TotalPicks;
	int AlwaysChangeWinCounter=0;
	int NeverChangeWinCounter=0;
	
	//Zero out all counters
	PrizeDoorCounter1=0;
	PrizeDoorCounter2=0;
	PrizeDoorCounter3=0;
	
	UserChoiceCounter1=0;
	UserChoiceCounter2=0;
	UserChoiceCounter3=0;
	
	AlwaysChangeChoiceCounter1=0;
	AlwaysChangeChoiceCounter2=0;
	AlwaysChangeChoiceCounter3=0;
	
	//FirstOrSecondLoserDoorCounter1=0;
	//FirstOrSecondLoserDoorCounter2=0;
	
	TotalPicks=0;

	/*
	printf("\nPrizeDoorChoice=%i,D1=%i,D2=%i,D3=%i",PrizeDoorChoice,PrizeDoorCounter1,PrizeDoorCounter2,PrizeDoorCounter3);
	printf("\nUserChoice=%i,D1=%i,D2=%i,D3=%i",UserChoice,UserChoiceCounter1,UserChoiceCounter2,UserChoiceCounter3);
	//printf("\nFirstorSecondLoserDoorChoice=%i,D1=%i,D2=%i",FirstOrSecondLoserDoor,FirstOrSecondLoserDoorCounter1,FirstOrSecondLoserDoorCounter2);
	printf("\nAlwaysChangeChoice=%i,D1=%i,D2=%i,D3=%i",AlwaysChangeChoice,AlwaysChangeChoiceCounter1,AlwaysChangeChoiceCounter2,AlwaysChangeChoiceCounter3);
	printf("\nTotalPicks Counter: %i", TotalPicks);
	*/
	
	char UserInput[20];
	int TotalRuns=0;
	printf("\nPlease Enter a Total Amount of Runs you wish to execute(1-1.4BILLION):");
	fgets(UserInput, 20, stdin);
	for(i=0;i<20;i++){
		if(UserInput[i]=='\n'){
			UserInput[i]='\0';
		}
	}
	TotalRuns=atoi(UserInput);
	
	for(i=0;i<TotalRuns;i++){
		///////////////////////////////////////////////////////////
		// Randomizers
		PrizeDoorChoice=(rand()%3)+1; //1,2,or 3
		UserChoice=(rand()%3)+1; //1,2,or 3
		//FirstOrSecondLoserDoor=(rand()%2)+1; //Are we going to *not show* the first or second loser?
		///////////////////////////////////////////////////////////
		
		///////////////////////////////////////////////////////////
		//Counters for Stats/Percentages with Error Checking for the choice Randomizers
		TotalPicks++;

			//-------------------------
			//Count and Check PrizeDoor
			if(PrizeDoorChoice==1){
				PrizeDoorCounter1++;
			}
			else if(PrizeDoorChoice==2){
				PrizeDoorCounter2++;
			}
			else if (PrizeDoorChoice==3){
				PrizeDoorCounter3++;
			}
			else{
				printf("\n\n[ERROR] -99");
				return -99; //ERROR it wasn't 1, 2, or 3
			}
			//<Error Checking>
				if(TotalPicks!=(PrizeDoorCounter1+PrizeDoorCounter2+PrizeDoorCounter3)){
					printf("\n\n[ERROR] -100");
					return -100; //ERROR total TotalPicks != the addition of the sum of each door counter
				}
			//</Error Checking>
			//-------------------------			

			//-------------------------
			//Count and Check PrizeDoor
			if(UserChoice==1){
				UserChoiceCounter1++;
			}
			else if(UserChoice==2){
				UserChoiceCounter2++;
			}
			else if (UserChoice==3){
				UserChoiceCounter3++;
			}
			else{
				printf("\n\n[ERROR] -104");
				return -104; //ERROR it wasn't 1, 2, or 3
			}
			//<Error Checking>
				if(TotalPicks!=(UserChoiceCounter1+UserChoiceCounter2+UserChoiceCounter3)){
				printf("\n\n[ERROR] -105");
				return -105; //ERROR total TotalPicks != the addition of the sum of each door counter
				}
			//</Error Checking>
			//-------------------------				
			///////////////////////////////////////////////////////////
		
		///////////////////////////////////////////////////////////
		//Random Door that is opened for a loser door)
		ShownLoserDoorChoice=PrizeDoorChoice; //Start at door 1
		do{
			ShownLoserDoorChoice++;
			if(ShownLoserDoorChoice>3){ //If were at door 3, added one, we need to start over at 1 (otherwise it's @ 4)
				ShownLoserDoorChoice=1;
			}
			if(ShownLoserDoorChoice!=PrizeDoorChoice){
				if(ShownLoserDoorChoice!=UserChoice){
					//FirstOrSecondLoserDoor--;
					break;
				}
			}
		}while(1);
		///////////////////////////////////////////////////////////
		
		///////////////////////////////////////////////////////////
		// Determine the "Aways Change Choice"
		AlwaysChangeChoice=PrizeDoorChoice; //Start at door 1
		do{
			AlwaysChangeChoice++;
			if(AlwaysChangeChoice>3){ //If were at door 3, added one, we need to start over at 1 (otherwise it's @ 4)
				AlwaysChangeChoice=1;
			}
			if(AlwaysChangeChoice!=ShownLoserDoorChoice){
				if(AlwaysChangeChoice!=UserChoice){
					//FirstOrSecondLoserDoor--;
					break;
				}
			}
		}while(1);
		//-------------------------
			//Count and Check PrizeDoor
			if(AlwaysChangeChoice==1){
				AlwaysChangeChoiceCounter1++;
			}
			else if(AlwaysChangeChoice==2){
				AlwaysChangeChoiceCounter2++;
			}
			else if (AlwaysChangeChoice==3){
				AlwaysChangeChoiceCounter3++;
			}
			else{
				printf("\n\n[ERROR] -109");
				return -109; //ERROR it wasn't 1, 2, or 3
			}
			//<Error Checking>
				if(TotalPicks!=(UserChoiceCounter1+UserChoiceCounter2+UserChoiceCounter3)){
				printf("\n\n[ERROR] -105");
				return -105; //ERROR total TotalPicks != the addition of the sum of each door counter
				}
			//</Error Checking>
			//-------------------------	
		///////////////////////////////////////////////////////////		
		
		///////////////////////////////////////////////////////////
		//Evaluate Choice for Winner
		if(AlwaysChangeChoice==PrizeDoorChoice){
			AlwaysChangeWinCounter++;
		}
		if(UserChoice==PrizeDoorChoice){
			NeverChangeWinCounter++;
		}
		///////////////////////////////////////////////////////////		
	}
	
	///////////////////////////////////////////////////////////
	// Print Final Tallies
	printf("\nChoices Summary");
	printf("\n===============");
	printf("\nLast PrizeDoorChoice=%i,D1=%i(%f),D2=%i(%f),D3=%i(%f)",PrizeDoorChoice,PrizeDoorCounter1,(float)PrizeDoorCounter1/(float)TotalPicks,PrizeDoorCounter2,(float)PrizeDoorCounter2/(float)TotalPicks,PrizeDoorCounter3,(float)PrizeDoorCounter3/(float)TotalPicks);
	printf("\nLast UserChoice=%i,D1=%i(%f),D2=%i(%f),D3=%i(%f)",UserChoice,UserChoiceCounter1,(float)UserChoiceCounter1/(float)TotalPicks,UserChoiceCounter2,(float)UserChoiceCounter2/(float)TotalPicks,UserChoiceCounter3,(float)UserChoiceCounter3/(float)TotalPicks);
	//printf("\nLast FirstorSecondLoserDoorChoice=%i,D1=%i,D2=%i",FirstOrSecondLoserDoor,FirstOrSecondLoserDoorCounter1,FirstOrSecondLoserDoorCounter2);
	printf("\nLast AlwaysChangeChoice=%i,D1=%i(%f),D2=%i(%f),D3=%i(%f)",AlwaysChangeChoice,AlwaysChangeChoiceCounter1,(float)AlwaysChangeChoiceCounter1/(float)TotalPicks,AlwaysChangeChoiceCounter2,(float)AlwaysChangeChoiceCounter2/(float)TotalPicks,AlwaysChangeChoiceCounter3,(float)AlwaysChangeChoiceCounter3/(float)TotalPicks);
	printf("\nTotalPicks Counter: %i", TotalPicks);
	
	printf("\n\nWinning Summary");
	printf("\n===============");
	printf("\nUser Choice Never Changes: Wins Counter=%i \nPercent Wins(UserPicksWinsCounter/TotalPicks)=(%f)",NeverChangeWinCounter,(float)NeverChangeWinCounter/(float)TotalPicks);
	
	printf("\n\n\"Always Change\" from User Choice: Wins Counter=%i \nPercent Wins(AlwaysChangePickWinsCounter/TotalPicks)=(%f)",AlwaysChangeWinCounter,(float)AlwaysChangeWinCounter/(float)TotalPicks);
	
	printf("\n\n");
	char PressEnter;
	printf("\nPlease Press Enter to Quit!");
	getch(PressEnter);
	///////////////////////////////////////////////////////////

	return EXIT_SUCCESS;
}