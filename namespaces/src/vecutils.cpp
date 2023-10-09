#include "vecutils.h"

namespace vecutils{
	int max(const std::vector<int>& sequence)
	{
		auto p = std::begin(sequence);
		int m = *p++;
		while (p != std::end(sequence))
		{
			if (*p > m)
			{
				m = *p;
			}
			p++;
		}
		int count = 0;
		for (auto element : sequence)
		{
			if (element == m)
			{
				count++;
			}
		}
		return count;
	}

	bool is_sorted(const std::vector<int>& sequence)
	{
		for (unsigned index = 0; index < sequence.size() - 1; index++)
		{
			if (sequence[index] > sequence[index + 1])
			{
				return false;
			}
		}
		return true;
	}
}
