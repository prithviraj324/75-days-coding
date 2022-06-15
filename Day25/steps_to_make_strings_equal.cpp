#include<bits/stdc++.h>
using namespace std;
//brute force exponential solution
class Solution {
public:
    int minDistance(string& word1, string& word2) {
	    return solve(word1, word2, 0, 0);
    }
    // recursive solver to find minimum deletions to equalize w1 & w2
    int solve(string w1, string w2, int i, int j) {
        if(i == w1.size() && j == w2.size()) return 0;  // reached end of both strings -> both strings have been equalized and no further steps required
        if(i == w1.size()) return w2.size() - j;        // reached end of word1 -> need to delete remaining characters of word2 to equalize
        if(j == w2.size()) return w1.size() - i;        // reached end of word2 -> need to delete remaining characters of word1 to equalize
        if(w1[i] == w2[j]) return solve(w1, w2, i + 1, j + 1);  // no deletion required since the characters already match
        // 1 current character deletion + min(after deleting w1[i], after deleting w2[j])
        return 1 + min(solve(w1, w2, i + 1, j), solve(w1, w2, i, j + 1));
    }
};
//top down memoized
class Solution2 {
    vector<vector<int> >dp;
    int minDistance(string& word1, string& word2) {
        // dp[i][j] will denote minimum steps required to equalize word1[i:end] and word[2:j:end]
        dp.resize(word1.size() + 1, vector<int>(word2.size() + 1, 1000));
        return solve(word1, word2, 0, 0);
    }
    int solve(string &w1, string &w2, int i, int j) {
        if(i == w1.size() && j == w2.size()) return 0;
        if(i == w1.size() || j == w2.size()) return max(w1.size() - i, w2.size() - j);
        if(dp[i][j] != 1000) return dp[i][j];  // directly return stored answer if already computed before
        if(w1[i] == w2[j]) return solve(w1, w2, i + 1, j + 1);
        return dp[i][j] = 1 + min(solve(w1, w2, i + 1, j), solve(w1, w2, i, j + 1));
    }
};
//bottom up tabulated
class Solution3 {
public:
    int minDistance(string& word1, string& word2) {        
        vector<vector<int> >dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for(int i = 0; i <= word1.size(); i++) 
            for(int j = 0; j <= word2.size(); j++) 
                if(!i || !j) dp[i][j] = i + j; // if one word == "", all other characters of other word need to be deleted
                //                if characters match        ?  dont delete     : 1 deletion + min to equalize after deletion of (word1[i], word2[j])
                else dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : 1 + min(dp[i - 1][j], dp[i][j - 1]);
        return dp[word1.size()][word2.size()];
    }
};