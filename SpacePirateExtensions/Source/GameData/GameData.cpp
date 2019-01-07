#include "GameData/GameData.hpp"
#include "GameData/AnimationData.hpp"
#include "GameData/AnimatorData.hpp"
#include "GameData/TilemapData.hpp"
#include "GameData/TextureData.hpp"

void GameData::initialize()
{
	initializeAllAssets();

}

void GameData::initializeAllAssets()
{
	initializeAsset<AnimationData>("Animation", "anim");
	initializeAsset<AnimatorData>("Animator", "ator");
	initializeAsset<TextureData>("Image", "png");
	//initializeAsset<>("Scene", "scene");
	initializeAsset<TilemapData>("Tilemap", "tmap");
	//initializeAsset<>("Object", "object");
}