#include <bits/stdc++.h>
using namespace std;


int main(){

      // Start measuring time
      auto start = std::chrono::high_resolution_clock::now();
      
      // Your code here , add #include<chrono>

      vector<vector<int>>grid ; 

      cout << " enter dimensions : " << endl;
      int rows, cols ; 
      cout << "no of rows : " ; cin >> rows;
      cout << "no of cols : " ; cin >> cols; 

      for(int i = 0 ; i < rows ; i++){
            vector<int>rowel (i + 1) ;

            for(int j = 0 ; j < (i+1) ; j++){
                  cin >> rowel[j];
            }
            
            grid.push_back(rowel);
      }


      vector<vector<int>>sgrid (rows , vector<int>(rows , 0));
      sgrid[0][0] = grid[0][0];

      for(int i = 0 ; i < rows-1 ; i++){
            // at main  row :

            for(int j = 0 ; j < (i + 1) ; j++){
                  // at the main elment of row : 
                  int mainsum = sgrid[i][j];

                  // going to adjacent elments in the next row : 
                  // we have two adjacent elments - i+1 , j       i+1, j+1
                  sgrid[i+1][j] = max(sgrid[i+1][j] , mainsum + grid[i + 1][j]);
                  sgrid[i+1][j + 1] = max(sgrid[i+1][j + 1] , mainsum + grid[i + 1][j + 1]);
                  
            }

      }

      int maxi = 0 ; 
      int m = grid.size()-1;

      for(int j = 0 ; j < (int)grid[m].size(); j++){
            maxi = max(maxi , sgrid[m][j]);
      }

      cout << maxi << endl;

       // Stop measuring time and calculate the elapsed time
      auto end = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

      // Output the elapsed time
      std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

      return 0;
}