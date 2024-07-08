#ifndef LAMBDA_H
#define LAMBDA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include<pthread.h>


// summarized list of all of the macros defined in the lambda.h

/**
 * Lambda Functions:
 *
 * Lambda(name, arg, body): Defines a lambda function in C.
 * assign_lambda(lambda_ptr, lambda_func): Assigns a lambda function to a pointer.
 */

/**
 * Error Handling:
 *
 * HANDLE_ERROR(msg): Handles fatal errors with a message and exits.
 * HANDLE_FILE_ERROR(filename): Handles file I/O errors.
 * HANDLE_NETWORK_ERROR(msg): Handles network errors.
 * HANDLE_MEMORY_ERROR(msg): Handles memory allocation errors.
 * HANDLE_NULL_POINTER(ptr, msg): Handles null pointer errors with a message.
 */

/**
 * File I/O:
 *
 * HANDLE_FILE_OPEN(filename, mode): Opens a file with error checking.
 * HANDLE_FILE_CLOSE(fp): Safely closes a file pointer.
 */

/**
 * Logging:
 *
 * LOG_WARNING(msg): Logs warning messages.
 * LOG_ERROR(msg): Logs error messages.
 * LOG_INFO(msg): Logs informational messages.
 */

/**
 * Memory Management:
 *
 * SAFE_MALLOC(size): Safely allocates memory.
 * SAFE_FREE(ptr): Safely frees allocated memory.
 * SAFE_STRDUP(str): Safely duplicates a string.
 * SAFE_STRCAT(dest, src): Safely concatenates strings.
 * SAFE_STRLEN(str): Safely calculates the length of a string.
 */

/**
 * Utility:
 *
 * SAFE_CAST(type, ptr): Type-safe casting.
 * LOG(msg): Logs messages to stderr.
 */

/**
 * Dynamic Array:
 *
 * DYNAMIC_ARRAY_CREATE(type): Creates a dynamic array of specified type.
 * DYNAMIC_ARRAY_FREE(array): Frees memory allocated for a dynamic array.
 * DYNAMIC_ARRAY_GET(array, index): Retrieves an element from a dynamic array.
 * DYNAMIC_ARRAY_SET(array, index, value): Sets an element in a dynamic array.
 * DYNAMIC_ARRAY_SIZE(array): Returns the size of a dynamic array.
 * DYNAMIC_ARRAY_RESIZE(array, new_size): Resizes a dynamic array to a new size.
 */

/**
 * Advanced Logging:
 *
 * compose_lambda(name, first, second): Composes lambda functions with error handling.
 * compose_lambda_recursive(arg, second, ...): Recursively composes lambda functions.
 */

/**
 * Additional Macros:
 *
 * VALIDATE_INPUT(ptr, msg): Validates input pointers.
 * VALIDATE_NOT_NULL(ptr, msg): Validates non-null pointers.
 * SAFE_FILE_CLOSE(fp): Safely closes file pointers.
 * HANDLE_NETWORK_STATUS(result, msg): Handles network status results.
 * CLEANUP_ON_ERROR(ptr, msg, ret_value): Cleans up resources on error.
 * CHECK_INT_OVERFLOW(op1, op2): Checks for integer overflow.
 * VALIDATE_INT_RANGE(num, min, max, msg): Validates integers within a specified range.
 * CHECK_DIVISION_BY_ZERO(op): Checks for division by zero errors.
 */

/**
 * Concurrency and Synchronization:
 *
 * LOCK_MUTEX(mutex): Locks mutexes.
 * UNLOCK_MUTEX(mutex): Unlocks mutexes.
 */

/**
 * Configuration:
 *
 * DEBUG_LOGGING(msg): Debug logging (enabled only in DEBUG mode).
 * HANDLE_INVALID_ARGUMENT(arg, msg): Handles invalid argument errors with a message.
 */




/**
 * @file lambda.h
 * @brief Header file for creating and using lambda functions in C with safety features.
 */

/********************* Type Definitions and Macros ***************************/

/**
 * @brief Define a generic lambda function type.
 *
 * A lambda function in C returns void* and takes a void* argument.
 */
typedef void* (*lambda_t)(void*);

/**
 * @brief Macro to define a lambda function.
 *
 * @param name The name of the lambda function.
 * @param arg The argument name of the lambda function.
 * @param body The body of the lambda function.
 *
 * Example usage:
 * ```
 * Lambda(add5, x, return (void*)((intptr_t)x + 5););
 * ```
 */
#define Lambda(name, arg, body) \
    void* name(void* arg) { body }

/**
 * @brief Macro to assign a lambda function to a pointer.
 *
 * @param lambda_ptr The lambda pointer to assign the lambda function.
 * @param lambda_func The lambda function to assign.
 *
 * Example usage:
 * ```
 * lambda_t p;
 * assign_lambda(p, add5);
 * ```
 */
#define assign_lambda(lambda_ptr, lambda_func) \
    lambda_ptr = lambda_func

/********************* Error Handling Macros ***************************/

/**
 * @brief Macro for handling fatal errors with a message and exit.
 *
 * @param msg The error message.
 *
 * Example usage:
 * ```
 * HANDLE_ERROR("Memory allocation failed");
 * ```
 */
#define HANDLE_ERROR(msg) \
    do { fprintf(stderr, "Error: %s\n", msg); exit(EXIT_FAILURE); } while (0)

/**
 * @brief Macro for file I/O error handling.
 *
 * @param filename The name of the file causing the error.
 *
 * Example usage:
 * ```
 * FILE* fp = fopen("file.txt", "r");
 * if (!fp) {
 *     HANDLE_FILE_ERROR("file.txt");
 * }
 * ```
 */
#define HANDLE_FILE_ERROR(filename) \
    do { perror(filename); exit(EXIT_FAILURE); } while (0)

/**
 * @brief Macro for network error handling.
 *
 * @param msg The network error message.
 *
 * Example usage:
 * ```
 * int result = connect_to_server();
 * if (result == -1) {
 *     HANDLE_NETWORK_ERROR("Failed to connect to server");
 * }
 * ```
 */
#define HANDLE_NETWORK_ERROR(msg) \
    do { fprintf(stderr, "Network error: %s\n", msg); exit(EXIT_FAILURE); } while (0)

/**
 * @brief Macro for handling memory allocation errors.
 *
 * @param msg The memory allocation error message.
 *
 * Example usage:
 * ```
 * void* ptr = malloc(size);
 * if (!ptr) {
 *     HANDLE_MEMORY_ERROR("Memory allocation failed");
 * }
 * ```
 */
#define HANDLE_MEMORY_ERROR(msg) \
    do { \
        LOG_ERROR(msg); \
        exit(EXIT_FAILURE); \
    } while (0)

/**
 * @brief Handles null pointer errors with a message.
 *
 * @param ptr The pointer to check.
 * @param msg The error message to log if the pointer is null.
 *
 * Example usage:
 * ```
 * char* ptr = NULL;
 * HANDLE_NULL_POINTER(ptr, "Null pointer encountered");
 * // Handle the error condition
 * ```
 */
#define HANDLE_NULL_POINTER(ptr, msg) \
    do { \
        if (!(ptr)) { \
            fprintf(stderr, "Null Pointer Error: %s\n", msg); \
        } \
    } while (0)



/********************* I/O Macros ***************************/


/**
 * @brief Macro for handling file opening with error checking.
 *
 * @param filename The name of the file to open.
 * @param mode The mode in which to open the file ("r", "w", etc.).
 *
 * @return Returns a FILE pointer if successful; otherwise, handles the file error.
 *
 * Example usage:
 * ```
 * FILE* fp = HANDLE_FILE_OPEN("file.txt", "r");
 * if (!fp) {
 *     // Handle file open error
 * }
 * ```
 */
#define HANDLE_FILE_OPEN(filename, mode) \
    ({ \
        FILE* fp = fopen(filename, mode); \
        if (!fp) { \
            HANDLE_FILE_ERROR(filename); \
        } \
        fp; \
    })

/**
 * @brief Macro for safely closing file pointers.
 *
 * @param fp The FILE pointer to close.
 *
 * Example usage:
 * ```
 * FILE* fp = fopen("file.txt", "r");
 * if (fp) {
 *     // Perform operations with the file
 *     HANDLE_FILE_CLOSE(fp);
 * }
 * ```
 */
#define HANDLE_FILE_CLOSE(fp) \
    do { \
        if (fp) { \
            fclose(fp); \
            fp = NULL; \
        } \
    } while (0)

/********************* Logging Macros ***************************/

/**
 * @brief Macro for logging warnings.
 *
 * @param msg The warning message.
 *
 * Example usage:
 * ```
 * LOG_WARNING("This is a warning message");
 * ```
 */
#define LOG_WARNING(msg) \
    do { \
        fprintf(stderr, "[WARNING] %s\n", msg); \
    } while (0)

/**
 * @brief Macro for logging errors.
 *
 * @param msg The error message.
 *
 * Example usage:
 * ```
 * LOG_ERROR("This is an error message");
 * ```
 */
#define LOG_ERROR(msg) \
    do { \
        fprintf(stderr, "[ERROR] %s\n", msg); \
    } while (0)

/**
 * @brief Macro for logging informational messages.
 *
 * @param msg The informational message.
 *
 * Example usage:
 * ```
 * LOG_INFO("This is an informational message");
 * ```
 */
#define LOG_INFO(msg) \
    do { \
        fprintf(stdout, "[INFO] %s\n", msg); \
    } while (0)


/********************* Memory Management Macros ***************************/

/**
 * @brief Macro for safe memory allocation with error handling.
 *
 * @param size The size of memory to allocate.
 * @return void* Pointer to the allocated memory.
 *
 * Example usage:
 * ```
 * char* str = "Hello";
 * char* new_str = SAFE_STRDUP(str);
 * ```
 */
#define SAFE_MALLOC(size) \
    ({ \
        void* ptr = malloc(size); \
        if (!ptr) HANDLE_ERROR("Memory allocation failed"); \
        ptr; \
    })

/**
 * @brief Macro for safe memory freeing.
 *
 * @param ptr The pointer to free.
 *
 * Example usage:
 * ```
 * SAFE_FREE(ptr);
 * ```
 */
#define SAFE_FREE(ptr) \
    do { \
        if (ptr) { \
            free(ptr); \
            ptr = NULL; \
        } \
    } while (0)

/********************* String Manipulation Macros ***************************/

/**
 * @brief Macro for safe string duplication with memory allocation and error handling.
 *
 * @param str The string to duplicate.
 * @return char* Pointer to the duplicated string.
 *
 * Example usage:
 * ```
 * char* str = "Hello";
 * char* new_str = SAFE_STRDUP(str);
 * ```
 */
#define SAFE_STRDUP(str) \
    ({ \
        char* new_str = SAFE_MALLOC(strlen(str) + 1); \
        strcpy(new_str, str); \
        new_str; \
    })

/**
 * @brief Macro for safe string concatenation with memory allocation and error handling.
 *
 * @param dest The destination string.
 * @param src The source string to concatenate.
 * @return char* Pointer to the concatenated string.
 *
 * Example usage:
 * ```
 * char* str1 = "Hello";
 * char* str2 = " World";
 * char* new_str = SAFE_STRCAT(str1, str2);
 * ```
 */
#define SAFE_STRCAT(dest, src) \
    ({ \
        size_t dest_len = strlen(dest); \
        size_t src_len = strlen(src); \
        char* new_str = SAFE_MALLOC(dest_len + src_len + 1); \
        strcpy(new_str, dest); \
        strcat(new_str, src); \
        new_str; \
    })


/**
 * @brief Safely calculates the length of a string.
 *
 * @param str The string to measure.
 *
 * @return Returns the length of the string.
 *
 * Example usage:
 * ```
 * size_t length = SAFE_STRLEN("hello");
 * ```
 */
#define SAFE_STRLEN(str) \
    ({ \
        size_t length = strlen(str); \
        length; \
    })

/********************* Utility Macros ***************************/

/**
 * @brief Macro for type-safe casting.
 *
 * @param type The type to cast to.
 * @param ptr The pointer to cast.
 * @return type* Pointer to the casted type.
 *
 * Example usage:
 * ```
 * int* intptr = (int*) ptr;
 * int* casted_ptr = SAFE_CAST(int*, ptr);
 * ```
 */
#define SAFE_CAST(type, ptr) ((type)(ptr))

/********************* Advanced Logging Macros ***************************/

/**
 * @brief Logging macro to print messages to stderr.
 *
 * @param msg The message to log.
 *
 * Example usage:
 * ```
 * LOG("Error: File not found");
 * ```
 */
#define LOG(msg) \
    fprintf(stderr, "%s\n", msg)

/********************* Function Composition Macros ***************************/

/**
 * @brief Macro for lambda function composition with error handling.
 *
 * Composes two lambda functions where the result of the first is passed as
 * input to the second. Provides error handling for NULL returns from the first function.
 *
 * @param name The name of the composed lambda function.
 * @param first The first lambda function.
 * @param second The second lambda function.
 *
 * Example usage:
 * ```
 * compose_lambda(add5AndAppend, add5, appendWorld);
 * ```
 */
#define compose_lambda(name, first, second) \
    void* name(void* arg) { \
        void* temp = first(arg); \
        if (!temp) { \
            LOG("Error: First lambda function returned NULL."); \
            return NULL; \
        } \
        void* result = second(temp); \
        SAFE_FREE(temp); \
        return result; \
    }

/**
 * @brief Helper macro for variadic composition of lambda functions.
 *
 * Recursively composes multiple lambda functions.
 *
 * @param arg The argument passed through the composition.
 * @param second The next lambda function to apply.
 * @param ... Additional lambda functions to compose.
 * @return void* The result of the composition.
 */
#define compose_lambda_recursive(arg, second, ...) \
    second(arg) ? compose_lambda_recursive(arg, __VA_ARGS__) : arg

/********************* Additional Macros ***************************/

/**
 * @brief Macro for input validation, checks if pointer is NULL and logs error message.
 *
 * @param ptr The pointer to validate.
 * @param msg The error message to log.
 *
 * Example usage:
 * ```
 * VALIDATE_INPUT(ptr, "Error: Null pointer detected");
 * ```
 */
#define VALIDATE_INPUT(ptr, msg) \
    do { \
        if (!(ptr)) { \
            LOG(msg); \
            return NULL; \
        } \
    } while (0)

/**
 * @brief Macro to validate if a pointer is not null.
 *
 * @param ptr The pointer to validate.
 * @param msg The error message to log if validation fails.
 *
 * @return Returns NULL if the pointer is null.
 *
 * Example usage:
 * ```
 * char* str = NULL;
 * VALIDATE_NOT_NULL(str, "Pointer 'str' is null");
 * // Code continues if 'str' is not null
 * ```
 */
#define VALIDATE_NOT_NULL(ptr, msg) \
    do { \
        if (!(ptr)) { \
            LOG_ERROR(msg); \
            return NULL; \
        } \
    } while (0)



/**
 * @brief Macro for safe closure of file pointers.
 *
 * @param fp The file pointer to close.
 *
 * Example usage:
 * ```
 * SAFE_FILE_CLOSE(fp);
 * ```
 */
#define SAFE_FILE_CLOSE(fp) \
    do { \
        if (fp) { \
            fclose(fp); \
            fp = NULL; \
        } \
    } while (0)

/**
 * @brief Macro for handling network status results.
 *
 * @param result The network result to check.
 * @param msg The error message to print on failure.
 *
 * Example usage:
 * ```
 * HANDLE_NETWORK_STATUS(result, "Failed to perform network operation");
 * ```
 */
#define HANDLE_NETWORK_STATUS(result, msg) \
    do { \
        if (result < 0) { \
            fprintf(stderr, "Network error: %s\n", msg); \
            exit(EXIT_FAILURE); \
        } \
    } while (0)

/**
 * @brief Macro for cleaning up resources on error, including freeing allocated memory.
 *
 * @param ptr The pointer to clean up.
 * @param msg The error message to log.
 * @param ret_value The return value in case of error.
 *
 * Example usage:
 * ```
 * CLEANUP_ON_ERROR(fp, "Error: Failed to open file.", EXIT_FAILURE);
 * ```
 */
#define CLEANUP_ON_ERROR(ptr, msg, ret_value) \
    do { \
        if (!(ptr)) { \
            LOG(msg); \
            SAFE_FREE(ptr); \
            return (ret_value); \
        } \
    } while (0)

/**
 * @brief Macro for checking integer overflow.
 *
 * @param op1 The first integer operand.
 * @param op2 The second integer operand.
 *
 * Example usage:
 * ```
 * intptr_t result = CHECK_INT_OVERFLOW(op1, op2);
 * ```
 */
#define CHECK_INT_OVERFLOW(op1, op2) \
    ({ \
        intptr_t result = (op1) + (op2); \
        if (((op1) > 0 && (op2) > 0 && result < 0) || ((op1) < 0 && (op2) < 0 && result > 0)) { \
            HANDLE_ERROR("Integer overflow detected"); \
        } \
        result; \
    })

/**
 * @brief Macro for validating an integer within a specified range.
 *
 * @param num The integer to validate.
 * @param min The minimum allowed value (inclusive).
 * @param max The maximum allowed value (inclusive).
 * @param msg The error message to log if validation fails.
 *
 * Example usage:
 * ```
 * VALIDATE_INT_RANGE(age, 18, 120, "Age must be between 18 and 120");
 * ```
 */
#define VALIDATE_INT_RANGE(num, min, max, msg) \
    do { \
        if ((num) < (min) || (num) > (max)) { \
            LOG(msg); \
            return NULL; \
        } \
    } while (0)


/**
 * @brief Checks for division by zero errors.
 *
 * @param op The operand to check for zero.
 *
 * Example usage:
 * ```
 * int divisor = 0;
 * CHECK_DIVISION_BY_ZERO(divisor);
 * // Handle division operation safely
 * ```
 */
#define CHECK_DIVISION_BY_ZERO(op) \
    do { \
        if ((op) == 0) { \
            LOG_ERROR("Division by zero error"); \
        } \
    } while (0)

/********************* Dynamic Array Macros ***************************/

/**
 * @brief Macro for creating a dynamically resizing array.
 *
 * @param type The type of elements in the array.
 *
 * Example usage:
 * ```
 * DYNAMIC_ARRAY(int);
 * ```
 */
#define DYNAMIC_ARRAY(type) \
    struct { \
        type* array; \
        size_t size; \
        size_t capacity; \
    }

/**
 * @brief Macro for initializing a dynamically resizing array.
 *
 * @param arr The dynamic array to initialize.
 *
 * Example usage:
 * ```
 * INIT_DYNAMIC_ARRAY(arr);
 * ```
 */
#define INIT_DYNAMIC_ARRAY(arr) \
    do { \
        (arr).array = NULL; \
        (arr).size = 0; \
        (arr).capacity = 0; \
    } while (0)

/**
 * @brief Macro for adding an element to a dynamically resizing array.
 *
 * @param arr The dynamic array.
 * @param element The element to add.
 *
 * Example usage:
 * ```
 * ADD_TO_DYNAMIC_ARRAY(arr, element);
 * ```
 */
#define ADD_TO_DYNAMIC_ARRAY(arr, element) \
    do { \
        if ((arr).size >= (arr).capacity) { \
            (arr).capacity = ((arr).capacity == 0) ? 1 : (arr).capacity * 2; \
            (arr).array = SAFE_REALLOC((arr).array, (arr).capacity * sizeof((arr).array[0])); \
        } \
        (arr).array[(arr).size++] = element; \
    } while (0)

/**
 * @brief Macro for accessing an element in a dynamically resizing array.
 *
 * @param arr The dynamic array.
 * @param index The index of the element to access.
 *
 * @return The element at the specified index.
 *
 * Example usage:
 * ```
 * int element = ACCESS_DYNAMIC_ARRAY(arr, index);
 * ```
 */
#define ACCESS_DYNAMIC_ARRAY(arr, index) \
    ((index < (arr).size) ? (arr).array[index] : (HANDLE_ERROR("Index out of bounds"), (arr).array[0]))

/**
 * @brief Macro for freeing the memory used by a dynamically resizing array.
 *
 * @param arr The dynamic array to free.
 *
 * Example usage:
 * ```
 * FREE_DYNAMIC_ARRAY(arr);
 * ```
 */
#define FREE_DYNAMIC_ARRAY(arr) \
    do { \
        SAFE_FREE((arr).array); \
        (arr).size = 0; \
        (arr).capacity = 0; \
    } while (0)


//********************* Concurrency and Synchronization Macros ***************************/

/**
 * @brief Macro for defining a mutex.
 *
 * @param mutex The name of the mutex variable.
 *
 * Example usage:
 * ```
 * DEFINE_MUTEX(my_mutex);
 * ```
 */
#define DEFINE_MUTEX(mutex) \
    pthread_mutex_t mutex

/**
 * @brief Macro for locking mutexes.
 *
 * @param mutex_ptr Pointer to the mutex variable to lock.
 *
 * Example usage:
 * ```
 * LOCK_MUTEX(&my_mutex);
 * ```
 */
#define LOCK_MUTEX(mutex_ptr) \
    do { \
        if (pthread_mutex_lock(mutex_ptr) != 0) { \
            HANDLE_ERROR("Failed to acquire mutex lock"); \
        } \
    } while (0)

/**
 * @brief Macro for unlocking mutexes.
 *
 * @param mutex_ptr Pointer to the mutex variable to unlock.
 *
 * Example usage:
 * ```
 * UNLOCK_MUTEX(&my_mutex);
 * ```
 */
#define UNLOCK_MUTEX(mutex_ptr) \
    do { \
        if (pthread_mutex_unlock(mutex_ptr) != 0) { \
            HANDLE_ERROR("Failed to release mutex lock"); \
        } \
    } while (0)

/********************* Configuration Macros ***************************/

/**
 * @brief Handles invalid argument errors with a message.
 *
 * @param arg The argument to check.
 * @param msg The error message to log if the argument is invalid.
 *
 * Example usage:
 * ```
 * int value = -1;
 * HANDLE_INVALID_ARGUMENT(value >= 0, "Value must be non-negative");
 * // Continue processing if argument is valid
 * ```
 */
#define HANDLE_INVALID_ARGUMENT(arg, msg) \
    do { \
        if (!(arg)) { \
            fprintf(stderr, "Invalid Argument Error: %s\n", msg); \
        } \
    } while (0)

#ifdef DEBUG
/**
 * @brief Macro for debug logging.
 *
 * @param msg The debug message to log.
 *
 * Example usage:
 * ```
 * DEBUG_LOGGING("Debug message");
 * ```
 */
#define DEBUG_LOGGING(msg) \
    do { \
        fprintf(stdout, "[DEBUG] %s\n", msg); \
    } while (0)
#else
#define DEBUG_LOGGING(msg)
#endif


#endif /* LAMBDA_H */
