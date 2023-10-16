#include "RunProgramme.h"
#include"Partie.h"
#include"Menu.h"
#include"UIKit.h"
#include"EnumChoixMenu.h"



RunProgramme::RunProgramme()
{
}


RunProgramme::~RunProgramme()
{
}

void RunProgramme::programmeRun()
{
	bool programmeRun = true;
	Partie* partie = new Partie();
	Menu::afficherTitle();
	Menu::intro();
	unsigned short  choixNiveau = 1;
	do
	{
		Partie sleepNiveau;
		
		UIKit::setDimensionFenetre(0, 0, 115, 40);

		unsigned short resutatChoix = Menu::choixMenu();
		sleepNiveau.setSleepNiveau(choixNiveau);
		switch (resutatChoix)
		{
		case ChoixMenu::DEMARRER_PARTIE:
			partie->debuter();
			break;
		case ChoixMenu::CHANGER_NIVEAU:
			choixNiveau = Menu::niveauDifficulter();
			break;
		case ChoixMenu::MODE_D_EMPLOI:
			Menu::modeDEmploi();
			break;
		case ChoixMenu::QUITTER:
			std::cout << "Au revoir !";
			programmeRun = false;
			break;
		default: std::cout << "Choix non valide " << std::endl;
			break;
		}

	} while (programmeRun);
	delete partie;


}
