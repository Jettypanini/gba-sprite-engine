#ifndef GUN_H
#define GUN_H

#include "bullets.h"

class Gun {
public:
	std::vector<Bullets> bullets;
	std::vector<Sprite*> bullet_sprites;
	SpriteBuilder<Sprite> builder;

	void shoot(short pos_x, short pos_y, short rotate);
	std::vector<Sprite*> get_bullets();
};

#endif