//
//  CountingSort.hpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#ifndef CountingSort_hpp
#define CountingSort_hpp

#include "SortAlgorithm.hpp"

class CountingSort : public SortAlgorithm{
private:
    void sortAlg(int * A, int n);
public:
    string getName();
};


#endif /* CountingSort_hpp */
