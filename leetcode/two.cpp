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