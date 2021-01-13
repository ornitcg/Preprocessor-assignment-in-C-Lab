#define MAX_LINE 500
#define MAX_ARGS 2
#define SPACES " \t"
#define EXTENTION ".c"
#define DOT "."
#define OPEN_COM "/*"
#define CLOSE_COM "*/"
#define QUOTE "\""
#define INCLUDE "#include"
#define EMPTY_STRING ""
#define FOREVER for(;;)

char *removeFromTo(char *string, int from ,int to);

void remChars(char* s, char* newS, char *toRemove);

int checkExtention( char *fileName);
int subStrPos(char *string ,char *sub);

FILE *makeCopy( FILE *inputFile, char *fileName);
