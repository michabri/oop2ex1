#include "Calculator.h"

//-----------------------------------------------------------------------------
Calculator::Calculator() 
{
	m_menu_actions.push_back(std::make_shared<Union>());
	m_menu_actions.push_back(std::make_shared<Intersection>());
	m_menu_actions.push_back(std::make_shared<Difference>());
}
//-----------------------------------------------------------------------------
void Calculator::run() 
{
	printMenu();
	std::string input;
	std::cin >> input;
	while (input != "exit")
	{
		if (input == "uni")
		{
			int action1, action2;
			std::cin >> action1 >> action2;
			m_menu_actions.push_back(std::make_shared<Union>(m_menu_actions[action1], m_menu_actions[action2]));
		}
		else if (input == "inter")
		{
			int action1, action2;
			std::cin >> action1 >> action2;
			m_menu_actions.push_back(std::make_shared<Intersection>(m_menu_actions[action1], m_menu_actions[action2]));
		}
		else if (input == "diff")
		{
			int action1, action2;
			std::cin >> action1 >> action2;
			m_menu_actions.push_back(std::make_shared<Difference>(m_menu_actions[action1], m_menu_actions[action2]));
		}
		else if (input == "eval")
		{
			int num;
			std::cin >> num;
			Group c(m_menu_actions[num]->evaluate());
			
			std::cout << c << "\n";
		}
		else if (input == "help")
			printHelp();
		else
			std::cout << "Error\n";
		
		std::cout << "\n";
		printMenu();
		std::cin >> input;
	}
	std::cout << "Goodbye\n";
}
//-----------------------------------------------------------------------------
void Calculator::printMenu()
{
	std::cout << "List of available set operations:\n";
	for (int i = 0; i < m_menu_actions.size(); i++)
	{
		std::cout << i << ". ";
		m_menu_actions[i]->printAction();
		std::cout << "\n";
	}
	std::cout << "Enter command ('help' for the list of available commands): ";
}
//-----------------------------------------------------------------------------
void Calculator::printHelp() 
{
	std::cout << 
"\n\
The available commands are :\n\
* eval(uate) num ... - compute the result of function #num on the following\n\
set(s); each set is prefixed with the count of numbers to read\n\
* uni(on) num1 num2 - Creates an operation that is the union of operation\n\
#num1 and operation #num2\n\
* inter(section) num1 num2 - Creates an operation that is the intersection\n\
of operation #num1 and operation #num2\n\
* diff(erence) num1 num2 - Creates an operation that is the difference of\n\
operation #num1 and operation #num2\n\
* prod(uct) num1 num2 - Creates an operation that returns the product of\n\
the items from the results of operation #num1 and operation #num2\n\
* comp(osite) num1 num2 - creates an operation that is the composition of\n\
operation #num1 and operation #num2\n\
* del(ete) num - delete operation #num from the operation list\n\
* help - print this command list\n\
* exit - exit the program\n\n";
}