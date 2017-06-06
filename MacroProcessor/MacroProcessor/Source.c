#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct symbol {
	char name[10];	// symbol name
	char value[10];	// replacement text
};
struct symbol def_symbols[50];

struct mac {
	char mname[10];	// macro name
	int nparams;	// number of parameters
	char p[3][10];	// dummy parameters
	char mbody[1000];	// macro body
};
struct mac macros[20];	// maximum 20 macros can be defined

struct param {
	char dp[3][10];	// dummy paramaters
	char rp[3][10];	// real paramaters
};
struct param PT[5];	//maximum 5 nested macro calls


FILE *fp, *nfp;
char line[256];
char temp[256];
char *token;
int symbolCount = 0;
int macroCount = 0;

void replace(char* text, char* dp, char* rp) {
	int lenRp = strlen(rp);
	int lenDp = strlen(dp);
	int lenText = strlen(text);
	int diff = lenRp - lenDp;
	int i;
	char *p = strstr(text, dp), c, x;
	if (p == NULL)return;
	

	if (diff > 0) for (i = lenText + diff; &text[i] != p; i--)text[i] = text[i - diff];
	else if (diff < 0) 	for (i = 0; i < lenText; i++) p[i] = p[i - diff];
	
	for (i = 0; i < lenRp; i++, p++) *p = rp[i];
}

void DEFINE()
{
	struct symbol *t = &def_symbols[symbolCount];
	token = strtok(NULL, " \t");
	strcpy(t->name, token);
	token = strtok(NULL, " \t\n\r");
	strcpy(t->value, token);
	symbolCount++;
}

void MACRO()
{
	struct mac* t = &macros[macroCount];
	t->nparams = 0;
	//Catch Name
	token = strtok(NULL, " \t\n\r");
	strcpy(t->mname, token);
	//Catch Variables
	token = strtok(NULL, " \t\n\r,()");
	while (token != NULL)
	{
		strcpy(t->p[t->nparams], token);
		token = strtok(NULL, " \t\n\r,()");
		t->nparams++;
	}
	//Catch Body 
	int size = 0;
	char temp[256];
	fgets(line, 256, fp);

	do
	{
		int i;
		char *ptr = line;
		for (i = 0; ptr[i] != '\0'; i++, size++) t->mbody[size] = ptr[i];
		fgets(line, 256, fp);
		strcpy(temp, ptr);
		token = strtok(temp, " \t\n\r");
	} while (strcmp(token, "@ENDM"));
	macroCount++;
}

void MCALL()
{
	//Macro name
	int i, j;
	struct param x;
	char dp[10], rp[10];

	token = strtok(NULL, " \t\n\r");
	for (i = 0; i < macroCount && strcmp(token, macros[i].mname); i++);
	//Catch Variables
	
	char _body[1000], *body = _body;
	strcpy(_body, macros[i].mbody);
	
	for (j = 0; j < macros[i].nparams; j++)
	{
		strcpy(x.dp[j], macros[i].p[j]);
		token = strtok(NULL, " ,()\t\n\r");
		strcpy(x.rp[j], token);
	}
	
	for (j = 0; j < macros[i].nparams; j++)
	{
		strcpy(dp, x.dp[j]);
		strcat(dp, ",");
		strcpy(rp, x.rp[j]);
		strcat(rp, ",");
		replace(body, dp, rp);
		strcpy(dp, x.dp[j]);
		strcat(dp, "\n");
		strcpy(rp, x.rp[j]);
		strcat(rp, "\n");
		replace(body, dp, rp);
	}
	fprintf(nfp, "%s", body);

}

void IF()
{
	int index, flag = 0;
	struct symbol x;
	char op;
	token = strtok(NULL, " ()");
	
	for (index = 0; token[index] != '\0'; index++) {
		op = token[index];
		if (op == '=' || op == '<' || op == '>') break;
	}

	strcpy(x.name, strtok(token, "=><() "));
	strcpy(x.value, strtok(NULL, ") \n\r\t"));

	int i;
	for (i = 0; i < symbolCount; i++)
	{
		if (op == '=' && !strcmp(x.name, def_symbols[i].name) && !strcmp(x.value, def_symbols[i].value)) flag = 1;
		else if (op == '<' && !strcmp(x.name, def_symbols[i].name) && (atoi(def_symbols[i].value) < atoi(x.value))) flag = 1;
		else if (op == '>' && !strcmp(x.name, def_symbols[i].name) && (atoi(def_symbols[i].value) > atoi(x.value))) flag = 1;
	}

	if (flag)
	{
		fgets(line, 256, fp);
		strcpy(temp, line);
		while (strcmp(token, "@ENDIF") && strcmp(token, "@ELSE"))
		{

			token = strtok(temp, " \t\n\r");
			if (!strcmp(token, "@MCALL")) MCALL();
			else fprintf(nfp, "%s", line);
			fgets(line, 256, fp);
			strcpy(temp, line);
			token = strtok(temp, " \t\n\r");
		}
		if (!strcmp(token, "@ELSE"))
		{
			while (strcmp(token, "@ENDIF"))
			{
				fgets(line, 256, fp);
				strcpy(temp, line);
				token = strtok(temp, " \t\n\r");
			}
		}
		return;
	}
	do
	{
		fgets(line, 256, fp);
		strcpy(temp, line);
		token = strtok(temp, " \t \n \r");
	} while (strcmp(token, "@ELSE"));
	do
	{
		fgets(line, 256, fp);
		strcpy(temp, line);
		token = strtok(temp, " \t \n \r");
		if (!strcmp(token, "@MCALL")) MCALL();
		else if (strcmp(token, "@ENDIF")) fprintf(nfp, "%s", line);
	} while (strcmp(token, "@ENDIF"));
}

int main(int argc, char* argv[])
{
	fp = fopen("code.asm", "r");
	nfp = tmpfile();
	while (!feof(fp))
	{
		fgets(line, 256, fp);
		strcpy(temp, line);
		token = strtok(temp, " \t");
		if (!strcmp(token, "@DEFINE"))DEFINE();
		else if (!strcmp(token, "@MACRO"))MACRO();
		else if (!strcmp(token, "@MCALL")) MCALL();
		else if (!strcmp(token, "@IF"))IF();
		else if (line[0] != '\r')fprintf(nfp, "%s", line);
		if (!strcmp(temp, "\tEND\n")) break;
	}
	
	fclose(fp);
	rewind(nfp);
	fp = nfp;
	nfp = fopen("final.asm", "w+");
	while (!feof(fp))
	{
		fgets(line, 256, fp);
		strcpy(temp, line);
		token = strtok(temp, " \t");
		if (!strcmp(token, "@MCALL")) MCALL();
		else if (!strcmp(token, "@IF"))IF();
		else if (line[0] != '\n')fprintf(nfp, "%s", line);
		if (!strcmp(temp, "\tEND\n")) break;

	}


}
