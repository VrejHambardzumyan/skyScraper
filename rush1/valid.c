/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:56:05 by armtoros          #+#    #+#             */
/*   Updated: 2024/09/15 16:52:20 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 int valid(int str[4][4], int row, int col, int num) {
      int i = 0;
      // stugum enq ka et tiv@ arden te che
      while (i < 4) {
          if (str[row][i] == num || str[i][col] == num) {
              // ete ka`
              return 0;
          }
          i++;
      }
      return 1; // ete chka uremn karanq dnenq
 }

int count(char *t)
{
	int count;
 
    count = 0;
    while(*t)
    {
         if (*t > '0' && *t < '5')
            count++;
         t++;
    }
    return (count);
}

int check_input(int *input)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if(!(input[i] + input[i+4] >= 3 && input[i] + input[i+4] <= 5
					&& input[i+8] + input[i+12] >= 3 && input[i+8] + input[i+12] <= 5))
			return (0);
		i++;
	}
	return (1);
}

void crmatr(int *vekt, int matr[][4])
{
	int	i;
	int temp;

	i = 0;
	while (i < 16)
	{
		matr[i / 4][i % 4] = vekt[i];
		i++;
	}
	i = 0;
	while (i < 8)
	{
		temp = matr[i / 4][i % 4];
		matr[i / 4][i % 4] = matr[(i + 8) / 4][(i + 8) % 4];
		matr[(i + 8) / 4][(i + 8) % 4] = temp;
		i++;
	}
}

int	valid_input(char *input, int matrix[][4])
{
	int int_input[16];
	int i;

	i = 0;
	if(count(input) == 0)
		return (0);
	while(input[i])
	{
		int_input[i] = input[i] - 48;
		i++;
	}
	if(check_input(int_input) == 0)
		return (0);
	else
	{
		crmatr(int_input, matrix);
		return (1);
	}
}
