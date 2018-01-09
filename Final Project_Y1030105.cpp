//
//  main.cpp
//  Final Project_Y1030105
//
//  Created by Chih-Chang Chao on 6/23/15.
//  Copyright (c) 2015 Chih-Chang Chao. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;

// create a distance calculator function in Cartesian coordinate system
double cartesian_calculate(int a[], int b[])  
{
	// simply calculate the distance
    double distance=sqrt(pow(a[0]-b[0],2.0)+pow(a[1]-b[1],2.0)+pow(a[2]-b[2],2.0));
    return distance;
}

// create a distance calculator function in spherical coordinate
double spherical_calculate(int a[], int b[]) 
{
	// first, covert the spherical coordinates to Cartesian coordinate system
    int x1=a[0]*sin(a[1])*cos(a[2]);
    int y1=a[0]*sin(a[1])*sin(a[2]);
    int z1=a[0]*cos(a[1]);
	int x2=b[0]*sin(b[1])*cos(a[2]);
	int y2=b[0]*sin(a[1])*sin(a[2]);
	int z2=b[0]*cos(a[1]);
	
	// then simply calculate the distance
	double distance=sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0)+pow(z1-z2,2.0));
    return distance;
}

// create a distance calculator function in cylindrial coordinate system
double cylindrical_calculate(int a[], int b[]) 
{
	// first, covert the cylindrical coordinates to Cartesian coordinates
    int x1=a[0]*cos(a[1]);
    int y1=a[0]*sin(a[1]);
    int z1=a[2];
	int x2=b[0]*cos(b[1]);
	int y2=b[0]*sin(b[1]);
	int z2=b[2];
	
	// then simply calculate the distance
	double distance=sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0)+pow(z1-z2,2.0));
    return distance;
}



int main(void)
{
    int guess[3]={0,0,0},mode,attempt=0;
    
    cout << "WELCOME TO MY TREASURE HUNTING GAME!!" << endl << endl;
    
A:  cout << "Please choose a specific coordinate system you want to play:" << endl << "(1) Cartesian (2) Spherical (3) Cylindrical (00) To exit: ";
    cin >> mode;
    cout << endl;

    while(mode==00) return 0;

    while(mode==1)	// Cartesian mode
    {
    	// randomly generates a location with respect to the specific coordinate
    	srand(time(NULL));
    	int ans[]={rand()%21+(-10),rand()%21+(-10),rand()%21+(-10)};
    	
        cout << "In this mystery Cartesian world...." << endl << "the treasure is hidden somewhere at (x,y,z), where: " << endl;
        cout << "x is a integer, has 21 pixels, and ranges from -10 to 10;" << endl;
        cout << "y is a integer, has 21 pixels, and ranges from -10 to 10;" << endl;
        cout << "z is a integer, has 21 pixels, and ranges from -10 to 10;" << endl << endl;
        
		for (int a=0;a<100;a++){
		
			cout << "Please enter your guess of x, y, and z with spaces in-between" << endl << "(e.g. 1 2 3, or 00 00 00 to show the answer and quit): " << endl;
			cout << "You guess: ";
        	cin >> guess[0] >> guess[1] >> guess[2];
            
            // introduce the distance calculator function
            // to determine if the treasure has been found
			if (cartesian_calculate(guess, ans)==0){																		
				cout << "Congratulations! You've found the treasure!" << endl;									
				break;
			}
			// create a gateway to exit the game
			else if(guess[0]==00 && guess[1]==00 && guess[2]==00){												
				cout << "The treasure is located at ("<< ans[0] << "," << ans[1] << "," << ans[2] << ")" << endl;
				cout << "You are almost there! What a shame!" << endl;
				return 0;
			}
			// accumulate the number of attempts for player's reference
			else
				attempt++;
				cout << "You are " << cartesian_calculate(guess, ans) << " steps away from the treasure!" << endl;
				cout << "You have tried " << attempt << " times in total!" << endl;								
				cout << endl;
		}
		break;
	}
	
	while(mode==2)	// spherical mode
	{
		// randomly generates a location with respect to the specific coordinate
    	srand(time(NULL));
    	int ans[]={rand()%21+(-10),rand()%11,rand()%11};

        cout << "In this mystery spherical world...." << endl << "the treasure is hidden somewhere at (r,£c,£p), where: " << endl;
        cout << "r  is a integer, has 21 pixels, and ranges from -10 to 10;" << endl;
        cout << "£c is a integer, has 10 pixels, and ranges from  0 to 180¢X(each pixel has 18¢X);" << endl;
        cout << "£p is a integer, has 10 pixels, and ranges from  0 to 360¢X(each pixel has 36¢X);" << endl << endl;
        
 		for (int a=0;a<100;a++){
		
			cout << "Please enter your guess of r,£cand £p with spaces in-between" << endl << "(e.g. 1 2 3, or 00 00 00 to show the answer and quit)" << endl;
			cout << "You guess: ";
        	cin >> guess[0] >> guess[1] >> guess[2];
        	
            // introduce the distance calculator function
            // to determine if the treasure has been found
			if (spherical_calculate(guess, ans)==0){
				cout << "Congratulations! You've found the treasure!" << endl;
				break;
			}
			// create a gateway to exit the game
			else if(guess[0]==00 && guess[1]==00 && guess[2]==00){
				cout << "The treasure is located at ("<< ans[0] << "," << ans[1] << "," << ans[2] << ")" << endl;
				cout << "You are almost there! What a shame!" << endl;
				return 0;
			}
			// accumulate the number of attempts for player's reference
			else																								
				attempt++;
				cout << "You are " << spherical_calculate(guess, ans) << " steps away from the treasure!" << endl;
				cout << "You have tried " << attempt << " times in total!" << endl;								
				cout << endl;
		}
		break;
	}
	
	
	while(mode==3)	// cylindrical mode
	{
		// randomly generates a location with respect to the specific coordinate
    	srand(time(NULL));
    	int ans[]={rand()%21+(-10),rand()%11,rand()%21+(-10)};

        cout << "In this mystery cylindrical world...." << endl << "the treasure is hidden somewhere at (r,£c,z), where: " << endl;
        cout << "r  is a integer, has 21 pixels, and ranges from -10 to 10;" << endl;
        cout << "£c is a integer, has 10 pixels, and ranges from  0 to 180¢X(each pixel has 18¢X);" << endl;
        cout << "z  is a integer, has 21 pixels, and ranges from  -10 to 10;" << endl << endl;
        
 		for (int a=0;a<100;a++){
		
			cout << "Please enter your guess of r,£cand z with spaces in-between" << endl << "(e.g. 1 2 3, or 00 00 00 to show the answer and quit): " << endl;
			cout << "You guess: ";
        	cin >> guess[0] >> guess[1] >> guess[2];

            // introduce the distance calculator function
            // to determine if the treasure has been found
			if (cylindrical_calculate(guess, ans)==0){
				cout << "Congratulations! You've found the treasure!" << endl;
				break;
			}
			// create a gateway to exit the game
			else if(guess[0]==00 && guess[1]==00 && guess[2]==00){												
				cout << "The treasure is located at ("<< ans[0] << "," << ans[1] << "," << ans[2] << ")" << endl;
				cout << "You are almost there! What a shame!" << endl;
				return 0;
			}
			// accumulate the number of attempts for player's reference
			else
				attempt++;
				cout << "You are " << cylindrical_calculate(guess, ans) << " steps away from the treasure!" << endl;
				cout << "You have tried " << attempt++ << " times in total!" << endl;								
				cout << endl;
		}
		break;
	}
	
	// check if the player wants to play again
	char check;
	cout << "Play again? Press (Y)es or any other key to exit: ";												
	cin >> check;
	cout << endl;
	
	switch(check)
	{
		case 'Y':
		case 'y':
			attempt=0;	// reset the attempts accumulator
			goto A;		// restart the game
			
		default:
			cout << "See you next time! :)" << endl;
			break;
	}
	
	// system("pause");
    return 0;
}
