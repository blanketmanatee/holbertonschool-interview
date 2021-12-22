#include "holberton.h"

/**
 * is_digit - checks that arg is a number
 * @x: arg
 * Return: 0 on success
 */

int is_digit(char *x)
{
while (*x)
{
if (*x < '0' || *x > '9')
return (0);

x++;
}
return (1);
}

/**
 * _strlen - find len of str 
 * @s: str
 * Return: len of str
 */

int _strlen(char *s)
{
char *ptr = s;

while (*s)
s++;
return (s - ptr);
}

/**
 * multiply - mul two numbers
 * @a: num
 * @b: num
 */

void multiply(char *a, char *b)
{
int i, len_a, len_b, total, a_num, b_num, res = 0, tmp;
int *ptr;

len_a = _strlen(a);
len_b = _strlen(b);
tmp = len_b;
total = len_a + len_b;
ptr = malloc(sizeof(int) * total);
if (!ptr)
return;
for (len_a--; len_a >= 0; len_a--)
{
a_num = a[len_a] - '0';
res = 0;
len_b = tmp;
for (len_b--; len_b >= 0; len_b--)
{
b_num = b[len_b] - '0';
res += ptr[len_b + len_a + 1] + (a_num * b_num);
ptr [len_a + len_b  + 1] = res % 10;
res /= 10;
}
if (res)
ptr[len_a + len_b + 1] = res % 10;
}
while (*ptr == 0)
{
ptr++;
total--;
}
for (i = 0; i < total; i++)
printf("%i", ptr[i]);
printf("\n");
}

/**
 * main - Entry point
 * @argc: arg count
 * @argv: arg values
 * Return: 0 on success
 **/
int main(int argc, char *argv[])
{
char *num1 = argv[1];
char *num2 = argv[2];

if (argc != 3 || !is_digit(num1) || !is_digit(num2))
{
printf("Error\n");
exit(98);
}
multiply(num1, num2);
return (0);
}
