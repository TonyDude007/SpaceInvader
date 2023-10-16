#include"validations.h"
#include<iostream>

unsigned short validerUnsignedShort()
{
	int valeur;
	std::cin >> valeur;
	while (std::cin.fail() || std::cin.peek() != '\n' || valeur < 0 || valeur > USHRT_MAX) {
		std::cin.clear();
		std::cin.ignore(512, '\n');
		std::cout << "Valeur numérique valide entre " << 0 << " et " << USHRT_MAX << " seulement : ";
		std::cin >> valeur;
	}
	std::cin.ignore(512, '\n');

	return (unsigned short)valeur;
}

double validerDouble()
{
	double valeur;
	std::cin >> valeur;
	while (std::cin.fail() || std::cin.peek() != '\n' || valeur < DBL_MIN || valeur > DBL_MAX) {
		std::cin.clear();
		std::cin.ignore(512, '\n');
		std::cout << "Valeur numérique valide entre " << DBL_MIN << " et " << USHRT_MAX << " seulement : ";
		std::cin >> valeur;
	}
	std::cin.ignore(512, '\n');
	return valeur;
}

char validerChaineDeCaracteres(char tab[], const int TAILLE)
{
	std::cin.getline(tab, TAILLE);
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(512, '\n');
		std::cout << "Saisir un message (max de " << TAILLE << " caractères) : " << std::endl;
		std::cin.getline(tab, TAILLE);
	}
	return 0;
}
unsigned short validerUnsignedShortEntre(const unsigned short MIN, const unsigned short MAX)
{
	unsigned short valeur = validerUnsignedShort();
	while (valeur < MIN || valeur > MAX) {
		std::cout << "Valeur entre " << MIN << " et " << MAX << " seulement : ";
		valeur = validerUnsignedShort();
	}
	return valeur;
}


