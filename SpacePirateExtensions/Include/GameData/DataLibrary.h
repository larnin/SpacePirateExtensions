#pragma once

#include "Prerequistes.h"
#include <Nazara/Core/ObjectRef.hpp>
#include <unordered_map>
#include <string>
#include <vector>

template <typename T>
class DataLibrary
{
public:
	using Iterator = std::unordered_map<std::string, Nz::ObjectRef<T>>::iterator;

	DataLibrary() = delete;
	~DataLibrary() = delete;

	static void clear();

	static bool add(const std::string & name, Nz::ObjectRef<T> object, bool replace = false);
	static bool remove(const std::string & name);

	static bool has(const std::string & name);
	static Nz::ObjectRef<T> get(const std::string & name);
	static std::vector<std::string> entries();

	static Iterator begin();
	static Iterator end();

private:
	std::unordered_map<std::string, Nz::ObjectRef<T>> m_library;
};

#include "DataLibrary.inl"