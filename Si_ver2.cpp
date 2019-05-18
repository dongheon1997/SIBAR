#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b)
{
	if (a[0] > b[0]) return 1;
	else if (a[0] == b[0]) return a[1] < b[1];
	else return 0;
}

int main()
{
	int num;
	cin >> num;

	vector<vector<int>> times;//{ time, -1 or 1 }
	int temp;

	for (int i = 0; i < num * 2; ++i)
	{
		cin >> temp;
		times.push_back(i % 2 ? vector<int>{ temp + 1, -1 } : vector<int>{ temp, 1 });
	}

	sort(times.begin(), times.end());
	
	num = 0;
	temp = -1;

	vector<vector<int>> nums;//{ num, begin, end }

	for (size_t i = 0; i < times.size(); ++i)
	{
		num += times[i][1];

		if (times[i][0] != temp)
		{
			if (nums.size()) nums[nums.size() - 1][2] = times[i][0] - 1;
			nums.push_back(vector<int>{ num, times[i][0], -1 });
			temp = times[i][0];
		}
		else
		{
			nums[nums.size() - 1][0] += times[i][1];
		}
	}

	sort(nums.begin(), nums.end(), cmp);

	int max = nums[0][0];

	for (size_t i = 0; i < nums.size(); ++i)
	{
		if (nums[i][0] == max)
		{
			for (int j = nums[i][1]; j <= nums[i][2]; ++j)
			{
				cout << j << ' ';
			}
		}
		else break;
	}
}
