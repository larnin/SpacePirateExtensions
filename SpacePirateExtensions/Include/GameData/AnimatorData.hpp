#pragma once

#include "Prerequistes.h"
#include "FileSerialization/Serializable.hpp"
#include <string>
#include <vector>

class SPE_API AnimatorStateData : public Serializable
{
public:
	virtual json serialize() const override;
	virtual bool deserialize(const json & j) override;

	std::string stateName;
	std::string animation;
	bool xFlipped = false;
	bool yFlipped = false;
};

class SPE_API AnimatorTransitionData : public Serializable
{
public:
	virtual json serialize() const override;
	virtual bool deserialize(const json & j) override;

	unsigned int previousState = 0;
	unsigned int nextState = 0;
	std::string condition;
};

class SPE_API AnimatorData : public Serializable
{
public:
	virtual json serialize() const override;
	virtual bool deserialize(const json & j) override;

	std::vector<AnimatorStateData> states;
	std::vector<AnimatorTransitionData> transitions;
	unsigned int startIndex = 0;
};