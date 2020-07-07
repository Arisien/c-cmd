#ifndef SUTIL_H
#define SUTIL_H

//String util C library by Arisien (https://github.com/Arisien)

_Bool equals (const char *str1, const char *str2) {
	if(strcmp(str1, str2) == 0) return 1;
	return 0;
}

_Bool contains (const char *str, const char chr) {
	if(strchr(str, chr) != NULL) return 1;
	return 0;
}

_Bool endsWith (const char *str1, const char *str2) {
	if(strlen(str2) > strlen(str1)) return 0;
	char temp[strlen(str1)];
	strcpy(temp, str1);
	memmove(temp, temp+strlen(str1)-strlen(str2), strlen(temp));
	if (equals(temp, str2)) return 1;
	return 0;
}

_Bool startsWith (const char *str1, const char*str2) {
	if(strncmp(str1, str2, strlen(str2)) == 0) return 1;
	return 0;
}

#endif
