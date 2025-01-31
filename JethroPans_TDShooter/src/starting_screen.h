#ifndef STARTING_SCREEN_H
#define STARTING_SCREEN_H

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/background/background.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/gba/tonc_core.h>
#include <libgba-sprite-engine/gba_engine.h>

#include "start_figures.h"

#define MAP_WIDTH GBA_SCREEN_WIDTH / 8
#define MAP_HEIGHT GBA_SCREEN_HEIGHT / 8
#define MAP_SIZE MAP_WIDTH * MAP_HEIGHT

class StartingScreen : public Scene {
private:
public:
    StartingScreen(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

	std::unique_ptr<Sprite> guy;
	std::unique_ptr<Sprite> enemy;
	std::unique_ptr<Sprite> bullet;
	SpriteBuilder<Sprite> builder;
	
	short bullet_pos = 56;

	std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 keys) override;
};

#endif