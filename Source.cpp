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
			print();
		}

		else if (p == 'a')
		{
			if (once)
			{
				checkFileContent();
				once = false;
			}
			add();
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
	void print() {

		chili::print("\n\n");

		std::ifstream in(filename);
		for (char c = in.get(); in.good(); c = in.get())
		{
			_putch(c);
		}

		chili::print("\n\n");
	}
	//ok
	void add()
	{		
			std::ofstream out(filename);

			for (char* d = &tekst[0]; *d >= 0; d++)
			{
				out.put(*d);
			}

			if (!afterOneLoop || once2)
			{
				tekst[i] = '\n';
				i++;
				out.put('\n');
				once2 = false;
			}
			if (afterOneLoop)
			{
				afterOneLoop = false;
			}

			chili::print("\n\n Enter Name: ");
			chili::read(&tekst[i], 1000);

			for (char* c = &tekst[i]; *c > 0; i++, c++)
			{
				out.put(*c);
			}

			char space = ' ';
			tekst[i] = space;
			i++;
			out.put(space);

			char number[4];
			chili::print("\n\n Enter Value: ");
			chili::read(number, 4);

			char* end  = &tekst[chili::str2int(number) + i];
			for (char* c = &tekst[i] ; c < end;i++, c++)
			{
				tekst[i] = '=';
				out.put('=');
			}
			tekst[i] = 0;
			i++;
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
		once2 = true;
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
		}
	}
	//ok
	void checkFileContent()
	{
		chili::print("\n");
		std::ifstream in(filename);
		for (char c = in.get();in.good(); c = in.get(), i++ )
		{
			tekst[i] = c;
		}
	}
	//ok
	void checkFileExists()
	{	
		std::ifstream in("P.txt");
		if (in)
		{
			in.close();
			system("del P.txt");
		}
		
		char p[] = "P.txt";
		for (int i = 0; i < 6; i++)
		{
			filename[i] = p[i];
		}
	}

public:
	bool go = true;	
private:
	int i = 0;
	char tekst[1000];
	char filename[30];
	bool once = true;
	bool once2 = false;
	bool afterOneLoop = true;
};


int main()
{
	Database data;	

	data.checkFileExists();

	while (data.go)
	{
		data.select();
	}
	return 0;
}