#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"

int size = 1;

int r2a(char *str);
void draw(int num);
void draw_str(char *str);
int check(char *str);

int main(int argc, char *argv[])
{
    char input[50] = "";
    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        if (input[0] == '\n')
            continue;
        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        if (strcmp(input, "exit") == 0)
            break;
        else if (strstr(input, "set size"))
            size = atoi(input + strlen("set size "));
        else if(check(input))
            draw(-1);
        else
            draw(r2a(input));
    }
    return 0;
}

int r2a(char *str)
{
    int roman[89] = {['I'] = 1,
                     ['V'] = 5,
                     ['X'] = 10,
                     ['L'] = 50,
                     ['C'] = 100,
                     ['D'] = 500,
                     ['M'] = 1000};
    int sum = roman[str[0]];
    int len = strlen(str);

    for (int i = 0; i < len - 1; i++)
        if (roman[str[i]] >= roman[str[i + 1]])
            sum += roman[str[i + 1]];
        else
            sum += roman[str[i + 1]] - 2 * roman[str[i]];
    return sum;
}

void draw(int num)
{
    if (num == -1)
        draw_str("E");
    else
    {
        char str[50] = "";
        sprintf(str, "%d", num);
        draw_str(str);
    }
}

int check(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        if (strchr("IVXLCDM", str[i]) == NULL)
            return -1;
    return 0;
}

void draw_str(char *str)
{
    char *p = NULL;
    graph_arr *graph;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < size; j++)
        {
            p = str;
            while (*p != '\0')
            {
                graph = graphs[*p];

                printf("%c", (*graph)[i][0]);
                for (int k = 0; k < size; k++)
                    printf("%c", (*graph)[i][1]);
                printf("%c", (*graph)[i][2]);
                p++;
            }
            printf("\n");
            if (i % 2 == 0)
                break;
        }
}
