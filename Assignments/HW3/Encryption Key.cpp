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
    int data;
    node* left;
    node* right;
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

////////////////////////////////



int treeheight(node* root)
{

    if (root == NULL)
        return 0;

    int l = treeheight(root->left);
    int r = treeheight(root->right);

    return ((l > r ? l : r) + 1);
}




void  minofeachlevel(node* root, vector<int>& min, int level)
{

    if (root != NULL)
    {

        minofeachlevel(root->left, min, level + 1);

        if (root->data < min[level])
            min[level] = root->data;

        minofeachlevel(root->right, min, level + 1);
    }
}



void levelsum(node* n, int l, int sum[])
{
    if (n == NULL)
        return;

    sum[l] += n->data;
    levelsum(n->left, l + 1, sum);
    levelsum(n->right, l + 1, sum);
}

void newinsert(vector<node*> v, int n, int e, char* arrh, int* arrp, int* arrc, int* arr)
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



int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];


    int e;
    cin >> e;

    char* arrh = new char[e];
    int* arrp = new int[e];
    int* arrc = new int[e];

    for (int i = 0; i < e; i++)
        cin >> arrh[i] >> arrp[i] >> arrc[i];


    vector<node*> p(n);
    for (int i = 0; i < n; i++)
    {
        p[i] = new node(arr[i]);
    }


    newinsert(p, n, e, arrh, arrp, arrc, arr);
    node* tree = p[0];

    ///////////////////////////
    int Treeheight = treeheight(tree);
    vector<int > t(Treeheight, INT_MAX);
    minofeachlevel(tree, t, 0);

    int l = tree->data % Treeheight;
    int k = t[l] % Treeheight;
    if (k == 0)
        k = 1;

    int* sum = new int[Treeheight];

    for (int i = 0; i < Treeheight; i++)
        sum[i] = 0;

    levelsum(tree, 0, sum);

    for (int i = 0; i < Treeheight; i += k) {
        cout << sum[i];
    }

    return 0;
}