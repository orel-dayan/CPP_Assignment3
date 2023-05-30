#include "doctest.h"

#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"

using namespace ariel;



TEST_CASE("Charcters tests")
{
    Cowboy tom("Tom", Point(1, 2));
    YoungNinja doni("Doni", Point(3, 4));
    TrainedNinja leo("Leo", Point(5, 6));
    OldNinja rich("Rich", Point(7, 8));

    CHECK_EQ(tom.getName(), "Tom");
    CHECK_EQ(tom.getHitPoints(), 110);

    CHECK_EQ(doni.getName(), "Doni");
    CHECK_EQ(doni.getHitPoints(), 100);

    CHECK_EQ(leo.getName(), "Leo");
    CHECK_EQ(leo.getHitPoints(), 120);

    CHECK_EQ(rich.getName(), "Rich");
    CHECK_EQ(rich.getHitPoints(), 150);

    CHECK_EQ(tom.getLocation().getX(), 1);
    CHECK_EQ(tom.getLocation().getY(), 2);

    CHECK_EQ(doni.getLocation().getX(), 3);
    CHECK_EQ(doni.getLocation().getY(), 4);

    CHECK_EQ(leo.getLocation().getX(), 5);
    CHECK_EQ(leo.getLocation().getY(), 6);

    CHECK_EQ(rich.getLocation().getX(), 7);
    CHECK_EQ(rich.getLocation().getY(), 8);

    CHECK_EQ(tom.isAlive(), true);
    CHECK_EQ(doni.isAlive(), true);
    CHECK_EQ(leo.isAlive(), true);
    CHECK_EQ(rich.isAlive(), true);

    CHECK_NOTHROW(doni.move(&leo));
    CHECK_NOTHROW(leo.move(&doni));
    CHECK_NOTHROW(rich.move(&tom));
}
TEST_CASE("Point tests")
{
    Point point1(1, 2);
    Point point2(3, 4);
    Point point3(5, 6);
    CHECK_EQ(point1.getX(), 1);
    CHECK_EQ(point1.getY(), 2);
    CHECK_EQ(point2.getX(), 3);
    CHECK_EQ(point2.getY(), 4);
    CHECK_EQ(point3.getX(), 5);
    CHECK_EQ(point3.getY(), 6);
    CHECK_EQ(point1.distance(point2), point2.distance(point1));
    CHECK_EQ(point1.distance(point2), 2.8284271247461903);
    CHECK_EQ(point1.distance(point3), 5.656854249492381);
    CHECK_EQ(point2.distance(point3), 2.8284271247461903);
    CHECK_NOTHROW(Point::moveTowards(point1, point2, 1));
}

TEST_CASE("Cowboy cannot kill himself")
{
    Cowboy *tomi = new Cowboy("Tomy", Point(1, 0));
    CHECK_THROWS(tomi->shoot(tomi));
}

TEST_CASE("YoungNinja cannot kill himself")
{
    YoungNinja *yn = new YoungNinja("YON", Point(1, 0));
    CHECK_THROWS(yn->slash(yn));
}
TEST_CASE("TrainedNinja cannot kill himself")
{
    TrainedNinja *tn = new TrainedNinja("LEO", Point(1, 0));
    CHECK_THROWS(tn->slash(tn));
}
TEST_CASE("OldNinja cannot kill himself")
{
    OldNinja *on = new OldNinja("RICH", Point(1, 0));
    CHECK_THROWS(on->slash(on));
}
TEST_CASE("a Team cannot attack itself")
{
    Cowboy *cow = new Cowboy("bob", Point(1, 0));
    Cowboy *boy = new Cowboy("yossi", Point(2, 0));
    YoungNinja *ninj = new YoungNinja("ninja", Point(3, 0));
    Team t1(cow);
    t1.add(boy);
    t1.add(ninj);
    CHECK_THROWS(t1.attack(&t1));
}
TEST_CASE("Cant be more than  10 members in team")
{
    Character *Leader1 = new Cowboy("Cowboy1", Point(1, 2));
    Character *Character2 = new Cowboy("Cowboy2", Point(3, 4));
    Character *Character3 = new Cowboy("Cowboy3", Point(5, 6));
    Character *Character4 = new Cowboy("Cowboy4", Point(7, 8));
    Character *Character5 = new Cowboy("Cowboy5", Point(9, 10));
    Character *Character6 = new Cowboy("Cowboy6", Point(11, 12));
    Character *Character7 = new Cowboy("Cowboy7", Point(13, 14));
    Character *Character8 = new Cowboy("Cowboy8", Point(15, 16));
    Character *Character9 = new Cowboy("Cowboy9", Point(17, 18));
    Character *Character10 = new Cowboy("Cowboy10", Point(19, 20));
    Character *Character11 = new Cowboy("Cowboy11", Point(21, 22));
    Team team1(Leader1);
    team1.add(Character2);
    team1.add(Character3);
    team1.add(Character4);
    team1.add(Character5);
    team1.add(Character6);
    team1.add(Character7);
    team1.add(Character8);
    team1.add(Character9);
    team1.add(Character10);
    CHECK_THROWS(team1.add(Character11));
}



