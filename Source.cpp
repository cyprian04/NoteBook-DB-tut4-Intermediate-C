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

namespace cypu 
{
	void print() {

		chili::print("\n\n");
		std::ifstream in("derp.txt");
		for (char c = in.get(); in.good(); c = in.get())
		{
			_putch(c);
		}
		chili::print("\n\n");
	}

	void add()
	{
		std::ofstream out("derp.txt");

		char repeat = 'a';
		while (repeat =='a')
		{
			repeat = '0';

			chili::print("\n\n Enter Name: ");
			for (char c = _getch(); c != 13; c = _getch())
			{
				_putch(c);
				out.put(c);
			}

			char space = ' ';
			out.put(space);

			chili::print("\n\n Enter number: ");
			for (char c = _getch(); c != 13; c = _getch())
			{
				_putch(c);
				out.put(c);
			}

			char endline = '\n';
			out.put(endline);
			chili::print("\n");
			
			chili::print("(l)oad  (s)ave  (q)uit  (a)dd  (p)rint?");
			repeat = _getch();
		}
	}

	void load(char* f)
	{
		chili::print("\n\nEnter a file name to load: ");

		chili::read(f, 10);
		std::ifstream in(f);

		chili::print("\n\nContent of the file\n==================== \n\n");

		for (char c = in.get(); in.good(); c = in.get())
		{
			_putch(c);
		}
		chili::print("\n\n");
	}
}

int main()
{
	char filename[10];
	bool once = true;

	while (once)
	{		
		once = false;
		chili::print("\n(l)oad  (s)ave  (q)uit  (a)dd  (p)rint?");
		char odp = _getch();
		
		if (odp == 'q')
		{
			chili::print("\n\nsayonara");
			return 0;
		}

		else if (odp == 'p')
		{
			cypu::print();
			once = true;
		}

		else if (odp == 'a')
		{
			cypu::add();
			once = true;
		}

		else if (odp == 's')
		{

			chili::read(filename, 10);
			std::ofstream out(filename);
			once = true;
		}

		else if (odp == 'l')
		{
			cypu::load(filename);
			once = true;
		}

		else
		{
			once = true;
			chili::print("\n");
		}
	}
	
	while (!_kbhit());
	return 0;
}