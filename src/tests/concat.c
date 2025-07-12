#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sstrings.h"

int main() {
    SString *str1 = CStringToSSTring("foo");
    SString *str2 = CStringToSSTring("bar");
    
    SString *str12concat = concat(str1, str2, " ");
    if (str12concat->len != 7) {
        printf("len is wrong, len = %d\n", str12concat->len);
        return 0;
    } else {
        printf("len is ok\n");
    }
  
    if (strcmp(str12concat->string, "foo bar") == 0) {
        printf("String OK: \"%s\"\n", SStringToCString(str12concat));
    } else {
        printf("String should be \"foo bar\", but is %s\n", SStringToCString(str12concat));
        return 0;
    }
    
    SString *str12concat_nospace = concat(str1, str2, "");
    if (strcmp(str12concat_nospace->string, "foobar") == 0) {
        printf("String OK: \"%s\"\n", SStringToCString(str12concat_nospace));
    } else {
        printf("String should be \"foobar\", but is %s\n", SStringToCString(str12concat_nospace));
        return 0;
    }

    return 1;
}