import time


def matrix_multiply(A, B, N):
    C = [[0 for _ in range(N)] for _ in range(N)]

    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][j] += A[i][k] * B[k][j]

    return C


def run_test(N, datatype):
    A = [[datatype(i + j) for j in range(N)] for i in range(N)]
    B = [[datatype(i - j) for j in range(N)] for i in range(N)]

    start = time.time()
    C = matrix_multiply(A, B, N)
    end = time.time()

    print(
        f"Time taken for {datatype.__name__} matrix multiplication for N = {N}: {end - start} seconds"
    )


sizes = [64, 128, 256, 512, 1024]

for N in sizes:
    run_test(N, int)
    run_test(N, float)
