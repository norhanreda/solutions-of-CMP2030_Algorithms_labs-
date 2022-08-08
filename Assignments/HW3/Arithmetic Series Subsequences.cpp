#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int getsubsequencescount(int arr[], int n, int d, int m)
{


    int count = 0;

    if (m == 2)
    {

        unordered_map<int, int> hash;




        for (int i = 0; i < n; i++)
        {



            if (hash.find(arr[i] - d) != hash.end())
                count += hash[(arr[i] - d)];

            hash[arr[i]]++;
        }

    }
    else if (m == 3)
    {

        unordered_map<int, int> before;
        unordered_map<int, int> after;



        for (int i = 0; i < n; i++)
        {

            after[arr[i]]++;

        }

        for (int i = 0; i < n; i++)
        {

            if (before.find(arr[i] - d) != before.end() && after.find(arr[i] + d) != after.end())
                count += (before[arr[i] - d]) * (after[arr[i] + d]);

            before[arr[i]]++;
            after[arr[i]]--;





        }
    }





    return count;

}





int main()
{
    int n, d, m;
    cin >> n >> d >> m;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << getsubsequencescount(arr, n, d, m) << endl;

    return 0;
}

