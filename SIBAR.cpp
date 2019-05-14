#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	
	cin >> n;

	vector<int> a(n), b(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i] >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<vector<int>> nums;

	int prev = -1;
	int num = 0;

	for (int i = 0, j = 0; ; )
	{
		if (i != a.size() && a[i] <= b[j])
		{
			++num;

			if (prev != a[i])
			{
				if (nums.size()) nums[nums.size() - 1][2] = a[i] - 1;
				nums.push_back(vector<int>(3));
				nums[nums.size() - 1][0] = num;
				nums[nums.size() - 1][1] = a[i];
				prev = a[i];
			}
			else
			{
				++nums[nums.size() - 1][0];
			}

			++i;
		}
		else
		{
			if (j == b.size()) break;

			--num;

			if (prev != -1)
			{
				prev = -1;

				nums[nums.size() - 1][2] = b[j];

				nums.push_back(vector<int>(3));
				nums[nums.size() - 1][0] = num;
				nums[nums.size() - 1][1] = b[j] + 1;
			}
			else
			{
				--nums[nums.size() - 1][0];
			}

			++j;
		}
	}

	sort(nums.begin(), nums.end(), greater<vector<int>>());

	int max = 0;

	vector<int> result;

	for (size_t i = 0; i < nums.size(); ++i)
	{
		if (nums[i][0] < max) break;

		for (int j = nums[i][1]; j <= nums[i][2]; ++j)
		{
			result.push_back(j);
		}

		max = nums[i][0];
	}

	sort(result.begin(), result.end());

	for (size_t i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
}
