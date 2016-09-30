//
//  SortAlgorithm.hpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#ifndef SortAlgorithm_hpp
#define SortAlgorithm_hpp

#include "Helper.hpp"

using namespace std;

class SortAlgorithm {
private:
    unsigned long long int count = 0;
    virtual void sortAlg(int * A, int n) = 0;
    
public:
    virtual string getName() = 0;
    
    void incrementCount(int val) { count += val; };
    long long int getCount() { return count; };
    
    void sort(int * A, int n) {
        count = 0;
        sortAlg(A, n);
    };
};


#endif /* SortAlgorithm_hpp */
