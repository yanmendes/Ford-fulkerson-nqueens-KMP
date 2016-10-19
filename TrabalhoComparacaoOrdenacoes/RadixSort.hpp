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
    void countingSort(int * A, int n, int exp);
    void sortAlg(int * A, int n);
public:
    string getName();
    string getInferiorLimit(string instance_type);
    string getSuperiorLimit(string instance_type);
    int    getSmallestConstant(string instance_type, int * A, int n);
};

#endif /* Radix_hpp */
