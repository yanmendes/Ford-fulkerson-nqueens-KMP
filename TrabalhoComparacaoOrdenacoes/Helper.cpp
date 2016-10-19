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
 * Method that returns the greatest absolute value in the array
 *
 * @param A (int*) Shuffled array
 * @param n (int)  Number of elements of said array
 *
 * @return   int
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

    DIR * dir;
    struct dirent * entry;

    if((dir = opendir(directory.c_str()))){
        while((entry = readdir(dir))){
            if (strstr( entry->d_name, ".in" ))
                files.push_front(directory + "/" + entry->d_name);
        }
        closedir(dir);
    }

    return files;
}

vector<string> Helper::explode(std::string const & s, char delim) {
    std::vector<std::string> result;
    std::istringstream iss(s);
    
    for (std::string token; std::getline(iss, token, delim); )
    {
        result.push_back(std::move(token));
    }
    
    return result;
}

