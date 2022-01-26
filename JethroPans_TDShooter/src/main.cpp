#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/palette/palette_manager.h>
#include <libgba-sprite-engine/allocator.h>

#include "starting_screen.h"

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    StartingScreen* start = new StartingScreen(engine);
    engine->setScene(start);

    while (true) {
        engine->update();
        engine->delay(1000);
    }

    return 0;
} 