
#include "GameData\TileInfo.hpp"
#include "EnumIterator.h"
#include <cassert>

std::string tileColliderTypeToString(TileColliderType type)
{
	switch (type)
	{
	case TileColliderType::Empty:
		return "Empty";
	case TileColliderType::Full:
		return "Full";
	case TileColliderType::Triangle:
		return "Triangle";
	case TileColliderType::Half:
		return "Half";
	case TileColliderType::Quarter:
		return "Quarter";
	case TileColliderType::ThreeQuarter:
		return "Tree quarter";
	case TileColliderType::CentredHalf:
		return "Centred half";
	case TileColliderType::Cross:
		return "Cross";
	case TileColliderType::TShape:
		return "T shape";
	case TileColliderType::CentredCorner:
		return "Centred corner";
	default:
		break;
	}
	assert(false);
	return "";
}

TileColliderType tileColliderTypeFromString(const std::string & s)
{
	for (auto t : TileColliderType::Max)
		if (tileColliderTypeToString(t) == s)
			return t;
	assert(false);
	return TileColliderType::Max;
}

TileCollider::TileCollider(unsigned int value)
{
	fromInt(value);
}

unsigned int TileCollider::toInt() const
{
	int value(0);
	if (xFlipped)
		value += 1 << 0;
	if (yFlipped)
		value += 1 << 1;
	value += static_cast<unsigned int>(rotation) << 2;
	value += static_cast<unsigned int>(type) << 4;
	value += collisionLayer << 16;

	return value;
}

void TileCollider::fromInt(unsigned int value)
{
	xFlipped = (value & 0b1) > 0;
	yFlipped = (value & 0b10) > 0;
	rotation = static_cast<TileColliderRotation>((value & 0b1100) >> 2);
	type = static_cast<TileColliderType>((value & 0xFFF0) >> 4);
	collisionLayer = (value & 0xFFFF0000) >> 16;
}