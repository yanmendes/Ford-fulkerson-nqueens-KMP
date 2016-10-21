//
//  QuickSort.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "QuickSort.hpp"

string QuickSort::getName(){
    stringstream name;
    name << "Quick Sort - " << this->pivot;

    return name.str();
};

string QuickSort::getInferiorLimit(string instance_type){
    return "O(n log n)";
}

string QuickSort::getSuperiorLimit(string instance_type){
    return (!strcmp(instance_type.c_str(), "ascending") || !strcmp(instance_type.c_str(), "descending")) && pivot == 1 ? "O(n^2)" : "O(n log n)";
}

int QuickSort::getSmallestConstant(string instance_type, int * A, int n){
    return (!strcmp(instance_type.c_str(), "ascending") || !strcmp(instance_type.c_str(), "descending")) && pivot == 1 ?
        floor(this->getCount() / (n * n)) :
        floor(this->getCount() / (n * log2(n)));
}

/**
 * Class constructor that requires which version of
 * the partition algorithm will be executed.
 *
 * @param partitionMethod (int)
 */
QuickSort::QuickSort(int partitionMethod){
    switch (partitionMethod) {
        case 1:
            this->pivot = 1;
            this->current_pivot_choice_method = &QuickSort::biggestFirstTwo;
            break;
        case 2:
            this->pivot = 2;
            this->current_pivot_choice_method = &QuickSort::biggestFirstMiddle;
            break;
        default:
            this->pivot = 3;
            this->current_pivot_choice_method = &QuickSort::biggestRandom;
            mt.seed(chrono::system_clock::now().time_since_epoch().count());
            break;
    }
}

int QuickSort::biggestFirstTwo(int *A, int start, int end){
    incrementCount(4);

    if(A[start] > A[start+1])
        return start;

    return start + 1;
}

int QuickSort::biggestFirstMiddle(int *A, int start, int end){
    incrementCount(5);

    int middle = floor((start + end) / 2);

    if(A[start] > A[middle])
        return start;

    return middle;
}


int QuickSort::biggestRandom(int *A, int start, int end){
    incrementCount(7);

    uniform_int_distribution<long int> dist(start, end);
    int firstRandom = dist(mt);
    int secondRandom = dist(mt);

    if(A[firstRandom] > A[secondRandom])
        return firstRandom;

    return secondRandom;
}

/**
 * Quick Sort
 *
 * @param A (int*) Shuffled array
 * @param n (int)  Number of elements of said array
 */
void QuickSort::sortAlg(int * A, int n){
    this->quickSort(A, 0, n - 1);
}

/**
 * Método recursivo auxiliar à construção do quicksort
 *
 * @param A    (int*)  Shuffled array
 * @param start (int)  Relative first element of the array
 * @param end   (int)  Relative last element of the array
 */
void QuickSort::quickSort(int * A, int start, int end){
    incrementCount(1); // start < end

    if(start < end){
        incrementCount(7);
        // declarations, current_pivot_choice_method call, "A" element access, quicksort calls

        int i = start,
            j = end,
            pivot = A[(this->*current_pivot_choice_method)(A, start, end)];

        // loop stops when i and j met, this happens after |j - i| increments/decrements
        // + pivot method comparison
        do {
            incrementCount(6); // A[i] && A[i] < pivot && A[j] && A[j] > pivot && i <= j && j > i

            while (A[i] < pivot) {
                ++i;
                incrementCount(2); // ++i && A[i] < pivot
            }
            while (A[j] > pivot) {
                --j;
                incrementCount(2); // --j && A[j] > pivot
            }

            if(i <= j) {
                swap(A[i], A[j]);
                ++i;
                --j;
                incrementCount(7); // A[i] && A[j] && swap(A[i], A[j]) && ++i && ++j
            }
        } while (j > i);

        quickSort(A, start, j);
        quickSort(A, i, end);
    }
}
