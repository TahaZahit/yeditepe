#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE* fp;
char line[256];

struct symbol
{
	char* name; // symbol name
	char* value; // replacement text
} def_symbols[50];

int symbolCount = 0;

struct mac
{
	char* mname; // macro name
	char mbody[1000]; // macro body
	char* p[3]; // dummy parameters
	int nparams; // number of parameters
	
} macros[20]; // maximum 20 macros can be defined
int macroCount = 0;


char* substr(char const* input, int start, int len)
{
	char* ret = (char *)(malloc(len + 1));
	memcpy(ret, input + start, len);
	ret[len] = '\0';
	return ret;
}

char* clone(char* source)
{
	char *destination;
	int size, i;
	for (size = 0; source[size] != '\0'; size++);
	destination = (char *)malloc((size + 1) * sizeof(char));
	for (i = 0; i < size; i++) destination[i] = source[i];
	destination[i] = '\0';
	return destination;
}


void define(char* tok)
{
	tok = strtok(NULL, " \t\n"); //deðiþken adý
	def_symbols[symbolCount].name=clone(tok);
	tok = strtok(NULL, " \t\n"); //deðiþken deðeri
	def_symbols[symbolCount].value=clone(tok);
	symbolCount++;
}

void macro(char* tok)
{	
	struct mac* t = &macros[macroCount];
	t->nparams = 0;

	//Catch Name
	tok = strtok(NULL, " \t\n");
	t->mname=clone(tok);

	//Catch Variables
	tok = strtok(NULL, " \t\n,()");
	while (tok != NULL)
	{
		t->p[t->nparams]=clone(tok);
		tok = strtok(NULL, " \t\n,()");
		t->nparams++;
	}

	//Catch Body 
	int size = 0;
	char temp[256];
	fgets(line, 256, fp);
	do
	{		
		for (int i = 0; line[i] != '\0'; i++, size++) t->mbody[size] = line[i];
		fgets(line, 256, fp);
		strcpy(temp, line);
		tok = strtok(temp, " \t\n");
	} while (strcmp(tok, "@ENDM"));
	macroCount++;

}

void _if(char * tok)
{
	char*left,*right;


	
	
}

void LineScanner(char* line)
{
	char* tok = strtok(line, " \t\n");
	while (tok != NULL)
	{
		if (!strcmp(tok, "@DEFINE")) define(tok);
		else if (!strcmp(tok, "@MACRO")) macro(tok);

		tok = strtok(NULL, " \t\n");
	}
}

int main(int argc, char* argv[])
{
	//FILE *fp = fopen(argv[1], "r");

	fp = fopen("a.txt", "r");

	while (!feof(fp))
	{
		fgets(line, 256, fp);
		LineScanner(line);
	}
	for(int i=0;i<symbolCount;i++)
		printf("DEF %d: %s-%s\n",i,def_symbols[i].name,def_symbols[i].value);
	for (int i = 0; i<macroCount; i++)
		printf("MACRO %d\n%s\n%s\n", i, macros[i].mname, macros[i].mbody);

	getchar();
}
