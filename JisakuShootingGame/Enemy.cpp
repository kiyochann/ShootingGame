#include "Enemy.hpp"

void Enemy::UpDate() {

	double deltaTime = Scene::DeltaTime();



	//自動
	if (!attackFlag && isMove) {
		//Print << U"aaa";
		if (x > targetPosX) speedX -= 3.5 * deltaTime;
		if (x < targetPosX) speedX += 3.5 * deltaTime;
		if (false && !isJump) {
			isJump = true;
			speedY += 4;
		}
		if (z > targetPosZ) speedZ -= 3.5 * deltaTime;
		if (z < targetPosZ) speedZ += 3.5 * deltaTime;

		if (0.5 > abs(x - targetPosX) && 0.5 > abs(z - targetPosZ) && !attackFlag && isMove) {
			attackFlag = true;
			isMove = false;
		}
	}
	else if (attackFlag && !isMove) {
		if (abs(x - targetX) < abs(z - targetZ)) {
			if (x > targetX)direction = (int)directions::left;
			else direction = (int)directions::right;
		}
		else {
			if (z > targetZ)direction = (int)directions::back;
			else direction = (int)directions::front;
		}
		isMove = true;
	}
	else {
		targetPosX = 32 * 0.5 + 32 * 16 * Random();
		targetPosZ = 32 * 4.8 + 32 * 3.8 * Random();
		attackFlag = false;
		isMove = true;
	}
	
	//Print << attackFlag << isMove;





	

	speedX *= 0.96, speedZ *= 0.96;
	speedY -= 9.8 * deltaTime;

	x += speedX, y += speedY, z += speedZ;

	//Print << speedY;//debug
	if (!attackFlag) {

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
	}
	if (abs(speedX) < 0.05 && abs(speedZ) < 0.05) {
		animationTimer = 0;
		animationNumber = 0;
	}

	if (animationTime < animationTimer) {
		animationTimer = 0;
		animationNumber = (animationNumber + 1) % texNum;
	}

	//Print << animationNumber;//debug

	if (x < 0) x = 0;
	if (x > 544) x = 544;

	if (y < 0 && speedY < 0) {
		isJump = false;
		speedY = 0;
		y = 0;
	}
	if (y > 1000) y = 1000;

	if (z < 145) z = 145;
	if (z > 280) z = 280;



	if (isIFrames) {
		isIFrames = false;
		IFramesTimer = IFramesTime;
	}

	if (IFramesTimer > 0) {
		IFramesTimer -= deltaTime;
		if (IFramesTimer < 0)IFramesTimer = 0;
	}

}

void Enemy::HitProcessing(int targetType_) {
	//Print << U"a";
	if (IFramesTimer <= 0) {
		switch (targetType_) {
		case (int)entityTypes::player:
			isIFrames = true;
			IFramesTimer = IFramesTime;
			hp -= 1;
			//Print << U"a";
			break;
		case (int)entityTypes::playerAttack:
			isIFrames = true;
			IFramesTimer = IFramesTime;
			hp -= 1;
			//Print << U"a";
			break;
		}
	}
}

void Enemy::GetTarget(double targetX_, double targetZ_) {
	targetX = targetX_, targetZ = targetZ_;
}
