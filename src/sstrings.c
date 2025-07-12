#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*
 *      Sector Seven - Strings
 *      This is a library created with my needs in mind,
 *      to be used in the Sector Seven Project.
 *
 *      I don't recommend using this in production or similar 
 *      scenarios, but, feel free to use to small pet projects. 
 *      If you need a feature that isn't yet implemented, 
 *      you can request it by opening an issue on the repository 
 *      (https://github.com/MarceloLuisDantas/Sector-Strings).
 * 
 *      Structs:
 *          typedef struct SString {
 *              char    *string;
 *              size_t capacity; 
 *              size_t      len;
 *          } SString;
 *    
 *          typedef struct SStringArray {
 *              SString **strings;
                size_t   capacity; 
 *              size_t        len;
 *          } SStringArray;      
 * 
 *      Functions:
 *          SString *NewSString(size_t size)
 *          SString *CStringToSSTring(const char* str)
 *          char *SStringToCString(const SString* str)
 *          SString *trim_left(SString *str)
 *          SString *trim_right(SString *str)
 *          SString *trim(const SString *str)
 *          SString *slice(const SString *str, size_t start, size_t end)
 *          SString *concat(const SString *str1, const SString *str2, const char *separator)
 * 
 */

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
SString *NewSString(size_t size) {
    SString *ns = malloc(sizeof(SString));
    if (ns == NULL) return NULL;

    ns->string = malloc(sizeof(char) * size);
    if (ns->string == NULL) return NULL;

    ns->capacity = size;
    ns->len = 0;
    return ns;
}

// Allocs a new Array of SStrings
// MAY RETURN NULL
SStringArray *NewSStringArray(size_t size) {
    SStringArray *array = malloc(sizeof(SStringArray));
    if (array == NULL) return NULL;

    array->strings = malloc(sizeof(SString) * size);
    if (array->strings == NULL) return NULL;

    array->capacity = size;
    array->len = 0;
    return array;
}

// Creates a SString from a C-String (list of chars ended with \0)
// MAY RETURN NULL
SString *CStringToSSTring(const char* str) {
    size_t len = strlen(str);
    SString *ns = NewSString(len);
    if (ns == NULL) return NULL;

    memcpy(ns->string, str, len);
    ns->len = len;
    return ns;
}

// Convertes a SString to a CString (list of charhs ended with \0)
// MAY RETURN NULL
char *SStringToCString(const SString* str) {
    char *cstr = malloc(sizeof(char) * (str->len + 1)); // +1 to the \0
    if (cstr == NULL) return NULL;

    for (size_t i = 0; i < str->len; i++)
        cstr[i] = str->string[i];
    cstr[str->len] = '\0';

    return cstr;
}

// Removes all extra spaces at the beginning the string
// MAY RETURN NULL IF
//      The string is only spaces (for some reason)
//      If the NewSString returns NULL
SString *trim_left(const SString *str) {
    int total_spaces = 0;
    for (int i = 0; i < str->len; i++) {
        if (str->string[i] == ' ') {
            total_spaces += 1;
        } else {
            break;
        }
    }

    if (total_spaces == str->len) return NULL;

    SString *ns = NewSString(str->len - total_spaces);
    if (ns == NULL) return NULL;

    ns->len = ns->capacity;
    for (int i = 0; i < ns->capacity; i++) 
        ns->string[i] = str->string[i + total_spaces];
    
    return ns;
}

// Removes all extra spaces at the end of the string
// MAY RETURN NULL IF
//      The string is only spaces (for some reason)
//      If the NewSString returns NULL
SString *trim_right(const SString *str) {
    int total_spaces = 0;
    for (int i = str->len - 1; i >= 0; i--) {
        if (str->string[i] == ' ') {
            total_spaces += 1;
        } else {
            break;
        }
    }

    if (total_spaces == str->len) return NULL;

    SString *ns = NewSString(str->len - total_spaces);
    if (ns == NULL) return NULL;

    ns->len = ns->capacity;
    for (int i = 0; i < ns->capacity; i++) 
        ns->string[i] = str->string[i];
    
    return ns;
}

// Removes all extra spaces in both sides of the string
// MAY RETURN NULL IF
//      The string is only spaces (for some reason)
//      If the trim_left returns NULL
//      If the trim_right returns NULL
SString *trim(const SString *str) {
    SString *trimed_left = trim_left(str); // temp, should be free at end of function
    if (trimed_left == NULL) return NULL;
    
    SString *full_trimmed = trim_right(trimed_left);
    if (full_trimmed == NULL) return NULL;

    free(trimed_left);
    return full_trimmed;
}

// Concats 2 SStrings with the separator in between
// MAY RETURN NULL
SString *concat(const SString *str1, const SString *str2, const char *separator) {
    size_t new_len = str1->len + str2->len;
    if (separator != NULL && separator[0] != '\0') 
        new_len += strlen(separator);
    new_len += 1; // '\0'

    char *cstr = malloc(sizeof(char) * new_len);
    
    size_t count = 0;
    // Copying str1 to cstr
    memcpy(cstr + count, str1->string, str1->len);
    count += str1->len;

    // Copying the separator
    if (separator != NULL && separator[0] != '\0') {
        size_t sep_len = strlen(separator);
        memcpy(cstr + count, separator, sep_len);
        count += sep_len;
    }

    // Copia str2
    memcpy(cstr + count, str2->string, str2->len);
    count += str2->len;

    cstr[count] = '\0';

    SString *ns = CStringToSSTring(cstr);
    if (ns == NULL) return NULL;

    free(cstr);
    return ns;
}

// Returns a SString with a slice of another SString.
// The slice starts ate the start idnex, and copys (including) until the end idnex
// str = "foo bar", start = 2, end = 5
// result = "o ba"
// MAY RETURN NULL
SString *slice(const SString *str, size_t start, size_t end) {
    if (str->len <= 0) return NULL;
    if (start > end) return NULL;
    if (start < 0 || end < 0) return NULL;
    if (start >= str->len || end >= str->len) return NULL;

    size_t cstr_len = end - start + 1;
    char *cstr = malloc(sizeof(char) * (cstr_len + 1 /* \0 */));
    if (cstr == NULL) return NULL;

    memcpy(cstr, str->string + start, cstr_len);
    cstr[cstr_len] = '\0';
    SString *sslice = CStringToSSTring(cstr);
    free(cstr);

    return sslice;
}

// Splits a SString at the separator
// MAY RETURN NULL
SStringArray *split(const SString *str, const char separator) {
    if (str->len <= 0)
        return NULL;

    size_t how_many_split_points = 0;
    for (size_t i = 0; i < str->len; i++)
        if (str->string[i] == separator)
            how_many_split_points += 1;
    SStringArray *splites = NewSStringArray(how_many_split_points + 1);
    if (splites == NULL) return NULL;

    size_t *split_points = malloc(sizeof(size_t) * how_many_split_points);
    if (split_points == NULL) return NULL;

    size_t count = 0;
    for (size_t i = 0; i < str->len; i++) {
        if (str->string[i] == separator) {
            split_points[count] = i;
            count += 1;
        }
    }

    int start = 0;
    int end = 0;
    for (int i = 0; i < how_many_split_points; i++) {
        end = split_points[i];
    }

    free(split_points);
    return NULL;
}


SString *join(const SStringArray *strs, const char *separator) {
    if (strs->len <= 0) return NULL;
    
    size_t sep_len = 0;
    if (separator != NULL && separator[0] != '\0') 
        sep_len += strlen(separator);
    int total_seps = strs->len - 1;
    
    size_t new_len = 0;
    for (int i = 0; i < strs->len; i++)
        new_len += strs->strings[i]->len;
    
    new_len += sep_len * total_seps;
    new_len += 1; // '\0'

    char *cstr = malloc(sizeof(char) * new_len);
    if (cstr == NULL) return NULL;

    size_t count = 0;
    for (int i = 0; i < strs->len; i++) {
        memcpy(cstr + count, strs->strings[i]->string, strs->strings[i]->len);
        count += strs->strings[i]->len;

        if (sep_len > 0 && total_seps > 0) {
            memcpy(cstr + count, separator, sep_len);
            count += sep_len;
            total_seps -= 1;
        }
    }
    cstr[count] = '\0';

    SString *joined = CStringToSSTring(cstr);
    free(cstr);

    return joined;
}