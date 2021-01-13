#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "comments.h"
#include "headers.h"

/*Author: Ornit cohen gindi*/


/*Comments Assumptions: comments are not nested, and no quoteation marks appear inside string*/
/*Header Assumptions: can appear in middle of code, not inside other strings, */
/*and always first in line (aside of spaces)*/
/*Added a messy input file and cute (non C)  header file to run this code with*/

int main(int argc, char *argv[]){

	char inpFileName[FILENAME_MAX] ;
	FILE *inpF ,*c1F, *c2F;

	if (argc < MAX_ARGS) {
		fprintf(stderr,"Error - There is no input file\n"); /*none given*/
		return 0;		
	}
	if (argc > 2) {
		fprintf(stderr,"Error - Too many arguments\n"); /*none given*/
		return 0;		
	}

	strcpy(inpFileName ,argv[MAX_ARGS-1]);
	
	if (checkExtention(inpFileName) == 0) return 0;  /*case something is wrong with  extention,  error msg inside*/
	
	inpF = fopen(inpFileName, "r");

	if (inpF == NULL){ 			 		 
		fprintf(stderr,"Error - cannot open file, file name may be wrong.\n");  /*like does not exist*/
		return 0;
	} 
	

	c1F = removeComments(inpF,inpFileName);
	fclose(c1F);	
	c2F = copyHeaders(inpFileName);
			
	fclose(inpF);
	fclose(c2F);	
	
	return 1;
}
