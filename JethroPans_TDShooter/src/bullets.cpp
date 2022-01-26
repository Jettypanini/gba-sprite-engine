#include "bullets.h"

void Bullets::move_bullet() {
	if(dir == 0x0000) {
		pos_x += 4;
	} else if(dir == 0x8000) {
		pos_x -= 4;
	} else if(dir == 0x4000) {
		pos_y -= 4;
	} else if(dir == 0xc000) {
		pos_y += 4;
	}
	bullet.get()->moveTo(pos_x, pos_y);
}

short Bullets::get_x() {
	return pos_x;
}

short Bullets::get_y() {
	return pos_y;
}

void Bullets::shoot(short position_x, short position_y, int direction) {
	bullet = builder
			.withData(bulletTiles, sizeof(bulletTiles))
			.withSize(SIZE_8_8)
			.withLocation(position_x, position_y)
			.buildPtr();
	pos_x = position_x;
	pos_y = position_y;
	dir = direction;
	empty = 0;
}

bool Bullets::is_empty() {
	return empty;
}

void Bullets::set_empty() {
	empty = 1;
	bullet = builder
			.withData(bulletEmpty, sizeof(bulletEmpty))
			.withSize(SIZE_8_8)
			.withLocation(0, 0)
			.buildPtr();
}

Sprite* Bullets::get_bullet() {
	return bullet.get();
}
