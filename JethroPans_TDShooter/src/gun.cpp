 #include "gun.h"
 
 void Gun::shoot(short pos_x, short pos_y, short rotate) {
		bullets.push_back(Bullets(builder
            .withData(bulletTiles, sizeof(bulletTiles))
			.withSize(SIZE_8_8)
            .withLocation(pos_x, pos_y)
            .buildPtr()));
	}
 
 std::vector<Sprite*> Gun::get_bullets() {
 	for(auto& bullet : bullets) {
         bullet_sprites.push_back(bullet.get_bullet());
     }
 	return bullet_sprites;
 }