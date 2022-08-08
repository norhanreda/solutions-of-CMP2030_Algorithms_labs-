#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;

// Note: you won't need long long in this problem

int solve(vector<int>& L, int i, int j, vector<vector<int>>& memo) {

    // TODO: check if you solved the problem before (memoization) (add this part after you implement the whole function)

    // TODO: step 2: add base case

    // TODO: step 1: write the optimal structure for the solution using subproblems to get the minimum total cost

    // TODO: save the minimum total cost in memo (add this part after you implement the whole function)

    // TODO: return the minimum total cost

    //int q=0;
    if (i == j - 1)
        return 0;
    int min = INT_MAX;
    if (memo[i][j] != INT_MIN)
        return memo[i][j];
    for (int z = i + 1; z < j; z++)
    {

        int x = solve(L, i, z, memo) + solve(L, z, j, memo);
        if (x < min)
            min = x;

    }
    min += L[j] - L[i];
    memo[i][j] = min;
    return min;

}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> L(M);

    for (int i = 0; i < M; i++)
    {
        cin >> L[i];
    }

    // TODO: uncomment the following if they help you solve the problem
    L.insert(L.begin(), 0);
    L.push_back(N);


    // TODO: declare DP storage and call it memo
    vector<vector<int>> memo(L.size(), vector<int>(L.size(), INT_MIN));

    // This function call is for guidance and you can change it if you want
    cout << solve(L, 0, L.size() - 1, memo) << endl;

    return 0;
}