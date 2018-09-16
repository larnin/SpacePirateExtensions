#pragma once

#include "DataLibrary.h"
template <typename T>
std::unordered_map<std::string, Nz::ObjectRef<T>> DataLibrary::m_library;

template <typename T>
void DataLibrary::clear()
{
	m_library.clear();
}

template <typename T>
bool DataLibrary::add(const std::string & name, Nz::ObjectRef<T> object, bool replace)
{
	if (replace || m_library.find(name) == m_library.end())
	{
		m_library[name] = object;
		return true;
	}
	return false;
}

template <typename T>
bool DataLibrary::remove(const std::string & name)
{
	return m_library.erase(name) > 0;
}

template <typename T>
bool DataLibrary::has(const std::string & name)
{
	return m_library.find(name) != m_library.end();
}

template <typename T>
Nz::ObjectRef<T> DataLibrary::get(const std::string & name)
{
	auto it = m_library.find(name);
	if (it != m_library.end())
		return it->second;
	return nullptr;
}

template <typename T>
std::vector<std::string> DataLibrary::entries()
{
	std::vector<std::string> names;
	for (const auto & e : m_library)
		names.push_back(e.first);
	return names;
}

template <typename T>
Iterator DataLibrary::begin()
{
	return m_library.begin();
}

template <typename T>
Iterator DataLibrary::end()
{
	return m_library.end();
}