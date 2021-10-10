#include "menger.h"

/**
 * menger - draws 2d menger sponge
 * @level: level of sponge to draw
 */

void menger(int level) 
{
int i, j, x, y, result;
char shape;

result = pow(3, level);

if (level < 0)
return;

if (level == 0)
{
printf("\n");
return;
}

for (i = 0; i < result; i++)
{
for (j = 0; j < result; j++)
{
x = i;
y = j;
shape = '#';

while (x)
{
if (x % 3 == 1 && y % 3 == 1)
shape = ' ';
x = x / 3;
y = y / 3;
}
printf("%c", shape);
}
printf("\n");
}
}
