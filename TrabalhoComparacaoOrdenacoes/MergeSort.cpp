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
    int i = start, j = mid + 1, k = 0;
    
    int * vetorTemp = new int [end - start + 1];
    
    while(i < mid + 1 || j  < end + 1) {
        if (i == mid + 1) {
            incrementCount(1);
            vetorTemp[k] = A[j];
            j++;
            k++;
        } else if (j == end + 1) {
            incrementCount(2);
            vetorTemp[k] = A[i];
            i++;
            k++;
        } else if (A[i] < A[j]) {
            incrementCount(3);
            vetorTemp[k] = A[i];
            i++;
            k++;
        } else {
            incrementCount(3);
            vetorTemp[k] = A[j];
            j++;
            k++;
        }
    }
    
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
    int i = start, j = mid + 1, k = 0;
    
    while(i < mid + 1 || j  < end + 1) {
        if (i == mid + 1) {
            incrementCount(1);
            Aux[k] = A[j];
            j++;
            k++;
        } else if (j == end + 1) {
            incrementCount(2);
            Aux[k] = A[i];
            i++;
            k++;
        } else if (A[i] < A[j]) {
            incrementCount(3);
            Aux[k] = A[i];
            i++;
            k++;
        } else {
            incrementCount(3);
            Aux[k] = A[j];
            j++;
            k++;
        }
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
    if (start < end) {
        int mid = (start + end) / 2;
        
        incrementCount(1);
        mergeSort(A, start, mid);
        
        incrementCount(1);
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
    if (start < end) {
        int mid = (start + end) / 2;
        
        incrementCount(1);
        adaptedMergeSort(A, start, mid, Aux);
        
        incrementCount(1);
        adaptedMergeSort(A, mid + 1, end, Aux);
        
        adaptedMerge(A, start, end, mid, Aux);
    }
}
