#include <iostream>
#include<string>
using namespace std;

const int teamsize = 20;
const int extendedTeamSize = 23;

struct CricketTeam
{
    string country_name;
    string player_f_name;
    string player_s_name;
    int matches_played;
    int best_score;
};

void inputData(CricketTeam team[teamsize]);
void search(CricketTeam team[teamsize]);
void addPlayers(CricketTeam team[teamsize]);
void printOutput(CricketTeam extendedTeam[extendedTeamSize], int counter);
int main()
{
    CricketTeam team[teamsize];
    inputData(team);
    search(team);
    addPlayers(team);
    return 0;
}
void inputData(CricketTeam team[teamsize])
{
    for (int i = 0; i < teamsize; i++)
    {
        cout << "Please Enter the first name of Player number " << i + 1 << " : ";
        cin >> team[i].player_f_name;
        cout << "Please Enter the second name of Player number " << i + 1 << " : ";
        cin >> team[i].player_s_name;
        cout << "Please Enter the name of the country for Player number " << i + 1 << " : ";
        cin >> team[i].country_name;
        cout << "Please Enter the number of matches Player number " << i + 1 << " has played : ";
        cin >> team[i].matches_played;
        cout << "Please Enter the best score that Player number " << i + 1 << " has scored in a match : ";
        cin >> team[i].best_score;
    }
}
void search(CricketTeam team[teamsize])
{
    string name;
    cout << endl << "Enter the first name of the player you would like to search for(Case sensetive):  " << endl;
    cin >> name;
    for (int i = 0; i < teamsize; i++)
    {
        if (name == team[i].player_f_name)
        {
            cout << "The details of " << team[i].player_f_name << " are" << endl;
            cout << "Second name is " << team[i].player_s_name << endl;
            cout << "Country name is " << team[i].country_name << endl;
            cout << "Number of matches played is " << team[i].matches_played << endl;
            cout << "Best Score is " << team[i].best_score << endl;
            break;
        }
        else
        {
            continue;
        }
    }
}

void addPlayers(CricketTeam team[teamsize])
{
    int counter = 3;
    CricketTeam extendedTeam[extendedTeamSize];
    char ch;

    for (int i = 0; i < teamsize; i++)
    {
        extendedTeam[i].player_f_name = team[i].player_f_name;
        extendedTeam[i].player_s_name = team[i].player_s_name;
        extendedTeam[i].country_name = team[i].country_name;
        extendedTeam[i].best_score = team[i].best_score;
        extendedTeam[i].matches_played = team[i].matches_played;
    }

    for (int i = teamsize; i < extendedTeamSize; i++)
    {
        cout << "Would You like to add more players(you can only add up to 3)? y/n ";
        cin >> ch;

        if (ch == 'y')
        {
            cout << "Please Enter the first name of the Player : ";
            cin >> extendedTeam[i].player_f_name;
            cout << "Please Enter the second name of the Player : ";
            cin >> extendedTeam[i].player_s_name;
            cout << "Please Enter the name of the country for the Player : ";
            cin >> extendedTeam[i].country_name;
            cout << "Please Enter the number of matches the Player has played : ";
            cin >> extendedTeam[i].matches_played;
            cout << "Please Enter the best score that the Player has scored in a match : ";
            cin >> extendedTeam[i].best_score;
            counter--;
        }
        else
        {
            break;
        }
    }
    printOutput(extendedTeam, counter);
}

void printOutput(CricketTeam extendedTeam[extendedTeamSize], int counter)
{
    cout << "The fully updated list of players: " << endl;

    for (int i = 0; i < extendedTeamSize - counter; i++)
    {
        cout << extendedTeam[i].player_f_name << "\t" << extendedTeam[i].player_s_name << "\t" << extendedTeam[i].country_name << "\t" << extendedTeam[i].matches_played << "\t" << extendedTeam[i].best_score << endl;
    }
}
