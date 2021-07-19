#include <printf.h>
#include <stdlib.h>

#include "debug.h"
#include "genutils.h"

void check_address(void *p) {
    if (p == NULL) {
        printf("ERROR: Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}
