#pragma once
#include <memory>
#include <iostream>

template <class T>
class Array {
private:
    std::shared_ptr<T[]> data;
    size_t size_;
    size_t capacity_;

    void grow() {
        capacity_ *= 2;
        std::shared_ptr<T[]> newdata(new T[capacity_]);
        for (size_t i = 0; i < size_; i++)
            newdata[i] = std::move(data[i]);
        data = newdata;
    }

public:
    Array() : size_(0), capacity_(2) {
        data = std::shared_ptr<T[]>(new T[capacity_]);
    }

    void push_back(const T& value) {
        if (size_ == capacity_) grow();
        data[size_++] = value;
    }

    void erase(size_t index) {
        if (index >= size_) return;
        for (size_t i = index; i + 1 < size_; i++)
            data[i] = std::move(data[i + 1]);
        size_--;
    }

    double total_area() const {
        double s = 0;
        for (size_t i = 0; i < size_; i++)
            s += static_cast<double>(*data[i]);
        return s;
    }

    void print() const {
        for (size_t i = 0; i < size_; i++) {
            data[i]->print();
            std::cout << "Площадь = " << double(*data[i]) << "\n";
        }
    }
};
