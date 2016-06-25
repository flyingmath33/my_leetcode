/*
  Find the kth largest element in an unsorted array. 
  Note that it is the kth largest element in the sorted order, not the kth distinct element.
  For example,
  Given [3,2,1,5,6,4] and k = 2, return 5.
  Note: 
  You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

int Partition(vector<int>& nums, int start, int end)
{
	int index = start + (end + 1 - start) / 2;
	swap(nums[index], nums[end]);
	int l = start - 1;
	for (int i = start; i < end; ++i)
	{
		if (nums[i] <= nums[end])
			swap(nums[++l], nums[i]);
	}
	swap(nums[end], nums[++l]);
	return l;
}

int findKthLargest(vector<int>& nums, int k) {
	if (nums.empty())
		return INT_MIN;
	
	int start = 0;
	int end = nums.size() - 1;
	int index = -1;
	while (k > 0)
	{
		index = Partition(nums, start, end);
		int right_size = end + 1 - index;
		if (right_size == k)
			break;
		else if (right_size > k)
		{
			start = index + 1;  
			// Since the size of the subarray from index to the end is bigger than k,
			// you only need to consider the sub-array from the next element of index + 1.
		}
		else
		{
			k -= right_size;
			end = index - 1;
			// Since the sub-array from the index is smaller than k,
			// you only need to consider the sub-array end with the index - 1.
		}
	}
	
	return nums[index];
}