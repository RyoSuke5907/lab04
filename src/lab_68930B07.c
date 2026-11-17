#include <stdio.h>
#include <string.h>
#include "get_line.h"
#include "essay.h"

#define MAXLEN 1000

const char ESSAY[] = "Ah Love! could you and I with Fate conspire \
To grasp this sorry Scheme of Things entire, \
Would not we shatter it to bits -- and then \
Re-mould it nearer to the Heart's Desire!";

int strindex(const char source[], char pattern[])
{
    const char *found = NULL;
    const char *p = source;
    const char *q;

    if (pattern[0] == '\0') {
        return (int)strlen(source);
    }

    while ((q = strstr(p, pattern)) != NULL) {
        found = q;
        p = q + 1;
    }

    if (found != NULL) {
        return (int)(found - source);
    }

    return -1;
}

#ifndef ___TEST___
int main(void)
{
    char pattern[MAXLEN] = "";

    printEssay(ESSAY);
    read_pattern_from_stdio(pattern, MAXLEN);

    int pos = strindex(ESSAY, pattern);
    printResult(ESSAY, pos);

    return 0;
}
#endif