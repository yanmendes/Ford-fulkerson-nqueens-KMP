//
//  main.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "Reader.hpp"

//Algorithms
#include "CountingSort.hpp" ///ERRO
#include "RadixSort.hpp" ///ERRO
#include "HeapSort.hpp" ///ERRO
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "QuickSort.hpp"

bool debug            = false;
string inputFolder    = "";
list<string> inputFiles;
int partitionMethod   = 1;
Reader * r = new Reader();
int * A;
SortAlgorithm * algorithm;
string instance;
time_t currentTime;

static void usage(){
    cout << "Usage:\n" <<
    "    ./SortTest [options] [algorithm] \n\n" <<
    "Options:\n" <<
    "    -h                     Show this help\n" <<
    "    --debug                Print Shuffled Vector before the sorted one\n" <<
    "    --inputFolder=value    Path to the input folder\n" <<
    "    -i=value               Instance description\n" <<
    "    --partition=value      When using quick sort, choose the partition method [1: Random, 2: First and last, 3: First and middle] \n" <<
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
        } else if (!strncmp(argv[argInd], "--inputFolder=", 14)) {
            inputFolder  = &argv[argInd][14];
        } else if (!strcmp(argv[argInd], "--debug")) {
            debug = true;
        } else if (!strncmp(argv[argInd], "--partition=", 12)) {
            partitionMethod = atoi(&argv[argInd][12]);
        } else if (!strncmp(argv[argInd], "-i=", 3)) {
            instance = &argv[argInd][3];
        }
    }

    if (argInd != argc - 1) {
        usage();
        return 1;
    }

    Helper *h = new Helper();
    inputFiles = h->getFilesInDirectory(inputFolder);
    if(inputFolder.empty() || inputFiles.empty()){
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

void printArray(int * A, int n, fstream& outputFile){
    for(int i = 0; i < n; ++i){
        outputFile << A[i] << endl;
    }
}

int main(int argc, const char * argv[]) {
    int errors;

    if((errors = processArgs(argc, argv)))
        return errors;

    cout << "Selected Algorithm: " << algorithm->getName() << endl;
    while(!inputFiles.empty()){
        string file = inputFiles.back();
        inputFiles.pop_back();
        int n = r->read(file, &A);

//        string outputFileName = regex_replace(file, ".txt", "_output.txt");

        fstream outputFile;
        //outputFile.open(inputFolder + "/output/" + "tetas.txt");
        outputFile.open("tetas.txt", fstream::out);

        outputFile << "Done reading file: " << file << "@ " << time(&currentTime) << endl;
        outputFile << "Instance identifier: " << instance << endl;
        outputFile << "Array Size: " << n << endl << endl;

        if(debug){
            outputFile << "########BEGINING DEBUG########" << endl;
            outputFile << "########SHUFFLED ARRAY########" << endl;
            printArray(A, n, outputFile);
        }

        clock_t before_sort = clock();
        algorithm->sort(A, n);
        clock_t after_sort  = clock();

        if(debug){
            outputFile << "########SORTED ARRAY########" << endl;
            printArray(A, n, outputFile);
            outputFile << "########ENDING DEBUG########" << endl;
        }

        outputFile << "Operations Count: " << algorithm->getCount() << endl;
        outputFile << "Time elapsed: " << after_sort - before_sort << algorithm->getCount() << endl;

        outputFile.close();

        delete [] A;
    }

    return 0;
}
