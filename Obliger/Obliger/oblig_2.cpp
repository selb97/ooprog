/*
 *	Programmet lar brukeren registrere og lagre tilbakemeldinger til ulike restauranter
 *	som han kan skrive ut til skjermen og se på senere.
 *
 *	@author Sondre Berntzen
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "LesData2.h"
using namespace std;


/**
 *	Hovedklasse i programmet.
 *
 */
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

/**
 *	Underklasse av Dyr, mer spesifikt dyr i luft.
 *
 */
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

/**
 *	Underklasse av Dyr, mer spesifikt dyr i vann.
 *
 */
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

/**
 *	Underklasse av Dyr i Luft, Insekter.
 *
 */
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

/**
 *	Underklasse av Dyr i Luft, Fugler.
 *
 */
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

/**
 *	Underklasse av Dyr i Vann, Fisker.
 *
 */
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

/**
 *	Underklasse av Dyr i Vann, Skalldyr.
 *
 */
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

vector <Insekt*>	insekter;		///< Datastrukturen med alle insekter
vector <Fugl*>		fugler;			///< Datastrukturen med alle fugler
vector <Fisk*>		fisker;			///< Datastrukturen med alle fisker
vector <Skalldyr*>	skalldyr;		///< Datastrukturen med alle skalldyr

/// Teller antall datamedlemmer i strukturer
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

/**
 *  Dyr sin lesdata
 *
 */
void Dyr::lesData()
{
	cout << "Skriv navn: "; getline(cin, navn);
	if (navn.empty())
		navn = "Ukjent";
}

/**
 *  Dyr sin skrivData
 *
 */
void Dyr::skrivData()
{
	cout << "\nNavn: \t\t" << navn << endl;
}


//	--------------------------------------------------------------DYR I LUFT--------------------------------------------------------------

/**
 *  Dyr i Luft sin lesdata
 *
 */
void DyrILuft::lesData()
{
	cout << "Skriv art: "; getline(cin, art);
	if (art.empty())
		art = "Ukjent";
}

/**
 *  Dyr i Luft sin skrivData
 *
 */
void DyrILuft::skrivData()
{
	Dyr::skrivData();
	cout << "Art: \t\t" << art << endl;
}


//	--------------------------------------------------------------DYR I VANN--------------------------------------------------------------

/**
 *  Dyr i Vann sin lesdata
 *
 */
void DyrIVann::lesData()
{
	cout << "Skriv art: "; getline(cin, art);
	if (art.empty())
		art = "Ukjent";
}

/**
 *  Dyr i Vann sin skrivData
 *
 */
void DyrIVann::skrivData()
{
	Dyr::skrivData();
	cout << "Art: \t\t" << art << endl;
}


//	----------------------------------------------------------------INSEKT----------------------------------------------------------------

/**
 *  Insekt sin lesdata
 *
 */
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

/**
 *  Insekt sin skrivdata
 *
 */
void Insekt::skrivData()
{
	DyrILuft::skrivData();
	if (harVinger == true)
		cout << "\t\tInsektet har vinger";
	else
		cout << "\t\tInsekter har ikke vinger";
}


//	-----------------------------------------------------------------FUGL-----------------------------------------------------------------

/**
 *  Fugl sin lesdata
 *
 */
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

/**
 *  Fugl sin skrivdata
 *
 */
void Fugl::skrivData()
{
	DyrILuft::skrivData();
	if (trekkfugl == true)
		cout << "\t\tFuglen er trekkfugl";
	else
		cout << "\t\tFuglen er ikke trekkfugl";
}


//	-----------------------------------------------------------------FISK-----------------------------------------------------------------

/**
 *  Fisk sin lesdata
 *
 */
void Fisk::lesData()
{
	antFinner = lesInt("Har fisken mange finner?", 1, 6);
}

/**
 *  Fisk sin skrivdata
 *
 */
void Fisk::skrivData()
{
	DyrIVann::skrivData();
	cout << "Antall finner: \t" << antFinner;
}


//	---------------------------------------------------------------SKALLDYR---------------------------------------------------------------

/**
 *  Skalldyr sin lesdata
 *
 */
void Skalldyr::lesData()
{
	antFoter = lesInt("Har skalldyret mange foter?", 1, 6);
}

/**
 *  Skalldyr sin skrivdata
 *
 */
void Skalldyr::skrivData()
{
	
	DyrIVann::skrivData();
	cout << "Antall foter: \t" << antFoter;
}


//	-----------------------------------------------------------------GLOBAL----------------------------------------------------------------

/**
 *  Skriver menyen til brukeren
 *
 */
void skrivMeny()
{
	cout << "\nKnapp\tM E N Y V A L G \n\n"
		 << "(1)\tInsekt\n"
		 << "(2)\tFugl\n"
		 << "(3)\tFisk\n"
		 << "(4)\tSkalldyr\n"
		 << "(q)\tAvslutt\n";
}

/**
 *  Lager ett nytt Insekt objekt, skriver ut dataen og sender det inn i datastrukturen
 *
 *	@see Insekt::skrivData()
 */
void nyInsekt()
{
	Insekt* ny = new Insekt;
	cout << "\n............... Insekt " << ++antInsekt << " ...............";
	ny->skrivData();
	insekter.push_back(ny);
}

/**
 *  Lager ett nytt Fugl objekt, skriver ut dataen og sender det inn i datastrukturen
 *
 *	@see Fugl::skrivData()
 */
void nyFugl()
{
	Fugl* ny = new Fugl;
	cout << "\n............... Fugl " << ++antFugl << " ...............";
	ny->skrivData();
	fugler.push_back(ny);
}

/**
 *  Lager ett nytt Fisk objekt, skriver ut dataen og sender det inn i datastrukturen
 *
 *	@see Fisk::skrivData()
 */
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

/**
 *  Lager ett nytt Skalldyr objekt, skriver ut dataen og sender det inn i datastrukturen
 *
 *	@see Skalldyr::skrivData()
 */
void nySkalldyr()
{
	Skalldyr* ny = new Skalldyr;
	cout << "\n............... Skalldyr " << ++antSkalldyr << " ...............";
	ny->skrivData();
	skalldyr.push_back(ny);
}

/**
 *  Sletter alle objekter og tømmer datastrukturene
 *
 */
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

