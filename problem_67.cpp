#include <bits/stdc++.h>
using namespace std;


int main(){
      ifstream file("0067_triangle.txt"); // Replace "data.txt" with the actual file name
      if (!file) {
            cerr << "Unable to open file." << endl;
            return 1;
      }
      else cout << " file working correctly ! " << endl;

      vector<vector<int>> grid;
      string line;

      // Read each line from the file
      while (getline(file, line))
      {
            vector<int> row;
            stringstream ss(line);
            int number;

            // Read each integer in the line
            while (ss >> number)
            {
                  row.push_back(number);
            }

            // Add the row to the grid
            grid.push_back(row);
      }

    file.close(); // Close the file after reading

      // cout << "Your input grid:" << endl;
      // for (const auto &row : grid)
      // {
      //       for (int num : row)
      //       {
      //             cout << num << " ";
      //       }
      //       cout << endl;
      // }

      // Start measuring time
      auto start = std::chrono::high_resolution_clock::now();

      
      // Your code here , add #include<chrono>
      

      int rows = 100, cols = 100 ; 

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