#include "GameData/TilemapData.hpp"

TilemapData::TilemapData()
	: TilemapData(0, 0)
{

}

TilemapData::TilemapData(size_t width, size_t height, const TileInfos & defaultTile)
	: tiles(width, height, defaultTile)
{

}

json TilemapData::serialize() const
{
	json j;
	j["texture"] = textureName;
	j["sizeX"] = width();
	j["sizeY"] = height();
	j["tile"] = tileSize;
	j["delta"] = tileDelta;

	json jtiles;
	for (const auto & t : tiles)
		jtiles.push_back({ { "id", t.id }, { "c", t.collider.toInt() } });

	j["tiles"] = jtiles;
	return j;
}

bool TilemapData::deserialize(const json & j)
{
	assert(j.is_object());
	if (!j.is_object())
		return false;

	textureName = j["texture"].get<std::string>();
	tileSize = j["tile"].get<unsigned int>();
	tileDelta = j["delta"].get<unsigned int>();
	auto w = j["sizeX"].get<size_t>();
	auto h = j["sizeY"].get<size_t>();

	const auto jtiles = j["tiles"];
	assert(jtiles.is_array() && jtiles.size() == w * h);
	if (!jtiles.is_array() || jtiles.size() != w * h)
		return false;

	tiles.resize(w, h);
	for (unsigned int i(0); i < w; i++)
		for (unsigned int j(0); j < h; j++)
		{
			const auto & jt = jtiles[i + j * w];
			assert(jt.is_object());
			if (!jt.is_object())
				return false;
			TileInfos t;
			t.id = jt["id"].get<unsigned int>();
			t.collider.fromInt(jt["c"].get<unsigned int>());
		}

	return true;
}