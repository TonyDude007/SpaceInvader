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
void intro();
void Partie::debuter()
{
	
	UIKit::curseurVisible(false);

	UIKit::setDimensionFenetre(0, 0,100,50);

	intro();


	bool partieTermine = false;
	UIKit::cadre(0, 0,30, 40, 137); //gauche top
	UIKit::cadre(0, 21, 30, 20, 137); //gauche bas
	UIKit::cadre(31, 0, 115,40, 137); // gamebox

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
	Coord limiteMouvementBas(0,35);

	srand(time(0));
	Coord alienSpawn( rand() % 114 + 32 , rand() % 5 + 1 );


	char apparenceAlien = '&';
	char apparenceDuVaisseau = 'A';

	Vaisseau vaisseau(apparenceDuVaisseau, coordonneesDepartVaisseau, limiteMouvementGauche, limiteMouvementDroite,limiteMouvementHaut, limiteMouvementBas);


	Extraterrestre alien(alienSpawn,apparenceAlien,1);
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
	//	laserAlien.deplacer();

		//Déplacer les lasers du vaisseau et des extraterrestres		

		//Déplacer les extraterrestres		

		//Faire tirer les extraterrestres		

		//Vérifier collision entre laser et joueur ou ennemis

		//Faire apparaitre nouveau extraterrestre

		//Mettre à jour le score affiché		

		//Vérifier si on gagne (si le nombre d'extraterrestre est rendu à 0)		

		//Vérifier si on perd si le nombre d'extra terrestre est à 15+ ou 
		//qu'un laser extraterrestre nous a atteint

		Sleep(100);
	} while (partieTermine == false);
	std::system("cls");


}
void intro() {
	

	

	//UIKit::gotoXY(5, 10);
	//std::cout << "Notre planète est en péril!" << std::endl;
	//UIKit::gotoXY(5, 11);
	//std::cout << "Une armée de martien a décidé d’envahir la terre.Vous êtes toutefois le héro de la situation " << std::endl;
	//UIKit::gotoXY(5, 12);
	//std::cout << "et la seule personne capable d’anéantir ces vilains «intragalactiques»." << std::endl;
	//Sleep(3000);
	//UIKit::gotoXY(20, 14);
	//std::cout << "Démarer une partie." << std::endl;
	//UIKit::gotoXY(20, 16);
	//std::cout << "Changer le niveau de difficulté du jeu." << std::endl;
	//UIKit::gotoXY(20, 18);
	//std::cout << "Afficher le mode d’emploi" << std::endl;
	//Sleep(5000);
	//system("cls");

	

}

void allezXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
