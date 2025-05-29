#include <iostream>
#include <iomanip>
#include "evaluation.h"


int main() {
    std::cout << std::fixed << std::setprecision(4); // красивый вывод
    for (int n = 2; n <= 10; ++n) {
        auto [mean, stddev] = Evaluation::evaluateApproximation(n, 100);
        std::cout << "N: " << n << " | Среднее: " << mean << " | Дисперсия: " << stddev << "\n";
    }

    return 0;
}