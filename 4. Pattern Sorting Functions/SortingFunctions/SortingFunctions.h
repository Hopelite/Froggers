#pragma once

class SortingFunctions
{
public:
	template <typename Iterator>
	static void bubbleSort(Iterator beginning, Iterator end)
	{
		while (beginning != end)
		{
			for (Iterator innerIterator = beginning; innerIterator != end; ++innerIterator)
			{
				if (*beginning > *innerIterator)
				{
					std::iter_swap(beginning, innerIterator);
				}
			}

			++beginning;
		}
	}

	template <typename T>
	static void patienceSort(T& collection)
	{
		// TODO: Implement patience sorting.
	}
};

