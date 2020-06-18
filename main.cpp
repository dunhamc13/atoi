/* ATOI
 * @Description: Practicing solving problems with arrays.  Given a string,
 * convert it to an integer.  
 *
 * @Assumption: Remove leading white space, optional + /-, no MAX / MIN over flow
 * @Efficiency: Time = O(n), Space = O(1).
 */
#include <stdexcept>
#include <iostream>
using namespace std;

/* reverse string
 * @Description
 *    Takes a string and converts to integer
 * @Pre: String created and passed to function
 * @Post: Integer returned.
 * @Param: str, a string maybe with a number in it
*/
int myAtoi(string str) {
    //loop to remove white space
    int i = 0, sign = 1, base = 0;
    while (str[i] == ' '){
        ++i;
    }//end remove white space

    //then check optional + / -
    if (str[i] == '-' || str[i] == '+'){
        sign = 1 - 2 * (str[i++] == '-'); 
        ++i;
    }//end check for optional + /-

    //while 0 - 9
    while (str[i] >= '0' && str[i] <= '9') {
        //if MAX OR MIN
        if (base > INT_MAX) {
            if (sign == 1){
                 return INT_MAX;     
            }
            else
                return INT_MIN;
        }//end MAX / MIN check
        base = 10 * base + (str[i++] - '0');
    }
        return base * sign;
}//end my atoi


/* main driver
 * @Description
 *    Creates a string and converts to integer.
 * @Pre: None
 * @Post: integer created.
*/
int main () {
   string test = "   -42and some";
   cout << test << endl;
   myAtoi(test);
   cout << test << endl;
   return 0;
}//end main
