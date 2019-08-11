//
// Created by anarion on 2019/8/11.
//

#include <sstream>
#include <cmath>
#include <set>
#include <limits>
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
    _mat.assign(_titles.size(), std::vector<_entry>());
    while (getline(inFile, lineStr)) {
        stringstream ss(lineStr);
        size_t i = 0;
        while (getline(ss, str, ',')){
            if (_entry::check_is_num(str)){
                if (str.empty() || _entry::check_is_blank(str)){
                    _mat[i].push_back(_entry());
                } else {
                    double num;
                    stringstream sss(str);
                    sss >> num;
                    _mat[i].push_back(_entry(num));
                }
            } else {
                _mat[i].push_back(_entry(str));
            }
            ++i;
        }
    }
    init_stats(_mat.size());
}

const _entry & DataFrame::loc(size_t width, size_t height) const {
    return _mat[width][height];
}

size_t DataFrame::height() const {
    return _mat[0].size();
}

size_t DataFrame::width() const {
    return _mat.size();
}

void DataFrame::init_stats(size_t dim) {
    _means.assign(dim, 0);
    _vars.assign(dim, 0);
}

void DataFrame::mean() {
    for (size_t i = 0; i < _mat.size(); ++i){
        double sum = 0;
        for (auto & j : _mat[i]){
            sum += j.get_num();
        }
        _means[i] = sum / _mat[i].size();
    }
}

void DataFrame::mean(size_t index) {
    double sum = 0;
    for (auto & j : _mat[index]){
        sum += j.get_num();
    }
    _means[index] = sum / _mat[index].size();
}

void DataFrame::variance() {
    for (size_t i = 0; i < _mat.size(); ++i){
        double sum = 0;
        for (size_t j = 0; j < _mat[i].size(); ++j){
            sum += pow(_mat[i][j].get_num() - _means[i], 2);
        }
        _vars[i] = sum / _mat[i].size();
    }
}

void DataFrame::variance(size_t index) {
    double sum = 0;
    for (size_t j = 0; j < _mat[index].size(); ++j){
        sum += pow(_mat[index][j].get_num() - _means[index], 2);
    }
    _vars[index] = sum / _mat[index].size();
}

void DataFrame::standardize() {
    for (size_t i = 0; i < _mat.size(); ++i){
        double sum2 = 0, sum1 = 0;
        for (size_t j = 0; j < _mat[i].size(); ++j){
            sum1 += _mat[i][j].get_num();
            sum2 += pow(_mat[i][j].get_num() - _means[i], 2);
        }
        double mean = sum1 / _mat[i].size();
        double var = sum2 / _mat[i].size();
        _means[i] = mean;
        _vars[i] = var;
        for (auto & j : _mat[i]){
            j.get_num() -= mean;
            j.get_num() /= var;
        }
    }
}

void DataFrame::format() {
    for (size_t i = 0; i < _mat.size(); ++i){
        bool type_is_num, ncont_flag = false;
        for (auto & j : _mat[i]){
            if (!j.is_nan){
                type_is_num = j.is_num;
                break;
            }
        }
        for (size_t j = 1; j < _mat[i].size(); ++j){
            if (_mat[i][j].is_num != type_is_num){
                _err_cols.push_back(i);
                ncont_flag = true;
                break;
            }
        }
        if (ncont_flag){
            continue;
        }
        if (type_is_num){
            _num_cols.push_back(i);
        } else {
            _str_cols.push_back(i);
        }
    }
}

void DataFrame::str2class() {
    std::map<std::string&, size_t> strs;
    for (size_t index : _str_cols){
        for (size_t i = 0; i < _mat[index].size(); ++i){
            strs.push(_mat[index][i].get_str(), strs.size());
        }
        for (size_t i = 0; i < _mat[index].size(); ++i){
            auto it = strs.find(_mat[index][i].get_str());
            _mat[index][i] = it->second;
        }
    }
}

void DataFrame::one_hot(size_t index) {
    size_t max = 0;
    for (auto & i : _mat[index]){
        double t = i.get_num();
        if (t > max){
            max = t;
        }
    }
    std::vector<std::vector<_entry>> ns(max, std::vector<_entry>(height(), _entry(0)));
    for (size_t i = 0; i < height(); ++i){
        ns[i][_mat[index][i].get_num()] = 1;
    }
}
