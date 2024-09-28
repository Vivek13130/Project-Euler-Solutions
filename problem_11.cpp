#include <bits/stdc++.h>
using namespace std;

int main()
{
      vector<vector<int>> mat(20, vector<int>(20));
      for (int i = 0; i < 20; ++i)
      {
            for (int j = 0; j < 20; ++j)
            {
                  cin >> mat[i][j];
            }
      }

      int maxi = 0;

      for (int i = 0; i <= 16; i++)
      {
            for (int j = 0; j <= 16; j++)
            {
                  
                  int prodright = mat[i][j] * mat[i][j+1] * mat[i][j+2] * mat[i][j+3];
                  int proddown = mat[i][j] * mat[i+1][j] * mat[i+2][j] * mat[i+3][j];
                  int proddownright = mat[i][j] * mat[i + 1][j+1] * mat[i+2][j+2] * mat[i+3][j+3];
                  int proddownleft = 1;

                  if (j >= 3){
                        proddownleft = mat[i][j] * mat[i+1][j-1] * mat[i + 2][j-2] * mat[i + 3][j-3];
                  }

                  maxi = max(maxi , proddownright);
                  maxi = max(maxi , proddownleft);
                  maxi = max(maxi , proddown);
                  maxi = max(maxi , prodright);
                  
            }
      }

      cout << maxi << endl;
}