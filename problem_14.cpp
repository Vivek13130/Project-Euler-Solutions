#include <bits/stdc++.h>
using namespace std;

inline int collatz_seq(long long num)
{ // Change num to long long
      int count = 0;
      while (num != 1)
      {
            count++;
            if (num & 1)
            {
                  num = 3 * num + 1;
            }
            else
            {
                  num /= 2;
            }
      }
      return count;
}

int main()
{
      int maxi = 0;
      int maxinum;

      cout << "processing " << endl;
      for (int i = 1; i <= 1000000; i++)
      {
            int ans = collatz_seq(i); // No need to change i, only collatz computation

            if (i % 10000 == 0)
            {
                  cout << "processing " << i / 10000 << endl;
            }

            if (ans > maxi)
            {
                  maxi = ans;
                  maxinum = i;
            }
      }

      cout << "Number with the longest Collatz sequence: " << maxinum << endl;

      return 0;
}
