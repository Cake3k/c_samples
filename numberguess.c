#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "numberguess.h"


/** Asks the user to think of a number, 
 *  which the program will try to guess,
 *  and give a range limit of possible guesses.
 */
void numberguesser(){
	srand(time(NULL));
	
	int high, low, guess;
	char hlc[32];
	int num_higher = 0, num_lower = 0, num_total = 0;

	printf("Think of a number you wish me to guess.\n");
	printf("Within which range should I guess?\n");
	printf("Range max: ");
	scanf("%d", &high);
	printf("Range min: ");
	scanf("%d", &low);

	guesslbl:
	guess = rand() % (high + 1 - low) + low;
	printf("\n###\nI GUESS %d\n###\n\n", guess);
	printf("Was I correct? (y)\nToo high? (h)\nToo low? (l)\n");

	wronglbl:
	fgets(hlc, sizeof(hlc), stdin);
	if (strcmp(hlc, "y\n") == 0){
		printf("Yay! I used %d guesses. %d too high, %d too low.\n", num_total, num_higher, num_lower);
	}else if(strcmp(hlc, "h\n") == 0){
		high = guess-1;
		num_higher++;
		num_total++;
		goto guesslbl;
	}else if(strcmp(hlc, "l\n") == 0){
		low = guess+1;
		num_lower++;
		num_total++;
		goto guesslbl;
	}else{
		printf("Please enter a valid option (y/h/l)\n");
		goto wronglbl;

	}






}