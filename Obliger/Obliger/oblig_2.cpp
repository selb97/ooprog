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


// GLOBALE FUNKSJONER

void skrivMeny();
void nyInsekt();
void nyFugl();
void nyFisk();
void nySkalldyr();
void slettAlt();



// GLOBALE VARIABLER

vector <Insekt*>	insekter;
vector <Fugl*>		fugler;
vector <Fisk*>		fisker;
vector <Skalldyr*>	skalldyr;

int antInsekt = 0, antFugl = 0, antFisk = 0, antSkalldyr = 0;

int main()
{

	char valg;
	skrivMeny();

	valg = lesChar("\nVelg ");

	while (valg != 'Q')
	{
		switch (valg)
		{
		case '1': nyInsekt();						break;
		case '2': nyFugl();							break;
		case '3': nyFisk();							break;
		case '4': nySkalldyr();						break;
		default: cout << "\n\tFEIL KNAPP" << endl;	break;
		}
		
		cout << "\n\n\n";
		skrivMeny();
		valg = lesChar("\nVelg ");
	}

	slettAlt();
	return 0;
}







//	-----------------------------------------------------------------DYR-----------------------------------------------------------------
void Dyr::lesData()
{
	cout << "Skriv navn: "; getline(cin, navn);
	if (navn.empty())
		navn = "Ukjent";
}

void Dyr::skrivData()
{
	cout << "\nNavn: \t\t" << navn << endl;
}


//	--------------------------------------------------------------DYR I LUFT--------------------------------------------------------------
void DyrILuft::lesData()
{
	cout << "Skriv art: "; getline(cin, art);
	if (art.empty())
		art = "Ukjent";
}

void DyrILuft::skrivData()
{
	Dyr::skrivData();
	cout << "Art: \t\t" << art << endl;
}


//	--------------------------------------------------------------DYR I VANN--------------------------------------------------------------
void DyrIVann::lesData()
{
	cout << "Skriv art: "; getline(cin, art);
	if (art.empty())
		art = "Ukjent";
}

void DyrIVann::skrivData()
{
	Dyr::skrivData();
	cout << "Art: \t\t" << art << endl;
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
		cout << "\t\tInsektet har vinger";
	else
		cout << "\t\tInsekter har ikke vinger";
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
		cout << "\t\tFuglen er trekkfugl";
	else
		cout << "\t\tFuglen er ikke trekkfugl";
}


//	-----------------------------------------------------------------FISK-----------------------------------------------------------------
void Fisk::lesData()
{
	antFinner = lesInt("Har fisken mange finner?", 1, 6);
}

void Fisk::skrivData()
{
	DyrIVann::skrivData();
	cout << "Antall finner: \t" << antFinner;
}


//	---------------------------------------------------------------SKALLDYR---------------------------------------------------------------
void Skalldyr::lesData()
{
	antFoter = lesInt("Har skalldyret mange foter?", 1, 6);
}

void Skalldyr::skrivData()
{
	
	DyrIVann::skrivData();
	cout << "Antall foter: \t" << antFoter;
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

void nyInsekt()
{
	Insekt* ny = new Insekt;
	cout << "\n............... Insekt " << ++antInsekt << " ...............";
	ny->skrivData();
	insekter.push_back(ny);
}

void nyFugl()
{
	Fugl* ny = new Fugl;
	cout << "\n............... Fugl " << ++antFugl << " ...............";
	ny->skrivData();
	fugler.push_back(ny);
}

void nyFisk()
{
	string navn;
	cout << "Skriv navn: "; getline(cin, navn);

	if (navn.empty())
	{ 
		cout << "\nVi prover pa nytt...\n";
		Fisk* ny = new Fisk;
		cout << "\n............... Fisk " << ++antFisk << " ...............";
		ny->skrivData();
		fisker.push_back(ny);
	}
	else
	{
		Fisk* ny = new Fisk(navn);
		cout << "\n............... Fisk " << ++antFisk << " ...............";
		ny->skrivData();
		fisker.push_back(ny);
	}
		
}

void nySkalldyr()
{
	Skalldyr* ny = new Skalldyr;
	cout << "\n............... Skalldyr " << ++antSkalldyr << " ...............";
	ny->skrivData();
	skalldyr.push_back(ny);
}

void slettAlt()
{
	for (int i = 0; i < insekter.size(); i++)
	{
		delete insekter[i];
		// --antInsekt;
	}

	for (int i = 0; i < fugler.size(); i++)
	{
		delete fugler[i];
		// --antFugl;
	}

	for (int i = 0; i < fisker.size(); i++)
	{
		delete fisker[i]; 
		// --antFisk;
	}

	for (int i = 0; i < skalldyr.size(); i++)
	{
		delete skalldyr[i];
		// --antSkalldyr;
	}

	insekter.clear(); fugler.clear(); fisker.clear(); skalldyr.clear();

}

