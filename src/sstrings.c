#include <stdlib.h>
#include <string.h>

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
 *              SString *strings;
 *              size_t       len;
 *          } SStringArray;      
 * 
 *      Functions:
 *          SString *NewSString(size_t size)
 *          SString *CStringToSSTring(const char* str)
 *          SString *trim_left(SString *str)
 *          SString *trim_right(SString *str)
 *          SString *trim(const SString *str)
 * 
 */

typedef struct SString {
    char    *string;
    size_t capacity; 
    size_t      len;
} SString;

typedef struct SStringArray {
    SString *strings;
    size_t       len;
} SStringArray;

// Allocs a new SString with the needed size
// MAY RETURN NULL
SString *NewSString(size_t size) {
    SString *ns = malloc(sizeof(SString));
    if (ns == NULL)
        return NULL;

    ns->string = malloc(sizeof(char) * size);
    if (ns->string == NULL)
        return NULL;

    ns->len = 0;
    ns->capacity = size;
    return ns;
}

// Creates a SString from a C-String (list of chars ended with \0)
// MAY RETURN NULL
SString *CStringToSSTring(const char* str) {
    size_t len = strlen(str);
    SString *ns = NewSString(len);
    if (ns == NULL)
        return NULL;

    memcpy(ns->string, str, len);
    ns->len = len;
    return ns;
}

// Removes all extra spaces at the beginning the string
// MAY RETURN NULL
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

    if (total_spaces == str->len)
        return NULL;

    SString *ns = NewSString(str->len - total_spaces);
    if (ns == NULL)
        return NULL;

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

    if (total_spaces == str->len)
        return NULL;

    SString *ns = NewSString(str->len - total_spaces);
    if (ns == NULL)
        return NULL;

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
    if (trimed_left == NULL)
        return NULL;
    
    SString *full_trimmed = trim_right(trimed_left);
    if (full_trimmed == NULL)
        return NULL;

    free(trimed_left);
    return full_trimmed;
}

SStringArray *split(const SString *str, const char separator) {

}
