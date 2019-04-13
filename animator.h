#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <map>
#include <string>
#include <vector>
#include "raylib.h"
#include "region.h"

using std::map;
using std::string;
using std::vector;

class AnimData
{
    public:

        vector<Region*> regions;
        int fps;
        int totalFrames;
        void (*OnComplete)();

        AnimData(vector<Region*> regions, int fps, void (*OnComplete)());
};

class Animator
{
    public:

        Region *region;

        Animator();
        ~Animator();
        void AddAnimation(const string &name, vector<Region*> regions, int fps = 5, void (*OnComplete)() = nullptr);
        void RemoveAnimation(const string &name);
        void Play(const string &name, bool loop = true, bool autoReverse = false, int index = 0);
        void Update();
        void Pause();
        void Resume();
        bool IsRunning();
        bool IsReversed();
        void Stop();
        void Restart(unsigned int index = 0);
        void Reverse();
        void FlipX(bool value = true);
        void FlipY(bool value = true);
        void Draw(Vector2 &position, Color tint);

    private:

        bool active;
        int direction;
        bool loop;
        bool autoReverse;
        float elapsed;
        map<string, AnimData> animations;
        AnimData *animation;
        string nameAnim;
        int index;
};

inline void Animator::AddAnimation(const string &name, vector<Region*> regions, int fps, void (*OnComplete)())
{
    animations.insert(std::make_pair(name, AnimData(regions, fps, OnComplete)));
}

inline void Animator::RemoveAnimation(const string &name)
{
    animations.erase(name);
}

inline void Animator::Pause()
{
    active = false;
}

inline void Animator::Resume()
{
    active = true;
}

inline bool Animator::IsRunning()
{
    return active;
}

inline bool Animator::IsReversed()
{
    return (direction == -1);
}

inline void Animator::Draw(Vector2 &position, Color tint)
{
    region->Draw(position, tint);
}

#endif // ANIMATOR_H
