#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>

/* The following is the size of a buffer to contain any error messages
   encountered when the regular expression is compiled. */

#define MAX_ERROR_MSG 0x1000

static int compile_regex (regex_t * r, const char * regex_text);  // Compile the regular expression described by "regex_text" into "r".
static int match_regex (regex_t * r, const char * to_match);  // Match the string in "to_match" against the compiled regular expression in "r".
void regexp (const char * regex_text, const char * find_text);
