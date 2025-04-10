#include "MultiSet.h"

void MultiSet::copyFrom(const MultiSet& other)
{
	n = other.n;
	k = other.k;
	unsigned int numBuckets = getNrOfBuckets();
	buckets = new unsigned char[numBuckets];
	for (unsigned int i = 0; i < numBuckets; i++) 
	{
		buckets[i] = other.buckets[i];
	}
}

void MultiSet::moveFrom(MultiSet&& other)noexcept
{
	n = other.n;
	other.n = 0;

	k = other.k;
	other.k = 0;

	buckets = other.buckets;
	other.buckets = nullptr;

}

void MultiSet::free()
{
	n = k = 0;
	delete[]buckets;
	buckets = nullptr;
}

MultiSet::MultiSet():n(0),k(0),buckets(nullptr)
{
}

MultiSet::MultiSet(const MultiSet& other)
{
	copyFrom(other);
}

MultiSet::MultiSet(MultiSet&& other)noexcept
{
	moveFrom(std::move(other));
}

MultiSet& MultiSet::operator=(const MultiSet& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MultiSet& MultiSet::operator=(MultiSet&& other)noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MultiSet::~MultiSet()
{
	free();
}

void MultiSet::setLargestNum(unsigned int largestNum)
{
	n = largestNum;
}

void MultiSet::setK(unsigned int k)
{
	if (k >= CONSTANTS::ONE && k <= CONSTANTS::BYTE) {
		this->k = k;
	}
}

unsigned int MultiSet::getNrOfBuckets() const
{
	return  (((CONSTANTS::ONE << k) - CONSTANTS::ONE) * (n + CONSTANTS::ONE)) / CONSTANTS::BYTE + CONSTANTS::ONE;
}

MultiSet::MultiSet(unsigned int largestNumber, unsigned int bitsNeeded)
{
	setLargestNum(largestNumber);
	setK(bitsNeeded);
	
	unsigned int numBuckets = getNrOfBuckets();
	buckets = new unsigned char[numBuckets]();

	for (unsigned int i = 0; i < numBuckets; ++i)
	{
		buckets[i] = 0;
	}
}

void MultiSet::calculateValues(unsigned int num, unsigned int& index, unsigned int& shift, unsigned char& mask, unsigned char& count) const
{
	index = num * ((CONSTANTS::ONE << k) - CONSTANTS::ONE) / CONSTANTS::BYTE;
	shift = (num * ((CONSTANTS::ONE << k) - CONSTANTS::ONE) % CONSTANTS::BYTE);
	mask = (CONSTANTS::ONE << k) - CONSTANTS::ONE;
	count = (buckets[index] >> shift) & mask;
}

void MultiSet::add(unsigned int num)
{
	if (num > n)
	{
		throw std::out_of_range("Number out of range!");
	}

	unsigned int byteIndex;
	unsigned int bitOffset;
	unsigned char mask;
	unsigned char count;
	calculateValues(num, byteIndex, bitOffset, mask, count);

	if (count < (CONSTANTS::ONE << k) - CONSTANTS::ONE)
	{
		count++;
		buckets[byteIndex] &= ~(mask << bitOffset);
		buckets[byteIndex] |= (count << bitOffset);
	}

	else 
	{
		throw std::out_of_range("Number of occurrences exceeded the limit!");
	}
}

unsigned int MultiSet::count(unsigned int num) const
{
	if (num > n) 
	{
		throw std::out_of_range("Number out of range!");
	}
	unsigned int byteIndex;
	unsigned int bitOffset;
	unsigned char mask;
	unsigned char count;
	calculateValues(num, byteIndex, bitOffset, mask, count);
	return count;
}

void MultiSet::printNumbers() const
{
	for (unsigned int num = 0; num <= n; ++num)
	{
		if (count(num) > 0)
		{
			std::cout << num << " "<<std::endl;
		}
	}
}

void MultiSet::printMemoryRepresentation() const
{
	unsigned int numBuckets = getNrOfBuckets();

	for (int i = numBuckets - CONSTANTS::ONE; i >= 0; --i) 
	{
		for (int j = CONSTANTS::INDEX_MOST_SIGNIFICANT_BIT; j >= 0; --j)
		{
			std::cout << ((buckets[i] >> j) & CONSTANTS::ONE);
		}
		std::cout << " ";
	}
	std::cout << std::endl;
}

void MultiSet::serialize(std::ofstream&ofs) const
{
	unsigned int numBuckets = getNrOfBuckets();
	ofs.write((const char*)&numBuckets, sizeof(numBuckets));
	ofs.write((const char*)buckets, numBuckets);
	ofs.close();
}

void MultiSet::deserialize(std::ifstream& ifs)
{
	unsigned int numBuckets;
	ifs.read((char*)&numBuckets, sizeof(numBuckets));

	if (buckets != nullptr) 
	{
		delete[] buckets;
	}

	buckets = new unsigned char[numBuckets];
	ifs.read((char*)buckets, numBuckets);
	ifs.close();
}

MultiSet intersection(const MultiSet& set1, const MultiSet& set2)
{
	unsigned int smallestN = HELPER_FUNCTIONS::minimum(set1.n, set2.n);
	unsigned int largestK = HELPER_FUNCTIONS::maximum(set1.k, set2.k);

	MultiSet result(smallestN, largestK);

	for (unsigned int i = 0; i <= result.getNrOfBuckets(); ++i)
	{
		result.buckets[i] = set1.buckets[i] & set2.buckets[i];
	}

	return result;
}

MultiSet difference(const MultiSet& set1, const MultiSet& set2)
{
	unsigned int largestestN = HELPER_FUNCTIONS::maximum(set1.n, set2.n);
	unsigned int largestK = HELPER_FUNCTIONS::maximum(set1.k, set2.k);
	MultiSet result(largestestN, largestK);
	unsigned int numBuckets = result.getNrOfBuckets();

	for (unsigned int i = 0; i <= numBuckets; ++i)
	{
		result.buckets[i] = set1.buckets[i] & ~set2.buckets[i];
	}
	return result;
}

MultiSet complement(const MultiSet& set)
{
	unsigned int largestN = set.n;
	unsigned int largestK = set.k;
	MultiSet result(largestN, largestK);
	unsigned int numBuckets = result.getNrOfBuckets();

	for (unsigned int i = 0; i <= numBuckets; ++i)
	{
		result.buckets[i] = ~(set.buckets[i]);
	}
	return result;
}

unsigned int HELPER_FUNCTIONS::minimum(unsigned int n1, unsigned int n2)
{
	return n1 < n2 ? n1 : n2;
}

unsigned int  HELPER_FUNCTIONS::maximum(unsigned int n1, unsigned int n2)
{
	return n1 > n2 ? n1 : n2;
}