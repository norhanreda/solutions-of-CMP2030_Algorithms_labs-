#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<unordered_map>
#include<utility>
#define INT_MAX 10e6
using namespace std;


class node
{
public:
    long long data;
    node* left;
    node* right;
    node* nested;
    node(int val)
    {
        data = val;
        left = right = nullptr;
    }
    node()
    {
        data = -1;
        left = right = nullptr;
    }

};
/////////////////////////////////////////
void newinsert(vector<node*> v, long long n, long long e, char* arrh, long long* arrp, long long* arrc, long long* arr)
{

    for (int j = 0; j < e; j++)
    {
        if (arrh[j] == 'L')
        {
            v[arrp[j]]->left = v[arrc[j]];
        }
        else if (arrh[j] == 'R')
        {
            v[arrp[j]]->right = v[arrc[j]];

        }


    }

}


///////////////////////////////////////

void inOrder(node* root)
{
    if (root != NULL)
    {

        cout << root->data << " ";
        inOrder(root->left);
        inOrder(root->right);
    }
}




////////////////////////////////////
/*int check(node * root,int r)
{





}*/


long long sum(node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return sum(root->left) + sum(root->right) + root->data;
}

void check(vector<node*>v, long long n, long long r, long long& count)
{
    for (long long i = 0; i < n; i++)
    {
        long long ls = sum(v[i]->left);
        long long rs = sum(v[i]->right);
        if (abs(ls - rs) <= r)
            count++;
    }
}




int main()
{

    long long n, r;
    cin >> n >> r;
    long long* arr = new long long[n];

    for (long long i = 0; i < n; i++)
        cin >> arr[i];


    long long e;
    cin >> e;

    char* arrh = new char[e];
    long long* arrp = new long long[e];
    long long* arrc = new long long[e];

    for (long long i = 0; i < e; i++)
        cin >> arrh[i] >> arrp[i] >> arrc[i];


    vector<node*> p(n);
    for (int i = 0; i < n; i++)
    {
        p[i] = new node(arr[i]);
    }
    newinsert(p, n, e, arrh, arrp, arrc, arr);
    long long count = 0;
    check(p, n, r, count);
    cout << count << endl;

    return 0;
}