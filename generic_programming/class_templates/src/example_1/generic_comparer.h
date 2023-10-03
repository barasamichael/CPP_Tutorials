#ifndef GENERIC_COMPARER_H_
#define GENERIC_COMPARER_H_

template <typename Type>
class Comparer
{
	// Keep track of comparisons
	int compare_count;
	int swap_count;
	bool (*comparison_function) (const Type&, const Type&);

	protected:
	virtual bool compare_implementation(const Type& value_one,
			const Type& value_two )
	{
		return comparison_function(value_one, value_two);
	}

	virtual void swap_implementation(Type& value_one, Type& value_two)
	{
		Type temp = value_one;
		value_one = value_two;
		value_two = temp;
	}

	public:
	Comparer(bool (*function)(const Type&, const Type&)):
		compare_count(0), swap_count(0), comparison_function(function){}

	void reset()
	{
		compare_count = swap_count = 0;
	}

	bool compare(const Type& value_one, const Type& value_two)
	{
		compare_count++;
		return compare_implementation(value_one, value_two);
	}

	void swap(Type& value_one, Type& value_two)
	{
		swap_count++;
		return swap_implementation(value_one, value_two);
	}

	int comparisons() const
	{
		return compare_count;
	}

	int swaps() const 
	{
		return swap_count;
	}
};
#endif
