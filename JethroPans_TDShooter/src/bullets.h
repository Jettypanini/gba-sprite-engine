#ifndef BULLETS_H
#define BULLETS_H

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/scene.h>

#include "figures.h"

class Bullets {
private:
	std::unique_ptr<Sprite> bullet;
	short pos_x;
	short pos_y;
	int dir;
	bool empty = 1;
	
	SpriteBuilder<Sprite> builder;
	
public:
	Bullets() : pos_x(0), pos_y(0), dir(0), empty(1) {}
	void move_bullet();
	short get_x();
	short get_y();
	void shoot(short position_x, short position_y, int direction);
	bool is_empty();
	void set_empty();
	
	Sprite* get_bullet();
};

#endif