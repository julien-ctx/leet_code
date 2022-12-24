#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> cbn;
        
        backtracking(cbn, n, 0, 0, "");
        return cbn;
    }

    void backtracking(vector<string> &cbn, int &n, int opened, int closed, string s)
    {
        if (opened + closed == n * 2)
        {
            cbn.push_back(s);
            return;
        }
        else if (opened < n)
        {
            s += '(';
            backtracking(cbn, n, opened + 1, closed, s);
        }
        else if (closed < n)
        {
            s += ')';
            backtracking(cbn, n, opened, closed + 1, s);
		}
    }
};
