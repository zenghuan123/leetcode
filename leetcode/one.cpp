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
			//��ֵ����
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
			//û���ҵ�
			set.insert(s.at(right));
			right++;
			//��Ϊ�Ѿ�right++��Ե���������治�ü�1
			if (right - left > result)
			{
				result = right - left;
			}
		}
		else {
			//��set���ҵ���˵����left�����������ַ������� left->right������Ӧ�øı�left��λ����
			set.erase(s.at(left));
			left++;
			//��������right���аѵ�ǰ��right�ӵ�set��
		}

	}
	return result;
}
double one::Solution::findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
	//best 
	//���������ݷֳ���ȴ�С������leftpart��rightpart 
	//��ô�м�ֵ��leftpart������ߺ�right�����ұ߲���

	//��ֹ���ָ��� j=mid-i; nums1.size����С�ڵ���nums2.size
	

	return 0.0;
	/*
	* n�ĸ��Ӷ�
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
