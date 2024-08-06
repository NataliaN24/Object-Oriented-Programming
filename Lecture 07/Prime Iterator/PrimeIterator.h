#pragma once
class PrimeIterator
{
	size_t value;

	PrimeIterator& goToNext();
	PrimeIterator& goToPrev();

public:
	PrimeIterator(size_t value);
	PrimeIterator();

	size_t getValue()const;
	void setValue(size_t value);

	PrimeIterator& operator++();
	PrimeIterator operator++(int);

	PrimeIterator& operator--();
	PrimeIterator operator--(int);

	unsigned operator*()const;
};
bool operator==(const PrimeIterator& lhs, const PrimeIterator& rhs);
bool operator!=(const PrimeIterator& lhs, const PrimeIterator& rhs);