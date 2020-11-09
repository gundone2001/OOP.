#include <iostream>
namespace maximka {

	int find(int* arr, int res, int maxindex);
	int insert(int elem, int* arr, int size);


	class MofINT {
	private:
		static const int SZ = 10;
		int SIZE;
		int pile[SZ];
	public:
		MofINT(int size = 0);
		MofINT(const MofINT&);
		friend MofINT operator+(const MofINT& , const MofINT& );
		friend MofINT operator*(const MofINT& , MofINT& );
		friend MofINT operator-(const  MofINT& ,MofINT& );
		friend MofINT operator+=(MofINT&, int element);
		int in(int element);
		int getSIZE()const;
		int getMaxSize()const;
		friend std::ostream& operator<<(std::ostream&,const MofINT&);
		friend std::istream& operator>>(std::istream&,MofINT&);



		template <size_t N>
		MofINT(int size, const int(&mass)[N])
		{
			int const size_m = N;
			if (size != size_m)
				throw std::exception("bad");
			if (size < 0 && size > SZ)
				throw std::exception("bad");
			SIZE = size;
			for (int i = 0; i < SIZE; ++i)
			{
				if (find(pile, mass[i], i))
				{
					insert(mass[i], pile, i);
				}
				else
				{
					throw std::exception("Item already be");
				}
			}
			for (int i = SIZE; i < SZ; ++i)
			{
				pile[i] = 0;
			}
		};

	};
}
