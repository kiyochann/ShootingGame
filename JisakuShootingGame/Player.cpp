#include "Player.hpp"

void Player::UpDate() {
	double deltaTime = Scene::DeltaTime();
	if (KeyA.pressed())speedX -= 3.5 * deltaTime;
	if (KeyD.pressed())speedX += 3.5 * deltaTime;
	if (KeySpace.down() && !isJump) {
		isJump = true;;
		speedY += 4;
	}
	if (KeyW.pressed())speedZ -= 3.5 * deltaTime;
	if (KeyS.pressed())speedZ += 3.5 * deltaTime;


	speedX *= 0.96, speedZ *= 0.96;
	speedY -= 9.8 * deltaTime;

	x += speedX, y += speedY, z += speedZ;

	//Print << speedY;

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



	//Print << IFramesTimer;
	if (isIFrames) {
		isIFrames = false;
		IFramesTimer = IFramesTime;
	}

	if (IFramesTimer > 0) {
		IFramesTimer -= deltaTime;
		if (IFramesTimer < 0)IFramesTimer = 0;
	}


	if (attackCoolTimer < 0) {
		if (KeyLShift.pressed()) {
			attackFlag = true;
			attackCoolTimer = attackCoolTime;
		}
		else {
			attackFlag = false;
		}
		
	}
	else {
		attackFlag = false;
		attackCoolTimer -= 1 * deltaTime;
	}
	//Print << attackCoolTimer;
	
}

void Player::HitProcessing(int targetType_) {
	//if(0 != targetType_)Print << targetType_;
	//Print << entityType;
	if (IFramesTimer <= 0) {
		switch (targetType_) {
		case (int)entityTypes::enemy:
			isIFrames = true;
			IFramesTimer = IFramesTime;
			hp -= 1;
			//Print << hp;
			break;
		case (int)entityTypes::enemyAttack:
			isIFrames = true;
			IFramesTimer = IFramesTime;
			hp -= 1;
			//Print << U"a";
			break;
		}
	}
}
