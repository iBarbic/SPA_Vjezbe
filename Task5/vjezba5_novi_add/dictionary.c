#include "dictionary.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
Dictionary create() {
	Dictionary dict = (Dictionary)malloc(sizeof(Word));
	dict->next = NULL;
	dict->word = NULL;
	return dict;
}


void add(Dictionary dict,char *str) {

	if (dict == NULL) {
		return;
	}
	Dictionary tmp = dict;

	/*while (tmp->next != NULL) {
		if (tmp->word != NULL) {
			if (strcmp(str, tmp->word) == 0) {
				tmp->count++;
				return;
			}
		}
		tmp = tmp->next;
	}
	*/
	Dictionary s = tmp->next;

	int duzina = strlen(str);
	if (s == NULL) {
		Dictionary novi = (Dictionary)malloc(sizeof(Word));
		novi->word = (char*)malloc(sizeof(char) *duzina);
		strcpy(novi->word, str);
		novi->count = 1;
		novi->next = NULL;
		tmp->next = novi;
	}
	while (s != NULL) {
		if (strcmp(str, s->word) == 0) {
			s->count++;
			return;
		}
	
	
	
		else if (tmp->word == NULL && strcmp(s->word, str) > 0 || strcmp(s->word, str) > 0 && strcmp(tmp->word, str) < 0) { //mozda tmp->next==NULL zaminit za tmp->word==NULL
			Dictionary novi = (Dictionary)malloc(sizeof(Word));
			novi->word = (char*)malloc(sizeof(char)*strlen(str));
			strcpy(novi->word, str);
			novi->count = 1;
			novi->next = s;
			tmp->next = novi;
			return;

		}
		else if (s->next == NULL && strcmp(s->word, str) < 0) {
			Dictionary novi = (Dictionary)malloc(sizeof(Word));
			novi->word = (char*)malloc(sizeof(char) * strlen(str));
			strcpy(novi->word, str);
			novi->count = 1;
			novi->next = NULL;
			s->next = novi;
			return;

		}
		tmp = tmp->next;
		s = s->next;


	}


}
void print(Dictionary dict) {
	dict = dict->next;
	while (dict != NULL) {
		printf("%s||%d -> ", dict->word,dict->count);
		dict = dict->next;
	}
	printf("NULL");
}

void destroy(Dictionary dict) {
	Dictionary tmp = dict->next;
	
	
	while (tmp!= NULL) {
		Dictionary brisi = tmp;
		tmp = tmp->next;
		free(brisi);
		free(brisi->word);
		
		
		
	
		
	}
	free(dict);

	

	
	
}

int filter(Word *w) {
	int broj = w->count;
	
	 if ((5<broj) && strlen(w->word) > 3 && broj<10 ) {
		//printf("!!!!");
		return 1;
	}
	
	 
	else {
		return 0;
	}
	
	
	
	

}
Dictionary filterDictionary(Dictionary indict, int (*filter)(Word *w)) {
	Dictionary temp = indict->next;
	Dictionary prev = indict;
	Dictionary b= (Dictionary)malloc(sizeof(Word));
	indict= indict->next;
	/*while (indict != NULL) {
		printf("%d\n", filter(indict));
		indict = indict->next;
	}
	
	
	indict = indict->next;
	*/
	while (temp->next != NULL) {
		if (filter(indict) != 1){
			indict = indict->next;
		}
	
		//printf("%s    %d\n",temp->word, filter(temp));
		
		if ((filter(temp)) != 1) {
			//printf("%d\n", filter(temp));
			//b = temp;
			prev->next = temp->next;
			temp = temp->next;
			//free(b);
			
		}
			
			
			
		else {
			temp = temp->next;
			prev = prev->next;
		}
		}
	
	if (filter(temp) != 1) {
		prev->next = NULL;
		temp = temp->next;
		
		}
	
	return indict;
}
