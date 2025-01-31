
## TDShooter using gba-sprite-engine

TDShooter is a top-down shooter game built for the GameBoy Advance by [Jethro Pans](https://github.com/Jettypanini) as a project for the course "Software design with C/C++". This project started form the [gba-sprite-engine](https://github.com/wgroeneveld/gba-sprite-engine) provided by the lecturer [Wouter Groeneveld](https://github.com/wgroeneveld). The code for this project can be observed in the file "JethroPans_TDShooter".

## Game description
In the game the player controls the character named Guy who has to pass a forest that is flooded with zombified machops. If the player gets too close to the zombified machops he dies. The zombified machops can be killed using the gun. The player possesses a normal glock and a shotgun. The glock shoots one bullet at a time, however can shoot continuously. The shotgun shoots five bullets at a time, however has to wait until the last bullets disappeared.

### Controls
```
- Arrow keys: player movement
- B: shoot
- Shoulder L: equip glock
- shoulder R: equip shotgun
```

### Music
The song heard in this game is "Spider dance" by Toby Fox from the RPG game Undertale.

### Characters
#### Guy
<img src="https://github.com/Jettypanini/gba-sprite-engine/blob/master/JethroPans_TDShooter/img/guy_64_64.png">

#### Zombified mashop
<img src="https://github.com/Jettypanini/gba-sprite-engine/blob/master/JethroPans_TDShooter/img/enemy_32.png">

### Screenshots
<img src="https://github.com/Jettypanini/gba-sprite-engine/blob/master/JethroPans_TDShooter/img/homescreen.PNG">
<img src="https://github.com/Jettypanini/gba-sprite-engine/blob/master/JethroPans_TDShooter/img/screenshot1.PNG">
<img src="https://github.com/Jettypanini/gba-sprite-engine/blob/master/JethroPans_TDShooter/img/screenshot.PNG">

## Domain model
When starting the game, the player can see the home screen. In this home screen the playable character can be seen shooting a bullet at the zombified machop, summarizing the game. After pressing the "Start" button the level starts. The background "stage1", the music "SpiderDance" and the sprites "figures" are being loaded. If the player shoots at a zombified mashop, the function shoot() reacts as the player is holding a glock or shotgun. Both are child classes of the abstract class gun. The bullets and enemies shown on the screen are vectors of the objects with the same name. Each object holds information involving the movement, position and whether it can be seen or not. If the player dies, the screen shows he failed. By pressing the "Start" button the player can return to the home screen. Same goes for the ending screen if the player completes the level.

<img src="https://github.com/Jettypanini/gba-sprite-engine/blob/master/JethroPans_TDShooter/img/domain_model.png">

## Authors
* *Wouter Groeneveld* - Lecturer - [GitHub](https://github.com/wgroeneveld)
* *Jethro Pans* - Student - [Github](https://github.com/Jettypanini)

## Acknowledgements
* high-level object-oriented Gameboy Advance sprite engine library: [gba-sprite-engine](https://github.com/wgroeneveld/gba-sprite-engine)
* GBA image transmogrifier: [Grit](https://www.coranac.com/man/grit/html/grit.htm)
* Sound to GBA file converter: [Audacity](https://www.audacityteam.org/download/)

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## References
* Machop sprite: [https://www.spriters-resource.com/game_boy_advance/pokemonfireredleafgreen/sheet/3711/](https://www.spriters-resource.com/game_boy_advance/pokemonfireredleafgreen/sheet/3711/)
* Materials used in the map: [https://www.spriters-resource.com/game_boy_advance/pokemonfireredleafgreen/sheet/3736/](https://www.spriters-resource.com/game_boy_advance/pokemonfireredleafgreen/sheet/3736/)
* Guy: [http://pixelartmaker.com/art/1b679450a241211](http://pixelartmaker.com/art/1b679450a241211)
* Bullet: [https://www.spriters-resource.com/game_boy_advance/gtadv/sheet/4612/](https://www.spriters-resource.com/game_boy_advance/gtadv/sheet/4612/)
