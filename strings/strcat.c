#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strappend(char *dest, char *src) {
    int destlen = strlen(dest);
    int srclen = strlen(src);
    
    char *news = malloc(destlen + srclen + 1);

    for (int i = 0; i < destlen; i++) {
        news[i] = dest[i];
    }

    for (int k = 0; k < srclen; k++) {
        news[k + destlen] = src[k];
    }

    news[destlen + srclen] = '\0';

    return news;
}

int main() {
    char s1[] = "This is another ";
    char s2[] = "fine mess";
    char *s3;

    s3 = strappend(s1, s2);
    printf("%s\n", s3);

    free(s3);

    return 0;
}