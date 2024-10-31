#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline ll get_score(string& name){
      ll score = 0 ;

      for(char c : name){
            score += ( c - 'A' ) + 1;
      }

      return score;
}

int main(){
      vector<string> names ;

      ifstream inputFile("D:/VS CODE/Project Euler/0022_names.txt");

      if(!inputFile){
            cout << "issue opening file" << endl;
            return 0;
      }

      string name;

      while(getline(inputFile , name , ',')){
            names.push_back(name.substr(1 , name.length()-2));
      }

      inputFile.close();

      sort(names.begin(), names.end());

      ll ans = 0 ;

      // for(int i = 0 ; i < 10 ; i++) cout << names[i] << endl;
      int n = names.size();
      for( int i = 0 ; i < n; i++){
            ll score = get_score(names[i]);
            // cout << score << endl;
            ans += score * (ll)(i + 1);
      }

      cout << " ans -> " << ans << endl;

      return 0;
}