#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//void strChange(char *rp, char *dp, char *text) {
//	char *p = text;
//	int textSize,rpSize,dpSize;
//	for (textSize = 0; text[textSize] != '\0'; textSize++);
//	for (rpSize = 0; rp[rpSize] != '\0'; rpSize++);
//	for (dpSize = 0; dp[dpSize] != '\0'; dpSize++);
//	printf("text=%d\nrp=%d\ndp=%d\n",textSize, rpSize, dpSize);
//
//	int i,j,flag=1;
//	for (i = 0; i < textSize; i++) {
//		if (text[i] == dp[0]) {
//			for (j = 0; j < dpSize; j++) {
//				if (text[i + j] != dp[j])flag = 0;
//			}
//			if (flag) {
//
//			}
//		}
//	}
//	
//
//}

void replace(char* text, char* dp, char* rp) {
	printf("%s\n", text);
	int lenRp = strlen(rp);
	int lenDp = strlen(dp);
	int lenText = strlen(text);

	char *p = strstr(text, dp);
	if (p == NULL)return;
	int fark = lenRp - lenDp;
	char c,x;
		if (fark>0)
			for (int i = lenText + fark; &text[i] != p; i--)
			{
				text[i] = text[i - fark];
			}
		else if (fark < 0) {
			for (int i = 0; i < lenText; i++) {
				p[i] = p[i - fark];
			}
		}
		
	for (int i = 0; i < lenRp; i++) {		
		*p = rp[i];
		p++;
	}
}
int main() {

	char text[1000] = "	ali Ata bak";
	char dp[] = "A";
	char rp[] = "";
	replace(text, dp, rp);
	printf("%s", text);
	getchar();
}