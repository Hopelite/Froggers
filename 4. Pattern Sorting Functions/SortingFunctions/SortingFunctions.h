#pragma once
#include <vector>
#include <stack>

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

	template <typename Iterator>
	static void patienceSort(Iterator beginning, Iterator end)
	{
		int numberOfElements = 1;
		std::vector<std::stack<typename std::iterator_traits<Iterator>::value_type>> piles;
		for (Iterator i = beginning; i < end; ++i)
		{
			if (piles.empty())
			{
				SortingFunctions::createPile(piles, *i);
			}
			else
			{
				bool isGreaterThanAllPilesTops = true;
				for (size_t j = 0; j < piles.size(); j++)
				{
					if (*i < piles[j].top())
					{
						piles[j].push(*i);
						isGreaterThanAllPilesTops = false;
						break;
					}
				}

				if (isGreaterThanAllPilesTops)
				{
					SortingFunctions::createPile(piles, *i);
				}

				numberOfElements++;
			}
		}

		SortingFunctions::mergePiles(piles, beginning, end, numberOfElements);
	}

private:
	template <typename T>
	static void createPile(std::vector<std::stack<T>>& piles, T value)
	{
		std::stack<T> pile;
		pile.push(value);
		piles.push_back(pile);
	}

	template <typename T, typename Iterator>
	static void mergePiles(std::vector<std::stack<T>>& piles, Iterator beginning, Iterator end, int numberOfElements)
	{
		// Get sorted vector collecting smallest by smallest elements of piles.
		std::vector<T> sortedElements;
		std::stack<T>* ptrToSmallestStackWithSmallestElement = &piles[0];
		while (numberOfElements != 0)
		{
			if (piles[0].size() == 0)
			{
				piles.erase(piles.begin());
			}

			T element = piles[0].top();
			for (size_t i = 0; i < piles.size(); i++)
			{
				if (element > piles[i].top())
				{
					element = piles[i].top();
					ptrToSmallestStackWithSmallestElement = &piles[i];
				}
			}

			sortedElements.push_back(ptrToSmallestStackWithSmallestElement->top());
			ptrToSmallestStackWithSmallestElement->pop();
			numberOfElements--;
		}

		// Write sorted elements to container.
		int index = 0;
		while (beginning != end)
		{
			*beginning = sortedElements[index];
			++beginning;
			++index;
		}
	}
};

