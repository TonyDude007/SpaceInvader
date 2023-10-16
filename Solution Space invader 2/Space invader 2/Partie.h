#pragma once
/*
	Vous pouvez modifier cette classe.
*/
class Partie
{
	static unsigned short nbTourDeBoucle;
	static unsigned short  nbSecondes;
	static unsigned short nbMinutes;
	static unsigned short nbBoucleChangeColor;
	static unsigned short nbBoucleChangeTextKillMe;
	static unsigned short pointsAccumules;
	static unsigned short calcPosition;
	static unsigned short detectMenutoshow;
	static unsigned short sleepNiveau;


	static unsigned short banqueMunitionLazer;
	static unsigned short tabNbExtraterrestre;
	static unsigned short nbExtraterrestre;
	static unsigned short nbExtraterrestreTue;
	static unsigned short nbMartienTue;
	static unsigned short setNiveauTimer;
	static unsigned short setSleep;
	static unsigned short nbVie;
	static unsigned short tabNbMartien;
	static unsigned short nbMartien;
	static unsigned short tabNbLaserExtraterrestre;
	static unsigned short tabNbLaser;


	const unsigned short TAB_RESERVE_LAZER_JOUEUR_MIN = 1;
	const unsigned short TAB_RESERVE_LAZER_JOUEUR_MAX = 100;

	const unsigned short TAB_RESERVE_LAZER_EXTRATERRESTRE_MIN = 101;
	const unsigned short TAB_RESERVE_LAZER_EXTRATERRESTRE_MAX = 150;

	const unsigned short TAB_RESERVE_EXTRATERRESTRE_MIN = 151;
	const unsigned short TAB_RESERVE_EXTRATERRESTRE_MAX = 175;

	const unsigned short TAB_RESERVE_MARTIEN_MIN = 176;
	const unsigned short TAB_RESERVE_MARTIEN_MAX = 200;


public:
	Partie();
	void debuter();
	void gagner();
	void perdu();
	void pause();
	void timer();
	void swichButtonsGagnerPerdu();
	void remettreToutAValeurInitial();
	void setSleepNiveau(unsigned short sleepNiveau);
	unsigned short getBanqueMunitionLazer()const;
	void changeColors()const;
	static void music(short quelleMusique);
	static void allezXY(int x, int y);
};

