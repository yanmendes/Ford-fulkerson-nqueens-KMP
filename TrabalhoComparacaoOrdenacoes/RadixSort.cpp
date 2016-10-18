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
 * Counting Sort
 *
 * @param A  (int*)  Shuffled array
 * @param n   (int)  Number of elements of said array
 * @param exp (int)  Decimal place to be ordered
 */
void RadixSort::countingSort(int * A, int n, int exp)
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
 * @param A (int*) Shuffled array
 * @param n (int)  Number of elements of said array
 */
void RadixSort::sortAlg(int * A, int n)
{
    int max = (new Helper())->getMax(A, n);

    //
    //#### Exp: Decimal place to be ordered at the current iteration                                    ####
    //#### Exp *= 10 until the result of the division of the biggest number by Exp is greater than zero ####
    //
    for (int exp = 1; max/exp > 0; exp *= 10)
        countingSort(A, n, exp);
}



