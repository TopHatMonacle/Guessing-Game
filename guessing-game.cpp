#include <iostream>
// Didn't use 'using namespace std;' because it is considered bad practice.

int main()
{
    srand(time(NULL));
    int randnum = rand() % 100 + 1;
    // Variable "guess" only worked if its data type was set to "double", please do not change it.
    double guess;
    int tries = 0;
    int score = 0;
    int difficuilty;
    int passon;
    
    std::cout << "Please enter the difficuilty for your number guessing game.\nThis will affect how many tries it takes to lose the game.\n";
    
    std::cin >> difficuilty;
    std::cout << "Welcome to our guessing game!\nPlease guess our number.\n(This number is between 1 and 100. Enter 0 to leave.)\n";
    
    while (true) 
    {
        std::cin >> guess;
        tries++;
        
        if (tries >= difficuilty)
        {
            // Will not end the game if given an invalid input.
            if (guess >= 1 && guess <= 100)
            {
                std::cout << "The game has ended.\nYou did not guess my number within the number of tries allotted.\n";
                std::cout << "The number was " << randnum << ".\n";
                
                // Gives different message depending on how many games you won up to that point.
                if (score == 0)
                {
                    std::cout << "You have not won any games in this session.\n";
                }
                else if (score == 1)
                {
                    std::cout << "You have won 1 game in this session.\n";
                }
                else
                {
                    std::cout << "You have won " << score << " games this session.\n";
                }
                break;
            }
        }
        
        // Main game loop (checks if the input is correct after every input)
        if (guess >= 1 && guess <= 100)
        {
            if (guess > randnum) 
            {
                std::cout << "Your guess is greater than our number.\nPlease try again.\n";
            }
        
            else if (guess < randnum)
            {
                std::cout << "Your guess is less than our number.\nPlease try again.\n";
            }
        
            else if (guess == randnum)
            {
                std::cout << "Congratulations!\nIt took you " << tries <<  " tries to guess my number.\n";
                std::cout << "The correct number was " << randnum << ".\nA new number has been generated.\n";
            
                // Resets most variables to default, adds 1 to score, randomises randnum
                srand(time(NULL));
                randnum = rand() % 100 + 1;
                tries = 0;
                score++;
                
                // Checks if the user wants to continue
                std::cout << "Would you like to continue?\n(Enter 1 to continue.)\n";
                std::cin >> passon;
                if (passon == 1)
                {
                    std::cout << "The game has continued.\nPlease input your next guess.\n";
                }
                else
                {
                    std::cout << "The game has ended.\n";
                    if (score == 0)
                    {
                        std::cout << "You have not won any games in this session.\n";
                    }
                    else if (score == 1)
                    {
                        std::cout << "You have won 1 game in this session.\n";
                    }
                    else
                    {
                        std::cout << "You have won " << score << " games this session.\n";
                    }
                    break;
                }
                
                continue;
            }
        }
        
        // Gives player the option to leave at any time.
        else if (guess == 0)
        {
            break;
        }
        
        /* Used 'tries--' here because it adds a try by default. 
        It doesn't punish you for inputting an incorrect input. 
        There is an additional clause with the death logic to avoid penalisation. */
        else
        {
            std::cout << "That was an invalid input.\nPlease try again.\n";
            tries--;
        }
        
        
        // Logic for try counter
        if (tries == 1)
        {
            std::cout << "You have used up 1 try.\n";
        }
        
        else if (tries >= difficuilty - 3 && tries <= difficuilty - 2)
        {
            std::cout << "Hurry up!\nYou only have " << difficuilty - tries << " tries left.\n";
        }
        
        else if (tries == difficuilty - 1)
        {
            std::cout << "Hurry up!\nYou only have 1 try left.\n";
        }
        
        else 
        {
          std::cout << "You have used up " << tries << " tries.\n";  
        }
        
        continue;
    }
    
    return 0;
}
