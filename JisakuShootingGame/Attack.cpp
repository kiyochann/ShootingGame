#pragma once
#include "Attack.hpp"

void Attack::UpDate() {
	deltaTime = Scene::DeltaTime();

	switch (direction) {
	case (int)directions::left:
		speedX = -30;
		break;
	case (int)directions::right:
		speedX = 30;
		break;
	case (int)directions::back:
		speedZ = -30;
		break;
	case (int)directions::front:
		speedZ = 30;
		break;
	}
	

	x += speedX * deltaTime, y += speedY * deltaTime, z += speedZ * deltaTime;

	if (x < -32 || x > 600) hp = 0;
	if (z < 145 || z > 280) hp = 0;


	if (abs(speedX) > abs(speedZ)) {
		if (speedX < -0.05) direction = (int)directions::left;
		if (speedX > 0.05) direction = (int)directions::right;
		animationTimer += deltaTime;
	}
	else {
		if (speedZ < -0.05) direction = (int)directions::back;
		if (speedZ > 0.05) direction = (int)directions::front;
		animationTimer += deltaTime;
	}

	if (abs(speedX) < 0.05 && abs(speedZ) < 0.05) {
		animationTimer = 0;
		animationNumber = 0;
	}

	if (animationTime < animationTimer) {
		animationTimer = 0;
		animationNumber = (animationNumber + 1) % texNum;
	}

}

void Attack::HitProcessing(int targetType_) {
	switch (entityType) {
	case (int)entityTypes::playerAttack:
		if (targetType_ == (int)entityTypes::enemy || targetType_ == (int)entityTypes::enemyAttack) {
			hp = 0;
		}
		break;
	case (int)entityTypes::enemyAttack:
		if (targetType_ == (int)entityTypes::player || targetType_ == (int)entityTypes::playerAttack) {
			hp = 0;
		}
		break;
	}
}
