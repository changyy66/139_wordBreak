// 139_wordBreak.cpp : 定义控制台应用程序的入口点。
//
/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
	 示例 3：

	 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
	 输出: false

	 来源：力扣（LeetCode）
	 链接：https://leetcode-cn.com/problems/word-break
	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
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

