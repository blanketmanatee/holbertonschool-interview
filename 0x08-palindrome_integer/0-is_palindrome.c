#include "palindrome.h"

/**
 * is_palindrome - checks for palindrome
 * @n: number to be checked
 * Return: 1 if n is a palindrome 0 otherwise
 */

int is_palindrome(unsigned long n)
{
    unsigned long reverse_num = 0, temp = 0, copy = n;


    while (n != 0) {
        temp = n % 10;
        reverse_num = reverse_num * 10 + temp;
        n /= 10;
    }
    if (copy == reverse_num)
        return (1);
    return (0);
}
