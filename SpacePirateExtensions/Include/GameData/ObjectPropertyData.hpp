#pragma once

#include "Prerequistes.h"
#include "FileSerialization/Serializable.hpp"
#include "GameData/ObjectValues/ObjectValueBase.hpp"
#include <string>
#include <memory>

class SPE_API ObjectPropertyData : public Serializable
{
public:
	ObjectPropertyData() = default;
	ObjectPropertyData(const ObjectPropertyData &) = delete;
	ObjectPropertyData & operator=(const ObjectPropertyData &) = delete;
	ObjectPropertyData(ObjectPropertyData &&) noexcept = default;
	ObjectPropertyData & operator=(ObjectPropertyData &&) noexcept = default;

	virtual json serialize() const override;
	virtual bool deserialize(const json & j) override;

	std::string name;
	std::unique_ptr<ObjectValueBase> value;
};