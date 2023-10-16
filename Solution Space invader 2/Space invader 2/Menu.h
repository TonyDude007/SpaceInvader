#pragma once
#include<iostream>
#include<string>
class Menu
{
	static unsigned short loadingScreen;

public:
	
	Menu();
	~Menu();
	static void intro();
	static unsigned short choixMenu();
	static void modeDEmploi();
	static unsigned short niveauDifficulter();
	static void afficherTitle();
	static void afficherLittleTitle(unsigned short sleepValeur);
	static void afficherKillMeText(unsigned short choix);
	static void afficherLogoExtraterrestre();
	static void afficherOuch();
};

