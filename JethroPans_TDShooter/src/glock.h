#ifndef GLOCK_H
#define GLOCK_H

#include "gun.h"

class Glock : public Gun {
public:
	Glock() {}
	void shoot(std::vector<Bullets> &bul, short pos_x, short pos_y, int rotate);
};

#endif