#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;


long long TheJumpingGame(long long** score, long long n, long long m, long long i, long long j, long long** db)
{
    if (n == 0)
        return 0;
    if (i > n - 1 || j > m - 1)
        return 0;
    if (i == n - 1 && j == m - 1)
        return db[i][j] = score[i][j];
    else
    {
        if (db[i][j] != 0)
            return db[i][j];
        else {
            if (i == 0)
                return db[i][j] = score[i][j] + max(max(TheJumpingGame(score, n, m, i, j + 3, db), TheJumpingGame(score, n, m, i + 1, j + 1, db)), TheJumpingGame(score, n, m, i + 1, j + 2, db));

            else
                return db[i][j] = score[i][j] + max(max(TheJumpingGame(score, n, m, i - 1, j + 3, db), TheJumpingGame(score, n, m, i - 1, j + 1, db)), TheJumpingGame(score, n, m, i - 1, j + 2, db));

        }
    }
}






int main()
{
    long long n;
    cin >> n;
    long long** arr = new long long* [2];
    for (long long i = 0; i < 2; i++)
        arr[i] = new long long[n];

    for (long long i = 0; i < 2; i++)
        for (long long j = 0; j < n; j++)
            cin >> arr[i][j];

    long long** db = new long long* [2];
    for (long long i = 0; i < 2; i++)
        db[i] = new long long[n];

    for (long long i = 0; i < 2; i++)
        for (long long j = 0; j < n; j++)
            db[i][j] = 0;


    cout << max(TheJumpingGame(arr, 2, n, 0, 0, db), TheJumpingGame(arr, 2, n, 1, 0, db)) << endl;

    /* for(long long i=0;i<n;i++)
      {
          for(long long j=0;j<m;j++)
             cout<<db[i][j]<<" ";
          cout<<endl;
      }*/


      //check
     /* for(int i=0;i<2;i++)
      {
          for(int j=0;j<n;j++)
               cout<<arr[i][j]<<" ";
          cout<<endl;
      }*/

    return 0;
}
