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
    _cols.assign(_titles.size(), std::vector<_entry>());
    while (getline(inFile, lineStr)) {
        stringstream ss(lineStr);
        size_t i = 0;
        while (getline(ss, str, ',')){
            if (_entry::check_is_num(str)){
                double num;
                stringstream sss(str);
                sss >> num;
                _cols[i].push_back(_entry(num));
            } else {
                _cols[i].push_back(_entry(str));
            }
            ++i;
        }
    }
}

std::string _col_mat::to_str(size_t begin, size_t end) {
    using namespace std;
    string ss;
    for (size_t i = 0; i < _titles.size() - 1; ++i){
        ss += _titles[i] + ',';
    }
    ss += *(_titles.end() - 1) + '\n';
    for (size_t j = begin; j < end; ++j){
        for (size_t i = 0; i < _titles.size() - 1; ++i){
            ss += _cols[i][j].to_str() + ',';
        }
        ss += (*(_cols.end() - 1))[j].to_str() + '\n';
    }
    return move(ss);
}

void _col_mat::to_csv(const char* dir, size_t begin, size_t end) {
    std::ofstream of;
}

size_t _col_mat::width() {
    return _titles.size();
}
