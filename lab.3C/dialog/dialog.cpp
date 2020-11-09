#include "../library3C/MofINT.h"

int main()
{
	maximka::MofINT first, second, third , extra;
	maximka::MofINT massive[] = { first,second,third };
	maximka::MofINT m[3];
	while (true)
	{
		std::cout << " Hello My friend , Max_SIZE of Mnogestfa = 10" << std::endl;
		std::cout << " You have 3 Mnogestf of int " << std::endl;
		std::cout << " Check " << std::endl;
		std::cout << " first ";
		std::cout << first;
		std::cout << " second ";
		std::cout << second;
		std::cout << " third ";
		std::cout << third;

		std::cout << " Lets go input NEW int in our MnoGestfa" << std::endl;
		std::cout << " first ";
		std::cin >> first;
		std::cout << " second ";
		std::cin >> second;
		std::cout << " third ";
		std::cin >> third;

		std::cout << " Oh, next ... Lets go check our functional" << std::endl;

		std::cout << " 0 -> extra = first " << std::endl;

		extra = first; 

		std::cout << extra;

		std::cout << " 1 -> union of first and second " << std::endl;
		try {
			std::cout << first + second;
		}
		catch (std::exception& a)
		{
			std::cout << " Size_first + Size_second > Max_SIZe , sorry not today" << a.what() << std::endl;
		}
		std::cout << " 2 -> general of first and third " << std::endl;

		std::cout << first * third;

		std::cout << " 3 -> differens of second and third " << std::endl;

		std::cout << second - third;

		std::cout << " 4 -> add new int in third " << std::endl;
		int number;
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
			third += number;
			std::cout << third;
		}
		catch (...)
		{
			std::cout << " Something no go on our plan ,thrid full or your number already be in third" << std::endl;
		}
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