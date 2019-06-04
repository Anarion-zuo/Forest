//
// Created by anarion on 6/3/19.
//

#include "Titles.h"

Titles::Titles(const std::vector<std::string> &titles) : _title_table(titles) {
    for (size_t i = 0; i < _title_table.size(); ++i){
        _title_index.insert(std::pair<std::string, size_t>(_title_table[i], i));
    }
    if (_title_table.size() != _title_index.size()){
        // exception
    }
}

std::string &Titles::operator[](size_t index) {
    if (index > _title_table.size()){
        // exception
    }
    return _title_table[index];
}

size_t Titles::operator[](const std::string &str) {
    auto it = _title_index.find(str);
    if (it == _title_index.end()) {
        //exception
    }
    return it->second;
}

void Titles::push_back(const std::string &newti) {
    auto it = _title_index.find(newti);
    if (it != _title_index.end()){
        // exception
    }
    _title_table.push_back(newti);
    _title_index.insert(std::pair<std::string, size_t>(newti, _title_table.size() - 1));
}

void Titles::pop_back() {
    if (!_title_index.size()){
        return;
    }
    std::string s = *(_title_table.end() - 1);
    _title_table.pop_back();
    _title_index.erase(s);
}

void Titles::push_at(const std::string &newti, size_t index) {
    if (index >= _title_index.size()){
        // exception
    }
    auto it = _title_index.find(newti);
    if (it != _title_index.end()){
        // exception
    }
    _title_table.insert(_title_table.begin() + index, newti);
    _title_index.insert(std::pair<std::string, size_t>(newti, index));
}

void Titles::pop_at(const std::string& str) {
    auto it = _title_index.find(str);
    if (it == _title_index.end()){
        // exception
    }
    _title_table.erase(_title_table.begin() + it->second);
    _title_index.erase(str);
}

void Titles::push_after(const std::string &str, const std::string &astr) {
    auto it = _title_index.find(astr);
    if (it == _title_index.end()){
        // exception
    }
    push_at(str, it->second + 1);
}

void Titles::push_before(const std::string &str, const std::string &bstr) {
    auto it = _title_index.find(bstr);
    if (it == _title_index.end()){
        // exception
    }
    push_at(str, it->second - 1);
}
