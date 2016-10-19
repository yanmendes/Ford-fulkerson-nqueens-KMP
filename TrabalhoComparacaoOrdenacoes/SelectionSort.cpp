//
//  SelectionSort.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "SelectionSort.hpp"

string SelectionSort::getName(){
    return "Selection Sort";
};

string SelectionSort::getInferiorLimit(string instance_type){
    return "O(n^2)";
}

string SelectionSort::getSuperiorLimit(string instance_type){
    return "O(n^2)";
}

int SelectionSort::getSmallestConstant(string instance_type, int * A, int n){
    return floor(this->getCount() / (n * n));
}

/**
 * Selection Sort
 *
 * @param A (int*) Shuffled array
 * @param n (int)  Number of elements of said array
 */
void SelectionSort::sortAlg(int * A, int n){
    int min;

    for (int i=0; i < n-1; i++){
        min = i;

        for (int j=i+1; j < n; j++){
            incrementCount(1);
            if (A[j] < A[min])
                min = j;
        }

        if (min != i)
            swap(A[i], A[min]);
    }
}
