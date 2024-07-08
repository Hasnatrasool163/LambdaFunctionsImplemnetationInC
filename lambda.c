#include <stdio.h>

// Lambda macro to create a named lambda function with a unique name
#define Lambda(ret_type, func_name, param, body) \
    ret_type func_name(int param) { return body; }

// Assign macro to assign the lambda function to a function pointer
#define assign(a, b) \
    a = b;

void abc() {}

int main() {
    // Function pointer declaration
    int (*p)(int);

    // Lambda function creation and assignment
    Lambda(int, lambda1, x, x + 5);
    assign(p, lambda1);

    printf("%d\n", p(5));

    // Another lambda example
    Lambda(int, lambda2, y, y * 2);
    assign(p, lambda2);

    printf("%d\n", p(5));

    return 0;
}
