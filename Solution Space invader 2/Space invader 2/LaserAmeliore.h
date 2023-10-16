#pragma once
#include "Laser.h"
class LaserAmeliore :public Laser
	
{
public:

	
	LaserAmeliore(Coord c, TypeLaser typeLaser);
	~LaserAmeliore();
	void deplacer()override;
	void detruire() override;
};

