#include <stdio.h>
#include <string.h>
#include "utils.h"


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

/*FILE *makeCopy( FILE *inputFile, char *fileName){
	FILE *cpyF ;
	char newName[FILENAME_MAX], line[MAX_LINE];
	int i;

	strcpy(newName,fileName);
	strcat(newName,"1");
	
	cpyF = fopen(newName , "w");	

	
	while(fgets(line , MAX_LINE-1 , inputFile) != NULL){
		fprintf(cpyF,"%s",line);
		i = subStrPos(&line[10] , CLOSE_COM);
	}

	return cpyF;
}*/


/*Returns 1 if extention is valid and 0 if there 
is a problem with the file name and extention*/
int checkExtention( char *fileName){
	int i,len;
	len = strlen(fileName);
	if (len == FILENAME_MAX){
		fprintf(stderr, "Error - too long file name.\n");
		return 0;
	}
	
	for (i = len ; i > 0 ; i--){
		if (fileName[i] == '.')
			break;
	}
	if (i< 1) {
		fprintf(stderr, "Error - too short file name.\n");
		return 0;
	}
	if (i == len){
		fprintf(stderr, "Error - There is no extention to the file.\n");
		return 0;
	}
	/*if (fileName[i+1] == 'c' && (fileName[i+2] == '\0' || */
	
	return 1;
}

#include <stdio.h>

/*Removes spaces and tabs from source string 's', 
the clean string will be inserted into 'newS'*/
void remChars(char* s, char* newS, char *toRemove){
	char *word; 
	int length ;
	char tmpNew[MAX_LINE] = {'\0'};

	length = strlen(s);
	word = strtok(s, toRemove); 
	if (word == NULL) return;		
	strcpy(tmpNew, word); 
	while((word = strtok(NULL, toRemove))!=NULL){

		length = strlen(tmpNew);
		strcpy(tmpNew+length, word);

	}
	strcpy(newS, tmpNew);
	 
}

/*Returns -1 if substring was not found
If found, returns the start position in string*/

int subStrPos(char *string ,char *sub){
	int i,j, lenStr, lenSub;
	
	lenStr = strlen(string);
	lenSub = strlen(sub);
	if (lenSub == 0 || lenStr == 0) return -1;
	for(i = 0 ; i < lenStr ; i++){

		for(j = 0 ; j < lenSub ; j++){
			if (string[i+j] != sub[j])
				break;

		}
		if (j == lenSub) return i;	
	}
	return -1;

}




	
