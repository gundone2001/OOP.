#include "pch.h"
#include "MofINT.h"

namespace maximka
{
	MofINT::MofINT(int size )
	{
		if (size < 0)
			throw std::out_of_range("Error");
		SIZE = size;
		pile = new int[SIZE];
		for (int i = 0; i < SIZE; ++i)
		{
			pile[i] = i;
		}
	}

	MofINT::MofINT(const MofINT& other)
	{
		SIZE = other.SIZE;
		pile = new int[SIZE];
		for (int i = 0; i < SIZE; ++i)
		{
			pile[i] = other.pile[i];
		}
	}

	MofINT::MofINT(int size, int *mass)
	{
		if (size < 0 )
			throw std::out_of_range("Error");
		SIZE = size;
		pile = new int[SIZE];
		for (int i = 0; i < SIZE; ++i)
		{
			pile[i] = mass[i];
		}
	}


	MofINT::MofINT(MofINT&& other) 
	{
		SIZE = other.SIZE;
		pile = other.pile;
		other.pile = nullptr;
	}
	


	std::ostream& operator << (std::ostream& s, const MofINT& mofi)
	{
		if (mofi.SIZE == 0)
			s << "Pile is empty";
		else
			for (int i = 0; i < mofi.SIZE; ++i)
			{
				s << mofi.pile[i] << " ";
			}
		s << std::endl;
		return s;
	}
	std::istream& operator >>(std::istream& s, MofINT& mofi)
	{
		do
		{
			//std::cout << "SIZE:-->";
			s >> mofi.SIZE;
			if (!s.good() || s.peek() != '\n')
			{
				s.clear();
				s.ignore(10000, '\n');
				continue;
			}
		} while (!(mofi.SIZE >= 0));
		if (mofi.SIZE == 0)
		{
			mofi.pile = nullptr;
		return s;
		}
		mofi.pile = new int[mofi.SIZE];
		for (int i = 0; i < mofi.SIZE; ++i)
		{
			int key;
			do {
				//std::cout << "key";
				s >> key;
				if (!s.good() || s.peek() != '\n')
				{
					s.clear();
					s.ignore(10000, '\n');
					//std::cout << "bed";	
					continue;
				}
			} while (!(find(mofi.pile, key, i)));
			insert(key, mofi.pile, i);
		}
		return s;
	}
	int MofINT::in(int element)
	{
		if (!find(pile, element, SIZE))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int MofINT::getSIZE() const
	{
		return SIZE;
	}
	int MofINT::getPILE(int number)const
	{
		return pile[number];
	}
	MofINT MofINT::operator= (const MofINT& other )
	{
		SIZE = other.SIZE;
		pile = new int[SIZE];
		for (int i = 0; i < SIZE; ++i)
		{
			pile[i] = other.pile[i];
		}
		return *this;
	}
	MofINT operator+(const MofINT& first, const MofINT& second)
	{
		MofINT tmp;
		int truesize = first.SIZE;
		int* tmpmass = new int[first.SIZE + second.SIZE];
		for (int i = 0; i < first.SIZE; ++i)
		{
			tmpmass[i] = first.pile[i];
		}
		for (int i = 0; i < second.SIZE; ++i)
		{
			if (find(tmpmass, second.pile[i], truesize))
			{
				insert(second.pile[i], tmpmass, truesize);
				truesize++;
			}
		}
		tmp.SIZE = truesize;
		tmp.pile = new int[tmp.SIZE];
		for (int i = 0; i < tmp.SIZE; ++i)
		{
			tmp.pile[i] = tmpmass[i];
		}
		delete[] tmpmass;
		return tmp;
	}
	MofINT operator+=(MofINT& left, int element)
	{
		if (find(left.pile, element, left.SIZE))
		{
			int* tmpmass = new int[left.SIZE];
			for (int i = 0; i < left.SIZE; ++i)
			{
				tmpmass[i] = left.pile[i];
			}
			left.pile = new int[left.SIZE + 1];
			for (int i = 0; i < left.SIZE; ++i)
			{
				left.pile[i] = tmpmass[i];
			}
			insert(element, left.pile, left.SIZE);
			left.SIZE++;
		}
		else
		{
			throw std::exception("Element already be");
		}
		return left;
	}
	MofINT operator*(const MofINT& first, MofINT& second)
	{
		MofINT tmp;
		int minsize = (first.SIZE < second.SIZE) ? first.SIZE : second.SIZE;
		int* tmpmass = new int[minsize];
		int truesize = 0;
		for (int i = 0; i < first.SIZE; ++i)
		{
			if (!find(second.pile, first.pile[i], second.SIZE))
			{
				insert(first.pile[i], tmpmass, truesize);
				truesize++;
			}
		}
		tmp.SIZE = truesize;
		tmp.pile = new int[tmp.SIZE];
		for (int i = 0; i < tmp.SIZE; ++i)
		{
			tmp.pile[i] = tmpmass[i];
		}
		delete[] tmpmass;
		return tmp;
	}
	MofINT operator-(const MofINT& first, MofINT& second)
	{
		MofINT tmp;
		int maxsize = first.SIZE;
		int* tmpmass = new int[maxsize];
		int truesize = 0;
		for (int i = 0; i < first.SIZE; ++i)
		{
			if (find(second.pile, first.pile[i], second.SIZE))
			{
				insert(first.pile[i], tmpmass, truesize);
				truesize++;
			}
		}
		tmp.SIZE = truesize;
		tmp.pile = new int[tmp.SIZE];
		for (int i = 0; i < tmp.SIZE; ++i)
		{
			tmp.pile[i] = tmpmass[i];
		}
		delete[] tmpmass;
		return tmp;
	}

	MofINT::~MofINT()
	{
		delete[] pile;
	}


	int find(int* arr, int res, int maxindex)
	{
		int l = 0;
		int r = maxindex - 1;
		while (l <= r)
		{
			int j = (l + r) / 2;
			if (arr[j] < res)
				l = j + 1;
			if (arr[j] > res)
				r = j - 1;
			if (arr[j] == res)
				return 0;
		}
		return 1;
	}
	int insert(int elem, int* arr, int size) {
		int i = 0;
		for (i = size - 1; i >= 0 || size == 0; --i) {
			if (arr[i] > elem && i >= 0) {
				arr[i + 1] = arr[i];
				arr[i] = elem;
			}
			else {
				arr[i + 1] = elem;
				return 1;
			}
		}
		return 1;
	}

}