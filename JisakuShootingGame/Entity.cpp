#pragma once
#include "Entity.hpp"


void Entity::Init(double x_, double y_, double z_, double size_, int hp_, int entityType_, EntityAnimationImgs img_[], int texNum_, double animationTime_, bool isUsed_, int direction_, double attackCoolTime_) {
	x = x_, y = y_, z = z_;
	size = size_;
	hp = hp_;
	isUsed = isUsed_;
	texNum = texNum_;
	animationTime = animationTime_;
	entityType = entityType_;
	direction = direction_;
	attackCoolTime = attackCoolTime_;
	for (int i = 0; i < texNum; ++i) {
		for (int j = 0; j < 4; ++j) {//四方向
			directionImgs[j].imgs << Texture{ img_[j].texture[i] };
		}
	}
	//Print << entityType;
}

void Entity::Draw() {
	if (isUsed) {
		if((int)(IFramesTimer * 10) % 2 < 1)directionImgs[direction].imgs[animationNumber].draw(x, z - y);
	}
}

double Entity::GetData(int mode_){
	switch (mode_)
	{
	case 0:
		return x;
		break;
	case 1:
		return y;
		break;
	case 2:
		return z;
		break;
	case 3:
		return size;
		break;
	case 4:
		return entityType;
		break;
	case 5:
		return hp;
		break;
	case 6:
		return direction;
		break;
	case 7:
		return attackFlag;
		break;
	}
}

bool Entity::GetIsUsed() {
	return isUsed;
}



bool Entity::CollisionCheck(Entity* entity_){

	double    targetX = entity_->GetData((int)modes::modeX);
	double    targetY = entity_->GetData((int)modes::modeY);
	double    targetZ = entity_->GetData((int)modes::modeZ);
	double targetSize = entity_->GetData((int)modes::modeSize);

	if (
		x <= targetX + targetSize && x + size >= targetX &&//x軸
		y <= targetY + targetSize && y + size >= targetY &&//y軸
		z <= targetZ + targetSize && z + size >= targetZ   //z軸
		)
	{
		//Print << (U"aaaaa");//debug
		return true;
	}

	return false;
}



/*
void Entity::aaaa() {
	Print << U"aaaa";
}
*/
