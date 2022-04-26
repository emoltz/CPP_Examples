// mxf4384_hw6 mehmet akif firatli
#include<iostream>
#include<vector>
using namespace std;

vector<int>readData();
int calculateLenght(vector<int>vs);
int* findIndex(vector<int>vs, int& arrSize, int max_value);
void printData(int* arr, const int arrSize);
int main() {
    vector<int>v = readData();
    int size;
    int max_len = calculateLenght(v);
    cout << "The most frequent length is " << max_len << endl;
    int* arr = findIndex(v, size, max_len);
    printData(arr, size);

    delete[]arr;
    arr = nullptr;

    return 0;
}
vector<int>readData() {
    int num;
    bool seen = false;
    vector<int>vs;
    cout << "Please enter a non-empty sequence of positive integers.Each integer should be in a seperate line" << endl;
    cout << "To indicate the end of the input enter 0 in line" << endl;
    while (seen == false) {
        cin >> num;
        if (num == 0) {
            seen = true;
        }
        else {
            vs.push_back(num);
        }
    }
    return vs;
}
int calculateLenght(vector<int>vs) {


    int max_size;
    int vs_size = vs.size();
    int* new_arr = new int[vs_size];
    for (int i = 0; i < vs_size; i++) {
        max_size = 1;
        int num = vs[i];
        while (num > 0) {
            if (num / 10 > 0) {
                max_size++;
            }
            num = num / 10;
        }
        new_arr[i] = max_size;
    }
    int max = new_arr[0];
    for (int i = 0; i < vs_size; i++) {
        if (max < new_arr[i]) {
            max = new_arr[i];
        }
    }
    return max_size;
}
int* findIndex(vector<int>vs, int& arrSize, int max_value) {
    int size = vs.size();
    int* new_arr = new int[size];
    int digit;
    for (int i = 0; i < size; i++) {
        new_arr[i] = 0;
    }
    for (int i = 0; i <size; i++) {
        digit= 1;
        int num = vs[i];
        while (num > 0) {
            if (num / 10 > 0) {
                digit++;
            }
            num = num / 10;
        }
        if (digit == max_value) {
            new_arr[i] = vs[i];
        }
    }
    arrSize = vs.size();
    return new_arr;
}
void printData(int* arr, const int arrSize) {
    cout << "The positive integrs with most frequent length are: " << endl;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            cout << arr[i] << ' ';
        }
    }
}