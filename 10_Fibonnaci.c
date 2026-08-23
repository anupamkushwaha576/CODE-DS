#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) 
        return n;   // base case
    return fibonacci(n - 1) + fibonacci(n - 2);  // recursive case
}

int main() {
    int n, i;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci sequence: ");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    return 0;
}
