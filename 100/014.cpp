/*
  Write a function to find the longest common prefix string amongst an array of strings.
*/


string longestCommonPrefix(vector<string>& strs) {
	string prefix("");

	if(strs.empty())
		return prefix;

	prefix = strs[0];
	for(int i = 1; i < strs.size(); ++i)
	{
		for(int j = 0; j < prefix.size(); ++j)
		{
			if(prefix[j] != strs[i][j])
			{
				prefix = prefix.substr(0, j);
				break;
			}
		}
	}

	return prefix;
}
