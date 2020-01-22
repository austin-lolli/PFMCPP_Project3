/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 1) Add a constructor for each User-Defined-Type.
 
 2) Instantiate a few of your user-defined types in the main function at the bottom of that file, and call some of those member functions.
 
 3) make them print out something interesting via std::cout
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type
{
    int a; //a member variable
    UDT() { a = 0; }             //3) the constructor
    void printThing()            //1) the member function
    {
        std::cout << "UDT::printThing() " << a << std::endl;  //5) printing out something interesting
    }
};

int main()
{
    UDT foo;              //4) instantiating a UDT in main()
    foo.printThing();     //4) calling a member function of the instance that was instantiated.
    
    return 0;
}
}



/*
 1)
 */
struct Headphones
{
    unsigned int volume = 3;
    bool powerSwitch = true;

    void increaseVolume( unsigned int vol );
};

void Headphones::increaseVolume ( unsigned int vol )
{
    Headphones::volume = vol;
}
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

    void startGame();
    void callPenalty( Penalty penalty, int playerNum, bool isMajor ); 
};

void Scoreboard::startGame()
{
    Scoreboard::timeRemaining = 20.00f;
    Scoreboard::period = 1;
    Scoreboard::homeScore = 0;
    Scoreboard::awayScore = 0;
}

void Scoreboard::callPenalty( Scoreboard::Penalty penalty, int playerNum, bool isMajor )
{
    if( isMajor == true )
    {
        penalty.penaltyTime = 5.00f;
    }
    else
    {
        penalty.penaltyTime = 2.00f;
    }

    penalty.playerNumber = playerNum;    
}
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

    void lineChange( int LW, int RW, int C, int LD, int RD );
    double calculateWinPercentage( double seasonWins, double seasonLoss );
};

void Team::lineChange( int LW, int RW, int C, int LD, int RD )
{
    Team::leftWing = LW;
    Team::rightWing = RW;
    Team::center = C;
    Team::leftDefense = LD;
    Team::rightDefense = RD;
}

double Team::calculateWinPercentage( double seasonWins, double seasonLoss)
{
    double total = seasonWins + seasonLoss;
    
    return seasonWins / total; 
}
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
        double waterTankVolume = 20.0;
        bool isBroken = false;
    };

    void resurfaceIce( Zamboni zamboni );
};

void IceRink::resurfaceIce( Zamboni zamboni )
{
    if( zamboni.isBroken == false )
    {
        if( zamboni.waterTankVolume >= 2.0 )
        {
            IceRink::iceIsResurfaced = true;
            zamboni.waterTankVolume -= 2.0;
        }
        else //fill up the tank
        {
            while( zamboni.waterTankVolume < 20.0 )
            {
                ++zamboni.waterTankVolume;
            }

        }
    }
}
/*
 5)
 */
struct Referee
{
    bool isBlind = true;
    unsigned int yearsExperience = 8;
    bool puckInPlay = false;

    void faceOff();
};

void Referee::faceOff()
{
    Referee::puckInPlay = true;
}
/*
 6)
 */
struct Attendee
{
    bool homeTeamFan = true;
    bool isHyped = false;
    int age = 25;

    struct Ticket // nested 3
    {
        float costOfTicket = 44.00f;
        unsigned int section = 204;
        char row = 'C';
        unsigned int seat = 4;
    };

    void cheerForTeam( bool homeFan );
};

void Attendee::cheerForTeam( bool homeFan )
{
    if( homeFan == true )
    {
        Attendee::isHyped = true;
    }
}
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

bool Game::hypeUpFans( Attendee fan )
{
    if( fan.homeTeamFan == true )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Game::intermission( Attendee fan, Scoreboard stateOfGame )
{
    fan.isHyped = false;
    stateOfGame.timeRemaining = 20.00f;
    ++stateOfGame.period;
}
/*
 8)
 */
struct Television
{   
    bool isTvOn = false;
    unsigned int volume = 15;
    unsigned int channel = 48;
    
    void setVolume( unsigned int vol );
    void changeChannel( unsigned int changeTo );
    bool powerSwitch( bool power );
    void playThroughHeadphones( Headphones headphones );
};

void Television::setVolume( unsigned int vol )
{
    Television::volume = vol;
}

void Television::changeChannel( unsigned int changeTo )
{
    Television::channel = changeTo;
}

bool Television::powerSwitch( bool power )
{
    if( power == true )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Television::playThroughHeadphones( Headphones headphones )
{
    Television::volume = 0;
    headphones.powerSwitch = true;
}
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

    void sunset( double time );
    int updateTemperature ( int currentTemp );
    void measureAirQuality ( unsigned int qualityIndex );
};

void WeatherReport::sunset( double time )
{
    if(WeatherReport::timeOfDay > time )
    {
        WeatherReport::isDaytime = false;
    }
    else
    {
        WeatherReport::isDaytime = true;
    }
}

int WeatherReport::updateTemperature( int currentTemp )
{
    WeatherReport::temperature = currentTemp;
    return currentTemp;
}

void WeatherReport::measureAirQuality( unsigned int qualityIndex )
{
    WeatherReport::airQualityIndex = qualityIndex;
}
/*
 10)
 */
struct GiftCard
{
    unsigned int expirationDate = 20221231; //yyyymmdd
    double cardBalance = 100.00;
    const double cardNumber = 6155200244839177.0;

    void makePurchase(double currentBalance, double itemCost, unsigned int expiration);
    double reloadCard(double currentBalance, double addBalance);
};

void GiftCard::makePurchase(double currentBalance, double itemCost, unsigned int expiration)
{
    if( expiration == false )
    {
        currentBalance -= itemCost;
    }
}

double GiftCard::reloadCard(double currentBalance, double addBalance)
{
    currentBalance += addBalance;
    GiftCard::cardBalance = currentBalance;
    return currentBalance;
}

#include <iostream>
int main()
{
    Example::main();
    std::cout << "good to go!" << std::endl;
}
