//
//  BubbleSort.hpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#ifndef BubbleSort_hpp
#define BubbleSort_hpp

#include "SortAlgorithm.hpp"

class BubbleSort : public SortAlgorithm{
private:
    void sortAlg(int * A, int n);
public:
    string getName();
};


#endif /* BubbleSort_hpp */
