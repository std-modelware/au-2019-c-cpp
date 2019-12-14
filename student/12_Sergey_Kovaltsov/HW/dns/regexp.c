#include "regexp.h"

static int compile_regex (regex_t * r, const char * regex_text)
{
    int status = regcomp (r, regex_text, REG_EXTENDED|REG_NEWLINE);
    if (status != 0) {
        char error_message[MAX_ERROR_MSG];
        regerror (status, r, error_message, MAX_ERROR_MSG);
        printf ("Regex error compiling '%s': %s\n",
                regex_text, error_message);
        return 1;
    }
    return 0;
}

static int match_regex (regex_t * r, const char * to_match)
{
    /* "P" is a pointer into the string which points to the end of the
       previous match. */
    const char * p = to_match;
    /* "N_matches" is the maximum number of matches allowed. */
    const int n_matches = 10;
    /* "M" contains the matches found. */
    regmatch_t m[n_matches];

    while (1) {
        int i = 0;
        int nomatch = regexec (r, p, n_matches, m, 0);
        if (nomatch) {
            return nomatch;
        }
        for (i = 0; i < n_matches; i++) {
            int start;
            int finish;
            if (m[i].rm_so == -1) {
                break;
            }
            start = m[i].rm_so + (p - to_match);
            finish = start + 8;
            printf (" | %.*s: ", (finish - start - 1), to_match + start);
            start = m[i].rm_so + (p - to_match) + 16;
            finish = m[i].rm_eo + (p - to_match);
            printf ("%.*s", (finish - start - 1), to_match + start);
            break;
        }
        break;
//        p += m[0].rm_eo;
    }
    return 0;
}

void regexp (const char * regex_text, const char * find_text)
{
    regex_t r;
    compile_regex (& r, regex_text);
    match_regex (& r, find_text);
//    printf("%s", find_text);
    regfree (& r);
}