#pragma once

#include "Prerequistes.h"
#include "FileSerialization/Serializable.hpp"
#include "GameData/ObjectPropertyData.hpp"
#include <vector>

class SPE_API ObjectData : public Serializable, private std::vector<ObjectPropertyData>
{
public:
	ObjectData() = default;
	ObjectData(const ObjectData &) = delete;
	ObjectData & operator=(const ObjectData &) = delete;
	ObjectData(ObjectData &&) = default;
	ObjectData & operator=(ObjectData &&) = default;

	virtual json serialize() const override;
	virtual bool deserialize(const json & j) override;

	using std::vector<ObjectPropertyData>::push_back;
	using std::vector<ObjectPropertyData>::pop_back;
	using std::vector<ObjectPropertyData>::begin;
	using std::vector<ObjectPropertyData>::end;
	using std::vector<ObjectPropertyData>::front;
	using std::vector<ObjectPropertyData>::back;
	using std::vector<ObjectPropertyData>::insert;
	using std::vector<ObjectPropertyData>::erase;
	using std::vector<ObjectPropertyData>::emplace_back;
	using std::vector<ObjectPropertyData>::clear;
	using std::vector<ObjectPropertyData>::operator [];
	using std::vector<ObjectPropertyData>::size;
	using std::vector<ObjectPropertyData>::empty;
};