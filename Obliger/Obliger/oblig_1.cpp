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

// struct fra oblig ark
struct Restaurant
{
	string	navn,
			adresse,
			type,
			omtale;
	int		terningkast;
};


// funksjoner fra oblig ark
void nyRestaurant();
void restaurantLesData(Restaurant& restaurant);
void restaurantSkrivData(const Restaurant& restaurant);
void skrivAlleRestauranter();
void skrivMeny();
void slettAlt();

// egene funksjoner
	// fikk ikke bruk for egen funksjoner


// globale variabler
vector <Restaurant*> gRestauranter;	// lager en global dynamisk array


/*
 *	Bruker et typisk oppsett med meny som frode alltid bruker.
 *	Kjører slettAlt() på slutten for ryddighesskyld i memory.
 */
int main()
{
	char valg;
	skrivMeny();
	
	valg = lesChar("\nVelg ");

	while (valg != 'Q')
	{
		switch (valg)
		{
		case '1': nyRestaurant();			break;
		case '2': skrivAlleRestauranter();	break;
		default: skrivMeny();				break;
		}
		cout << "\n\n-----------------------------------------\n";
		skrivMeny();
		valg = lesChar("\nVelg ");
	}

	slettAlt();
	return 0;
}



/*
 *	1. Lager en ny peker til et Restaurant objekt.
 *	2. Leser data inn i pekeren.
 *	3. Sender pekeren til vektoren. Kan ikke sende som en faktisk peker,
 *	siden funksjonen er overloadet.
 */
void nyRestaurant()
{
	Restaurant* rest = new Restaurant;
	restaurantLesData(*rest);
	gRestauranter.push_back(rest);
}



/*
 *	Leser inn alle variablene ved hjelp av getline og frode sine standardfunksjoner.
 *
 *	@param - restaurant - variabler som ligger inne i Struct.
 */
void restaurantLesData(Restaurant& restaurant)
{
	cout << "\nNavn:		      ";	getline(cin, restaurant.navn);
	cout << "Adresse:	      ";	getline(cin, restaurant.adresse);
	cout << "Type:		      ";	getline(cin, restaurant.type);
	cout << "Omtale:	\t      ";	getline(cin, restaurant.omtale);
	restaurant.terningkast = lesInt("Terningkast", 1, 6);
}

/*
 *	Skriver ut alle variablene. <cout3
 *	
 *	@param - restaurant - variabler som ligger inne i Struct.
*/

void restaurantSkrivData(const Restaurant& restaurant)
{
	cout	<< "\nNavn:			" << restaurant.navn << endl
			<< "Adresse:		" << restaurant.adresse << endl
			<< "Type:			" << restaurant.type << endl
			<< "Omtale:			" << restaurant.omtale << endl
			<< "Terningkast:	\t" << restaurant.terningkast << endl;
}

/*
 *	1.	Hvis den dynamiske arrayen er tom får brukeren beskjed om det.
 *	2.	Hvis den ikke er tom, skriv ut alle verdiene i hvert enkelt objekt i den
 *		dynamiske arrayen.
 */

void skrivAlleRestauranter()
{
	if (gRestauranter.size() == 0)
		cout << "\t\t\tFINNES INGEN DATA I PROGRAM\n";

	else
	{
		cout << "\t\t\tSKRIVER ALLE RESTAURANTENE\n";
		for (int i = 0; i < gRestauranter.size(); i++)
			restaurantSkrivData(*gRestauranter[i]);
	}
	
}

/*
 *	Skriver bare en meny.
 */
void skrivMeny()
{
	cout	<< "\nKnapp\tM E N Y V A L G \n\n"
			<< "(1)\tNy restaurant\n"
			<< "(2)\tPrint all data\n"
			<< "(q)\tAvslutt\n";
}


/*
 *	1.	Blar seg fra start til slutt av den dynamiske arrayen, og
 *		sletter alle pekerene som er laget.
 *	2.	Sletter allt innhold i vektoren.
*/
void slettAlt()
{
	for (int i = 0; i < gRestauranter.size(); i++)
		delete gRestauranter[i];
	gRestauranter.clear();
}