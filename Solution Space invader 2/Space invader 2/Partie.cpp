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
#include <mmsystem.h>
#include"LaserAmeliore.h"
#include <Windows.h>
#include<iomanip>
#include "ExtraterrestreAmeliore.h"

/*
	Vous pouvez modifier ce fichier.
*/


unsigned short Partie::nbTourDeBoucle = 0;
unsigned short Partie::nbSecondes = 0;
unsigned short Partie::nbMinutes = 0;
unsigned short Partie::calcPosition = 0;
unsigned short Partie::detectMenutoshow = 0;
unsigned short Partie::sleepNiveau = 0;
unsigned short Partie::pointsAccumules = 0;
unsigned short Partie::nbBoucleChangeColor = 0;
unsigned short Partie::nbBoucleChangeTextKillMe = 1;

unsigned short  Partie::banqueMunitionLazer = 900;
unsigned short  Partie::tabNbExtraterrestre = 151;
unsigned short Partie::nbExtraterrestre = 0;
unsigned short  Partie::nbExtraterrestreTue = 0;
unsigned short  Partie::nbMartienTue = 0;
unsigned short  Partie::setNiveauTimer = 9;
unsigned short Partie::setSleep = 100;
unsigned short Partie::nbVie = 3;
unsigned short Partie::tabNbMartien = 0;
unsigned short Partie::nbMartien = 176;
unsigned short Partie::tabNbLaserExtraterrestre = 101;
unsigned short Partie::tabNbLaser = 1;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

Partie::Partie()
{
}


void Partie::debuter()
{

	system("cls");

	bool partieTermine = false;

	//set le niveau de difficulter
	if (sleepNiveau == 2)
	{
		this->setNiveauTimer = 18;
		this->setSleep = 50;
	}

	UIKit::curseurVisible(false);
	UIKit::cadre(0, 0, 30, 19, 141); //gauche top
	UIKit::cadre(0, 20, 30, 40, 137); //gauche bas


	//info tableau
	const unsigned short TAB_MIN = 1;
	const unsigned short TAB_MAX = 200;

	ObjetDeJeu* tabObjetJeu[TAB_MAX];
	for (size_t i = 0; i < TAB_MAX; i++)
	{
		tabObjetJeu[i] = nullptr;
	}


	//info vaisseau
	char apparenceDuVaisseau = 'A';
	Coord coordonneesDepartVaisseau(73, 35);
	Coord limiteMouvementGauche(32, 0);
	Coord limiteMouvementDroite(114, 0);
	Coord limiteMouvementHaut(0, 15);
	Coord limiteMouvementBas(0, 35);


	UIKit::color(138);
	Vaisseau* vaisseau = new Vaisseau(apparenceDuVaisseau, coordonneesDepartVaisseau, limiteMouvementGauche, limiteMouvementDroite, limiteMouvementHaut, limiteMouvementBas);
	tabObjetJeu[0] = vaisseau;

	//info extraterrestre

	Extraterrestre* extraterrestre = nullptr;
	Martien* martien = nullptr;

	//info laser
	Laser* laser = nullptr;
	Laser* laserExtraterrestre = nullptr;


	//music(3); //musique normal
	music(5); // musique pour Evan

	do {

		do {

			this->timer();

			//Pause si cette condition est rencontré
			if ((GetAsyncKeyState(VK_ESCAPE)))
			{
				detectMenutoshow = 1;
				pause();
				if (calcPosition == 2)
				{
					partieTermine = true;
				}
				else
				{
					UIKit::color(0);
					UIKit::cadre(51, 10, 95, 25, 0);
					UIKit::cadre(64, 21, 73, 23, 0);
					allezXY(68, 14);
					cout << "GAME PAUSE" << endl;
					allezXY(55, 18);
					cout << "PRESS << SHIFT >> Apres votre choix." << endl;
					allezXY(65, 22);
					cout << "CONTINUE" << endl;
					allezXY(77, 22);
					cout << "MENU " << endl;
					swichButtonsGagnerPerdu();
					UIKit::gotoXY(0, 0);
				}

			}
			//déplacer le vaisseau
			if (GetAsyncKeyState(VK_LEFT))
			{
				(*vaisseau).deplacer(Direction::GAUCHE);
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				(*vaisseau).deplacer(Direction::DROITE);
			}
			if (GetAsyncKeyState(VK_UP))
			{
				(*vaisseau).deplacer(Direction::HAUT);
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				(*vaisseau).deplacer(Direction::BAS);
			}

			//tire du vaisseau
			if (GetAsyncKeyState(VK_SPACE))
			{
				laser = new Laser((*vaisseau).getCoord(), LAS_JOUEUR);
				tabObjetJeu[tabNbLaser] = laser;
				tabNbLaser++;
				banqueMunitionLazer--;
				if (tabNbLaser == TAB_RESERVE_LAZER_JOUEUR_MAX)
				{
					tabNbLaser = TAB_RESERVE_LAZER_JOUEUR_MIN;
				}
			}

			//afficher les extraterrestre
			if (nbExtraterrestre <= 15)
			{
				if ((rand() % 100 + 1 < 10))
				{
					extraterrestre = new Extraterrestre(Coord(rand() % 80 + 32, rand() % 8 + 3), '&', 1000);
					tabObjetJeu[this->tabNbExtraterrestre] = extraterrestre;
					tabObjetJeu[this->tabNbExtraterrestre]->isActif() == true;
					this->nbExtraterrestre++;
					this->tabNbExtraterrestre++;

					if (this->tabNbExtraterrestre == TAB_RESERVE_EXTRATERRESTRE_MAX)
					{
						this->tabNbExtraterrestre = TAB_RESERVE_EXTRATERRESTRE_MIN;
					}
				}

				if ((rand() % 100 + 1 < 5))
				{
					martien = new Martien(Coord(rand() % 80 + 32, rand() % 8 + 3), '@', 1500);
					tabObjetJeu[this->tabNbMartien] = martien;
					this->nbMartien++;
					this->tabNbMartien++;

					if (this->tabNbMartien == TAB_RESERVE_MARTIEN_MAX)
					{
						this->tabNbExtraterrestre = TAB_RESERVE_MARTIEN_MIN;
					}
				}
			}


			//Faire tirer les extraterrestres
			for (size_t i = TAB_RESERVE_EXTRATERRESTRE_MIN; i < TAB_RESERVE_EXTRATERRESTRE_MAX; i++)
			{
				if (rand() % 100 + 1 < 3)
				{
					if (tabObjetJeu[i] != nullptr && ((Extraterrestre*)tabObjetJeu[i])->isActif() == true)
					{

						laserExtraterrestre = new LaserAmeliore(((Extraterrestre*)tabObjetJeu[i])->getCoord(), LAS_EXTRATERRESTRE);
						tabObjetJeu[tabNbLaserExtraterrestre] = laserExtraterrestre;
						tabNbLaserExtraterrestre++;

						if (tabNbLaserExtraterrestre == TAB_RESERVE_LAZER_EXTRATERRESTRE_MAX)
						{
							tabNbLaserExtraterrestre = TAB_RESERVE_LAZER_EXTRATERRESTRE_MIN;
						}
					}
				}
			}

			//Deplacer les lasers des extraterrestres	
			for (int i = TAB_RESERVE_LAZER_EXTRATERRESTRE_MIN; i < TAB_RESERVE_LAZER_EXTRATERRESTRE_MAX; i++)
			{
				if (tabObjetJeu[i] != nullptr)
				{
					((LaserAmeliore*)tabObjetJeu[i])->deplacer();
				}
			}
			//Deplacer les lasers du vaisseau 	
			for (int i = TAB_RESERVE_LAZER_JOUEUR_MIN; i < TAB_RESERVE_LAZER_JOUEUR_MAX; i++)
			{
				if (tabObjetJeu[i] != nullptr)
				{
					((Laser*)tabObjetJeu[i])->deplacer();
				}
			}


			//Verifier collision entre laser joueur et ennemis
			if (tabNbExtraterrestre > 0)
			{
				for (int i = TAB_RESERVE_LAZER_JOUEUR_MIN; i < TAB_RESERVE_LAZER_JOUEUR_MAX; i++)
				{
					if (((Laser*)tabObjetJeu[i]) != nullptr)
					{
						if (tabObjetJeu[i]->detecterCollision(*extraterrestre))
						{
							
							this->nbExtraterrestreTue++;
							this->nbExtraterrestre--;
							this->pointsAccumules += extraterrestre->getValeurPoints();

						}
					}
				}
			}
			if (tabNbMartien > 0)
			{
				for (int i = TAB_RESERVE_LAZER_JOUEUR_MIN; i < TAB_RESERVE_LAZER_JOUEUR_MAX; i++)
				{
					if (tabObjetJeu[i] != nullptr)
					{
						if (tabObjetJeu[i]->detecterCollision(*martien))
						{

							//this->nbMartienTue++;
							//this->pointsAccumules += martien->getValeurPoints();
						}
					}
				}
			}


			//Verifier collision entre laser ennemi et vaisseau

			for (int i = TAB_RESERVE_LAZER_EXTRATERRESTRE_MIN; i < TAB_RESERVE_LAZER_EXTRATERRESTRE_MAX; i++)
			{
				if (tabObjetJeu[i] != nullptr)
				{
					if (tabObjetJeu[i]->detecterCollision(*vaisseau))
					{
						music(4);
						this->nbVie--;
						UIKit::color(140);
						Menu::afficherOuch();
						Sleep(1000);
						music(5);
						UIKit::color(0);
						Menu::afficherOuch();
					}
				}
			}
			//Verifier collision entre martien et laser ennemi
			for (int i = TAB_RESERVE_MARTIEN_MIN; i < TAB_RESERVE_MARTIEN_MAX; i++)
			{
				if ((Martien*)tabObjetJeu[i] != nullptr)
				{
					if (tabObjetJeu[i]->detecterCollision(*laser))
					{
						system("pause");
					}
				}
			}

			//Gagner si cette condition est rencontré
			if (this->nbExtraterrestreTue >= 15)
			{
				this->pointsAccumules *= 2;
				detectMenutoshow = 2;
				partieTermine = true;
				this->gagner();
				this->setSleep = 2;
			}

			//Perdu si cette condition est rencontré
			/*if ((this->nbExtraterrestre - this->nbExtraterrestreTue == 15) || this->nbVie == 0)
			{
				if ((this->nbExtraterrestre - this->nbExtraterrestreTue >= 15))				<- cette logique doit etre utilisé quand le prb du extraterrestre est fixé
				{
				this->pointsAccumules /= 2;
				}*/
			if ((this->nbExtraterrestre == 15 && this->nbExtraterrestreTue == 0) || this->nbVie == 0)
			{
				detectMenutoshow = 3;
				partieTermine = true;
				perdu();
			}

			//Delete des elements du tableau inactif
			for (int i = TAB_MIN; i < TAB_MAX; i++)
			{
				if (tabObjetJeu[i] != nullptr && tabObjetJeu[i]->isActif() == false)
				{
					delete tabObjetJeu[i];
					tabObjetJeu[i] = nullptr;
				}
			}
			Sleep(setSleep);
		} while (partieTermine == false);

		//**********************************************************************************************************************************************************************************
		//**********************************************************************************************************************************************************************************
		//**********************************************************************************************************************************************************************************

		// Detecter menu pause
		if (detectMenutoshow == 1)
		{
			if (calcPosition == 2)
			{
				this->remettreToutAValeurInitial();  // remettre les valeurs utiliser a 0 
			}
		}

		// Detecter menu gagnier
		if (detectMenutoshow == 2)
		{
			this->remettreToutAValeurInitial();

			if (calcPosition == 2)
			{
				this->setNiveauTimer = 9;
				this->setSleep = 100;
			}
			if (calcPosition == 1)
			{
				this->debuter();
			}
		}
		// Detecter menu perdu
		if (detectMenutoshow == 3)
		{
			this->remettreToutAValeurInitial();
			if (calcPosition == 1)
			{
				this->debuter();
			}
		}
	} while (!(GetAsyncKeyState(VK_SHIFT)));
}



void Partie::gagner()
{
	do
	{
		UIKit::cadre(51, 10, 95, 25, 15);
		allezXY(66, 12);
		cout << "CONGRATULATION" << endl;
		allezXY(65, 16);
		cout << "Votre Score est : " << this->pointsAccumules << endl;
		allezXY(55, 19);
		cout << "PRESS << SHIFT >> Apres votre choix." << endl;
		allezXY(65, 22);
		cout << "Next lvl" << endl;
		allezXY(77, 22);
		cout << "MENU " << endl;
		this->swichButtonsGagnerPerdu();
		UIKit::gotoXY(0, 0);
	} while (!(GetAsyncKeyState(VK_SHIFT)));

}
void Partie::perdu()
{
	do
	{
		UIKit::cadre(51, 10, 95, 25, 15);
		allezXY(68, 12);
		cout << "GAME OVER" << endl;
		allezXY(65, 16);
		cout << "Votre Score est : " << this->pointsAccumules << endl;
		allezXY(55, 19);
		cout << "PRESS << SHIFT >> Apres votre choix." << endl;
		allezXY(65, 22);
		cout << "REJOUER" << endl;
		allezXY(77, 22);
		cout << "MENU " << endl;
		this->swichButtonsGagnerPerdu();
		UIKit::gotoXY(0, 0);
	} while (!(GetAsyncKeyState(VK_SHIFT)));
}

void Partie::pause()
{
	do
	{
		UIKit::cadre(51, 10, 95, 25, 15);
		allezXY(68, 14);
		cout << "GAME PAUSE" << endl;
		allezXY(55, 18);
		cout << "PRESS << SHIFT >> Apres votre choix." << endl;
		allezXY(65, 22);
		cout << "CONTINUE" << endl;
		allezXY(77, 22);
		cout << "MENU " << endl;
		swichButtonsGagnerPerdu();
		UIKit::gotoXY(0, 0);
	} while (!(GetAsyncKeyState(VK_SHIFT)));
	UIKit::cadre(64, 21, 73, 23, 0);
	UIKit::cadre(75, 21, 82, 23, 0);
}

void Partie::timer()
{
	this->changeColors();

	allezXY(2, 2);
	UIKit::color(143);
	this->nbTourDeBoucle++;
	if (this->nbTourDeBoucle == setNiveauTimer)
	{
		this->nbTourDeBoucle = 0;
		this->nbSecondes++;
		nbBoucleChangeColor++;
		nbBoucleChangeTextKillMe++;

		if (nbBoucleChangeColor == 5)
		{
			nbBoucleChangeColor = 0;
		}
		if (nbBoucleChangeTextKillMe > 2)
		{
			nbBoucleChangeTextKillMe = 1;
		}
		if (this->nbSecondes == 60)
		{
			this->nbSecondes = 0;
			this->nbMinutes++;
			if (this->nbMinutes == 60)
			{
				this->nbMinutes = 0;
			}
		}
	}
	allezXY(2, 2);
	std::cout << "Timer : " << ((this->nbMinutes < 10) ? "0" : "");
	std::cout << this->nbMinutes;
	std::cout << " : " << ((this->nbSecondes < 10) ? "0" : "");
	std::cout << this->nbSecondes;
	std::cout << " : " << ((this->nbSecondes < 10) ? "0" : "0");
	std::cout << this->nbTourDeBoucle;

	allezXY(2, 4);
	std::cout << "Score : " << this->pointsAccumules;
	allezXY(2, 6);
	std::cout << "Nombre de vie      : " << this->nbVie;
	allezXY(2, 8);
	std::cout << "Munition restant   : " << this->banqueMunitionLazer;
	allezXY(2, 10);
	std::cout << "Extraterrestres    : " << this->nbExtraterrestre;
	allezXY(2, 12);
	std::cout << "Extraterrestre tue : " << this->nbExtraterrestreTue;
	allezXY(2, 14);
	std::cout << "Martien tue        : " << this->nbMartienTue;
}

void Partie::swichButtonsGagnerPerdu()
{

	if (GetAsyncKeyState(VK_LEFT)) {
		if (detectMenutoshow == 3)
		{
			UIKit::cadre(64, 21, 72, 23, 15);
		}
		else
		{
			UIKit::cadre(64, 21, 73, 23, 15);
		}
		UIKit::cadre(75, 21, 82, 23, 0);
		calcPosition = 1;

	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		UIKit::cadre(75, 21, 82, 23, 15);
		if (detectMenutoshow == 3)
		{
			UIKit::cadre(64, 21, 72, 23, 0);
		}
		else
		{
			UIKit::cadre(64, 21, 73, 23, 0);
		}
		calcPosition = 2;
	}
}

void Partie::remettreToutAValeurInitial()
{
	this->nbExtraterrestre = 0;
	this->pointsAccumules = 0;
	this->nbMinutes = 0;
	this->nbSecondes = 0;
	this->banqueMunitionLazer = 900;
	this->nbExtraterrestreTue = 0;
	this->nbMartienTue = 0;
	this->nbVie = 3;
}

void Partie::setSleepNiveau(unsigned short sleepNiveau)
{
	this->sleepNiveau = sleepNiveau;
}

unsigned short Partie::getBanqueMunitionLazer() const
{
	return this->banqueMunitionLazer;
}

void Partie::changeColors() const
{

	if (nbBoucleChangeColor == 0)
	{
		UIKit::color(138);
	}
	if (nbBoucleChangeColor == 1)
	{
		UIKit::color(139);
	}
	if (nbBoucleChangeColor == 2)
	{
		UIKit::color(140);
	}
	if (nbBoucleChangeColor == 3)
	{
		UIKit::color(141);
	}
	if (nbBoucleChangeColor == 4)
	{
		UIKit::color(142);
	}
	if (nbBoucleChangeColor == 5)
	{
		UIKit::color(143);
	}
	Menu::afficherKillMeText(nbBoucleChangeTextKillMe);
	Menu::afficherLogoExtraterrestre();
}

void Partie::allezXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void Partie::music(short quelleMusique) {

	std::string a1 = "start_music_menu.wav";
	std::string a2 = "Game_start_sound";
	std::string a3 = "music_background.wav";
	std::string a4 = "Ouch.wav";
	std::string a5 = "chanson_pour_evan.wav";

	if (quelleMusique == 1) { PlaySound((a1.c_str()), NULL, SND_ASYNC); }

	else if (quelleMusique == 2) { PlaySound((a2.c_str()), NULL, SND_ASYNC); }

	else if (quelleMusique == 3) { PlaySound((a3.c_str()), NULL, SND_ASYNC); }

	else if (quelleMusique == 4) { PlaySound((a4.c_str()), NULL, SND_ASYNC); }

	else if (quelleMusique == 5) { PlaySound((a5.c_str()), NULL, SND_ASYNC); }
}