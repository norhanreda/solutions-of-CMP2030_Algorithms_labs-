#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;


long long GoldCollector(long long** gold, long long n, long long m, long long i, long long j, long long** db)
{
    if (i > n - 1 || j > m - 1)
        return LLONG_MIN;
    if (i == n - 1 && j == m - 1)
        return db[i][j] = gold[i][j];
    else
    {
        if (db[i][j] != LLONG_MIN)
            return db[i][j];
        else {
            return db[i][j] = gold[i][j] + max(GoldCollector(gold, n, m, i + 1, j, db), max(GoldCollector(gold, n, m, i, j + 1, db), GoldCollector(gold, n, m, i + 1, j + 1, db)));



        }
    }
}






int main()
{
    long long n, m;
    cin >> n >> m;
    long long** arr = new long long* [n];
    for (long long i = 0; i < n; i++)
        arr[i] = new long long[m];

    for (long long i = 0; i < n; i++)
        for (long long j = 0; j < m; j++)
            cin >> arr[i][j];

    long long** db = new long long* [n];
    for (long long i = 0; i < n; i++)
        db[i] = new long long[m];

    for (long long i = 0; i < n; i++)
        for (long long j = 0; j < m; j++)
            db[i][j] = LLONG_MIN;


    cout << GoldCollector(arr, n, m, 0, 0, db) << endl;

    /* for(long long i=0;i<n;i++)
      {
          for(long long j=0;j<m;j++)
             cout<<db[i][j]<<" ";
          cout<<endl;
      }*/


      //check
      /*for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
               cout<<arr[i][j]<<" ";
          cout<<endl;
      }*/

    return 0;
}
