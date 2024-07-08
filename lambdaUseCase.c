#include "lambda.h"

// Example use case function
void example_use_cases() {
    // Define a lambda function that adds 5 to an integer
    Lambda(add5, x, return (void*)((intptr_t)x + 5););
    
    // Assign the lambda function to a pointer
    lambda_t p;
    assign_lambda(p, add5);

    // Call the lambda function
    int result = (intptr_t)p((void*)5);
    printf("add5: %d\n", result);
    
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
    printf("appendWorld: %s\n", new_str);
    free(new_str);

    // Define a lambda function that squares an integer
    Lambda(square, x, return (void*)((intptr_t)x * (intptr_t)x););
    
    // Assign the lambda function to a pointer
    assign_lambda(p, square);

    // Call the lambda function
    result = (intptr_t)p((void*)6);
    printf("square: %d\n", result);

    // Define a lambda function that concatenates two strings
    Lambda(concatStrings, args, 
        char** strings = (char**)args;
        size_t len = strlen(strings[0]) + strlen(strings[1]) + 1;
        char* result = (char*)malloc(len);
        strcpy(result, strings[0]);
        strcat(result, strings[1]);
        return result;
    );

    // Assign the lambda function to a pointer
    assign_lambda(p, concatStrings);

    // Call the lambda function
    char* strings[2] = { "Hello", " Lambda" };
    new_str = (char*)p((void*)strings);
    printf("concatStrings: %s\n", new_str);
    free(new_str);
}

int main() {
    example_use_cases();
    return 0;
}
