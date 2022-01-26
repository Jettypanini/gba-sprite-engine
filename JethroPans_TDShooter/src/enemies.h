#ifndef ENEMIES_H
#define ENEMIES_H

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/scene.h>

#include "figures.h"

class Enemies {
private:
	std::unique_ptr<Sprite> enemy;
	short map_pos_x;
	short map_pos_y;
	short walking_route_x1;
	short walking_route_x2;
	short screen_pos_x;
	short screen_pos_y = 0;
	short lives = 3;
	short direction = 0;
	bool on_screen = 0;
	short counter = 0;
	
	SpriteBuilder<Sprite> builder;
	
public:
	Enemies(short map_pos_x, short map_pos_y) : map_pos_x(map_pos_x), map_pos_y(map_pos_y), screen_pos_x(map_pos_x), walking_route_x1(map_pos_x), walking_route_x2(map_pos_x+32), on_screen(0) {set_visibility(0);};
	void move_enemy(short map_scroll);
	void set_visibility(bool visible);
	bool bullet_hit(short bullet_pos_x, short bullet_pos_y);
	
	bool get_on_screen();
	short get_x();
	short get_y();
	
	Sprite* get_enemy();
};

#endif