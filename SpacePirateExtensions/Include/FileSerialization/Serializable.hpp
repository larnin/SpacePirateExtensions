#pragma once

#include "Prerequistes.h"
#include "OtherLibs/Json.hpp"

#include <string>

using json = nlohmann::json;

class SPE_API Serializable
{
public:
	virtual ~Serializable() = default;

	virtual json serialize() const = 0;
	virtual bool deserialize(const json & j) = 0;
};