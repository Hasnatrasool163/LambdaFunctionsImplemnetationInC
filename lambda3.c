// call back functions usecase

#include <stdio.h>

#define Lambda(ret_type, func_name, param, body) \
    ret_type func_name(int param) { return body; }

#define assign(a, b) \
    a = b;

// Event-driven callback example
void execute_callback(int (*callback)(int), int value) {
    printf("Callback result: %d\n", callback(value));
}

int main() {
    int (*callback)(int);

    // Define a callback lambda
    Lambda(int, event_callback, event, event * 2);
    assign(callback, event_callback);

    // Trigger the callback
    execute_callback(callback, 10); // Output: Callback result: 20

    return 0;
}
