#include "../inc/libmx.h"

char *mx_strchr(const char *s, int c){
	int i = 0;
	for(; s[i] != c && s[i]; i++);

	return *(char*)(s+i) == c ? (char*)(s+i) : 0;
}


