﻿#include<iostream>
#include<string>
// Прототип функции по переводу ПРОПИСНЫХ букв в строчные (только для кириллицы):
template<typename T>
T tolower_rus(T str);
// Прототип функции подсчета знаков препинания и пробелов:
template <typename T>
int search_punct_char(T str);
// Прототип функции Задачи 4:
template <typename T>
T my_substr(T str, char sym);

int main() {
	system("chcp 1251>null");	// команда ввода-вывода русского текста.
	int n;
	
	// Задача 1. Дана строка str. Пользователь вводит символ sym. Программа создаёт 
	// новую строку, которая состоит из символа sym. Длина новой строки равна количеству
	// совпадений введённого символа в изначальной строке str.
	std::cout << "Задача 1. Нахождение символов в слове.\n";
	std::string str1 = "Hello World!";
	char sym;
	std::cout << str1 << std::endl;
	std::cout << "Введите символ, который необходимо вывести в консоль -> ";
	std::cin >> sym;
	std::string str1_1;		// создадим строковую переменную.
	for (int i = 0; i <= str1.length(); i++)
		if (sym == str1[i])			// если найдем символ sym в строке str,
			str1_1 += str1[i];		// то добавим этот символ в строковую переменную.
	std::cout << str1_1 << "\n\n";	// вывод строковой переменной в консоль.
	
	// Задача 2. Создайте функцию, которая принимает слово и возвращает true,
	//  если оно является палиндромом. В противном случае возвращается false.
	// Функция должна быть нерегистрозависимой.
	std::cout << "Задача 2. Палиндром\n";
	std::string str2;
	std::cout << "Введите слово -> ";
	std::cin >> str2;
	std::string str2_1 = str2;	// создадим клон, у кот. все буквы переведем в нижний регистр.
	// переведем все буквы в строке в нижний регистр (почему-то работает только для латиницы):
	for (int i = 0; i < str2_1.length(); i++)
		str2_1[i] = std::tolower(str2_1[i]);
	// также переводем все буквы в нижний регистр (только для кириллицы):
	str2_1 = tolower_rus(str2_1);
	bool word = false;	// создадим переменную состояния word и присвоем ей значение false.
	int count = 0;		// создадим счет и обнулим его.
	// проверим является ли введенное слово палиндромом:
	for (int i = 0; i < str2_1.length()/2; i++)
		if (str2_1[i] == str2_1[(str2_1.length()-1) - i])	// если левый и правый элементы равны,
			count++;										// то инкрементируем счетчик.
	if (count == str2_1.length() / 2)		// если значение счетчика совпадает с кол-вом букв в слове(деленное на 2),
		word = true;						// то переменной word присваиваем значение true.
	if (word)		// если word == true, то переход на строку 54, иначе - 56.
		std::cout << "Слово " << str2 << " является палиндромом\n\n";
	else
		std::cout << "Слово " << str2 << " не является палиндромом\n\n";
	
	// Задача 3. Создайте функцию, которая принимает строку. Функция считает все пробелы, точки, 
	// запятые, восклицательные и вопросительные знаки, которые есть в переданной строке
	// и возвращает их общее количество.
	std::cout << "Задача 3. Подсчет всех знаков препинания и пробелов.\n";
	std::cin.ignore();		// подготовка к выполнению функции std::getline().
	std::string sentence;
	std::cout << "Введите предложение для подсчета всех знаков препинания и пробелов -> ";
	std::getline(std::cin, sentence);
	
	if (search_punct_char(sentence) > 0)
		std::cout << "В введенном предложении " << search_punct_char(sentence) << " знаков препиния и пробелов." << std::endl;
	else
		std::cout << "В введенном слове нет знаков препинания и пробелов." << std::endl;
	std::cout << std::endl;
	
	// Задача 4. Создайте функцию, которая принимает строку и символ. Функция ищет последнее вхождение
	//  символа в переданную строку и возвращает подстроку, начинающуюся с этого символа и
	//  заканчивающуюся концом строки. Если символа в строке нет, то функция возвращает пустую строку.
	std::cout << "Задача 4.\n";
	std::cout << "Введите предложение -> ";
	std::cin.ignore();		// подготовка к выполнению функции std::getline().
	std::string str4;
	getline(std::cin, str4);
	std::cout << "Введите символ -> ";
	char symbol;
	std::cin >> symbol;
	std::cout << my_substr(str4, symbol) << std::endl;
	std::cout << std::endl;
	
	return 0;
}
// Функция по переводу ПРОПИСНЫХ букв в строчные (КОСТЫЛЬ):
template<typename T>
T tolower_rus(T str) {
	std::string RUS = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	std::string rus = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	for (int i = 0; i < str.length(); i++)
		for (int j = 0; j < RUS.length(); j++)
			if (str[i] == RUS[j])	// если найдем в строке str прописную букву из строки RUS, 
				str[i] = rus[j];	// то заменим её на строчную из строки rus той же позиции, что в строке RUS.
	return str;
}
// Функция подсчета знаков препинания и пробелов:
template <typename T>
int search_punct_char(T str) {
	// введем в массив все необходимые знаки препиния и пробел:
	char punkt_char[] = { '.', ',', ':', ';', '?', '!', '(', ')', '=', '-', ' ', '"' };
	int counter = 0;	// создадим счетчик.
	for (int i = 0; i < str.length(); i++)
		for (int j = 0; j < sizeof(punkt_char); j++)	// sizeof(punkt_char) - определяет длину символьного массива.
			if (str[i] == punkt_char[j])
				counter++;
	return counter;
}
// Функция Задачи 4:
template <typename T>
T my_substr(T str, char sym) {
	int index = str.rfind(sym);	// создадим индекс и найдем его значение через str.rfind(sym), т.е. последний индекс символа sym в строке str.
	for (int i = 0; i < str.length(); i++)
		if (str[i] == sym)				// если символ sym присутствует в строке str, то переход к строке 117, иначе переход к строке 118.
			return str.substr(index);	// вернем подстроку из строки от index до конца строки.
	str = "";		// обнулим строку str,
	return str;		// и вернем её в блок main.
}