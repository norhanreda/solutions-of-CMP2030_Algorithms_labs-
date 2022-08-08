#include <vector>
#include<string>
#include <iostream>
using namespace std;


void ArrangeSeats(vector<string> s, vector<bool> isused, int index, vector<string>& seq, int& count)

{
    if (s.size() == index)
    {
        bool flag = false;
        for (int i = 0; i < (int)seq.size() - 1; i++)
        {
            if (seq[i].back() == seq[i + 1].front())
            {
                flag = true;

                return;
            }
        }
        if (flag == false)
            count++;
        return;


    }
    for (int i = 0; i < s.size(); i++)
    {
        if (!isused[i])
        {
            isused[i] = true;
            seq.push_back(s[i]);
            ArrangeSeats(s, isused, index + 1, seq, count);
            seq.pop_back();
            isused[i] = false;
        }
    }

}




int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<string> seq;
    int count = 0;
    vector<bool> isused(n, false);
    ArrangeSeats(s, isused, 0, seq, count);
    cout << count << endl;

    return 0;
}

