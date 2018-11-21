#pragma once

#include "Prerequistes.h"

#include "FileSerialization\Serializable.hpp"
#include "GameData\FrameData.hpp"

#include <vector>

class SPE_API AnimationData : public Serializable, private std::vector<FrameData>
{
public:
	virtual json serialize() const override;
	virtual bool deserialize(const json & j) override;

	using std::vector<FrameData>::push_back;
	using std::vector<FrameData>::pop_back;
	using std::vector<FrameData>::begin;
	using std::vector<FrameData>::end;
	using std::vector<FrameData>::front;
	using std::vector<FrameData>::back;
	using std::vector<FrameData>::insert;
	using std::vector<FrameData>::erase;
	using std::vector<FrameData>::emplace_back;
	using std::vector<FrameData>::clear;
	using std::vector<FrameData>::operator [];
	using std::vector<FrameData>::size;
	using std::vector<FrameData>::empty;

	std::string imageName;
	bool loop = false;
};