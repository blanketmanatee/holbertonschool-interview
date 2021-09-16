#include "palindrome.h"

/**
 * is_palindrome - checks for palindrome
 * @n: number to be checked
 * Return: 1 if n is a palindrome 0 otherwise
 */

int is_palindrome(unsigned long n)
{
    unsigned long reverse_num=0, rem;


    while (n !=0){
        rem = n%10;
        reverse_num = reverse_num*10+rem;
        is_palindrome(n/10);
    }
    if (n == rem)
        return (1);
    else
        return (0);
}
