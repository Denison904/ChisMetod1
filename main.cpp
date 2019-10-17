#include "stdio.h"
#include "math.h"
#include "conio.h"
#include "iostream"
#include <iomanip>
#define M_PI 3.1415926535897932384626433832795
using namespace std;
double grrad(double x, double m, double s)
{
	x = x * M_PI / 180 + m * M_PI / 180 / 60 + s * M_PI / 180 / 360;
	return x;
}
double fact(int n) {
	double f = 1;
	for (int i = 1; i <= n; i++)
		f /= i;
	return f;
}

void tsin(double x)
{
	double f = 0, eps = 0.0001;
	double f1 = x;
	for (int i = 1; fabs(f1) > eps; i++)
	{
		f1 = powf(-1, i + 1) * powf(x, 2 * i - 1) * fact(2 * i - 1);
		f += f1;
	}
	cout << setprecision(4) << "Значение sin(x)=" << f << " с точностью " << eps << endl;
};

void tcos(double x)
{
	double f = 0, f1 = 1, eps = 0.00001;
	for (int i = 0; fabs(f1) > eps; i++)
	{
		f1 = powf(-1, i) * powf(x, 2 * i) * fact(2 * i);
		f += f1;
	}
	cout << setprecision(5) << "Значение cos(x)=" << f << " с точностью " << eps << endl;
};


void tsh(double x)
{
	int i = 0;
	double f = x, f1 = x, eps = 0.000001;
	while ((f1 *= (x * x / (2 * i + 2) / (2 * i + 3))) > eps)
	{

		f += f1;
		i++;
	}
	if (f <= 1)
		cout << setprecision(7) << "Значение sh(x)=" << f << " с точностью " << eps << endl;
	else cout << setprecision(7) << "Значение sh(x)=" << f << " с точностью " << eps << endl;
};

void tln(double x)
{
	double f = 0, f1 = x, eps = 0.000001;

	if (x <= 0 && x <= 2)
	{
		x--;
		for (int i = 1; fabs(f1) > eps; i++)
		{
			f1 = powf(-1, i + 1) * powf(x, i) / i;
			f += f1;
		}
		cout << setprecision(6) << "Значение ln(x)=" << f << " с точностью " << eps << endl;
	}
	else if (x > 2)
	{
		x = x / (x - 1);
		for (int i = 1; fabs(f1) > eps; i++)
		{
			f1 = 1.0 / (i * pow(x, i));
			f += f1;
		}
		cout << setprecision(7) << "Значение ln(x)=" << f << " с точностью " << eps << endl;
	}
	else cout << "Неверно введен аргумент!" << endl;
};


int main()
{
	setlocale(LC_CTYPE, "russian");
	char a;
	int o, b = 0;
	double x, f;
	double g, m = 0, s = 0;
	do {
		cout << "Выберите интересующую функцию от аргумента \n Введите 1 для sin(x) (Точность 10^(-4)) \n Введите 2 для cos(x) (Точность 10^(-5)) \n Введите 3 для sh(x) (Точность 10^(-6)) \n Введите 4 для lg(x) (Точность 10^(-6)) \n";
		cin >> o;
		if (o != 1 && o != 2 && o != 3 && o != 4)
		{
			cout << "Вы ввели неверное число. Запустите программу заново и введите число от 1 до 4, в зависимости от интересующей функции"; break;
		}
		if (o == 1 || o == 2 || o == 3)
		{
			cout << "Введите 1, чтобы ввести аргумент x в градусах \n Введите 2,чтобы ввести аргумент x в радианах \n";
			cin >> b;
		}
		if (b == 1)
		{
			cout << "Введите градусы, минуты, секунды аргумента x: \n";
			cin >> g >> m >> s;
			x = grrad(g, m, s);
		}
		else
		{
			cout << "Введите значение аргумента x: ";
			cin >> x;
		}

		if (o == 1) tsin(x);
		if (o == 2) tcos(x);
		if (o == 3) tsh(x);
		if (o == 4) tln(x);
		cout << "Продолжеть (y/n)?" << endl;
		cin >> a;
	} while (a == 'y');
	return 0;
}