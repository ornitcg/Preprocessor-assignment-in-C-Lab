#include <stdio.h>
#include <string.h>
#include "utils.h"



/*Returns 1 if extention is valid and 0 if there 
is a problem with the file name and extention*/
int checkExtention( char *fileName){
	int  lenName, lenExt, extPos, dotPos;
	char *temp;

	lenName = strlen(fileName);
	lenExt = strlen(EXTENTION);
	if (lenName == FILENAME_MAX){
		fprintf(stderr, "Error - too long file name.\n");
		return 0;
	}
	dotPos = subStrPos(fileName ,DOT);
	extPos = subStrPos(fileName ,EXTENTION);
	if (extPos == -1 && dotPos > -1) {
		fprintf(stderr, "Error - Wrong File Extention.\n"); /*if the is an extention that does not begin with .c as in .exe*/
		return 0;
	}
	if (extPos > -1){
		temp = fileName + extPos;
	
		if (*(temp + lenExt)  != '\0'){ /*if there is any char right after the .c as in .cpp*/
			fprintf(stderr, "Error - Wrong File Extention.\n");
			return 0;
		}
	}
	return 1;
}



/*Returns -1 if substring was not found
If found, returns the position in string*/

int subStrPos(char *string ,char *sub){
	int i,j, lenStr, lenSub;

	if(string == NULL)
 		return -1;

	lenStr = strlen(string);
	lenSub = strlen(sub);

	if (lenSub == 0 || lenStr == 0) return -1;
	for(i = 0 ; i < lenStr ; i++){  /*looking for the sub string in string*/

		for(j = 0 ; j < lenSub ; j++){
			if (string[i+j] != sub[j])
				break;  /*sub is not here*/
		}
		if (j == lenSub) return i; /*sub was found starting from position i*/	
	}
	return -1;

}

/*Gets a string and a range, and returns the string 
without the part that was in the given range*/
char *removeFromTo(char *string, int from ,int to){
	int len , i;
	len = strlen(string);
	if (to == len){
		string[from] = '\0';
		return string;
	}
	if ((to +1  - from) >= len) return NULL; /*Delete all row*/
	
	for (i = 0 ; i < len ; i++){
		if ((to +1 +i) < len)	
			string[from + i] = string[to +1 +i];
		else {
			string[from + i] = '\0';
			break;
		}	
	}
	return string;
}


	
