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
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            incrementCount(1);
            if(A[i] > A[j])
                swap(A[i], A[j]);
        }
    }
}
