#include <conio.h>
namespace cypu
{
	void print(const char* s)
{
	for (; *s != 0; s++)
	{
		_putch(*s);
	}
}
	
	void read(char* buff, int size)
{
	const char* const pEnd = buff + size;
	for (char c = _getch(); c != 13 && (buff + 1 < pEnd); c = _getch(), buff++)
	{
		_putch(c);
		*buff = c;
	}
	*buff = 0;
}
	
	int str2Int(const char* s)
{
	const char* p = s;
	for (; *p >= '0' && *p <= '9'; p++);
	p--;

	int val = 0;
	int number = 1;

	for (; p >= s; p--)
	{
		val += (*p - '0') * number;
		number *= 10;
	}
	return val;
}
	
	void int2Str(int* s)
{
	print("\n");

	int p = *s;
	int znak[10];
	int i = 0;
	int a = 0;
	int divider = 1;

	int handler = 1;
	int number = 0;
	int* q = &znak[9];

	while (true)
	{
		a = (((p - a) / divider) % 10);
		znak[9 - i] = a;
		divider *= 10;		// roz³am przekazaniej liczby na czesci do tablicy

		int* pStart = q - i;
		number += (*pStart) * handler;
		handler *= 10;
		i++;
		if (number == p) break; // przrównanie liczby p z poskladanych liczb z przekazanych pojedynczych cyfr liczby p
	}

	char znak2[10];
	int j = 0;
	int b = 0;
	bool go = true;
	while (go)
	{
		if (znak[j] >= 0 && znak[j] <= 9)
		{
			znak2[b] = (znak[j + b] + '0');
			if (znak2[b] >= '0' && znak2[b] <= '9')
			{
				_putch(znak2[b]);
				b++;
			}
			else
			{
				go = false;
				break;
			}
		}
		else
		{
			j++;
		}
	}
}
	
	void fib(const int getNumber, int* s)
{
	int* p = s;
	int n = 0;
	if (getNumber == 1)
	{
		n = *(p - 2);
	}
	else if (getNumber == 2)
	{
		n = *(p - 1);
	}
	else
	{
		for (int i = 2; i < getNumber; i++, p++)
		{
			int n1 = *(p - 1);
			int n2 = *(p - 2);
			*p = n1 + n2;
			n = *p;
		}
	}
	int2Str(&n);
}
}

namespace chili
{
	void read(char* buf, int maxSize)
	{
		const char* const pEnd = buf + maxSize;
		for (char c = _getch(); c != 13 && (buf + 1 < pEnd); c = _getch(), buf++)
		{
			_putch(c);
			*buf = c;
		}
		*buf = 0;
	}

	int str2int(const char* s)
	{
		// scan to start point
		const char* p = s;
		for (; *p >= '0' && *p <= '9'; p++);
		p--;

		int val = 0;
		int place = 1;
		// convert place values and accumulate
		for (; p >= s; p--)
		{
			val += (*p - '0') * place;
			place *= 10;
		}

		return val;
	}

	int fib(int n)
	{
		if (n < 2)
		{
			return n;
		}
		return fib(n - 1) + fib(n - 2);
	}

	void strrev(char* pl)
	{
		// scan to start point
		char* pr = pl;
		for (; *pr != 0; pr++);
		pr--;

		for (; pl < pr; pl++, pr--)
		{
			const char temp = *pl;
			*pl = *pr;
			*pr = temp;
		}
	}

	void int2str(int val, char* buf, int size)
	{
		char* const pStart = buf;
		char* const pEnd = buf + size;
		for (; val > 0 && (buf + 1 < pEnd); val /= 10, buf++)
		{
			*buf = '0' + val % 10;
		}
		*buf = 0;
		strrev(pStart);
	}
}


int main()
{
	cypu::print("\nPodaj liczbe: ");
	char number[3];
	cypu::read(number, 3);
	const int GetNumber = cypu::str2Int(number);
	int Stored[100];
	Stored[0] = 0;
	Stored[1] = 1;
	cypu::fib(GetNumber, &Stored[2]);

	while (!_kbhit());
	return 0;
}