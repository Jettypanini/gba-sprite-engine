 #include "failed.h"
 #include "starting_screen.h"
 
 std::vector<Background *> Failed::backgrounds() {
    return {};
}

std::vector<Sprite *> Failed::sprites() {
    return {};
}
 
 void Failed::load() {

	engine.get()->enableText();
    TextStream::instance().setText("You died!", 3, 1);
	TextStream::instance().setText("Failure is never the end", 5, 1);
	TextStream::instance().setText("Press start to return to the", 7, 1);
	TextStream::instance().setText("home screen", 8, 1);

    engine->getTimer()->start();
}
 
 void Failed::tick(u16 keys) {

    if(keys & KEY_START) {
        if(!engine->isTransitioning()) {
            engine->transitionIntoScene(new StartingScreen(engine), new FadeOutScene(2));
        }
    }
}
