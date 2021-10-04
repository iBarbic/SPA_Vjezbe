#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortiranja.h"
#include <stdbool.h>


int main() {
	srand(time(NULL));
	int n = 1000 + rand() % 9000;
	//int n = 10000;
	n_min = 1;
	printf("N = %d\n", n);
	int* niz1 = generate(n);
	double vrijeme_1 = measure(quicksort, niz1, n);
	double vrijeme_2 = measure(quicksort, niz1, n);
	printf("Vrijeme qsort (nesortirani niz): %f  i za sortirani niz: %f \t (pivot ukljucen)\n", vrijeme_1, vrijeme_2);
	choose_pivot = false;
	int* niz2 = generate(n);
	double vrijeme_3 = measure(quicksort, niz2, n);
	double vrijeme_4 = measure(quicksort, niz2, n);
	printf("Vrijeme qsort (nesortirani niz): %f  i za sortirani: %f \t (pivot iskljucen)\n", vrijeme_3, vrijeme_4);

	

/*

	for (n = 0;n< 200; n += 10) {
		int* niz2 = generate(n);
		double vrijeme_5 = measure(quicksort, niz2, n);
		printf("Vrijeme izvodenja quicksort za N = %d: %f\n", n, vrijeme_5);
		double vrijeme_6 = measure(insertionsort, niz2, n);
		printf("Vrijeme izvodenja insertionsort za N = %d: %f\n", n, vrijeme_6);
		printf("\n");
	}
	*/
	free(niz1);
	free(niz2);
	return 0;
}
	
		
		
		
		
	/*int n = 1000;

	int i;
	for (n = 1000; n <= 10000; n += 1000) {
		int *niz1 = generate(n);
		double vrijeme_1 = measure(quicksort, niz1, n);
		printf("Vrijeme za niz od %d :%f\n,", n, vrijeme_1);
	}
	for (n = 1000; n <= 10000; n += 1000) {
		int *niz1 = generate(n);
		quicksort(niz1, n);
		double vrijeme_2 = measure(quicksort, niz1, n);
		printf("Vrijeme za niz od %d :%f\n,", n, vrijeme_2);
	}
	
	/*int n = 200;
	int *niz1 = generate(n);
	double vrijeme_2 = measure(quicksort, niz1, n);
	
	printf("Vrijeme za niz od  :%f\n,",  vrijeme_2);
	*/
