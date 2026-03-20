#include <stdio.h>
#include <stdlib.h>

int global = 100;

void foo() {
    int local = 42;
    printf("local address:  %p\n", (void*)&local);
    printf("global address: %p\n", (void*)&global);
}

void bar() {
    int a = 1, b = 2, c = 3;
    printf("a: %p\n", (void*)&a);
    printf("b: %p\n", (void*)&b);
    printf("c: %p\n", (void*)&c);
}

int main() {
    foo();
    bar();

    // Heap allocation
    int *ptr = malloc(sizeof(int));
    *ptr = 42;
    printf("heap value: %d\n", *ptr);
    printf("heap address: %p\n", (void*)ptr);
    free(ptr);
    ptr = NULL;

    return 0;
}