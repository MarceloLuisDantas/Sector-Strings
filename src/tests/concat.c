#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sstrings.h"

int main() {
    SString *str1 = CStringToSSTring("foo");
    SString *str2 = CStringToSSTring("bar");

    SString *str12concat = concat(str1, str2, " ");
    printf("%s\n", str12concat->string);
    printf("%s\n", SStringToCString(str12concat));
    if (strcmp(str12concat->string, "foo bar") == 0) {
        printf("String OK: \"%s\"", SStringToCString(str12concat));
    } else {
        printf("String should be \"foo bar\", but is %s", SStringToCString(str12concat));
        return 0;
    }

    SString *str12concat_nospace = concat(str1, str2, "");
    if (strcmp(str12concat->string, "foobar") == 0) {
        printf("String OK: \"%s\"", SStringToCString(str12concat));
    } else {
        printf("String should be \"foobar\", but is %s", SStringToCString(str12concat));
        return 0;
    }
}