 #include "shotgun.h"
 
 void Shotgun::shoot(std::vector<Bullets> &bul, short pos_x, short pos_y, int rotate) {
		short x = 0;
		short y = 0;
		if(rotate == 0x0000) {
			x = pos_x + 30;
			y = pos_y + 12;
		} else if(rotate == 0x8000) {
			x = pos_x -6;
			y = pos_y + 12;
		} else if(rotate == 0xc000) {
			x = pos_x + 12;
			y = pos_y + 30;
		} else if(rotate == 0x4000) {
			x = pos_x + 12;
			y = pos_y - 6;
		}
		empty_slots = 0;
		for(int i=0; i<bul.size(); i++) {
			if(bul.at(i).is_empty()) {
				empty_slots++;
			}
		}
		if(empty_slots == 5) {
			for(int i=0; i<bul.size(); i++) {
				if((rotate == 0x0000) | (rotate == 0x8000)) {
					bul.at(i).shoot(x, (y-16)+8*i, rotate);
				} else if((rotate == 0xc000) | (rotate == 0x4000)) {
					bul.at(i).shoot((x-16)+8*i, y, rotate);
				}
			}
		}
	}
	