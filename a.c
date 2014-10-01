#include<stdio.h>
#include<stdlib.h>

typedef struct avl{
	int info // nó
	int altura 
	struct avl *esq;
	struct avl *dir;
}ArAvl;

ArvAvl * cria(int info){      //criação da arvore
	ArvAvl *arv
	arv = (ArvAvl*)malloc(sizeof(ArvAvl));
	arv->info = info;
	arv->altura = 0;
	arv->esq = arv->dir = NULL;
	return arv;
}
