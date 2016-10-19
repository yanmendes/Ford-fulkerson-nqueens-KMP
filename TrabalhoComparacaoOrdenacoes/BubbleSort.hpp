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
    string getInferiorLimit(string instance_type);
    string getSuperiorLimit(string instance_type);
    int    getSmallestConstant(string instance_type, int * A, int n);
};


#endif /* BubbleSort_hpp */
