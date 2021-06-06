// Copyright 2021 Soda

#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_

#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <functional>
#include <utility>


std::function<bool(std::string, std::string)> comp_1 = [](std::string a,
    std::string b) { return a > b; };

std::function<bool(std::string, std::string)> comp_2 = [](std::string a,
    std::string b) {
    int count_a = 0;
    int count_b = 0;
    for (int i = 0; i < a.size(); ++i) if (a[i] >= 'A' && a[i] <= 'Z')
        count_a++;
    for (int i = 0; i < b.size(); ++i) if (b[i] >= 'A' && b[i] <= 'Z')
        count_b++;
    if (count_a < count_b) {
        return true;
    } else {
        return false;
    }
};

std::function<bool(std::string, std::string)> comp_3 = [](std::string a,
    std::string b) {
    int count_a = 0;
    int count_b = 0;
    for (int i = 0; i < a.size(); ++i) if (a[i] == 'a' || a[i] == 'A')
        count_a++;
    for (int i = 0; i < b.size(); ++i) if (b[i] == 'a' || b[i] == 'A')
        count_b++;
    if (count_a < count_b) {
        return true;
    } else { 
        return false;
    }
};

std::function<bool(std::string, std::string)> comp_4 = [](std::string a,
    std::string b) {
    if (a.back() > b.back()) {
        return true;
    }
    else {
        return false;
    }
};

std::function<bool(std::string, std::string)> comp_5 = [](std::string a,
    std::string b) {
    if (a.size() > b.size()) {
        return true;
    }
    else {
        return false;
    }
};

void bubble_sort(std::vector<std::string>& vect,
    std::function<bool(std::string, std::string)> comp) {
    int size = vect.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (comp(vect[j], vect[j + 1])) {
                std::swap(vect[j], vect[j + 1]);
            }
        }
    }
}


template<class T>
void BubbleSort_T(std::vector<std::string>& vect, T comp) {
    int n = vect.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (comp(vect[j + 1], vect[j])) {
                std::swap(vect[j], vect[j + 1]);
            }
        }
    }
}


void print_vct(const std::vector<std::string>&);

#endif  // INCLUDE_TASK1_H_
