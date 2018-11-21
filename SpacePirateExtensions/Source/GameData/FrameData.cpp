
#include "GameData/FrameData.hpp"
#include <cassert>

FrameData::FrameData(const json & j)
{
	deserialize(j);
}

json FrameData::serialize() const
{
	return { {"left", rect.x}
		   , {"top", rect.y }
		   , {"width", rect.width}
		   , {"height", rect.height}
		   , {"x", offset.x}
		   , {"y", offset.y}
		   , {"time", time} };
}

bool FrameData::deserialize(const json & j)
{
	assert(j.is_object());
	if (!j.is_object())
		return false;

	rect.x = j["left"].get<int>();
	rect.y = j["top"].get<int>();
	rect.width = j["width"].get<int>();
	rect.height = j["height"].get<int>();
	offset.x = j["x"].get<float>();
	offset.y = j["y"].get<float>();
	time = j["time"].get<float>();

	return true;
}