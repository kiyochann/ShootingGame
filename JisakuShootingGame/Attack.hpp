#pragma once
#include "Entity.hpp"

class Attack : public Entity {
public:
	void UpDate()override;
	void HitProcessing(int targertType_)override;
private:
	double speedX = 0, speedY = 0, speedZ = 0;
	double deltaTime;
};
