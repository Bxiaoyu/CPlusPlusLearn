#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/************************************************************************/
// Õ∞≈≈–Ú
/************************************************************************/

namespace NPBucketSort
{
	template<size_t BucketSize, typename IterT, typename T = typename iterator_traits<IterT>::value_type, typename Compare = std::less<T>>
	void bucketSort(IterT first, IterT last, Compare comp = Compare())
	{
		const T min = *min_element(first, last), max = *max_element(first, last);
		const T range = max + 1 - min;
		const size_t bucket_num = (range - 1) / BucketSize + 1;

		vector<vector<T>> buckets(bucket_num);
		for (auto b : buckets)
		{
			b.reserve(2 * BucketSize);
		}

		for (IterT i = first; i != last; ++i)
		{
			size_t idx = (*i - min) / BucketSize;
			buckets[idx].emplace_back(*i);
		}

		IterT dest = first;
		for (auto b : buckets)
		{
			sort(b.begin(), b.end(), comp);
			copy(b.begin(), b.end(), dest);
			dest += b.size();
		}

		return;
	}

	// ≤‚ ‘
	template<size_t BucketSize, typename Container, typename T = typename Container::value_type, typename Compare = std::less<T>>
	void test_bucketSort(Container cont, Compare comp = Compare())
	{
		bucketSort<BucketSize>(cont.begin(), cont.end(), comp);
		transform(cont.begin(), cont.end(), ostream_iterator<T>(cout, " "), [](T i) { return i; });
		cout << endl;
	}

	void test_func()
	{
		vector<int> test{ 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9 };

		test_bucketSort<2>(test);
		test_bucketSort<3>(test);
		test_bucketSort<4>(test);
		test_bucketSort<5>(test);
		test_bucketSort<6>(test);
	}
}