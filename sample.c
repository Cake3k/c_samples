#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coinflip.h"
#include "numberguess.h"
#include "txtcount.h"

static void optprint();

/**
 * Main entry point for sample program
 */
void main(){
	printf("\nSample C programs.\nType in the corresponding command to choose an option.\n");
	
	char input[32];
	
	int active = 1;
	while(active == 1){
		optprint();

		fgets(input, sizeof(input), stdin);

		if(strcmp(input, "cf\n") == 0)
			coinflipper();
		else if(strcmp(input, "ng\n") == 0)
			numberguesser();
		else if (strcmp(input, "wc\n") == 0){
			char *in = "word";
			txtcounter(in);
		}else if (strcmp(input, "chc\n") == 0){
			char *in = "ch";
			txtcounter(in);
		}else if(strcmp(input, "q\n") == 0)
			break;
		else
			printf("Invalid command\n");
		
	}

}

/**
 * Print module options
 */
static void optprint(){
	printf("\nOption        -     Command\n");
	printf("##############################\n");
	printf("Coin flip       -     cf\n");
	printf("Number guesser  -     ng\n");
	printf("Word counter    -     wc\n");
	printf("Char counter    -     chc\n");
	printf("Quit            -     q\n\n");
}