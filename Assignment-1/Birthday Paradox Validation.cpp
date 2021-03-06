//============================================================================
// Name        : Birthday.cpp
// Author      : TheCodeBusters
// Version     : Version 3.0
// Copyright   : Your copyright notice
// Description : Validation of the Birthday Paradox
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
	int i,j,k,temp,match;
	int no_of_people = 23;
	int bday[no_of_people];
	int no_of_matches= 0;
	double no_of_trials = 50000.0;
	double prob = 1.0,expected_prob,experimental_prob;

	srand(time(0));								//seed generator using time() for rand() function
	for(k=1; k<=no_of_trials; k++)
	{
		for (i=1; i<=no_of_people; i++)					//randomly generate 23 bdays
		{
			bday[i] = ((rand()%365) + 1);
			//cout<< bday[i] <<" ";
		}

		for(i=1; i<=no_of_people; i++)                   //bubble sort bday array
		{
			for (j=1; j<=no_of_people-1; j++)
			{
				if (bday[j] > bday[j+1])
				{
					temp = bday[j];
					bday[j] = bday[j+1];
					bday[j+1] = temp;
				}
			}
		}
		/*cout<<endl;
		for (i=1; i<=no_of_people; i++)
			cout<< bday[i] <<" ";*/

		match=0;
		i=1;												//find if match is there
		while (i<=no_of_people && match==0)
		{
			if (bday[i] == bday[i+1])
				match = 1;
			else
				i++;
		}

		if(match == 1)
			no_of_matches = no_of_matches + 1;
	}

	cout << "No. of trials in which match found = "<<no_of_matches << endl;
	experimental_prob=no_of_matches/no_of_trials;
	cout<<fixed<<setprecision(15)<<"Experimental Probability value ="<<experimental_prob;

	for(i=0; i<no_of_people; i++)						 //calculate expected probability by formula
	    prob = prob*(365-i)/365;
	expected_prob = 1 - prob;
	cout<< endl /*<< prob << endl*/ <<fixed<<setprecision(15)<<"Expected Probability value ="<< expected_prob;

}

