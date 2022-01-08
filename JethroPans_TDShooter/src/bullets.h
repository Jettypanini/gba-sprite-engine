#ifndef BULLETS_H
#define BULLETS_H

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/scene.h>

#include "sprites.h"
#include "bullet.h"

class Bullets {
private:
	std::unique_ptr<Sprite> bullet;
	
public:
	Bullets(std::unique_ptr<Sprite> sprite) : bullet(std::move(sprite)) {}
	
	Sprite* get_bullet();
};

#endif