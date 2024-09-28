// # summation of primes
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main()
{
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      int n;
      cin >> n;
      n++;

      // Start measuring time
      auto start = std::chrono::high_resolution_clock::now();
      vector<bool> prime(n, true);

      for (int i = 2; i * i < n; ++i)
      {
            if (prime[i] == true)
            {
                  for (int z = i * i; z < n; z += i)
                  {
                        prime[z] = false;
                  }
            }
      }

      long long sum = 0;
      for (int i = 2; i < n; i++)
      {
            if (prime[i])
            {
                  sum += long(i);
            }
      }

      // Stop measuring time and calculate the elapsed time
      auto end = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
      cout << sum << endl;
      std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

      return 0;
}
