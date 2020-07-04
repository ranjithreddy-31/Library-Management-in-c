#include <iostream>
#include<fstream>
#include<cstring>
#include<ctime>
using namespace std;
class book
{
	char a[10][30];
	int y, m, d;
	public:
		void getdata ();
		void putdata ();
		void search ();
		void getTime ();
		void fine ();
		book ()
		{;
			y = 0;
			m = 0;
			d = 0;
		}
};

void book::getdata()
{
	for(int i=0;i<10;i++)
	{
		cout<<"enter the name of"<<i+1<<"book";
		cin>>a[i];
	}
}
void book::putdata ()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		cout << a[i] << endl;

	}
}

void book::search ()
{
	int i;
	char s[20];
	cout << "Enter the name of the book to be searched";
	cin >> s;
	for (i = 0; i < 10; i++)
	{
		if (strcmp (a[i], s) == 0)
		{
			cout << "Book is found at " << i + 1 << " position" << endl;
			break;
		}
	}
	if (i == 10)
	cout << "Book is not found" << endl;

}

void book::getTime ()
{
	std::time_t t = std::time (0);
	std::tm * now = std::localtime (&t);
	cout << "Today's date is :";
	y = (now->tm_year + 1900);
	m = (now->tm_mon + 1);
	d = (now->tm_mday);
	cout << y << '/' << m << '/' << d << endl;
	cout << "You should return it by :";
	d = d + 15;
	if (((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10)|| (m == 12)) && (d > 31))
	{
		d = d % 31;
		m = m + 1;
	}
	else
	{
		if ((m == 2) && ((y % 4 == 0) && (y % 100 == 0) && (y % 400 == 0))&& (d > 29))
		{
			d = d % 29;
			m = m + 1;
		}
		else
		{
			if ((m == 2) && (y % 4 != 0) && (d > 28))
			{
				d = d % 28;
				m = m + 1;
			}
			else
			{
				if ((m == 12) && (d > 31))
				{
					d = d % 31;
					m = 1;
				}
				else
				{
					if (d > 30)
					{
						d = d % 30;
						m = m + 1;
					}
				}
			}
		}
	}
	cout << y << '/' << m << '/' << d;
}

void book::fine ()
{
	int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days = 0;
	float f;
	int y1, m1, d1, y2, m2, d2;
	std::time_t t = std::time (0);
	std::tm * now = std::localtime (&t);
	cout << "Today's date is :";
	y1 = (now->tm_year + 1900);
	m1 = (now->tm_mon + 1);
	d1 = (now->tm_mday);
	cout << y1 << "/" << m1 << "/" << d1 << endl;
	cout << "enter the date on which you took the book in the format y/m/d\n";
	cin >> y2 >> m2 >> d2;
	if (y1 == y2)
	{
		if (m1 == m2)
		{
			days = d1 - d2;
			cout << days;
		}
		else
		{
			for (int i = m2 - 1; i < m1 - 1; i++)
			days += mdays[i];
			days += d1 - d2;
			cout << days;
		}

	}
	else
	{
		for (int j = m2; j < 12; j++)
		days += mdays[j];
		for (int k = 0; k < m1 - 1; k++)
		days += mdays[k];
		if (y1 - y2 >= 1)
		days += (((y1 - y2 - 1) * 365) + mdays[m2 - 1] + d1 - d2);
		cout << days;
	}
	cout << "you took book before " << days << " days\n";
	if (days > 15)
	{
		cout << "you are late by " << days - 15 << " dayis\n";
		f = (days - 15) * 0.5;
		cout << "your fine is " << f << "rs\n";
	}
	else
	{
	cout << "you are on/before the given time\n";
	}
}


int main ()
{
	static int i = 1;
	char j, a[4000][20], p[20];
	int c, e, ch, cho, id;
	book b, t;
	string libpw = "librarian12";
	string x;
	cout << "WELCOME TO LIBRARY\n";
	cout << "Enter who you are\n1.Librarian\n2.Student\n";
	cin >> c;
	switch (c)
	{
		case 1:
			{
				cout << "Enter your password\n";
				cin >> x;
				if (x == libpw)
				{
					b.getdata ();
					ofstream fout;
					fout.open ("bk.txt", ios::out|ios::ate);
					fout.write ((char *)&b,sizeof(b));
					fout.close ();
				}
				else
				cout << "Incorrect password\n";
			}break;
		case 2:
			{
				cout << "enter your choice\n1.new user\t2.old user\n";
				cin >> cho;
				switch (cho)
				{
					case 1:
						{
							cout << "enter tour user id\n";
							cin >> id;
							cout << "enter your password\n";
							cin >> a[id];
							ofstream fout;
							fout.open ("pw.txt", ios::out | ios::ate);
							fout.write ((char *) &a[id], sizeof (a[id]));
							fout.close ();
						}break;
					case 2:
						{
							cout << "enter your user id\n";
							cin >> id;
							cout << "enter your password\n";
							cin >> p;
							ifstream fin;
							fin.open ("pw.txt", ios::in);
							fin.read ((char *) &a[id], sizeof (a[id]));
							if (strcmp (a[id], p) == 0)
							{
								cout << "password is correct";
								cout << "enter your choice\n";
								cout << "1.take book\n2.return book\n";
								cin >> ch;
								switch (ch)
								{
									case 1:
										{
											while (i <= 3)
											{
											ifstream fin;
											fin.open ("bk.txt",ios::in);
											fin.read ((char *)&t, sizeof(t));
											t.putdata ();
											fin.close ();
											t.search ();
											t.getTime ();
											cout << "enter Y to take another book else N\n";
											cin >> j;
											if (j == 'Y')
											i++;
											else
											i = 4;
											}
											if (i == 4)
											cout <<"Thank You(you may have reached your maximum limit)\n";

										}break;
 
									case 2:	
										{
											b.fine ();
										}break;
								}
							}
							else
							cout << "Incorrect password\n";
							fin.close ();
						}break;
				}
			}break;
	}
return 0;
}

 


