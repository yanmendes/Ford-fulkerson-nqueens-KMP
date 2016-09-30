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
    void heapify(int * A, int i, int n);
public:
    string getName();
};

#endif /* HeapSort_hpp */
