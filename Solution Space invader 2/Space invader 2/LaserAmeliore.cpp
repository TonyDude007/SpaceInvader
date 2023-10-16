#include "LaserAmeliore.h"
#include"UIKit.h"

LaserAmeliore::LaserAmeliore(Coord c, TypeLaser typeLaser):Laser( c,typeLaser)
{
}

LaserAmeliore::~LaserAmeliore()
{
	
}

void LaserAmeliore::deplacer()
{
	this->effacer();
	switch (this->typeLaser)
	{
	case TypeLaser::LAS_JOUEUR:
		UIKit::color(139);
		this->coord.setY(this->coord.getY() - 1);
		break;
	case TypeLaser::LAS_EXTRATERRESTRE:
		UIKit::color(142);
		this->coord.setY(this->coord.getY() + 1);
		break;
	}

	if ((this->coord.getY() <= 2 && this->typeLaser == TypeLaser::LAS_JOUEUR) || (this->coord.getY() >= 40 && this->typeLaser == TypeLaser::LAS_EXTRATERRESTRE)) {
		this->detruire();
	}

	if (this->isActif()) {
		this->afficher();
	}
}

void LaserAmeliore::detruire()
{
	this->effacer();
	ObjetDeJeu::detruire();
}
