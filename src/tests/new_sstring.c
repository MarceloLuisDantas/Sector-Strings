#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sstrings.h"

int main() {
    SString *ns = NewSString(100);
    if (ns->capacity != 100) {
        printf("len should be 100, but is %li\n", ns->len);
        return 0;
    }

    SString *ns2 = CStringToSSTring("works");
    if (strcmp(ns2->string, "works") != 0) {
        printf("Not OK - %s\n", ns2->string);
        return 0;
    }    
    printf("OK - %s\n", ns2->string);

    SString *ns3 = CStringToSSTring("");   
    if (strcmp(ns3->string, "") != 0) {
        printf("Not OK - \"%s\"\n", ns3->string);
        return 0;
    }
    printf("OK - \"%s\"\n", ns3->string);

    return 1;
}
