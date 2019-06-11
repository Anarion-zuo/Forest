//
// Created by anarion on 6/11/19.
//

#ifndef CPPFOREST_RANGE_H
#define CPPFOREST_RANGE_H


class Range {
protected:
    double _left;
    double _right;
public:
    Range(double left, double right);
    virtual ~Range() = default;

    Range* clone();

    bool is_in(double n);
    bool is_in(Range* range);
    bool on_right(Range* range);
    bool on_right(double n);
    bool on_left(Range* range);
    bool on_left(double n);

    void set_left(double n);
    double get_left();
    void set_right(double n);
    double get_right();
};


#endif //CPPFOREST_RANGE_H
