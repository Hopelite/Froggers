#pragma once

class SortingFunctions
{
public:
	template <typename T>
	static void bubbleSort(T& collection)
	{
		typename T::iterator outerIterator = collection.begin();
		typename T::iterator innerIterator;
		while (outerIterator != collection.end())
		{
			for (innerIterator = outerIterator; innerIterator != collection.end(); ++innerIterator)
			{
				if (*outerIterator > *innerIterator)
				{
					std::iter_swap(outerIterator, innerIterator);
				}
			}

			++outerIterator;
		}
	}

	template <typename T>
	static void patienceSort(T& collection)
	{
		// TODO: Implement patience sorting.
	}
};

