#ifndef DISTANCE_H
#define DISTANCE_H


class Distance
{
public:
    Distance();

    Distance(double dMiles, int currentID, int nextID);

    void SetMiles(double dMiles);

    double GetMiles();

    void SetCurrentRestaurantID(int currentID);

    int GetCurrentRestaurantID();

    void SetNextID(int nextID);

    int GetNextID();

private:
    double miles;
    int    currentRestaurantID;
    int    nextRestaurantID;
};

#endif // DISTANCE_H
