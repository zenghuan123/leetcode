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