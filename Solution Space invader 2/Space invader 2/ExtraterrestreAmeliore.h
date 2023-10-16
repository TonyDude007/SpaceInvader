#pragma once
#include "Extraterrestre.h"
class ExtraterrestreAmeliore :
	public Extraterrestre
{unsigned short valeurPoints;
public:
	ExtraterrestreAmeliore(Coord coord, char apparence, unsigned short valeurPoints);
	~ExtraterrestreAmeliore();
	void afficher() override;
	void effacer() override;
	unsigned short getValeurPoints() const;
	char apparence;
};

