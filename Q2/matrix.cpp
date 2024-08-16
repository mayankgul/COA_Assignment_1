#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

template <typename T>
void matrix_multiply(const vector<vector<T>> &A, const vector<vector<T>> &B, vector<vector<T>> &C, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

template <typename T>
void run_test(int N)
{
    vector<vector<T>> A(N, vector<T>(N));
    vector<vector<T>> B(N, vector<T>(N));
    vector<vector<T>> C(N, vector<T>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = static_cast<T>(i + j);
            B[i][j] = static_cast<T>(i - j);
        }
    }

    auto start = chrono::high_resolution_clock::now();
    matrix_multiply(A, B, C, N);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = end - start;
    cout << "Time taken for " << typeid(T).name() << " matrix multiplication for N = " << N << ": " << elapsed.count() << " seconds" << endl;
}

int main()
{
    int sizes[] = {64, 128, 256, 512, 1024};

    for (int N : sizes)
    {
        run_test<int>(N);
        run_test<double>(N);
    }

    return 0;
}