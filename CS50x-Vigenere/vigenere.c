#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }

    string strarg = argv[1];
    int n = strlen(strarg);

    for (int i = 0; i < n; i++) 
    { 
        if (isdigit(strarg[i])) {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    } 
  
    string s = get_string("plaintext: ");
    int intarg[n];
    int k = 0, cint;
   
    for (int i = 0; i < n; ++i) {
        int iarg = (int)strarg[i];
        intarg[i] = toupper(iarg) - 65;
    }

    for (int i = 0, size = strlen(s); i < size; ++i) {
        if (k == n) {
            k = 0;
        }
        cint = s[i];
        if (cint >= 65 && cint <= 90)  {
            cint += intarg[k];
            ++k;
            while (cint > 90) {
                     cint = (cint - 90) + 64;
                 }
        }

         if (cint >= 97 && cint <= 122)  {
            cint += intarg[k];
            ++k;
            while (cint > 122) {
                     cint = (cint - 122) + 96;
                 }
        }

        s[i] = (char)cint;
    }

    printf("ciphertext: %s\n", s);
}

