#include "animator.h"
#include <cstdlib>

AnimData::AnimData(vector<Region*> regions, int fps, void (*OnComplete)()) : regions(regions),
    fps(fps), totalFrames((int)regions.size()), OnComplete(OnComplete)
{
}

Animator::Animator() : active(false), direction(1), loop(false), autoReverse(false),
    elapsed(0), nameAnim(""), index(0)
{
}

Animator::~Animator()
{
    animation = nullptr;
    animations.clear();
}

void Animator::Play(const string &name, bool loop, bool autoReverse, int index)
{
    map<string, AnimData>::iterator it;

    it = animations.find(name);

    if (it != animations.end())
    {
        animation = &it->second;
        nameAnim = name;
        this->loop = loop;
        this->autoReverse = autoReverse;

        Restart(index);

        region = animation->regions[index];
    }
    else
        throw std::out_of_range("(Animator.Play) animation " + name + " does not exist");
}

void Animator::Update()
{
    if (!active)
        return;

    elapsed += GetFrameTime() * abs(direction);

    // next frame
    if (elapsed >= (1.0f / animation->fps))
    {
        elapsed -= (1.0f / animation->fps);

        index += (direction >= 0) ? 1 : -1;

        if (index >= animation->totalFrames)
        {
            if (animation->OnComplete != nullptr)
                animation->OnComplete();

            if (!loop)
            {
                Stop();
                return;
            }

            if (!autoReverse)
                index = 0;
            else
            {
                index = animation->regions.size() - 1;
                Reverse();
            }
        }
        else if (index < 0)
        {
            if (animation->OnComplete != nullptr)
                animation->OnComplete();

            if (!loop)
            {
                Stop();
                return;
            }

            if (!autoReverse)
                index = animation->regions.size() - 1;
            else
            {
                index = 0;
                Reverse();
            }
        }
    }

    // update region
    region = animation->regions[index];
}

void Animator::Stop()
{
    active = false;
    index = 0;
    elapsed = 0;
    nameAnim = "";
}

void Animator::Restart(unsigned int index)
{
    active = true;
    this->index = index;
    elapsed = 0;
}

void Animator::Reverse()
{
    direction *= -1;
}

void Animator::FlipX(bool value)
{
    if (animation != nullptr)
    {
        if (value)
        {
            for (auto &region: animation->regions)
                region->FlipX();
        }
        else
        {
            for (auto &region: animation->regions)
                region->FlipX(false);
        }
    }
    else
        throw std::logic_error("(Animator.FlipX) region not loaded");
}

void Animator::FlipY(bool value)
{
    if (animation != nullptr)
    {
        if (value)
        {
            for (auto &region: animation->regions)
                region->rect.height = -abs(region->rect.height);
        }
        else
        {
            for (auto &region: animation->regions)
                region->rect.height = abs(region->rect.height);
        }
    }
    else
        throw std::logic_error("(Animator.FlipY) region not loaded");
}
