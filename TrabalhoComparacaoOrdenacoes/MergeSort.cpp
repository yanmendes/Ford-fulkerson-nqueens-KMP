//
//  MergeSort.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 18/10/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "MergeSort.hpp"

string MergeSort::getName(){
    stringstream name;
    name << "Merge Sort - " << this->allocationMethod;

    return name.str();
};

string MergeSort::getInferiorLimit(string instance_type){
    return "O(n log n)";
}

string MergeSort::getSuperiorLimit(string instance_type){
    return "O(n log n)";
}

int MergeSort::getSmallestConstant(string instance_type, int * A, int n){
    return floor(this->getCount() / (n * log2(n)));
}

/**
 * Class constructor that requires which version of
 * the MergeSort algorithm will be executed.
 *
 * @param allocationMethod (int) [1: Default, 2: Alocates array beforehand]
 */
MergeSort::MergeSort(int allocationMethod){
    this->allocationMethod = allocationMethod;
}

/**
 * Merge Sort
 *
 * @param A (int*) Shuffled array
 * @param n (int)  Number of elements of said array
 */
void MergeSort::sortAlg(int * A, int n){
    if(this->allocationMethod == 2){
        int * Aux = new int[n];
        this->adaptedMergeSort(A, 0, n - 1, Aux);
    }
    else
        this->mergeSort(A, 0, n - 1);
}

/**
 * Merge
 * @param A     (int*) Shuffled array
 * @param start (int)  Relative first element of the array
 * @param end   (int)  Relative last element of the array
 * @param mid   (int)  Relative middle element of the array
 */
void MergeSort::merge(int * A, int start, int end, int mid){
    incrementCount(6);
    // i = start && j = mid + 1 && k = 0 && int * vetorTemp = ... && FIRST i < mid + 1 && FIRST j < end + 1
    int i = start, j = mid + 1, k = 0;

    int * vetorTemp = new int [end - start + 1];

    while(i < mid + 1 || j  < end + 1) {
        if (i == mid + 1) {
            vetorTemp[k] = A[j];
            j++;
            k++;
            incrementCount(5); // i == mid + 1 && A[j] && Aux[k] = A[j] && j++ && k++
        } else if (j == end + 1) {
            vetorTemp[k] = A[i];
            i++;
            k++;
            incrementCount(6); // i == mid + 1 && j == end + 1 && A[i] && Aux[k] = A[i] && i++ && k++
        } else if (A[i] < A[j]) {
            vetorTemp[k] = A[i];
            i++;
            k++;
            incrementCount(9);
            // i == mid + 1 && j == end + 1 && A[j] && A[i] && A[i] < A[j] && A[i] && Aux[k] = A[i] && i++ && k++
        } else {
            vetorTemp[k] = A[j];
            j++;
            k++;
            incrementCount(9);
            // i == mid + 1 && j == end + 1 && A[j] && A[i] && A[i] < A[j] && A[j] && Aux[k] = A[j] && j++ && k++
        }
        incrementCount(2); // i < mid + 1 || j < end + 1
    }

    incrementCount(1 + (3 * (end - start + 1))); // i = start && i <= end && vetorTemp[i - start] && A[i] = ...
    for(i = start; i <= end; i++)
        A[i] = vetorTemp[i - start];

    delete [] vetorTemp;
}

/**
 * Merge
 * @param A     (int*) Shuffled array
 * @param start (int)  Relative first element of the array
 * @param end   (int)  Relative last element of the array
 * @param mid   (int)  Relative middle element of the array
 * @param Aux  (int*)  Auxilary array that merge the two sorted halves
 */
void MergeSort::adaptedMerge(int * A, int start, int end, int mid, int * Aux){
    incrementCount(5); // i = start && j = mid + 1 && k = 0 && FIRST i < mid + 1 && FIRST j < end + 1
    int i = start, j = mid + 1, k = 0;

    while(i < mid + 1 || j < end + 1) {
        if (i == mid + 1) {
            Aux[k] = A[j];
            j++;
            k++;
            incrementCount(5); // i == mid + 1 && A[j] && Aux[k] = A[j] && j++ && k++
        } else if (j == end + 1) {
            Aux[k] = A[i];
            i++;
            k++;
            incrementCount(6); // i == mid + 1 && j == end + 1 && A[i] && Aux[k] = A[i] && i++ && k++
        } else if (A[i] < A[j]) {
            Aux[k] = A[i];
            i++;
            k++;
            incrementCount(9);
            // i == mid + 1 && j == end + 1 && A[j] && A[i] && A[i] < A[j] && A[i] && Aux[k] = A[i] && i++ && k++
        } else {
            Aux[k] = A[j];
            j++;
            k++;
            incrementCount(9);
            // i == mid + 1 && j == end + 1 && A[j] && A[i] && A[i] < A[j] && A[j] && Aux[k] = A[j] && j++ && k++
        }
        incrementCount(2); // i < mid + 1 || j < end + 1
    }

    for(i = start; i <= end; i++){
        incrementCount(1);
        A[i] = Aux[i - start];
    }
}

/**
 * Recursive method that implements MergeSort
 *
 * @param A    (int*)  Shuffled array
 * @param start (int)  Relative first element of the array
 * @param end   (int)  Relative last element of the array
 */
void MergeSort::mergeSort(int * A, int start, int end){
    incrementCount(1);

    if (start < end) {
        incrementCount(4); // int mid = ... && function calls

        int mid = (start + end) / 2;

        mergeSort(A, start, mid);
        mergeSort(A, mid + 1, end);

        merge(A, start, end, mid);
    }
}

/**
 * Recursive method that implements the adapted MergeSort
 *
 * @param A    (int*)  Shuffled array
 * @param start (int)  Relative first element of the array
 * @param end   (int)  Relative last element of the array
 * @param Aux  (int*)  Auxilary array that merge the two sorted halves
 */
void MergeSort::adaptedMergeSort(int * A, int start, int end, int * Aux){
    incrementCount(1);

    if (start < end) {
        incrementCount(4); // int mid = ... && function calls

        int mid = (start + end) / 2;

        adaptedMergeSort(A, start, mid, Aux);
        adaptedMergeSort(A, mid + 1, end, Aux);

        adaptedMerge(A, start, end, mid, Aux);
    }
}
