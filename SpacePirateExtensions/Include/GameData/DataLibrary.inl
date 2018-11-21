#pragma once

#include "DataLibrary.hpp"
#include <cassert>

template <typename T>
std::unordered_map<std::string, T> DataLibrary<T>::m_library;

template <typename T>
void DataLibrary<T>::clear()
{
	m_library.clear();
}

template <typename T>
bool DataLibrary<T>::add(const std::string & name, T object, bool replace)
{
	if (replace || m_library.find(name) == m_library.end())
	{
		m_library[name] = object;
		return true;
	}
	return false;
}

template <typename T>
bool DataLibrary<T>::remove(const std::string & name)
{
	return m_library.erase(name) > 0;
}

template <typename T>
bool DataLibrary<T>::has(const std::string & name)
{
	return m_library.find(name) != m_library.end();
}

template <typename T>
const T & DataLibrary<T>::get(const std::string & name)
{
	const auto it = m_library.find(name);
	assert(it != m_library.end());
	
	return it->second;
}

template <typename T>
std::vector<std::string> DataLibrary<T>::entries()
{
	std::vector<std::string> names;
	for (const auto & e : m_library)
		names.push_back(e.first);
	return names;
}

template <typename T>
typename DataLibrary<T>::Iterator DataLibrary<T>::begin()
{
	return m_library.begin();
}

template <typename T>
typename DataLibrary<T>::Iterator DataLibrary<T>::end()
{
	return m_library.end();
}