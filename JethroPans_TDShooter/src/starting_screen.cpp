 #include "starting_screen.h"
 #include "level_one.h"
 
 std::vector<Background *> StartingScreen::backgrounds() {
    return {};
}

std::vector<Sprite *> StartingScreen::sprites() {
	std::vector<Sprite*> sprites;
	sprites.push_back(guy.get());
	sprites.push_back(enemy.get());
	sprites.push_back(bullet.get());
	return sprites;
}
 
 void StartingScreen::load() {
	foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(start_figuresPal, sizeof(start_figuresPal)));
	
	guy = builder
            .withData(guy_64_64Tiles, sizeof(guy_64_64Tiles))
			.withSize(SIZE_64_64)
            .withLocation(0, 0)
            .buildPtr();
	enemy = builder
            .withData(enemy_32Tiles, sizeof(enemy_32Tiles))
			.withSize(SIZE_32_32)
            .withLocation(200, 16)
            .buildPtr();
	bullet = builder
            .withData(bullet_16Tiles, sizeof(bullet_16Tiles))
			.withSize(SIZE_16_16)
            .withLocation(bullet_pos, 28)
            .buildPtr();
	
	engine.get()->enableText();
    TextStream::instance().setText("PRESS START TO PLAY THE GAME!", 7, 1);

    engine->getTimer()->start();
}
 
 void StartingScreen::tick(u16 keys) {

    if(keys & KEY_START) {
        if(!engine->isTransitioning()) {
            engine->transitionIntoScene(new LevelOne(engine), new FadeOutScene(2));
        }
    }
	bullet_pos += 4;
	if(bullet_pos == 180) {
		bullet_pos = 64;
	}
	bullet.get()->moveTo(bullet_pos, 28);
	engine.get()->updateSpritesInScene();
}
