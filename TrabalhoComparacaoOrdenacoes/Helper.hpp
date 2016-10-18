//
//  Helper.hpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#ifndef Helper_hpp
#define Helper_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <list>
#include <stdlib.h>
#include <cstdlib>
#include <dirent.h>
#include <cwchar>
#include <time.h>
#include <cstring>
#include <sstream> 

using namespace std;

class Helper{
public:
    int getMax(int * A, int n);
    list<string> getFilesInDirectory(string directory);
};

#endif /* Helper_hpp */
