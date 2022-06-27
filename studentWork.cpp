#include <iostream>
#include <string>
using namespace std;

int main()
{
    int input = 0;
    string output = "";

    cout << "Please enter a positive integer: ";
    cin >> input;

    for (int r = 0; r < input; r++)
    {
        for (int c = 0; c < input; c++)
        {
            // left || right || top || bottom
            if (c == 0 || c == input - 1 || r == 0 || r == input - 1)
            {
                output += "#";
            }
                // left diagonal going right || right diagonal going left
            else if (r == c || r + c == input - 1)
            {
                output += "$";
            }
            else
            {
                output += " ";
            }
        }

        // initial attempt -- too ridiculous
        //  for (int nc=0; nc<= input-1;nc++){
        //    if (r!=0 || r!=input-1){
        //      if (nc==0 ){
        //        output += "#";
        //      }
        //    }
        //  }

        // for (int s=1;s<r;s++){
        //   output +="P";
        // }

        // for (int d=0;d<r;d++){
        //   if (d==0 ){
        //   output +="$";
        //   }
        // }

        // for (int as=2;as<input-r ;as++ ){
        //   if (r!=0){
        //   output+= "X";
        //   }
        // }

        output += "\n";
    }
    cout << output;

    return 0;
}
