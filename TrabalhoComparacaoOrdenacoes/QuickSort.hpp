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
#include <chrono>

class QuickSort : public SortAlgorithm {
private:
    int pivot;
    mt19937 mt;

    void sortAlg(int * A, int n);
    void quickSort(int * A, int start, int end);

    typedef int (QuickSort::*pivotChoiceMethod)(int * A, int start, int end);
    pivotChoiceMethod current_pivot_choice_method;

    int partition(int * A, int start, int end);

    /*Métodos de escolha de pivô*/
    int biggestFirstTwo(int * A, int start, int end);
    int biggestFirstMiddle(int * A, int start, int end);
    int biggestRandom(int * A, int start, int end);

public:
    string getName();
    string getInferiorLimit(string instance_type);
    string getSuperiorLimit(string instance_type);
    int    getSmallestConstant(string instance_type, int * A, int n);

    QuickSort(int partitionMethod);
};

#endif /* QuickSort_hpp */
