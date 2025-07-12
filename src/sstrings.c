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
 *          char *SStringToCString(const SString* str)
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
    size_t  capacity; 
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

// Allocs a new Array of SStrings
// MAY RETURN NULL
SStringArray *NewSStringArray(size_t size) {
    SStringArray *array = malloc(sizeof(SStringArray));
    if (array == NULL)
        return NULL;

    array->strings = malloc(sizeof(SString) * size);
    if (array->strings == NULL)
        return NULL;

    array->capacity = size;
    array->len = 0;
    return array;
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

// Convertes a SString to a CString (list of charhs ended with \0)
// MAY RETURN NULL
char *SStringToCString(const SString* str) {
    char *cstr = malloc(sizeof(char) * (str->len + 1)); // +1 to the \0
    if (cstr == NULL)
        return NULL;

    for (size_t i = 0; i < str->len; i++)
        cstr[i] = str->string[i];
    cstr[str->len] = '\n';

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

// Splits a SString at the separator
// MAY RETURN NULL
SStringArray *split(const SString *str, const char separator) {
    size_t how_many_split_points = 0;
    for (size_t i = 0; i < str->len; i++)
        if (str->string[i] == separator)
            how_many_split_points += 1;

    size_t *split_points = malloc(sizeof(size_t) * how_many_split_points);
    size_t count = 0;
    for (size_t i = 0; i < str->len; i++) {
        if (str->string[i] == separator) {
            split_points[count] = i;
            count += 1;
        }
    }

    SStringArray *splited = NULL;


    free(split_points);
    return NULL;
}

// Concats 2 SStrings with the separator in between
// MAY RETURN NULL
SString *concat(const SString *str1, const SString *str2, const char *separator) {
    size_t new_len = str1->len + str2->len;
    if (separator != "") 
        new_len += 1;
    
    SString *ns = NewSString(new_len);
    if (ns == NULL)
        return NULL;
        
    size_t count = 0;
    for (size_t i = 0; i < str1->len; i++) {
        ns->string[count] = str1->string[i];
        count += 1;
    }

    if (separator != "") {
        ns->string[count] = separator;
        count += 1;
    }

    for (size_t i = 0; i < str2->len; i++) {
        ns->string[count] = str2->string[i];
        count += 1;
    }

    return ns;
}