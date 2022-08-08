#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void Arithmeticexpression(int number, int* num, vector<bool> isused, int n, bool& t, int index)
{
    if (index == n)
    {

        if (number == 27)
            t = true;


        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (!isused[i])
        {
            isused[i] = true;
            Arithmeticexpression(number + num[i], num, isused, n, t, index + 1);
            Arithmeticexpression(number - num[i], num, isused, n, t, index + 1);
            Arithmeticexpression(number * num[i], num, isused, n, t, index + 1);
            isused[i] = false;
        }
    }

}


int fact(int n)
{
    if (n > 1)
        return n * fact(n - 1);
    else
        return 1;
}


int main()

{
    int n = 5;

    //vector<int> v(n);
    int* v = new int[n];
    bool t = false;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;

        v[i] = x;

    }

    vector<bool> isused(n, false);
    vector<bool> o(fact(n), false);
    sort(v, v + n);


    for (int i = 0; i < fact(n); i++)
    {

        t = false;
        next_permutation(v, v + n);
        Arithmeticexpression(v[0], v, isused, n, t, 1);
        //cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] <<" "<< v[4] << " ";
        o[i] = t;
        //cout << o[i] << endl;
    }

    bool valid = false;
    for (int i = 0; i < fact(n); i++)
    {
        if (o[i] == true)
            valid = true;
    }
    if (valid)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;

    return 0;
}