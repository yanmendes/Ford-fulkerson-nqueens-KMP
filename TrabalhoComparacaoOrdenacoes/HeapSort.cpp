//
//  HeapSort.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "HeapSort.hpp"

string HeapSort::getName(){
    return "Heap Sort";
};

string HeapSort::getInferiorLimit(string instance_type){
    return "O(n log n)";
}

string HeapSort::getSuperiorLimit(string instance_type){
    return "O(n log n)";
}

int HeapSort::getSmallestConstant(string instance_type, int * A, int n){
    return floor(this->getCount() / (n * log2(n)));
}

/**
 * Method that heapifies an array
 *
 * @param A (int*) Shuffled array
 * @param n (int)  Number of elements of said array
 * @param i (int)  Position of array that shall be heapified
 */
void HeapSort::heapify(int * A, int n, int i){

    int max = i;
    int filhoEsquerdo = 2 * i + 1;
    int filhoDireito = filhoEsquerdo + 1;

    if (filhoEsquerdo < n && A[filhoEsquerdo] > A[max])
        max = filhoEsquerdo;

    if (filhoDireito < n && A[filhoDireito] > A[max]){
        max = filhoDireito;
    }

    incrementCount(1);
    if (max != i){
        swap(A[i], A[max]);
        heapify(A, n, max);
    }
}

/**
 * Heap Sort
 *
 * @param A (int*) Shuffled array
 * @param n (int)  Number of elements of said array
 */
void HeapSort::sortAlg(int * A, int n){

    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(A, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }

}
