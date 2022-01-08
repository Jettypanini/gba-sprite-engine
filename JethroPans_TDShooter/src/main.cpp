#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/palette/palette_manager.h>
#include <libgba-sprite-engine/allocator.h>

#include "level_one.h"

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    LevelOne* stage1 = new LevelOne(engine);
    engine->setScene(stage1);

    while (true) {
        engine->update();
        engine->delay(1000);
    }

    return 0;
} 