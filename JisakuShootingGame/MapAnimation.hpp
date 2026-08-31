#pragma once
#include "Map.hpp"

struct AnimationImgs {
	Array<String> texture;
	int texCount = 0;
	double animationTime;
	void AddTexture(String addTexture) {

		texture << addTexture;
		++texCount;
	}
};

class MapAnimation : public Map {
public:
	void const Init(int x_, int y_, Array<String> img_, int texNum_, double animationTime_, bool isUsed_, int layer_);
	void draw(int drawLayerNumber_)override;
	void UpDate(double deltaTime_);
	bool GetIsSpawn();
private:
	struct TextureAnimationArray {
		int texNum;
		Array<s3d::Texture> texture;
		int animationNumber = 0;
		int animationCount = 0;
		double animationTimer = 0;
		double animationTime = 1;
		bool isSpawn = false;
	};
	TextureAnimationArray textureAnimationArray[10][18];
};
