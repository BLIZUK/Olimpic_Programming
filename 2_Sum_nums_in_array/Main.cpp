#include <iostream>
#include <vector>


static std::vector<int> PrefSum(std::vector<int> a, size_t n)
{
	std::vector<int> pref(n);
	pref[0] = a[0];

	for (size_t i = 1; i < n; i++)
	{
		pref[i] = pref[i - 1] + a[i];
	}

	return pref;
}


void FindInd(std::vector<int> a, size_t n)
{
	size_t l = 0, r = 0;
	int max_sum = 0, min_sum = 0;

	for (size_t i = 0; i < n; i++)
	{
		if (a[i] > max_sum)
		{
			max_sum = a[i];
			r = i;
		}
		if (min_sum - a[i] >= 0)
		{
			l = i;
		}
	}

	std::cout << '\n' << l + 1 << '\n' << r + 1;
}


int main()
{
	size_t n, i;
	std::cin >> n;
	std::vector<int> arr(n);

	for (i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	std::vector<int> pref = PrefSum(arr, n);

	FindInd(pref, n);

	return 0;
}