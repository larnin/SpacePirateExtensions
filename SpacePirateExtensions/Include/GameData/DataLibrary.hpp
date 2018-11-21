#pragma once

#include "Prerequistes.h"
#include <unordered_map>
#include <string>
#include <vector>

template <typename T>
class DataLibrary
{
public:
	using Iterator = typename std::unordered_map<std::string, T>::iterator;

	DataLibrary() = delete;
	~DataLibrary() = delete;

	static void clear();

	static bool add(const std::string & name, T object, bool replace = false);
	static bool remove(const std::string & name);

	static bool has(const std::string & name);
	static const T & get(const std::string & name);
	static std::vector<std::string> entries();

	static Iterator begin();
	static Iterator end();

private:
	static std::unordered_map<std::string, T> m_library;
};

#include "DataLibrary.inl"