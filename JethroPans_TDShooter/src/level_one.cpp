
#include "level_one.h"

#define ROTATION_DIFF (128 * 6)

std::vector<Sprite *> LevelOne::sprites() {
    std::vector<Sprite*> sprites;
	for(auto& bullet : bullets) {
        sprites.push_back(bullet.get());
    }
    sprites.push_back(player.get());
	return sprites;
}

std::vector<Background *> LevelOne::backgrounds() {
    return {
        stage1.get()
    };
}

void LevelOne::load() {
	foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(spritesPal, sizeof(spritesPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(stage1Pal, sizeof(stage1Pal)));
	
	player = affineBuilder
            .withData(guyTiles, sizeof(guyTiles))
			.withSize(SIZE_32_32)
            .withLocation(player_x, player_y)
            .buildPtr();	
	
	spriteBuilder = std::unique_ptr<SpriteBuilder<Sprite>>(new SpriteBuilder<Sprite>);
	bulletSprite = spriteBuilder->withData(bulletTiles, sizeof(bulletTiles))
            .withSize(SIZE_8_8)
            .buildPtr();
			
	create_bullet();

    stage1 = std::unique_ptr<Background>(new Background(1, stage1Tiles, sizeof(stage1Tiles), stage1Map, sizeof(stage1Map), 0, 1, 2));
    stage1.get()->useMapScreenBlock(16);
	
	engine->enqueueMusic(SpiderDance, SpiderDance_bytes);
}

//get_map_pos() returns the index of the stage1Map array that indicates the tile the player is standing on.
short LevelOne::get_map_pos(short pos_x, short pos_y, short pos_map) {
	return ((pos_map - pos_map%8)/8)*32 + ((pos_y - pos_y%8)/8)*32 + (pos_x+1-pos_x%8)/8;
}

//Given the parameters of the next position, check_collision() returns if the next step is an obstacle
bool LevelOne::check_collision(short next_pos_x, short next_pos_y, short next_pos_map) {
	if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] >= 0x0001 & stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] <= 0x0004) {
		return 1;
	} else if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] >= 0x0009 & stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] <= 0x002b) {
		return 1;
	} else if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] == 0x0034 || stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] == 0x0039 || stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] == 0x003f) {
		return 1;
	} else if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] >= 0x0040 & stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] <= 0x0041) {
		return 1;
	} else if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] == 0x0047) {
		return 1;
	} else if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] >= 0x0051 & stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] <= 0x0055) {
		return 1;
	} else if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] == 0x0059) {
		return 1;
	} else if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] == 0x007c) {
		return 1;
	} else if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] >= 0x040f & stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] <= 0x0411) {
		return 1;
	} else if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] >= 0x0421 & stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] <= 0x0422) {
		return 1;
	} else if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] == 0x0440) {
		return 1;
	} else if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] >= 0x0072 & stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] <= 0x0076) {
		return 1;
	} else if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] == 0x1025) {
		return 1;
	} else if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] == 0x1425) {
		return 1;
	} else if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] >= 0x1044 & stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] <= 0x1046) {
		return 1;
	} else if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] >= 0x1056 & stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] <= 0x1058) {
		return 1;
	} else if(stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] >= 0x1066 & stage1Map[get_map_pos(next_pos_x, next_pos_y, next_pos_map)] <= 0x1071) {
		return 1;
	} else {
		return 0;
	}
}

void LevelOne::create_bullet() {
	bullets.push_back( spriteBuilder->withLocation(player_x+16, player_y+16)
		.buildWithDataOf(*bulletSprite.get()) );
}

void LevelOne::tick(u16 keys) {
	if(keys & KEY_B) {
		bullets.push_back( spriteBuilder->withLocation(player_x+16, player_y+16)
		.buildWithDataOf(*bulletSprite.get()) );
	}
	
	if(keys & KEY_LEFT) {
		if(player_x >= 1) {
			if(!check_collision(player_x+8, player_y+16, map_y)) {
				player_x -= 1;
			}
		}
		player_rotate = 0x8000;
    } else if(keys & KEY_RIGHT) {
		if(player_x <= GBA_SCREEN_WIDTH - 16) {
			if(!check_collision(player_x+24, player_y+16, map_y)) {
				player_x += 1;
			}
		}
		player_rotate = 0x0000;
		create_bullet();
    } else if(keys & KEY_UP) {
		if(!check_collision(player_x+16, player_y+8, map_y)) {
			if(map_y > 0) {
				if(map_y == 351 & player_y > (GBA_SCREEN_HEIGHT/2 - 16)) {
				player_y -= 1;
				} else if(map_y == 1 & player_y > -8) {
					player_y -= 1;
				} else {
					map_y -= 1;
				}
			}
		}
		player_rotate = 0x4000;
    } else if(keys & KEY_DOWN) {	
		if(!check_collision(player_x+16, player_y+24, map_y)) {
			if(map_y < 352) {
				if(map_y == 1 & player_y < (GBA_SCREEN_HEIGHT/2 - 16)) {
					player_y += 1;
				} else if(map_y == 351 & player_y < (GBA_SCREEN_HEIGHT - 24)) {
					player_y += 1;
				} else {
					map_y += 1;
				}
			}
		}
		player_rotate = 0xc000;
    }
	player->rotate(player_rotate);
	player.get()->moveTo(player_x, player_y);
    stage1.get()->scroll(map_x, map_y);
	for(auto& bullet : bullets) {
        bullet.get()->moveTo(player_x+16, player_y+16);
    }
}
