// leetcode.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int main()
{
	one::Solution s;
	vector<int> vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vector<int> vec2;
	vec2.push_back(4);
	vec2.push_back(6);
	vec2.push_back(10);
	double i = s.findMedianSortedArrays(vec1,vec2);
	cout << i << endl;
    return 0;
}