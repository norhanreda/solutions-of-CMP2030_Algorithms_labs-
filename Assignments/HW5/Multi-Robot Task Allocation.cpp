#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<list>
using namespace std;




void dfs(vector<int> adjlist[], int v, bool isvisted[], list<int>& l)
{
    isvisted[v] = true;
    for (int i : adjlist[v])
    {
        if (isvisted[i] == false)
        {
            dfs(adjlist, i, isvisted, l);
        }
    }
    l.push_front(v);
}
void MultiRobotTaskAllocation(int n, vector<int> adjlist[], bool* isvisted, list<int>& l)
{




    for (int i = 0; i < n; i++)
    {
        if (isvisted[i] == false)
            dfs(adjlist, i, isvisted, l);
    }


}





int main() {

    int  n;
    cin >> n;
    int a, b;
    vector<int>* adjlist = new vector<int>[n];
    bool* isvisted = new bool[n];
    list<int> l;
    for (int i = 0; i < n; i++)
        isvisted[i] = false;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (a != -1)
            adjlist[a].push_back(i);
        if (b != -1)
            adjlist[b].push_back(i);


    }

    MultiRobotTaskAllocation(n, adjlist, isvisted, l);
    while (!l.empty())
    {
        cout << l.front() << " ";
        l.pop_front();
    }


    cout << endl;
    return 0;
}
