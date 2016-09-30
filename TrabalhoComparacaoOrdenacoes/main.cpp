//
//  main.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "Reader.hpp"
#include "RadixSort.hpp"
#include "CountingSort.hpp"

SortAlgorithm *algorithm;
int seed = time(NULL);
int size = 100;
bool debug = false;


static void interface(){
    cout << "Usage:\n" <<
    "    ./SortTest [options] [algorithm] \n\n" <<
    "Options:\n" <<
    "    -?              Show this help\n" <<
    "    -seed=value     Randomic Seed [positive int] (default: time(NULL))\n" <<
    "    -debug          Print Shuffled Vector before and after sort\n\n" <<
    "Algorithm:\n" <<
    "    bubble          Bubble Sort\n" <<
    "    heap            Heap Sort\n" <<
    "    merge           Merge Sort\n" <<
    "    quick           Quick Sort\n" <<
    "    radix           Radix Sort\n\n";
}

int main(int argc, const char * argv[]) {
//    Reader * r = new Reader(argv[1]);
//    int * A;
//    
//    r->read(A);
//    
//    while(true){
//        interface();
//    }
    
    int * A = new int [5];
    A[0] = 5;
    A[1] = 3;
    A[2] = 4;
    A[3] = 1;
    A[5] = 2;
    
    int n = 5;
    
    for(int i = 0; i < n; i++)
        cout << A[i] << '\t';
    
    delete [] A;
    
    return 0;
}
