#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sstrings.h"

int main() {
    SString *sstr = CStringToSSTring("foo bars");
    char *cstr = SStringToCString(sstr);
    
    if (strlen(cstr) != 8) {
        printf("Not Ok CStr len, %li\n", strlen(cstr));
        return 0;
    }
    printf("Ok \"%s\" len, %li\n", cstr, strlen(cstr));

    if (strcmp(cstr, "foo bars") != 0) {
        printf("CStr should be \"foo bars\", but is %s\n", cstr);
        return 0;
    }

    if (cstr[8] != '\0') {
        printf("cstr[8] should be '\n'\n");
        return 0;
    }
    printf("Ok cstr[8] == '\\0'\n");

    return 1;
}