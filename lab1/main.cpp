#include <iostream>
#include <vector>
#include <string>

void qsortRecursive(std::vector<std::string>& mas, int size, size_t index) {
    int i = 0;
    int j = size - 1;

    char mid = mas[size / 2][index];

    do {
        while (mas[i][index] < mid) {
            i++;
        }

        while (mas[j][index] > mid) {
            j--;
        }

        if (i <= j) {
            std::swap(mas[i], mas[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        qsortRecursive(mas, j + 1, index);
    }
    if (i < size) {
        qsortRecursive(mas, size - i, index);
    }
}

int main() {

    std::string in;

    std::vector<std::string> data;

    while (getline(std::cin, in)) {
        data.push_back(in);
    }

    for (size_t i = 0; i < 8; i++) {

        if (i != 1 && i != 5) {

            qsortRecursive(data, data.size(), i);

        }
    }
    
    for (size_t i = 0; i < data.size(); i++) {
        std::cout << data[i] << std::endl;
    }
}