#include <string>
#include <map>
#include "state.h"

std::map<std::string, State> State::stateList;
State *State::active;

void State::AddState(State &state, std::string name, bool go)
{
    stateList.insert(make_pair(name, state));

    if (go)
    {
        active = &state;
        active->Init();
    }
}

void State::RemoveState(std::string name, bool destroy)
{
    std::map<std::string, State>::iterator it = stateList.find(name);

    if (destroy)
        it->second.Destroy();

    stateList.erase(it);
}

void State::SwitchState(std::string name)
{
    State state = stateList[name];

    state.Init();
    active = &state;
}

void State::Init() {}

void State::Update() {}

void State::Render() {}

void State::Destroy() {}
