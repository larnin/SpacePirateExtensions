#pragma once

#include "Prerequistes.h"
#include "FileSerialization/Serializable.hpp"

#include <Nazara/Math/Vector2.hpp>
#include <Nazara/Math/Rect.hpp>

class SPE_API FrameData : public Serializable
{
public:
	FrameData() = default;
	FrameData(const json & j);
	virtual json serialize() const override;
	virtual bool deserialize(const json & j) override;

	Nz::Recti rect = { 0, 0, 0, 0 };
	Nz::Vector2f offset = { 0, 0 };
	float time = 0;

};