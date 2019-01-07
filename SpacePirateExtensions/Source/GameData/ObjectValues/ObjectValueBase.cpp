#include "GameData/ObjectValues/ObjectValueBase.hpp"
#include <cassert>

std::unique_ptr<ObjectValueBase> ObjectValueBase::createValue(ValueType type)
{
	switch (type)
	{
	case ValueType::Transform:
	case ValueType::Box2DCollider:
	case ValueType::CircleCollider:
	case ValueType::ConvexeCollider:
	case ValueType::Rigidbody:
	case ValueType::Animator:
	case ValueType::Animation:
	case ValueType::Object:
	case ValueType::Texture:
	case ValueType::Scene:
	case ValueType::SpriteRenderer:
	case ValueType::Script:
	case ValueType::Float:
	case ValueType::Int:
	case ValueType::Vector2f:
	case ValueType::Vector2i:
	case ValueType::Color:
	case ValueType::Text:
	case ValueType::Camera:
	case ValueType::TilemapCollider:
	case ValueType::TilemapRenderer:
		break;
	}

	assert(false);
	return {};
}

std::unique_ptr<ObjectValueBase> ObjectValueBase::loadValue(const json & j)
{
	auto type = static_cast<ValueType>(j["type"].get<int>());

	switch (type)
	{
	case ValueType::Transform:
	case ValueType::Box2DCollider:
	case ValueType::CircleCollider:
	case ValueType::ConvexeCollider:
	case ValueType::Rigidbody:
	case ValueType::Animator:
	case ValueType::Animation:
	case ValueType::Object:
	case ValueType::Texture:
	case ValueType::Scene:
	case ValueType::SpriteRenderer:
	case ValueType::Script:
	case ValueType::Float:
	case ValueType::Int:
	case ValueType::Vector2f:
	case ValueType::Vector2i:
	case ValueType::Color:
	case ValueType::Text:
	case ValueType::Camera:
	case ValueType::TilemapCollider:
	case ValueType::TilemapRenderer:
		break;
	}

	assert(false);
	return {};
}