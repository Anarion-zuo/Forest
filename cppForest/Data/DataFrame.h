//
// Created by anarion on 2019/8/6.
//

#ifndef CPPFOREST_DATAFRAME_H
#define CPPFOREST_DATAFRAME_H


#include <fstream>
#include <vector>

class DataFrame {
protected:
    std::ifstream _infile;
    std::vector<std::string> _titles;
    std::vector<std::vector<double>> _mat;

public:
    explicit DataFrame(const std::string&& dir);
    size_t width() const ;
    size_t height() const ;
    double loc(size_t width, size_t height) const ;
};


#endif //CPPFOREST_DATAFRAME_H
