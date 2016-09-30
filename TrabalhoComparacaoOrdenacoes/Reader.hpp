//
//  Reader.hpp
//  TrabalhoComparacaoOrdenacoes
//
//  Created by Yan Mendes on 30/09/16.
//  Copyright © 2016 Yan Mendes. All rights reserved.
//

#ifndef Reader_hpp
#define Reader_hpp

#include "Helper.hpp"

using namespace std;

class Reader{
private:
    string _fileName;
public:
    Reader(string fileName) {this->_fileName = fileName;};
    int read(int * A);
};

#endif /* Reader_hpp */
