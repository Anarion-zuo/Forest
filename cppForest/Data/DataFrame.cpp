//
// Created by anarion on 2019/8/6.
//

#include <sstream>
#include "DataFrame.h"

DataFrame::DataFrame(const std::string &&dir) {
    using namespace std;
    ifstream inFile(dir, ios::in);
    string lineStr;
    string str;
    getline(inFile, lineStr);
    stringstream s(lineStr);
    while (getline(s, str, ',')){
        _titles.push_back(str);
    }
    _mat.assign(_titles.size(), std::vector<double>());
    while (getline(inFile, lineStr)) {
        stringstream ss(lineStr);
        size_t i = 0;
        while (getline(ss, str, ',')){
//            if (_entry::check_is_num(str)){
            double num;
            stringstream sss(str);
            sss >> num;
            _mat[i].push_back(num);
//            } else {
//                _cols[i].push_back(_entry(str));
//            }
            ++i;
        }
    }
}

size_t DataFrame::height() const {
    return _mat[0].size();
}

size_t DataFrame::width() const {
    return _mat.size();
}

double DataFrame::loc(size_t width, size_t height) const {
    return _mat[width][height];
}
