#include <stdio.h>
#include <stdarg.h>
#include<stdlib.h>
#include<string.h>
// Define a generic lambda type that returns void* and takes a void* argument
typedef void* (*lambda_t)(void*);

// Macro to create a lambda function
#define Lambda(name, arg, body) \
    void* name(void* arg) { body }

// Macro to assign a lambda function to a pointer
#define assign_lambda(lambda_ptr, lambda_func) \
    lambda_ptr = lambda_func

// Example use case function
void abc() {
    // Define a lambda function that adds 5 to an integer
    Lambda(add5, x, return (void*)((intptr_t)x + 5););
    
    // Assign the lambda function to a pointer
    lambda_t p;
    assign_lambda(p, add5);

    // Call the lambda function
    int result = (intptr_t)p((void*)5);
    printf("%d\n", result);
    
    // Define a lambda function that appends " World" to a string
    Lambda(appendWorld, str, 
        char* new_str = (char*)malloc(strlen((char*)str) + 7);
        strcpy(new_str, (char*)str);
        strcat(new_str, " World");
        return new_str;
    );
    
    // Assign the lambda function to a pointer
    assign_lambda(p, appendWorld);

    // Call the lambda function
    char* new_str = (char*)p("Hello");
    printf("%s\n", new_str);
    free(new_str);
}

int main() {
    abc();
    return 0;
}
