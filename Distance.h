#ifndef DISTANCE_H
#define DISTANCE_H


class Distance
{
public:
    Distance();

    Distance(float dMiles, int currentID, int nextID);

    void SetMiles(float dMiles);

    float GetMiles();

    void SetCurrentRestaurantID(int currentID);

    int GetCurrentRestaurantID();

    void SetNextID(int nextID);

    int GetNextID();

private:
    float  miles;
    int    currentRestaurantID;
    int    nextRestaurantID;
};

#endif // DISTANCE_H
