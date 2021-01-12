#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "headers.h"

FILE *copyHeaders(FILE *c1F , char *fileName){
	FILE *cpyF, *lib ;
	char newName[FILENAME_MAX], headerFileName[FILENAME_MAX];
	char line[MAX_LINE];
	char* afterInc;
	int include;
	
	strcpy(newName,fileName);
	strcat(newName,"2");

	cpyF = fopen(newName , "w");	/*create new file*/

	/*remChars(char* s, char* newS,*char toRemove)*/
	while(fgets(line , MAX_LINE-1 , inputFile) != NULL){
		include = checkInclude(line);
		if (include){
			libName = getName(line);
			lib = fopen(headerFileName, "r");
			copyLines(lib, cpyF);   /*lib -source, cpyF -destination*/
		}
		/*incPos = subStrPos(line , INCLUDE);*/
	
		
	}
	return cpyF;

	
	return NULL;
}
