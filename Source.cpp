#include <conio.h>
#include <fstream>
namespace chili
{
	void print(const char* s)
	{
		for (; *s != 0; s++)
		{
			_putch(*s);
		}
	}

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
	// const char data[] = "abc\n\n123";
	// std::ofstream out("test.txt", std::ios::binary);
	// // jeœli zapisujemy dane do pliku które zawieraj¹ tylko liczby ipt. to powinno siê je zapisywaæ w formacie std::ios::binary  //
	// for ( char c: data )
	// {
	// 	if (c == 0)
	// 	{
	// 		break;
	// 	}
	// 	out.put(c);
	// }
	// 
	// std::ofstream out2("boi.dat", std::ios::binary);
	// const int myInt = 69420;
	// out2.write(reinterpret_cast<const char*>(&myInt), sizeof(myInt)); // podajemy rozmiar zmiennej( int w c++ to 4 bajty (32 bity))
	// // do funkcji read i write z biblioteki fstream trzeba stosowaæ reinterpret_cast<char*>, poniewa¿ przyjmuj¹ one wskaŸnik jako parametr

	std::ifstream in2("boi.dat", std::ios::binary); // odczytywanie danych, które wpisaliœmy wczeœniej do pliku
	int data2;
	in2.read(reinterpret_cast<char*>(&data2), sizeof(data2)); 
	char buffer[10];
	chili::int2str(data2, buffer, 10);
	chili::print(buffer);

	while (!_kbhit());
	return 0;
}