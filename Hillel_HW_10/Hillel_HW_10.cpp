#include <iostream>
#include <vector>

class Calculator
{
private:
	int result = 0;
	static const char ADDITION = '+';
	static const char SUBTRACT = '-';
	static const char MULTIPLY = '*';
	static const char DIVISION = '/';
	std::vector<char> history;

public:

	int getResult() const
	{
		return result;
	}

	void resetResult()
	{
		result = 0;
	}

	void calculateValues(const int value1, const int value2, const char operation)
	{
		switch (operation)
		{
		case ADDITION:
			result = value1 + value2;
			history.clear();
			history.push_back(ADDITION);
			break;
		case SUBTRACT:
			result = value1 - value2;
			history.clear();
			history.push_back(SUBTRACT);
			break;
		case MULTIPLY:
			result = value1 * value2;
			history.clear();
			history.push_back(MULTIPLY);
			break;
		case DIVISION:
			if (value2 != 0)
			{
				result = value1 / value2;
				history.clear();
				history.push_back(DIVISION);
				break;
			}
			else
			{
				std::cout << "You can't divide by zero!!! Please use \"resetResult\" to reset value" << std::endl;
				result = 0;
				break;
			}
		default:
			std::cout << "Invalid operation" << std::endl;
			break;
		}
	}

	Calculator& calculateValues(const int value1, const char operation)
	{
		switch (operation)
		{
		case ADDITION:
			result += +value1;
			history.push_back(ADDITION);
			break;
		case SUBTRACT:
			result -= value1;
			history.push_back(SUBTRACT);
			break;
		case MULTIPLY:
			result *= value1;
			history.push_back(MULTIPLY);
			break;
		case DIVISION:
			if (value1 != 0)
			{
				result /= value1;
				history.push_back(DIVISION);
				break;
			}
			else
			{
				std::cout << "You can't divide by zero!!! Please use \"resetResult\" to reset value" << std::endl;
				result = 0;
				break;
			}
		default:
			std::cout << "Invalid operation" << std::endl;
			break;
		}
		return *this;
	}

	void getHistoryOfOperations() const
	{
		for (char const& operation : history)
		{
			std::cout << operation << " ";
		}
		std::cout << std::endl;
	}
};


int main()
{
	Calculator myCalculator;

	std::cout << "****** TEST #1 ******\n";
	std::cout << myCalculator.calculateValues(2, '+').calculateValues(4, '-').calculateValues(5, '*').getResult() << "\n";
	myCalculator.getHistoryOfOperations();

	std::cout << std::endl;

	std::cout << "****** TEST #2 ******\n";
	myCalculator.calculateValues(2, 2, '+');
	myCalculator.calculateValues(2, 5, '*');
	myCalculator.calculateValues(2, 2, '/');
	std::cout << myCalculator.getResult() << "\n";
	myCalculator.getHistoryOfOperations();

	return 0;
}

