/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

#include <iostream>
namespace Example {
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; //3) in-class initialization
    UDT() : a(0) { } //3) 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()




/*
 1)
 */
struct Headphones
{
    unsigned int volume;
    bool powerSwitch;

    Headphones() 
    { 
        volume = 3; 
        powerSwitch = true; 
    }

    void increaseVolume( unsigned int vol );
};

void Headphones::increaseVolume ( unsigned int vol )
{
    Headphones::volume = vol;
    std::cout << "Volume set at :" << vol << std::endl;
}
/*
 2)
 */
struct Scoreboard
{
    float timeRemaining;
    int period;
    int homeScore;
    int awayScore;

    Scoreboard() 
    { 
        timeRemaining = 20.00f; 
        period = 1; 
        homeScore = 0; 
        awayScore = 0;
    }

    struct Penalty // nested 1
    {
        float penaltyTime;
        int playerNumber;

        Penalty() 
        { 
            penaltyTime = 2.00f; 
            playerNumber = 99; 
        }
    };

    void startGame();
    void callPenalty( Penalty penalty, int playerNum, bool isMajor ); 
};

void Scoreboard::startGame()
{
    std::cout << "Game on!" << std::endl;
}

void Scoreboard::callPenalty( Scoreboard::Penalty penalty, int playerNum, bool isMajor )
{
    if( isMajor == true )
    {
        penalty.penaltyTime = 5.00f;
        std::cout << "5 Minute Major on " << playerNum << std::endl;
    }
    else
    {
        penalty.penaltyTime = 2.00f;
        std::cout << "2 Minute Minor on " << playerNum << std::endl;
    }

    penalty.playerNumber = playerNum;    
}
/*
 3)
 */
struct Team
{
    int leftWing;
    int rightWing;
    int center;
    int leftDefense;
    int rightDefense;
    int goalie;
    double winPercentage;
    bool isPlayoffTeam;

    Team()
    { 
        leftWing = 9; 
        rightWing = 28; 
        center = 39; 
        leftDefense = 65; 
        rightDefense = 88; 
        goalie = 31; 
        winPercentage = 0.0; 
        isPlayoffTeam = true; 
    }

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

    std::cout << "Active Players: " << LW << ", " << RW << ", " << C << ", " << LD << ", " << RD << std::endl;
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
    bool iceIsResurfaced;
    bool isGameDay;
    unsigned int rinkCapacity;

    IceRink()
    { 
        iceIsResurfaced = false; 
        isGameDay = true; 
        rinkCapacity = 17500; 
    }

    struct Zamboni //nested 2
    {
        double waterTankVolume;
        bool isBroken;
        
        Zamboni() 
        { 
            waterTankVolume = 20.0; 
            isBroken = false; 
        }
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
    bool isBlind;
    unsigned int yearsExperience ;
    bool puckInPlay;

    Referee()
    { 
        isBlind = true; 
        yearsExperience = 8; 
        puckInPlay = false;
    }

    void faceOff();
};

void Referee::faceOff()
{
    Referee::puckInPlay = true;
    std::cout << "Puck is live!" << std::endl;
}
/*
 6)
 */
struct Attendee
{
    bool homeTeamFan;
    bool isHyped;
    int age;

    Attendee()
    { 
        homeTeamFan = true; 
        isHyped = false; 
        age = 25;
    }

    struct Ticket // nested 3
    {
        float costOfTicket;
        unsigned int section;
        char row;
        unsigned int seat;

        Ticket()
        { 
            costOfTicket = 44.00f; 
            section = 204; 
            row = 'C'; 
            seat = 4; 
        }
    };

    void cheerForTeam( bool homeFan );
};

void Attendee::cheerForTeam( bool homeFan )
{
    if( homeFan == true )
    {
        Attendee::isHyped = true;
        std::cout << "This crowd is ROARING!!!" << std::endl;
    }
    else
    {
    std::cout << "You can really feel the presenece of the Away team's fans tonight!" << std::endl;
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

    Game()
    { 
        Team(); 
        Team(); 
        Referee(); 
        Referee(); 
        Referee(); 
        Scoreboard(); 
        IceRink(); 
        Attendee(); 
    }

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
    bool isTvOn;
    unsigned int volume = 15;
    unsigned int channel = 48;

    Television()
    {
        isTvOn = false;
        volume = 15;
        channel = 48;
    }
    
    void setVolume( unsigned int vol );
    void changeChannel( unsigned int changeTo );
    bool powerSwitch( bool power );
    void playThroughHeadphones( Headphones headphones );
};

void Television::setVolume( unsigned int vol )
{
    Television::volume = vol;

    std::cout << "Volume now set at: " << vol << std::endl;

}

void Television::changeChannel( unsigned int changeTo )
{
    unsigned int temp = Television::channel;

    Television::channel = changeTo;

    std::cout << "Channel changed from " << temp << " to " << changeTo << std::endl;
}

bool Television::powerSwitch( bool power )
{
    if( power == true )
    {
        std::cout << "Powering on!" << std::endl;
        return true;
    }

    std::cout << "Shutting down." << std::endl;   
    return false;
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
    int temperature;
    double percentHumidity;
    float chanceOfRain;
    unsigned int airQualityIndex;
    double barometer;
    double timeOfDay; // in format of military time hour . fraction of hour
    bool isDaytime;

    WeatherReport()
    {
        temperature = 55;
        percentHumidity = 0.4;
        chanceOfRain = 0.50f;
        airQualityIndex = 7;
        barometer = 31.44;
        timeOfDay = 21.25;
        isDaytime = false;
    }

    void sunset( double time );
    int updateTemperature ( int currentTemp );
    void measureAirQuality ( unsigned int qualityIndex );
};

void WeatherReport::sunset( double time )
{
    if(WeatherReport::timeOfDay > time )
    {
        WeatherReport::isDaytime = false;
        std::cout << "The stars are bright tonight!" << std::endl;
    }
    else
    {
        WeatherReport::isDaytime = true;
        std::cout << "There's still time left to enjoy the sun!" << std::endl;
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
    double cardNumber = 6155200244839177.0; //removed const from previous assignment to allow overwrite in constructor

    // constructor will overwrite default values
    GiftCard()
    {
        expirationDate = 20230131; //yyyymmdd
        cardBalance = 150.00;
        cardNumber = 2833730365431231.0;
    }

    void makePurchase(double itemCost);
    double reloadCard(double addBalance);
};

void GiftCard::makePurchase(double itemCost)
{
    if( GiftCard::expirationDate >= 20200131 )
    {
        GiftCard::cardBalance -= itemCost;

        std::cout << "Your remaining balance is: " << GiftCard::cardBalance << std::endl;
    }
    else
    {
        std::cout << "Card expired!" << std::endl;
    }
}

double GiftCard::reloadCard(double addBalance)
{
    GiftCard::cardBalance += addBalance;
    return GiftCard::cardBalance;
}

#include <iostream>
int main()
{
    Example::main();
    Headphones airPods;
    airPods.increaseVolume(6);

    Scoreboard newGame;
    newGame.startGame();
    Scoreboard::Penalty sinBin;
    newGame.callPenalty( sinBin, 88, 0);

    Team sanJoseSharks;
    sanJoseSharks.lineChange(12, 19, 20, 44, 4);
    std::cout << "Team Win Percentage: " << sanJoseSharks.calculateWinPercentage(12,25)<< std::endl;
    
    Referee wesMcCauley;
    wesMcCauley.faceOff();

    Attendee me;
    me.cheerForTeam(true);

    Television flatscreen;
    flatscreen.setVolume(30);
    flatscreen.changeChannel(7);
    
    WeatherReport sanFrancisco;
    sanFrancisco.sunset(17.25);
    std::cout << "The current temperature is: " << sanFrancisco.updateTemperature(49) << std::endl;

    GiftCard amazon;
    amazon.makePurchase(24.97);
    std::cout << "Credit added to your gift card. New balance is: " << amazon.reloadCard(100.0) << std::endl;



    std::cout << "good to go!" << std::endl;
}
