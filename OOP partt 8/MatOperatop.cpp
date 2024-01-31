#include "MatOperatop.hpp"

void PrintSumm(const MatOperator<int>& obj)
{
	std::cout << obj.GetLeft() << "+" << obj.GetRight()
		<< '=' << obj.Summ() << '\n';
}
