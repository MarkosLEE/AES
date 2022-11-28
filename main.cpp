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
    //a.XOR(data,key);
    cout<<hex;
    //cout<<b_8(0x57)<<'\t';
    //a.xtime(7,b_8(0x57));
    //cout<<a.mul(b_8(0x63),b_8(0x02))<<endl;
    //v_b8 d={0x63,0xe0,0x63,0x89};
    //auto temp=a.mul(a.Bx[0][0],d[0])^a.mul(a.Bx[0][1],d[1])^a.mul(a.Bx[0][2],d[2])^a.mul(a.Bx[0][3],d[3]);
    // for(int i=0; i<4; i++){
    //     cout<<a.Bx[0][i]<<'\t'<<d[i]<<endl;
    //     cout<<a.mul(a.Bx[0][i],d[i])<<endl;
    // }
    //a.display(temp);
    a.Encryption(data,key);
    a.display(data);
    a.Decryption(data,key);
    a.display(data);
    //auto ret=a.KeyExpansion(key);
    // for(int i=0; i<ret.size(); i++){
    //     for(int col=0; col<ret[i][0].size(); col++){
    //         for(int row=0; row<ret[i].size(); row++)
    //         cout<<bitset<8>(ret[i][row][col].to_string()).to_ulong()<<'\t';
    //     }
    //     cout<<endl;
    // }    
    /*
    for(int i=0; i<ret[0].size(); i++){
        cout<<hex;
        for(int j=0; j<ret.size(); j++){
            cout<<bitset<8>(ret[j][i].to_string()).to_ulong();
        }
    }*/
    return 0;
}