#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c;
    long long vowels = 0, consonants = 0, digits = 0, spaces = 0;

    while ((c = getchar()) != EOF && c != '\n') {
        if (isalpha((unsigned char)c)) {
            char lower = (char)tolower((unsigned char)c);
            if (lower == 'a' || lower == 'e' || lower == 'i' ||
                lower == 'o' || lower == 'u')
                vowels++;
            else
                consonants++;
        } else if (isdigit((unsigned char)c)) {
            digits++;
        } else if (c == ' ') {
            spaces++;
        }
    }

    printf("%lld %lld %lld %lld\n", vowels, consonants, digits, spaces);
    return 0;
}