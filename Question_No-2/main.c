#include <stdio.h>

//DYNAMIC PROGRAMMING
int fibonacciDynamic(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 3] + dp[i - 2];

    return dp[n];
}

int main() {
    int n = 10;
    int result = fibonacciDynamic(n);
    printf("F(%d) = %d\n", n, result);

    return 0;
}


//RECURSIVE APPROACH
int fibonacciRecursive(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return fibonacciRecursive(n - 3) + fibonacciRecursive(n - 2);
}

int main() {
    int n = 10;
    int result = fibonacciRecursive(n);
    printf("F(%d) = %d\n", n, result);

    return 0;
}

//MEMOISATION
int fibonacciMemoization(int n, int cache[]) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    if (cache[n] != -1)
        return cache[n];

    cache[n] = fibonacciMemoization(n - 3, cache) + fibonacciMemoization(n - 2, cache);
    return cache[n];
}

int fibonacci(int n) {
    int cache[n + 1];
    for (int i = 0; i <= n; i++)
        cache[i] = -1;

    return fibonacciMemoization(n, cache);
}

int main() {
    int n = 10;
    int result = fibonacci(n);
    printf("F(%d) = %d\n", n, result);

    return 0;
}
