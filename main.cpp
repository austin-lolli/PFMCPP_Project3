 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */


/*
 1)
 */
struct Headphones
{
    bool powerSwitch = true;
    unsigned int volume = 3;

    void increaseVolume( int vol );
};
/*
 2)
 */
struct Scoreboard
{
    float timeRemaining = 20.00f;
    int period = 1;
    int homeScore = 0;
    int awayScore = 0;

    struct Penalty // nested 1
    {
        float penaltyTime = 2.00f;
        int playerNumber = 99;
    };

    void startGame( float gameClock );
    void callPenalty( Penalty penalty ); 
};
/*
 3)
 */
struct Team
{
    int leftWing = 9;
    int rightWing = 28;
    int center = 39;
    int leftDefense = 65;
    int rightDefense = 88;
    int goalie = 31;
    double winPercentage = 0.444;
    bool isPlayoffTeam = false;

    int lineChange( int playerToBench, int PlayerToStart );
    double calculateWinPercentage( double seasonWins, double seasonLoss );
};
/*
 4)
 */
struct IceRink
{
    bool iceIsResurfaced = false;
    bool isGameDay = true;
    unsigned int rinkCapacity = 17000;

    struct Zamboni //nested 2
    {
        float waterTankVolume = 20.0f;
        bool isBroken = false;
    };

    void resurfaceIce( Zamboni zamboni );
};
/*
 5)
 */
struct Referee
{
    bool isBlind = true;
    unsigned int yearsExperience = 8;

    void callPenalty( int playerNumber );
    void faceOff( Team home, Team away );
};
/*
 6)
 */
struct Attendee
{
    bool homeTeamFan = 1;
    bool isHyped = 0;
    int age = 25;

    struct Ticket // nested 3
    {
        float costOfTicket = 44.00f;
        unsigned int section = 204;
        char row = 'C';
        unsigned int seat = 4;
    };

    void cheerForTeam( bool homeTeamFan );
};
/*
 7)
 */
 // uses only UDT's
struct Game
{
    Team homeTeam;
    Team awayTeam;
    Referee headRef;
    Referee linesman;
    Referee assistantRef;
    Scoreboard gameStatus;
    IceRink gameLocation;
    Attendee spectator;

    bool hypeUpFans( Attendee fan );
    void intermission( Attendee fan, Scoreboard stateOfGame );
};
/*
 8)
 */
struct Television
{   
    bool isTvOn = false;
    unsigned int volume = 15;
    unsigned int channel = 48;
    
    void setVolume( int vol );
    void changeChannel( int changeTo );
    bool powerSwitch( bool power );
    void playThroughHeadphones( Headphones headphones );
};
/*
 9)
 */
struct WeatherReport
{
    int temperature = 39;
    double percentHumidity = 0.87;
    float chanceOfRain = 0.10f;
    unsigned int airQualityIndex = 31;
    double barometer = 29.96;
    double timeOfDay = 14.50;
    bool isDaytime = true;

    void sunset( bool isDay, double time );
    int updateTemperature ( int currentTemp );
    void measureAirQuality ( int qualityIndex );
};
/*
 10)
 */
struct GiftCard
{
    double cardBalance = 100.00;
    unsigned int expirationDate = 20221231; //yyyymmdd
    const double cardNumber = 6155200244839177.0;

    void makePurchase(double currentBalance, double itemCost, unsigned int expiration);
    double reloadCard(double currentBalance, double addBalance);
};

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
