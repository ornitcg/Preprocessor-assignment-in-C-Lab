#include <stdio.h>
#include <string.h>
#include "utils.h"





/*Returns 1 if extention is valid and 0 if there 
is a problem with the file name and extention*/
int checkExtention( char *fileName){
	int i, len;
	len = strlen(fileName);
	if (len == FILENAME_MAX){
		fprintf(stderr, "Error - too long file name.\n");
		return 0;
	}
	if (len < 1) {
		fprintf(stderr, "Error - too short file name.\n");
		return 0;
	}
	
	for (i = len ; i > 0 ; i--){
		if (fileName[i] == '.')
			break;
	}
	
	if (i == len){
		fprintf(stderr, "Error - There is no extention to the file.\n");
		return 0;
	}
	/*if (fileName[i+1] == 'c' && (fileName[i+2] == '\0' || */
	
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


	
