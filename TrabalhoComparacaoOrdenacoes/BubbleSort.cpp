//
//  BubbleSort.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "BubbleSort.hpp"

string BubbleSort::getName(){
    return "Bubble Sort";
};

string BubbleSort::getInferiorLimit(string instance_type){
    return !strcmp(instance_type.c_str(), "ascending") ? "O(n)" : "O(n^2)";
}

string BubbleSort::getSuperiorLimit(string instance_type){
    return "O(n^2)";
}

int BubbleSort::getSmallestConstant(string instance_type, int * A, int n){
    return floor(this->getCount() / (!strcmp(instance_type.c_str(), "ascending") ? n : (n * n)));
}

/**
 * Bubble Sort
 *
 * @param A (int*) Shuffled array
 * @param n (int)  Number of elements of said array
 */
void BubbleSort::sortAlg(int * A, int n){
    int ncp = n;
    bool swapped;
    incrementCount(1); // int ncp = n
    do {
        swapped = false;
        for(int i = 1; i < ncp-1; ++i) {
            if(A[i-1] > A[i])
            {
                swap(A[i-1], A[i]);
                swapped = true;
                incrementCount(6); // A[i-1] && A[i] && swap(A[i], A[j]) && swapped = true
            }
            incrementCount(4); // A[i-1] && A[i] && A[i-1] > A[j] && i < n-1
        }
        --ncp;
        incrementCount(4); // swapped = false && i = 1 && i < n-1 while (swap) && --ncp
    } while (swapped);
}
