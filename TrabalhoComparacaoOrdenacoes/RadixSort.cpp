//
//  Radix.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "RadixSort.hpp"

using namespace std;

string RadixSort::getName(){
    return "Radix Sort";
}

/**
 * Método similar ao countSort original. A única adaptação presente
 * é que ao invés de acessar diretamente o valor A[i], escolhe-se o número
 * constante na casa decimal (exp) da iteração. Para isto, utiliza-se (A[i]/exp) % 10
 *
 * @param A   (int*) Array a ser ordenado
 * @param n   (int)  Número de elementos do arranjo
 * @param exp (int)  Casa decimal a ser ordenada
 * @return int *
 */
void countSort(int * A, int n, int exp)
{
    int * B = new int[n]; // output array
    int C[10] = {0};      // counting array
    int i;

    for (i = 0; i < n; i++)
        C[(A[i]/exp) % 10]++;

    for (i = 1; i < 10; i++)
        C[i] += C[i - 1];

    for (i = n - 1; i >= 0; i--) {
        B[C[(A[i]/exp) % 10] - 1] = A[i];
        C[(A[i]/exp) % 10]--;
    }

    for(int i = 0; i < n; i++){
        A[i] = B[i];
    }
}

/**
 * Radix Sort
 *
 * @param A (int*) Array a ser ordenado
 * @param n (int)  Número de elementos do arranjo
 */
void RadixSort::sortAlg(int * A, int n)
{
    int max = (new Helper())->getMax(A, n);

    //
    //#### Exp: Casa decimal em que o counting sort irá ordenar na presente iteração         ####
    //#### Exp *= 10 até que a divisão do elemento de maior casas decimais por este seja < 1 ####
    //
    for (int exp = 1; max/exp > 0; exp *= 10)
        countSort(A, n, exp);
}



