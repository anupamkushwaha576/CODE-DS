#include <stdio.h>

int factorial(int n, int result)
{
    if (n == 0)
        return result;

    return factorial(n - 1, result * n);
}

int main()
{
    int n = 5;

    printf("Factorial = %d", factorial(n, 1));

    return 0;
}
/*int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}*/