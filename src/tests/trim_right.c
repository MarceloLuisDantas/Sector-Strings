#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sstrings.h"

int main() {
    SString *only_spaces = CStringToSSTring("           ");
    SString *null = trim_right(only_spaces);
    if (null != NULL) {
        printf("Strings with only spaces should be NULL after trim\n");
        return 0;
    }

    SString *without_extra_space = CStringToSSTring("without spaces on right");
    SString *trimed_str_1 = trim_right(without_extra_space);
    if (strcmp(trimed_str_1->string, "without spaces on right") == 0) {
        printf("OK - \"%s\"\n", trimed_str_1->string);
    } else {
        printf("Not OK - \"%s\"\n", trimed_str_1->string);
        return 0;
    }

    SString *with_extra_space = CStringToSSTring("with spaces on right        ");
    SString *trimed_str_2 = trim_right(with_extra_space);
    if (strcmp(trimed_str_2->string, "with spaces on right") == 0) {
        printf("OK - \"%s\"\n", trimed_str_2->string);
        return 1;
    }
    printf("Not OK - \"%s\"\n", trimed_str_2->string);
    return 0;
}