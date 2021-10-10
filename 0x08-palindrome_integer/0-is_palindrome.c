#include "palindrome.h"

/**
 * is_palindrome - checks for palindrome
 * @n: number to be checked
 * Return: 1 if n is a palindrome 0 otherwise
 */

int is_palindrome(unsigned long n)
{
    unsigned long reverse_num = 0, rem, original = n;


    while (original != 0) {
        rem = original % 10;
        reverse_num = reverse_num * 10 + rem;
        original /= 10;
    }
    if (original == rem)
        return (1);
    else
        return (0);
}
