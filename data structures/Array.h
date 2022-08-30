//
// Created by alex on 24/08/2022.
//

#include <vector>
#pragma once

class Array {
private:
    int size;
    std::vector<int> data;
public:

    Array(int n, const int* input) {
        size = n;
        data = std::vector<int>(n);
        for (int i = 0; i < n; ++i) {
            data[i] = input[i];
        }
    }

    int getData(int i) {
        return data[i];
    }

    [[nodiscard]] int getSize() const {
        return size;
    }

    void setData(int i, int x) {
        data[i] = x;
    }

    void swapData(int i, int j) {
        int a = data[i];
        int b = data[j];
        data[i] = b;
        data[j] = a;
    }

    void printData() {
        for (int d : data) {
            std::cout << d << " ";
        }
        std::cout << std::endl;
    }

    void insertFront(int x) {
        std::vector<int> newData = std::vector<int>(size + 1);
        newData[0] = x;
        for (int i = 0; i < size; ++i) {
            newData[i+1] = data[i];
        }
        data = newData;
        size++;
    }

    void insertBack(int x) {
        std::vector<int> newData = std::vector<int>(size + 1);
        newData[size] = x;
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        data = newData;
        size++;
    }

    void insertMid(int i, int x) {
        if (i <= 0) {
            insertFront(x);
        } else if (i >= size) {
            insertBack(x);
        } else {
            std::vector<int> newData = std::vector<int>(size + 1);
            for (int j = 0; j < i; ++j) {
                newData[j] = data[j];
            }
            newData[i] = x;
            for (int j = i; j < size; ++j) {
                newData[j+1] = data[j];
            }
            data = newData;
            size++;
        }
    }

    void deleteFront() {
        std::vector<int> newData = std::vector<int>(size - 1);
        for (int i = 1; i < size; ++i) {
            newData[i-1] = data[i];
        }
        data = newData;
        size--;
    }

    void deleteBack() {
        std::vector<int> newData = std::vector<int>(size - 1);
        for (int i = 0; i < size - 1; ++i) {
            newData[i] = data[i];
        }
        data = newData;
        size--;
    }

    void deleteMid(int i) {
        if (i <= 0) {
            deleteFront();
        } else if (i >= size - 1) {
            deleteBack();
        } else {
            std::vector<int> newData = std::vector<int>(size - 1);
            for (int j = 0; j < i; ++j) {
                newData[j] = data[j];
            }
            for (int j = i+1; j < size; ++j) {
                newData[j-1] = data[j];
            }
            data = newData;
            size--;
        }
    }
};