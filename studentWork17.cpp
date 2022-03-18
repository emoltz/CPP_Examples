#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

const string PIN = "12345";
const int arraySize = 10;

bool checkPin (char arr[], int arraySize, char digArr[], string str);
void genCode (char arr[], int arraySize);
void printArray (char arr[], int arraySize);

void genCode (char arr[], int arraySize)
{
    srand(time(0));
    int temp;
    for (int i=0; i<arraySize; i++)
    {   temp = (rand()%3)+1;
        if (temp == 1)
            arr[i] = '1';

        else if (temp == 2)
            arr[i] = '2';

        else if (temp == 3)
            arr[i] = '3';
    }
    return;

}

void printArray(char arr[], int arrSize)
{
    int i;
    for (i = 0; i < arrSize; i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return;
}

int main()
{   string userInput;
    bool validC;
    char arr[arraySize];
    char digitList[arraySize] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    cout<<"Please enter your PIN according to the following mapping:"<<endl;
    cout<<"PIN:\t";
    printArray(digitList, arraySize);

    cout<<"NUM:\t";
    genCode(arr, arraySize);
    printArray(arr, arraySize);
    cin>>userInput;

    validC = checkPin(arr, arraySize, digitList, userInput);

    if(validC == true)
        cout<<"Your PIN is correct"<<endl;

    else
        cout<<"Your PIN is not correct"<<endl;

    return 0;
}

bool checkPin (char arr[], int arraySize, char digArr[], string str)
{
    int i=0;
    int j;
    int count = 0;
    while (i < str.length())
    {
        j=0;
        while(j < arraySize)
        {   if((str[i] == arr[j]) && (digArr[j] == PIN[i]))
            {
                count++;
                j = arraySize;
            }
            else
                j++;
        }
        if (j >= arraySize)
            i++;
    }
    if (count == 5)
        return true;

    else
        return false;
}