#ifndef STATE_H
#define STATE_H

#include <string>
#include <map>

using std::string;
using std::map;

class State
{
	private:

		static map<string, State> stateList;

	public:

		static State *active;

		static void AddState(State *state, string name, bool go = false);
		static void RemoveState(string name, bool destroy = false);
		static void SwitchState(string name);

		virtual void Init();
		virtual void Update();
		virtual void Draw();
		virtual void Destroy();
};

#endif
