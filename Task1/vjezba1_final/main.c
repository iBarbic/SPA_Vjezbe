#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* podniz(int *niz, int start, int stop) {
	int *niz0;
	niz0 = (int*)malloc((stop - start - 1) * sizeof(int));
	int i = 0;
	for (i = 0; i < (stop - start + 1); i++) {
		niz0[i] = niz[start + i];
	}
	return niz0;
}
int* filtriraj(int *niz, int n, int th, int *nth) {
	int i = 0;
	int brojac = 0;
	int j = 0;
	for (i = 0; i < n; i++) {
		if (niz[i] < th) {
			brojac = brojac + 1;
		}
	}
	nth = (int*)malloc(brojac * sizeof(int));
	for (i = 0; i < 10; i++) {
		if (niz[i] < th)
			nth[j] = niz[i];
		j = j + 1;
	}
	return nth;
}
int** podijeli(int *niz, int n) {
	int j = 0;
	int i = 0;
	int *niz1;
	int *niz2;
	int **niz3;
	niz1 = (int*)malloc((n / 2) * sizeof(int));
	niz2 = (int*)malloc((n - n / 2) * sizeof(int));
	niz3 = (int**)malloc(2 * sizeof(int));
	for (i = 0; i < n; i++) {
		if (i < n / 2) {
			niz1[i] = niz[i];
		}
		else {
			niz2[j] = niz[i];
			j++;
		}
	}
	niz3[0] = niz1;
	niz3[1] = niz2;
	return niz3;
}
typedef struct {
	float x;
	float y;

} Tocka;

typedef struct {
	int br_vrhova;
	Tocka vrh[20];
} Poligon;

Poligon* novi_poligon(float *niz_x, float *niz_y, int n) {
	int i;
	if (n < 3)
		return NULL;
	Poligon *poligon1 = malloc(sizeof(Poligon));
	(*poligon1).br_vrhova = n;

	for (i = 0; i < n; i++) {
		(*poligon1).vrh[i].x = niz_x[i];
		(*poligon1).vrh[i].y = niz_y[i];


	}

	return poligon1;
}
Tocka** pozitivni(Poligon *p) {
	int i, j = 0, br = (*p).br_vrhova;
	printf(" broj vrhova u poligonu: %d\n", br);
	Tocka **niz_pozitivnih = (Tocka**)malloc(br*(sizeof(Tocka)));
	for (i = 0; i < br; i++) {
		if ((*p).vrh[i].x > 0 && (*p).vrh[i].y > 0) {
			niz_pozitivnih[j] = &(*p).vrh[i];
			j++;
		}

	}
	return niz_pozitivnih;

}



int main() {

	int niz[] = { 1,2,3,4,5,6,7,8,9 };
	int *niz1;
	int *nth = 0;
	int **niz2=0;
	int i;
	int n = 10;
	/*niz2 = podijeli(niz, 9);
	for (i = 0; i < (n-n/2); i++) {
		printf("%d,", niz2[0][i]);
		printf("%d,", niz2[1][i]);
	}
	*/
	//niz1 = podniz(niz, 1, 3);
	//printf("%d,%d,%d", niz1[0], niz1[1], niz1[2]);
	//nth = filtriraj(niz, 10, 5, nth);
	//printf("%d,%d,%d,%d,", nth[0], nth[1], nth[2], nth[3]);
	float x[] = { 2, -10, 5, 40 };
	float y[] = { 50, 20, -25,4 };
	int len = (sizeof(x) / sizeof(float));
	Poligon *p1 = novi_poligon(x, y, len);
	printf("%f %f\n", (*p1).vrh[0].x, (*p1).vrh[0].y);
	Tocka **poz = pozitivni(p1);
	printf("%f %f\n", poz[1]->x, poz[1]->y);
}
