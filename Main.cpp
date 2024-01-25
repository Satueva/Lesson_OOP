#include <iostream>
// конструкторы копирования и администраторы класса

class Integer {
public:
	Integer():data_(0){}
	Integer(int num):data_(num){}


	// перегрузка оператора как дружественой функции
	friend Integer operator + (Integer A, Integer B) {
		Integer result;
		result.data_ = A.data_ + B.data_;
		return result;
		//return Integer(this->data_ + obj.data_); если алгоритм легче 
	}
	
	friend std::ostream& operator << (
		std::ostream& out, 
		const Integer& obj
		);

	int GetNum() {
		return data_;
	}
	
	// оператор перегружен как метод класса
	Integer& operator=(const Integer& other) {
		this->data_ = other.data_;
		return *this;
	}

private:
	int data_;
	
	//bool sign_;
	//unsigned long long units_;
	// таксая реализация полей лучше подойдёт 
	// для математически достоверных целых чисел
};

std::ostream& operator << (
	std::ostream& out,
	const Integer& obj
	) {
	return out << obj.data_;
}

Integer operator-(Integer a, Integer b) {
	return a.GetNum() - b.GetNum();
}



int main() {
	setlocale(LC_ALL, "rus");
	int a{ 5 };
	int b{ 8 };
	//operator+(a, b);
	std::cout << a + b << '\n';
	std::cout << a - b << '\n';
	std::cout << a * b << "\n\n";

	std::cout << a + 5 << '\n';
	std::cout << a - 5 << '\n';
	std::cout << a * 3 << "\n\n";

	std::cout << 4 + b << '\n';
	std::cout << 7 - b << '\n';
	std::cout << 1 * b << '\n';


/*
 Правила работы с операторами:
 - Операторы можно перегружать только для классов. 
   Для встроинных типов данных операторы не перегружают;
 - Оператор не может менять своего поведения в ходе перегрузки;
 - Ряд оперяторов запрещено перегружать:  ( . ),  ( ?: ),  ( & - унарный омперсант ),  ( :: ),  ( -> );
*/









	return 0;
}