#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 4. zadatak samo free sve
typedef struct {
	float t1;
	float t2;
	float t3;
}Tocka;

typedef struct {
	float normala1;
	float normala2;
	float normala3;
	Tocka vrhovi_trokuta[3];
	unsigned short boja;
}Trokut;

typedef struct {
	Trokut niz_trokuta[1404]; //[broj trokuta], dovoljno da spremi sve trokute u datoteci
	unsigned short br_trokuta;

}Objekt3D;

Objekt3D * citaj_STL(FILE *fp) {
	fseek(fp, 80, SEEK_SET);
	Objekt3D *obj = (Objekt3D*)malloc(sizeof(Objekt3D));
	Trokut * trokut = (Trokut*)malloc(sizeof(Trokut));

	fread(&(obj->br_trokuta), 4, 1, fp);
	int i = 0;
	

	while (fread(trokut, 50, 1, fp)) {
		obj->niz_trokuta[i] = *trokut;
		i++;
	}
	fclose(fp);
	return obj;
	free(obj);
	free(trokut);
}


void zapisi_stl(FILE *fp, Objekt3D *obj2) {
	int pocetak = 0;
	int i = 0;
	fwrite(&pocetak, 4, 20, fp);
	fwrite(&obj2->br_trokuta, 4, 1, fp);
	printf("Upisan pocetak!\n");
	for (i = 0; i < obj2->br_trokuta; i++) {
		fwrite(&obj2->niz_trokuta[i].normala1, sizeof(float), 1, fp);
		fwrite(&obj2->niz_trokuta[i].normala2, sizeof(float), 1, fp);
		fwrite(&obj2->niz_trokuta[i].normala3, sizeof(float), 1, fp);
		fwrite(&obj2->niz_trokuta[i].vrhovi_trokuta[0].t1, sizeof(float), 1, fp);
		fwrite(&obj2->niz_trokuta[i].vrhovi_trokuta[0].t2, sizeof(float), 1, fp);
		fwrite(&obj2->niz_trokuta[i].vrhovi_trokuta[0].t3, sizeof(float), 1, fp);
		fwrite(&obj2->niz_trokuta[i].vrhovi_trokuta[1].t1, sizeof(float), 1, fp);
		fwrite(&obj2->niz_trokuta[i].vrhovi_trokuta[1].t2, sizeof(float), 1, fp);
		fwrite(&obj2->niz_trokuta[i].vrhovi_trokuta[1].t3, sizeof(float), 1, fp);
		fwrite(&obj2->niz_trokuta[i].vrhovi_trokuta[2].t1, sizeof(float), 1, fp);
		fwrite(&obj2->niz_trokuta[i].vrhovi_trokuta[2].t2, sizeof(float), 1, fp);
		fwrite(&obj2->niz_trokuta[i].vrhovi_trokuta[2].t3, sizeof(float), 1, fp);
		fwrite(&i, sizeof(unsigned short), 1, fp);
	}
	fclose(fp);

}

void zapisi_txt(FILE *fp, Objekt3D *obj3) {
	int i = 0;
	fprintf(fp, "solid 3Dobjekt\n");
	for (i = 0; i < obj3->br_trokuta; i++) {
		fprintf(fp, "   facet normal %f %f %f \n", obj3->niz_trokuta[i].normala1, obj3->niz_trokuta[i].normala2, obj3->niz_trokuta[i].normala3);
		fprintf(fp, "     outer loop\n");
		fprintf(fp, "       vertex %f %f %f \n", obj3->niz_trokuta[i].vrhovi_trokuta[0].t1, obj3->niz_trokuta[i].vrhovi_trokuta[0].t2, obj3->niz_trokuta[i].vrhovi_trokuta[0].t3);
		fprintf(fp, "       vertex %f %f %f \n", obj3->niz_trokuta[i].vrhovi_trokuta[1].t1, obj3->niz_trokuta[i].vrhovi_trokuta[1].t2, obj3->niz_trokuta[i].vrhovi_trokuta[1].t3);
		fprintf(fp, "       vertex %f %f %f \n", obj3->niz_trokuta[i].vrhovi_trokuta[2].t1, obj3->niz_trokuta[i].vrhovi_trokuta[2].t2, obj3->niz_trokuta[i].vrhovi_trokuta[2].t3);
		fprintf(fp, "     endloop\n");
		fprintf(fp, "   endfacet\n");
	}
	fclose(fp);
}


int main() {
	//printf("Velicina trokuta: %d\n", sizeof(Trokut));
	FILE *fp_binarna = fopen("primjerbin.stl", "rb");
	Objekt3D *obj = citaj_STL(fp_binarna);
	FILE *fp_nova_binarna = fopen("stlDatoteka.stl", "wb");

	printf("Broj trokuta: %d\n", obj->br_trokuta);

	//printf("Velicina niza: %d\n", sizeof(obj->niz_trokuta));
	zapisi_stl(fp_nova_binarna, &obj->niz_trokuta);

	FILE *fp_nova_text = fopen("tekstualnaSTL.stl", "wt");

	zapisi_txt(fp_nova_text, &obj->niz_trokuta);
	return 0;

}