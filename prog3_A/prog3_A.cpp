#include <iostream>
#include "../librarylab3/MofINT.h"

int main()
{
	maximka::MofINT first, second, third;
	maximka::MofINT massive[] = { first,second,third };
	maximka::MofINT m[3];
	while (true)
	{
		std::cout << " Hello My friend , Max_SIZE of Mnogestfa = 10" << std::endl;
		std::cout << " You have 3 Mnogestf of int " << std::endl;
		std::cout << " Check " << std::endl;
		std::cout << " first ";
		first.output(std::cout);
		std::cout << " second ";
		second.output(std::cout);
		std::cout << " third ";
		third.output(std::cout);

		std::cout << " Lets go input NEW int in our MnoGestfa" << std::endl;
		std::cout << " first ";
		first.input(std::cin);
		std::cout << " second ";
		second.input(std::cin);
		std::cout << " third ";
		third.input(std::cin);

		std::cout << " Oh, next ... Lets go check our functional" << std::endl;

		std::cout << " 1 -> union of first and second " << std::endl;
		int fl = 1;
		try {
			m[0].unionM(first, second);
		}
		catch(std::exception& a)
		{
			std::cout << " Size_first + Size_second > Max_SIZe , sorry not today" <<a.what() << std::endl;
			fl = 0;
		}
		if (fl)
			m[0].output(std::cout);
		std::cout << " 2 -> general of first and third " << std::endl;

		m[1].general(first, third);

		m[1].output(std::cout);

		std::cout << " 3 -> differens of second and third " << std::endl;

		m[2].diff(second, third);

		m[2].output(std::cout);

		std::cout << " 4 -> add new int in third " << std::endl;
		int number;
		fl = 1;
		std::cout << "New int -->";
		do
		{
			std::cin >> number;
			if (!std::cin.good() || std::cin.peek() != '\n')
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << " Bed enter , reapet please my fried :)" << std::endl;
				std::cout << " -->";
				continue;
			}
			else
				break;
		} while (1);
		try {
			third.add(number);
		}
		catch (...)
		{
			std::cout << " Something no go on our plan ,thrid full or your number already be in third" << std::endl;
			fl = 0;
		}
		if (fl)
			third.output(std::cout);
		std::cout << " 5 -> check  int in third " << std::endl;

		std::cout << "Check int -->";
		do
		{
			std::cin >> number;
			if (!std::cin.good() || std::cin.peek() != '\n')
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << " Bed enter , reapet please my fried :)" << std::endl;
				std::cout << " -->";	
				continue;
			}
			else
				break;
		} while (1);

		if (third.in(number))
			std::cout << "EEEE , Int here " << std::endl;
		else
			std::cout << "We cant find your int , sorry " << std::endl;
		std::cout << " If you want one more time tap 1+enter-->" << std::endl;
		int check;
		do
		{
			std::cin >> check;
			if (!std::cin.good() || std::cin.peek() != '\n')
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << " Bed enter , reapet please my fried :)" << std::endl;
				std::cout << " -->";
				continue;
			}
			else
				break;
		} while (1);
		if (check == 1)
		{
			continue;
		}
		{
			std::cout << "Thanks,bye";
			break;
		}
		
	}

}
