#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int usporedi(const void *a, const void *b)
{
	const double *da = (const double *)a;
	const double *db = (const double *)b;

	return (*da > *db) - (*da < *db);
}

int* generiraj(int n) {
	int *niz = (int*)malloc(n * sizeof(int));
	niz[0] = rand() % 3;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 3;
	}
	return niz;
}
void shuffle(int *niz, int n) {
	for (int i = 0; i < n; i++) {
		int ia = i;
		int ib = rand() % n;
		int tmp = niz[ia];
		niz[ia] = niz[ib];
		niz[ib] = tmp;
	}
}
int* presjek(int *niz1, int n1, int *niz2, int n2) { //O(N^2)
	niz1 = generiraj(n1);
	niz2 = generiraj(n2);

	shuffle(niz2, n2);
	shuffle(niz1, n1);
	clock_t start_t, end_t, total;
	start_t = clock();
	int *niz3 = malloc(3 * n1 * sizeof(int));
	int k = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < n1; i++) { //O(N)
		for (j = 0; j < n2; j++) {//O(N)
			if (niz1[i] == niz2[j]) {
				niz3[k] = niz1[i];
				k++;
			}
		}
	}
	niz3 = (int*)realloc(niz3, k * sizeof(int));
	end_t = clock();
	double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Vrijeme za nesortirani niz1[%d] i niz2[%d]:%f\n", n1, n2, total_t);
	return niz3;
	free(niz3);
}
int* presjek_sortiran(int *niz1, int n1, int *niz2, int n2) { //O(NlogN)
	niz1 = generiraj(n1);
	niz2 = generiraj(n2);

	shuffle(niz1, n1);
	clock_t start_t, end_t, total, t;
	start_t = clock();

	int *niz3 = malloc(10*n2 * sizeof(int));



	int j = 0;
	int *br;
	for (int i = 0; i < n2; i++) { //O(N)
		br = (int*)bsearch(&niz1[i], niz2, n2, sizeof(int), usporedi);// O(logN)
		if (br != NULL)
		{
			niz3[j] = *br;
			j++;
		}
	}
	/*int k=0;
	for(k=0;k<j;k++){
		printf("%d\n",niz3[k]);
	}
   */
	niz3 = (int*)realloc(niz3, j * sizeof(int));
	end_t = clock();
	double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Vrijeme za nesortiranog i sortiranog (bsearch)niz1[%d] i niz2[%d]:%f\n", n1, n2, total_t);
	return niz3;
}
int* presjek_sortiranqs(int *niz1, int n1, int *niz2, int n2) {//O(N^2+logN)
	niz1 = generiraj(n1);
	niz2 = generiraj(n2);
	shuffle(niz2, n2);
	clock_t start_t, end_t, total, t;
	start_t = clock();

	int *niz3 = malloc(3 * n1 * sizeof(int));


	qsort(niz2, n2, sizeof(int), usporedi);//O(logN)

	int k = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < n1; i++) {//O(N)
		for (j = 0; j < n2; j++) {//O(N)
			if (niz1[i] == niz2[j]) {
				niz3[k] = niz1[i];
				k++;
			}
		}
	}
	niz3 = (int*)realloc(niz3, k * sizeof(int));
	end_t = clock();
	double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Vrijeme za nesortiranog i sortiranog (quicksort)niz1[%d] i niz2[%d]:%f\n", n1, n2, total_t);
	return niz3;
}



void main() {
	srand(time(NULL));
	int n1;
	int n2;
	int *niz1=0;
	int *niz2=0;
	int *niz3;
	for (n2 = 10000; n2 <= 50000; n2 += 5000) {
		n1 = 30000;
		niz3 = presjek(niz1, n1, niz2, n2);
		niz3 = presjek_sortiran(niz1, n1, niz2, n2);
		niz3 = presjek_sortiranqs(niz1, n1, niz2, n2);
	}
	
	printf("\n");
	
	/*for (n1 = 10000; n1 <= 50000; n1 += 5000) {
		n2 = 30000;
		niz3 = presjek(niz1, n1, niz2, n2);
		niz3 = presjek_sortiran(niz1, n1, niz2, n2);
		niz3 = presjek_sortiranqs(niz1, n1, niz2, n2);
		
	}
	*/

	return 0;
}
