// при организации шаблонного класса в виде библиотеки требуется
//весь код который является шаблоном оставить в заголовочном файле
//в файл реализации переносятся только те элементы, которые
//имеют полное определение. Например функции и вспомогательные классы
//которые не являются шаблонами.

#pragma once

#ifndef MATH_OPERATOR_HPP
#define MATH_OPERATOR_HPP


#include<iostream>

//Шаблонные классы
template<typename Type> 

class MatOperator {
public:
	//конструктор по умолчанию
	MatOperator() :operand1_(Type()), operand2_(Type()) {};

	//Конструктор с параметром
	MatOperator(Type left, Type right) :operand1_(left), operand2_(right) {};

	//сеттеры принимают аргументы шаблонного типа данных
	//это позволяет корректно занести данные в поля.
	void SetLeft(Type num) {
		operand1_ = num;
	}

	void SetRight(Type num) {
		operand2_ = num;
	}

	//Геттеры возвращают шаблонный тип, чтобы не было конгфликта при возврате полей
	Type GetLeft()const {
		return operand1_;
	}

	Type GetRight()const {
		return operand2_;
	}

	Type Summ()const {
		return operand1_ + operand2_;
	}

	Type Multiply()const {
		return operand1_ * operand2_;
	}
private:
	Type operand1_;
	Type operand2_;

};

template<>
class MatOperator<bool> {
public:
	MatOperator() :operand1_(false), operand2_(false) {};

	//Конструктор с параметром
	MatOperator(bool left, bool right) :operand1_(left), operand2_(right) {};

	//сеттеры принимают аргументы шаблонного типа данных
	//это позволяет корректно занести данные в поля.
	void SetLeft(bool num) {
		operand1_ = num;
	}

	void SetRight(bool num) {
		operand2_ = num;
	}

	//Геттеры возвращают шаблонный тип, чтобы не было конгфликта при возврате полей
	bool GetLeft()const {
		return operand1_;
	}

	bool GetRight()const {
		return operand2_;
	}

	bool Summ()const {
		return operand1_ + operand2_;
	}
private:
	bool operand1_;
	bool operand2_;
};


//обработка объектов шаблонного класса

// Вариант 1
// обработка конкретной специализации

void PrintSumm(const MatOperator<int>& obj);
	

// Вариант 2
//обработка обобщенного вида

template<typename T>
void PrintMyltiply(MatOperator<T> obj) {
	std::cout << obj.GetLeft() << "*" << obj.GetRight()
		<< '=' << obj.Multiply() << '\n';
};

template<>
void PrintMyltiply(MatOperator<bool> obj) {
	//Вариант 1 обработки:кидаем исключение
	// 
	// throw -1; если так не делать, то проблема с неккоректным поведением
	//программы может выдезти в будущем в непредсказуемый момент времени 


	//Вариант 2 обработки: работаем с учетом особенностей ыходных данных
	std::cout << obj.GetLeft() << "*" << obj.GetRight()
		<< "not allowed operations" << '\n';
};



#endif //