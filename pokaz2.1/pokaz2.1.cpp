#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> getUniqueFromA(int* A, int M, int* B, int N) {
    std::vector<int> result;

    for (int i = 0; i < M; ++i) {
        bool found = false;
        for (int j = 0; j < N; ++j) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found && std::find(result.begin(), result.end(), A[i]) == result.end()) {
            result.push_back(A[i]);
        }
    }

    return result;
}

int main() {
    int M, N;

    std::cout << "розмір масиву A ";
    std::cin >> M;
    int* A = new int[M];
    std::cout << "елементи масиву A ";
    for (int i = 0; i < M; ++i) {
        std::cin >> A[i];
    }

    std::cout << "розмір масиву B ";
    std::cin >> N;
    int* B = new int[N];
    std::cout << "елементи масиву B ";
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }

    std::vector<int> uniqueFromA = getUniqueFromA(A, M, B, N);

    std::cout << "Елементи масиву A, яких немає в масиві B ";
    for (int val : uniqueFromA) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    delete[] A;
    delete[] B;

    return 0;
}
