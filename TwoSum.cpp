// leetcode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
struct MyNode
{
	int val;
	int index;
};

int _cdecl comp(const void* a,const void* b)
{
	return (((MyNode*)a)->val > ((MyNode*)b)->val);
}
class Solution {
	
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<MyNode> tmp(nums.size());
		for (int i = 0; i < nums.size(); i++)
		{
			tmp[i].index = i;
			tmp[i].val = nums.at(i);
		}
		qsort(tmp.data(), tmp.size(), sizeof(MyNode),comp);

		size_t _size = tmp.size();
		int i1 = 0;
		int i2 = _size-1;
		int sum = 0;
		while (i1<=i2)
		{
			sum = tmp.at(i1).val + tmp.at(i2).val;
			if (sum == target)
			{
				vector<int> re;
				if (tmp.at(i1).index > tmp.at(i2).index)
				{
					re.push_back(tmp.at(i2).index + 1);
					re.push_back(tmp.at(i1).index + 1);
				}
				else
				{
					re.push_back(tmp.at(i1).index + 1);
					re.push_back(tmp.at(i2).index + 1);
				}
				return re;
			}
			if (sum < target) i1++;
			if (sum > target) i2--;
		}

	}
};

//int main()
//{
//	Solution test;
//	int a[] = { 0,4,2,0 };
//	int target = 6;
//	vector<int> b(a, a+4);
//	vector<int> c = test.twoSum(b, target);
//	cout << c[0] << ' ' << c[1] << endl;
//	cin >> target;
//    return 0;
//}

