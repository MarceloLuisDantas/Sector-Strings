#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sstrings.h"

int main() {
    SString *sstr = CStringToSSTring("foo bars");
    char *cstr = SStringToCString(sstr);
    printf("%s\n", cstr);
    if (strlen(cstr) != 8) {
        printf("Not Ok CStr len, %i\n", strlen(cstr));
        return 0;
    }
    printf("Ok \"%s\" len, %i\n", cstr, strlen(cstr));

    if (cstr[8] != '\0') {
        printf("cstr[8] should be '\n'\n");
        return 0;
    }
    printf("Ok cstr[8] == '\\0'\n");

    return 1;
}