//
//  main.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "Reader.hpp"

//Algorithms
#include "CountingSort.hpp"
#include "RadixSort.hpp"
#include "HeapSort.hpp"
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "QuickSort.hpp"

bool debug            = false;
string inputFolder    = "", outputFolder = "";
list<string> inputFiles;
int partitionMethod   = 1;
Reader * r;
int * A;
SortAlgorithm * algorithm;

static void usage(){
    cout << "Usage:\n" <<
    "    ./SortTest [options] [algorithm] \n\n" <<
    "Options:\n" <<
    "    -h                     Show this help\n" <<
    "    --debug                Print Shuffled Vector before the sorted one\n" <<
    "    --inputFolder=value    Path to the input folder\n" <<
    "    --partition=value      When using quick sort, choose the partition method [1: Random, 2: First and last, 3: First and middle] \n" <<
    "    --debug                Print Shuffled Vector before and after sort\n\n" <<
    "Algorithm:\n" <<
    "    bubble          Bubble Sort\n" <<
    "    counting        Counting Sort\n" <<
    "    heap            Heap Sort\n" <<
    "    insertion       Insertion Sort\n" <<
    "    merge           Merge Sort\n" <<
    "    quick           Quick Sort\n" <<
    "    radix           Radix Sort\n" <<
    "    selection       Selection Sort\n\n";
}

int processArgs(int argc, const char * argv[]){
    
    if(argc < 2){
        usage();
        return 2;
    }
    
    int argInd;
    
    for(argInd = 1; argInd < argc; argInd++) {
        
        if (argv[argInd][0] != '-')
            break;
        
        if (!strcmp(argv[argInd], "-h")) {
            usage();
            return 2;
        } else if (!strncmp(argv[argInd], "--inputFolder=", 6)) {
            inputFolder  = &argv[argInd][6];
        } else if (!strcmp(argv[argInd], "--debug")) {
            debug = true;
        } else if (!strncmp(argv[argInd], "--partition=", 6)) {
            partitionMethod = atoi(&argv[argInd][6]);
        }
    }
    
    if (argInd != argc - 1) {
        usage();
        return 1;
    }
    
    if(inputFolder.empty() || (inputFiles = (new Helper)->getFilesInDirectory(inputFolder)).empty()){
        cout << "Invalid folder name or empty directory" <<endl;
        return 3;
    }
    
    if(!strcmp (argv[argInd], "bubble")) {
        algorithm = new BubbleSort();
    } else if(!strcmp (argv[argInd], "counting")) {
        algorithm = new CountingSort();
    } else if(!strcmp (argv[argInd], "heap")) {
        algorithm = new HeapSort();
    } else if(!strcmp (argv[argInd], "insertion")) {
        algorithm = new InsertionSort();
    } else if(!strcmp (argv[argInd], "merge")) {
        //        algorithm = new MergeSort();
    } else if(!strcmp (argv[argInd], "quick")) {
        algorithm = new QuickSort(partitionMethod);
    } else if(!strcmp (argv[argInd], "radix")) {
        algorithm = new RadixSort();
    } else if(!strcmp (argv[argInd], "selection")) {
        algorithm = new SelectionSort();
    } else {
        cout << "Invalid Algorithm!!" << endl;
        usage();
        return 4;
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    int errors;
    
    if((errors = processArgs(argc, argv)))
        return errors;

    delete [] A;
    
    return 0;
}
