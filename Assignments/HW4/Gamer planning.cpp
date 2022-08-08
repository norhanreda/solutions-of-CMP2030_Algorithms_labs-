#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool sortbypenalty(const pair<int, int>& a1, const pair<int, int>& a2)
{
    return (a1.second > a2.second);
}

void Gamerplanning(pair<int, int>* v, int n, long long& val, int maxd)
{
    int s[100000];
    int chosen = 0;
    int q;
    for (int i = 1; i <= maxd; i++)
    {
        s[i] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        q = min(maxd, v[i - 1].first);
        while (q >= 1)
        {
            if (s[q] == -1)
            {
                s[q] = i - 1;
                chosen++;
                break;
            }
            else
                q--;
        }


        if (chosen == maxd)
        {
            break;
        }
    }


    for (int i = 1; i <= maxd; i++)
    {
        //if(v[s[i]].second>0)
        val += v[s[i]].second;
    }
    //cout<<val<<endl;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i].second;
    }

    val = sum - val;




}





int main()
{

    int n;
    cin >> n;

    int* d = new int[n];
    int* p = new int[n];
    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int i = 0; i < n; i++)
        cin >> p[i];

    /*vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    v.push_back(make_pair(d[i],p[i]));*/

    pair<int, int >* a = new pair<int, int>[n];
    for (int i = 0; i < n; i++)
        a[i] = make_pair(d[i], p[i]);

    long long val = 0;
    sort(a, a + n, sortbypenalty);
    /*for(int i=0;i<n;i++)
        cout<<a[i].first<<" "<<a[i].second<<endl;*/
    int maxd = d[0];
    for (int i = 0; i < n; i++)
    {
        if (d[i] > maxd)
            maxd = d[i];
    }
    /* int *s=new int[n];
     for(int i=0;i<maxd;i++)
         s[i]=0;*/

    Gamerplanning(a, n, val, maxd);

    cout << val << endl;

    return 0;
}
