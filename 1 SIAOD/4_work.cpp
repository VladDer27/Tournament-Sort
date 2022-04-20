#include <iostream>
#include <fstream>
#include <vector>
#include <valarray> 
#include <sstream>
#include <cstring>
#include <string>

using namespace std;



struct Film {
	string name;
	string studio;
	string genre;
	string year;
	string director;
	string actor_1;
	string actor_2;
	string actor_3;
};



void testInA(vector <Film>& myObj) {
	// Запись в файл А

	

	ofstream out_A;
	out_A.open("A.txt");
	if (out_A.is_open()) {
		for (int i = 0; i < myObj.size(); i++) {
			out_A << myObj[i].director << ";";
		}
	}
	out_A.close();
}

void intSliyanie(vector<int>& A, vector<int>& B, vector<int>& C)

{
	// Функция реализуеут слияние массивов A и B размеров

	size_t a = 0, b = 0; // Индексы текущих элементов в массивах A и B

	if (A.size() == 0) {
		for (int i = 0; i < B.size(); i++) {
			C.push_back(B[i]);
		}
		return;
	}

	if (B.size() == 0) {
		for (int i = 0; i < A.size(); i++) {
			C.push_back(A[i]);
		}
		return;
	}

	while (a + b < A.size() + B.size()) // пока остались элементы в массивах

	{
		if ((b >= B.size()) || ((a < A.size()) && (A[a] <= B[b])))
		{

			// Копируем элемент из массива A

			C.push_back(A[a]);

			++a;

		}

		else

		{

			// Копируем элемент из массива B
			C.push_back(B[b]);
			++b;
		}
	}
}

void fromAtoBCNum(int portion) {
	// Достаем из файла А и записываем в B и C
	vector <int> Arr;

	ifstream fin;
	ofstream out_B;
	out_B.open("B.txt");
	ofstream out_C;
	out_C.open("C.txt");

	fin.open("A.txt");

	int number;
	do
	{
		// пробуем считать число
		if (fin >> number)
		{
			// если считали число - выводим
			Arr.push_back(number);
		} 
		else
		{
			// если считали не число, очищаем ошибки
			fin.clear();
			// пропускаем символы до следующего пробела
			fin.ignore(1, ' ');
		}
	} while (!fin.eof());

	int counter = 0;
	for (int i = 0; i < Arr.size(); i += portion) {
		if (counter % 2 == 0) {
			for (int j = i; j < min(i + portion, static_cast <int> (Arr.size())); j++){
				out_B << Arr[j] << " ";
			}
		}
		else {
			for (int j = i; j < min(i + portion, static_cast <int> (Arr.size())); j++) {
				out_C << Arr[j] << " ";
			}
		}
		counter++;
	}
	Arr.clear();
	fin.close();
	out_B.close();
	out_C.close();
	
}

void intMerge(int portion) {
	ofstream out_A;
	ifstream fin_B;
	ifstream fin_C;
	out_A.open("A.txt");
	fin_B.open("B.txt");
	fin_C.open("C.txt");
	vector<int> A;
	vector<int> B;
	vector<int> C;

	int number;
	do
	{
		// пробуем считать число
		if (fin_B >> number)
		{
			B.push_back(number);
		}
		else
		{
			// если считали не число, очищаем ошибки
			fin_B.clear();
			// пропускаем символы до следующего пробела
			fin_B.ignore(1, ' ');
		}
	} while (!fin_B.eof());
	do
	{
		// пробуем считать число
		if (fin_C >> number)
		{
			C.push_back(number);
		}
		else
		{
			// если считали не число, очищаем ошибки
			fin_C.clear();
			// пропускаем символы до следующего пробела
			fin_C.ignore(1, ' ');
		}
	} while (!fin_C.eof());


	for (int i = 0; i < max(B.size(), C.size()); i += portion) {
		vector<int> b;
		vector<int> c;
		for (int j = i; j < min(B.size(), static_cast <size_t> (i + portion)); j++) {
			b.push_back(B[j]);
		}
		for (int j = i; j < min(C.size(), static_cast <size_t> (i + portion)); j++) {
			c.push_back(C[j]);
		}

		intSliyanie(b, c, A);
	}


	if (out_A.is_open()) {
		for (int i = 0; i < A.size(); i++) {
			out_A << A[i] << " ";
		}
	}



	out_A.close();
	fin_B.close();
	fin_C.close();
}

void Sliyanie(vector<string>& A, vector<string>& B, vector<string>& C) {
	// Функция реализуеут слияние массивов A и B размеров

	size_t a = 0, b = 0; // Индексы текущих элементов в массивах A и B

	if (A.size() == 0) {
		for (int i = 0; i < B.size(); i++) {
			C.push_back(B[i]);
		}
		return;
	}

	if (B.size() == 0) {
		for (int i = 0; i < A.size(); i++) {
			C.push_back(A[i]);
		}
		return;
	}

	while (a + b < A.size() + B.size()) // пока остались элементы в массивах
	{
		if ((b >= B.size()) || ((a < A.size()) && (A[a] <= B[b]))){
			// Копируем элемент из массива A
			C.push_back(A[a]);
			++a;
		}
		else
		{
			// Копируем элемент из массива B
			C.push_back(B[b]);
			++b;
		}
	}
}

void fromAtoBC(int portion) {
	vector <string> Arr;

	ifstream fin;
	ofstream out_B;
	out_B.open("B.txt");
	ofstream out_C;
	out_C.open("C.txt");

	fin.open("A.txt");
	string str;
	while (getline(fin, str)) {

		string temp = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ';') {
				temp = temp + str[i];
			}
			else {
				Arr.push_back(temp);
				temp = "";
			}


		}
	}
	int counter = 0;
	for (int i = 0; i < Arr.size(); i += portion) {
		if (counter % 2 == 0) {
			for (int j = i; j < min(i + portion, static_cast <int> (Arr.size())); j++) {
				out_B << Arr[j] << ";";
			}
		}
		else {
			for (int j = i; j < min(i + portion, static_cast <int> (Arr.size())); j++) {
				out_C << Arr[j] << ";";
			}
		}
		counter++;
	}
	Arr.clear();
	fin.close();
	out_B.close();
	out_C.close();

}

void Merge(int portion) {
	ofstream out_A;
	ifstream fin_B;
	ifstream fin_C;
	out_A.open("A.txt");
	fin_B.open("B.txt");
	fin_C.open("C.txt");
	vector<string> A;
	vector<string> B;
	vector<string> C;

	string str;
	while (getline(fin_B, str)) {

		string temp = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ';') {
				temp = temp + str[i];
			}
			else {
				B.push_back(temp);
				temp = "";
			}


		}
	}
	while (getline(fin_C, str)) {

		string temp = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ';') {
				temp = temp + str[i];
			}
			else {
				C.push_back(temp);
				temp = "";
			}


		}
	}
	
	
	for (int i = 0; i < max(B.size(), C.size()); i += portion) {
		vector<string> b;
		vector<string> c;
		for (int j = i; j < min(B.size(), static_cast <size_t> (i + portion)); j++) {
			b.push_back(B[j]);
		}
		for (int j = i; j < min(C.size(), static_cast <size_t> (i + portion)); j++) {
			c.push_back(C[j]);
		}

		Sliyanie(b, c, A);
	}


	if (out_A.is_open()) {
		for (int i = 0; i < A.size(); i++) {
			out_A << A[i] << ";";
		}
	}
	


	out_A.close();
	fin_B.close();
	fin_C.close();
}

void fromAtoFinal(vector <Film>& myObj) {
	vector <string> Arr;

	ifstream fin;
	fin.open("A.txt");

	ofstream out_Final;
	out_Final.open("Отредактированный ВидеоФильм .txt");

	string str;
	while (getline(fin, str)) {
		string temp = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ';') {
				temp = temp + str[i];
			}
			else {
				Arr.push_back(temp);
				temp = "";
			}
		}
	}
	for (int i = 0; i < myObj.size(); i++) {
		for (int j = 0; j < Arr.size(); j++) {
			if (myObj[j].director == Arr[i]) {
				if (out_Final.is_open()) {
					out_Final << myObj[j].name << ";" << myObj[j].studio << ";" << myObj[j].genre << ";" << myObj[j].year << ";" << myObj[j].director << ";" << myObj[j].actor_1 << ";" << myObj[j].actor_2 << ";" << myObj[j].actor_3 << ";" << endl;
				}
				break;
			}
		}
	}




	out_Final.close();
	fin.close();
}

bool fromAtoBCSecondTryInt() {
	vector <int> Arr;
	

	ifstream fin;
	fin.open("A.txt");

	int number;
	do
	{
		// пробуем считать число
		if (fin >> number)
		{
			// если считали число - выводим
			Arr.push_back(number);
		}
		else
		{
			// если считали не число, очищаем ошибки
			fin.clear();
			// пропускаем символы до следующего пробела
			fin.ignore(1, ' ');
		}
	} while (!fin.eof());

	int counter = 0;

	vector<int> A;
	vector<int> B;
	vector<int> C;

	vector <int> b;
	vector <int> c;

	b.push_back(Arr[0]);
	B.push_back(Arr[0]);
	
	for (int i = 1; i < Arr.size(); i++) {
		if (Arr[i - 1] < Arr[i]) {
			if (counter % 2 == 0) {
				b.push_back(Arr[i]);
				B.push_back(Arr[i]);
				if (b.size() == Arr.size()) {
					fin.close();
					return false;
				}
			}
			else {
				c.push_back(Arr[i]);
				C.push_back(Arr[i]);
			}
		}
		else {
			counter++;
			if (counter % 2 == 0) {
				intSliyanie(b, c, A);
				b.clear();
				c.clear();
				b.push_back(Arr[i]);
				B.push_back(Arr[i]);
			}
			else {
				c.push_back(Arr[i]);
				C.push_back(Arr[i]);
			}
		}
		

	}
	intSliyanie(b, c, A);

	ofstream out_B;
	out_B.open("B.txt");
	ofstream out_C;
	out_C.open("C.txt");

	if (out_B.is_open()) {
		for (int i = 0; i < B.size(); i++) {
			out_B << B[i] << " ";
		}
	}
	if (out_C.is_open()) {
		for (int i = 0; i < C.size(); i++) {
			out_C << C[i] << " ";
		}
	}

	out_B.close();
	out_C.close();
	fin.close();
	
	ofstream out_A;
	out_A.open("A.txt");

	if (out_A.is_open()) {
		for (int i = 0; i < A.size(); i++) {
			out_A << A[i] << " ";
		}
	}
	out_A.close();
	return true;
}

bool secondSort() {
	vector <string> Arr;

	ifstream fin;
	

	fin.open("A.txt");
	string str;
	while (getline(fin, str)) {

		string temp = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ';') {
				temp = temp + str[i];
			}
			else {
				Arr.push_back(temp);
				temp = "";
			}


		}
	}

	
	int counter = 0;

	vector<string> A;
	vector<string> B;
	vector<string> C;

	vector <string> b;
	vector <string> c;

	b.push_back(Arr[0]);
	B.push_back(Arr[0]);

	for (int i = 1; i < Arr.size(); i++) {
		if (Arr[i - 1] < Arr[i]) {
			if (counter % 2 == 0) {
				b.push_back(Arr[i]);
				B.push_back(Arr[i]);
				if (b.size() == Arr.size()) {
					fin.close();
					return false;
				}
			}
			else {
				c.push_back(Arr[i]);
				C.push_back(Arr[i]);
			}
		}
		else {
			counter++;
			if (counter % 2 == 0) {
				Sliyanie(b, c, A);
				b.clear();
				c.clear();
				b.push_back(Arr[i]);
				B.push_back(Arr[i]);
			}
			else {
				c.push_back(Arr[i]);
				C.push_back(Arr[i]);
			}
		}


	}
	Sliyanie(b, c, A);

	ofstream out_B;
	out_B.open("B.txt");
	ofstream out_C;
	out_C.open("C.txt");

	if (out_B.is_open()) {
		for (int i = 0; i < B.size(); i++) {
			out_B << B[i] << ";";
		}
	}
	if (out_C.is_open()) {
		for (int i = 0; i < C.size(); i++) {
			out_C << C[i] << ";";
		}
	}

	out_B.close();
	out_C.close();
	fin.close();

	ofstream out_A;
	out_A.open("A.txt");

	if (out_A.is_open()) {
		for (int i = 0; i < A.size(); i++) {
			out_A << A[i] << ";";
		}
	}
	out_A.close();
	
	return true;
	
}
/*
int main() {
	
	setlocale(LC_ALL, "ru");

	vector <Film> myObj;
	ifstream fin;
	fin.open("ВидеоФильм(32).txt");
	string str;
	while (getline(fin, str)) {
		vector<string> tokens;
		
		string temp = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ';' ) {
				temp = temp + str[i];
			}
			else {
				tokens.push_back(temp);
				temp = "";
			}
			

		}
		
		
		Film film;
		film.name = tokens[0];
		film.studio = tokens[1];
		film.genre = tokens[2];
		film.year = tokens[3];
		film.director = tokens[4];
		film.actor_1 = tokens[5];
		film.actor_2 = tokens[6];
		film.actor_3 = tokens[7];
		myObj.push_back(film);
	}
	fin.close();

	// Не трогать!
	/*
	int n = 32;
	int portion = 1;
	testInA(myObj);
	while (portion <= n) {
		fromAtoBC(portion);
		Merge(portion);
		portion *= 2;
	}
	fromAtoFinal(myObj);
	
	
	testInA(myObj);
	while(secondSort());
	fromAtoFinal(myObj);
	
	
	return 0;
}
*/

