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
    string getInferiorLimit(string instance_type);
    string getSuperiorLimit(string instance_type);
    int    getSmallestConstant(string instance_type, int * A, int n);
};


#endif /* CountingSort_hpp */
