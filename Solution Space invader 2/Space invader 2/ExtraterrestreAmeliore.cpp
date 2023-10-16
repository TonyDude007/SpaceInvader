#include "ExtraterrestreAmeliore.h"

#include"UIKit.h"



ExtraterrestreAmeliore::ExtraterrestreAmeliore(Coord coord, char apparence, unsigned short valeurPoints):Extraterrestre(coord,apparence,valeurPoints)
{
}


ExtraterrestreAmeliore::~ExtraterrestreAmeliore()
{
}

void ExtraterrestreAmeliore::afficher()
{
	UIKit::gotoXY(this->coord.getX(), this->coord.getY());
	std::cout << this->apparence;
}

void ExtraterrestreAmeliore::effacer()
{
	UIKit::gotoXY(this->coord.getX(), this->coord.getY());
	std::cout << " ";
}

unsigned short ExtraterrestreAmeliore::getValeurPoints() const
{
	return this->valeurPoints;
}
