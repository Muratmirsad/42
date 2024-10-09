#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {};

PmergeMe::PmergeMe(const PmergeMe & src) { *this = src; };

PmergeMe::~PmergeMe(void) {};

PmergeMe & PmergeMe::operator=(const PmergeMe & elem)
{
	this->nbrsDeque = elem.nbrsDeque;
	this->nbrsVector = elem.nbrsVector;

	return (*this);
}


std::string removeSpaces(std::string str)
{
	int i;
	for (i = 0; ::isspace(str[i]); i++);
	str.erase(0, i);

	for (i = str.size() - 1; ::isspace(str[i]); i--);
	str.erase(i + 1, str.size());

	return str;
}

int checkElem(std::string elem)
{
	long checkLong;

	elem = removeSpaces(elem);
	if (elem.size() > 10)
	{
		std::cout << "Error\n";
		return -1;
	}

	for (int i = 0; elem[i]; i++)
	{
		if (!isdigit(elem[i]))
		{
			std::cout << "Error\n";
			return -1;
		}
	}

	checkLong = static_cast<long>(stol(elem));
	if (checkLong > 2147483647)
	{
		std::cout << "Error\n";
		return -1;
	}
	return (static_cast<int>(checkLong));
}


// Merge-Insert
template <typename T>
void merge(T & left, T & right, T & full)
{
	unsigned int length = full.size();
	unsigned int leftLen = left.size();
	unsigned int rightLen = length - leftLen;

	unsigned int l = 0, r = 0, i = 0;
	while (l < leftLen && r < rightLen)
	{
		if (left[l] < right[r])
			full[i++] = left[l++];
		else
			full[i++] = right[r++];
	}

	while (r < rightLen)
		full[i++] = right[r++];

	while (l < leftLen)
		full[i++] = left[l++];
}

template <typename T>
void mergeInsertSort(T & nbrs)
{
	unsigned int len = nbrs.size();
	if (len <= 1)
		return ;
	
	unsigned int mid = len / 2;
	T left;
	for (unsigned int i = 0; i < mid; i++)
		left.push_back(nbrs[i]);
	
	T right;
	for (unsigned int i = mid; i < len; i++)
		right.push_back(nbrs[i]);

	mergeInsertSort(left);
	mergeInsertSort(right);
	merge(left, right, nbrs);
}


bool PmergeMe::getNumbers(char ** args)
{
	for (int i = 1; args[i]; i++)
	{
		int theNumber = checkElem(args[i]);
		if (theNumber == -1)
			return false;
		this->nbrsDeque.push_back(theNumber);
		this->nbrsVector.push_back(theNumber);
	}

	return true;
}

void PmergeMe::sort(void)
{
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	mergeInsertSort(this->nbrsDeque);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	this->dequeTime = std::chrono::duration<double, std::micro>(end - start).count();


	start = std::chrono::high_resolution_clock::now();
	mergeInsertSort(this->nbrsVector);
	end = std::chrono::high_resolution_clock::now();
	this->vectorTime = std::chrono::duration<double, std::micro>(end - start).count();
}

void PmergeMe::printNumbers(void)
{
	for (std::vector<int>::iterator iter = this->nbrsVector.begin(); iter != nbrsVector.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

void PmergeMe::printInfos(void)
{
	std::cout << "Time to process a range of  " << this->nbrsDeque.size() << "  with std::[deque]  :  " <<
		std::fixed << this->dequeTime << " us" << std::endl;
	std::cout << "Time to process a range of  " << this->nbrsVector.size() << "  with std::[vector] :  " <<
		std::fixed << this->vectorTime << " us" << std::endl;
}