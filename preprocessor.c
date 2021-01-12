#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "comments.h"
#include "headers.h"

/*Author: Ornit cohen gindi*/

/*Filename Assumptions: the only thing to check is the extention and not other wrong charachters*/
/*Comments Assumptions: comments are not nested, and do not appear inside other strings*/
/*Header Assumptions: can appear in middle of code, not inside other strings, */
/*and always first in line (aside of spaces)*/
/*Added input file and heder file to run this code with*/

int main(int argc, char *argv[]){

	char inpFileName[FILENAME_MAX] ;
	FILE *inpF ,*c1F, *c2F;

	if (argc < MAX_ARGS) {
		fprintf(stderr,"Error - There is no input file\n");
		return 0;		
	}

	strcpy(inpFileName ,argv[MAX_ARGS-1]);
	
	if (checkExtention(inpFileName) == 0) return 0;  /*case something is wrong with  extention,  error msg inside*/
	
	inpF = fopen(inpFileName, "r");

	if (inpF == NULL){ 			 		 
		fprintf(stderr,"Error cannot open file.\n");
		return 0;
	} 
	

	c1F = removeComments(inpF,inpFileName);
	fclose(c1F);	
	c2F = copyHeaders(inpFileName);
			
	fclose(inpF);
	fclose(c2F);	
	
	return 1;
}
