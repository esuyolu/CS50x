#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string arg = argv[1];

    for (int i = 0, n = strlen(arg); i < n; i++) 
    { 
        if (isalpha(arg[i]) != 0) {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    } 
  
    int num = atoi(argv[1]);
    string s = get_string("plaintext: ");

    for (int i = 0, n = strlen(s); i < n; ++i) {
        int cint = (int)s[i];
        int count = 0;

        while (count != num) {
            if (cint >= 65 && cint <= 90) {
                 ++cint;
                 if (cint > 90) {
                     cint = 65;
                 }
            }
            if (cint >= 97 && cint <= 122) {
                 ++cint;
                 if (cint > 122) {
                     cint = 97;
                 }
            }
            ++count;
        }
        s[i] = (char)cint;
    }

    printf("ciphertext: %s\n", s);
}

