#include<stdio.h>

main(){
    int i, j, aux, n=10000, vetor[n];
    for(i=0; i<n; i++){
        vetor[i] = rand() % 10000;
    }

    for(i=1; i<n;  i++){
        j=i;

        while((vetor[j] < vetor[j-1]) && (j>0)){
            aux = vetor[j];
            vetor[j] = vetor[j-1];
            vetor[j-1] = aux;

            j--;
        }
    }
    for(i=0; i<n; i++){
        printf("%d - ", vetor[i]);
    }
    return 0;
}
void invertionSort(int vetor[], int n){
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
    for(i=0; i<n; i++){
        printf("%d - ", vetor[i]);
    }

}

