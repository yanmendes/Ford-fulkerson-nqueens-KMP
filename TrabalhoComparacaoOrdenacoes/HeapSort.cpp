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

/**
 * Método que transforma um array em uma heap
 *
 * @param A (int*) Array a ser ordenado
 * @param i (int)  Posição relativa do array que começará a operação
 * @param n (int)  Número de elementos do arranjo
 */
void HeapSort::heapify(int * A, int i, int n){
    
    int max = i;
    int filhoEsquerdo = 2 * i + 1;
    int filhoDireito = filhoEsquerdo + 1;
    
    incrementCount(1);
    if (filhoEsquerdo < n && A[filhoEsquerdo] > A[max])
        max = filhoEsquerdo;
    
    incrementCount(1);
    if (filhoDireito < n && A[filhoDireito] > A[max]){
        max = filhoDireito;
    }
    
    if (max != i){
        swap(A[i], A[max]);
        heapify(A, n, max);
    }
}

/**
 * Heap Sort
 *
 * @param A (int*) Array a ser ordenado
 * @param n (int)  Número de elementos do arranjo
 */
void HeapSort::sortAlg(int * A, int n){
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);
    
    for (int i=n-1; i>=0; i--) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
    
}
