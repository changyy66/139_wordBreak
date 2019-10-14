// 139_wordBreak.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int len = s.size();
		vector<int> pos;
		set<string> wordMap(wordDict.begin(), wordDict.end());
		bool isMatch = false;
		for (int i = 0; i < len; i++)
		{
			for (int j = pos.size() - 1; j >= 0; j--)
			{
				int var = pos[j];
				string tmp = s.substr(var + 1, i - var);
				if (isMatch = wordMap.count(tmp) > 0)
				{
					pos.push_back(i);
					break;
				}
			}
			if (!isMatch)
			{
				string tmp = s.substr(0, i + 1);
				isMatch = wordMap.count(tmp) > 0;
				if (isMatch)
				{
					pos.push_back(i);
				}
			}
		}
		return isMatch;
	}
};

int main()
{
	string s = "catsandog";
	vector<string> wordDict = { "cats", "dog", "sand", "and", "cat" };
	Solution s0;
	cout << s0.wordBreak(s, wordDict);
    return 0;
}

