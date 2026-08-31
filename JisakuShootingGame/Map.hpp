#pragma once

class Map {
public :
	//void Init();
	virtual void draw(int drawLayerNumber_) = 0;
protected:
	int layerNumber;
	bool isUsed[10][18];
	double mapTileSize = 32;
};
//int x_, int y_ , int layer_, String img_
