//
// Created by anarion on 6/3/19.
//

#ifndef CPPFOREST_TITLES_H
#define CPPFOREST_TITLES_H

#include <string>
#include <vector>
#include <map>

class Titles {
private:
    std::vector<std::string> _title_table;
    std::map<std::string, size_t> _title_index;

public:
    Titles(const std::vector<std::string>& titles);
    void push_back(const std::string& newti);
    void push_at(const std::string& newti, size_t index);
    void pop_back();
    void pop_at(const std::string& str);
    void push_after(const std::string& str, const std::string& astr);
    void push_before(const std::string& str, const std::string& bstr);
    std::string&operator[] (size_t index);
    size_t operator[] (const std::string& str);
};


#endif //CPPFOREST_TITLES_H
