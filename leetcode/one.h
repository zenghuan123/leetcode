#pragma once
#include"stdafx.h"
namespace one {
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
		
	};
	class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target);
		void testTwoSum();
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
		int lengthOfLongestSubstring(string s);
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
		string longestPalindrome(string s);
		int reverse(int x);
		int myAtoi(string str);
		bool isPalindrome(int x);
	private:
		int judge(string s, int left, int right);
	};
}
