//
//  InsertionSort.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "InsertionSort.hpp"

string InsertionSort::getName(){
    return "Insertion Sort";
};

string InsertionSort::getInferiorLimit(string instance_type){
    return !strcmp(instance_type.c_str(), "ascending") ? "O(n)" : "O(n^2)";
}

string InsertionSort::getSuperiorLimit(string instance_type){
    return "O(n^2)";
}

int InsertionSort::getSmallestConstant(string instance_type, int * A, int n){
    return floor(this->getCount() / (!strcmp(instance_type.c_str(), "ascending") ? n : (n * n)));
}

/**
 * Insertion Sort
 *
 * @param A (int*) Shuffled array
 * @param n (int)  Number of elements of said array
 */
void InsertionSort::sortAlg(int * A, int n){
    int i, j, key;

    incrementCount(8*n - 7);
    // i = 1 && i < n
    // *
    // A[i] && key = A[i] && j = i - 1 && FIRST j >= 0 && FIRST A[j] && FIRST key < A[j] && A[j + 1] = key
    for (i = 1; i < n; i++){
        key = A[i];
        j = i - 1;

        while (j >= 0 && key < A[j]){
            A[j + 1] = A[j];
            --j;
            incrementCount(6); // A[j] && A[j + 1] = A[j] && --J && j >= 0 && A[j] && key < A[j]
        }

        A[j + 1] = key;
    }

}
