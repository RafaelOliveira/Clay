#ifndef STATE_H
#define STATE_H

#include <string>
#include <map>

class State
{
    private:

        static std::map<std::string, State> stateList;

    public:

        static State *active;

        static void AddState(State &state, std::string name, bool go = false);
        static void RemoveState(std::string name, bool destroy = false);
        static void SwitchState(std::string name);

        virtual void Init();
        virtual void Update();
        virtual void Draw();
        virtual void Destroy();
};

#endif
