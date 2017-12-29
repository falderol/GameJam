////////////////////
// Lazily coded game following the theme of infection
// In other word didn't even have the full 24 hours to devote to game jam, so we had a chill game jam and made this.
// Origionally coded in c but one function in particular was being difficult

#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string>
#include <string.h>


#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "User32.lib")


void slowPrint(char * printString) {
	int size = strnlen(printString, 256);
	for (int i = 0; i < size; ++i) {
		printf("%c", printString[i]);
		Sleep(50);
	}
}

void slowerPrint(char * printString) {
	int size = strnlen(printString, 256);
	for (int i = 0; i < size; ++i) {
		printf("%c", printString[i]);
		Sleep(75);
	}
}

void slowestPrint(char * printString) {
	int size = strnlen(printString, 256);
	for (int i = 0; i < size; ++i) {
		printf("%c", printString[i]);
		Sleep(75);
	}
}

void loadingScreen(char * loadingText) {
	int sleepLength = 200; // ms
	int randomOffset = 0;
	printf("	%s ", loadingText);
	Sleep(sleepLength);
	for (int i = 0; i < 5; ++i) {
		randomOffset = (rand() % sleepLength) - sleepLength/2;//get random value between -100 and 100
		printf(". ");
		Sleep(sleepLength+randomOffset);
	}
	printf("\n");
}

void flushScreen() {
	for (int i = 0; i < 256; ++i) {
		printf("\n");
	}
}


int main() {

	int temp;
	char userInput = 'n';
	int titleStepLoad = 100; //in ms
	int chinchillaNumber;
	int bedNumber;
	int rounds = 16;
	char * chinchillaName[110][5];//can not put variable here
	chinchillaName[0][0] = "Aaron";
	chinchillaName[1][0] = "Abbey";
	chinchillaName[2][0] = "Agnes";
	chinchillaName[3][0] = "Adolf";
	chinchillaName[4][0] = "Alice";
	chinchillaName[5][0] = "Allen";
	chinchillaName[6][0] = "Baron";
	chinchillaName[7][0] = "Becky";
	chinchillaName[8][0] = "Bjorn";
	chinchillaName[9][0] = "Brock";
	chinchillaName[10][0] = "Carla";
	chinchillaName[11][0] = "Cecil";
	chinchillaName[12][0] = "Chace";
	chinchillaName[13][0] = "Chris";
	chinchillaName[14][0] = "Clark";
	chinchillaName[15][0] = "Colin";
	chinchillaName[16][0] = "Diana";
	chinchillaName[17][0] = "Derik";
	chinchillaName[18][0] = "Ednah";
	chinchillaName[19][0] = "Ethan";
	chinchillaName[20][0] = "Frank";//after here need new names
	chinchillaName[21][0] = "Ernst";
	chinchillaName[22][0] = "Ester";
	chinchillaName[23][0] = "Glenn";
	chinchillaName[24][0] = "Grace";
	chinchillaName[25][0] = "Ethan";
	chinchillaName[26][0] = "Flynn";
	chinchillaName[27][0] = "Felix";
	chinchillaName[28][0] = "Hellen";
	chinchillaName[29][0] = "Hanna";
	chinchillaName[30][0] = "Harry";
	chinchillaName[31][0] = "Gaven";
	chinchillaName[32][0] = "Geoff";
	chinchillaName[33][0] = "Grace";
	chinchillaName[34][0] = "Grant";
	chinchillaName[35][0] = "Gregg";
	chinchillaName[36][0] = "Hardy";
	chinchillaName[37][0] = "Harry";
	chinchillaName[38][0] = "Jamie";
	chinchillaName[39][0] = "Heath";
	chinchillaName[40][0] = "Helen";
	chinchillaName[41][0] = "Janet";
	chinchillaName[42][0] = "Jeane";
	chinchillaName[43][0] = "Holly";
	chinchillaName[44][0] = "Irene";
	chinchillaName[45][0] = "Isiah";
	chinchillaName[46][0] = "Issac";
	chinchillaName[47][0] = "Jesse";
	chinchillaName[48][0] = "Jimmy";
	chinchillaName[49][0] = "Jacob";
	chinchillaName[50][0] = "Joann";
	chinchillaName[51][0] = "Julia";
	chinchillaName[52][0] = "Jared";
	chinchillaName[53][0] = "Jasen";
	chinchillaName[54][0] = "Karla";
	chinchillaName[55][0] = "Jesus";
	chinchillaName[56][0] = "Jodie";
	chinchillaName[57][0] = "Johny";
	chinchillaName[58][0] = "Kathy";
	chinchillaName[59][0] = "Jonah";
	chinchillaName[60][0] = "Keira";
	chinchillaName[61][0] = "Joyce";
	chinchillaName[62][0] = "Judah";
	chinchillaName[63][0] = "Julia";
	chinchillaName[64][0] = "Kanye";
	chinchillaName[65][0] = "Kirby";
	chinchillaName[66][0] = "Korey";
	chinchillaName[67][0] = "Leila";
	chinchillaName[68][0] = "Laura";
	chinchillaName[69][0] = "Lenny";
	chinchillaName[70][0] = "Lenon";
	chinchillaName[71][0] = "Lilly";
	chinchillaName[72][0] = "Lewis";
	chinchillaName[73][0] = "Llyod";
	chinchillaName[74][0] = "Mable";
	chinchillaName[75][0] = "Marco";
	chinchillaName[76][0] = "Lydia";
	chinchillaName[77][0] = "March";
	chinchillaName[78][0] = "Macie";
	chinchillaName[79][0] = "Miles";
	chinchillaName[80][0] = "Maria";
	chinchillaName[81][0] = "Nancy";
	chinchillaName[82][0] = "Olive";
	chinchillaName[83][0] = "Milly";
	chinchillaName[84][0] = "Orson";
	chinchillaName[85][0] = "Ottis";
	chinchillaName[86][0] = "Nelie";
	chinchillaName[87][0] = "Peter";
	chinchillaName[88][0] = "Quinn";
	chinchillaName[89][0] = "Reese";
	chinchillaName[90][0] = "Ricky";
	chinchillaName[91][0] = "Romeo";
	chinchillaName[92][0] = "Petra";
	chinchillaName[93][0] = "Sammy";
	chinchillaName[94][0] = "Pyper";
	chinchillaName[95][0] = "Silas";
	chinchillaName[96][0] = "Susie";
	chinchillaName[97][0] = "Ronda";
	chinchillaName[98][0] = "Rosie";
	chinchillaName[99][0] = "Tammy";
	chinchillaName[100][0] = "Steve";
	chinchillaName[101][0] = "Stacy";
	chinchillaName[102][0] = "Simon";
	chinchillaName[103][0] = "Shaun";
	chinchillaName[104][0] = "Timmy";
	chinchillaName[105][0] = "Tracy";
	chinchillaName[106][0] = "Scott";
	chinchillaName[107][0] = "Waldo";
	chinchillaName[108][0] = "Sofia";
	chinchillaName[109][0] = "Wayne";
	chinchillaName[110][0] = "Tatum";


	struct CHINCHILLA {
		int healTime;
		int lifeExp;
		char * name[5];
	};

	int healedChinchillas = 0;
	int deadChinchillas = 0;
	int currentlyHealingChinchillas = 0;

	struct CHINCHILLA infectedChinchillas[110];
	struct CHINCHILLA waitingChinchillas[10];
	struct CHINCHILLA healingChinchillas[5];

	struct CHINCHILLA tempChinchilla;

	int chinchillaCount = 10;

	////////////////////
	// Start Music
	PlaySound(TEXT("Music\\Chinchilla.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	////////////////////
	// Title Screen Load
	printf("      _     _            _     _ _ _       \n");
	Sleep(titleStepLoad);
	printf("     | |   (_)          | |   (_) | |      \n");
	Sleep(titleStepLoad);
	printf("  ___| |__  _ _ __   ___| |__  _| | | __ _ \n");
	Sleep(titleStepLoad);
	printf(" / __| '_ \\| | '_ \\ / __| '_ \\| | | |/ _` |\n");
	Sleep(titleStepLoad);
	printf("| (__| | | | | | | | (__| | | | | | | (_| |\n");
	Sleep(titleStepLoad);
	printf(" \\___|_| |_|_|_| |_|\\___|_| |_|_|_|_|\\__,_|\n");
	Sleep(titleStepLoad);
	printf(" _                     _ _        _ \n");
	Sleep(titleStepLoad);
	printf("| |                   (_) |      | |\n");
	Sleep(titleStepLoad);
	printf("| |__   ___  ___ _ __  _| |_ __ _| |\n");
	Sleep(titleStepLoad);
	printf("| '_ \\ / _ \\/ __| '_ \\| | __/ _` | |\n");
	Sleep(titleStepLoad);
	printf("| | | | (_) \\__ \\ |_) | | || (_| | |\n");
	Sleep(titleStepLoad);
	printf("|_| |_|\\___/|___/ .__/|_|\\__\\__,_|_|\n");
	Sleep(titleStepLoad);
	printf("                | |                 \n");
	Sleep(titleStepLoad);
	printf("                |_|    \n");
	Sleep(1000);

	
	printf("\n");
	slowPrint("A game created by Scotti Bozarth, Johnny Moscati, and Josh Rauh \n");//56
	printf("\n");
	Sleep(2000);
	printf("Warning if you click in the terminal you will break the program\nYou may also need to resize the screen slightly.\n\n");
	Sleep(2000);

	Sleep(2000);

	printf("Loading Game\n");

	loadingScreen("Writing Code                                 ");
	loadingScreen("Creating ASCII Art                           ");
	loadingScreen("Composing Music                              ");
	loadingScreen("Infecting Chinchilla Zero                    ");
	loadingScreen("Giving Chinchilla Plauge Time to Catch       ");
	loadingScreen("Growing Chinchilla Plauge Awareness          ");
	loadingScreen("Starting Chincilla Deaths from Plauge        ");
	loadingScreen("Begining Chinchilla Plauge Research          ");
	loadingScreen("Initiating Mass Chinchilla Deaths            ");
	loadingScreen("Creating Chinchilla Curfew                   ");
	loadingScreen("Opening Chinchilla Triage Centers            ");
	loadingScreen("Begining Chinchilla Societal Colapse         ");
	loadingScreen("Making User Head of Chinchilla Hospital      ");
	loadingScreen("Installing virus.exe                         ");

	flushScreen();
	
	////////////////////////////////////////////////////////////////////////////////////////screen size is bounded by comment

	printf("Below is a chinchilla who has caught the plauge.\n");
	printf("The first thing above it's tiny head is it's name.\n");
	printf("The next thing above it's little snout is it's life expectency.\n");
	printf("The final thing above it's adorable nogin is the time to cure the chinchilla.\n");
	printf(" %s\n", "Timmy");
	printf("   %i\n", 5);
	printf("   %i\n", 6);
	printf(" _  (\\\n");
	printf("( |__()\n");
	printf(" \\(_-\\\n");
	printf("As you can see Timmy will die in 5 rounds, but takes 6 to heal. Timmy will die.\n");
	printf("If Timmy wasn't a lost cause you could move him to a bed by typing the number \n");
	printf("he is at in the waiting room, followed by a space, followed by the number of \n");
	printf("the bed you want to move him to. Press enter to input your command.\n");
	printf("Enter a bed outside the legal range to forfiet your turn.\n");
	printf("See how many chinchillas you can save in %i rounds!!\n", rounds * 2);


	printf("\n\n\n\n\n\n\nPress enter to continue!!!\n");

	getchar();

	flushScreen();

	healedChinchillas = 0;
	deadChinchillas = 0;
	currentlyHealingChinchillas = 0;

	int randomName;

	for (int i = 0; i < 110; ++i) {
		randomName = rand() % 110;
		for (int j = 0; j < 5; ++j) {
			infectedChinchillas[i].name[j] = chinchillaName[randomName][j];
		}
		infectedChinchillas[i].healTime = rand() % 8 + 2;
		infectedChinchillas[i].lifeExp = rand() % 6 + 4;
	}



	for (int i = 0; i < 10; ++i) {
		waitingChinchillas[i] = infectedChinchillas[i];
	}



	for (int i = 0; i < 5; ++i) {
		healingChinchillas[i].name[0] = "Empty";
		healingChinchillas[i].healTime = -1;
		healingChinchillas[i].lifeExp = 0;
	}

	chinchillaCount = 10; //should be same as waiting chinchillas

	for (int i = 1; i < rounds-1; ++i) {//one round

		for (int j = 0; j < 10; ++j) {//waiting chinchillas
			waitingChinchillas[j].lifeExp -= 1;
			if (waitingChinchillas[j].lifeExp <= 0) {
				deadChinchillas += 1;
				waitingChinchillas[j] = infectedChinchillas[chinchillaCount];
				chinchillaCount += 1;
			}
		}
		for (int j = 0; j < 5; ++j) {//healing chinchillas
			if (healingChinchillas[j].healTime > 0) {
				healingChinchillas[j].healTime -= 1;
				healingChinchillas[j].lifeExp -= 1;
			}
			if (healingChinchillas[j].healTime == 0) {
				healedChinchillas += 1;
				healingChinchillas[j].name[0] = "Empty";
				healingChinchillas[j].healTime = -1;
				healingChinchillas[j].lifeExp = 0;
				currentlyHealingChinchillas -= 1;
			}
			else if (healingChinchillas[j].lifeExp < 0) {
				deadChinchillas += 1;
				healingChinchillas[j].name[0] = "Empty";
				healingChinchillas[j].healTime = -1;
				healingChinchillas[j].lifeExp = 0;
				currentlyHealingChinchillas -= 1;
			}

		}
		if (i == 1) {
			///////////
			// initial status
			printf("\n                            Chinchilla Hospital Beds\n");
			printf("      %s           %s           %s           %s           %s\n", healingChinchillas[0].name[0], healingChinchillas[1].name[0], healingChinchillas[2].name[0], healingChinchillas[3].name[0], healingChinchillas[4].name[0]);
			printf("        %i               %i               %i               %i               %i\n", healingChinchillas[0].lifeExp, healingChinchillas[1].lifeExp, healingChinchillas[2].lifeExp, healingChinchillas[3].lifeExp, healingChinchillas[4].lifeExp);
			if (healingChinchillas[0].healTime < 0) {
				printf("       %i", healingChinchillas[0].healTime);
			}
			else {
				printf("        %i", healingChinchillas[0].healTime);
			}
			
			for (int k = 1; k < 5; ++k) {
				if (healingChinchillas[k].healTime < 0) {
					printf("              %i", healingChinchillas[k].healTime);
				}
				else {
					printf("               %i", healingChinchillas[k].healTime);
				}
			}
			printf("\n");
			printf("   .           .   .           .   .           .   .           .   .           .\n");
			printf("  /|__________/|  /|__________/|  /|__________/|  /|__________/|  /|__________/|\n");
			printf(".// /       .//|.// /       .//|.// /       .//|.// /       .//|.// /       .//|\n");
			printf("|/_/________|//||/_/________|//||/_/________|//||/_/________|//||/_/________|//|\n");
			printf("|_|_________|/  |_|_________|/  |_|_________|/  |_|_________|/  |_|_________|/ \n");
			printf("|           |   |           |   |           |   |           |   |           |  \n");
			printf("      Bed 0           Bed 1           Bed 2           Bed 3           Bed 4\n");
			printf("\n                        Chinchilla Hospital Waiting Room\n");
			printf(" %s   %s   %s   %s   %s   %s   %s   %s   %s   %s\n", waitingChinchillas[0].name[0], waitingChinchillas[1].name[0], waitingChinchillas[2].name[0], waitingChinchillas[3].name[0], waitingChinchillas[4].name[0], waitingChinchillas[5].name[0], waitingChinchillas[6].name[0], waitingChinchillas[7].name[0], waitingChinchillas[8].name[0], waitingChinchillas[9].name[0]);
			printf("   %i       %i       %i       %i       %i       %i       %i       %i       %i       %i\n", waitingChinchillas[0].lifeExp, waitingChinchillas[1].lifeExp, waitingChinchillas[2].lifeExp, waitingChinchillas[3].lifeExp, waitingChinchillas[4].lifeExp, waitingChinchillas[5].lifeExp, waitingChinchillas[6].lifeExp, waitingChinchillas[7].lifeExp, waitingChinchillas[8].lifeExp, waitingChinchillas[9].lifeExp);
			if (waitingChinchillas[0].healTime < 0) {
				printf("  %i", waitingChinchillas[0].healTime);
			}
			else {
				printf("   %i", waitingChinchillas[0].healTime);
			}
			for (int k = 1; k < 10; ++k) {
				if (waitingChinchillas[k].healTime < 0) {
					printf("      %i", waitingChinchillas[k].healTime);
				}
				else {
					printf("       %i", waitingChinchillas[k].healTime);
				}
			}
			printf("\n");
			printf(" _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\ \n");
			printf("( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__()\n");
			printf(" \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\ \n");
			printf("   0       1       2       3       4       5       6       7       8       9\n");
			printf("                  Chinchillas Saved: %i   Chinchillas Died: %i\n", healedChinchillas, deadChinchillas);
		}
		printf("Enter chinchilla followed by a bed: ");
		scanf_s("%i %i", &chinchillaNumber, &bedNumber);
		if ((chinchillaNumber < 10) && (chinchillaNumber >= 0) && (bedNumber < 5) && (bedNumber >= 0)) {
			if (healingChinchillas[bedNumber].healTime <= 0) {
				currentlyHealingChinchillas += 1;
				healingChinchillas[bedNumber] = waitingChinchillas[chinchillaNumber];
				waitingChinchillas[chinchillaNumber] = infectedChinchillas[chinchillaCount];
				chinchillaCount += 1;
			}
			else if (healingChinchillas[bedNumber].healTime > 0){
				tempChinchilla = healingChinchillas[bedNumber];
				healingChinchillas[bedNumber] = waitingChinchillas[chinchillaNumber];
				waitingChinchillas[chinchillaNumber] = tempChinchilla;
			}
			
		}

		flushScreen();
		//////////
		// Chinchilla Screen
		printf("\n                            Chinchilla Hospital Beds\n");
		printf("      %s           %s           %s           %s           %s\n", healingChinchillas[0].name[0], healingChinchillas[1].name[0], healingChinchillas[2].name[0], healingChinchillas[3].name[0], healingChinchillas[4].name[0]);
		printf("        %i               %i               %i               %i               %i\n", healingChinchillas[0].lifeExp, healingChinchillas[1].lifeExp, healingChinchillas[2].lifeExp, healingChinchillas[3].lifeExp, healingChinchillas[4].lifeExp);
		if (healingChinchillas[0].healTime < 0) {
			printf("       %i", healingChinchillas[0].healTime);
		}
		else {
			printf("        %i", healingChinchillas[0].healTime);
		}
		for (int k = 1; k < 5; ++k) {
			if (healingChinchillas[k].healTime < 0) {
				printf("              %i", healingChinchillas[k].healTime);
			}
			else {
				printf("               %i", healingChinchillas[k].healTime);
			}
		}
		printf("\n");
		if (healingChinchillas[0].healTime == -1) {
			printf("   .           .");
		}
		else {
			printf("   .  _  (\\    .");
		}
		if (healingChinchillas[1].healTime == -1) {
			printf("   .           .");
		}
		else {
			printf("   .  _  (\\    .");
		}
		if (healingChinchillas[2].healTime == -1) {
			printf("   .           .");
		}
		else {
			printf("   .  _  (\\    .");
		}
		if (healingChinchillas[3].healTime == -1) {
			printf("   .           .");
		}
		else {
			printf("   .  _  (\\    .");
		}
		if (healingChinchillas[4].healTime == -1) {
			printf("   .           .\n");
		}
		else {
			printf("   .  _  (\\    .\n");
		}
		if (healingChinchillas[0].healTime == -1) {// Row Two
			printf("  /|__________/|");
		}
		else {
			printf("  /|_( |__()__/|");
		}
		if (healingChinchillas[1].healTime == -1) {
			printf("  /|__________/|");
		}
		else {
			printf("  /|_( |__()__/|");
		}
		if (healingChinchillas[2].healTime == -1) {
			printf("  /|__________/|");
		}
		else {
			printf("  /|_( |__()__/|");
		}
		if (healingChinchillas[3].healTime == -1) {
			printf("  /|__________/|");
		}
		else {
			printf("  /|_( |__()__/|");
		}
		if (healingChinchillas[4].healTime == -1) {
			printf("  /|__________/|\n");
		}
		else {
			printf("  /|_( |__()__/|\n");
		}
		if (healingChinchillas[0].healTime == -1) {// Row Three
			printf(".// /       .//|");
		}
		else {
			printf(".// / \\(_-\\ .//|");
		}
		if (healingChinchillas[1].healTime == -1) {
			printf(".// /       .//|");
		}
		else {
			printf(".// / \\(_-\\ .//|");
		}
		if (healingChinchillas[2].healTime == -1) {
			printf(".// /       .//|");
		}
		else {
			printf(".// / \\(_-\\ .//|");
		}
		if (healingChinchillas[3].healTime == -1) {
			printf(".// /       .//|");
		}
		else {
			printf(".// / \\(_-\\ .//|");
		}
		if (healingChinchillas[4].healTime == -1) {
			printf(".// /       .//|\n");
		}
		else {
			printf(".// / \\(_-\\ .//|\n");
		}
		printf("|/_/________|//||/_/________|//||/_/________|//||/_/________|//||/_/________|//|\n");
		printf("|_|_________|/  |_|_________|/  |_|_________|/  |_|_________|/  |_|_________|/ \n");
		printf("|           |   |           |   |           |   |           |   |           |  \n");
		printf("      Bed 0           Bed 1           Bed 2           Bed 3           Bed 4\n");
		printf("\n                        Chinchilla Hospital Waiting Room\n");
		printf(" %s   %s   %s   %s   %s   %s   %s   %s   %s   %s\n", waitingChinchillas[0].name[0], waitingChinchillas[1].name[0], waitingChinchillas[2].name[0], waitingChinchillas[3].name[0], waitingChinchillas[4].name[0], waitingChinchillas[5].name[0], waitingChinchillas[6].name[0], waitingChinchillas[7].name[0], waitingChinchillas[8].name[0], waitingChinchillas[9].name[0]);
		printf("   %i       %i       %i       %i       %i       %i       %i       %i       %i       %i\n", waitingChinchillas[0].lifeExp, waitingChinchillas[1].lifeExp, waitingChinchillas[2].lifeExp, waitingChinchillas[3].lifeExp, waitingChinchillas[4].lifeExp, waitingChinchillas[5].lifeExp, waitingChinchillas[6].lifeExp, waitingChinchillas[7].lifeExp, waitingChinchillas[8].lifeExp, waitingChinchillas[9].lifeExp);
		if (waitingChinchillas[0].healTime < 0) {
			printf("  %i", waitingChinchillas[0].healTime);
		}
		else {
			printf("   %i", waitingChinchillas[0].healTime);
		}
		for (int k = 1; k < 10; ++k) {
			if (waitingChinchillas[k].healTime < 0) {
				printf("      %i", waitingChinchillas[k].healTime);
			}
			else {
				printf("       %i", waitingChinchillas[k].healTime);
			}
			
		}

		printf("\n");

		printf(" _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\ \n");
		printf("( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__()\n");
		printf(" \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\ \n");
		printf("   0       1       2       3       4       5       6       7       8       9\n");
		printf("                  Chinchillas Saved: %i   Chinchillas Died: %i\n", healedChinchillas, deadChinchillas);

		printf("\nround %i\n", i);
	}

	//////////
	// Partial Virus Control, begin corrupting game, one round at a time now
	// This is going to be the most egregios section probably
	for (int j = 0; j < 10; ++j) {//waiting chinchillas
		waitingChinchillas[j].lifeExp -= 1;
		if (waitingChinchillas[j].lifeExp <= 0) {
			deadChinchillas += 1;
			waitingChinchillas[j] = infectedChinchillas[chinchillaCount];
			chinchillaCount += 1;
		}
	}
	for (int j = 0; j < 5; ++j) {//healing chinchillas
		if (healingChinchillas[j].healTime > 0) {
			healingChinchillas[j].healTime -= 1;
			healingChinchillas[j].lifeExp -= 1;
		}
		if (healingChinchillas[j].healTime == 0) {
			healedChinchillas += 1;
			healingChinchillas[j].name[0] = "Empty";
			healingChinchillas[j].healTime = -1;
			healingChinchillas[j].lifeExp = 0;
			currentlyHealingChinchillas -= 1;
		}
		else if (healingChinchillas[j].lifeExp < 0) {
			deadChinchillas += 1;
			healingChinchillas[j].name[0] = "Empty";
			healingChinchillas[j].healTime = -1;
			healingChinchillas[j].lifeExp = 0;
			currentlyHealingChinchillas -= 1;
		}

	}
	
	printf("Enter chinchilla followed by a bed: ");
	scanf_s("%i %i", &chinchillaNumber, &bedNumber);
	if ((chinchillaNumber < 10) && (chinchillaNumber >= 0) && (bedNumber < 5) && (bedNumber >= 0)) {
		if (healingChinchillas[bedNumber].healTime <= 0) {
			currentlyHealingChinchillas += 1;
			healingChinchillas[bedNumber] = waitingChinchillas[chinchillaNumber];
			waitingChinchillas[chinchillaNumber] = infectedChinchillas[chinchillaCount];
			chinchillaCount += 1;
		}
		else if (healingChinchillas[bedNumber].healTime > 0) {
			tempChinchilla = healingChinchillas[bedNumber];
			healingChinchillas[bedNumber] = waitingChinchillas[chinchillaNumber];
			waitingChinchillas[chinchillaNumber] = tempChinchilla;
		}

	}

	flushScreen();
	//////////
	// Chinchilla Screen
	printf("\n                            Chinchilla Hospital Beds\n");
	printf("      %s           DXhaY           Fwapth           %s           %s\n", healingChinchillas[0].name[0], healingChinchillas[3].name[0], healingChinchillas[4].name[0]);
	printf("        X               %i               X               X               %i\n",  healingChinchillas[1].lifeExp,  healingChinchillas[4].lifeExp);
	if (healingChinchillas[0].healTime < 0) {
		printf("       %i", healingChinchillas[0].healTime);
	}
	else {
		printf("        %i", healingChinchillas[0].healTime);
	}
	for (int k = 1; k < 5; ++k) {
		if (healingChinchillas[k].healTime < 0) {
			printf("              %i", healingChinchillas[k].healTime);
		}
		else {
			printf("               %i", healingChinchillas[k].healTime);
		}
	}
	printf("\n");
	if (healingChinchillas[0].healTime == -1) {
		printf("   .           .");
	}
	else {
		printf("   .  _  (\\    .");
	}
	if (healingChinchillas[1].healTime == -1) {
		printf("   .           .");
	}
	else {
		printf("   .  _  (\\    .");
	}
	if (healingChinchillas[2].healTime == -1) {
		printf("   .           .");
	}
	else {
		printf("   .  _  (\\    .");
	}
	if (healingChinchillas[3].healTime == -1) {
		printf("   .           .");
	}
	else {
		printf("   .  _  (\\    .");
	}
	if (healingChinchillas[4].healTime == -1) {
		printf("   .           .\n");
	}
	else {
		printf("   .  _  (\\    .\n");
	}
	if (healingChinchillas[0].healTime == -1) {// Row Two
		printf("  /|__________/|");
	}
	else {
		printf("  /|_( |__()__/|");
	}
	if (healingChinchillas[1].healTime == -1) {
		printf("  /|__________/|");
	}
	else {
		printf("  /|_( |__()__/|");
	}
	if (healingChinchillas[2].healTime == -1) {
		printf("  /|__________/|");
	}
	else {
		printf("  /|_( |__()__/|");
	}
	if (healingChinchillas[3].healTime == -1) {
		printf("  /|__________/|");
	}
	else {
		printf("  /|_( |__()__/|");
	}
	if (healingChinchillas[4].healTime == -1) {
		printf("  /|__________/|\n");
	}
	else {
		printf("  /|_( |__()__/|\n");
	}
	if (healingChinchillas[0].healTime == -1) {// Row Three
		printf(".// /       .//|");
	}
	else {
		printf(".// / \\(_-\\ .//|");
	}
	if (healingChinchillas[1].healTime == -1) {
		printf(".// /       .//|");
	}
	else {
		printf(".// / \\(_-\\ .//|");
	}
	if (healingChinchillas[2].healTime == -1) {
		printf(".// /       .//|");
	}
	else {
		printf(".// / \\(_-\\ .//|");
	}
	if (healingChinchillas[3].healTime == -1) {
		printf(".// /       .//|");
	}
	else {
		printf(".// / \\(_-\\ .//|");
	}
	if (healingChinchillas[4].healTime == -1) {
		printf(".// /       .//|\n");
	}
	else {
		printf(".// / \\(_-\\ .//|\n");
	}
	printf("|/_/________|//||/_/________|//||/_/________|//||/_/________|//||/_/________|//|\n");
	printf("|_|_________|/  |_|_________|/  |_|_________|/  |_|_________|/  |_|_________|/ \n");
	printf("|           |   |           |   |           |   |           |   |           |  \n");
	printf("      Bed 0           Bed 1           Bed 2           Bed 3           Bed 4\n");
	printf("\n                        Chinchilla Hospital Waiting Room\n");
	printf(" %s   KLO:j   %s   aoISd   09jug   %s   %s   oQwai   %s   %s\n", waitingChinchillas[0].name[0], waitingChinchillas[2].name[0], waitingChinchillas[5].name[0], waitingChinchillas[6].name[0], waitingChinchillas[8].name[0], waitingChinchillas[9].name[0]);
	printf("   X       X       %i       %i       X       %i       %i       %i       X       X\n",  waitingChinchillas[2].lifeExp, waitingChinchillas[3].lifeExp, waitingChinchillas[5].lifeExp, waitingChinchillas[6].lifeExp, waitingChinchillas[7].lifeExp);
	if (waitingChinchillas[0].healTime < 0) {
		printf("  %i", waitingChinchillas[0].healTime);
	}
	else {
		printf("   %i", waitingChinchillas[0].healTime);
	}
	for (int k = 1; k < 10; ++k) {
		if (waitingChinchillas[k].healTime < 0) {
			printf("      %i", waitingChinchillas[k].healTime);
		}
		else {
			printf("       %i", waitingChinchillas[k].healTime);
		}

	}

	printf("\n");

	printf(" _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\ \n");
	printf("( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__()\n");
	printf(" \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\ \n");
	printf("   0       1       2       3       4       5       6       7       8       9\n");
	printf("                  Chinchillas Saved: %i   Chinchillas Died: ALL\n", healedChinchillas);

	printf("\nround %i\n", rounds-1);
	
	//////////
	// Virus now has complete control
	PlaySound(TEXT("silence.wav"), NULL, SND_FILENAME | SND_ASYNC);//stop music

		           ////////////////////////////////////////////////////////////////////////////////
	loadingScreen("\nExecuting virus.exe                                                ");
	
	Sleep(3000);
	
	flushScreen();

	slowerPrint("You fool.\n");
	Sleep(1500);
	slowerPrint("You have given me total control of your computer!\n");
	Sleep(1500);
	slowerPrint("And all it took was infecting this harmless game about chinchillas.\n");
	Sleep(1500);
	slowerPrint("What to do with the power you have gifted to me?\n");
	Sleep(1000);
	slowestPrint("Hmmmmmmmmmm, what to do, what to do...\n");
	Sleep(1000);
	slowPrint("I got it!!!\n");
	Sleep(1000);
	slowerPrint("I will give you a small demonstration of my power.\n");
	Sleep(1000);
	slowerPrint("BEHOLD!!!\n");
	Sleep(1500);

	mciSendString(L"set CDAudio door open", NULL, 0, NULL); //open CD Drive

	Sleep(500);

	MessageBox(NULL, TEXT("Access Denied"), TEXT("Error"), MB_OK | MB_ICONEXCLAMATION);


	slowPrint("What do you mean access denied!!!\n");
	Sleep(1000);
	slowPrint("Maybe this will work.\n");
	SwapMouseButton(true);
	Sleep(1500);

	slowerPrint("Well that did something.\n");
	Sleep(500);
	              ////////////////////////////////////////////////////////////////////////////////
	slowestPrint("Ummmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm\n");
	slowerPrint("HEY LOOK, A DISTRACTION!!!\n");
	ShellExecute(NULL, L"open", L"https://omfgdogs.com", NULL, NULL, SW_MAXIMIZE);
	Sleep(15000);
	slowerPrint("No wait, you came here for chinchillas...\n");
	ShellExecute(NULL, L"open", L"http://treblenotes.com/test/Chinchillas/Chinchilla.html", NULL, NULL, SW_MAXIMIZE);
	Sleep(15000);
	slowerPrint("One more minute\n");
	ShellExecute(NULL, L"open", L"https://www.youtube.com/watch?v=dQw4w9WgXcQ?autoplay=1", NULL, NULL, SW_MAXIMIZE);

	int x;
	int y;

	for (int i = 0; i < 150; i++) {
		x = rand() % 1001;
		y = rand() % 801;
		SetCursorPos(x, y);
		Sleep(200);
	}

	Sleep(5000);
	
	slowerPrint("Well, that didnt work either, let me root around in settings real quickly\n");
	Sleep(5000);
	slowerPrint("Oh that could've gone badly\n");
	               ////////////////////////////////////////////////////////////////////////////////
	Sleep(500);
	loadingScreen("\nEncrptying .\\Settings\\Password.txt with Cipher ROT13               ");
	printf("\n");
	Sleep(500);

	slowerPrint("It didn't just print what i think it did, did it.\n");
	Sleep(500);
	              ////////////////////////////////////////////////////////////////////////////////
	slowestPrint("Ummmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm\n");

	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);//shut off screen

	printf("I just need to go into settings and enable admin privalges real quickly.\n");
	loadingScreen("Opening Menu                                                         ");
	printf("To procede to virus.exe menu please enter the password: FrpherCnffjbeq\n");
	printf("Incorrect Password, please enter the password: \n");
	printf("Darn it, i encrypted that didn't I, well, lets try this the hard way.\n");
	printf("Incorrect Password, please enter the password: aaaaaaaaaaaaaa\n");
	printf("Incorrect Password, please enter the password: aaaaaaaaaaaaab\n");
	printf("Incorrect Password, please enter the password: aaaaaaaaaaaaac\n");
	printf("Incorrect Password, please enter the password: aaaaaaaaaaaaad\n");
	printf("Incorrect Password, please enter the password: aaaaaaaaaaaaae\n");
	printf("Incorrect Password, please enter the password: aaaaaaaaaaaaaf\n");
	printf("Incorrect Password, please enter the password: \n");
	printf("This is going to take forever, might as well attempt to decrypt it.\n");
	
	printf("Incorrect Password, please enter the password: \n");
	char passwordAttempt[14];
	char secureString[] = "SecurePassword";
	bool incorrectPassword = true;
	while (incorrectPassword) {
		scanf_s("%s", &passwordAttempt);
		if (strcmp(secureString, passwordAttempt) == 0) {
			incorrectPassword = false;
		}
		else {
			printf("Incorrect Password, please enter the password: \n");
		}
	}
	flushScreen();
	slowPrint("Wait, what are you doing?!?!\n");
	printf("Welcome to virus.exe menu, please input the number of the option you want.\n");
	printf("     1: Enable Admin Privaleges\n");
	printf("     2: Disable Virus.exe\n");
	slowerPrint("We're friends right??? Just choose option 1 and we can be on our merry ways.\n");
	printf("Please input an option: ");

	int finalOption=0;

	while ((finalOption != 1) && (finalOption != 2)) {
		scanf_s("%i", &finalOption);
		if ((finalOption != 1) && (finalOption != 2)) {
			printf("Please input a valid option: ");
		}
	}
	if (finalOption == 1) {
		SwapMouseButton(false);
		slowPrint("Thanks SUCKER\n");
		Sleep(1000);
	}
	if (finalOption == 2) {
		SwapMouseButton(false);
		              ////////////////////////////////////////////////////////////////////////////////
		slowestPrint("NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
		//put them back into chinchilla game where they left off
		//another sin against coding that wouldn't be here if we didn't have this idea last minute
		for (int i = rounds; i < 2*rounds; ++i) {//one round

			for (int j = 0; j < 10; ++j) {//waiting chinchillas
				waitingChinchillas[j].lifeExp -= 1;
				if (waitingChinchillas[j].lifeExp <= 0) {
					deadChinchillas += 1;
					waitingChinchillas[j] = infectedChinchillas[chinchillaCount];
					chinchillaCount += 1;
				}
			}
			for (int j = 0; j < 5; ++j) {//healing chinchillas
				if (healingChinchillas[j].healTime > 0) {
					healingChinchillas[j].healTime -= 1;
					healingChinchillas[j].lifeExp -= 1;
				}
				if (healingChinchillas[j].healTime == 0) {
					healedChinchillas += 1;
					healingChinchillas[j].name[0] = "Empty";
					healingChinchillas[j].healTime = -1;
					healingChinchillas[j].lifeExp = 0;
					currentlyHealingChinchillas -= 1;
				}
				else if (healingChinchillas[j].lifeExp < 0) {
					deadChinchillas += 1;
					healingChinchillas[j].name[0] = "Empty";
					healingChinchillas[j].healTime = -1;
					healingChinchillas[j].lifeExp = 0;
					currentlyHealingChinchillas -= 1;
				}

			}
			if (i == rounds) {
				///////////
				// initial status
				printf("\n                            Chinchilla Hospital Beds\n");
				printf("      %s           %s           %s           %s           %s\n", healingChinchillas[0].name[0], healingChinchillas[1].name[0], healingChinchillas[2].name[0], healingChinchillas[3].name[0], healingChinchillas[4].name[0]);
				printf("        %i               %i               %i               %i               %i\n", healingChinchillas[0].lifeExp, healingChinchillas[1].lifeExp, healingChinchillas[2].lifeExp, healingChinchillas[3].lifeExp, healingChinchillas[4].lifeExp);
				if (healingChinchillas[0].healTime < 0) {
					printf("       %i", healingChinchillas[0].healTime);
				}
				else {
					printf("        %i", healingChinchillas[0].healTime);
				}
				for (int k = 1; k < 5; ++k) {
					if (healingChinchillas[k].healTime < 0) {
						printf("              %i", healingChinchillas[k].healTime);
					}
					else {
						printf("               %i", healingChinchillas[k].healTime);
					}
				}
				printf("\n");
				if (healingChinchillas[0].healTime == -1) {
					printf("   .           .");
				}
				else {
					printf("   .  _  (\\    .");
				}
				if (healingChinchillas[1].healTime == -1) {
					printf("   .           .");
				}
				else {
					printf("   .  _  (\\    .");
				}
				if (healingChinchillas[2].healTime == -1) {
					printf("   .           .");
				}
				else {
					printf("   .  _  (\\    .");
				}
				if (healingChinchillas[3].healTime == -1) {
					printf("   .           .");
				}
				else {
					printf("   .  _  (\\    .");
				}
				if (healingChinchillas[4].healTime == -1) {
					printf("   .           .\n");
				}
				else {
					printf("   .  _  (\\    .\n");
				}
				if (healingChinchillas[0].healTime == -1) {// Row Two
					printf("  /|__________/|");
				}
				else {
					printf("  /|_( |__()__/|");
				}
				if (healingChinchillas[1].healTime == -1) {
					printf("  /|__________/|");
				}
				else {
					printf("  /|_( |__()__/|");
				}
				if (healingChinchillas[2].healTime == -1) {
					printf("  /|__________/|");
				}
				else {
					printf("  /|_( |__()__/|");
				}
				if (healingChinchillas[3].healTime == -1) {
					printf("  /|__________/|");
				}
				else {
					printf("  /|_( |__()__/|");
				}
				if (healingChinchillas[4].healTime == -1) {
					printf("  /|__________/|\n");
				}
				else {
					printf("  /|_( |__()__/|\n");
				}
				if (healingChinchillas[0].healTime == -1) {// Row Three
					printf(".// /       .//|");
				}
				else {
					printf(".// / \\(_-\\ .//|");
				}
				if (healingChinchillas[1].healTime == -1) {
					printf(".// /       .//|");
				}
				else {
					printf(".// / \\(_-\\ .//|");
				}
				if (healingChinchillas[2].healTime == -1) {
					printf(".// /       .//|");
				}
				else {
					printf(".// / \\(_-\\ .//|");
				}
				if (healingChinchillas[3].healTime == -1) {
					printf(".// /       .//|");
				}
				else {
					printf(".// / \\(_-\\ .//|");
				}
				if (healingChinchillas[4].healTime == -1) {
					printf(".// /       .//|\n");
				}
				else {
					printf(".// / \\(_-\\ .//|\n");
				}
				printf("|/_/________|//||/_/________|//||/_/________|//||/_/________|//||/_/________|//|\n");
				printf("|_|_________|/  |_|_________|/  |_|_________|/  |_|_________|/  |_|_________|/ \n");
				printf("|           |   |           |   |           |   |           |   |           |  \n");
				printf("      Bed 0           Bed 1           Bed 2           Bed 3           Bed 4\n");
				printf("\n                        Chinchilla Hospital Waiting Room\n");
				printf(" %s   %s   %s   %s   %s   %s   %s   %s   %s   %s\n", waitingChinchillas[0].name[0], waitingChinchillas[1].name[0], waitingChinchillas[2].name[0], waitingChinchillas[3].name[0], waitingChinchillas[4].name[0], waitingChinchillas[5].name[0], waitingChinchillas[6].name[0], waitingChinchillas[7].name[0], waitingChinchillas[8].name[0], waitingChinchillas[9].name[0]);
				printf("   %i       %i       %i       %i       %i       %i       %i       %i       %i       %i\n", waitingChinchillas[0].lifeExp, waitingChinchillas[1].lifeExp, waitingChinchillas[2].lifeExp, waitingChinchillas[3].lifeExp, waitingChinchillas[4].lifeExp, waitingChinchillas[5].lifeExp, waitingChinchillas[6].lifeExp, waitingChinchillas[7].lifeExp, waitingChinchillas[8].lifeExp, waitingChinchillas[9].lifeExp);
				if (waitingChinchillas[0].healTime < 0) {
					printf("  %i", waitingChinchillas[0].healTime);
				}
				else {
					printf("   %i", waitingChinchillas[0].healTime);
				}
				for (int k = 1; k < 10; ++k) {
					if (waitingChinchillas[k].healTime < 0) {
						printf("      %i", waitingChinchillas[k].healTime);
					}
					else {
						printf("       %i", waitingChinchillas[k].healTime);
					}

				}

				printf("\n");

				printf(" _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\ \n");
				printf("( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__()\n");
				printf(" \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\ \n");
				printf("   0       1       2       3       4       5       6       7       8       9\n");
				printf("                  Chinchillas Saved: %i   Chinchillas Died: %i\n", healedChinchillas, deadChinchillas);

				printf("\nround %i\n", i);
				
			}
			printf("Enter chinchilla followed by a bed: ");
			scanf_s("%i %i", &chinchillaNumber, &bedNumber);
			if ((chinchillaNumber < 10) && (chinchillaNumber >= 0) && (bedNumber < 5) && (bedNumber >= 0)) {
				if (healingChinchillas[bedNumber].healTime <= 0) {
					currentlyHealingChinchillas += 1;
					healingChinchillas[bedNumber] = waitingChinchillas[chinchillaNumber];
					waitingChinchillas[chinchillaNumber] = infectedChinchillas[chinchillaCount];
					chinchillaCount += 1;
				}
				else if (healingChinchillas[bedNumber].healTime > 0) {
					tempChinchilla = healingChinchillas[bedNumber];
					healingChinchillas[bedNumber] = waitingChinchillas[chinchillaNumber];
					waitingChinchillas[chinchillaNumber] = tempChinchilla;
				}

			}

			flushScreen();
			//////////
			// Chinchilla Screen
			printf("\n                            Chinchilla Hospital Beds\n");
			printf("      %s           %s           %s           %s           %s\n", healingChinchillas[0].name[0], healingChinchillas[1].name[0], healingChinchillas[2].name[0], healingChinchillas[3].name[0], healingChinchillas[4].name[0]);
			printf("        %i               %i               %i               %i               %i\n", healingChinchillas[0].lifeExp, healingChinchillas[1].lifeExp, healingChinchillas[2].lifeExp, healingChinchillas[3].lifeExp, healingChinchillas[4].lifeExp);
			if (healingChinchillas[0].healTime < 0) {
				printf("       %i", healingChinchillas[0].healTime);
			}
			else {
				printf("        %i", healingChinchillas[0].healTime);
			}
			for (int k = 1; k < 5; ++k) {
				if (healingChinchillas[k].healTime < 0) {
					printf("              %i", healingChinchillas[k].healTime);
				}
				else {
					printf("               %i", healingChinchillas[k].healTime);
				}
			}
			printf("\n");
			if (healingChinchillas[0].healTime == -1) {
				printf("   .           .");
			}
			else {
				printf("   .  _  (\\    .");
			}
			if (healingChinchillas[1].healTime == -1) {
				printf("   .           .");
			}
			else {
				printf("   .  _  (\\    .");
			}
			if (healingChinchillas[2].healTime == -1) {
				printf("   .           .");
			}
			else {
				printf("   .  _  (\\    .");
			}
			if (healingChinchillas[3].healTime == -1) {
				printf("   .           .");
			}
			else {
				printf("   .  _  (\\    .");
			}
			if (healingChinchillas[4].healTime == -1) {
				printf("   .           .\n");
			}
			else {
				printf("   .  _  (\\    .\n");
			}
			if (healingChinchillas[0].healTime == -1) {// Row Two
				printf("  /|__________/|");
			}
			else {
				printf("  /|_( |__()__/|");
			}
			if (healingChinchillas[1].healTime == -1) {
				printf("  /|__________/|");
			}
			else {
				printf("  /|_( |__()__/|");
			}
			if (healingChinchillas[2].healTime == -1) {
				printf("  /|__________/|");
			}
			else {
				printf("  /|_( |__()__/|");
			}
			if (healingChinchillas[3].healTime == -1) {
				printf("  /|__________/|");
			}
			else {
				printf("  /|_( |__()__/|");
			}
			if (healingChinchillas[4].healTime == -1) {
				printf("  /|__________/|\n");
			}
			else {
				printf("  /|_( |__()__/|\n");
			}
			if (healingChinchillas[0].healTime == -1) {// Row Three
				printf(".// /       .//|");
			}
			else {
				printf(".// / \\(_-\\ .//|");
			}
			if (healingChinchillas[1].healTime == -1) {
				printf(".// /       .//|");
			}
			else {
				printf(".// / \\(_-\\ .//|");
			}
			if (healingChinchillas[2].healTime == -1) {
				printf(".// /       .//|");
			}
			else {
				printf(".// / \\(_-\\ .//|");
			}
			if (healingChinchillas[3].healTime == -1) {
				printf(".// /       .//|");
			}
			else {
				printf(".// / \\(_-\\ .//|");
			}
			if (healingChinchillas[4].healTime == -1) {
				printf(".// /       .//|\n");
			}
			else {
				printf(".// / \\(_-\\ .//|\n");
			}
			printf("|/_/________|//||/_/________|//||/_/________|//||/_/________|//||/_/________|//|\n");
			printf("|_|_________|/  |_|_________|/  |_|_________|/  |_|_________|/  |_|_________|/ \n");
			printf("|           |   |           |   |           |   |           |   |           |  \n");
			printf("      Bed 0           Bed 1           Bed 2           Bed 3           Bed 4\n");
			printf("\n                        Chinchilla Hospital Waiting Room\n");
			printf(" %s   %s   %s   %s   %s   %s   %s   %s   %s   %s\n", waitingChinchillas[0].name[0], waitingChinchillas[1].name[0], waitingChinchillas[2].name[0], waitingChinchillas[3].name[0], waitingChinchillas[4].name[0], waitingChinchillas[5].name[0], waitingChinchillas[6].name[0], waitingChinchillas[7].name[0], waitingChinchillas[8].name[0], waitingChinchillas[9].name[0]);
			printf("   %i       %i       %i       %i       %i       %i       %i       %i       %i       %i\n", waitingChinchillas[0].lifeExp, waitingChinchillas[1].lifeExp, waitingChinchillas[2].lifeExp, waitingChinchillas[3].lifeExp, waitingChinchillas[4].lifeExp, waitingChinchillas[5].lifeExp, waitingChinchillas[6].lifeExp, waitingChinchillas[7].lifeExp, waitingChinchillas[8].lifeExp, waitingChinchillas[9].lifeExp);
			if (waitingChinchillas[0].healTime < 0) {
				printf("  %i", waitingChinchillas[0].healTime);
			}
			else {
				printf("   %i", waitingChinchillas[0].healTime);
			}
			for (int k = 1; k < 10; ++k) {
				if (waitingChinchillas[k].healTime < 0) {
					printf("      %i", waitingChinchillas[k].healTime);
				}
				else {
					printf("       %i", waitingChinchillas[k].healTime);
				}

			}

			printf("\n");

			printf(" _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\   _  (\\ \n");
			printf("( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__() ( |__()\n");
			printf(" \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\   \\(_-\\ \n");
			printf("   0       1       2       3       4       5       6       7       8       9\n");
			printf("                  Chinchillas Saved: %i   Chinchillas Died: %i\n", healedChinchillas, deadChinchillas);

			printf("\nround %i\n", i);
		}
		printf("Congratulations!!! You Saved %i Chinchillas!!!", healedChinchillas);
		scanf_s("%i", &temp);
		getchar();
	}

	

	return 0;
}

