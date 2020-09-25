# N皇后问题

## 题目链接

[力扣](https://leetcode-cn.com/problems/n-queens/)

## 方法一：基于集合的回溯

```cpp
class Solution {
private:
    vector<string> generateBoard(vector<int>& queens, int n)
    {
        vector<string> board = vector<string>();

        for(int i = 0; i < n; i++)
        {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.emplace_back(row);
        }
        return board;
    }

    void backTrack(vector<vector<string>>& ans, vector<int>& queens, int row, int n, unordered_set<int>& conlum, unordered_set<int>& diagonals1, unordered_set<int>& diagonals2)
    {
        if(row == n)
        {
            ans.emplace_back(generateBoard(queens, n));
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                if(conlum.find(i) != conlum.end())
                {
                    continue;
                }

                int diagonal1 = row + i;
                if(diagonals1.find(diagonal1) != diagonals1.end())
                {
                    continue;
                }

                int diagonal2 = row - i;
                if(diagonals2.find(diagonal2) != diagonals2.end())
                {
                    continue;
                }

                queens[row] = i;
                conlum.emplace(i);
                diagonals1.emplace(diagonal1);
                diagonals2.emplace(diagonal2);

                backTrack(ans, queens, row + 1, n, conlum, diagonals1, diagonals2);

                queens[row] = -1;
                conlum.erase(i);
                diagonals1.erase(diagonal1);
                diagonals2.erase(diagonal2);
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> queens(n, -1);
        unordered_set<int> conlum;
        unordered_set<int> diagonals1;
        unordered_set<int> diagonals2;

        vector<vector<string>> ans;

        backTrack(ans, queens, 0, n, conlum, diagonals1, diagonals2);

        return ans;
    }
};
```


## 方法二：基于位运算的回溯
