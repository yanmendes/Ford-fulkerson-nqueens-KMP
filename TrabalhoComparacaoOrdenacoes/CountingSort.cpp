//
//  CountingSort.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "CountingSort.hpp"

string CountingSort::getName(){
    return "Counting Sort";
}

string CountingSort::getInferiorLimit(string instance_type){
    return "O(n + k)";
}

string CountingSort::getSuperiorLimit(string instance_type){
    return "O(n + k)";
}

int CountingSort::getSmallestConstant(string instance_type, int * A, int n){
    return floor(this->getCount() / (n + (int) log10((new Helper)->getMax(A, n)) + 1));
}

/**
 * Counting Sort
 *
 * @param A (int*) Shuffled array
 * @param n (int)  Number of elements of said array
 */
void CountingSort::sortAlg(int * A, int n){
    int sup_range = (new Helper())->getMax(A, n);

    int * B = new int[n];
    int * C = new int[sup_range + 1];

    for(int i = 0; i <= sup_range; i++){
        C[i] = 0;
    }

    for(int i = 0; i < n; i++){
        C[A[i]] += 1;
    }

    for(int i = 1; i <= sup_range; i++){
        C[i] += C[i - 1];
    }

    for(int i = 0; i < n; i++){
        incrementCount(1);
        B[C[A[i]] - 1] = A[i];
        --C[A[i]];
    }

    for(int i = 0; i < n; i++){
        A[i] = B[i];
    }
}
