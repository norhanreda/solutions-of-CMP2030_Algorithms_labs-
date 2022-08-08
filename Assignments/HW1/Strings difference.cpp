#include<iostream>
#include<string>
#include<vector>

using namespace std;

int countchar(string s, char c)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == c)
            count++;
    }
    return count;
}


void string_difference(string s, int n, vector<string>& v, int h)
{
    if (s.length() == n)
    {

        int count = countchar(s, '1');

        if (count == h)
            v.push_back(s);

        return;
    }

    string_difference(s + "0", n, v, h);
    string_difference(s + "1", n, v, h);

}
int main()
{
    int n, h;
    cin >> n >> h;

    vector<string> v;
    string_difference("", n, v, h);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;


    return 0;
}