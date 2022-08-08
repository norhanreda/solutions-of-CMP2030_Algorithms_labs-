#include<iostream>
#include<vector>
#include <climits>
using namespace std;

void getpath(vector<vector<vector<int>>> v, vector<vector<vector<bool>>> isused, int i, int j, int k, int n, int  currentcoast, int& mincoast, vector<int>& currentpath, vector<int>& minpath)
{
    isused[i][j][k] = true;
    currentcoast += v[i][j][k];
    currentpath.push_back(v[i][j][k]);

    if (i == n - 1 && j == n - 1 && k == n - 1)
    {

        if (currentcoast < mincoast)
        {
            mincoast = currentcoast;
            minpath = currentpath;
            //return;
        }

    }
    else
    {
        if (currentcoast < mincoast)
        {
            if (i + 1 < n && !isused[i + 1][j][k])
                getpath(v, isused, i + 1, j, k, n, currentcoast, mincoast, currentpath, minpath);

            if (j + 1 < n && !isused[i][j + 1][k])
                getpath(v, isused, i, j + 1, k, n, currentcoast, mincoast, currentpath, minpath);
            if (k + 1 < n && !isused[i][j][k + 1])
                getpath(v, isused, i, j, k + 1, n, currentcoast, mincoast, currentpath, minpath);
        }



    }
    isused[i][j][k] = false;
    currentcoast -= v[i][j][k];
    currentpath.pop_back();






}










int main()

{
    int n;
    cin >> n;
    vector<vector<vector<int>>> v(n, vector<vector<int>>(n, vector< int>(n)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                cin >> v[i][j][k];

    vector<vector<vector<bool>>> isused(n, vector<vector<bool>>(n, vector< bool>(n, false)));
    int mincoast = INT_MAX;
    vector<int> currentpath;
    vector<int> minpath;

    getpath(v, isused, 0, 0, 0, n, 0, mincoast, currentpath, minpath);
    cout << mincoast << endl;


    return 0;
}





