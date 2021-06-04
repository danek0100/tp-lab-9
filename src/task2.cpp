// Copyright 2021 SoDa

#include "task2.h"
#include <fstream>
#include <iostream>

void bubble_sort_th(std::vector<std::string>& vect,
    std::function<bool(std::string, std::string)> comp,
    bool& printed, bool& sorted, bool& step, std::mutex& mtx, cv& con_var) {
    int size = vect.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            std::unique_lock<std::mutex> unqLock(mtx);
            con_var.wait(unqLock, []() { return printed; });
            if (comp(vect[j + 1], vect[j])) {
                std::swap(vect[j], vect[j + 1]);
            }
            step = true;
            printed = false;
            unqLock.unlock();
            con_var.notify_all();
        }
    }
    sorted = true;

void print_vct(std::vector<std::string> & vct) {
    for (auto x : vct) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
