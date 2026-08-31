#pragma once

struct Imgs {
	Array<Texture> imgs;
};

struct EntityAnimationImgs {
	Array<String> texture;

	void AddTexture(String addTexture) {
		texture << addTexture;
	}
};

enum class directions {
	left = 0,
	right = 1,
	back = 2,
	front = 3
};

enum class modes {
	modeX,
	modeY,
	modeZ,
	modeSize,
	modeEntityType,
	modeHp,
	modeDirection,
	modeAttackFlag
};

enum class entityTypes {
	player,
	playerAttack,
	enemy,
	enemyAttack
};

class Entity {
public:
	void Init(double x_, double y_, double z_, double size_, int hp_, int entityType_, EntityAnimationImgs img_[], int texNum_, double animationTime_, bool isUsed_, int direction_, double attackCoolTime_);
	virtual void UpDate() = 0;
	void Draw();
	double GetData(int mode_);
	bool GetIsUsed();
	bool CollisionCheck(Entity* entity_);
	virtual void HitProcessing(int targertType_) = 0;
	//void aaaa();
protected:
	Imgs directionImgs[4];//[方向].img[number]
	double x = 0, y = 0, z = 0;
	double size = 0;
	int hp = 0;
	int direction = 0;//0:左 1:右 2:上 3:下
	int texNum = 0;
	int entityType = 0;
	int animationNumber = 0;
	double animationTime = 0;
	double animationTimer = 0;
	bool isUsed = false;
	bool isIFrames = false;
	double IFramesTime = 1;
	double IFramesTimer = 0;

	//攻撃
	bool attackFlag = false;
	double attackCoolTime = 1;
	double attackCoolTimer = 0;
	
};
