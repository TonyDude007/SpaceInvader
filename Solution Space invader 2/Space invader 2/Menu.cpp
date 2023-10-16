#include "Menu.h"
#include"UIKit.h"
#include"EnumChoixMenu.h"
#include"validations.h"
#include<string>
#include"Partie.h"

unsigned short Menu::loadingScreen = 0;

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::intro()
{
	UIKit::curseurVisible(false);
	UIKit::cadre(10, 8, 111, 25, 138);
	std::string ligne1 = "Notre planete est en peril!";
	std::string ligne2 = "Une armee de martien a decide d envahir la terre. Vous etes toutefois le hero de la situation ";
	std::string ligne3 = "et la seule personne capable d aneantir ces vilains <<intragalactiques>>.";
	system("cls");
	UIKit::color(141);
	UIKit::gotoXY(0, 2);
	Menu::afficherLittleTitle(50);
	UIKit::cadre(10, 8, 111, 25, 138);
	UIKit::color(143);
	unsigned short compilateurX = 15;
	for (int i = 0; i < 28; i++)
	{
		UIKit::gotoXY(compilateurX, 10);
		std::cout << ligne1[i];
		Sleep(10);
		compilateurX++;
	}
	compilateurX = 15;
	for (int i = 0; i < 93; i++)
	{
		UIKit::gotoXY(compilateurX, 12);
		std::cout << ligne2[i] << std::endl;
		Sleep(10);
		compilateurX++;
	}
	compilateurX = 15;
	for (int i = 0; i < 73; i++)
	{
		UIKit::gotoXY(compilateurX, 14);
		std::cout << ligne3[i];
		Sleep(10);
		compilateurX++;
	}
	Sleep(1500);
}

unsigned short Menu::choixMenu()
{
	//std::cin.ignore(512, '\n');
	Partie::music(2);
	system("cls");

	UIKit::gotoXY(0, 2);
	Menu::afficherLittleTitle(0);
	UIKit::cadre(10, 8, 111, 25, 138);
	UIKit::color(143);
	std::string ligne1 = "Notre planete est en peril!";
	std::string ligne2 = "Une armee de martien a decide d envahir la terre. Vous etes toutefois le hero de la situation ";
	std::string ligne3 = "et la seule personne capable d aneantir ces vilains <<intragalactiques>>.";

	UIKit::gotoXY(15, 10);
	std::cout << ligne1;
	UIKit::gotoXY(15, 12);
	std::cout << ligne2;
	UIKit::gotoXY(15, 14);
	std::cout << ligne3;


	UIKit::gotoXY(50, 17);
	std::cout << "Demarrer une partie";
	UIKit::gotoXY(27, 20);
	std::cout << "Niveau de difficulte";
	UIKit::gotoXY(70, 20);
	std::cout << "Afficher le mode d emploi";
	UIKit::gotoXY(56, 23);
	std::cout << "Quitter";
	UIKit::gotoXY(11, 26);
	UIKit::color(141);
	std::cout << "Press <<SHIFT>> apres votre selection";
	unsigned short resutatChoix = -1;


	do
	{
		UIKit::curseurVisible(false);
		if ((GetAsyncKeyState(VK_UP)))
		{
			UIKit::cadre(48, 16, 70, 18, 140);
			UIKit::cadre(54, 22, 64, 24, 0);
			UIKit::cadre(68, 19, 96, 21, 0);
			UIKit::cadre(25, 19, 48, 21, 0);
			resutatChoix = DEMARRER_PARTIE;
		}
		if ((GetAsyncKeyState(VK_DOWN)))
		{
			UIKit::cadre(48, 16, 70, 18, 0);
			UIKit::cadre(54, 22, 64, 24, 140);
			UIKit::cadre(68, 19, 96, 21, 0);
			UIKit::cadre(25, 19, 48, 21, 0);
			resutatChoix = QUITTER;
		}
		if ((GetAsyncKeyState(VK_RIGHT)))
		{
			UIKit::cadre(48, 16, 70, 18, 0);
			UIKit::cadre(54, 22, 64, 24, 0);
			UIKit::cadre(68, 19, 96, 21, 140);
			UIKit::cadre(25, 19, 48, 21, 0);
			resutatChoix = MODE_D_EMPLOI;
		}
		if ((GetAsyncKeyState(VK_LEFT)))
		{
			UIKit::cadre(48, 16, 70, 18, 0);
			UIKit::cadre(54, 22, 64, 24, 0);
			UIKit::cadre(68, 19, 96, 21, 0);
			UIKit::cadre(25, 19, 48, 21, 140);
			resutatChoix = CHANGER_NIVEAU ;
		}


	} while (!(GetAsyncKeyState(VK_SHIFT)));

	return resutatChoix;
}

void Menu::modeDEmploi()
{
	system("cls");

	UIKit::gotoXY(0, 2);
	Menu::afficherLittleTitle(0);
	UIKit::curseurVisible(false);

	UIKit::cadre(3, 7, 114, 31, 140);
	UIKit::color(143);

	UIKit::gotoXY(6, 9);
	std::cout << "*********************************************/ MODE D'EMPLOI /**********************************************" << std::endl;
	UIKit::gotoXY(6, 11);
	std::cout << "DEPLACEMENT ET TIR :" << std::endl;
	UIKit::gotoXY(8, 13);
	std::cout << "-Pour vous deplacer vous devez utiliser les fleches : DROITE, GAUCHE, HAUT, BAS." << std::endl;
	UIKit::gotoXY(8, 15);
	std::cout << "-Pour tirer vos missiles vous devez appuyer sur <<SPACE BAR>>." << std::endl;
	UIKit::gotoXY(6, 17);
	std::cout << "BUT DU JEU :" << std::endl;
	UIKit::gotoXY(8, 19);
	std::cout << "-Vous Devez tirer vos missiles sur les extraterrestres sans vous faire toucher par les missiles ennemis.";
	UIKit::gotoXY(8, 21);
	std::cout << "-Si vous vous faites toucher par un missile extraterrestre plus de 3 fois vous perdez la partie.";
	UIKit::gotoXY(8, 23);
	std::cout << "-Si le nombre d extraterrestre atteint 15, vous perdez la partie." << std::endl;
	UIKit::gotoXY(8, 25);
	std::cout << "-En revanche, si vous tuez les 15 extraterrestres vous changez de niveau." << std::endl;
	UIKit::gotoXY(12, 27);
	std::cout << "-Les extraterrestres <<&>> = 1000 points et les <<#>> = 1500 points" << std::endl;
	UIKit::gotoXY(8, 29);
	std::cout << " BONNE CHANCE !!!" << std::endl;
	UIKit::gotoXY(8, 32);
	std::cout << "Press <<ESCAPE>> Pour quitter." << std::endl;
	UIKit::gotoXY(8, 34);
	
	do
	{
	} while (!(GetAsyncKeyState(VK_ESCAPE)));
}

unsigned short Menu::niveauDifficulter()
{
	system("cls");
	const unsigned short CHOIX_MENU_MIN = 1;
	const unsigned short CHOIX_MENU_MAX = 2;
	unsigned short choixNiveau = 1;
	UIKit::gotoXY(0, 2);
	Menu::afficherLittleTitle(0);
	UIKit::cadre(16, 7, 101, 20, 140);
	UIKit::color(143);
	UIKit::curseurVisible(false);
	UIKit::gotoXY(19, 9);
	std::cout << "****************************/ NIVEAU DE DIFFICULTE /****************************" << std::endl;
	UIKit::cadre(49, 12, 65, 14, 141);
	UIKit::cadre(52, 16, 62, 18, 0);
	UIKit::color(143);
	UIKit::gotoXY(51, 13);
	std::cout << "INTERMEDIAIRE";
	UIKit::gotoXY(54, 17);
	std::cout << "AVANCER";
	UIKit::gotoXY(17, 19);
	std::cout << "PRESS <<SPACE>> Apres votre choix.";
	UIKit::gotoXY(0, 0);

	do
	{

		if (GetAsyncKeyState(VK_UP)) {

			UIKit::cadre(49, 12, 65, 14, 141);
			UIKit::cadre(52, 16, 62, 18, 0);
			UIKit::color(143);
			UIKit::gotoXY(0, 0);
			choixNiveau = 1;


		}
		if (GetAsyncKeyState(VK_DOWN)) {
			UIKit::cadre(49, 12, 65, 14, 0);
			UIKit::cadre(52, 16, 62, 18, 141);
			UIKit::color(143);
			UIKit::gotoXY(0, 0);
			choixNiveau = 2;

		}

	} while (!(GetAsyncKeyState(VK_SPACE)));
	return  choixNiveau;
}



void Menu::afficherTitle()
{
	UIKit::curseurVisible(false);
	Partie::music(1);
	//Sleep(1000);

	cout << endl;
	UIKit::color(142);
	cout << "                         |||||||||||  |||||||||||   |||||||||||   |||||||||||   |||||||||||" << endl; Sleep(50); UIKit::color(139);
	cout << "                         |||          |||     |||   |||     |||   |||     |||   |||        " << endl; Sleep(50); UIKit::color(140);
	cout << "                         |||          |||     |||   |||     |||   |||           |||        " << endl; Sleep(50); UIKit::color(141);
	cout << "                         |||||||||||  |||||||||||   |||||||||||   |||           |||||||||||" << endl; Sleep(50); UIKit::color(142);
	cout << "                                 |||  |||           |||     |||   |||           |||        " << endl; Sleep(50); UIKit::color(143);
	cout << "                                 |||  |||           |||     |||   |||     |||   |||        " << endl; Sleep(50); UIKit::color(139);
	cout << "                         |||||||||||  |||           |||     |||   |||||||||||   |||||||||||" << endl; Sleep(50); UIKit::color(140);
	cout << endl; Sleep(100);
	cout << "           |||||   ||||      |||   |||         |||   |||||||||||  |||||||||||     |||||||||||   ||||||||||" << endl; Sleep(50); UIKit::color(141);
	cout << "            |||    ||||||    |||    |||       |||    |||     |||  |||      |||    |||           |||     |||  " << endl; Sleep(50); UIKit::color(142);
	cout << "            |||    ||| |||   |||     |||     |||     |||     |||  |||       |||   |||           |||     |||  " << endl; Sleep(50); UIKit::color(143);
	cout << "            |||    |||  |||  |||      |||   |||      |||||||||||  |||       |||   |||||||||||   ||||||||||" << endl; Sleep(50); UIKit::color(139);
	cout << "            |||    |||   ||| |||       ||| |||       |||     |||  |||       |||   |||           |||   |||   " << endl; Sleep(50); UIKit::color(140);
	cout << "            |||    |||    ||||||        |||||        |||     |||  |||      |||    |||           |||    |||  " << endl; Sleep(50); UIKit::color(141);
	cout << "           |||||   |||      ||||         |||         |||     |||  |||||||||||     |||||||||||   |||     ||| " << endl; Sleep(50); UIKit::color(142);
	cout << endl; Sleep(100);
	cout << "			                             |||||||||||" << endl; Sleep(50); UIKit::color(143);
	cout << "			                                     |||" << endl; Sleep(50); UIKit::color(139);
	cout << "			                                     |||" << endl; Sleep(50); UIKit::color(140);
	cout << "			                             |||||||||||" << endl; Sleep(50); UIKit::color(141);
	cout << "			                             |||        " << endl; Sleep(50); UIKit::color(142);
	cout << "			                             |||        " << endl; Sleep(50); UIKit::color(143);
	cout << "			                             |||||||||||" << endl; Sleep(50); UIKit::color(139);

	UIKit::cadre(8, 25, 109, 27, 15);
	int cptX = 7;

	for (int i = 0; i < 50; i++)
	{
		cptX +=2;
		loadingScreen++;
		if (loadingScreen++)
		{
			UIKit::color(138);
			UIKit::gotoXY(cptX, 26);
			std::cout << "||";
		}

		UIKit::gotoXY(110, 26);
		std::cout << loadingScreen << "%";
		Sleep(70);
	}
}

void Menu::afficherLittleTitle(unsigned short sleepValeur)
{
	UIKit::color(141);
	cout << "                ####  ####  ####  ####  ####      #  #   #  #       #  ####  # #    ####  ## #       ####" << endl; Sleep(sleepValeur);
	cout << "                #     #  #  #  #  #     #         #  ##  #   #     #   #  #  #  #   #     #   #         #" << endl; Sleep(sleepValeur);
	cout << "                ####  ####  ####  #     ####      #  # # #    #   #    ####  #   #  ####  ## #       ####" << endl; Sleep(sleepValeur);
	cout << "                   #  #     #  #  #     #         #  #  ##     # #     #  #  #  #   #     #  #       #   " << endl; Sleep(sleepValeur);
	cout << "                ####  #     #  #  ####  ####      #  #   #      #      #  #  # #    ####  #   #      ####" << endl; Sleep(sleepValeur);
}

void Menu::afficherKillMeText(unsigned short choix)
{
	if (choix == 1)
	{
		Partie::allezXY(2, 22);
		cout << " ||  ||  ||  ||      ||" << endl; Partie::allezXY(2, 23);
		cout << " || ||   ||  ||      ||" << endl; Partie::allezXY(2, 24);
		cout << " ||||    ||  ||      ||" << endl; Partie::allezXY(2, 25);
		cout << " || ||   ||  ||      ||" << endl; Partie::allezXY(2, 26);
		cout << " ||  ||  ||  ||||||  ||||||" << endl;
	}

	if (choix == 2)
	{
		Partie::allezXY(2, 22);
		cout << "     ||     |||  ||||||" << endl; Partie::allezXY(2, 23);
		cout << "     ||||  ||||  ||    " << endl; Partie::allezXY(2, 24);
		cout << "     ||  ||  ||  ||||||" << endl; Partie::allezXY(2, 25);
		cout << "     ||      ||  ||    " << endl; Partie::allezXY(2, 26);
		cout << "     ||      ||  ||||||     " << endl;
	}
}

void Menu::afficherLogoExtraterrestre()
{
	UIKit::gotoXY(110, 26);

	cout << endl; Partie::allezXY(2, 29);
	cout << "     |||           |||" << endl; Partie::allezXY(2, 30);
	cout << "       |||       |||" << endl; Partie::allezXY(2, 31);
	cout << "     |||||||||||||||||" << endl; Partie::allezXY(2, 32);
	cout << "  |||||   |||||||   |||||" << endl; Partie::allezXY(2, 33);
	cout << "|||||||||||||||||||||||||||" << endl; Partie::allezXY(2, 34);
	cout << "|||||||||||||||||||||||||||" << endl; Partie::allezXY(2, 35);
	cout << "|||  |||||||||||||||||  |||" << endl; Partie::allezXY(2, 36);
	cout << "|||     |||     |||     |||" << endl; Partie::allezXY(2, 37);
	cout << "      |||||     |||||   " << endl; 

}


void Menu::afficherOuch()
{
	Partie::allezXY(45, 15);
	std::cout << " ||||||||||||  |||     |||  ||||||||  |||     |||" << std::endl; Partie::allezXY(45, 16);
	std::cout << " |||      |||  |||     |||  |||       |||     |||" << std::endl; Partie::allezXY(45, 17);
	std::cout << " |||      |||  |||     |||  |||       |||||||||||" << std::endl; Partie::allezXY(45, 18);
	std::cout << " |||      |||  |||     |||  |||       |||||||||||" << std::endl; Partie::allezXY(45, 19);
	std::cout << " |||      |||  |||     |||  |||       |||     |||" << std::endl; Partie::allezXY(45, 20);
	std::cout << " ||||||||||||  |||||||||||  ||||||||  |||     |||" << std::endl;


}


