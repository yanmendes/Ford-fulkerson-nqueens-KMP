//
//  SelectionSort.hpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#ifndef SelectionSort_hpp
#define SelectionSort_hpp

#include "SortAlgorithm.hpp"

class SelectionSort : public SortAlgorithm{
private:
    void sortAlg(int * A, int n);
public:
    string getName();
};


#endif /* SelectionSort_hpp */
