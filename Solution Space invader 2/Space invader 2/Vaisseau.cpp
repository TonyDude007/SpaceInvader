#include "Vaisseau.h"
#include "UIKit.h"
#include <iostream>

Vaisseau::Vaisseau(char apparenceVaisseau, Coord c, Coord limiteGauche, Coord limiteDroite, Coord limiteHaut, Coord limiteBas) : apparence(apparenceVaisseau), ObjetDeJeu(c, TypeObjetDeJeu::OBJ_VAISSEAU), limiteGauche(limiteGauche), limiteDroite(limiteDroite), limiteHaut(limiteHaut), limiteBas(limiteBas) {
	this->afficher();
}

void Vaisseau::effacer() {
	UIKit::gotoXY(this->coord.getX(), this->coord.getY());
	std::cout << " ";
}

void Vaisseau::deplacer(Direction direction) {
	this->effacer();
	switch (direction)
	{
	case Direction::GAUCHE:
		if (this->coord.getX() > this->limiteGauche.getX()) {
			this->coord.setX(this->coord.getX() - 1);
		}
		break;
	case Direction::DROITE:
		if (this->coord.getX() < this->limiteDroite.getX()) {
			this->coord.setX(this->coord.getX() + 1);
		}
		break;
	case Direction::HAUT:
		if (this->coord.getY() > this->limiteHaut.getY()) {
			this->coord.setY(this->coord.getY() - 1);
		}
		break;
	case Direction::BAS:
		if (this->coord.getY() < this->limiteBas.getY()) {
			this->coord.setY(this->coord.getY() + 1);
		}
		break;
	}
	this->afficher();
}

Laser Vaisseau::tireVaisseau(Coord VaisseauGetCoord)
{

	Laser monLaser(VaisseauGetCoord, LAS_JOUEUR);

	return monLaser;

}




void Vaisseau::afficher() {
	UIKit::gotoXY(this->coord.getX(), this->coord.getY());
	std::cout << this->apparence;
}