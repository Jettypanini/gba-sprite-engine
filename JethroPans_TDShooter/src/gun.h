#ifndef GUN_H
#define GUN_H

#include "bullets.h"

class Gun {
public:
	Gun() {}
	virtual void shoot(std::vector<Bullets> &bul, short pos_x, short pos_y, int rotate) {}
};

#endif