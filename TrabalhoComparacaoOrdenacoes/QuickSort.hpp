//
//  QuickSort.hpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include "SortAlgorithm.hpp"

class QuickSort : public SortAlgorithm {
private:
    void sortAlg(int * A, int n);
    void quickSort(int * A, int start, int end);
    
    typedef int (QuickSort::*partitionMethod)(int * A, int start, int end);
    partitionMethod current_partition_method;
    
    int random(int * A, int start, int end);
    int firstLast(int * A, int start, int end);
    int firstMiddle(int * A, int start, int end);
    
public:
    string getName();
    QuickSort(int partitionMethod);
};

#endif /* QuickSort_hpp */
