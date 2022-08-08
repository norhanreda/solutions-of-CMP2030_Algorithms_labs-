#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;


long long ObstaclesGame(long long** arr, long long n, long long m, long long i, long long j, long long** db)
{

    if (i >= n || j >= m || arr[i][j] == -1)
        return 0;


    if (i == n - 1 && j == m - 1 && arr[i][j] == 0)
        return db[i][j] = 1;

    else
    {
        if (db[i][j] != LLONG_MIN)
            return db[i][j];
        return db[i][j] = ObstaclesGame(arr, n, m, i + 1, j, db) + ObstaclesGame(arr, n, m, i, j + 1, db);

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


    cout << ObstaclesGame(arr, n, m, 0, 0, db) << endl;

    /* for(long long i=0;i<n;i++)
      {
          for(long long j=0;j<m;j++)
             cout<<db[i][j]<<" ";
          cout<<endl;
      }*/

      //check
     /* for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
               cout<<arr[i][j]<<" ";
          cout<<endl;
      }*/

    return 0;
}
