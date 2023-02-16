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
			go = false;
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
			save();
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

		const char verify = fileN[0];
		if (verify < 0)
		{
			char p[] = "P.txt";
			for (int i = 0; i < 6; i++)
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
			char number[5];
			chili::read(number, 5);
			chili::str2int(number);

			for (int i = 0; i < chili::str2int(number) ; i++)
			{
				out2.put('=');
			}
			

			char endline = '\n';
			out2.put(endline);
			chili::print("\n");
			
		}

		else if (out.good())
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
				char number[5];
				chili::read(number, 5);
				chili::str2int(number);

				for (int i = 0; i < chili::str2int(number); i++)
				{
					out.put('=');
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
	//ok
	void save()
	{
		const char verify = filename[0];
		
		if ( verify < 0 )
		{
			chili::print("\n\n There's no data to save to the file \n\n");
		}

		else
		{
			char Pname[30];
			chili::print("\n Save file as: ");
			chili::read(Pname, 30);

			std::ifstream in(filename); 
			std::ofstream out(Pname);

			for (char c = in.get(); in.good(); c = in.get()) //czytam plik tymczasowy
			{
				out.put(c); // i dla ka¿dego pojedynczego odczytanego znaku wstawiam go do nowego pliku
			}
			chili::print("\n\n");

			in.close();
			out.close();
			char* p = &Pname[0];
			for (int i = 0; *p >= 0 ; i++,p++)
			{
				filename[i] = *p;
			}

			system("del P.txt");
		}
	}

public:
	bool go = true;
private:
	char filename[30];
};


int main()
{
	Database data;	
	while (data.go)
	{
		data.select();
	}
	while (!_kbhit());
	return 0;
}