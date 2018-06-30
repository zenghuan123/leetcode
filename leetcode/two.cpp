#include"stdafx.h"
int two::Solution::maxArea(vector<int>& height) {

	//ע�⵽����� �������е���Сֵ�йأ���������̶���Сֵ�ƶ�����Ǹ�λ�ñ����õ������һ���ȵ�ǰ���С
	//����ÿ�μ���󣬶��ƶ�С���Ǹ���ȥ���������û�б���������϶�Ҫ������һ���Ѿ������������С
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