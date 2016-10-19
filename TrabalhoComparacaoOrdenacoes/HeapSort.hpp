//
//  HeapSort.hpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#ifndef HeapSort_hpp
#define HeapSort_hpp

#include "SortAlgorithm.hpp"

class HeapSort : public SortAlgorithm {
private:
    void sortAlg(int * A, int n);
    void heapify(int * A, int n, int i);
public:
    string getName();
    string getInferiorLimit(string instance_type);
    string getSuperiorLimit(string instance_type);
    int    getSmallestConstant(string instance_type, int * A, int n);
};

#endif /* HeapSort_hpp */
