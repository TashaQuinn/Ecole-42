#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int i;
    int j;
    int buffer[255];

    if (argc == 3)
    {
        i = 0;
        while (i < 255)
        {
            buffer[i] = 0;
            i++;
        }
        i = 2;
        while (i > 0)
        {
            j = 0;
            while(argv[i][j])
            {
                if (i == 2 && !buffer[(unsigned char)argv[i][j]])
                    buffer[(unsigned char)argv[i][j]] = 1;
                else if (i == 1 && buffer[(unsigned char)argv[i][j]] == 1)
                {
                    write(1, &argv[i][j], 1);
                    buffer[(unsigned char)argv[i][j]] = 2;
                }
                j++;
            }
            i--;
        }
    }
    write(1, "\n", 1);
    return (0);
}