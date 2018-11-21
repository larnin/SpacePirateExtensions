
#include "GameData\AnimationData.hpp"
#include <cassert>

json AnimationData::serialize() const
{
	json j;
	j["image"] = imageName;
	j["loop"] = loop;

	json frames;
	for (const auto & f : *this)
		frames.push_back(f.serialize());
	j["frames"] = frames;

	return j;
}

bool AnimationData::deserialize(const json & j)
{
	assert(j.is_object());
	if (!j.is_object())
		return false;

	clear();

	imageName = j["image"].get<std::string>();
	loop = j["loop"].get<bool>();

	const auto & frames = j["frames"];
	assert(frames.is_array());
	if (!frames.is_array())
		return false;
	for (const auto & jf : frames)
	{
		FrameData f;
		if (!f.deserialize(jf))
			return false;

		push_back(f);
	}

	return true;
}