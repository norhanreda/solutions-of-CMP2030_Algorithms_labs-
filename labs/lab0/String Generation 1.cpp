#include<iostream>
#include<vector>
#include<string>
using namespace std;

void correctsub(string s, vector<string> sub, int  k, int& count)
{
    int c = 0;
    for (int i = 0; i < sub.size(); i++)
    {
        if (s.find(sub[i]) != string::npos)
            c++;

    }
    if (c >= k) {
        count++;
    }

    return;
}

void generatestring(string s, int n, vector<string> stringlist, int& count, int k)
{
    if (s.length() == n)
    {
        correctsub(s, stringlist, k, count);
        return;
    }

    generatestring(s + "A", n, stringlist, count, k);
    generatestring(s + "B", n, stringlist, count, k);
    generatestring(s + "C", n, stringlist, count, k);
    generatestring(s + "D", n, stringlist, count, k);
    generatestring(s + "E", n, stringlist, count, k);
}



int main()

{
    int m, n, k;
    cin >> m >> n >> k;
    vector<string> s;
    string x;
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        s.push_back(x);
    }

    generatestring("", n, s, count, k);
    cout << count << endl;
    return 0;
}
