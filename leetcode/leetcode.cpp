// leetcode.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int main()
{
	
	two::Solution s;
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(5);
	cout << s.maxArea(vec) << endl;
    return 0;
}