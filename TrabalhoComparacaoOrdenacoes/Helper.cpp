//
//  Helper.cpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#include "Helper.hpp"

using namespace std;

/**
 * Método que retorna o maior elemento (absoluto) de um vetor
 *
 * @param A   (int*) Array a ser ordenado
 * @param n   (int)  Número de elementos do arranjo
 * @return int
 */
int Helper::getMax(int * A, int n)
{
    int max = abs(A[0]);
    
    for (int i = 1; i < n; i++){
        if(abs(A[i]) > max)
            max = abs(A[i]);
    }
    
    return max;
}

list<string> Helper::getFilesInDirectory(string directory)
{
    list<string> files;
    
    DIR * diretorio;
    struct dirent * entry;
    
    if((diretorio = opendir(directory.c_str()))){
        while((entry = readdir(diretorio))){
            if (string(entry->d_name).find(".txt") != string::npos || string(entry->d_name).find(".rtf") != string::npos) {
                files.push_front(directory + entry->d_name);
            }
        }
        closedir(diretorio);
    }
    
    return files;
}
