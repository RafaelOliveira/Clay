#include <string>
#include <map>
#include "state.h"

map<string, State> State::stateList;
State *State::active;

void State::AddState(State& state, string name, bool go)
{
	stateList.insert(make_pair(name, state));

	if (go)
	{
		active = &state;
		active->Init();
	}
}

void State::RemoveState(string name, bool destroy)
{
	map<string, State>::iterator it = stateList.find(name);

	if (destroy)
		it->second.Destroy();

	stateList.erase(it);
}

void State::SwitchState(string name)
{
	State state = stateList[name];

	state.Init();
	active = &state;
}

void State::Init() {}

void State::Update() {}

void State::Draw() {}

void State::Destroy() {}
