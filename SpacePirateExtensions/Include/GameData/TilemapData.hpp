#pragma once

#include "Prerequistes.h"
#include "FileSerialization/Serializable.hpp"
#include "Matrix.hpp"
#include "GameData/TileInfo.hpp"
#include <string>

class SPE_API TilemapData : public Serializable
{
public:
	TilemapData();
	TilemapData(size_t width, size_t height, const TileInfos & defaultTile = {});

	virtual json serialize() const override;
	virtual bool deserialize(const json & j) override;

	size_t width() const { return tiles.width(); }
	size_t height() const { return tiles.height(); }

	std::string textureName;
	Matrix<TileInfos> tiles;
	unsigned int tileSize = 1;
	unsigned int tileDelta = 0;
};