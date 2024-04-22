#include "Data.h"
#include <iostream>




int Data::getValue() const
{
	return Data::value_;
}

void Data::setValue(int value)
{
	Data::value_ = value;
}

//void Data::printDataValue() const
//{
//	std::cout << "value_ = " << value_ << ";" << std::endl;
//}

