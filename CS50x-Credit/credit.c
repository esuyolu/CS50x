#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count(long num);
long getReverse(long num);
int getDigitsSum(int val);
bool isVALID(long num);
bool isAMEX(long num);
bool isMASTERCARD(long num);
bool isVISA(long num);

int main(void)
{
    long l;
    do {
        l = get_long("Number: ");
    } while (l < 0);

    if (isAMEX(l)) {
        printf("AMEX\n");
    }
    else if (isMASTERCARD(l)) {
        printf("MASTERCARD\n");
    }
    else if (isVISA(l)) {
        printf("VISA\n");
    }
    else {
        printf("INVALID\n");
    }
}

int count(long num)
{
    int count = 0;
    do {
        ++count;
        num /= 10;
    } while(num != 0);

    return count;
}

long getReverse(long num)
{
    long result = 0;

    while (num != 0) {
        result = result * 10 + num % 10;
        num /= 10;
    }

    return result;
}
int getDigitsSum(int val)
{
	int sum = 0;
		
	while (val != 0) {
		sum += val % 10;
		val /= 10;
	}
		
	return sum;
}
bool isVALID(long num)
{
    int sum = 0;
    int twiceSum = 0;

    while (num != 0) {
        sum += num % 10;
        num /= 10;
        twiceSum += getDigitsSum( (num % 10) * 2);
        num /= 10;
    }

    int res = sum + twiceSum;

    if (res % 10 == 0)
        return true;
    else
        return false;
}

bool isAMEX(long num)
{
    int c = count(num);
    int res = getReverse(num) % 100;

    if (c == 15 && (res == 43 || res == 73) && isVALID(num))
        return true;
    else
    return false;
}

bool isMASTERCARD(long num)
{
    int c = count(num);
    int res = getReverse(num) % 100;

    if (c == 16 && (res == 15 || res == 25|| res == 35 || res == 45 || res == 55) && isVALID(num))
        return true;
    else
        return false;
}

bool isVISA(long num)
{
    int c = count(num);
    int res = getReverse(num) % 10;

    if ((c == 13 || c == 16 ) && res == 4 && isVALID(num))
        return true;
    else
        return false;
}

