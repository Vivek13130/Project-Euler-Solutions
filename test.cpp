#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
      void help_multiply(string & s , string& c){
            string ans = "";
            string name = "";
            string count = "";

            for (int i = 0; i < s.length(); i++)
            {

                  if (s[i] >= 'A' && s[i] <= 'Z')
                  {
                        // starting of name ;
                        if (name.length() != 0)
                        {
                              int freq = 1;
                              if (count.length() != 0)
                                    freq = stoi(count);

                              // mp[name] = freq;
                              ans += name + to_string(freq * stoi(c));

                              name = "";
                              count = "";
                              // resetting both back ;
                        }

                        name += s[i];
                  }
                  else if (s[i] >= 'a' && s[i] <= 'z')
                  {
                        // continuation of name ;
                        name += s[i];
                  }
                  else
                  {
                        // now this is count ;
                        count += s[i];
                  }
            }

            s = ans;
            return;
      }

      void solve_par(int ind, string &s)
      {
            int tempind = ind; // storing for later use
            string semistr = "";
            ind++;

            for (ind; ind < s.length(); ind++)
            {
                  if (s[ind] == '(')
                        solve_par(ind, s); // another ();
                  else if (s[ind] == ')')
                        break;
                  else
                        semistr += s[ind];
            }

            // now ind is pointing at ')' , we need the count after it ;
            ind++;
            string count = "";
            while (ind < s.length() && s[ind] >= '0' && s[ind] <= '9')
            {
                  count += s[ind];
                  ind++;
            }

            // now we have our string and count , just need to multiply the values  ;
            help_multiply(semistr, count);

            // now our semistr is multiplied with count ;
            // we need to replace the str subpart with semistr and return ;
            s.replace(tempind , ind - tempind , semistr);
            return;
      }

      string countOfAtoms(string s)
      {
            // ordered map to keep the names sorted ;
            map<string, int> mp;

            // handle the () first ;
            for (int i = 0; i < s.length(); i++)
            {
                  if (s[i] == '(')
                  {
                        solve_par(i, s);
                  }
            }

            // no more () ;
            string name = "";
            string count = "";
            for (int i = 0; i < s.length(); i++)
            {

                  if (s[i] >= 'A' && s[i] <= 'Z')
                  {
                        // starting of name ;
                        if (name.length() != 0)
                        {
                              int freq = 1;
                              if (count.length() != 0)
                                    freq = stoi(count);

                              mp[name] = freq;

                              name = "";
                              count = "";
                              // resetting both back ;
                        }

                        name += s[i];
                  }
                  else if (s[i] >= 'a' && s[i] <= 'z')
                  {
                        // continuation of name ;
                        name += s[i];
                  }
                  else
                  {
                        // now this is count ;
                        count += s[i];
                  }
            }

            //  we have our ordered map ready , just need to fetch ans ;
            string ans = "" ;
            for (auto it : mp)
            {
                  ans += it.first;
                  if (it.second != 1)
                  {
                        ans += to_string(it.second);
                  }
            }

            return ans;
      }
};



int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      // int ans = countOfAtoms(string formula);

      return 0;
}