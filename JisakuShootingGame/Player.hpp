#pragma once
#include "Entity.hpp"

class Player : public Entity {
public:

	//void Init(double x_, double y_, double z_, EntityAnimationImgs img_[], int texNum_, double animationTime_, bool isUsed_);
	void UpDate()override;
	void HitProcessing(int targertType_)override;
	//void Draw();
	//double GetPos(int mode_);
private:
	struct Imgs {
		Texture imgs[4];
	};

	//Imgs imgs[4];//[方向].img[number]
	//double x, y, z;
	double speedX = 0, speedY = 0, speedZ = 0;
	bool isJump = false;

	

	//int direction;//0:左 1:右 2:上 3:下
	//int animationNumber;
	//double animationTime;
	//double animationTimer;
};

