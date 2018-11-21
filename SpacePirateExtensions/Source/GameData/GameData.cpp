#include "GameData/GameData.hpp"
#include "GameData/AnimationData.hpp"
#include "GameData/AnimatorData.hpp"
#include "GameData/TilemapData.hpp"

void GameData::initialize()
{
	initializeAllAssets();

}

void GameData::initializeAllAssets()
{
	initializeAsset<AnimationData>("Animation", "anim");
	initializeAsset<AnimatorData>("Animator", "ator");
	//initializeAsset<>("Image", "png");
	//initializeAsset<>("Scene", "scene");
	initializeAsset<TilemapData>("Tilemap", "tmap");
	//initializeAsset<>("Object", "object");
}