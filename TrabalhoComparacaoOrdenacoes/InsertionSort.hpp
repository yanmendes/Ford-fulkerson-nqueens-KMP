//
//  InsertionSort.hpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#ifndef InsertionSort_hpp
#define InsertionSort_hpp

#include "SortAlgorithm.hpp"

class InsertionSort : public SortAlgorithm{
private:
    void sortAlg(int * A, int n);
public:
    string getName();
};

#endif /* InsertionSort_hpp */
