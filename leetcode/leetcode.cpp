// leetcode.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int main()
{
	two::Solution s;
	vector<string> vec;
	vec.push_back(string("abcdef")); 
	vec.push_back(string("abcadf"));
	vec.push_back(string("abcew"));
	cout << s.longestCommonPrefix(vec).c_str() <<endl;
    return 0;
}