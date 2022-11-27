#include"AES.h"
#include<iostream>
using namespace std;
int main(){
    vv_b8 data={
        {0x00,0x01,0xda,0x86},
        {0x01,0xa1,0x78,0x15},
        {0x00,0x98,0x17,0x35},
        {0x01,0xaf,0x34,0x66}
    };
    vv_b8 key={
        {0x00,0x71,0xda,0x60},
        {0x01,0x01,0x79,0x15},
        {0x20,0x98,0x17,0x35},
        {0x01,0xae,0x14,0x94}
    };
    AES a;
    a.XOR(data,key);
    cout<<hex;
    auto ret=a.KeyExpansion(key);
    for(int i=0; i<ret.size(); i++){
        for(int col=0; col<ret[i][0].size(); col++){
            for(int row=0; row<ret[i].size(); row++)
            cout<<bitset<8>(ret[i][row][col].to_string()).to_ulong()<<'\t';
        }
        cout<<endl;
    }    
    /*
    for(int i=0; i<ret[0].size(); i++){
        cout<<hex;
        for(int j=0; j<ret.size(); j++){
            cout<<bitset<8>(ret[j][i].to_string()).to_ulong();
        }
    }*/
    return 0;
}