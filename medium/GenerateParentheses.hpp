#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> cbn;
        return backtracking(cbn, n, 0, 0, "");
    }

    vector<string> backtracking(vector<string> &cbn, int n, int opened, int closed, string s)
    {
        if (opened + closed == n * 2)
        {
            cbn.push_back(s);
            return cbn;
        }
        if (opened < n )
            backtracking(cbn, n, opened + 1, closed, s + '(');
        if (closed < opened)
            backtracking(cbn, n, opened, closed + 1, s + ')');
        return cbn;
    }
};
