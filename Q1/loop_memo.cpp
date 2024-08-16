#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<long long> memo(51, -1);

long long loop_fib_memo(int n)
{
    if (n <= 1)
    {
        return n;
    }

    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[n];
}

int main()
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < 50; i++)
    {
        cout << loop_fib_memo(i) << " ";
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_taken = ((end.tv_sec - start.tv_sec) * 1e9) + (end.tv_nsec - start.tv_nsec) * 1e-9;

    cout << "\nTime taken by memoized loop: " << time_taken << " seconds" << endl;

    return 0;
}