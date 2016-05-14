#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    int max_freq = INT_MIN;
    for(int i = 0; i < nums.size(); ++i)
    {
	if(freq.find(nums[i]) != freq.end())
	    ++freq[nums[i]];
	else
	    freq[nums[i]] = 1;

	max_freq = max(max_freq, freq[nums[i]]);
    }

    vector<vector<int> > bucket(max_freq + 1, vector<int>());
    for(unordered_map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it)
	bucket[it->second].push_back(it->first);

    vector<int> result(k, INT_MIN);
    for(int i = 0, index = bucket.size() - 1; i < k; ++i)
    {
	result[i] = bucket[index][bucket[index].size() - 1];
	bucket[index].pop_back();
	if (bucket[index].empty())
	    for (--index; index >= 0 && bucket[index].empty(); --index) {}
    }

    return result;
}

int main()
{
    vector<int> v({5,3,1,1,1,3,73,1});
    vector<int> r = topKFrequent(v, 2);
    for(int i = 0; i < r.size(); ++i)
	cout << r[i];
    cout << endl;
    return 1;
}
