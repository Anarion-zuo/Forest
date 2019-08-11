//
// Created by anarion on 2019/8/11.
//

#ifndef CPPFOREST_DATAFRAME_H
#define CPPFOREST_DATAFRAME_H

#include <fstream>
#include <vector>
#include <map>
#include "_entry/_entry.h"

class DataFrame {
protected:
    std::ifstream _infile;
    std::vector<std::string> _titles;
    std::vector<std::vector<_entry>> _mat;

    // statistics
    void init_stats(size_t dim);
    std::vector<double> _means, _vars;

    // format
    std::vector<size_t> _str_cols, _num_cols, _err_cols;
public:
    explicit DataFrame(const std::string&& dir);
    size_t width() const ;
    size_t height() const ;
    const _entry & loc(size_t width, size_t height) const ;

    // statistics
    void mean();
    void mean(size_t index);
    void variance();
    void variance(size_t index);
    void standardize();

    // format
    void format();
    void str2class();
    void one_hot(size_t index);
};


#endif //CPPFOREST_DATAFRAME_H
