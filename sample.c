#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coinflip.h"
#include "numberguess.h"

void optprint();

void main(){
	printf("\nSample C programs.\nType in the corresponding command to choose an option.\n");
	
	//printf("Coin flip\t-\tcf");
	//printf("Quit\t-\tq\n");
	char input[32];
	

	/*while(1){
		//fgets(input, sizeof(input), stdin);
		//if (strcmp)

	}*/
	int active = 1;
	while(active == 1){
		optprint();

		fgets(input, sizeof(input), stdin);

		if(strcmp(input, "cf\n") == 0)
			coinflipper();
		else if(strcmp(input, "ng\n") == 0)
			numberguesser();
		else if(strcmp(input, "q\n") == 0)
			break;
		else
			printf("Invalid command\n");
		
	}

}

void optprint(){
	printf("\nOption        -     Command\n");
	printf("##############################\n");
	printf("Coin flip       -     cf\n");
	printf("Number guesser  -     ng\n");
	printf("Quit            -     q\n\n");
}