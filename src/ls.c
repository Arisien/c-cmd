#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "./header/sutil.h"
#include "./header/cutil.h"

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
			printc(filename, ANSI_BLUE);

		else if (endsWith(filename, ".exe") || endsWith(filename, ".out"))
			printc(filename, ANSI_GREEN);

		else printf("%s ", filename);
	}

	closedir(dr);

	printf("\n");

	return 0;
}
