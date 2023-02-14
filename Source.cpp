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

class Database
{
public:

	void select() 
	{
		chili::print("\n(l)oad  (s)ave  (q)uit  (a)dd  (p)rint?");
		char odp = _getch();
		choice(odp);
	}

	void choice(char p)
	{
		if (p == 'q')
		{
			chili::print("\n\n	koniec	\n\n");
		}

		else if (p == 'p')
		{
			print(filename);
		}

		else if (p == 'a')
		{
			add(filename);
		}

		else if (p == 's')
		{
			save(SomeTypedName, SomeTypedValue);
		}

		else if (p == 'l')
		{
			load();
		}
	
		else
		{
			chili::print("\n");
		}
	}

	void print(char* fileN) {

		chili::print("\n\n");

		std::ifstream in(fileN);
		for (char c = in.get(); in.good(); c = in.get())
		{
			_putch(c);
		}

		chili::print("\n\n");
	}

	void add(char* fileN)
	{
		std::ofstream out(fileN, std::ios::app);

		if (out.fail())
		{
			chili::print("\n u don't have a file yet ;)");

			chili::print("\n\n Enter Name: ");
			chili::read(SomeTypedName, 10);

			chili::print("\n\n Enter value: ");
			chili::read(SomeTypedValue, 3);

		}
		else if (out.good())
		{
			bool once = true;
			while (once)
			{
				
				chili::print("\n\n Enter Name: ");
				for (char c = _getch(); c != 13; c = _getch())
				{
					_putch(c);
					out.put(c);
				}

				char space = ' ';
				out.put(space);

				chili::print("\n\n Enter value: ");
				for (char c = _getch(); c != 13; c = _getch())
				{
					_putch(c);
					out.put(c);
				}

				char endline = '\n';
				out.put(endline);
				chili::print("\n");
				once = false;
			}
		}
	}

	void load()
	{
		chili::print("\n\nEnter a file name to load: ");

		chili::read(filename, 10);
		std::ifstream in(filename);

		chili::print("\n\nContent of the file\n==================== \n\n");

		for (char c = in.get(); in.good(); c = in.get())
		{
			_putch(c);
		}
		chili::print("\n\n");
	} 

	void save(char* name, char* value)
	{
		const char verify = filename[0]; // wa¿na rzecz, narazie zostaw
		
		if (verify < 0 && *value >= 0)

		{
			chili::print("\n Save file as: ");

			chili::read(filename, 10);
			std::ofstream out(filename);

			const char* const pEnd = name + 10;
			for (char* c = name; *c != 0 && (name+1 < pEnd); c = name, name++)
			{
				out.put(*c);
			}

			const char* const vEnd = value + 3;
			for (char* c = value; *c != 0 && (name+1 < vEnd); c = value, value++)// poprawiæ usterke z wyœwietlaniem
			{
				out.put(*c);
			}
		}
		else if(*value < 0 && verify < 0)
		{
			chili::print("\n\n There's no data to save to the file \n\n");
		}
	}

private:

	char filename[10];
	char SomeTypedName[10];
	char SomeTypedValue[3];
};


int main()
{
	Database data;	
	while (true)
	{
		data.select();
	}
	while (!_kbhit());
	return 0;
}