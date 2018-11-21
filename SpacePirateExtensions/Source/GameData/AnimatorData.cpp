#include "GameData\AnimatorData.hpp"
#include <cassert>

json AnimatorStateData::serialize() const
{
	return { {"name", stateName}
		  , {"animation", animation}
		  , {"xFlipped", xFlipped}
		  , {"yFlipped", yFlipped} };
}

bool AnimatorStateData::deserialize(const json & j)
{
	assert(j.is_object());
	if (!j.is_object())
		return false;

	stateName = j["name"].get<std::string>();
	animation = j["animation"].get<std::string>();
	xFlipped = j["xFlipped"].get<bool>();
	yFlipped = j["yFlipped"].get<bool>();

	return true;
}

json AnimatorTransitionData::serialize() const
{
	return { {"previous", previousState}
		  , {"next", nextState}
		  , {"condition", condition} };
}

bool AnimatorTransitionData::deserialize(const json & j)
{
	assert(j.is_object());
	if (!j.is_object())
		return false;

	previousState = j["previous"].get<unsigned int>();
	nextState = j["next"].get<unsigned int>();
	condition = j["condition"].get<std::string>();

	return true;
}

json AnimatorData::serialize() const
{
	json j;
	j["start"] = startIndex;

	json jstates;
	for (const auto & s : states)
		jstates.push_back(s.serialize());
	j["states"] = jstates;
	json jtransitions;
	for (const auto & t : transitions)
		jtransitions.push_back(t.serialize());
	j["transitions"] = jtransitions;
	return j;
}

bool AnimatorData::deserialize(const json & j)
{
	assert(j.is_object());
	if (!j.is_object())
		return false;

	states.clear();
	transitions.clear();

	startIndex = j["start"].get<unsigned int>();
	const auto & jstates = j["states"];
	const auto & jtransitions = j["transitions"];
	assert(jstates.is_array() && jtransitions.is_array());
	if (!jstates.is_array() || !jtransitions.is_array())
		return false;
	for (const auto & js : jstates)
	{
		AnimatorStateData s;
		if (!s.deserialize(js))
			return false;
		states.push_back(s);
	}
	for (const auto & jt : jtransitions)
	{
		AnimatorTransitionData t;
		if (!t.deserialize(jt))
			return false;
		transitions.push_back(t);
	}

	return startIndex < states.size();
}