
#include <stdio.h>
#include <unistd.h>
int valid_input(char *input, int matrix[][4]);
int game_solve(int str[4][4], int row, int col, int arr[4][4]);

void mprint(int str[4][4]) {
    int i = 0;
    int j = 0;
    char c;
    while (i < 4) {
        while (j < 4) {
            // int-y dardznum enq char
            c = str[i][j] + '0';
            write(1, &c, 1);
            if (j < 3)
                write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        j = 0;
        i++;
    }
}

// hashvum e te vorerordn e max@ vor dni dranic heto
int count_vis(int *line, int size) {
    int max = 0;
    int i = 0;
    int c = 0;
    while (i < size) {
        if (line[i] > max) {
            max = line[i];
            c++;
        }
        i++;
    }
    return c;
}

// stugum e dzaxic aj u ajic dzax

// stugum e verevic nerqev u nerqevic verev

// ete bolor koxmeric normal e`

char *args(char *res, char *input)
{
      int i;
 
      i = 0;
      while (*input)
      {
          if (*input > '0' && *input < '5')
             res[i++] = *input;
          input++;
      }
      res[i] = '\0';
      //printf("args done");
      return (res);
}

int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	char input[16];
	args(input, argv[1]);
	int arr[4][4];
	if(valid_input(input,arr) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
    // mnuma argc argv u normal validacia
    // chenq moranum norminette!!!
    int game[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    //int arr[4][4] = {{2, 3, 2, 1}, {2, 1, 2, 3}, {4, 1, 2, 2}, {1, 4, 2, 2}};

    /*
    arr[0] Row1Lt - Row4Lt
    arr[1] Row1Rt - Row4Rt
    arr[2] Col1up - Col4up
    arr[3] Col1down = Col4down
    */

    if (game_solve(game, 0, 0, arr)) {
        mprint(game); // tpum enq ardyunqy
    } else {
       write(1, "Error\n", 6);
    }
    return 0;
}
