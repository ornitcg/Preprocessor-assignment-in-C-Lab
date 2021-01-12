#define MAX_LINE 500
#define MAX_ARGS 2
#define OPEN_COM "/*"
#define CLOSE_COM "*/"
#define INCLUDE "#include"
#define EMPTY_STRING ""
#define TO_REMOVE " \""



void remChars(char* s, char* newS, char *toRemove);
int checkExtention( char *fileName);

FILE *copyHeaders(FILE *c1F , char *fileName);
FILE *makeCopy( FILE *inputFile, char *fileName);
int subStrPos(char *string ,char *sub);
