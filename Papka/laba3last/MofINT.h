#include <iostream>
namespace maximka {

	int find(int* arr, int res, int maxindex);
	int insert(int elem, int* arr, int size);

	class MofINT {
	private:
		int SIZE;
		int* pile;
	public:
		MofINT(int size = 0);
		MofINT(const MofINT&);
		MofINT(int size, int* arr);
		MofINT(MofINT&&)noexcept;
		MofINT &operator=(const MofINT&);
		MofINT &operator=(MofINT&&)noexcept;	
		friend MofINT operator+(const MofINT&, const MofINT&);
		friend MofINT operator*(const MofINT&, MofINT&);
		friend MofINT operator-(const  MofINT&, MofINT&);
		friend MofINT operator+=(MofINT&, int element);
		int in(int element);
		int getSIZE()const;
		int getPILE(int)const;
		friend std::ostream& operator<<(std::ostream&, const MofINT&);
		friend std::istream& operator>>(std::istream&, MofINT&);
		~MofINT();
	};
}