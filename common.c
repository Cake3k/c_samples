#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdbool.h>
#include <string.h>
#include "common.h"


/**
 * Lists all files in given subdirectory, 
 * with given filetype.
 */
bool listfiles(char *dirname[], char *filetype[]){

	DIR *dir;
	struct dirent *dirent;

	if ((dir = opendir(*dirname)) != NULL){
		printf("\nAvailable files in directory:\n");
		while((dirent = readdir(dir)) != NULL){
			if (strstr(dirent->d_name, *filetype))
				printf("%s\n", dirent->d_name);
		}

		closedir(dir);
	}else{
		perror("");
		return false;
	}
	return true;

}

/**		Quick Percentage calculation		*/
float percentage(int part, int total){
	if (part == 0)
		return 0;

	return ((float)part/(float)total*100);
}