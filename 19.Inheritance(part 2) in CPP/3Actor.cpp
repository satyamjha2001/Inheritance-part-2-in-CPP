#include <iostream>
#include <string.h>
using namespace std;
class Actor
{
private:
    char name[25];
    int age;

public:
    void setName(char n[]) { strcpy(name, n); }
    void setAge(int a) { age = a; }
    char *getName() { return name; }
    int getAge() { return age; }
};
class TVActor : virtual public Actor
{
private:
    int TVProjectCount = 0;

public:
    void setTVProjectCount(int c) { TVProjectCount = c; }
    int getTVProjectCount() { return TVProjectCount; }
    void setTVActor(char n[], int a, int pcount)
    {
        setName(n);
        setAge(a);
        setTVProjectCount(pcount);
    }
    void showTVActor()
    {
        cout << "\nName = " << getName() << "\nage = " << getAge() << "\nProject Count = " << getTVProjectCount();
    }
};
class MovieActor : virtual public Actor
{
private:
    int movieProjectCount;

public:
    void setMovieProjectCount(int c) { movieProjectCount = c; }
    int getMovieProjectCount() { return movieProjectCount; }
    void setMovieActor(char name[], int age, int pcount)
    {
        setName(name);
        setAge(age);
        setMovieProjectCount(pcount);
    }
    void showMovieActor()
    {
        cout << "\nName = " << getName() << "\nage = " << getAge() << "\nProject Count = " << getMovieProjectCount();
    }
};
class AllScreenActor : public TVActor, public MovieActor
{
public:
    void setActorData(char n[], int a, int tvproject, int movieproject)
    {
        setName(n);
        setAge(a);
        setTVProjectCount(tvproject);
        setMovieProjectCount(movieproject);
    }
    void showActorData()
    {
        cout << "\nName = " << getName() << "\nage = " << getAge() << "\nTV Project Count = " << getTVProjectCount() << "\nMovie Project Count = " << getMovieProjectCount();
    }
};
int main()
{
    AllScreenActor a1;
    a1.setActorData("Satyam", 21, 10, 5);
    a1.showActorData();
    return 0;
}