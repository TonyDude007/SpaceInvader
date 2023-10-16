#include "Partie.h"
#include "Vaisseau.h"
#include "UIKit.h"
#include <iostream>
#include <conio.h>

/*
	Vous pouvez modifier ce fichier.
*/
void intro();
void Partie::debuter()
{
	
	UIKit::curseurVisible(false);

	UIKit::setDimensionFenetre(0, 0,100,50);

	intro();


	bool partieTermine = false;
	// x,heightleft // bottom x , Height
	UIKit::cadre(0, 0,30, 40, 137); //gauche top
	UIKit::cadre(0, 21, 30, 20, 137); //gauche bas
	UIKit::cadre(31, 0, 115,40, 137); // gamebox

	//Faire apparaitre le vaisseau

	Coord coordonneesDepartVaisseau(73, 35);
	Coord limiteMouvementGauche(32, 0);
	Coord limiteMouvementDroite(114, 0);

	char apparenceDuVaisseau = 'A';
	Vaisseau vaisseau(apparenceDuVaisseau, coordonneesDepartVaisseau, limiteMouvementGauche, limiteMouvementDroite);


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

		//D�placer les lasers du vaisseau et des extraterrestres		

		//D�placer les extraterrestres		

		//Faire tirer les extraterrestres		

		//V�rifier collision entre laser et joueur ou ennemis

		//Faire apparaitre nouveau extraterrestre

		//Mettre � jour le score affich�		

		//V�rifier si on gagne (si le nombre d'extraterrestre est rendu � 0)		

		//V�rifier si on perd si le nombre d'extra terrestre est � 15+ ou 
		//qu'un laser extraterrestre nous a atteint

		Sleep(100);
	} while (partieTermine == false);
	system("cls");


}
void intro() {
	
	UIKit::setDimensionFenetre(0, 0, 100, 42);
	locale::global(locale(""));
	UIKit::gotoXY(5, 10);
	std::cout << "Notre plan�te est en p�ril!" << std::endl;
	UIKit::gotoXY(5, 11);
	std::cout << "Une arm�e de martien a d�cid� d�envahir la terre.Vous �tes toutefois le h�ro de la situation " << std::endl;
	UIKit::gotoXY(5, 12);
	std::cout << "et la seule personne capable d�an�antir ces vilains �intragalactiques�." << std::endl;
	UIKit::gotoXY(20, 14);
	std::cout << "D�marer une partie." << std::endl;
	UIKit::gotoXY(20, 16);
	std::cout << "Changer le niveau de difficult� du jeu." << std::endl;
	UIKit::gotoXY(20, 18);
	std::cout << "Afficher le mode d�emploi" << std::endl;

	Sleep(5000);
}
