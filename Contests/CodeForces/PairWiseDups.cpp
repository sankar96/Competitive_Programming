/****
 *
 * Description : Pairwise dups sum
 * Created by : Sankaranarayanan G
 * Date : 2018-10-17 16:16:24
 *
 ****/

// The concept here is to use xor operator.
// The beauty of XOR is if u XOR 2 same nos, u get 0, if different number, u get  some value

// 0^0 = 0, 1^1 = 0
// 1^0 = 1

// So 4 ^ 4 = 0 (write it in binary and find it for urself)

// But 3 ^ 5 = 0011 ^ 0101 = 0110 which is 6

// Anyway, since the qn says every element except 1 is guaranteed to appear twice, we can just XOR
// all the elements in the array. So all the pairwise occuring elements will XOR with each other And
// they cancel each other. Only the remaining single element is stored in the final answer.


#include <iostream>
using namespace std;

int main () {
    int n;
    
    if (n=0)
        cout << "true"
    return 0;
}