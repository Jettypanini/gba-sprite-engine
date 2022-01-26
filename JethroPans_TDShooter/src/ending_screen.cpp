 #include "ending_screen.h"
 #include "starting_screen.h"
 
 std::vector<Background *> EndingScreen::backgrounds() {
    return {};
}

std::vector<Sprite *> EndingScreen::sprites() {
    return {};
}
 
 void EndingScreen::load() {

	engine.get()->enableText();
    TextStream::instance().setText("Congratulations!", 3, 1);
	TextStream::instance().setText("You finished the first level!", 5, 1);
	TextStream::instance().setText("Press start to return to the", 7, 1);
	TextStream::instance().setText("home screen", 8, 1);

    engine->getTimer()->start();
}
 
 void EndingScreen::tick(u16 keys) {

    if(keys & KEY_START) {
        if(!engine->isTransitioning()) {
            engine->transitionIntoScene(new StartingScreen(engine), new FadeOutScene(2));
        }
    }
}
