//
//  Radix.hpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#ifndef Radix_hpp
#define Radix_hpp

#include "SortAlgorithm.hpp"

class RadixSort : public SortAlgorithm{
private:
    void sortAlg(int * A, int n);
public:
    string getName();
};

#endif /* Radix_hpp */
