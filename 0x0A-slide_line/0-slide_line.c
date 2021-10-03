#include "slide_line.h"

/**
 * reverse - reverses the list
 * @line: points to array of int containing size elements
 * @size: the size
 **/

void reverse (int *line, size_t size)
{
    size_t i, j;
    int temp;

    for (i = 0, j = size - 1; i < size / 2; i++, j--)
    {
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;
    }

}

/**
 * add - adds
 * @line: points to array of int containing size elements
 * @size: size
 **/

void add(int *line, size_t size)
{
    size_t i, j;

    for (i = 0; i < size; i++)
    for (j = i + 1; j < size; j++)
    {
        if (line[i] != 0 && line[j] != 0 && line[i] != line[j])
        {
            i = j;
            break;
        }
        if (line[i] != 0 && line[i] == line[j])
        {
            line[i] += line[i];
            line[j] = 0;
            break;
        }
    }
}

/**
 * align - align
 * @line: points to array of int containing size elements
 * @size: size
 **/

void align(int *line, size_t size)
{
    size_t i, j;

    for (i = 0, j = 0; i < size; i++)
    if (line[i] != 0)
    {
        line[j] = line[i];
        j++;
    }
    for (; j < size; j++)
    line[j] = 0;
}

/**
 * slide_line - slides and merges array of ints
 * @line: points to array of int containing size elements
 * @size: size
 * @direction: direction the line must be slided and merged
 * Return: 1 or 0
 **/

int slide_line(int *line, size_t size, int direction)
{
    switch (direction)
    {
        case 0:
        add(line, size);
        align(line, size);
        break;

        case 1:
        reverse(line, size);
        add(line, size);
        align(line, size);
        reverse(line, size);
        break;

        default:
        return (0);
    }
    return (1);
}
