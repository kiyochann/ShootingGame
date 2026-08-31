#include "Entity.hpp"

class Enemy : public Entity {
public:
	void UpDate()override;
	void HitProcessing(int targertType_)override;
	void GetTarget(double targetX_, double targetZ_);
private:
	double speedX = 0, speedY = 0, speedZ = 0;
	bool isJump = false;

	//Entity* targetEntity;
	double targetX, targetZ;
	double targetPosX, targetPosZ;
	bool isMove = false;

	

	
};
