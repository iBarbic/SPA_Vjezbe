#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo
	/*BSTree novo_stablo = malloc(sizeof(Node));
	novo_stablo->word = NULL;
	novo_stablo->left = NULL;
	novo_stablo->right = NULL;
	*///return &novo_stablo;
	return NULL;
}

void AddNode(BSTree *bst, char *word)
{
	// Rekurzivno se tra�i mjesto za novi �vor u stablu. Ako rije� postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokaziva�.


	if (*bst == NULL) {
		BSTree new_node = (BSTree)malloc(sizeof(Node));
		new_node->word = word;
		new_node->left = NULL;
		new_node->right = NULL;
		*bst = new_node;
        return;

	}
	if (strcmp((*bst)->word, word) == 0) {
		return;
	}
	if (strcmp((*bst)->word, word) < 0) {
		AddNode(&((*bst)->right), word);
	}
	else if (strcmp((*bst)->word, word) > 0) {
		AddNode(&((*bst)->left), word);
	}

}

int BSTHeight(BSTree bst)//triba ic iz korijena livo i desno i onda kod svakog od cvorova ic livo i desnno da skuzimo koji ide najvise u dubinu
{
	// Rekurzivno se prolazi cijelo stablo da bi se prona�la najdu�a grana (visina stabla).
	if (bst == NULL) {
		return 0;
	}

	int lijevo = BSTHeight(bst->left);
	int desno = BSTHeight(bst->right);

	if (lijevo > desno) {
		return (lijevo + 1);
	}
	else {
		return (desno + 1);
	}
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rije�i u stablu na ekran po abecednom redu.
	// In-order �etnja po stablu (lijevo dijete, �vor, desno dijete)
	if (bst == NULL) {
		return;
	}
	PrintBSTree(bst->left);
	printf("%s\n", bst->word);
	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE *fd)
{
	// Snima rije� po rije� iz stabla u tekstualnu datoteku. Rije�i su odvojene razmakom.
	// Pre-order �etnja po stablu (ttenutni �vor pa djeca)

	if (bst == NULL) {
		return;
	}
	fprintf(fd, " %s", bst->word);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);

}

void DeleteBSTree(BSTree bst)
{
	// Bri�e stablo (string word i sam �vor) iz memorije.
	// Post-order �etnja po stablu (prvo djeca pa trenutni �vor)
    if (bst == NULL)
        return;




	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	printf("\n Deleting node: %s", bst->word);
	free(bst->word);
	free(bst);



}


BSTree LoadBSTree(FILE *fd)
{
	// Ucitava rijec po rijec iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rijec duplicirati sa strdup().

	BSTree bst;
	bst = NewBSTree();
	char buffer[1024];


	while (readWord(fd, buffer)) {
		AddNode(&bst, strdup(buffer));
	}

	return bst;
}



