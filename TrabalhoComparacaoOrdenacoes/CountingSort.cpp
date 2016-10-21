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
    long int maxValue = (new Helper)->getMax(A, n);
    return floor(this->getCount() / ((maxValue < n) ? n : maxValue));
}

/**
 * Counting Sort
 *
 * @param A (int*) Shuffled array
 * @param n (int)  Number of elements of said array
 */
void CountingSort::sortAlg(int * A, int n){
    incrementCount(n + 4); // getMax(A, n) && sup_range = ... && int * B = new int[n] && int * C = new int[sup_range + 1]
    int sup_range = (new Helper())->getMax(A, n);

    int * B = new int[n];
    int * C = new int[sup_range + 1];

    incrementCount(1 + (2 * (sup_range + 1))); // i = 0 && i <= sup_range && C[i] = 0
    for(int i = 0; i <= sup_range; i++){
        C[i] = 0;
    }

    incrementCount(1 + (3 * n)); // i = 0 && i < n && A[i] && C[A[i]] += 1
    for(int i = 0; i < n; i++){
        C[A[i]] += 1;
    }

    incrementCount(1 + (3 * sup_range)); // i = 1 && i <= sup_range && C[i - 1] && C[i] = C[i - 1]
    for(int i = 1; i <= sup_range; i++){
        C[i] += C[i - 1];
    }

    incrementCount(1 + (7 * n)); // i = 0 && i < n && 3*A[i] && C[A[i]] && B[C[A[i]] - 1] = A[i] && --C[A[i]]
    for(int i = 0; i < n; i++){
        B[C[A[i]] - 1] = A[i];
        --C[A[i]];
    }

    incrementCount(1 + (3 * n)); // i = 0 && i < n && B[i] && A[i] = B[i]
    for(int i = 0; i < n; i++){
        A[i] = B[i];
    }
}
