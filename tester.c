#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coinflip.h"
#include "numberguess.h"
#include "txtcount.h"


static void module_opt();

/**
 * Entry point for testing modules
 * @param[in]  argv Which module to test
 */
void main(int argc, char *argv[]){

	if (argc<2){
		printf("Testing requires an argument\n");
		module_opt();
		return;
	}
	else
		printf("%s\n", argv[1]);
	if (strcmp(argv[1], "flip") == 0)
		coinflipper();
	else if (strcmp(argv[1], "guess") == 0)
		numberguesser();
	else if (strcmp(argv[1], "wordc") == 0){
		char *in = "word";
		txtcounter(in);
	}else if (strcmp(argv[1], "charc") == 0){
		char *in = "ch";
		txtcounter(in);
	}
	else{
		printf("Incorrect argument.\n");
		module_opt();
	}
}

/**
 * Print module options
 */
static void module_opt(){
	
	printf("Choose one available testing option - argument\n");
	printf("#####\n\n");
	printf("Coin flip - flip\n");
	printf("Number guesser - guess\n");
	printf("Word counter - wordc\n");
	printf("Character counter - charc\n");
}