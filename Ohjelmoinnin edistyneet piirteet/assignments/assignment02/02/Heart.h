#ifndef HEART_H
#define HEART_H
#include <string>

class Heart
{
private:
    int beatsPerMinute;

public:
    Heart(int bpm) : beatsPerMinute(bpm) {}
    std::string toString() const
    {
        return "Heart(" + std::to_string(beatsPerMinute) + " bpm)";
    }
};
#endif