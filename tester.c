#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coinflip.h"
#include "numberguess.h"

static void module_opt();

int main(int argc, char *argv[]){

	if (argc<2){
		printf("Testing requires an argument\n");
		module_opt();
		return 0;
	}
	else
		printf("%s\n", argv[1]);
	if (strcmp(argv[1], "flip") == 0)
		coinflipper();
	else if (strcmp(argv[1], "guess") == 0)
		numberguesser();
	else{
		printf("Incorrect argument.\n");
		module_opt();
	}
}

static void module_opt(){
	
	printf("Choose one available testing option - argument\n");
	printf("#####\n\n");
	printf("Coin flip - flip\n");
	printf("Number guesser - guess\n");
}