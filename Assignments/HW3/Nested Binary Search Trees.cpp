#include <cmath>
#include <cstdio>
#include <vector>
#include<unordered_map>
#include <iostream>
#include <algorithm>
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






class bst {


public:
    node* root;

    node* insert(int val, node* t)
    {
        if (t == NULL)
        {
            t = new node;
            t->data = val;
            t->left = t->right = NULL;


        }

        else if (val > t->data)
            t->right = insert(val, t->right);
        else if (val < t->data)
            t->left = insert(val, t->left);
        return t;
    }





    void printin(node* t) {
        if (t == NULL)
            return;
        printin(t->left);
        cout << t->data << " ";
        printin(t->right);
    }

    node* findanode(node* t, int val) {
        if (t == NULL)
            return NULL;
        else if (val < t->data)
            return findanode(t->left, val);
        else if (val > t->data)
            return findanode(t->right, val);
        else
            return t;
    }


    void  getlength(node* t, int x, int& len)
    {
        if (t == NULL)
            return;

        if (t->data == x)
            len++;

        else if (x < t->data)
        {
            len++;
            getlength(t->left, x, len);
        }

        else if (x > t->data)
        {
            len++;
            getlength(t->right, x, len);

        }


    }




public:
    bst() {
        root = NULL;
    }

    ~bst() {
        root = NULL;
    }

    void insert(int x) {
        root = insert(x, root);

    }


    void display() {
        printin(root);
        cout << endl;
    }

    bool search(int val) {
        node* t;
        t = findanode(root, val);
        if (t)
            return true;
        else
            return false;


    }
};




//  this function makes the array unique with the same order


void uni(int* a, int& n)
{

    int u[100000] = { 0 };

    int j = 0;


    for (int i = 0; i < n; i++)

    {
        if (u[a[i]] == 0)
        {
            u[a[i]] = 1;
            a[j++] = a[i];
        }

    }

    n = j;

}





int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    int* x = new int[n]; //values of key
    int* y = new int[n];// values of id


    int* z = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        z[i] = x[i];
    }
    bst b;

    int tree1count = n;
    uni(z, tree1count);//unique values for key 



    for (int i = 0; i < tree1count; i++)
    {

        b.insert(z[i]); //insertion of keys  unique values
    }


    bst* nestedtrees = new  bst[tree1count];



    unordered_map<int, bst> m;
    unordered_map<int, int> nono;
    unordered_map<int, int> yes;
    for (int i = 0; i < tree1count; i++)
    {
        nono[i] = z[i];
        yes[z[i]] = i;

    }



    for (int i = 0; i < n; i++) //build an id key for each key
    {

        if (x[i] == nono[yes[x[i]]])
        {
            nestedtrees[yes[x[i]]].insert(y[i]);
            m[yes[x[i]]] = nestedtrees[yes[x[i]]];
        }


    }

    // this part was fot test each tree

   /*b.display();
    for(int i=0;i<tree1count;i++)
        nestedtrees[i].display();*/

        ////////////////// well !


        ///////////////////////////////////




        ///////////////////////////////////


    int e, d;
    int g;
    int len1 = 0;
    int len2 = 0;
    int len3 = 0;

    for (int k = 0; k < q; k++)
    {
        len1 = 0;
        len2 = 0;
        len3 = 0;

        g = 0;
        cin >> e >> d;
        b.getlength(b.root, e, len1);
        if (b.search(e)) //if key exists
        {
            m[yes[e]].getlength(m[yes[e]].root, d, len2);

            if (m[yes[e]].search(d)) //search for id
            {


                g = 1;
            }
            else//id doesn't exist
            {

                g = 0;

            }
        }
        else

        {
            len2 = 0;
        }

        len3 = len1 + len2;
        cout << len3 << " " << g << endl;
    }





    return 0;
}
