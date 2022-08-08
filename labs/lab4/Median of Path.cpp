#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<unordered_map>
#include<utility>
#include<set>
#define INT_MAX 10e6
using namespace std;


class node
{
public:
    int data;
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





int sum(node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return sum(root->left) + sum(root->right) + root->data;
}




void check(node* root, multiset<int> path, int& count)
{


    if (root == NULL)
        return;

    path.insert(root->data);


    auto it = path.begin();
    advance(it, (path.size()) / 2);
    if (*it == root->data && path.size() % 2 != 0)
        count++;

    check(root->left, path, count);
    check(root->right, path, count);


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
    node* root = p[0];
    //inOrder(tree);

    multiset<int> s;
    int count = 0;
    check(root, s, count);
    cout << count << endl;

    return 0;
}