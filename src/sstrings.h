#ifndef SSTRINGS_H
#define SSTRINGS_H

#include <stdlib.h>

typedef struct SString {
    char    *string;
    size_t capacity; 
    size_t      len; 
} SString;

typedef struct SStringArray {
    SString **strings;
    size_t   capacity; 
    size_t        len;
} SStringArray;

// Allocs a new SString with the needed size
// MAY RETURN NULL
SString *NewSString(size_t size);

// Creates a SString from a C-String (list of chars ended with \0)
// MAY RETURN NULL
SString *CStringToSSTring(const char* string);

// Converts a SString to a CString (list of charhs ended with \0)
// MAY RETURN NULL
char *SStringToCString(const SString* str);

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

// Returns a SString with a slice of another SString.
// The slice starts ate the start idnex, and copys (including) until the end idnex
// str = "foo bar", start = 2, end = 5
// result = "o ba"
// MAY RETURN NULL
SString *slice(const SString *str, size_t start, size_t end);

// Concats 2 SStrings with the separator in between
// MAY RETURN NULL
SString *concat(const SString *str1, const SString *str2, const char *separator);

// Splits a SString at the separator, separator is a single char
// MAY RETURN NULL IF
//      str.len <= 0
//      NewSStringArray returns null (malloc = null)
//      slice returns null 
SStringArray *split(const SString *str, const char separator);

// Join all SStrings in a SStringsArray, separed buy the separator.
// MAY RETURN NULL IF
//     strs->len <= 0
//     malloc returns null
SString *join(const SStringArray *strs, const char *separator);

// Returns the number of times a specified value occurs in a string
// Returns -1 if the value doesn't exist
size_t count(SString *str, const char *value);

// Searches the string for a specified value and returns the position of where it was found
// Returns -1 if the value doesn't exist
size_t indexof(SString *str, const char *value);

#endif