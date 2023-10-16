#include "Partie.h"
#include "Vaisseau.h"
#include "UIKit.h"
#include <iostream>
#include <conio.h>
#include "Laser.h"
#include "Martien.h"
#include <time.h>
#include "Extraterrestre.h"

/*
	Vous pouvez modifier ce fichier.
*/

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void allezXY(int x, int y);

void Partie::debuter()
{

	system("cls");
	UIKit::curseurVisible(false);

	UIKit::setDimensionFenetre(0, 0, 100, 50);




	bool partieTermine = false;
	UIKit::cadre(0, 0, 30, 40, 137); //gauche top
	UIKit::cadre(0, 21, 30, 20, 137); //gauche bas
	UIKit::cadre(31, 0, 115, 40, 137); // gamebox

	UIKit::color(143);
	allezXY(1, 22);
	cout << " SHOP : ?" << endl;
	cout << endl;
	cout << "  Balance : " << endl;
	cout << endl;
	cout << "  50$ = Ajouter Cannon" << endl;
	cout << endl;
	cout << "  25$ = Ajouter Vie " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "  Nombre de vie : " << endl;


	//Faire apparaitre le vaisseau

	Coord coordonneesDepartVaisseau(73, 35);
	Coord limiteMouvementGauche(32, 0);
	Coord limiteMouvementDroite(114, 0);
	Coord limiteMouvementHaut(0, 15);
	Coord limiteMouvementBas(0, 35);

	srand(time(0));
	Coord alienSpawn(rand() % 114 + 32, rand() % 5 + 1);


	char apparenceAlien = '&';
	char apparenceDuVaisseau = 'A';
	UIKit::color(138);
	Vaisseau vaisseau(apparenceDuVaisseau, coordonneesDepartVaisseau, limiteMouvementGauche, limiteMouvementDroite, limiteMouvementHaut, limiteMouvementBas);


	Extraterrestre alien(alienSpawn, apparenceAlien, 1);
	Laser laserJoueurs(vaisseau.getCoord(), LAS_JOUEUR);
	Laser laserAlien(alien.getCoord(), LAS_EXTRATERRESTRE);
	do {
		//Récupérer la touche appuyée par l'utilisateur
		//Effectuer action en fonction de la touche appuyé par l'utilisateur
		//Ici on peut soit déplacer le vaiseau à gauche ou à droite, soit tirer un laser
		if (GetAsyncKeyState(VK_LEFT)) {
			vaisseau.deplacer(Direction::GAUCHE);
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			vaisseau.deplacer(Direction::DROITE);
		}
		if (GetAsyncKeyState(VK_UP)) {
			vaisseau.deplacer(Direction::HAUT);
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			vaisseau.deplacer(Direction::BAS);
		}

		if (GetAsyncKeyState(VK_SPACE)) {
			vaisseau.getCoord();
			laserJoueurs.getCoord();
			laserJoueurs.isActif();
		}

		laserJoueurs.deplacer();

		// ce while fais disparaitre la balle pour qu'il ne sort pas du cadre de jeu, mais ca bloque le jouruer de plus bouger, si qlq a une solution
		//while (laserJoueurs.getCoord().getY() == 1)
		//{
		//	laserJoueurs.detruire();
		//}

		//laserAlien.deplacer();

			//Déplacer les lasers du vaisseau et des extraterrestres		

			//Déplacer les extraterrestres		

			//Faire tirer les extraterrestres		

			//Vérifier collision entre laser et joueur ou ennemis

			//Faire apparaitre nouveau extraterrestre

			//Mettre à jour le score affiché		

			//Vérifier si on gagne (si le nombre d'extraterrestre est rendu à 0)		
		//if (Extraterrestre::getNbExtraterrestre() == 15 && alien.getValeurPoints() == 0) // alien.getValeurPoints va etre changer par score  (score egale 15)
		//{
		//	this->gagner();
		//}

		//Vérifier si on perd si le nombre d'extra terrestre est à 15+ ou qu'un laser extraterrestre nous a atteint
		//if ((Extraterrestre::getNbExtraterrestre() == 15 && alien.getValeurPoints() == 1) /*|| ou si vaisseau detecter Collision 3 fois */) // alien.getValeurPoints va etre changer par score  (score egale 0)
		//{
		//	this->perdu();
		//}

		Sleep(100);
	} while (partieTermine == false || !(GetAsyncKeyState(VK_ESCAPE)));
	std::system("cls");
}
void Partie::gagner()
{
	UIKit::cadre(51, 10, 95, 25, 15);
	allezXY(68, 12);
	cout << "CONGRATULATION" << endl;
	allezXY(65, 15);
	cout << "Votre Score est : " << endl;
	allezXY(70, 18);
	cout << "SCORE" << endl;
	allezXY(60, 22);
	cout << "NEXT NV" << endl;
	allezXY(72, 22);
	cout << "MENU " << endl;
	allezXY(81, 22);
	cout << "QUITTER" << endl;
}
void Partie::perdu()
{
	UIKit::cadre(51, 10, 95, 25, 15);
	allezXY(68, 12);
	cout << "GAME OVER" << endl;
	allezXY(65, 16);
	cout << "Votre Score est : " << endl;
	allezXY(70, 18);
	cout << "SCORE" << endl;
	allezXY(60, 22);
	cout << "REJOUER" << endl;
	allezXY(72, 22);
	cout << "MENU " << endl;
	allezXY(81, 22);
	cout << "QUITTER" << endl;
}





void allezXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
