#include "menger.h"

/**
 * menger - draws 2d menger sponge
 * @level: level of sponge to draw
 */

void menger(int level) {
    int i, j, x, y, result;
    char shape;

    result = pow(3, level);

    for (i = 0; i < result; i++)
    {
        for (j = 0; j < result; j++)
        {
            shape = '#';
            x = i;
            y = j;
            while (x > 0)
            {
                if (x % 3 == 1 && y % 3 == 1)
                shape = " ";
                x /= 3;
                y /= 3;
            }
            printf("%c", shape);
        }
        printf("/n");
    }
}
