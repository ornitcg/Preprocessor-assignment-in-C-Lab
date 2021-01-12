#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "comments.h"

FILE *removeComments( FILE *inputFile, char *fileName){
	FILE *cpyF ;
	char newName[FILENAME_MAX];
	char line[MAX_LINE];
	char* l;
	int inComment=0 ; 
	
	
	strcpy(newName,fileName);
	strcat(newName,"1");
	
	cpyF = fopen(newName , "w");	/*create new file*/


	while(fgets(line , MAX_LINE-1 , inputFile) != NULL){
		
		l = cleanCommentsLine(line, &inComment);
		if (l == NULL)
			fprintf(cpyF,"%s", EMPTY_STRING);
		else fprintf(cpyF,"%s",l);
	}
	return cpyF;
}


/*cleans all comment parts from a single line
returns pointer to clean string*/
char *cleanCommentsLine(char *line , int *inComment){
	int len, openPos, closePos;

	len = strlen(line);
	openPos = subStrPos(line ,OPEN_COM);
	closePos = subStrPos(line ,CLOSE_COM);
	
	while (openPos > -1 || closePos > -1 || *inComment){
		
		if (*inComment){       			 /*assuming that all comments are valid*/
			if (closePos == -1)			/* the whole row is part of comment*/
				return NULL;
			
			else line = removeFromTo(line, 0 , closePos+1);
			*inComment = 0;
		}
		else if (closePos>-1)		     /* comment ends within the line*/
				line = removeFromTo(line, openPos , closePos+1);
		else {				    /* comment begins but not ends in the line*/
			line = removeFromTo(line, openPos , len);
			*inComment = 1;	
			break;
		}
		openPos = subStrPos(line ,OPEN_COM);
		closePos = subStrPos(line ,CLOSE_COM);
	}
	return line;

}
