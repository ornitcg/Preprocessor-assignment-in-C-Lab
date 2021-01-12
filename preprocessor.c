#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "comments.h"
#include "headers.h"



int main(int argc, char *argv[]){

	int i;
	char inpFileName[FILENAME_MAX] ;
	FILE *inpF ,*c1F, *c2F;

	if (argc < MAX_ARGS) {
		fprintf(stderr,"Error - There is no input file\n");
		return 0;		
		}
	
	strcpy(inpFileName ,argv[MAX_ARGS-1]);

	inpF = fopen(inpFileName, "r");
	
	if (inpF == NULL){ 			 		 
		fprintf(stderr,"Error cannot open file.\n");
		return 0;
	} 
	/*i= checkExtention(inpFileName);*/

	c1F = removeComments(inpF,inpFileName);

	c2F = copyHeaders(c1F,inpFileName);
			
				
	fclose(inpF);
	fclose(c1F);	
	/*fclose(c2F);	*/

	





	return 1;
}
