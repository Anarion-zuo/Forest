//
// Created by anarion on 2019/8/5.
//

#include <fstream>
#include <sstream>
#include <fcntl.h>
#include <zconf.h>
#include "_col_mat.h"

_col_mat::_col_mat() {}

_col_mat::_col_mat(const std::string &&dir) {
    using namespace std;
    ifstream inFile(dir, ios::in);
    string lineStr;
    string str;
    getline(inFile, lineStr);
    stringstream s(lineStr);
    while (getline(s, str, ',')){
        _titles.push_back(str);
    }
    _cols.assign(_titles.size(), std::vector<double>());
    while (getline(inFile, lineStr)) {
        stringstream ss(lineStr);
        size_t i = 0;
        while (getline(ss, str, ',')){
//            if (_entry::check_is_num(str)){
                double num;
                stringstream sss(str);
                sss >> num;
                _cols[i].push_back(num);
//            } else {
//                _cols[i].push_back(_entry(str));
//            }
            ++i;
        }
    }
}


void _col_mat::to_csv(const char* dir, size_t begin, size_t end) {
    std::ofstream of;
}

size_t _col_mat::width() {
    return _titles.size();
}

size_t _col_mat::height() {
    return _cols[0].size();
}

double _col_mat::loc(size_t h, size_t w) {
    return _cols[w][h];
}
