#pragma once
#include "Map.hpp"

class MapTile : public Map {
public :
	void const Init(int x_, int y_, String img_, bool isUsed_ , int layer_);
	void  draw(int drawLayerNumber_)override;
	const Font font{ FontMethod::MSDF, 15 };
private:
	Texture textureArray[10][18];
};
