#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float f;
    do {
        f = get_float("Change: ");
    } while (f < 0);

    double d = f * 100;
    int n = 0;

    if (d >= 25) {
        n += (d / 25);
        d = round(fmod(d, 25));
    }
    if (d >= 10) {
        n += (d / 10);
        d = round(fmod(d, 10));
    }
    if (d >= 5) {
        n += (d / 5);
        d = round(fmod(d, 5));
    }
    if (d >= 1) {
        n += (d / 1);
        d = round(fmod(d, 1));
    }
    printf("%i\n", n);
}

