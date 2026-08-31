#include <Siv3D.hpp> // Siv3D v0.6.16
#include "Map.hpp"
#include "MapTile.hpp"
#include "MapAnimation.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Attack.hpp"

#define LAYER_MAX 5
#define ENTITY_MAX 100

void SpawnEntity(Entity* entity_[], double x_, double y_, double z_, double size_, int hp_, EntityAnimationImgs img_[], int texNum_, double animationTime_, bool isUsed_, int entityType_, int direction_) {
	for (int i = 0; i < ENTITY_MAX; ++i) {
		if (entity_[i] == nullptr) {
			//Print << U"aaa";  
			switch (entityType_) {
			case (int)entityTypes::player:
				entity_[i] = new Player();
				break;
			case (int)entityTypes::playerAttack:
				entity_[i] = new Attack();
				break;
			case (int)entityTypes::enemy:
				entity_[i] = new Enemy();
				break;
			case (int)entityTypes::enemyAttack:
				entity_[i] = new Attack;
				break;
			}
			//Print << i;
			//entity[1]->Init(32 * (4 + (Random() * 4)), 32 * 1, 32 * 7 + (Random() * 10), 16, 5, (int)entityTypes::enemy, playerAnimationImgs, 3, 0.2, true);
			entity_[i]->Init(x_, y_, z_, size_, hp_, entityType_, img_, texNum_, animationTime_, isUsed_,direction_, 0.5);

			break;
		}
	}
}

void Main()
{

	int mapTileDataArray[LAYER_MAX][10][18] = {//layer,y,x
	{//layer0
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{ 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
		{ 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	},
	{//layer1
		{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
		{ 3, 3, 4, 4, 4, 4, 3, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3},
		{ 3, 3, 4, 4, 4, 4, 3, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3},
		{ 3, 3, 4, 4, 4, 4, 3, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3},
		{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
	},
	{//layer2(animationLayer)
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
	},
	{//layer3
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
	},
	{//layer4
		{-1, 6,-1,-1,-1,-1, 6,-1,-1,-1,-1, 6,-1,-1,-1,-1, 6,-1},
		{-1, 7,-1,-1,-1,-1, 7,-1,-1,-1,-1, 7,-1,-1,-1,-1, 7,-1},
		{-1, 7,-1,-1,-1,-1, 7,-1,-1,-1,-1, 7,-1,-1,-1,-1, 7,-1},
		{-1, 7,-1,-1,-1,-1, 7,-1,-1,-1,-1, 7,-1,-1,-1,-1, 7,-1},
		{-1, 7,-1,-1,-1,-1, 7,-1,-1,-1,-1, 7,-1,-1,-1,-1, 7,-1},
		{-1, 7,-1,-1,-1,-1, 7,-1,-1,-1,-1, 7,-1,-1,-1,-1, 7,-1},
		{-1, 7,-1,-1,-1,-1, 7,-1,-1,-1,-1, 7,-1,-1,-1,-1, 7,-1},
		{-1, 7,-1,-1,-1,-1, 7,-1,-1,-1,-1, 7,-1,-1,-1,-1, 7,-1},
		{-1, 8,-1,-1,-1,-1, 8,-1,-1,-1,-1, 8,-1,-1,-1,-1, 8,-1},
		{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}
	}
	};

	const int imgMax = 9;
	String imgs[imgMax] = {U"example/Tile_stone_1.png" , U"example/Tile_stone_2.png", U"example/Tile_stone_3.png", U"example/Tile_StoneWall_1.png", U"example/Tile_StoneWall_2.png", U"example/Tile_gate_1.png", U"example/TIle_ pillar_1.png", U"example/Tile_ pillar_3.png", U"example/Tile_ pillar_2.png"};

	const int gateAnimationImgMax = 1;
	AnimationImgs animationImgsArray[gateAnimationImgMax];

	animationImgsArray[0].AddTexture(String(U"example/Tile_gate_1_1.png"));
	animationImgsArray[0].AddTexture(String(U"example/Tile_gate_1_2.png"));
	animationImgsArray[0].AddTexture(String(U"example/Tile_gate_1_3.png"));
	animationImgsArray[0].AddTexture(String(U"example/Tile_gate_1_4.png"));
	animationImgsArray[0].AddTexture(String(U"example/Tile_gate_1_5.png"));
	animationImgsArray[0].AddTexture(String(U"example/Tile_gate_1_6.png"));

	animationImgsArray[0].animationTime = 0.6;

	const int playerAnimaitonMax = 4;
	EntityAnimationImgs playerAnimationImgs[playerAnimaitonMax];

	String imgString0[3] = { U"example/player_nomal_left.png", U"example/player_left_0.png", U"example/player_left_1.png" };
	String imgString1[3] = { U"example/player_nomal_right.png", U"example/player_right_0.png", U"example/player_right_1.png" };
	String imgString2[3] = { U"example/player_nomal_back.png", U"example/player_back_0.png", U"example/player_back_1.png" };
	String imgString3[3] = { U"example/player_nomal.png", U"example/player_forward_0.png", U"example/player_forward_1.png" };

	for (int i = 0; i < 3; ++i) {
		playerAnimationImgs[0].AddTexture(imgString0[i]);
		playerAnimationImgs[1].AddTexture(imgString1[i]);
		playerAnimationImgs[2].AddTexture(imgString2[i]);
		playerAnimationImgs[3].AddTexture(imgString3[i]);
	}

	const int enemyAnimaitonMax = 4;
	EntityAnimationImgs enemyAnimationImgs[enemyAnimaitonMax];

	String imgString4[3] = { U"example/enemy0_left_0.png" , U"example/enemy0_left_1.png"   , U"example/enemy0_left_2.png" };
	String imgString5[3] = { U"example/enemy0_right_0.png", U"example/enemy0_right_1.png"  , U"example/enemy0_right_2.png" };
	String imgString6[3] = { U"example/enemy0_back_0.png" , U"example/enemy0_back_1.png"   , U"example/enemy0_back_2.png" };
	String imgString7[3] = { U"example/enemy0_front_0.png", U"example/enemy0_front_1.png"  , U"example/enemy0_front_2.png" };

	for (int i = 0; i < 3; ++i) {
		enemyAnimationImgs[0].AddTexture(imgString4[i]);
		enemyAnimationImgs[1].AddTexture(imgString5[i]);
		enemyAnimationImgs[2].AddTexture(imgString6[i]);
		enemyAnimationImgs[3].AddTexture(imgString7[i]);
	}

	const int playerAttackAnimaitonMax = 4;
	EntityAnimationImgs playerAttackAnimationImgs[playerAttackAnimaitonMax];

	String imgString8 [3] = { U"example/playerAttack_0.png" , U"example/playerAttack_1.png"   , U"example/playerAttack_2.png" };
	
	for (int i = 0; i < 3; ++i) {
		playerAttackAnimationImgs[0].AddTexture(imgString8[i]);
		playerAttackAnimationImgs[1].AddTexture(imgString8[i]);
		playerAttackAnimationImgs[2].AddTexture(imgString8[i]);
		playerAttackAnimationImgs[3].AddTexture(imgString8[i]);
	}

	const int enemyAttackAnimaitonMax = 4;
	EntityAnimationImgs enemyAttackAnimationImgs[enemyAttackAnimaitonMax];

	String imgString9 [3] = { U"example/enemyAttack_0.png" , U"example/enemyAttack_1.png"   , U"example/enemyAttack_2.png" };
	
	for (int i = 0; i < 3; ++i) {
		enemyAttackAnimationImgs[0].AddTexture(imgString9[i]);
		enemyAttackAnimationImgs[1].AddTexture(imgString9[i]);
		enemyAttackAnimationImgs[2].AddTexture(imgString9[i]);
		enemyAttackAnimationImgs[3].AddTexture(imgString9[i]);
	}

	Texture shadow = Texture{ U"example/shadow.png" };

	bool isGameEnd = false;
	bool isGameStart = false;

	const Font font{ FontMethod::MSDF, 20, Typeface::Bold };

	double timer = 0;
	int killCount = 0;
	int playerHp = 0;

	bool checked = false;

	Array<String> emptyArray;

	Window::Resize(32*18, 32*10);

	Scene::SetBackground(ColorF{ 0, 0, 0 });


	
	Map* map[LAYER_MAX] = { nullptr };
	for (int l = 0; l < LAYER_MAX; ++l) {
		map[l] = new MapTile();
		if (l == 2) map[l] = new MapAnimation();
	}
	
	
	Entity* entity[ENTITY_MAX] = { nullptr };
	
	for (int i = 0; i < ENTITY_MAX - 1; ++i) {
		if(i == 0)entity[i] = new Player();
		//else entity[i] = new Enemy();
	}
	
	for (int i = 0; i < ENTITY_MAX; ++i) {
		if (entity[i] != nullptr) {
			if (i == 0) entity[i]->Init(32 * 3, 32 * 10, 32 * 6.3, 16, 10, (int)entityTypes::player, playerAnimationImgs, 3, 0.2, true, (int)directions::right, 0.4);
			//else entity[i]->Init(32 * (4 + (Random() * 4)), 32 * 1, 32 * 7 + (Random() * 10), 16, 5, (int)entityTypes::enemy, playerAnimationImgs, 3, 0.2, true);
			
		}
	}
	
	
	
	
	

	for (int l = 0; l < LAYER_MAX; ++l) {
		for(int y = 0; y < 10; ++y){
			for (int x = 0; x < 18; ++x) {
				MapTile* t = dynamic_cast<MapTile*>(map[l]);
				MapAnimation* a = dynamic_cast<MapAnimation*>(map[l]);
				if (t) {
					if (mapTileDataArray[l][y][x] != -1) {
						//Print << mapTileDataArray[l][y][x];
						t->Init(x, y, imgs[mapTileDataArray[l][y][x]], true, l);
					}
					else {
						t->Init(x, y, U"", false, l);
					}
				}
				else if (a) {
					if (mapTileDataArray[l][y][x] != -1) {
						a->Init(x, y, animationImgsArray[mapTileDataArray[l][y][x]].texture, animationImgsArray[mapTileDataArray[l][y][x]].texCount, animationImgsArray[mapTileDataArray[l][y][x]].animationTime, true, l);
					}
					else {
						a->Init(x, y, emptyArray , 0 , 0 , false, l);
					}
				}
			}
		}
	}
	
	

	
	
	
	
	while (System::Update())
	{
		
		if (!isGameEnd && isGameStart) {

			timer += Scene::DeltaTime();


			if (Key1.down()) {

				//SpawnEntity(entity, 100, 1, 200, 10, 1, playerAnimationImgs, 3, 0.2, true, (int)entityTypes::playerAttack, (int)directions::right);
			}

			for (int l = 0; l < LAYER_MAX; ++l) {
				MapAnimation* a = dynamic_cast<MapAnimation*>(map[l]);
				if (a) {
					a->UpDate(Scene::DeltaTime());
					if (a->GetIsSpawn() == true)SpawnEntity(entity, 435, 0, 100, 16, 2, enemyAnimationImgs, 3, 0.5, true, (int)entityTypes::enemy, (int)directions::front);;
				}
			}


			for (int i = 0; i < ENTITY_MAX; ++i) {
				for (int j = 0; j < ENTITY_MAX; ++j) {
					if (entity[i] != nullptr && entity[j] != nullptr) {
						if (entity[i]->CollisionCheck(entity[j])) {
							//if (i != j)Print << entity[i]->GetData((int)modes::entityType);



							entity[i]->HitProcessing((int)entity[j]->GetData((int)modes::modeEntityType));
							entity[j]->HitProcessing((int)entity[i]->GetData((int)modes::modeEntityType));
						}
					}
				}
			}
			//Print << U"aaa";

			for (int i = 0; i < ENTITY_MAX; ++i) {
				if (entity[i] != nullptr) {
					entity[i]->UpDate();

					Player* p = dynamic_cast<Player*>(entity[i]);
					if (p) {
						playerHp = p->GetData((int)modes::modeHp);
					}

					if (entity[i]->GetData((int)modes::modeAttackFlag)) {

						switch ((int)entity[i]->GetData((int)modes::modeEntityType)) {
						case (int)entityTypes::player:
							SpawnEntity(entity, (int)entity[i]->GetData((int)modes::modeX), (int)entity[i]->GetData((int)modes::modeY) + 32 * Random() * 0.5, (int)entity[i]->GetData((int)modes::modeZ), 16, 1, playerAttackAnimationImgs, 3, 0.2, true, (int)entityTypes::playerAttack, (int)entity[i]->GetData((int)modes::modeDirection));
							break;

						case (int)entityTypes::enemy:
							SpawnEntity(entity, (int)entity[i]->GetData((int)modes::modeX), (int)entity[i]->GetData((int)modes::modeY) + 32 * Random() * 0.5, (int)entity[i]->GetData((int)modes::modeZ), 16, 1, enemyAttackAnimationImgs, 3, 0.2, true, (int)entityTypes::enemyAttack, (int)entity[i]->GetData((int)modes::modeDirection));
							break;
						}

					}



					if (entity[i]->GetData((int)modes::modeHp) <= 0) {
						if (entity[i]->GetData((int)modes::modeEntityType) == (int)entityTypes::player) isGameEnd = true;
						if (entity[i]->GetData((int)modes::modeEntityType) == (int)entityTypes::enemy) killCount += 1;
						delete(entity[i]);
						entity[i] = nullptr;
					}
				}
			}



			for (int i = 0; i < ENTITY_MAX; ++i) {
				for (int j = 0; j < ENTITY_MAX; j++) {
					if (entity[i] != nullptr && entity[j] != nullptr) {

						if (!entity[i]->GetIsUsed() && !entity[j]->GetIsUsed())continue;

						if (entity[i]->GetData((int)modes::modeZ) <= entity[j]->GetData((int)modes::modeZ)) {
							Entity* tmp = entity[i];
							entity[i] = entity[j];
							entity[j] = tmp;
						}

						Enemy* e = dynamic_cast<Enemy*>(entity[i]);
						Player* p = dynamic_cast<Player*>(entity[j]);
						if (e && p) {
							e->GetTarget(entity[j]->GetData((int)modes::modeX), entity[j]->GetData((int)modes::modeZ));
						}
					}
				}
			}

		}

		for (int l = 0; l < LAYER_MAX; ++l) {
			map[l]->draw(l);
			if (l == 3) {
				for (int i = 0; i < ENTITY_MAX; ++i) {
					

					if (entity[i] != nullptr) {
						shadow.draw(entity[i]->GetData((int)modes::modeX), entity[i]->GetData((int)modes::modeZ));
						entity[i]->Draw();
					}

				}
			}
			if (l == 2) {
				font(U"Shift\nWASD\nSpace").draw(97, 40);
				font(U"time:{:.2f}"_fmt(timer)).draw(240, 50);
				font(U"  kill:{}"_fmt(killCount)).draw(240, 70);
				font(U"   hp:{}"_fmt(playerHp)).draw(240, 90);
				
			}
		}
		if (isGameEnd && SimpleGUI::Button(U"復活", Vec2{225, 130}, 120, (checked == false)))
		{
			isGameEnd = false;
			
			SpawnEntity(entity, 32 * 3, 32 * 10, 32 * 6.3, 16, 10, playerAnimationImgs, 3, 0.5, true, (int)entityTypes::player, (int)directions::front);;
		}
		if (!isGameStart && SimpleGUI::Button(U"GameStart", Vec2{ 225, 130 }, 120, (checked == false))) {
			isGameStart = true;
		}
	}	
}
