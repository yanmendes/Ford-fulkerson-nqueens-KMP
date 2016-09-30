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

/**
 * Selection Sort
 *
 * @param A (int*) Array a ser ordenado
 * @param n (int)  Número de elementos do arranjo
 */
void SelectionSort::sortAlg(int * A, int n){
    int min;
    
    for (int i=0; i < n-1; i++){
        min = i;
        
        for (int j=i+1; j < n; j++){
            if (A[j] < A[min])
                min = j;
        }
        
        if (min != i)
            swap(A[i], A[min]);
    }
}
