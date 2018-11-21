#pragma once

#include "Prerequistes.h"
#include <string>

enum class TileColliderType : unsigned int
{
	Empty,
	Full,
	Triangle,
	Half,
	Quarter,
	ThreeQuarter,
	CentredHalf,
	Cross,
	TShape,
	CentredCorner,
	Max = CentredCorner
};

std::string tileColliderTypeToString(TileColliderType type);
TileColliderType tileColliderTypeFromString(const std::string & s);

enum class TileColliderRotation : unsigned int
{
	R_0,
	R_90,
	R180,
	R270
};

/// int value
/// [0] xFlipped
/// [1] yFlipped
/// [2-3] rotation
/// [4-15] colliderType
/// [16-32] collisionLayer

struct TileCollider
{
	TileCollider(unsigned int value = 0);
	unsigned int toInt() const;
	void fromInt(unsigned int value);

	TileColliderType type;
	TileColliderRotation rotation;
	bool xFlipped;
	bool yFlipped;
	unsigned int collisionLayer;
};


struct SPE_API TileInfos
{
	unsigned int id = 0;
	TileCollider collider;
};
