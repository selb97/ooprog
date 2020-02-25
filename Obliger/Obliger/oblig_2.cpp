#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "LesData2.h"
using namespace std;


class Dyr
{
private:
		string navn;

public:
	Dyr(string navn)
		: navn(navn)
	{};

	Dyr()
	{
		lesData();
	};

	void lesData();
	void skrivData();

};

class DyrILuft : public Dyr
{
private:
	string art;

public:
	DyrILuft()
	{
		lesData();
	}

	void lesData();
	void skrivData();
};

class DyrIVann : public Dyr
{
private:
	string art;

public:
	DyrIVann(string navn)
		: Dyr(navn)
	{
		lesData();
	}

	DyrIVann()
	{
		lesData();
	}

	void lesData();
	void skrivData();
};

class Insekt : public DyrILuft
{
private:
	bool harVinger;

public:
	Insekt()
	{
		lesData();
	}

	void lesData();
	void skrivData();
};

class Fugl : public DyrILuft
{
private:
	bool trekkfugl;

public:
	Fugl()
	{
		lesData();
	}

	void lesData();
	void skrivData();
};

class Fisk : public DyrIVann
{
private:
	int antFinner;

public:
	Fisk(string navn)
	: DyrIVann(navn)
	{
		lesData();
	}

	Fisk()
	{
		lesData();
	}

	void lesData();
	void skrivData();
};

class Skalldyr : public DyrIVann
{
private:
	int antFoter;

public:
	Skalldyr()
	{
		lesData();
	}

	void lesData();
	void skrivData();
};


// Globale funkjsoner

void skrivMeny();


int main()
{

	char valg;
	skrivMeny();

	valg = lesChar("\nVelg ");

	while (valg != 'Q')
	{
		switch (valg)
		{
		case '1': /* funksjon */					break;
		case '2': /* funksjon */					break;
		case '3': /* funksjon */					break;
		case '4': /* funksjon */					break;
		default: cout << "\n\tFEIL KNAPP" << endl;	break;
		}
		cout << "\n\n-----------------------------------------\n"
			 << "-----------------------------------------\n"
			 << "-----------------------------------------\n";
		skrivMeny();
		valg = lesChar("\nVelg ");
	}

	//slettAlt();
	return 0;
}








//	-----------------------------------------------------------------DYR-----------------------------------------------------------------
void Dyr::lesData()
{
	cout << "Skriv navn: "; getline(cin, navn);
}

void Dyr::skrivData()
{
	cout << navn << endl;
}


//	--------------------------------------------------------------DYR I LUFT--------------------------------------------------------------
void DyrILuft::lesData()
{
	cout << "Skriv art: "; getline(cin, art);
}

void DyrILuft::skrivData()
{
	Dyr::skrivData();
	cout << art << endl;
}


//	--------------------------------------------------------------DYR I VANN--------------------------------------------------------------
void DyrIVann::lesData()
{
	cout << "Skriv art: "; getline(cin, art);
}

void DyrIVann::skrivData()
{
	Dyr::skrivData();
	cout << art << endl;
}


//	----------------------------------------------------------------INSEKT----------------------------------------------------------------
void Insekt::lesData()
{
	char c;
	c = lesChar("Har insektet vinger? (Y/N)");
	while (c != 'Y' && c != 'N')
	{
		cin >> c; c = toupper(c);
	}

	c == 'Y' ? harVinger = true : harVinger = false;
}

void Insekt::skrivData()
{
	DyrILuft::skrivData();
	if (harVinger == true)
		cout << "Insektet har vinger";
	else
		cout << "Insekter har ikke vinger";
}


//	-----------------------------------------------------------------FUGL-----------------------------------------------------------------
void Fugl::lesData()
{
	char c;
	c = lesChar("Er det trekkfugl? (Y/N)");
	while (c != 'Y' && c != 'N')
	{
		cin >> c; c = toupper(c);
	}
	c == 'Y' ? trekkfugl = true : trekkfugl= false;
}

void Fugl::skrivData()
{
	DyrILuft::skrivData();
	if (trekkfugl == true)
		cout << "Fuglen er trekkfugl";
	else
		cout << "Fuglen er ikke trekkfugl";
}


//	-----------------------------------------------------------------FISK-----------------------------------------------------------------
void Fisk::lesData()
{
	antFinner = lesInt("Har fisken mange finner?", 1, 6);
}

void Fisk::skrivData()
{
	DyrIVann::skrivData();
	cout << antFinner;
}


//	---------------------------------------------------------------SKALLDYR---------------------------------------------------------------
void Skalldyr::lesData()
{
	antFoter = lesInt("Har skalldyret mange foter?", 1, 6);
}

void Skalldyr::skrivData()
{
	
	DyrIVann::skrivData();
	cout << antFoter;
}


//	-----------------------------------------------------------------GLOBAL----------------------------------------------------------------

void skrivMeny()
{
	cout << "\nKnapp\tM E N Y V A L G \n\n"
		 << "(1)\tInsekt\n"
		 << "(2)\tFugl\n"
		 << "(3)\tFisk\n"
		 << "(4)\tSkalldyr\n"
		 << "(q)\tAvslutt\n";
}