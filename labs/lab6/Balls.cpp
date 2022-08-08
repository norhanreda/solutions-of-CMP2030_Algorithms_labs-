#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void Balls(long long s, long long a, long long b, long long& ca, long long& cb, long long& r)
{
    long long q;
    //long long q1;
    q = s;
    int tca = 0;
    int tcb = q / b;
    r = s;


    while (q >= 0)
    {



        tcb = q / b;
        int tr = q % b;

        q = q - a;
        tca++;
        if (tr < r) {
            r = tr;
            ca = tca;
            cb = tcb;
        }
        if (r == 0)
            return;
    }


}


int main() {

    long long s, a, b;
    cin >> s >> a >> b;
    long long ca, cb, r;
    r = 1;
    if (s < a && s < b)
        cout << 0 << " " << 0 << " " << s << " " << endl;
    else
    {
        Balls(s, a, b, ca, cb, r);


        cout << ca - 1 << " " << cb << " " << r << " " << endl;
    }

    return 0;
}
