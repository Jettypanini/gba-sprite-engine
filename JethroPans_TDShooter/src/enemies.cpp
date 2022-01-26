#include "enemies.h"
 
 void Enemies::move_enemy(short map_scroll) {
	 if((map_pos_y < map_scroll+176) & (map_pos_y > map_scroll-16)) {
		 screen_pos_y = map_pos_y-map_scroll;
		 if((on_screen == 0) & (lives > 0)) {
			 set_visibility(1);
		 }
	 } else {
		 if(on_screen == 1) {
			 set_visibility(0);
		 }
	 }
	 if(on_screen) {
		if(counter == 3) {
			if(direction == 3) {
				screen_pos_x += 1;
				counter = 0;
			} else if(direction == 2) {
				screen_pos_x-= 1;
				counter = 0;
			}
			if(direction == 0) {
				direction = 3;
				counter = 0;
			} else if(direction == 1) {
				direction = 2;
				counter = 0;
			}
			if((screen_pos_x == walking_route_x1) & (direction == 2)) {
				direction = 0;
				counter = -5;
			} else if((screen_pos_x == walking_route_x2) & (direction == 3)) {
				direction = 1;
				counter = -5;
			}
		}
		counter++;
		enemy->animateToFrame(direction);
		enemy.get()->moveTo(screen_pos_x, screen_pos_y);
	 }
	 
 }
 
 void Enemies::set_visibility(bool visible) {
	 if(visible) {
		 enemy =  builder
				.withData(enemyTiles, sizeof(enemyTiles))
				.withSize(SIZE_16_16)
				.withAnimated(4, 1)
				.withLocation(screen_pos_x, screen_pos_y)
				.buildPtr();
		enemy->stopAnimating();
		on_screen = 1;
	 } else {
		 enemy =  builder
				.withData(enemyEmpty, sizeof(enemyEmpty))
				.withSize(SIZE_16_16)
				.withLocation(0, 0)
				.buildPtr();
		 on_screen = 0;
	 }
 }
 
 bool Enemies::bullet_hit(short bullet_pos_x, short bullet_pos_y) {
	 if((bullet_pos_x > screen_pos_x-4) & (bullet_pos_x < screen_pos_x+12) & (bullet_pos_y > screen_pos_y-4) & (bullet_pos_y < screen_pos_y+12) & (lives > 0)) {
		 lives--;
		 if(lives == 0) {
			 set_visibility(0);
		 }
		 return 1;
	 } else {
		 return 0;
	 }
 }
 
 bool Enemies::get_on_screen() {
	 return on_screen;
 }
 
 short Enemies::get_x() {
	 return screen_pos_x;
 }
 
 short Enemies::get_y() {
	 return screen_pos_y;
 }
 
 Sprite* Enemies::get_enemy() {
	return enemy.get();
}
