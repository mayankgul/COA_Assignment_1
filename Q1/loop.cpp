#include <iostream>
#include <ctime>

using namespace std;

long long iterative_fib(int n)
{
    if (n <= 1)
        return n;

    long long a = 0, b = 1, c;

    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main()
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < 50; i++)
    {
        cout << iterative_fib(i) << " ";
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_taken = ((end.tv_sec - start.tv_sec) * 1e9) + (end.tv_nsec - start.tv_nsec) * 1e-9;

    cout << "\nTime taken by loop: " << time_taken << " seconds" << endl;

    return 0;
}