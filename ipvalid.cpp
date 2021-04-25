
// Program to check if a given
// string is valid IPv4 address or not
#include <bits/stdc++.h>
#include <arpa/inet.h>
#include<netinet/in.h>
using namespace std;
#define DELIM "."
 
/* function to check whether the
   string passed is valid or not */
bool valid_part(char* s)
{
    int n = strlen(s);
     
    // if length of passed string is
    // more than 3 then it is not valid
    if (n > 3)
        return false;
     
    // check if the string only contains digits
    // if not then return false
    for (int i = 0; i < n; i++)
        if ((s[i] >= '0' && s[i] <= '9') == false)
            return false;
    string str(s);
     
    // if the string is "00" or "001" or
    // "05" etc then it is not valid
    if (str.find('0') == 0 && n > 1)
        return false;
    stringstream geek(str);
    int x;
    geek >> x;
     
    // the string is valid if the number
    // generated is between 0 to 255
    return (x >= 0 && x <= 255);
}
 
/* return 1 if IP string is
valid, else return 0 */
int is_valid_ip(char* ip_str)
{
    // if empty string then return false
    if (ip_str == NULL)
        return 0;
    int i, num, dots = 0;
    int len = strlen(ip_str);
    int count = 0;
     
    // the number dots in the original
    // string should be 3
    // for it to be valid
    for (int i = 0; i < len; i++)
        if (ip_str[i] == '.')
            count++;
    if (count != 3)
        return false;
     
    // See following link for strtok()
   
    char *ptr = strtok(ip_str, DELIM);
    if (ptr == NULL)
        return 0;
 
    while (ptr) {
 
        /* after parsing string, it must be valid */
        if (valid_part(ptr))
        {
            /* parse remaining string */
            ptr = strtok(NULL, ".");
            if (ptr != NULL)
                ++dots;
        }
        else
            return 0;
    }
 
    /* valid IP string must contain 3 dots */
    // this is for the cases such as 1...1 where
    // originally the no. of dots is three but
    // after iteration of the string we find
    // it is not valid
    if (dots != 3)
        return 0;
    return 1;
}

string ip_to_binary(char* ip_str){
        for(int i = 0;i<10;i++){
                if(ip_str[i]!='.'){
                 std::string binary = std::bitset<8>(ip_str[i]).to_string();
                 cout<<binary;
                }
    }


}
 
// Driver code
int main()
{
    char ip1[100];
    while(1){
    cin>>ip1;
    if(is_valid_ip(ip1)){
         cout<<"Valid\n";
        ip_to_binary(ip1);
         break;
    }else {
        cout<<"not valid";
    }
    }
   
    return 0;
}