#pragma once
#include "MapTile.hpp"
//動かない画像
void const MapTile::Init(int x_, int y_,String img_ ,bool isUsed_, int layer_) {
	textureArray[y_][x_] = Texture{ img_ };
	isUsed[y_][x_] = isUsed_;
	layerNumber = layer_;
	//if(textureArray[y_][x_].width() > mapTileSize)mapTileSize = textureArray[y_][x_].width();
}

void MapTile::draw(int drawLayerNumber_) {
	if (layerNumber == drawLayerNumber_) {
		for (int y = 0; y < 10; ++y) {
			for (int x = 0; x < 18; ++x) {
				if (isUsed[y][x]) {
					textureArray[y][x].draw(x * mapTileSize, y * mapTileSize);
					//font(U"{}{}"_fmt(x,y)).draw(x * mapTileSize, y * mapTileSize,ColorF{0});
				}
			}
		}
	}
}
