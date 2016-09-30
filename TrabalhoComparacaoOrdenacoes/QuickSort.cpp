//
//  QuickSort.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "QuickSort.hpp"

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

string QuickSort::getName(){
    return "Quick Sort";
};

void QuickSort::sortAlg(int * A, int n){
    
    QuickSort::quickSort(A, 0, n - 1);
    
}

void QuickSort::quickSort(int * A, int start, int end){
    
    int index = (this->*current_partition_method)(A, start, end);
    
    if (end < index - 1)
        quickSort(A, start, index - 1);
    if (index < end)
        quickSort(A, start, end);
    
}
