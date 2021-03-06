#include"stdafx.h"
int two::Solution::maxArea(vector<int>& height) {

	//注意到面积跟 两个数中的最小值有关，所以如果固定最小值移动最大那个位置遍历得到的面积一定比当前这个小
	//所以每次计算后，都移动小的那个点去遍历，最后没有遍历到的组合都要比至少一个已经遍历到的组合小
	int bigest = 0, l = 0, r = height.size() - 1;
	while (l < r) {
		bigest = max<int>(bigest,min<int>(height.at(l), height.at(r))*(r - l));
		if (height.at(l) < height.at(r))
		{
			l++;
		}
		else {
			r--;
		}
	}
	
	return bigest;

}
string two::Solution::intToRoman(int num) {
	string str[][10] = {
	{string("I"),string("II"),string("III"),string("IV"),string("V"),string("VI"),string("VII"),string("VIII"),string("IX")},
	{string("X"),string("XX"),string("XXX"),string("XL"),string("L"),string("LX"),string("LXX"),string("LXXX"),string("XC")},
	{string("C"),string("CC"),string("CCC"),string("CD"),string("D"),string("DC"),string("DCC"),string("DCCC"),string("CM")},
	{string("M"),string("MM"),string("MMM"),string("MMMM"),string("MMMMM")
	,string("MMMMMM"),string("MMMMMMM"),string("MMMMMMMM"),string("MMMMMMMMM") }
	};
	int j = 0;
	vector<string> vec;
	do {
		int i = num % 10 -1;
		if (i >= 0) {
			vec.push_back(str[j][i]);
		}
		num = num / 10;
		j++;
	} while (num != 0);
	string result;
	for (int i = vec.size() - 1; i >= 0; i--) 
	{
		result.append(vec.at(i));
	}
	return result;
}
int two::Solution::romanToInt(string s) {

	int result = 0;
	int lastAddtion = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int addtion = 0;
		switch (s.at(i)) {
		case 'I':addtion = 1; break;
		case 'V':addtion = 5; break;
		case 'X':addtion = 10; break;
		case 'L':addtion = 50; break;
		case 'C':addtion = 100; break;
		case 'D':addtion = 500; break;
		case 'M':addtion = 1000; break;
		}
		if (lastAddtion < addtion) {
			result -= lastAddtion * 2;
		}
		lastAddtion = addtion;
		result += addtion;
	}
	return result;

}
string two::Solution::longestCommonPrefix(vector<string>& strs) {
	//这个题目是从开始处找到相同的字符串
	if (strs.size() == 0)
		return string("");
	string result = strs.at(0);
	for (int i = 1; i < strs.size(); i++) {
		while (strs[i].find(result.c_str())!=0) {
			result.erase(result.size() - 1, 1);
		}
	}
	return result;

}