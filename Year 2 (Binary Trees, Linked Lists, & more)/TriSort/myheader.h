#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<iomanip>

template <class BubbleSort>
void BSort(BubbleSort myAry[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(myAry[i] > myAry[j])
            {
                BubbleSort temp = myAry[i];
                myAry[i] = myAry[j];
                myAry[j] = temp;
            }
        }
    }
}

void ISort(int intAry[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(intAry[i] > intAry[j])
            {
                int temp = intAry[i];
                intAry[i] = intAry[j];
                intAry[j] = temp;
            }
        }
    }
}

void CSort(char charAry[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(charAry[i] > charAry[j])
            {
                char temp = charAry[i];
                charAry[i] = charAry[j];
                charAry[j] = temp;
            }
        }
    }
}

void DSort(double doubAry[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(doubAry[i] > doubAry[j])
            {
                double temp = doubAry[i];
                doubAry[i] = doubAry[j];
                doubAry[j] = temp;
            }
        }
    }
}
