#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::string;

double FunctionFromTask(double x) {
    return -sqrt(x) * std::sin(x) + 2;
}

const double LOWER_EDGE = 1.;
const double UPPER_EDGE = 4.;

void Dependence() {
    cout << "Part 1. Dependence N of P and q :\n+"
         << std::string(7, '-') << '+';
    for (size_t i = 0; i < 10; ++i) {
        cout << std::string(6, '-') << '+';
    }
    cout
            << "\n|  q\\P  |  0.9 | 0.91 | 0.92 | 0.93 | 0.94 "
               "| 0.95 | 0.96 | 0.97 | 0.98 | 0.99 |\n+"
            << std::string(7, '-') << "+";
    for (size_t i = 0; i < 10; ++i) {
        cout << std::string(6, '-') << '+';
    }
    cout << '\n';
    for (double q = 0.005; q <= 0.1;) {
        cout << "| " << q << "\t|";
        for (double P = 0.9; P < 0.995;) {
            cout << std::setw(5) << ceil(log(1 - P) / log(1 - q))
                 << " |";
            P += 0.01;
        }
        cout << '\n';
        q += 0.005;
    }
    cout << '+' << std::string(7, '-') << '+';
    for (size_t i = 0; i < 10; ++i) {
        cout << std::string(6, '-') << '+';
    }
    cout << "\n\n";
}

double GetMinimum(const size_t &N, const string &FunctionType) {
    srand(time(nullptr));
    vector<double> VectorOfY;
    for (size_t i = 0; i < N; ++i) {
        double x = LOWER_EDGE + (UPPER_EDGE - 1) * rand() / (float) RAND_MAX;
        if (FunctionType == "unimodal")
            VectorOfY.push_back(FunctionFromTask(x));
        else if (FunctionType == "multimodal")
            VectorOfY.push_back(FunctionFromTask(x) * std::sin(5 * x));
    }
    return *min_element(VectorOfY.begin(), VectorOfY.end());
}

void SearchMinimumOfFunction(const string &FunctionType) {
    cout << '+' << std::string(7, '-') << '+';
    for (size_t i = 0; i < 10; ++i) {
        cout << std::string(10, '-') << '+';
    }
    cout << "\n|  q\\P  |    0.9   |   0.91   |   0.92   |   0.93   |"
            "   0.94   |   0.95   |   0.96   |   0.97   |   0.98   |   0.99   "
            "|\n+"
         << std::string(7, '-') << "+";
    for (size_t i = 0; i < 10; ++i) {
        cout << std::string(10, '-') << '+';
    }
    cout << '\n';
    for (double q = 0.005; q <= 0.1;) {
        cout << "| " << q << "\t|";
        for (double P = 0.9; P < 0.995;) {
            size_t N = ceil(log(1 - P) / log(1 - q));
            cout << std::setw(9) << GetMinimum(N, FunctionType) << " |";
            P += 0.01;
        }
        cout << '\n';
        q += 0.005;
    }
    cout << '+' << std::string(7, '-') << '+';
    for (size_t i = 0; i < 10; ++i) {
        cout << std::string(10, '-') << '+';
    }
    cout << "\n\n";
}

int main() {
    cout << "Variant 7: \t -sqrt(x) * sin(x) + 2 \t [" << LOWER_EDGE << "; "
         << UPPER_EDGE << "]\n";
    Dependence();
    cout << "Part 2. Search for the extremum of a unimodal function f(x) :\n";
    SearchMinimumOfFunction("unimodal");
    cout
            << "Part 2. Search for the extremum of a multimodal function "
               "f(x) * sin(5x) :\n";
    SearchMinimumOfFunction("multimodal");
    return 0;
}
