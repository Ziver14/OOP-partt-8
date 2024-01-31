#include<iostream>

#include"MatOperatop.hpp"


int main() {

	MatOperator<float> f(1.,2.);
	std::cout << f.Summ()<<'\n';
	
	std::cout << f.GetLeft() << "+" << f.GetRight()
		<< '=' << f.Summ() << '\n';

	MatOperator<float> f2(1.5, 2.9);
	std::cout << f2.Summ()<<'\n';

	f2.SetRight(f.GetRight() + 1);
	std::cout << f2.GetLeft() << "+" << f2.GetRight() 
		<< '=' << f2.Summ() << '\n';
	//MatOperator<bool> b;

	std::cout << 4 << "*" << 9
		<< '=' << MatOperator<int>(4,9).Multiply() << '\n';
	// при работе с шаблонными классами нет запретов на использование анонимных объектов
	// при анонимного объекта от шаблонного класса, так же используется его специализация
	  

	PrintSumm(MatOperator<int>(4, 9));

	const MatOperator<int> int_m (4, 54);
	PrintSumm(int_m);
	//PrintSumm(f2); невозможно так как в функции упомянута конкретная реализация

	PrintMyltiply(f);
	PrintMyltiply(int_m);
	PrintMyltiply(MatOperator<char>('4', '*'));
	PrintMyltiply(MatOperator<bool>(true, false));

	return 0;
}