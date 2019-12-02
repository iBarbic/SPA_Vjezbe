#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mystrlen(char *str) {

	int i = 0;
	while (str[i] != '\0') {
		i = i + 1;


	}
	return i;
}

void* mystrcpy(char *str1, char *str2) {
	int i = 0;
	while (str1[i] != '\0') {

		str1[i] = str2[i];
		i++;


	}
}

int mystrcmp(char *str1, char *str2) {
	int i = 0;

	while (str1[i] != '\0') {
		if (str1[i] < str2[i]) {
			return -1;
		}
		if (str1[i] > str2[i]) {
			return 1;
		}
		i++;


	}
	return 0;
}

int mystrcat(char *str1, char *str2) {
	int i = 0;
	int j = 0;
	while (str1[j] != '\0') {
		if (str2[i] == '\0') {

			for (j = 0; j < i; j++) {
				str2[i + j] = str1[j];
			}


		}
		i++;
	}
}

char *mystrstr(char *str1, char *str2) {
	int n = 0;
	int i = 0;
	int j = 0;
	int duzina2 = 0;
	int duzina3 = 0;
	char *p;
	while (str2[i] != '\0') {
		duzina2 = duzina2 + 1;
		i++;
	}
	
	while (str1[i] != '\0') {
		
			 
		
		i++;
	}
	for (j = 0; j < i; j++) {
		for (n = 0; n < duzina2; n++) {

			if (str1[j] == str2[n]) {
				duzina3++;

			}
			if (duzina2 == duzina3) {
				p = &str1[j - duzina3 + 1];
				return p;
			}

		}

	}





	return NULL;
}
void reverse(char *str1, char *str2) {

	int j = 0;

	int i = 0;
	while (str2[i] != '\0') {

		i++;

	}


	for (j = 0; j < i; j++) {
		str2[i - j - 1] = str1[j];

	}


}

	

	
int main() {
	/*
	char s1[80]="123";
	char s2[80] = "abc"; //Cat
	mystrcat(s1, s2);
	printf("%s", s1);
	*/
	
	
	/*
	char *s3[10];
	char *s4[10];
	gets(s3);           //Reverse
	gets(s4);
	reverse(s3,s4);
	printf("%s",s4);
	*/
	
	
	
	
	char *string1 = "abcd";
	char *string2 = "abcd";
	/*
	pchar *string1 = "abcd";
	char *string2 = "abcd";
	char *p = mystrstr(string1, string2); //strstr
	char *k;
	k = strstr(string1, string2);
	printf("%p\n", p);
	printf("%p", k);
	*/
	
	//printf("Duzina stringa %d\n", mystrlen(string1)); //duzina
	//mystrcpy(&string1, &string2);
	//printf("Kopija %s\n", string1); //kopija
	
	//printf("%d", mystrcmp(string1, string2)); //compare
		
	
	
	return 0;

	}