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
    incrementCount(3);
    int max = i;
    int filhoEsquerdo = 2 * i + 1;
    int filhoDireito = filhoEsquerdo + 1;

    incrementCount(4); // filhoEsquerdo < n && A[filhoEsquerdo] && A[max] && A[filhoEsquerdo] > A[max]
    if (filhoEsquerdo < n && A[filhoEsquerdo] > A[max]) {
        incrementCount(1);
        max = filhoEsquerdo;
    }

    incrementCount(4); // filhoDireito < n && A[filhoDireito] && A[max] && A[filhoDireito] > A[max]
    if (filhoDireito < n && A[filhoDireito] > A[max]) {
        incrementCount(1);
        max = filhoDireito;
    }

    incrementCount(1);
    if (max != i) {
        incrementCount(6); // A[i] && A[max] && swap(A[i], A[max]) && heapify(A, n, max)
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
    incrementCount(1 + n); // i = n / 2 - 1 && i >= 0 && heapify(A, i, 0)
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(A, n, i);
    }

    incrementCount(1 + (7 * n)); // i = n - 1 && i >= 0 && A[i] && A[j] && swap(A[i], A[j]) && heapify(A, i, 0)
    for (int i = n - 1; i >= 0; i--) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }

}
