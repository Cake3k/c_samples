#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "coinflip.h"

static char flip();
static float percentage(int total, int part);

/** Flips a coin when the user hits enter.
 * 	Records flip statistics, and outputs them
 * 	at user request or when user quits.
 */
void coinflipper(){
	int heads = 0, tails = 0, flips = 0;
	char input[32];
	char res;

	/* Set random seed */
	srand(time(NULL));

	printf("Hit enter to flip a coin.\nType 'q' to quit.\nType 's' to see current number of heads and tails.\n");

	while(1){

		gotscore:

		fgets(input, sizeof(input), stdin);

		if (strcmp(input, "q\n") == 0)
			break;
		else if((strcmp(input, "s\n") == 0)){
			printf("Total heads: %d (%.2f%%)\nTotal tails: %d (%.2f%%)\n", 
				heads, percentage(heads, flips), tails, percentage(tails, flips));
			goto gotscore;
		}
		
		res = flip();
		flips++;

		switch (res){
			case 'h':
				heads++;
				printf("Flip number %d:   HEADS!\n", flips);
				break;			
			case 't':
				tails++;
				printf("Flip number %d:   TAILS!\n", flips);
				break;
		}
	}

	printf("Final result after %d flips:\nHeads: %d (%.2f%%)\nTails: %d (%.2f%%)\n", 
		flips, heads, percentage(heads, flips), tails, percentage(tails, flips));
}

/** 	
 * Flip calculation.
 * 
 * Uses C rand function with time as seed (set in main),
 * modulo 100 to set a number between 0 and 99.
 * 0-49 = Heads
 * 50-99 = Tails
 */
static char flip(){
	int flip = rand() % 100;

	if (flip <= 49)
		return 'h';
	else if (flip >= 50)
		return 't';

}

/* 		Quick Percentage calculation for prints		*/
static float percentage(int part, int total){
	if (part == 0)
		return 0;

	return ((float)part/(float)total*100);
}