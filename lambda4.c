// shows use case of state machines 

#include <stdio.h>

#define Lambda(ret_type, func_name, param, body) \
    ret_type func_name(int param) { return body; }

#define assign(a, b) \
    a = b;

// Example state machine
typedef enum {
    STATE_IDLE,
    STATE_RUNNING,
    STATE_STOPPED
} State;

void handle_state(int (*state_func)(int), int state) {
    printf("State result: %d\n", state_func(state));
}

int main() {
    int (*state_func)(int);

    // Define state transition functions
    Lambda(int, idle_state, s, s == STATE_IDLE ? 1 : 0);
    Lambda(int, running_state, s, s == STATE_RUNNING ? 1 : 0);
    Lambda(int, stopped_state, s, s == STATE_STOPPED ? 1 : 0);

    // Handle different states
    assign(state_func, idle_state);
    handle_state(state_func, STATE_IDLE); // Output: State result: 1

    assign(state_func, running_state);
    handle_state(state_func, STATE_RUNNING); // Output: State result: 1

    assign(state_func, stopped_state);
    handle_state(state_func, STATE_STOPPED); // Output: State result: 1

    return 0;
}
