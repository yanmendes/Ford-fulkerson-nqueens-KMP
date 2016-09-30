//
//  QuickSort.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "QuickSort.hpp"

string QuickSort::getName(){
    return "Quick Sort";
};

/**
 * Construtor da classe que leva em consideração qual o método
 * de particionamento será utilizado
 *
 * @param partitionMethod (int) Índice da função
 */
QuickSort::QuickSort(int partitionMethod){
    switch (partitionMethod) {
        case 1:
            this->current_partition_method = &QuickSort::random;
            break;
        case 2:
            this->current_partition_method = &QuickSort::firstLast;
            break;
        default:
            this->current_partition_method = &QuickSort::firstMiddle;
            break;
    }
}

/**
 * Quick Sort
 *
 * @param A (int*) Array a ser ordenado
 * @param n (int)  Número de elementos do arranjo
 */
void QuickSort::sortAlg(int * A, int n){
    this->quickSort(A, 0, n - 1);
}

/**
 * Método recursivo auxiliar à construção do quicksort
 *
 * @param A     (int*) Array a ser ordenado
 * @param start (int)  Posição à esquerda do arranjo
 * @param end   (int)  Posição à direita do arranjo
 */
void QuickSort::quickSort(int * A, int start, int end){
    
    int index = (this->*current_partition_method)(A, start, end);
    
    if (end < index - 1)
        quickSort(A, start, index - 1);
    if (index < end)
        quickSort(A, start, end);
    
}
