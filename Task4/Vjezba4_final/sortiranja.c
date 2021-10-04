#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>
bool choose_pivot=true;
int n_min;
// generiranje i ispis niza
int* generate(int n) {
	int i;
	int *niz = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		niz[i] = rand() % 1000;//maknit ako nesto ne bude radilo
	return niz;
}

void print(int *niz, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", niz[i]);
	}
	printf("\n");
}

// selection sort
void selectionsort(int *niz, int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		int j, tmp, maxi = i;
		for (j = i + 1; j < n; j++) {
			if (niz[j] < niz[maxi])
				maxi = j;
		}

		tmp = niz[maxi];
		niz[maxi] = niz[i];
		niz[i] = tmp;
	}
}

// insertion sort
void insertionsort(int *niz, int n) {
	int i;
	for (i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && niz[j - 1] > niz[j]) {
			int tmp;
			tmp = niz[j-1];
			niz[j - 1] = niz[j];
			niz[j] = tmp;
			j--;
		}
	}
}

// quick sort
int partition(int *niz, int n) {
	int tmp;
	int l, r;
	l = 1;
	r = n - 1;
	
	if (choose_pivot==true){
		
		if(niz[n/2]<niz[0] && niz[n/2]>niz[n-1] || niz[n/2]>niz[0] && niz[n/2]<niz[n-1]){
			tmp = niz[0];
			niz[0]=niz[n/2];
			niz[n/2]=tmp;

		}
		else if(niz[n-1]<niz[0] && niz[n-1]>niz[n/2] || niz[n-1]>niz[0] && niz[n-1]<niz[n/2]) {
			tmp = niz[0];
			niz[0] = niz[n-1];
			niz[n-1] = tmp;
		}
}





	while (l < r) {
		if (niz[r] >= niz[0]) {
			r--;
		}
		else if (niz[l] < niz[0]) {
			l++;
		}
		else {
			tmp = niz[l];
			niz[l] = niz[r];
			niz[r] = tmp;
		}
	}
	if (niz[0] < niz[r]) { // 1
		return 0;
	}
	else { // 3
		tmp = niz[r];
		niz[r] = niz[0];
		niz[0] = tmp;
		return r;
	}
}
double measure(void(*sort)(int *niz, int n), int *niz, int n) {
	int start_time = clock();
	sort(niz, n);
	int end_time = clock();
	return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}
void quicksort(int *niz, int n) {

	if (n < 2)
		return;

	if (n < 200) {
		int pi = partition(niz, n);
		int pocetno_vrijeme = clock();
		quicksort(niz, pi);
		int vrijeme_zavrsetka = clock();
		double vrijeme_izvodenja = ((vrijeme_zavrsetka - pocetno_vrijeme) / CLOCKS_PER_SEC);
		if (measure(insertionsort, niz, n) <= vrijeme_izvodenja) {
 // printf("za nove za koje je brzi insertion od qs %d\n",n);
			n_min = n;
			insertionsort(niz, n);
		}
	}
	else {
		int pi = partition(niz, n);
		quicksort(niz, pi);
		quicksort(niz + pi + 1, n - pi - 1);
	}
}
// merge sort
void merge(int *niz, int *niza, int na, int *nizb, int nb) {
	


}

// alocira i vra�a kopiju niza
int* duplicate(int *niz, int n) {
	int i;
	int *novi = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		novi[i] = niz[i];
	}
	return novi;
}

void mergesort(int *niz, int n) {
	
}

// mjerenje vremena izvo�enja funkcije sortiranja

