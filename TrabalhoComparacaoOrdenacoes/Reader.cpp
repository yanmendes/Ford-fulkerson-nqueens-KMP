//
//  Reader.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "Reader.hpp"

/**
 * @param A (int *) shuffled array
 *
 * @return   int    size of array
**/
int Reader::read(string fileName, int** A){
    int n, i = 0;
    string id, line;
    fstream file;

    file.open(fileName);

    file >> id >> n;

    *A = new int[n];

    while(file >> line){
        (*A)[i] = atoi(line.c_str());
        ++i;
    }

    return n;
}
