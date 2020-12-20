#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// void merge(int array[], int aux[], int start, int middle, int end){

//     int i, j , k;

//     i = start;
//     j = middle + 1;
//     k = start;

//     while (i < (middle + 1) && j < (end + 1)){
        
//     }
    

// }

// void mergeSort(int array[], int aux[], int start, int end){

//     if(start < end){
//         int middle = (start + end)/2;
//         mergeSort(array, aux, start, middle);
//         mergeSort(array, aux, middle, end);
        
//     }

// }

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

void insertionSort(int array[], int length);
void bubbleSort(int array[], int length);

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