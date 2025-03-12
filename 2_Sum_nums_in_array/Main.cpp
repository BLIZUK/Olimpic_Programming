#include <iostream>
#include <vector>


static std::vector<int> PrefSum(std::vector<int> a, size_t n)
{
	std::vector<int> pref(n);
	pref[0] = a[0];

	for (size_t i = 1; i < n; i++)
	{
		pref[i] = pref[i - 1] + a[i] ;
	}

	return pref;
}


static void FindInd(std::vector<int> a, size_t n)
{
	size_t l = 0, r = 0, min_index = 0;
	int max_sum = a[0], min_sum = 0;

	for (size_t i = 0; i < n; i++)
	{
		if (a[i] - min_sum > max_sum)
		{
			max_sum = a[i] - min_sum;
			min_index + 1;
			r = i;
		}
		if (a[i] < min_sum)
		{
			min_sum = a[i];
			min_index = i;
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

	FindInd(PrefSum(arr, n), n);

	return 0;
}