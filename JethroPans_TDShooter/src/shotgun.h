#ifndef SHOTGUN_H
#define SHOTGUN_H

#include "gun.h"

class Shotgun : public Gun {
	private:
		short empty_slots = 0;
	public:
		Shotgun() {}
		void shoot(std::vector<Bullets> &bul, short pos_x, short pos_y, int rotate);
};

#endif