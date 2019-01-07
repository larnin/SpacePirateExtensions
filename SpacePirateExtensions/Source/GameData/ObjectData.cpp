#include "GameData/ObjectData.hpp"

json ObjectData::serialize() const
{
	json jproperties;
	for (const auto & p : *this)
		jproperties.push_back(p.serialize());
	return { {"properties", jproperties} };
}

bool ObjectData::deserialize(const json & j)
{
	assert(j.is_object());
	if (!j.is_object())
		return false;

	const auto & jproperties = j["properties"];
	assert(jproperties.is_array());
	if (!jproperties.is_array())
		return false;

	clear();

	for (const auto & jp : jproperties)
	{
		ObjectPropertyData p;
		if (!p.deserialize(jp))
			return false;
		emplace_back(std::move(p));
	}

	return true;
}