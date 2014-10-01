#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void dividir (int *vetor,int *aux,int ini1, int ini2,int fim2);
void mergeSort (int *vetor, int *aux,int esq, int dir);
void insertionSort(int *vetor, int n);

int main(){
    int n = 10000, *vetor, *inicio, *aux,i,j;
    clock_t ini,fim;
    FILE *arq;
    double t, s1=0, s2=0;
   	arq = fopen ("texto.txt", "w");

	if ((vetor = malloc (n * sizeof (int))) == NULL){
        printf("Não foi possível alocar na memória");
    }
	if ((aux = malloc (n * sizeof (int))) == NULL){
        printf("Não foi possível alocar na memória");
	}
	for (j=0;j<20;j++){
		inicio = vetor;
		for (i=0; i<n; i++){
			vetor[i] = rand() % n;
			vetor ++;
		}
		ini = clock();
		insertionSort (inicio, n);
		fim = clock();
		t = (fim - ini)/CLOCKS_PER_SEC;
		s1 = s1 + t;
		fprintf (arq, "tamanho: %d", n);
		fprintf (arq, "    insertion: %.2f", t);
		ini = clock();
		mergeSort (inicio, aux, 0, n-1);
		fim = clock();
		t = (fim-ini)/(double)CLOCKS_PER_SEC;
		s2 = s2 + t;

		fprintf (arq, "    merge: %.3f\n", t);
		n = n + 15000;
		vetor = realloc ( vetor, (n));
		aux = realloc ( aux, (n));
	}
    printf ("Media insertion: %.2f\n", s1/20);
    printf ("Media merge: %.2f\n", s2/20);
    fclose(arq);
    return 0;
}


void dividir (int *vetor,int *aux,int ini1, int ini2,int fim2){
    int in1=ini1,in2=ini2,fim1=in2-1,au=0,i;

    while(in1<=fim1 && in2<=fim2){

        if (vetor[in1]<vetor[in2])
            aux[au++] = vetor[in1++];
        else
            aux[au++] = vetor[in2++];
    }

    while(in1<=fim1)
        aux[au++] = vetor[in1++];

    while(in2<=fim2)
        aux[au++] = vetor[in2++];

    for(i=0; i<au; i++)
        vetor[i+ini1]=aux[i];
}
void mergeSort (int *vetor, int *aux,int esq, int dir){
        int meio;
        if(esq<dir){
            meio=(esq+dir)/2;
            mergeSort(vetor,aux,esq,meio);
            mergeSort(vetor,aux,meio+1,dir);
            dividir(vetor,aux,esq,meio+1,dir);
        }
}
void insertionSort(int *vetor, int n){
    int i, j, aux;
    for(i=1; i<n;  i++){
        j=i;
        while((vetor[j] < vetor[j-1]) && (j>0)){
            aux = vetor[j];
            vetor[j] = vetor[j-1];
            vetor[j-1] = aux;

            j--;
        }
    }

}



