#pragma once

#include "Prerequistes.h"

#include <functional>
#include <string>

class SPE_API GameData
{
public:
	static void initialize();

private:
	static void initializeAllAssets();

	template <typename T>
	static void initializeAsset(const std::string & directory, const std::string & extension);
	template<typename T>
	static void initializeAssetSub(const std::string & baseDirectory, const std::string & subDirectory, const std::string & extension);
	template<typename T>
	static void loadAsset(const std::string & filename, const std::string & name);
};

#include "GameData.inl"