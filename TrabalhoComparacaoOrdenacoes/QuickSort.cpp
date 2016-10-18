//
//  QuickSort.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "QuickSort.hpp"

string QuickSort::getName(){
    stringstream name;
    name << "Quick Sort - " << this->pivot;
    
    return name.str();
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
            this->pivot = 1;
            this->current_pivot_choice_method = &QuickSort::biggestFirstTwo;
            break;
        case 2:
            this->pivot = 2;
            this->current_pivot_choice_method = &QuickSort::biggestFirstMiddle;
            break;
        default:
            this->pivot = 3;
            this->current_pivot_choice_method = &QuickSort::biggestRandom;
            break;
    }
}

int QuickSort::biggestFirstTwo(int *A, int start, int end){
    incrementCount(1);
    if(A[start] > A[end])
        return start;
    
    return end;
}

int QuickSort::biggestFirstMiddle(int *A, int start, int end){
    int middle = floor((start + end) / 2);
    
    incrementCount(1);
    if(A[start] > A[middle])
        return start;
    
    return middle;
}


int QuickSort::biggestRandom(int *A, int start, int end){
    int firstRandom = (start + rand()) % end;
    int secondRandom = (start + rand()) % end;
    
    incrementCount(1);
    if(A[firstRandom] > A[secondRandom])
        return firstRandom;
    
    return secondRandom;
}

/**
 * Particionamento
 *
 * @param A    (int*) Array a ser ordenado
 * @param start (int) primeira posição deste array
 * @param end   (int) última posição deste array
 *
 */
int QuickSort::partition(int * A, int start, int end){
    int i = start, j = end;
    int pivot = (this->*current_pivot_choice_method)(A, start, end);
    
    while (i <= j) {
        while (A[i] < pivot)
            i++;
        while (A[j] > pivot)
            j--;
        if (i <= j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    };
    
    return i;
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
 * @param A    (int*) Array a ser ordenado
 * @param start (int)  Posição à esquerda do arranjo
 * @param end   (int)  Posição à direita do arranjo
 */
void QuickSort::quickSort(int * A, int start, int end){
    if(start < end){
        int index = partition(A, start, end);
    
        incrementCount(1);
        
        if (start < index - 1)
            quickSort(A, start, index - 1);
        if (index < end)
            quickSort(A, index, end);
    }
}
