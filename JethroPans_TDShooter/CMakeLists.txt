project(TDZShooter)

add_executable(${PROJECT_NAME}.elf
        	src/main.cpp
        	src/level_one.h
		src/level_one.cpp
		src/gun.h
		src/glock.h
		src/glock.cpp
		src/shotgun.h
		src/shotgun.cpp
		src/bullets.h
		src/bullets.cpp
		src/enemies.h
		src/enemies.cpp
		src/stage1.h
		src/stage1.c
		src/starting_screen.cpp
		src/starting_screen.h
		src/ending_screen.cpp
		src/ending_screen.h
		src/failed.cpp
		src/failed.h
		src/figures.h
		src/start_figures.h
		src/SpiderDance.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
