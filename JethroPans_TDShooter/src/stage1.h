
//{{BLOCK(stage1)

//======================================================================
//
//	stage1, 256x512@8, 
//	+ palette 256 entries, not compressed
//	+ 127 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x64 
//	Total size: 512 + 8128 + 4096 = 12736
//
//	Time-stamp: 2021-12-26, 11:54:29
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.17
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_STAGE1_H
#define GRIT_STAGE1_H

#define stage1TilesLen 8128
extern const unsigned int stage1Tiles[2032];

#define stage1MapLen 4096
extern const unsigned short stage1Map[2048];

#define stage1PalLen 512
extern const unsigned short stage1Pal[32];

#endif // GRIT_STAGE1_H

//}}BLOCK(stage1)
