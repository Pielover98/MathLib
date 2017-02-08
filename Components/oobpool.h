#pragma once

#include <vector>
#include <cassert>

template <typename T>
class obpool
{
	// Default capacity for object pool.
	const static size_t DEFAULT_POOL_SIZE = 100;

	// Backing array for object pool.
	std::vector<T> pool;
	std::vector<bool> poolValidity;

	size_t counter;

	// Returns the index of the first empty slot found.
	// Returns -1 if an empty index cannot be found.
	size_t nextEmpty()
	{
		// linearly search for the index of an empty slot
		for (size_t i = 0; i < poolValidity.size(); ++i)
		{
			if (poolValidity[i] == false)
			{
				return i;
			}
		}

		// vec[100]
		// size is? 100
		// valid idx range from 0 - 99
		size_t newIdx = pool.size();

		// vec[150]
		// size is? 150
		// valid idx range from 0 - 149
		pool.resize(pool.size() * 1.5);
		poolValidity.resize(poolValidity.size() * 1.5);
		//memset(&poolValidity[newIdx], 0, sizeof(bool) * (newIdx / 2));    // zero out memory to be false

		// returns a value of 100
		return newIdx;
	}
public:
	obpool()
	{
		pool.resize(DEFAULT_POOL_SIZE);
		poolValidity.resize(DEFAULT_POOL_SIZE);

		counter = 0;

		//memset(&pool[0], 0, sizeof(int) * DEFAULT_POOL_SIZE);
		//memset(&poolValidity[0], 0, sizeof(bool) * DEFAULT_POOL_SIZE);

		// setting all values to zero
		for (size_t i = 0; i < DEFAULT_POOL_SIZE; ++i)
		{
			pool.push_back(T());
			poolValidity.push_back(false);
		}
	}
	~obpool()
	{

	}

	class handle
	{

	public:
		handle() : pool(NULL) {}
		handle(obpool * poolPtr, size_t poolIdx) : pool(poolPtr), index(poolIdx) {}

		// back-pointer to pool
		obpool * pool;
		size_t index;

		// Returns a reference to the object in the object pool.
		T& value() const
		{
			return pool->at(index);
		}

		// Instructs the object pool to the free the slot occupied by this handle's slot.
		void free()
		{
			pool->pop(index);
		}

		// Returns true if the slot that this handle is referring to is occupied.
		// Otherwise, it should return false.
		bool isValid() const
		{
			return pool->isValid(index);
		}

		// Returns the index of the slot pointed to by this handle.
		size_t getIndex() const
		{
			return index;
		}

		// Moves the handle to the next valid element in the pool
		handle &operator++()
		{
			// attempt to find the next valid index
			for (size_t i = index + 1; i < pool->poolValidity.size(); ++i)
			{
				if (pool->poolValidity[i])
				{
					index = i;
					return *this;
				}
			}

			// failed to find next valid index
			// we must be at the end!
			index = pool->pool.size();
			return *this;
		}

		// Returns a reference to the object in the object pool
		T& operator*()
		{
			return value();
		}

		// Returns a const reference to the object in the object pool
		const T& operator*() const
		{
			return value();
		}

		// Returns a reference to the object in the object pool
		T& operator->()
		{
			return value();
		}

		// Returns a const reference to the object in the object pool
		const T& operator->() const
		{
			return value();
		}

		// Returns true they're pointing to the same slot.
		// Otherwise, returns false.
		bool operator==(const handle& other) const
		{
			return other.pool == pool && other.index == index;
		}

		// Returns true they're NOT pointing to the same slot.
		// Otherwise, returns false.
		bool operator!=(const handle& other) const
		{
			return !(other == *this);
		}
	};

	// Adds the given object to the object pool.
	// Returns a handle with the appropriate information to access the object pool.
	handle push(const T& cpy)
	{
		size_t idx = nextEmpty();
		assert(idx != -1);

		pool[idx] = cpy;
		poolValidity[idx] = true;

		counter++;

		return handle(this, idx);
	}

	void pop(size_t idx)
	{
		poolValidity[idx] = false;

		counter--;
	}

	// Returns true if the handle
	bool isValid(size_t idx) const
	{
		return poolValidity[idx];
	}

	// Return a handle to the first valid slot.
	handle begin()
	{
		for (size_t i = 0; i < poolValidity.size(); ++i)
		{
			if (poolValidity[i])
			{
				return handle(this, i);
			}
		}

		return end();
	}

	handle get(size_t idx)
	{
		assert(idx < pool.size());      // bounds check
		return handle(this, idx);
	}

	handle end()
	{
		return handle(this, pool.size());
	}

	size_t count()
	{
		return counter;
	}

	// Returns a reference to the object stored in the pool at the given index.
	T& at(size_t idx)
	{
		assert(isValid(idx));
		return pool[idx];
	}
	// Returns a const reference to the object stored in the pool at the given index.
	const T& at(size_t idx) const
	{
		assert(isValid(idx));
		return pool[idx];
	}
};