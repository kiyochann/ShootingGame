#pragma once
#include "MapAnimation.hpp"


void const MapAnimation::Init(int x_, int y_, Array<String> img_, int texNum_, double animationTime_, bool isUsed_, int layer_) {
	//textureArray[y_][x_] = Texture{img_};
	textureAnimationArray[y_][x_].texNum = texNum_;

	for (int i = 0; i < texNum_; ++i) {
		textureAnimationArray[y_][x_].texture << Texture{ img_[i] };//配列を追加に変更
	}
	//if(isUsed_) Print << textureAnimationArray[y_][x_].texNum;

	textureAnimationArray[y_][x_].animationNumber = 0;
	textureAnimationArray[y_][x_].animationTime = animationTime_;
	isUsed[y_][x_] = isUsed_;
	layerNumber = layer_;
	//if(textureArray[y_][x_].width() > mapTileSize)mapTileSize = textureArray[y_][x_].width();
}

void MapAnimation::draw(int drawLayerNumber_) {
	if (layerNumber == drawLayerNumber_) {
		for (int y = 0; y < 10; ++y) {
			for (int x = 0; x < 18; ++x) {
				if (isUsed[y][x]) {
					textureAnimationArray[y][x].texture[textureAnimationArray[y][x].animationNumber].draw(x * mapTileSize, y * mapTileSize);
					//font(U"{}{}"_fmt(x,y)).draw(x * mapTileSize, y * mapTileSize,ColorF{0});
				}
			}
		}
	}
}

void MapAnimation::UpDate(double deltaTime_) {
	for (int y = 0; y < 10; ++y) {
		for (int x = 0; x < 18; ++x) {
			if (isUsed[y][x]) {
				textureAnimationArray[y][x].animationTimer += deltaTime_;

				if (textureAnimationArray[y][x].animationTimer > textureAnimationArray[y][x].animationTime) {
					textureAnimationArray[y][x].animationTimer -= textureAnimationArray[y][x].animationTime;

					++textureAnimationArray[y][x].animationCount;


					if (textureAnimationArray[y][x].animationCount < textureAnimationArray[y][x].texNum) textureAnimationArray[y][x].animationNumber = textureAnimationArray[y][x].animationCount;
					else textureAnimationArray[y][x].animationNumber = textureAnimationArray[y][x].texNum - 1 - (textureAnimationArray[y][x].animationCount - textureAnimationArray[y][x].texNum);
					//Print << (textureAnimationArray[y][x].animationNumber == textureAnimationArray[y][x].texNum - 1);
					if (textureAnimationArray[y][x].animationNumber == textureAnimationArray[y][x].texNum - 1) textureAnimationArray[y][x].isSpawn = true;

					if (textureAnimationArray[y][x].animationCount >= textureAnimationArray[y][x].texNum * 2) {
						textureAnimationArray[y][x].animationTimer = 0;
						textureAnimationArray[y][x].animationCount = 0;
						textureAnimationArray[y][x].animationNumber = 0;
					}

				}




			}
		}
	}

}

bool MapAnimation::GetIsSpawn() {
	for (int y = 0; y < 10; ++y) {
		for (int x = 0; x < 18; ++x) {
			if (isUsed[y][x]) {
				if (textureAnimationArray[y][x].isSpawn == true) {

					textureAnimationArray[y][x].isSpawn = false;

					return true;
				}
			}
		}
	}
}
