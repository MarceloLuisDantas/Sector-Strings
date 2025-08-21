#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sstrings.h"

int main() {
    SString *str1 = CStringToSSTring("foo");
    SString *str1pad = right_pad(str1, 3, " ");
    printf("Str Ok - \"%s\"\n", SStringToCString(str1pad));
    if (str1pad->len != 6) {
        printf("Not Ok - Should be 6, but got %ld\n", str1pad->len);
        return 0;
    }
    printf("Len Ok - %ld\n", str1pad->len);

    if (strcmp(SStringToCString(str1pad), "foo   ") != 0) {
        printf("Not Ok - Should be \"foo   \", but got \"%s\"\n", SStringToCString(str1pad));
        return 0;
    }
    printf("Str Ok - \"%s\"\n", SStringToCString(str1pad));

    SString *str2 = CStringToSSTring("bar");
    SString *str2pad = right_pad(str2, 3, "--");
    if (str2pad->len != 9) {
        printf("Not Ok - Should be 9, but got %ld\n", str2pad->len);
        return 0;
    }
    printf("Len Ok - %ld\n", str2pad->len);

    if (strcmp(SStringToCString(str2pad), "bar------") != 0) {
        printf("Not Ok - Should be \"bar------\", but got \"%s\"\n", SStringToCString(str2pad));
        return 0;
    }
    printf("Str Ok - \"%s\"\n", SStringToCString(str2pad));

    SString *str3 = CStringToSSTring("baz");
    SString *str3pad = right_pad(str3, 3, "");
    if (str3pad->len != 3) {
        printf("Not Ok - Should be 3, but got %ld\n", str3pad->len);
        return 0;
    }
    printf("Len Ok - %ld\n", str3pad->len);

    if (strcmp(SStringToCString(str3pad), "baz") != 0) {
        printf("Not Ok - Should be \"baz\", but got \"%s\"\n", SStringToCString(str3pad));
        return 0;
    }
    printf("Str Ok - \"%s\"\n", SStringToCString(str3pad));
    

    return 1;
}