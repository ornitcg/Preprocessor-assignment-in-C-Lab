#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "headers.h"

FILE *copyHeaders(char *fileName){ /*fileName has the extention of .c*/
	FILE *c1F, *cpyF, *hFile ;
	char srcFileName[FILENAME_MAX], newName[FILENAME_MAX], headerFileName[FILENAME_MAX];
	char line[MAX_LINE];
	int incPos1,posQuot1,posQuot2;
	
	strcpy(srcFileName,fileName);
	strcpy(newName,fileName);
	strcat(srcFileName,"1");
	strcat(newName,"2");

	c1F = fopen(srcFileName , "r");
	cpyF = fopen(newName , "w");	/*create new file*/
	
	/*remChars(char* s, char* newS,*char toRemove)*/
	FOREVER{
		while(fgets(line , MAX_LINE-1 , c1F) != NULL){
			incPos1 = subStrPos(line , INCLUDE); 	/*find if include statement exists in line*/
			
			if (incPos1 > -1){       			/*case #include statement exists*/
				posQuot1 = subStrPos(line , QUOTE);     /*find the first quotation mark*/
				posQuot2 = posQuot1 + 1 + subStrPos(line + posQuot1 + 1 , QUOTE);   /*find the second quotation mark*/
				
				if (posQuot1 == -1){
					fprintf(cpyF, "%s", line);
					break;
				}
	
				getSubstring(line , posQuot1 +1 , posQuot2 -1 , headerFileName);     
				hFile = fopen(headerFileName, "r");
				
				copyLines( cpyF, hFile);   /*lib -source, cpyF -destination*/
				fclose(hFile);
				fprintf(cpyF, "%s", line + posQuot2 +1);  /*add to file, the rest of the line after the include statement*/
			}
			else fprintf(cpyF, "%s", line); /*case of no include statment - just copy the line as is*/
		
		}
		if (feof(c1F)){ /*end of file*/
			break;
		}	
	}

	fclose(c1F);
	return cpyF;
	
}

void getSubstring(char* source , int from , int to, char* destination){
	int i, len;
	len = to - from +1;
	for (i = 0 ; i < len ; i++){
		destination[i] = source[from +i];
	}
	destination[i] = '\0';
}

void copyLines(FILE *destination, FILE *source){
	char line[MAX_LINE];
	FOREVER{
		while(fgets(line , MAX_LINE-1 , source) != NULL)
			fprintf(destination,"%s", line );

		if (feof(source)){
			break;
		}
	}/*end FOREVER*/	
}

