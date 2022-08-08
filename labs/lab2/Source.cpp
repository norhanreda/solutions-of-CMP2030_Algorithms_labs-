#include<iostream>
#include <algorithm>
#include <string>
#include<vector>
#include<set>
using namespace std;


int main()
{
    int n, m;


    cin >> n;
    vector<long long> result(n);
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        vector<int> v(m);
        for (int i = 0; i < m; i++)
            cin >> v[i];

        long long num = 0;
        for(int k=0;k<m;k++)
            for (int j = k+1; j < m; j++)
            {
                if (j > v[j] && v[j] > k && k > v[k])
                    num++;

            }
            
        result[i] = num;
    }
    for (int i = 0; i < n; i++)
        cout << result[i] << endl;
   

    return 0;
}