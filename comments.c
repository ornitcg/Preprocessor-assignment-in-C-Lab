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
		/*fprintf(stderr,"line %d ",i++);*/
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
	int len, openCom, closeCom, openQuot, closeQuot;
	char *temp;
	len = strlen(line);
	openCom = subStrPos(line ,OPEN_COM);  /*position of first comment opening*/
	closeCom = subStrPos(line ,CLOSE_COM); /*position of first comment closing*/
	openQuot = subStrPos(line ,QUOTE);  	/*position of first quote mark*/

	if ((openQuot = subStrPos(line ,QUOTE))>-1)  /*case there is a quote, find the position of closing quote*/
		if ((closeQuot = subStrPos(line + openQuot + 1 ,QUOTE))>-1) 
			closeQuot += openQuot +1;
	temp = line;
	while (openCom > -1 || closeCom > -1 || *inComment){
		
		if (*inComment){       			 /*assuming that all comments are valid*/
			if (closeCom == -1)			/* the whole row is part of comment*/
				return NULL;
			
			else temp = removeFromTo(temp, 0 , closeCom+1);
			
			*inComment = 0;
		}
		
		else if (((openQuot > -1) && (closeQuot >-1)) && ((openQuot < openCom)  && (closeCom < closeQuot))){  
			/*skipping string that contains a comment*/
			temp = temp + closeQuot+1;
			
		}
		else if (openCom > -1 && closeCom > -1 && openCom  > closeQuot){	/*comment comes after quot*/	     
			temp = openCom + removeFromTo(temp, openCom , closeCom + 1);
			
		}

		else if (openCom > -1 && closeCom > -1){		     /* comment ends within the line*/
			temp = openCom + removeFromTo(temp, openCom , closeCom + 1);
			
		}
		else {				    /* comment begins but not ends in the line*/
			temp = openCom + removeFromTo(temp, openCom , len);
			*inComment = 1;	
			break;
		}
		openCom = subStrPos(temp ,OPEN_COM);
		closeCom = subStrPos(temp ,CLOSE_COM);
		openQuot = subStrPos(temp ,QUOTE);
		if (openQuot > -1){  /*case there is a quote, find the closing quote*/
			closeQuot = subStrPos(temp + openQuot + 1 ,QUOTE);
				if (closeQuot > -1) 
					closeQuot = closeQuot + openQuot +1;
		}
		
	}
	return line; /*stays poining at beginning of line while temp dose all the cutting*/

}


