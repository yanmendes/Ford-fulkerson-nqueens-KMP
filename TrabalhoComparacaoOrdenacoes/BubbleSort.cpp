//
//  BubbleSort.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "BubbleSort.hpp"

string BubbleSort::getName(){
    return "Bubble Sort";
};

void BubbleSort::sortAlg(int * A, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            incrementCount(1);
            if(A[i] > A[j])
                swap(A[i], A[j]);
        }
    }
}
