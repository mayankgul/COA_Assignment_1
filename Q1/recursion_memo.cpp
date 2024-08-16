#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<long long> memo(51, -1);

long long recursive_fib_memo(int n)
{
    if (n <= 1)
        return n;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = recursive_fib_memo(n - 1) + recursive_fib_memo(n - 2);

    return memo[n];
}

int main()
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < 50; i++)
    {
        cout << recursive_fib_memo(i) << " ";
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_taken = ((end.tv_sec - start.tv_sec) * 1e9) + (end.tv_nsec - start.tv_nsec) * 1e-9;

    cout << "\nTime taken by memoized recursion: " << time_taken << " seconds" << endl;

    return 0;
}