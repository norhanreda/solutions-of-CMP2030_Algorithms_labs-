#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// This code is used for guidance (you can change it if you want).

struct Node
{
    int index;
    int rating;
    Node* parent; // this is optional
    vector<Node*> children;
};


int maximumSum(Node* root, unordered_map <Node*, int>& memo)
{
    if (memo.find(root) != memo.end())
        return memo[root];
    int total = 0;
    int out = 0;
    int in = 0;
    for (auto it = root->children.begin(); it < root->children.end(); it++)
    {
        out += maximumSum(*it, memo);
    }
    for (auto its = root->children.begin(); its < root->children.end(); its++)
    {
        for (auto itg = (*its)->children.begin(); itg < (*its)->children.end(); itg++)
        {
            total += maximumSum(*itg, memo);
        }
    }
    in = root->rating + total;
    //memo.push_back(make_pair(root,0));
   // memo[memo.size()-1].second= max(in, out);

    return memo[root] = max(in, out);



}





int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // Number of nodes in the tree
    int N;
    cin >> N;

    vector<Node*> nodes(N);
    for (int i = 0; i < N; i++) {
        nodes[i] = new Node;
        nodes[i]->index = i;
        cin >> nodes[i]->rating;
    }

    // Iterating over all edges
    int parent, child;
    for (int i = 0; i < N - 1; i++) {
        cin >> parent >> child;
        nodes[child]->parent = nodes[parent];
        nodes[parent]->children.push_back(nodes[child]);
    }

    // TODO: Create a vector called 'memo' used for memoization (What is the dimensions of that vector?)

     //vector<pair<Node*, int> > memo;
    unordered_map<Node*, int> memo;
    // then uncomment the following line.
    cout << maximumSum(nodes[0], memo) << endl;

    return 0;
}