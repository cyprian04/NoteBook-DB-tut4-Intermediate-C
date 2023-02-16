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
	//ok
	void select() 
	{
		chili::print("\n(l)oad  (s)ave  (q)uit  (a)dd  (p)rint?");
		char odp = _getch();
		choice(odp);
	}
	//ok
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
	//ok
	void print(char* fileN) {

		chili::print("\n\n");

		std::ifstream in(fileN);
		for (char c = in.get(); in.good(); c = in.get())
		{
			_putch(c);
		}

		chili::print("\n\n");
	}
	//ok
	void add(char* fileN)
	{
		std::ofstream out(fileN, std::ios::app);

		const char verify = filename[0];
		if (verify < 0)
		{
			char p[] = "Prototyp.txt";
			for (int i = 0; i < 13; i++)
			{
				filename[i] = p[i];
			}

			std::ofstream out2( filename, std::ios::app);
			chili::print("\n u created a prototype file ;)");

			chili::print("\n\n Enter Name: ");
			for (char c = _getch(); c != 13; c = _getch())
			{
				_putch(c);
				out2.put(c);
			}

			char space = ' ';
			out2.put(space);

			chili::print("\n\n Enter value: ");
			for (char c = _getch(); c != 13; c = _getch())
			{
				_putch(c);
				out2.put(c);
			}

			char endline = '\n';
			out2.put(endline);
			chili::print("\n");
			
		}

		if (out.good())
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
		}
	}
	//ok
	void load()
	{
		chili::print("\n\nEnter a file name to load: ");

		chili::read(filename, 30);
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
		const char verify = filename[0];
		
		if (*value < 0 && verify < 0 && *name < 0)
		{
			chili::print("\n\n There's no data to save to the file \n\n");
		}

		else
		{
			chili::print("\n Save file as: ");

			chili::read(filename, 10);
			std::ofstream out(filename); /// wykorzystaæ ifstream z pliku o nazwie prototype.txt, ju¿ coraz bli¿ej rozwi¹zania
		}
	}

private:

	char filename[30];
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