#include <stdio.h>
#include <stdlib.h>


struct mail {
    int zipcode;
    char city[40+1];
};

typedef struct mail zapis;


void swap(zapis *a, zapis *b) {
    zapis temp;

    temp = *a;
    *a = *b;
    *b = temp;
}


void insertionSort(zapis *A, int n, char direction) {
    int i, hole;
    zapis temp;

    /* ascending */
    if (direction == '0') {

        for(i = 1; i < n; i++) {
            hole = i;
            temp = A[hole];

            while (hole > 0 && A[hole-1].zipcode > temp.zipcode) {
                A[hole] = A[hole-1];
                hole--;
            }

            A[hole] = temp;
        }

    }
    /* descending */
    else {

        for(i = 1; i < n; i++) {
            hole = i;
            temp = A[hole];

            while (hole > 0 && A[hole-1].zipcode < temp.zipcode) {
                A[hole] = A[hole-1];
                hole--;
            }

            A[hole] = temp;
        }

    }

}


void selection2Sort(zapis *A, int n, char direction) {
    int i, j, min;

    /* ascending */
    if (direction == '0') {

        for(i = 0; i < n - 1; i++) {
            min = i;

            for(j = i + 1; j < n; j++) {
                if (A[j].zipcode < A[min].zipcode) {
                    min = j;
                }
            }
            swap(&A[i], &A[min]);
        }

    }
    /* descending */
    else {

        for(i = 0; i < n - 1; i++) {
            min = i;

            for(j = i + 1; j < n; j++) {
                if (A[j].zipcode > A[min].zipcode) {
                    min = j;
                }
            }
            swap(&A[i], &A[min]);
        }

    }


}


void bubbleSort(zapis *A, int n, char direction) {
    int i, j;

    /* ascending */
    if (direction == '0') {

        for(i = 0; i < n; i++) {
            for(j = 0; j < n - i - 1; j++) {
                if (A[j].zipcode > A[j+1].zipcode) {
                    swap(&A[j], &A[j+1]);
                }
            }
        }

    }
    /* descending */
    else {

        for(i = 0; i < n; i++) {
            for(j = 0; j < n - i - 1; j++) {
                if (A[j].zipcode < A[j+1].zipcode) {
                    swap(&A[j], &A[j+1]);
                }
            }
        }

    }
}


