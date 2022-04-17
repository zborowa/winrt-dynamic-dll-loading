#pragma once
#include "pch.h"
#include <vector>
#include <algorithm>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <functional>
#include <numeric>
#include <random>
#include <chrono>
#include <ppltasks.h >

template <typename T>
inline void CreateIntegerRange(T& _vector, int min, int max)
{
	int index = min;
	do
	{

		_vector.insert(_vector.end(), index);
		++index;
	} while (index <= max);
}

template <typename T>
class RandomOrder
{
public:

	RandomOrder() = delete;

	virtual ~RandomOrder()
	{
		m_vector.clear();

	}

	RandomOrder(std::vector<T> D)
	{
		unsigned seed = (unsigned)std::chrono::system_clock::now().time_since_epoch().count();

		std::shuffle(D.begin(), D.end(), std::default_random_engine(seed));

		m_vector = D;
	}

	std::vector<T> get()
	{
		return m_vector;
	}
private:
	std::vector<T> m_vector;

};

template <typename I>
class Collection
{
public:
	Collection() = default;

	winrt::Windows::Foundation::Collections::IVectorView<I>
		GetView(winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::
			Collections::IVector<I>> items)
	{
		return Concurrency::create_task([items] {
			return  items.get().GetView();
			}).get();
	}

	std::vector<I> GetItems(I const& E, bool shuffle)
	{
		winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::
			Foundation::Collections::IVector<I>> items = E.GetCollection();
		winrt::Windows::Foundation::Collections::IVectorView<I> viewItems = GetView(items);

		std::vector<I> _items;

		int i = 0;
		int elements = viewItems.Size();
		do
		{
			_items.push_back(viewItems.GetAt(i));
			++i;
		} while (i <= (elements - 1));

		if (shuffle)
		{
			RandomOrder<I> rdrItems(_items);
			return rdrItems.get();
		}

		else
			return _items;
	}
};