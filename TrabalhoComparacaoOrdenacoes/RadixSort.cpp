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

string RadixSort::getInferiorLimit(string instance_type){
    return "O(wn)";
}

string RadixSort::getSuperiorLimit(string instance_type){
    return "O(wn)";
}

int RadixSort::getSmallestConstant(string instance_type, int * A, int n){
    return floor(this->getCount() / (n * (int) log10((new Helper)->getMax(A, n)) + 1));
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
    incrementCount(12); // int * B = new int[n] && int C[10] = {0}

    int * B = new int[n]; // output array
    int C[10] = {0};      // counting array
    int i;

    incrementCount(31);
    for (i = 0; i < n; i++)
        C[(A[i]/exp) % 10]++;

    incrementCount(31);
    for (i = 1; i < 10; i++)
        C[i] += C[i - 1];

    incrementCount(1 + (7 * n));
    // i = n - 1 && i >= 0 && 3*A[i] && C[(A[i]/exp) % 10] && B[C[(A[i]/exp) % 10] - 1] = A[i]; && C[(A[i]/exp) % 10]--
    for (i = n - 1; i >= 0; i--) {
        B[C[(A[i]/exp) % 10] - 1] = A[i];
        C[(A[i]/exp) % 10]--;
    }

    incrementCount(1 + (3 * n)); // i = 0 && i < n && B[i] && A[i] = B[i]
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
    incrementCount(5 + n); // getMax(A, n) && int max = ... && int exp = 1 && FIRST max/exp > 0
    int max = (new Helper())->getMax(A, n);

    //
    //#### Exp: Decimal place to be ordered at the current iteration                                    ####
    //#### Exp *= 10 until the result of the division of the biggest number by Exp is greater than zero ####
    //
    for (int exp = 1; max/exp > 0; exp *= 10) {
        incrementCount(1); // countingSort call
        countingSort(A, n, exp);
    }
}



