#include <bits/stdc++.h>
using namespace std;

const int MAX_BAKTERII = 1000010;

int rep[MAX_BAKTERII];
int masa[MAX_BAKTERII];
int maxIQ[MAX_BAKTERII];
int minIQ[MAX_BAKTERII];

int Find (int a) {
 if ( rep[a] == a )
    return a;
 rep[a] = Find ( rep[a] );
 return (rep[a]);
}

void Union(int a, int b){
 int x, y;
 
 x = Find(a);
 y = Find(b);
 if(x == y)
    return;
 rep[x] = rep[y];
 maxIQ[y] = max(maxIQ[y], maxIQ[x]);
 minIQ[y] = min(minIQ[y], minIQ[x]);
 masa[y] = masa[y] + masa[x];
}

int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);

 int liczba_bakterii;
 int bakteria1, bakteria2;
 int rep_bak_1, rep_bak2;
 char komenda[10];

 cin >> liczba_bakterii;

 for (int i = 1; i <= liczba_bakterii; i++)
    rep[i] = i;

 for (int i = 1; i <= liczba_bakterii; i++) {
    cin  >> masa[i] >> minIQ[i];
    maxIQ[i] = minIQ[i];
 }

 while( cin>>komenda ){ 
    switch (komenda[0]) {
       case 'J':
          cin >> bakteria1 >> bakteria2;
          Union(bakteria1, bakteria2);
          break;
       case 'M':
          cin >> bakteria1;
          rep_bak_1 = Find(bakteria1);
          cout << masa[rep_bak_1] << "\n";
          break;
       case 'I':
          cin >> bakteria1;
          rep_bak_1 = Find(bakteria1);
          if(komenda[4]=='A')
             cout << maxIQ[rep_bak_1] << "\n";
          else
             cout << minIQ[rep_bak_1] << "\n";
          break;
    }
 }

 return 0;
}
