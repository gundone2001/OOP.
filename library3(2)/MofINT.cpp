#include "pch.h"
#include "MofINT.h"

namespace maximka
{
	MofINT::MofINT(int size)
	{
		if (size < 0 && size > SZ + 1)
			throw std::out_of_range("");
		SIZE = size;
		for (int i = 0; i < SIZE; ++i)
		{
			pile[i] = i;
		}
		for (int i = SIZE; i < SZ; ++i)
		{
			pile[i] = 0;
		}
	}

	MofINT::MofINT(const MofINT& tmp)
	{
		SIZE = tmp.SIZE;
		for (int i = 0; i < SIZE; ++i)
		{
			pile[i] = tmp.pile[i];
		}
		for (int i = SIZE; i < SZ; ++i)
		{
			pile[i] = 0;
		}
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
	std::istream& operator >>(std::istream& s,MofINT& mofi)
	{
		do
		{
			//std::cout << "SIZE:-->";
			s >> mofi.SIZE;
			if (!s.good() || s.peek() != '\n')
			{
				s.clear();
				s.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		} while (!(mofi.SIZE > 0 && mofi.SIZE < mofi.SZ + 1));
		for (int i = 0; i < mofi.SIZE; ++i)
		{
			int key;
			do {
				//std::cout << "key";
				s >> key;
				if (!s.good() || s.peek() != '\n')
				{
					s.clear();
					s.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					//std::cout << "bed";	
					continue;
				}
			} while (!(find(mofi.pile, key, i)));
			insert(key, mofi.pile, i);
		}
		for (int i = mofi.SIZE; i < mofi.SZ; ++i)
		{
			mofi.pile[i] = 0;
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
	int MofINT::getMaxSize() const
	{
		return SZ;
	}                
	MofINT operator+(const MofINT& first, const MofINT& second)
	{
		MofINT tmp;
		tmp.SIZE = first.SIZE;
		for (int i = 0; i < tmp.SIZE; ++i)
		{
			tmp.pile[i] = first.pile[i];
		}
		for (int i = 0; i < second.SIZE; ++i)
		{
			if (tmp.SIZE == tmp.SZ)
			{
				throw std::exception("Pile is Full");
			}
			if (find(tmp.pile, second.pile[i], tmp.SIZE))
			{
				insert(second.pile[i], tmp.pile, tmp.SIZE);
				tmp.SIZE++;
			}
		}
		return tmp;
	}
	MofINT operator+=(MofINT& left,int element)
	{
		if (left.SIZE == left.SZ)
		{
			throw std::exception();
		}
		if (find(left.pile, element, left.SIZE))
		{
			insert(element, left.pile, left.SIZE);
			left.SIZE++;
		}
		else
		{
			throw std::exception("Element already be");
		}
		return left;
	}
	MofINT operator*(const MofINT& first,  MofINT& second)
	{
		MofINT tmp;
		for (int i = 0; i < first.SIZE; ++i)
		{
			if (!find(second.pile, first.pile[i], second.SIZE))
			{
				insert(first.pile[i], tmp.pile, tmp.SIZE);
				tmp.SIZE++;
			}
		}
		return tmp;
	}
	MofINT operator-(const MofINT& first, MofINT& second)
	{
		MofINT tmp;
		for (int i = 0; i < first.SIZE; ++i)
		{
			if (find(second.pile, first.pile[i], second.SIZE))
			{
				insert(first.pile[i], tmp.pile, tmp.SIZE);
				tmp.SIZE++;
			}
		}
		return tmp;
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