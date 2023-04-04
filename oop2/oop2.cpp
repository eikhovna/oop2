#include<iostream>
#include<conio.h>
using namespace std;

class Stasic { //статический объект
	protected:
	int x, y;
	public:
	Stasic() {
		cout << "Stasic() запуск конструктора" << endl;
		x = 0;
		y = 0;
	}
	Stasic(int x, int y) {
		cout << "Stasic() запуск конструктора с параметром" << endl;
		this->x = x;
		this->y = y;
	}
	Stasic(const Stasic& s) {
		cout << "Stasic() запуск конструктора копирования" << endl;
		x = s.x;
		y = s.y;
	}
	~Stasic() {
		cout << x << " " << y << endl;
		cout << "~Stasic() запуск деструктора" << endl;	
	}

	void move(int dx, int dy) {//метод объекта, определяется сразу
		cout << " " << endl << endl;
		printf("move(int dx, int dy)\n");
		x = x + dx;
		y = y + dy;
	}
	void after();//метод объекта, определяется позже
};
void Stasic::after() {
	
	printf("after()\n");
	x = 12;
	y = 8;
 }

class Dimasik:public Stasic {//динамический объект(наследственный)
protected:
	int a;
public:
	Dimasik():Stasic() {
		cout << "Dimasik() запуск конструктора" << endl;
		a = 0;
	}
	Dimasik(int x, int y, int a):Stasic(x, y) {
		cout << "Dimasik() запуск конструктора с параметром" << endl;
		this->a = a;
	}
	Dimasik(const Dimasik& s) {
		cout << "Dimasik() запуск конструктора копирования" << endl;
		x =s.x;
		y = s.y;
		a = s.a;
	}
	~Dimasik() {
		cout << x << " " << y << " " << a << endl;
		cout << "~Dimasik() запуск деструктора" << endl;
	}
};
		
class Papik {//композиция
protected:
	Stasic s,*s2;
public:
	Papik() {
		cout << "Papik() запуск конструктора" << endl;
		s =  Stasic();
		s2 = new Stasic();
	}
	Papik(int x, int y, int x1, int y1) {
		cout << "Papik() запуск конструктора с параметром" << endl;
		s =  Stasic(x, y);
		s2 = new Stasic(x1, y1);
	}
	Papik(const Papik& p) {
		cout << "Papik() запуск конструктора копирования" << endl;
		s =Stasic((p.s));
		s2 =new  Stasic(*(p.s2));
	}
	~Papik() {
		
		delete s2;
		cout << "~Papik() запуск деструктора" << endl;
	}
};




int main()
{
	setlocale(LC_ALL, "rus");
	{	printf("Stasic static\n");
	    Stasic s;
		Stasic s2(5, 9);
		Stasic s3(s2); 
	}
	cout << " " << endl << endl << endl;;
	{
		printf("Stasic dinamic\n");
		Stasic* s = new Stasic;//создание динамических переменных
		Stasic* s2 = new Stasic(5, 9);
		Stasic* s3 = new Stasic(*s2);
		//Stasic* d = new Stasic(5, 9);
		//Stasic* d2 = new Stasic(5, 9);

		s->move(5, 1);//запуск методов
		s2->after();
		delete s;//работа деструктора
		delete s2;
		delete s3;
		
		//delete d;
		//delete d2;
	}
	cout << " " << endl << endl << endl;
	{
		printf("Dimasic dinamik\n");
		Dimasik* s1 = new Dimasik();
		Dimasik* s = new Dimasik(7, 3, 10);
		Dimasik* s2 = new Dimasik(*s);
	//	Stasic* s3 = new Dimasik(7, 3, 10);//помещение объектов в переменные разных типов
		delete s;
		delete s1;
		delete s2;

    // 	delete s3;
	}
	cout << " " << endl << endl << endl;;
	{
		printf("Papik dinamic\n");
		Papik* s = new Papik;
		Papik* s2 = new Papik(3, 5, 1, 1);
		Papik* s3 = new Papik(*s);
		delete s;
		delete s2;
		delete s3;
	}

	_getch();
	return 0;
}