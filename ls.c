#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "sutil.h"

#define ANSI_BLUE "\x1b[34m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_DEF "\x1b[0m"

//Ls command in C by Arisien (https://github.com/Arisien) 

int main() {
	struct dirent *de;

	DIR *dr = opendir(".");

	if (dr == NULL) {
		printf("Could not open directory.\n");
		return 0;
	}

	while ((de = readdir(dr)) != NULL){
		char filename[255]; 
		strcpy(filename, de->d_name);
		
		if(equals(filename, ".") || equals(filename, ".."))
			continue;

		if(opendir(filename) != NULL)
			printf(ANSI_BLUE "%s " ANSI_DEF, filename);

		else if (endsWith(filename, ".exe") || endsWith(filename, ".out"))
			printf(ANSI_GREEN "%s " ANSI_DEF, filename);

		else printf("%s ", filename);
	}

	closedir(dr);

	printf("\n");

	return 0;
}
