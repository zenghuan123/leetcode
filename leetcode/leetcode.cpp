// leetcode.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int main()
{
	one::Solution s;
	vector<int> vec1;
	vector<int> vec2;
	vec1.push_back(4);
	double i = s.findMedianSortedArrays(vec1,vec2);
	cout << i << endl;
    return 0;
}