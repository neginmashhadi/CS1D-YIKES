/*
 *  Fast Food Project
 *  Spring 2019
 *
 *  Oscar Lopez <olopez23@saddleback.edu>
 *  Jeff Adams <jadams62@saddleback.edu>
 *  Isaac Estrada <iestrada5@saddleback.edu>
 *  Caroline Ta <tta24@saddleback.edu>
 *  Negin Mashhadi <nmashhadi0@ivc.edu>
 *
 *  Descr: Fast Food Project for Spring 2019 CS1D
 *  Professor: Jerry Lebowitz
 *
 *  This program is an application in which a foodie
 *  at Saddleback College can plan various trips to
 *  fast food restaurants.
 *
 **/
/*
    File: Distance.h
    Class for calculating and displaying the distances
*/

#ifndef DISTANCE_H
#define DISTANCE_H

/**
@brief used to handle distance information of the restaurants
*/
class Distance
{
public:
    /** Default constructor
    */
    Distance();

    /** Alternative constructor - Gets the distance between 2 restaurants
    @param dMiles - miles between 2 restaurants
    @param currentID - ID of the current restaurant
    @param nextID - ID of the next restaurant
    */
    Distance(double dMiles, int currentID, int nextID);

    /** Set the miles between the 2 restaurants
    @param dMiles - miles between 2 restaurants to set
    */
    void SetMiles(double dMiles);

    /** Set the ID of the current restaurant
    @param - ID of the current restaurant to set
    */
    void SetCurrentRestaurantID(int currentID);

    /** Set the ID of the next restaurant
    @param - ID of the next restaurant to set
    */
    void SetNextID(int nextID);

    /** Get the miles between the 2 restaurants
    @return miles between the 2 restaurants
    */
    double GetMiles();

    /** Get the ID of the current restaurant
    @return ID of the current restaurant
    */
    int GetCurrentRestaurantID();

    /** Get the ID of the next restaurant
    @return ID of the next restaurant
    */
    int GetNextID();

private:
    double miles;               /**<Saves the miles between 2 restaurants*/
    int    currentRestaurantID; /**<Saves the ID of the current restaurant*/
    int    nextRestaurantID;    /**<Saves the ID of the next restaurant*/
};

#endif // DISTANCE_H
