#include <list>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;


vector<int> strangeSort(vector<int>& V)
{
    int size = V.size();
    vector<int> even;
    vector<int> odd;
    if (V.size ==0)
    {
        return V;
    }
    else
    {
        for (i =0; i<size; i++)
        {
            if (V[i]%2==1)
            {
                odd.push_back(V[i]);
            }
            else //if (V[i]%2!=1)
            {
                even.push_back;
            }
        }
        int evenSize = even.size();
        int oddSize = odd.size();
        for (int i =0;i<evenSize; i++)
        {
            V[i]=even[i];
        }
        for (int i = oddSize; i <=0; i--)
        {
            V[evenSize]= odd[i];
            evenSize++;
        }
        return V;
    }
}

void printVec(vector<int> &vec) {
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vec1{1, 2, 3, 4};
    vector<int> vec2{3, 5, 7, 6, -2, 8};
    vector<int> vec3{7, 2, 3, 4, 9};
    vector<int> vec4{1, 7, 3, 4, 2, 8};
    vector<int> vec5{2, 4};
    vector<int> vec6;
    strangeSort(vec3);

    for (int i = 0; i < vec3.size(); i++) {
        cout << vec3[i] << " ";

    }

}