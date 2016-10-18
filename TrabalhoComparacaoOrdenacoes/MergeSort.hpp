//
//  MergeSort.hpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include "SortAlgorithm.hpp"

class MergeSort : public SortAlgorithm {
private:
    int allocationMethod;
    
    void merge(int * A, int start, int end, int mid);
    void adaptedMerge(int * A, int start, int end, int mid, int * Aux);
    
    void sortAlg(int * A, int n);
    void mergeSort(int * A, int start, int end);
    void adaptedMergeSort(int * A, int start, int end, int * Aux);
public:
    string getName();
    MergeSort(int allocationMethod);
};

#endif /* QuickSort_hpp */
