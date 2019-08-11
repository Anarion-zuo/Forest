//
// Created by anarion on 2019/8/6.
//

#ifndef CPPFOREST_FINALDATA_H
#define CPPFOREST_FINALDATA_H


#include <fstream>
#include <vector>

class FinalData {
protected:
    std::ifstream _infile;
    std::vector<std::string> _titles;
    std::vector<std::vector<double>> _mat;

public:
    explicit FinalData(const std::string&& dir);
    size_t width() const ;
    size_t height() const ;
    double loc(size_t width, size_t height) const ;
};


#endif //CPPFOREST_FINALDATA_H
