#include "Calculator.h"

//-----------------------------------------------------------------------------
Calculator::Calculator() {
	m_menu_actions.push_back(std::make_shared<Union>());
}
//-----------------------------------------------------------------------------
void Calculator::printMenu()
{
	for (int i = 0; i < m_menu_actions.size(); i++)
	{
		std::cout << i << ". ";
		m_menu_actions[i]->printAction();
		std::cout << "\n";
	}
}

//-----------------------------------------------------------------------------
void Calculator::printHelp() {
	std::cout << "The available commands are :\n\
		*eval(uate) num ... - compute the result of function #num on the following\n\
		set(s); each set is prefixed with the count of numbers to read\n\
		* uni(on) num1 num2 - Creates an operation that is the union of operation\n\
		#num1 and operation #num2\n\
		* inter(section) num1 num2 - Creates an operation that is the intersection\n\
		of operation #num1 and operation #num2\n\
		* diff(erence) num1 num2 - Creates an operation that is the difference of\n\
		operation #num1 and operation #num2\n\
		\n\
		* prod(uct) num1 num2 - Creates an operation that returns the product of\n\
		the items from the results of operation #num1 and operation #num2\n\
		* comp(osite) num1 num2 - creates an operation that is the composition of\n\
		operation #num1 and operation #num2\n\
		* del(ete) num - delete operation #num from the operation list\n\
		* help - print this command list\n\
		* exit - exit the program";
}