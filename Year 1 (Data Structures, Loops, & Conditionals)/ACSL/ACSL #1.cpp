//Trisha Choudhary, 12/14/17
//Mrs. Patnaik
//Enloe High School, Raleigh NC
//ACSL Competition #1
//Division: Junior Intermediate

#include<iostream>
#include<math.h>

using namespace std;

int checkRules(int total, int card)
{
	if (card == 9)
	{
		total = total + 0;
	}
	else if (card == 4)
	{
		total = total - 10;
	}
	else if (card == 0)
	{
		if (total + 11 <= 99)
		{
			total = total + 11;
		}
		else
		{
			total = total + 1;
		}
	}
	else
    {
	    total = total + card;
	}
	return total;
}

int main()
{
    int totalPts;
    int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10;
    int i;
    for(i=1; i<=5; i++)
    {
        int input = 0;
		do
        {
            cout << "Please enter total points less than 99 and 10 numerical value cards from 0 to 9." << endl;
            cin >> totalPts >> card1 >> card2 >> card3 >> card4 >> card5 >> card6 >> card7 >> card8 >> card9 >> card10;

        if (totalPts > 99 ||
            ((card1||card2||card3||card4||card5||card6||card7||card8||card9||card10) < 0) ||
            ((card1||card2||card3||card4||card5||card6||card7||card8||card9||card10) > 9))
        {
            cout << "Starting points needs to be less than 99 and cards need to be between 0 and 9." << endl;
        }
        else
        {
            input = 1;
        }

		} while(input==0);

        totalPts = checkRules(totalPts, card1);
        if (totalPts > 99)
        {
            cout << totalPts << ", " << "Dealer" << endl;
        }
        else
        {
            totalPts = checkRules(totalPts, card5);
            if (totalPts > 99)
            {
                cout << totalPts << ", " << "Player" << endl;
            }
            else
            {
                totalPts = checkRules(totalPts, card2);
                if (totalPts > 99)
                {
                    cout << totalPts << ", " << "Dealer" << endl;
                }
                else
                {
                    totalPts = checkRules(totalPts, card7);
                    if (totalPts > 99)
                    {
                        cout << totalPts << ", " << "Player" << endl;
                    }
                    else
                    {
                        totalPts = checkRules(totalPts, card3);
                        if (totalPts > 99)
                        {
                            cout << totalPts << ", " << "Dealer" << endl;
                        }
                        else
                        {
                            totalPts = checkRules(totalPts, card9);
                            if (totalPts > 99)
                            {
                                cout << totalPts << ", " << "Player" << endl;
                            }
                            else
                            {
                              totalPts = checkRules(totalPts, card4);
                              if (totalPts > 99)
                              {
                                cout << totalPts << ", " << "Dealer" << endl;
                              }
                            }
                        }
                    }
                }
            }
        }
    }
	return 0;
}
