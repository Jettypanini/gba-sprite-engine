project(TDZShooter)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/level_one.h
		src/level_one.cpp
		src/gun.h
		src/gun.cpp
		src/bullets.h
		src/bullets.cpp
		src/stage1.h
		src/stage1.c
		src/sprites.h
		src/bullet.h
		src/bullet.c
		src/guy.h
		src/guy.c
		src/SpiderDance.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
