#pragma once

#include "Prerequistes.h"
#include "FileSerialization/Serializable.hpp"
#include <string>

enum class ValueType
{
	Transform = -1,
	Box2DCollider,
	CircleCollider,
	ConvexeCollider,
	Rigidbody,
	Animator,
	Animation,
	Object,
	Texture,
	Scene,
	SpriteRenderer,
	Script,
	Float,
	Int,
	Vector2f,
	Vector2i,
	Color,
	Text,
	Camera,
	TilemapCollider,
	TilemapRenderer,
	Max = TilemapRenderer,
};

class SPE_API ObjectValueBase : public Serializable
{
public:
	static std::unique_ptr<ObjectValueBase> createValue(ValueType type);
	static std::unique_ptr<ObjectValueBase> loadValue(const json & j);
};