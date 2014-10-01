#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void dividir (int *vetor,int *aux,int ini1, int ini2, int fim2);
void mergeSort (int *vetor, int *aux,int esq, int dir);
void insertionSort(int *vetor, int n);
void print_list(int * list, int len);

int main() {
    int n = 10000, *vetorInsertion, *vetorMerge, *aux, i , j, repeticoes = 20;
    clock_t ini, fim;
    FILE *arq;
    double tempo, tempoInsertion = 0, tempoMerge = 0;

    arq = fopen ("texto.txt", "w");

    if ((vetorInsertion = malloc(n * sizeof(int))) == NULL) {
        printf("Não foi possível alocar na memória");
    }

    if ((vetorMerge = malloc(n * sizeof(int))) == NULL) {
        printf("Não foi possível alocar na memória");
    }

    if ((aux = malloc(n * sizeof (int))) == NULL) {
        printf("Não foi possível alocar na memória");
    }

    for (j = 0; j < repeticoes; j++) {
        
        for (i=0; i < n; i++) {
            vetorInsertion[i] = rand() % n;
        }

        memcpy(vetorMerge, vetorInsertion, n * 4);

        ini = clock();
        insertionSort(vetorInsertion, n);
        fim = clock();
        // print_list(vetorInsertion, n);

        tempo = ((fim - ini) / CLOCKS_PER_SEC);
        tempoInsertion = tempoInsertion + tempo;

        fprintf (arq, "tamanho: %d", n);
        fprintf (arq, "    insertion: %f", tempo);
        
        ini = clock();
        mergeSort(vetorMerge, aux, 0, n - 1);
        fim = clock();
        // print_list(vetorMerge, n);
        
        tempo = (fim - ini)/(double)CLOCKS_PER_SEC;
        tempoMerge = tempoMerge + tempo;
        
        fprintf (arq, "    merge: %.3f\n", tempo);
        
        n = n + 15000;
        vetorInsertion = realloc(vetorInsertion, n);
        vetorMerge = realloc(vetorMerge, n);
        aux = realloc(aux, n);
    }

    printf ("Media insertion: %f\n", tempoInsertion/repeticoes);
    printf ("Media merge: %f\n", tempoMerge/repeticoes);
    fclose(arq);
    free(vetorInsertion);
    free(vetorMerge);
    free(aux);
    return 0;
}

void dividir (int *vetor,int *aux,int ini1, int ini2, int fim2) {
    int in1 = ini1, in2 = ini2, fim1 = in2 - 1, au = 0, i;

    while(in1 <= fim1 && in2 <= fim2) {
        if (vetor[in1] < vetor[in2]) {
            aux[au++] = vetor[in1++];
        } else {
            aux[au++] = vetor[in2++];
        }
    }

    while(in1 <= fim1) {
        aux[au++] = vetor[in1++];
    }

    while(in2 <= fim2) {
        aux[au++] = vetor[in2++];
    }

    for(i = 0; i < au; i++) {
        vetor[i+ini1] = aux[i];
    }
}

void print_list(int * list, int len)
{
    /* Print all the ints of a list in brackets followed by a newline */
    int i;
 
    printf("[");
    for (i = 0; i < len; i++)
    {
        printf("%d, ", list[i]);
    }
    printf("]\n");
}

void mergeSort (int *vetor, int *aux, int esq, int dir) {
    int meio;
    if(esq < dir) {
        meio = (esq + dir) / 2;
        mergeSort(vetor, aux, esq, meio);
        mergeSort(vetor, aux, meio + 1, dir);
        dividir(vetor, aux, esq, meio + 1, dir);
    }
}

void insertionSort(int *vetor, int n) {
    int i, j, aux;
    for(i = 1; i < n; i++) {
        j=i;

        while((vetor[j] < vetor[j-1]) && (j > 0)) {
            aux = vetor[j];
            vetor[j] = vetor[j-1];
            vetor[j-1] = aux;
            j--;
        }
    }

}
