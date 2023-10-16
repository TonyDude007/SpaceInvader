#include "Partie.h"
#include "Vaisseau.h"
#include "UIKit.h"
#include <iostream>
#include <conio.h>
#include "Laser.h"
#include "Martien.h"
#include <time.h>
#include "Extraterrestre.h"
#include"ObjetDeJeu.h"
#include "Menu.h"
/*
	Vous pouvez modifier ce fichier.
*/
unsigned short Partie::nbTourDeBoucle = 0;
unsigned short Partie::nbSecondes = 0;
unsigned short Partie::nbMinutes = 0;
unsigned short Partie::calcPosition = 0;



HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void allezXY(int x, int y);


Partie::Partie() :timerSpawn(0) {
}


void Partie::debuter()
{

	bool partieTermine = false;
	system("cls");
	UIKit::curseurVisible(false);
	UIKit::cadre(0, 0, 30, 19, 141); //gauche top
	UIKit::cadre(0, 20, 30, 40, 137); //gauche bas

	UIKit::color(143);
	allezXY(1, 23);
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
	char apparenceDuVaisseau = 'A';
	Coord coordonneesDepartVaisseau(73, 35);
	Coord limiteMouvementGauche(32, 0);
	Coord limiteMouvementDroite(99, 0);
	Coord limiteMouvementHaut(0, 15);
	Coord limiteMouvementBas(0, 35);

	char apparenceAlien = '&';
	char apparenceMartien = '@';
	UIKit::color(138);
	Vaisseau vaisseau(apparenceDuVaisseau, coordonneesDepartVaisseau, limiteMouvementGauche, limiteMouvementDroite, limiteMouvementHaut, limiteMouvementBas);
	Laser laserJoueurs(vaisseau.getCoord(), LAS_JOUEUR);
	

		int nbLaserMax = 2000;
		int nbLaserSurEcran = 100;
		Laser* laserJoueurs[2000];

<<<<<<< HEAD
		if (timerSpawn == 10)
		{
			Extraterrestre alienRandomSpawn = Extraterrestre::randomSpawn();
			timerSpawn = 0;

		}
		Extraterrestre martienRandomSpawn(Coord(75, 5), apparenceMartien, 1500);

		Laser laserAlien(martienRandomSpawn.getCoord(), LAS_EXTRATERRESTRE);
		

		
=======
		do {

>>>>>>> bb9f02cd6a7c9d4acd6101574bfade35f33ceeef

			do {
				this->afficherNbExtraterrestre();
				this->timer();


<<<<<<< HEAD
			laserJoueurs = vaisseau.tireVaisseau(vaisseau.getCoord());
			
		}
		
		

		//Déplacer les lasers du vaisseau et des extraterrestres		
		laserJoueurs.deplacer();
		laserAlien.deplacer();
		//Déplacer les extraterrestres		
=======
				if (timerSpawn == 10)
				{
					Extraterrestre alienRandomSpawn = Extraterrestre::randomSpawn();
					timerSpawn = 0;
				}
				Extraterrestre alienRandomSpawn(Coord(75, 5), apparenceAlien2, 1);

				Laser laserAlien(alienRandomSpawn.getCoord(), LAS_EXTRATERRESTRE);

				//Récupérer la touche appuyée par l'utilisateur
				//Effectuer action en fonction de la touche appuyé par l'utilisateur
				//Ici on peut soit déplacer le vaiseau à gauche ou à droite, soit tirer un laser
				if ((GetAsyncKeyState(VK_ESCAPE))) {
					partieTermine = true;
				}
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
				if (GetAsyncKeyState(VK_SPACE))
				{

					//vaisseau.isActif(); 
					//laserJoueurs.isActif();
					//laserJoueurs.getCoord();
				/*
				if (laserJoueurs[0]->isActif() == true)
				{
					laserJoueurs[0]->deplacer();
				}
				else if (laserJoueurs[0]->isActif() == false)
				{
					laserJoueurs[0] = new Laser(vaisseau.getCoord(), LAS_JOUEUR);
					laserJoueurs[0] = vaisseau.tireVaisseau(vaisseau.getCoord());
				}*/
				}


>>>>>>> bb9f02cd6a7c9d4acd6101574bfade35f33ceeef

				//	laserAlien.deplacer();

						laserJoueurs = vaisseau.tireVaisseau(vaisseau.getCoord());

					
					laserJoueurs.deplacer();
								//	laserAlien.deplacer();


<<<<<<< HEAD
		//Vérifier si on gagne (si le nombre d'extraterrestre est rendu à 0)		
	if (Extraterrestre::getNbExtraterrestre() == 15 ) /// alien.getValeurPoints va etre changer par score  (score egale 15)
	{

		 this->perdu();
		 system("pause");
		

	}
=======

					//laserAlien.deplacer();

					//Déplacer les lasers du vaisseau et des extraterrestres		

					//Déplacer les extraterrestres		

					//Faire tirer les extraterrestres		
>>>>>>> bb9f02cd6a7c9d4acd6101574bfade35f33ceeef

					//Vérifier collision entre laser et joueur ou ennemis

<<<<<<< HEAD
	//if ((Extraterrestre::getNbExtraterrestre() == 15) /*|| ou si vaisseau detecter Collision 3 fois */) // alien.getValeurPoints va etre changer par score  (score egale 0)
	//{
=======
					//Faire apparaitre nouveau extraterrestre
>>>>>>> bb9f02cd6a7c9d4acd6101574bfade35f33ceeef

					//Mettre à jour le score affiché		

<<<<<<< HEAD
		this->perdu();
		//this->swichButtonsGagnerPerdu();
		if (GetAsyncKeyState(VK_LEFT)) {
			UIKit::cadre(64, 21, 72, 23, 15);
			UIKit::cadre(75, 21, 82, 23, 0);
			if (GetAsyncKeyState(VK_SPACE))
			{
				partieTermine = true;

				//this->debuter();
			}
=======
					//Vérifier si on gagne (si le nombre d'extraterrestre est rendu à 0)		
				/*if (Extraterrestre::getNbExtraterrestre() == 15 ) */// alien.getValeurPoints va etre changer par score  (score egale 15)
				//{

					 //this->perdu();
>>>>>>> bb9f02cd6a7c9d4acd6101574bfade35f33ceeef

					/*this->gagner();*/

<<<<<<< HEAD
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			UIKit::cadre(75, 21, 82, 23, 15);
			UIKit::cadre(64, 21, 72, 23, 0);
			if (GetAsyncKeyState(VK_SPACE))
			{
				//partieTermine = true;
=======

				//}

				//Vérifier si on perd si le nombre d'extra terrestre est à 15+ ou qu'un laser extraterrestre nous a atteint

				//if ((Extraterrestre::getNbExtraterrestre() == 15 && alien.getValeurPoints() == 1) /*|| ou si vaisseau detecter Collision 3 fois */) // alien.getValeurPoints va etre changer par score  (score egale 0)
				//{

				//	this->gagner();
				//}

				if ((Extraterrestre::getNbExtraterrestre() == 15 && alienRandomSpawn.getValeurPoints() == 1) /*|| ou si vaisseau detecter Collision 3 fois */) // alien.getValeurPoints va etre changer par score  (score egale 0)
				{
					partieTermine = true;
				}

				Sleep(100);
			} while (partieTermine == false);
			perdu();
			this->swichButtonsGagnerPerdu();
			if (GetAsyncKeyState(VK_SPACE)) {
				if (calcPosition == 2)
				{
					partieTermine = true;
				}
				if (calcPosition == 1)
				{
					this->debuter();
				}
>>>>>>> bb9f02cd6a7c9d4acd6101574bfade35f33ceeef

			}
<<<<<<< HEAD

		}
		

		//if ((Extraterrestre::getNbExtraterrestre() == 15 && alienRandomSpawn.getValeurPoints() == 1) /*|| ou si vaisseau detecter Collision 3 fois */) // alien.getValeurPoints va etre changer par score  (score egale 0)
		//{
		//	this->perdu();
		//	this->swichButtonsGagnerPerdu();
		//	if (GetAsyncKeyState(VK_RETURN))
		//	{
		//		//partieTermine = true;

		//		this->debuter();
		//	}
		//}

=======
>>>>>>> bb9f02cd6a7c9d4acd6101574bfade35f33ceeef

		} while (!GetAsyncKeyState(VK_SPACE));
		std::system("cls");
	}


	
void Partie::gagner()
{
	UIKit::cadre(51, 10, 95, 25, 15);
	allezXY(66, 12);
	cout << "CONGRATULATION" << endl;
	allezXY(65, 15);
	cout << "Votre Score est : " << endl;
	allezXY(71, 18);
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
	allezXY(65, 22);
	cout << "REJOUER" << endl;
	allezXY(77, 22);
	cout << "MENU " << endl;

}

void Partie::timer()
{
	allezXY(1, 3);
	UIKit::color(143);
	this->nbTourDeBoucle++;
	if (this->nbTourDeBoucle == 9)
	{
		this->nbTourDeBoucle = 0;
		this->nbSecondes++;
		if (this->nbSecondes == 60)
		{
			this->nbMinutes++;
			if (this->nbMinutes == 60)
			{
				this->nbMinutes = 0;
			}
		}
	}
	std::cout << "Timer : " << this->nbMinutes << " : " << this->nbSecondes << " : " << this->nbTourDeBoucle;
	timerSpawn++;
}
void Partie::afficherNbExtraterrestre()
{
	allezXY(1, 5);
	UIKit::color(143);
	std::cout << "Extraterrestres : " << Extraterrestre::getNbExtraterrestre();
}

void Partie::swichButtonsGagnerPerdu()
{
	if (GetAsyncKeyState(VK_LEFT)) {
		UIKit::cadre(64, 21, 72, 23, 15);
		UIKit::cadre(75, 21, 82, 23, 0);
		calcPosition = 1;

	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		UIKit::cadre(75, 21, 82, 23, 15);
		UIKit::cadre(64, 21, 72, 23, 0);
		calcPosition = 2;

	}
}
void Partie::tirer()
{

}



void allezXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
