#include <stdio.h>

#define Lambda(ret_type, func_name, param, body) \
    ret_type func_name(int param) { return body; }

#define assign(a, b) \
    a = b;

int main() {
    int (*math_func)(int);

    // Addition
    Lambda(int, add, x, x + 10);
    assign(math_func, add);
    printf("Add: %d\n", math_func(5)); // Output: 15

    // Multiplication
    Lambda(int, multiply, y, y * 3);
    assign(math_func, multiply);
    printf("Multiply: %d\n", math_func(5)); // Output: 15

    return 0;
}
