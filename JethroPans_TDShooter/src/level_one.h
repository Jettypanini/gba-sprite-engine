#ifndef LEVEL_ONE_H
#define LEVEL_ONE_H

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/background/background.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/gba/tonc_core.h>
#include "figures.h"
#include "stage1.h"
#include "SpiderDance.h"
#include "ending_screen.h"
#include "failed.h"

#include "bullets.h"
#include "enemies.h"
#include "glock.h"
#include "shotgun.h"

#define MAP_WIDTH GBA_SCREEN_WIDTH / 8
#define MAP_HEIGHT GBA_SCREEN_HEIGHT / 8
#define MAP_SIZE MAP_WIDTH * MAP_HEIGHT

class LevelOne : public Scene {
private:
    std::unique_ptr<Background> stage1;
	std::unique_ptr<AffineSprite> player;
	std::unique_ptr<Sprite> bulletSprite;
	std::unique_ptr<Sprite> enemy;
	std::vector<Enemies> enemies;
	std::vector<Bullets> bullets;
	Gun *gun = new Glock();
	
	SpriteBuilder<Sprite> builder;
	SpriteBuilder<AffineSprite> affineBuilder;

	short rotate_step = 128;
	short player_rot_step = 0;
	int player_rotate = 0x4000;
	short player_x = GBA_SCREEN_WIDTH/2 - 16;
	short player_y = GBA_SCREEN_HEIGHT - 32;
    int map_x = 0;
	int map_y = 0;
	bool ris_edge = 0;
	short i = 0;
public:
    LevelOne(std::shared_ptr<GBAEngine> engine) : Scene(engine), map_x(0), map_y(351) {}

	std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;
	
	short get_map_pos(short pos_x, short pos_y, short pos_map);
	bool check_collision(short next_pos_x, short next_pos_y, short next_pos_map);

    void load() override;
    void tick(u16 keys) override;
};

#endif