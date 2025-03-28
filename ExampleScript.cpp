#include "eventhandler.hpp"

/*

This is a script where there's some kind of Voting Event that happens at time = 100. So it initalizes 100 people (who all vote at the same time for some reason?) using i to
give them unique ID's and then waits until the EventHandler returns true for event ID = 0. Not a realistic script but hey it's an example.

*/

/*=== Event defining ===*/

class Vote : public Event
{
protected:
    std::function<int(int*)> func;
    int* time;
public:
    Vote(std::function<int(int*)> func, int* time, int id)
    {
        this->func = func;
        this->time = time;
        this->id = id;
    }

    bool check() override
    {
        return func(time);
    }

};

int voted(int* time) {
    if (*time > 100) return 1;
    else return 0;
}

int main()
{
    int time = 0;

    std::vector<std::shared_ptr<Event>> evVector;
    
    for (int i = 0; i < 100; i++) {
        evVector.emplace_back(std::make_shared<Vote>(voted, &time, i));
    }
    
    EventHandler evHandle(evVector);

    while (evHandle.checkEvent(0) != 1) {
        time++;
    }

    std::cout << "At time " << time << " they voted!!!!\n";


}
