#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdbool.h>
#include <string.h>
#include "common.h"
#include "txtcount.h"

int BUFSIZE = 255;



void txtcounter(char *type){

	char fpath[BUFSIZE];
	char input[32];
	bool ret;

	char *dirname = "./txtfiles/";
	char *ftype = ".txt";
	
	bool readconf = listfiles(&dirname, &ftype);
	if (readconf == false){
		return;
	}

	retry:
	fpath[0] = '\0';
	printf("Enter filename: ");
	fgets(input, sizeof(input), stdin);
	strtok(input, "\n");
	strcat(fpath, dirname);
	strcat(fpath, input);

	if (strcmp(type, "word") == 0)
		ret = wordcounter(fpath);
	else if(strcmp(type, "ch") == 0)	
		ret = charcounter(fpath);
	else
		printf("Incorrect type!\n");

	if(ret == false)
		goto retry;
	else
		return;
	
}

/**
 * Counts the number of words in a text file,
 * chosen by the user.
 */
static bool wordcounter(char *fpath){
	FILE *fp;
	int numwords = 0;

	char *buf;
	buf = malloc(BUFSIZE);
	fp = fopen(fpath, "r");
	if (fp == NULL){
		printf("File not available\n");
		return false;
	}

	while(fscanf(fp, "%s", buf) == 1){
		numwords++;
	}
	
	if(feof(fp)){
		printf("\n#####\n%d words found.\n#####\n", numwords);
	}else
		printf("ERROR: Could not read to EOF.\n");

	rewind(fp);
	fclose(fp);
	free(buf);
	return true;

}

/**
 * Counts the number of characters in a text file,
 * chosen by the user.
 */
static bool charcounter(char *fpath){
	FILE *fp;
	int c;
	int numchars = 0;

	char *buf;
	buf = malloc(255);

	fp = fopen(fpath, "r");
	if (fp == NULL){
		printf("File not available\n");
		return false;
	}

	while(c = fgetc(fp) != EOF)
		numchars++;

	if(feof(fp)){
		printf("\n#####\n%d characters found.\n#####\n", numchars);
	}else
		printf("ERROR: Could not read to EOF.\n");


	rewind(fp);
	fclose(fp);
	free(buf);
	return true;

}


