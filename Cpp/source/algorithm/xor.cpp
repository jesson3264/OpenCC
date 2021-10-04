/*******************************************************************************
    XOR.cpp
     
    This function takes in two strings (value,key) and uses XOR encryption to
    encrypt (and decrypt) the value using the key.  it returns the encrypted
    value as a C++ string.
     
    John Shao
    
For more on XOR encryption: http://www.cprogramming.com/tutorial/xor.html 
********************************************************************************
    This work is hereby released into the Public Domain. To view a copy of the
    public domain dedication, visit
    http://creativecommons.org/licenses/publicdomain/
 
    or send a letter to
 
    Creative Commons
    559 Nathan Abbott Way
    Stanford, California 94305
    USA.
*******************************************************************************/
#include<iostream>
using std::string;
 
string XOR(string value,string key)
{
    string retval(value);
 
    short unsigned int klen=key.length();
    short unsigned int vlen=value.length();
    short unsigned int k=0;
    short unsigned int v=0;
     
    for(v;v<vlen;v++)
    {
        retval[v]=value[v]^key[k];
        k=(++k<klen?k:0);
    }
     
    return retval;
}

/******************************************************************************/
/*                         Here's a Test Program                              */
/******************************************************************************/
/*
#include<iostream>
 
int main()
{
    std::string value("Hello World");
    std::string key("key");
     
    std::cout<<"Plain text: "<<value<<"\n\n";
    value=XOR(value,key);
    std::cout<<"Cipher text: "<<value<<"\n\n";
    value=XOR(value,key);
    std::cout<<"Decrypted text: "<<value<<std::endl;
     
    std::cin.get();
    return 0;
}
*/