#ifndef SSTRINGS_H
#define SSTRINGS_H

#include <stdlib.h>

typedef struct SString {
    char *string;
    size_t   len; 
} SString;

// Allocs a new SString with the needed size
// MAY RETURN NULL
SString *NewSString(size_t size);

// Creates a SString from a C-String (list of chars ended with \0)
// MAY RETURN NULL
SString *CStringToSSTring(const char* string);

// Removes all extra spaces at the beginning the string
// MAY RETURN NULL
//      The string is only spaces (for some reason)
//      If the NewSString returns NULL
SString *trim_left(SString *str);

// Removes all extra spaces at the end of the string
// MAY RETURN NULL IF
//      The string is only spaces (for some reason)
//      If the NewSString returns NULL
SString *trim_right(SString *str);

// Removes all extra spaces in both sides of the string
// MAY RETURN NULL IF
//      The string is only spaces (for some reason)
//      If the trim_left returns NULL
//      If the trim_right returns NULL
SString *trim(const SString *str);

#endif