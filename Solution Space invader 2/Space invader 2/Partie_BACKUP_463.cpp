#include "Partie.h"
#include "Vaisseau.h"
#include "UIKit.h"
#include <iostream>
#include <conio.h>
#include "Laser.h"
#include "Martien.h"
#include <time.h>
#include "Extraterrestre.h"
<<<<<<< HEAD
#include "Menu.h"

=======
>>>>>>> 6080e69f54a7b8cc47abccfe8c85adb9ffcc4694
/*
	Vous pouvez modifier ce fichier.
*/

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void allezXY(int x, int y);
<<<<<<< HEAD
void Partie::debuter()
{
	Menu monMenu;
=======
void intro();

void Partie::debuter()
{
>>>>>>> 6080e69f54a7b8cc47abccfe8c85adb9ffcc4694
	UIKit::curseurVisible(false);

	UIKit::setDimensionFenetre(0, 0, 100, 50);

	


	bool partieTermine = false;
	UIKit::cadre(0, 0, 30, 40, 137); //gauche top
	UIKit::cadre(0, 21, 30, 20, 137); //gauche bas
	UIKit::cadre(31, 0, 115, 40, 137); // gamebox
<<<<<<< HEAD
=======

>>>>>>> 6080e69f54a7b8cc47abccfe8c85adb9ffcc4694

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

	Vaisseau vaisseau(apparenceDuVaisseau, coordonneesDepartVaisseau, limiteMouvementGauche, limiteMouvementDroite, limiteMouvementHaut, limiteMouvementBas);


	Extraterrestre alien(alienSpawn, apparenceAlien, 1);
	Laser laserJoueurs(vaisseau.getCoord(), LAS_JOUEUR);
	Laser laserAlien(alien.getCoord(), LAS_EXTRATERRESTRE);
	do {
		//R�cup�rer la touche appuy�e par l'utilisateur
		//Effectuer action en fonction de la touche appuy� par l'utilisateur
		//Ici on peut soit d�placer le vaiseau � gauche ou � droite, soit tirer un laser
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
<<<<<<< HEAD
		//	laserAlien.deplacer();
=======

		while (laserJoueurs.getCoord().getY() == 1)
		{
			laserJoueurs.detruire();
		}
		laserAlien.deplacer();

>>>>>>> 6080e69f54a7b8cc47abccfe8c85adb9ffcc4694

			//D�placer les lasers du vaisseau et des extraterrestres		

			//D�placer les extraterrestres		

			//Faire tirer les extraterrestres		

			//V�rifier collision entre laser et joueur ou ennemis

			//Faire apparaitre nouveau extraterrestre

			//Mettre � jour le score affich�		

			//V�rifier si on gagne (si le nombre d'extraterrestre est rendu � 0)		

<<<<<<< HEAD
			//V�rifier si on perd si le nombre d'extra terrestre est � 15+ ou 
			//qu'un laser extraterrestre nous a atteint
=======
//test affichage menu perdu / gagner
//this->gagner();
//this->perdu();
//Sleep(10000);

		//V�rifier si on perd si le nombre d'extra terrestre est � 15+ ou 
		//qu'un laser extraterrestre nous a atteint
>>>>>>> 6080e69f54a7b8cc47abccfe8c85adb9ffcc4694

		Sleep(100);
	} while (partieTermine == false);
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
<<<<<<< HEAD

=======
void intro() {


	//UIKit::gotoXY(5, 10);
	//std::cout << "Notre plan�te est en p�ril!" << std::endl;
	//UIKit::gotoXY(5, 11);
	//std::cout << "Une arm�e de martien a d�cid� d�envahir la terre.Vous �tes toutefois le h�ro de la situation " << std::endl;
	//UIKit::gotoXY(5, 12);
	//std::cout << "et la seule personne capable d�an�antir ces vilains �intragalactiques�." << std::endl;
	//Sleep(3000);
	//UIKit::gotoXY(20, 14);
	//std::cout << "D�marer une partie." << std::endl;
	//UIKit::gotoXY(20, 16);
	//std::cout << "Changer le niveau de difficult� du jeu." << std::endl;
	//UIKit::gotoXY(20, 18);
	//std::cout << "Afficher le mode d�emploi" << std::endl;
	//Sleep(5000);
	//system("cls");



}
>>>>>>> 6080e69f54a7b8cc47abccfe8c85adb9ffcc4694


void allezXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
