/*
6  合并排序数组
题目
合并两个排序的整数数组A和B变成一个新的数组。

样例
给出A=[1,2,3,4]，B=[2,4,5,6]，返回 [1,2,2,3,4,4,5,6]

挑战
你能否优化你的算法，如果其中一个数组很大而另一个数组很小？
求出短数组最大值在长数组中的最左索引idx，合并短数组和长数组[0,idx]部分，直接连接其剩余部分。
*/

class Solution {
public:
	/**
	* @param A and B: sorted integer array A and B.
	* @return: A new sorted integer array
	*/
	vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
		// write your code here
		if (A.empty())
		{
			return B;
		}//if
		else if (B.empty())
		{
			return A;
		}
		else{
			int lenA = A.size(), lenB = B.size();
			vector<int> ret(lenA + lenB, 0);
			if (lenA <= lenB)
			{
				int idx = binarySearch(B, A[lenA - 1]);
				idx = idx == -1 ? lenB : idx;
				int i = 0, j = 0, k = 0;
				while (i<lenA && j < idx)
				{
					if (A[i] <= B[j])
					{
						ret[k++] = A[i];
						++i;
					}
					else{
						ret[k++] = B[j];
						++j;
					}//else
				}//while

				while (i<lenA)
				{
					ret[k++] = A[i++];
				}//while

				while (j < idx)
				{
					ret[k++] = B[j++];
				}//while

				while (j < lenB)
				{
					ret[k++] = B[j++];
				}//while
			}//if
			else{
				int idx = binarySearch(A, B[lenB - 1]);
				idx = idx == -1 ? lenA : idx;
				int i = 0, j = 0, k = 0;
				while (i<idx && j<lenB)
				{
					if (A[i] <= B[j])
					{
						ret[k++] = A[i];
						++i;
					}
					else{
						ret[k++] = B[j];
						++j;
					}//else
				}//while

				while (i < idx)
				{
					ret[k++] = A[i++];
				}//while

				while (j < lenB)
				{
					ret[k++] = B[j++];
				}//while

				while (i < lenA)
				{
					ret[k++] = A[i++];
				}//while
			}//else
			return ret;
		}
	}

	int binarySearch(vector<int> A, int target)
	{
		if (A.empty())
		{
			return -1;
		}//if

		int low = 0, high = A.size() - 1;
		while (low < high)
		{
			int mid = (low + high) / 2;
			if (A[mid] == target)
			{
				return mid;
			}//if
			else if (A[mid] < target)
			{
				if (mid < high && A[mid + 1] >= target)
				{
					return mid + 1;
				}//if
				else
				{
					low = mid + 1;
				}//else
			}//elif
			else{
				if (mid > 0 && A[mid - 1] <= target)
				{
					return mid;
				}//if
				else{
					high = mid - 1;
				}//else
			}//else
		}//while
		return -1;
	}
};