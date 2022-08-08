#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
void Rotate(string& s)
{
    char x = s.at(0);
    s = s.substr(1, s.length() - 1);
    s = s + x;
}


void String_rearrangement(string s, vector<string> t, int i, int& count)
{



    if (i == t.size())
    {

        return;

    }
    while (s.compare(t[i]) != 0)
    {
        Rotate(t[i]);
        count++;

    }

    String_rearrangement(s, t, i + 1, count);



}

int main()
{

    int n;
    cin >> n;
    vector<string> v(n);

    for (int i = 0; i < v.size(); i++)
        cin >> v[i];

    string a = v[0];
    bool equal = true;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < v[i].length(); j++)
        {
            if (a.find(v[i][j]) == string::npos)
                equal = false;
        }
    }
    int q;
    int count = 0;
    if (equal == true)
    {
        set<int> x;
        for (int i = 0; i < v.size(); i++)
        {
            string z = v[i];

            String_rearrangement(z, v, 0, count);
            x.insert(count);
            count = 0;
        }


        auto it = x.begin();
        auto ite = x.end();
        q = *it;
        ite--;

    }
    else
        q = -1;
    cout << q << endl;

    return 0;
}