// Custom implementation of strtok, no standard headers, no globals
// Implements behavior compatible with the C strtok contract.

static inline int __is_delim(char c, const char *delim) {
    for (const char *p = delim; *p; ++p) {
        if (*p == c) return 1;
    }
    return 0;
}

char *strtok( char * __restrict str, const char * __restrict delim ) {
    static char *saved = 0;

    char *s;
    if (str) {
        s = str;
    } else {
        s = saved;
        if (!s) return (char*)0;
    }

    // Skip leading delimiters
    while (*s && __is_delim(*s, delim)) {
        ++s;
    }

    if (!*s) {
        saved = (char*)0;
        return (char*)0;
    }

    char *token_start = s;

    // Find end of token
    while (*s && !__is_delim(*s, delim)) {
        ++s;
    }

    if (*s == '\0') {
        saved = (char*)0;
        return token_start;
    } else {
        *s = '\0';
        saved = s + 1;
        return token_start;
    }
}

