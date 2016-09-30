//
//  Helper.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "Helper.hpp"

/**
 * Método que retorna o maior elemento (absoluto) de um vetor
 *
 * @param A   (int*) Array a ser ordenado
 * @param n   (int)  Número de elementos do arranjo
 * @return int
 */
int Helper::getMax(int * A, int n)
{
    int max = abs(A[0]);
    
    for (int i = 1; i < n; i++){
        if(abs(A[i]) > max)
            max = abs(A[i]);
    }
    
    return max;
}

