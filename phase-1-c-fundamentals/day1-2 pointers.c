#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // Basic pointer
    int x = 5;
    int *ptr = &x;
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", &x);
    printf("ptr holds: %p\n", ptr);
    printf("Value at ptr: %d\n", *ptr);
    *ptr = 99;
    printf("x is now: %d\n", x);

    // Pointer arithmetic
    int arr[5] = {10, 20, 30, 40, 50};
    int *aptr = arr;
    for (int i = 0; i < 5; i++) {
        printf("address: %p, value: %d\n", (aptr+i), *(aptr+i));
    }

    // Pointer to pointer
    int **pp = &ptr;
    printf("pp holds: %p\n", pp);
    printf("*pp = %p\n", *pp);
    printf("**pp = %d\n", **pp);

    // Swap
    int m = 5, n = 10;
    printf("Before swap: m = %d, n = %d\n", m, n);
    swap(&m, &n);
    printf("After swap:  m = %d, n = %d\n", m, n);

    return 0;
}