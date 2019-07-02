//
// Created by anarion on 7/1/19.
//

#ifndef CPPFOREST_MLPARSER_H
#define CPPFOREST_MLPARSER_H

#include <string>

class MLParser {
protected:
    std::string _data;

public:
    MLParser(const std::string&& data);
    virtual ~MLParser() = default;


};


#endif //CPPFOREST_MLPARSER_H
