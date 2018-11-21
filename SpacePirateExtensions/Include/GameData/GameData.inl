#pragma once

#include "GameData.hpp"
#include "DataLibrary.hpp"
#include "FileSerialization\FileOperations.hpp"
#include <Nazara\Core\Error.hpp>
#include <Nazara\Core\Log.hpp>
#include <filesystem>

namespace fs = std::experimental::filesystem;

template <typename T>
void GameData::initializeAsset(const std::string & directory, const std::string & extension)
{
	DataLibrary<T>::clear();

	initializeAssetSub<T>(directory, "", extension);
}

template<typename T>
void GameData::initializeAssetSub(const std::string & baseDirectory, const std::string & subDirectory, const std::string & extension)
{
	fs::path path = fs::path(baseDirectory) / subDirectory / "";
	auto pathSize = path.string().size();
	for (auto & p : fs::directory_iterator(path))
	{
		if (fs::is_directory(p))
		{
			std::string s = p.path().string();
			s.erase(0, pathSize);

			initializeAssetSub<T>(baseDirectory, subDirectory + "/" + s, extension);
		}
		else if (fs::is_regular_file(p))
		{
			std::string s = p.path().string();
			s.erase(0, pathSize);
			if (!subDirectory.empty())
				s = subDirectory + "/" + s + "." + extension;

			const auto & data = readFile(p.path().string());
			T t;
			if (!t.deserialize(data))
			{
				NazaraError("Failed to load resource from file: " + p.path().string());
				return;
			}

			NazaraDebug("Loaded resource from file " + s);

			DataLibrary<T>::add(s, t);
		}
	}
}