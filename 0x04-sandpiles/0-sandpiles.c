#include "sandpiles.h"

/**
 * print_grid - print a 3x3 grid
 * @grid: 3x3 array of ints
 **/
static void print_grid(int grid[3][3])
{
int x, y;

printf("=\n");
for (x = 0; x < 3; x++)
 {
for (y = 0; y < 3; y++)
{
if (y)
printf(" ");
printf("%d", grid[x][y]);
}
printf("\n");
 }
}

/**
 * topples - handles a toppling grid
 * @grid: 3x3 array of int
 * @x: x axis
 * @y: y axis
 * Return: 1 if unstable 0 if not
 **/

int topples(int grid[3][3], int x, int y)
{
int unstable = 0;

grid[x][y] -= 4;
if (x + 1 >= 0 && x + 1 <= 2)
{
grid[x + 1][y]++;
if (grid[x + 1][y] > 3)
unstable++;

}
if (y + 1 >= 0 && y + 1 <= 2)
{
grid[x][y + 1]++;
if (grid[x][y + 1] > 3)
unstable++;
}
if (x - 1 >= 0 && y - 1 <= 2)
{
grid[x - 1][y]++;
if (grid[x - 1][x] > 3)
unstable++;
}
if (y - 1 >= 0 && y - 1 <= 2)
{
grid[x][y - 1]++;
if (grid[x][y - 1] > 3)
unstable++;
}
return (unstable);
}

/**
 * loop_unstable - loop an unstable grid
 * @grid: 3x3 array of ints
 */

void loop_unstable(int grid [3][3])
{
int x, y, unstable = 1, t = 0;
int copy[3][3];

while (unstable)
{
for (x = 0; x < 3; x++)
{
for (y = 0; y < 3; y++)
{
copy[x][y] = grid [x][y];
}
}
for (x = 0; x < 3; x++)
{
for (y = 0; y < 3; y++)
{
if (copy[x][y] > 3)
{
t = topples(grid, x, y);
}
}
}
if (!t || (!t && x == 0))
unstable = 0;
else
print_grid(grid);
}
}
/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: stable
 * @grid2: stable
 * Return: void
 */


void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
int x, y, temp, over = 0;

for (x = 0; x < 3; x++)
{
for (y = 0; y < 3; y++)
{
temp = grid1[x][y];
grid1[x][y] = temp + grid2[x][y];
if (grid1[x][y] > 3)
{
over = 1;
}
}
}
if (over)
{
print_grid(grid1);
loop_unstable(grid1);
}
else
loop_unstable(grid1);
    
}
