
int valid(int str[4][4], int row, int col, int num);
int count_vis(int *line, int size);
// stugum e verevic nerqev u nerqevic verev
int check_top_bott(int str[4][4], int arr[4][4]) {
     int new_arr[4];
     int i = 0;
     int j = 0;

     while (i < 4) {
         // verevic nerqev
         while (j < 4) {
             new_arr[j] = str[j][i];
             j++;
         }
         if (count_vis(new_arr, 4) != arr[2][i])
             return 0;
         // nerqevic verev
         j = 0;
         while (j < 4) {
              new_arr[j] = str[3 - j][i];
              j++;
          }
          if (count_vis(new_arr, 4) != arr[3][i])
              return 0;
          j = 0;
          i++;
      }
      return 1;
  }
int check_left_right(int str[4][4], int arr[4][4]) {
      int new_arr[4];
      int i = 0;
      int j = 0;
 
     while (i < 4) {
          // dzaxic aj
          while (j < 4) {
             new_arr[j] = str[i][j];
              j++;
          }
          if (count_vis(new_arr, 4) != arr[0][i]) {
              return 0;
          }
          // ajic dzax
         j = 0;
          while (j < 4) {
              new_arr[j] = str[i][3 - j];
              j++;
          }
          if (count_vis(new_arr, 4) != arr[1][i]) {
            return 0;
         }
         j = 0;
         i++;
      }
      return 1;
}
int check(int str[4][4], int arr[4][4])
{
     return check_left_right(str, arr) && check_top_bott(str, arr);
}
// himnakan xaxi uxexy
 int game_solve(int str[4][4], int row, int col, int arr[4][4]) {
     int nb = 1;

     // ete sax lracrel enq toxery mi hat el stugum enq
     if (row == 4)
         return check(str, arr);
     // erb hasnenq toghi verjin ancnenq hajordin
     if (col == 4) {
         return game_solve(str, row + 1, 0, arr);
     }
     // sksum enq dnel tvery
     while (nb <= 4) {
         if (valid(str, row, col, nb)) {
             str[row][col] = nb;
             if (game_solve(str, row, col + 1, arr)) {
                 return 1;
             }
             // ete chka lucum noric sksum enq 0-ic
             str[row][col] = 0;
         }
         nb++;
     }
     return 0;
}
