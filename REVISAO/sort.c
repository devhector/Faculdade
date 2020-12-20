#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void insertionSort(int array[], int length);
void bubbleSort(int array[], int length);
void selectionSort(int array[], int length);
void merge(int array[], int start, int middle, int end);
void mergeSort(int array[], int start, int end);


int main(){

    int array[20];
    int i, tam = 20;

    srand(time(0));

    for(i = 0; i < tam; i++){

        array[i] = rand() % 100;

    }
    printf("\n");

    for(i = 0; i < tam; i++){

        printf(" %d ", array[i]);

    }
    printf("\n");

    printf("\nSelection:\n");
    selectionSort(array, tam);

    for(i = 0; i < tam; i++){

        printf(" %d ", array[i]);

    }
    printf("\n");

    for(i = 0; i < tam; i++){

        array[i] = rand() % 100;

    }
    printf("\n");
    printf("\n");


    for(i = 0; i < tam; i++){

        printf(" %d ", array[i]);

    }
    printf("\n");

    printf("\nBubble:\n");
    bubbleSort(array, tam);

    for(i = 0; i < tam; i++){

        printf(" %d ", array[i]);

    }
    printf("\n");

 for(i = 0; i < tam; i++){

        array[i] = rand() % 100;

    }
    printf("\n");
    printf("\n");


    for(i = 0; i < tam; i++){

        printf(" %d ", array[i]);

    }
    printf("\n");

    printf("\nInsertion:\n");
    insertionSort(array, tam);

    for(i = 0; i < tam; i++){

        printf(" %d ", array[i]);

    }
    printf("\n");

 for(i = 0; i < tam; i++){

        array[i] = rand() % 100;

    }
    printf("\n");
    printf("\n");


    for(i = 0; i < tam; i++){

        printf(" %d ", array[i]);

    }
    printf("\n");

    printf("\nMerge:\n");
    mergeSort(array, 0, tam);

    for(i = 0; i < tam; i++){

        printf(" %d ", array[i]);

    }
    printf("\n");


    return 0;
}

void bubbleSort(int array[], int length){

    int i, j, aux;

    for(i = 0; i < length - 1; i++){

        for(j = i + 1; j < length; j++){

            if(array[i] > array[j]){

                aux = array[i];
                array[i] = array[j];
                array[j] = aux;

            }

        }

    }
}

void insertionSort(int array[], int length){

    int value, i, j;

    for(i = 1; i < length; i++){

        value = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > value){

            array[j + 1] = array[j];
            j -= 1;

        }

        array[j + 1] = value;


    }


}

void selectionSort(int array[], int length){

    int min, aux, i, j;

    for ( i = 0; i < length - 1; i++){
        
        min = i;

        for ( j = i + 1; j < length; j++){
            
            if(array[j] < array[min]){

                min = j;

            }

        }

        if(i != min){

            aux = array[i];
            array[i] = array[min];
            array[min] = aux;

        }
        
    }
    
}

void merge(int array[], int start, int middle, int end){

    int aStart = start,
        bStart = middle + 1,
        auxStart = 0;

    int *arrayAux = (int *)malloc(sizeof(int) * ((end - start) + 1));

    while (aStart <= middle && bStart <= end){

        if(array[aStart] < array[bStart]){

            arrayAux[auxStart] = array[aStart];
            aStart++;

        }else{

            arrayAux[auxStart] = array[bStart];
            bStart++;

        }

        auxStart++;
        
    }

    while (aStart <= middle){

        arrayAux[auxStart] = array[aStart];
        aStart++;
        auxStart++;
        
    }

    while (bStart <= end){
        
        arrayAux[auxStart] = array[bStart];
        bStart++;
        auxStart++;

    }

    for(auxStart = start; auxStart <= end; auxStart++){

        array[auxStart] = arrayAux[auxStart - start];

    }
    
    free(arrayAux);

}

void mergeSort(int array[], int start, int end){

    if(start < end){

        int middle = (end + start) / 2;

        mergeSort(array, start, middle);
        mergeSort(array, middle + 1, end);
        merge(array, start, middle, end);

    }

}