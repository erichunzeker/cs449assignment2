#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *input = malloc(sizeof(char) * 100);
    int size = 100;
    char curr;
    int len = 0;

    if(argc != 2){
        printf("Usage: %s filename", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");

    while(feof(f) == 0)
    {
        fread(&curr, sizeof(curr), 1, f);

        if((curr > 31 && curr <= 126 ) || curr == 9)
        {
            input[len] = curr;

            if(len < size)
                len++;
            else {
                input = realloc(input, 2 * size);
                size *= 2;
                len++;
            }
        }

        else
        {
            input[len] = '\0';
            if(len > 3)
                printf("%s\n", input);
            free(input);
            input = malloc(sizeof(char) * 100);
            size = 100;
            len = 0;

        }
    }

    free(input);
    fclose(f);
    return 0;
}

