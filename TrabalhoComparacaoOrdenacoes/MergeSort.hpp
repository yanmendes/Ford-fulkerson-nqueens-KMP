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
    string getInferiorLimit(string instance_type);
    string getSuperiorLimit(string instance_type);
    int    getSmallestConstant(string instance_type, int * A, int n);
    
    MergeSort(int allocationMethod);
};

#endif /* QuickSort_hpp */
