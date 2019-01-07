#include "GameData/ObjectPropertyData.hpp"

json ObjectPropertyData::serialize() const
{
	return { {"name", name}, {"value", value->serialize()} };
}

bool ObjectPropertyData::deserialize(const json & j)
{
	assert(j.is_object());
	if (!j.is_object())
		return false;

	name = j["name"].get<std::string>();
	value = std::move(ObjectValueBase::loadValue(j["value"]));
	return !!value;
}