#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libtcc.h" // Assuming libtcc.h is in your include path

int main()
{
    TCCState *s;
    const char *program = 
        "int add(int a, int b) { return a + b; }\n"
        "int main() { return add(5, 7); }"; // Simple C program

    // Create a new TCC compilation state
    s = tcc_new();
    if (!s)
    {
        fprintf(stderr, "Could not create TCC state\n");
        return 1;
    }

    // Set output type to memory (TCC_OUTPUT_MEMORY)
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    // Compile the C program string
    if (tcc_compile_string(s, program) < 0)
    {
        fprintf(stderr, "Could not compile program\n");
        tcc_delete(s);
        return 1;
    }

    // Relocate the code in memory
    if (tcc_relocate(s) < 0)
    {
        fprintf(stderr, "Could not relocate code\n");
        tcc_delete(s);
        return 1;
    }

    // Get a pointer to the 'main' function
    int (*main_func)(void);
    using ftpr_t = int (*)(void);
    main_func = (ftpr_t)tcc_get_symbol(s, "main");

    if (!main_func)
    {
        fprintf(stderr, "Could not find 'main' symbol\n");
        tcc_delete(s);
        return 1;
    }

    // Execute the compiled 'main' function
    int result = main_func();
    printf("Result of compiled code: %d\n", result); // Expected: 12

    // Delete the TCC compilation state
    tcc_delete(s);

    return 0;
}