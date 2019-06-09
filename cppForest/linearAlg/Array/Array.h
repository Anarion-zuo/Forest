//
// Created by anarion on 19-5-31.
//

#ifndef CPPFOREST_ARRAY_H
#define CPPFOREST_ARRAY_H


#include <vector>
#include <string>

class Array {
protected:
    std::vector<double> _c;
public:
    Array();
    Array(const std::vector<double> &c);
    Array(size_t n, double a);
    ~Array(){}
    Array* clone();

    size_t size();
    std::string to_string();

    // statistics
    double sum();
    double prod();
    double mean();
    double moment(size_t n);
    double nth_item(size_t n);
    double most_frequent();

    // search
    double& operator[] (size_t n);
    std::vector<size_t> find(double a);
    size_t count(double a);
    bool has(double a);

    // structure operations
    void push_back(double a);
    void push_at(double a, size_t n);
    void del_back();
    void del_at(size_t n);
    void stack(Array* a);

    // binary operations
    static Array* add(Array* x, Array* y);
    static Array* sub(Array* x, Array* y);
    static Array* mul(Array* x, Array* y);
    static Array* div(Array* x, Array* y);
    static Array* add(Array* x, double y);
    static Array* sub(Array* x, double y);
    static Array* mul(Array* x, double y);
    static Array* div(Array* x, double y);
    static double dot(Array* x, Array* y);
};


#endif //CPPFOREST_ARRAY_H
