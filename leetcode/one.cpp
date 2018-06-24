#include "stdafx.h"
/*
	vector<int> oneDay::Solution::twoSum(vector<int>& nums, int target) {

			(vector<int>::iterator it = nums.begin();
			unordered_map<int, int> map;
			int index = 0;
			while (it != nums.end())
			{
				map[index] = *it;
				index++;
				it++;
			}
			it = nums.begin();
			while (it != nums.end())
			{
				int iTamp = target - *it;
				unordered_map<int, int>::iterator findResult = map.find(iTamp);
				if (findResult != map.end())
				{
					vector<int>result;
					result.push_back(distance(nums.begin(), find(nums.begin(), nums.end(), *it)));
					result.push_back(distance(nums.begin(), find(nums.begin(), nums.end(),iTamp)));
					return result;
				}
				it++;
			}

		}
		*/

vector<int> one::Solution::twoSum(vector<int>& nums, int target) {
	vector<int>::iterator it = nums.begin();
	while (it != nums.end()) {
		int subNum = target - *it;
		vector<int>::iterator findResult = find(nums.begin(), nums.end(), subNum);
		if (findResult != nums.end() && findResult != it)
		{
			int i1 = distance(nums.begin(), it);
			int i2 = distance(nums.begin(), findResult);
			vector<int> result;
			result.push_back(i1);
			result.push_back(i2);
			//result.insert(nums.end(),1,i2);
			//赋值构造
			return result;
		}
		it++;
	}
	return vector<int>();
}
void one::Solution::testTwoSum() {
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);
	//nums.push_back(10);
	vector<int> result = this->twoSum(nums, 6);
	cout << result[0] << " " << result[1] << endl;
}
one::ListNode* one::Solution::addTwoNumbers(one::ListNode* l1, one::ListNode* l2) {
	if (l1 == NULL) {
		return l2;
	}
	if (l1 == NULL) {
		return l1;
	}
	ListNode*first = NULL;
	ListNode* listNode = NULL;

	int carryBit = 0;
	ListNode* sum = new ListNode(0);
	sum->val = l1->val + l2->val + carryBit;
	carryBit = sum->val / 10;
	sum->val = sum->val % 10;
	listNode = sum;
	first = sum;
	l1 = l1->next;
	l2 = l2->next;
	while (l1 != NULL || l2 != NULL) {
		ListNode* sum = new ListNode(0);
		if (l1 == NULL) {
			sum->val = l2->val + carryBit;
		}
		else if (l2 == NULL)
		{
			sum->val = l1->val + carryBit;
		}
		else {
			sum->val = l1->val + l2->val + carryBit;
		}
		carryBit = sum->val / 10;
		sum->val = sum->val % 10;
		listNode->next = sum;
		listNode = sum;
		if (l1 != NULL)
			l1 = l1->next;
		if (l2 != NULL)
			l2 = l2->next;
	}
	if (carryBit != 0) {
		ListNode *sum = new ListNode(0);
		sum->val = carryBit;
		listNode->next = sum;
	}
	return first;


}
int one::Solution::lengthOfLongestSubstring(string s) {
	unordered_set<char> set;
	int result = 0;
	int left = 0;
	int right = 0;
	while (left < s.size() && right < s.size()) {
		if (set.find(s.at(right)) == set.end()) {
			//没有找到
			set.insert(s.at(right));
			right++;
			//因为已经right++的缘故所以下面不用加1
			if (right - left > result)
			{
				result = right - left;
			}
		}
		else {
			//在set里找到了说明从left往后找最大的字符串就是 left->right了所以应该改变left的位置了
			set.erase(s.at(left));
			left++;
			//不能增加right还有把当前的right加到set中
		}

	}
	return result;
}
double one::Solution::findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
	//best 
	//把两组数据分成相等大小的两份leftpart和rightpart 
	//那么中间值在leftpart的最左边和right的最右边产生

	//防止出现负数 j=mid-i; nums1.size必须小于等于nums2.size
	

	return 0.0;
	/*
	* n的复杂度
	vector<int>::iterator it1=nums1.begin();
	vector<int>::iterator it2 = nums2.begin();
	int midIndexLeft = (nums1.size() + nums2.size()+1) / 2;
	int midLeft = 0;
	while (midIndexLeft)
	{
		int i1 = it1 == nums1.end() ? INT_MAX : *it1;
		int i2 = it2 == nums2.end()? INT_MAX : *it2;
		if (i1 < i2) {
			midLeft = i1;
			it1++;
		}
		else {
			midLeft = i2;
			it2++;
		}
		midIndexLeft--;
	}
	if ((nums1.size() + nums2.size()) % 2) {
		return midLeft;
	}
	else {
		int i1 = it1 == nums1.end() ? INT_MAX : *it1;
		int i2 = it2 == nums2.end() ? INT_MAX : *it2;
		if (i1 < i2) {
			return ((double)i1 + (double)midLeft) / 2.0;
		}
		else {
			return ((double)i2 + (double)midLeft) / 2.0;
		}
		}

	*/

}
string one::Solution::longestPalindrome(string s) {

	int maxLen = 0;
	int startIndex = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int len1 = judge(s, i, i);
		int len2 = judge(s, i, i + 1);
		int len = len1 > len2 ? len1 : len2;
		if (len > maxLen) {
			maxLen = len;
			startIndex = i - (len - 1) / 2;
		}
	}
	return s.substr(startIndex, maxLen);

}
int one::Solution::judge(string s, int left, int right) {
	while (left >= 0 && right < s.size())
	{
		if (s.at(left) == s.at(right))
		{
			left--;
			right++;
			continue;
		}
		else {
			break;
		}
	}
	return right - left - 1;
}
int one::Solution::reverse(int x) {

	int result=0;
	do {
		int i = x % 10;
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && i>7))
		{
			return 0;
		}
		if (result < INT_MIN / 10 || (result == INT_MIN / 10&&i<-8))
		{
			return 0;
		}
		result = result * 10;
		result += i;
		x = x / 10;
	} while (x!= 0);
	return result;

}
int one::Solution::myAtoi(string str) {
	int result = 0;
	bool first = true;
	bool minus= false;
	for (int i = 0; i < str.size(); i++)
	{
		if (str.at(i) < 58 && str.at(i) >= 48) {
			first = false;
			int addition = (int)str.at(i) - 48;
			//边界返回值取巧了
			if (result > INT_MAX / 10 || (result == INT_MAX / 10 && addition>7))
			{
				if (minus) {
					
					return INT_MIN;
				}
				else {
					return INT_MAX;
				}
				
			}
			result = result * 10 + addition;
		}
		else if (str.at(i) == ' '&&first)
		{
			continue;
		}else if (str.at(i) == '-'&&first) {
			minus = true;
			first = false;
		}
		else if (str.at(i) == '+'&&first) {
			first = false;
		}else  {
			first = false;
			break;
		}
	}
	if (minus)
		return -result;
	else
		return result;


}
bool one::Solution::isPalindrome(int x) {
	if (x < 0 || (x % 10 == 0 && x != 0)) {
		return false;
	}
	int y = x;
	int i = 0;
	while (x != 0) {
		i = i * 10 + x % 10;
		x = x / 10;
	}
	return y == i;
}
bool one::Solution::isMatch(string s, string p) {
	vector<string> vec;
	int i = -1;
	int j = 0;
	bool up = true;
	while (j < p.size())
	{
		char temp[3];

		if (j + 1 < p.size()&& p.at(j + 1) == '*')
		{

			temp[0] = p.at(j);
			temp[1] = p.at(j+1);
			temp[2] = '\0';
			vec.push_back(temp);
			i++;
			j++;
			j++;
			up = true;
			continue;
		}
		else 
		{
			if (up) {
				vec.push_back(string(""));
				i++;
				up=false;
			}
			temp[0] = p.at(j);
			temp[1] = '\0';
			temp[2] = '\0';
			string str(temp);
			vec.at(i).append(str);
			j++;
		}
		
	}

	i = 0; j = 0;
	while (true) 
	{
		if (i >= vec.size()) {
			return j ==s.size();
		}
		if (j >= s.size()) {
			i++;
			for (; i < vec.size(); i++) {
				string temp = vec.at(i);
				if (temp.at(temp.size() - 1) != '*') {
					return false;
				}
			}
			return true;
		}

		bool haveStar = vec.at(i).at(vec.at(i).size() - 1) == '*';
		if (match(s, j,vec.at(i)))
		{
			j=j+ vec.at(i).size()-haveStar;
			if (haveStar) {
				continue;
			}
			else {
				i++;
				continue;
			}
		}
		else if(haveStar) {
			
			i++;
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}
bool one::Solution::match(string s,int startIndex,string simpleP){
	int i = 0;
	int addtion = simpleP.at(simpleP.size() - 1) == '*' ? 1 : 0;
	while (i<simpleP.size()-addtion) {
		if (simpleP.at(i) == '.') 
		{
			i++;
		}else
		{
			if (i + startIndex >= s.size()) {
				return false;
			}
			if (simpleP.at(i)==s.at(i+startIndex))
			{
				i++;
				continue;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}