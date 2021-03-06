/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() or for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 example:
 */

#include <iostream>
namespace Example {
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //3), 4c) 
    {
        Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //5) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //6) 
    return 0;
}
}

//call Example::main() in main()



/*
 1)
 */
struct Headphones
{
    unsigned int volume { 3 };
    bool powerSwitch { true };

    Headphones();

    void increaseVolume( unsigned int vol );
    unsigned int holdDecreaseVolume( unsigned int vol, unsigned int target );
};

Headphones::Headphones() {}

void Headphones::increaseVolume ( unsigned int vol )
{
    volume = vol;
    std::cout << "Volume set at: " << vol << std::endl;
}

unsigned int Headphones::holdDecreaseVolume ( unsigned int vol, unsigned int target )
{
    if( vol <  target )
    {
        return 0;
    }
    else if ( vol > target )
    {
        while( vol >= target )
        {
            vol -= 1;
            if( vol == target )
            {
                return vol;
            }
        }
    }
    return volume;
}
/*
 2)
 */
struct Scoreboard
{
    int timeRemaining; // changed to int for new while loop function clockTick
    int period;
    int homeScore;
    int awayScore;

    Scoreboard() : timeRemaining(20), period(1), homeScore(0), awayScore(0)
    {

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
    void clockTick();
};

void Scoreboard::startGame()
{
    std::cout << "Game on!" << std::endl;
    std::cout << "Time Remaining: " << timeRemaining << std::endl;
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

void Scoreboard::clockTick()
{
    while( timeRemaining > 0 )
    {
        --timeRemaining; 
    } 
    if( period < 3 )
    {
        std::cout << "End of Period " << period << std::endl; 
        timeRemaining = 20;  
        ++period;  
        std::cout << "Now starting Period " << period << std::endl;
    }
    else
    {
        std::cout << "End of regulation!" << std::endl;
    }
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
    double winPercentage = 0.0;
    bool isPlayoffTeam = true;

    Team();

    void lineChange( int LW, int RW, int C, int LD, int RD );
    double calculateWinPercentage( double seasonWins, double seasonLoss );
};

Team::Team() {}

void Team::lineChange( int LW, int RW, int C, int LD, int RD )
{
    std::cout << "Subbing out: " << leftWing << ", " << rightWing << ", " << center << ", " << leftDefense << ", " << rightDefense <<std::endl; 

    leftWing = LW;
    rightWing = RW;
    center = C; 
    leftDefense = LD; 
    rightDefense = RD; 

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

    IceRink();

    struct Zamboni //nested 2
    {
        double waterTankVolume;
        bool isBroken;
        
        Zamboni();
    };

    void resurfaceIce( Zamboni zamboni );
};

IceRink::IceRink() : iceIsResurfaced(false),  isGameDay(true), rinkCapacity(17500)
{

}

IceRink::Zamboni::Zamboni() : waterTankVolume(20.0), isBroken(false)
{

}

void IceRink::resurfaceIce( Zamboni zamboni )
{
    if( zamboni.isBroken == false )
    {
        if( zamboni.waterTankVolume >= 2.0 )
        {
            iceIsResurfaced = true; 
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

    Referee();

    void faceOff();
};

Referee::Referee() {}

void Referee::faceOff()
{
    puckInPlay = true; 
    std::cout << "Puck is live!" << std::endl;
}
/*
 6)
 */
struct Attendee
{
    Attendee();

    bool homeTeamFan;
    bool isHyped;
    int age;

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

        float priceIncrease( int daysToGame);
    };

    void cheerForTeam( bool homeFan );
};

Attendee::Attendee() : homeTeamFan(true), isHyped(false), age(25) 
{

}


void Attendee::cheerForTeam( bool homeFan )
{
    if( homeFan == true )
    {
        isHyped = true; 
        std::cout << "This crowd is ROARING!!!" << std::endl;
    }
    else
    {
    std::cout << "You can really feel the presenece of the Away team's fans tonight!" << std::endl; 
    }
}

float Attendee::Ticket::priceIncrease( int daysToGame )
{
    for( int i = 0; i <= daysToGame; ++i)
    {
        costOfTicket *= 1.1f;
    }
    return costOfTicket; 
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
    bool isTvOn = false;
    int volume = 15;
    int channel = 48;

    Television();
    
    void setVolume( int vol );
    void changeChannel( int changeTo );
    bool powerSwitch( bool power );
    void playThroughHeadphones( Headphones headphones );
    void channelUpOrDown( int changeTo );
};

Television::Television() {}

void Television::setVolume( int vol )
{
    volume = vol;

    std::cout << "Volume now set at: " << vol << std::endl;

}

void Television::changeChannel( int changeTo )
{
    int temp = channel; 

    channel = changeTo; 

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
    volume = 0; 
    headphones.powerSwitch = true;
}

void Television::channelUpOrDown( int changeTo )
{
    if( changeTo == channel ) 
    {
        std::cout << "Already on channel " << changeTo << std::endl;
    }
    else if( changeTo > channel ) 
    {
        while( channel != changeTo )
        {
            ++channel; 
            std::cout << "Channel: " << channel << std::endl;
        }
    }
    else // changeTo < channel
    {
        int temp = channel - changeTo;
        for( int i = 0; i < temp; ++i )
        {
            --channel;
            std::cout << "Channel: " << channel << std::endl;
        }
    }
}
/*
 9)
 */
struct WeatherReport
{
    int temperature {55};
    double percentHumidity {0.4};
    float chanceOfRain {0.50f};
    unsigned int airQualityIndex = 7;
    double barometer = 31.44;
    double timeOfDay = 21.25; // in format of military time hour . fraction of hour
    bool isDaytime {false};

    WeatherReport();

    void sunset( double time );
    int updateTemperature ( int currentTemp );
    void measureAirQuality ( unsigned int qualityIndex );
};

WeatherReport::WeatherReport()
{

}

void WeatherReport::sunset( double time )
{
    if(timeOfDay > time )
    {
        isDaytime = false;
        std::cout << "The stars are bright tonight!" << std::endl;
    }
    else
    {
        isDaytime = true;
        std::cout << "There's still time left to enjoy the sun!" << std::endl;
    }
}

int WeatherReport::updateTemperature( int currentTemp )
{
    temperature = currentTemp;
    return currentTemp;
}

void WeatherReport::measureAirQuality( unsigned int qualityIndex )
{
    airQualityIndex = qualityIndex;
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
    GiftCard();

    void makePurchase(double itemCost);
    double reloadCard(double addBalance);
    void recurringPurchase(double subscriptionCost, int subscriptionLength);
};

GiftCard::GiftCard() : expirationDate(20230131), cardBalance(150.00), cardNumber(2833730365431231.0) 
{

}


void GiftCard::makePurchase(double itemCost)
{
    if( expirationDate >= 20200131 )
    {
        cardBalance -= itemCost;

        std::cout << "Your remaining balance is: " << cardBalance << std::endl;
    }
    else
    {
        std::cout << "Card expired!" << std::endl;
    }
}

double GiftCard::reloadCard(double addBalance)
{
    cardBalance += addBalance;
    return cardBalance;
}

void GiftCard::recurringPurchase(double subscriptionCost, int subscriptionLength)
{
    for( int i = 0; i < subscriptionLength; ++i)
    {
        cardBalance -= subscriptionCost;
        std::cout << "Card billed $" << subscriptionCost << ". Your current balance is " << cardBalance << " and your subscription is active for " << subscriptionLength << " more months. " << std::endl;
    }
}

#include <iostream>
int main()
{
    Example::main();
    Headphones airPods;
    std::cout << airPods.volume << std::endl;
    airPods.increaseVolume(6);
    std::cout << "Volume decreased to: " << airPods.holdDecreaseVolume(airPods.volume, 2) << std::endl; // new volume function, conditional while

    Scoreboard newGame;
    newGame.startGame();
    Scoreboard::Penalty sinBin;
    newGame.callPenalty( sinBin, 88, 0);
    newGame.clockTick(); // new scoreboard function, while

    Team sanJoseSharks;
    sanJoseSharks.lineChange(12, 19, 20, 44, 4);
    std::cout << "Team Win Percentage: " << sanJoseSharks.calculateWinPercentage(12,25)<< std::endl;
    
    Referee wesMcCauley;
    wesMcCauley.faceOff();

    Attendee me;
    me.cheerForTeam(true);

    Attendee::Ticket sharksGame;
    std::cout << "Expected ticket value on game day: " << sharksGame.priceIncrease(3) << std::endl; // value appreciation ticket function, for loop

    Television flatscreen;
    flatscreen.setVolume(30);
    flatscreen.changeChannel(7);
    flatscreen.channelUpOrDown(10); // channel changer, "hold +" while loop
    flatscreen.channelUpOrDown(3); // channel changer, "hold -" for loop
    
    WeatherReport sanFrancisco;
    sanFrancisco.sunset(17.25);
    std::cout << "The current temperature is: " << sanFrancisco.updateTemperature(49) << std::endl;

    GiftCard amazon;
    amazon.makePurchase(24.97);
    std::cout << "Credit added to your gift card. New balance is: " << amazon.reloadCard(100.0) << std::endl;
    amazon.recurringPurchase(4.99, 6); // subscription purchase function, for loop



    std::cout << "good to go!" << std::endl;
}
