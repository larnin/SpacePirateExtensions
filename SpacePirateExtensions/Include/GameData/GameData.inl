#pragma once

#include "GameData.h"
#include "DataLibrary.h"
#include <filesystem>

namespace fs = std::experimental::filesystem;

template <typename T>
void GameData::initializeAsset(const std::string & directory, const std::string & extension)
{
	DataLibrary<T>::clear();

	initializeAssetSub(directory, "", extension);
}

template<typename T>
static void initializeAssetSub(const std::string & baseDirectory, const std::string & subDirectory, const std::string & extension)
{
	fs::path path = baseDirectory / subDirectory / "";
	unsigned int pathSize = path.string().size();
	for (auto & p : fs::directory_iterator(path))
	{
		if (p->is_directory())
		{
			std::string s = p->path.string();
			s.erase(0, pathSize);

			initializeAssetSub(baseDirectory, subDirectory + "/" + s);
		}
		else if (p->is_regular_file())
		{
			std::string s = p->path.string();
			s.erase(0, pathSize);
			if (!subDirectory.empty())
				s = subDirectory + "/" + s;

			Nz::ObjectRef<T> resource = T::New();
			if (!resource)
			{
				NazaraError("Failed to create resource");
				return;
			}

			if (!resource->LoadFromFile(s))
			{
				NazaraError("Failed to load resource from file: " + s);
				return;
			}

			NazaraDebug("Loaded resource from file " + s);

			DataLibrary<T>::add(s, resource);
		}
	}
}