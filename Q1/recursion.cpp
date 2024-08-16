#include <iostream>
#include <ctime>

using namespace std;

long long
recursive_fib(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return recursive_fib(n - 1) + recursive_fib(n - 2);
}

int main()
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < 50; i++)
    {
        cout << recursive_fib(i) << " ";
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_taken = ((end.tv_sec - start.tv_sec) * 1e9) + (end.tv_nsec - start.tv_nsec) * 1e-9;

    cout << "\nTime taken by recursion: " << time_taken << " seconds" << endl;

    return 0;
}
