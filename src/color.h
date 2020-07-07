#ifndef COLOR_H
#define COLOR_H

//Color util library by Arisien (https://github.com/Arisien)


#define ANSI_GREEN  "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define ANSI_DEF "\x1b[0m"

void printc(char *str, char *clr){
	printf("%s%s "ANSI_DEF, clr, str);
}

#endif
