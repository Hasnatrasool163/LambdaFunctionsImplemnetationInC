#ifndef LAMBDA_H
#define LAMBDA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define a generic lambda type that returns void* and takes a void* argument
typedef void* (*lambda_t)(void*);

// Macro to create a lambda function
#define Lambda(name, arg, body) \
    void* name(void* arg) { body }

// Macro to assign a lambda function to a pointer
#define assign_lambda(lambda_ptr, lambda_func) \
    lambda_ptr = lambda_func

#endif // LAMBDA_H
