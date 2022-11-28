#include"AES.h"
#include<iostream>
//S盒
const  vv_b8 AES::Sbox={
{0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76},
{0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0},
{0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15},
{0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75},
{0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84},
{0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf},
{0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8},
{0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2},
{0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73},
{0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb},
{0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79},
{0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08},
{0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a},
{0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e},
{0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf},
{0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16}
};

//逆S盒
const vv_b8 AES::Inverse_Sbox={
{0x52,0x09,0x6a,0xd5,0x30,0x36,0xa5,0x38,0xbf,0x40,0xa3,0x9e,0x81,0xf3,0xd7,0xfb},
{0x7c,0xe3,0x39,0x82,0x9b,0x2f,0xff,0x87,0x34,0x8e,0x43,0x44,0xc4,0xde,0xe9,0xcb},
{0x54,0x7b,0x94,0x32,0xa6,0xc2,0x23,0x3d,0xee,0x4c,0x95,0x0b,0x42,0xfa,0xc3,0x4e},
{0x08,0x2e,0xa1,0x66,0x28,0xd9,0x24,0xb2,0x76,0x5b,0xa2,0x49,0x6d,0x8b,0xd1,0x25},
{0x72,0xf8,0xf6,0x64,0x86,0x68,0x98,0x16,0xd4,0xa4,0x5c,0xcc,0x5d,0x65,0xb6,0x92},
{0x6c,0x70,0x48,0x50,0xfd,0xed,0xb9,0xda,0x5e,0x15,0x46,0x57,0xa7,0x8d,0x9d,0x84},
{0x90,0xd8,0xab,0x00,0x8c,0xbc,0xd3,0x0a,0xf7,0xe4,0x58,0x05,0xb8,0xb3,0x45,0x06},
{0xd0,0x2c,0x1e,0x8f,0xca,0x3f,0x0f,0x02,0xc1,0xaf,0xbd,0x03,0x01,0x13,0x8a,0x6b},
{0x3a,0x91,0x11,0x41,0x4f,0x67,0xdc,0xea,0x97,0xf2,0xcf,0xce,0xf0,0xb4,0xe6,0x73},
{0x96,0xac,0x74,0x22,0xe7,0xad,0x35,0x85,0xe2,0xf9,0x37,0xe8,0x1c,0x75,0xdf,0x6e},
{0x47,0xf1,0x1a,0x71,0x1d,0x29,0xc5,0x89,0x6f,0xb7,0x62,0x0e,0xaa,0x18,0xbe,0x1b},
{0xfc,0x56,0x3e,0x4b,0xc6,0xd2,0x79,0x20,0x9a,0xdb,0xc0,0xfe,0x78,0xcd,0x5a,0xf4},
{0x1f,0xdd,0xa8,0x33,0x88,0x07,0xc7,0x31,0xb1,0x12,0x10,0x59,0x27,0x80,0xec,0x5f},
{0x60,0x51,0x7f,0xa9,0x19,0xb5,0x4a,0x0d,0x2d,0xe5,0x7a,0x9f,0x93,0xc9,0x9c,0xef},
{0xa0,0xe0,0x3b,0x4d,0xae,0x2a,0xf5,0xb0,0xc8,0xeb,0xbb,0x3c,0x83,0x53,0x99,0x61},
{0x17,0x2b,0x04,0x7e,0xba,0x77,0xd6,0x26,0xe1,0x69,0x14,0x63,0x55,0x21,0x0c,0x7d}
};


//行混淆矩阵
const vv_b8 AES::Bx={
    {0x02,0x03,0x01,0x01},
    {0x01,0x02,0x03,0x01},
    {0x01,0x01,0x02,0x03},
    {0x03,0x01,0x01,0x02}
};
//行混淆逆变换矩阵
const vv_b8 AES::Inverse_Bx={
    {0x0e,0x0b,0x0d,0x09},
    {0x09,0x0e,0x0b,0x0d},
    {0x0d,0x09,0x0e,0x0b},
    {0x0b,0x0d,0x09,0x0e}
};

const v_b8 AES::Rc={
    0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80,0x1B,0x36
};
//S盒变换
vv_b8 AES::ByteSub(const vv_b8& input)const{
    vv_b8 ret(4,v_b8 (length/8/4));
    for(int i=0; i<4; i++){
        for(int j=0; j<length/8/4; j++){
            auto row=b_4(input[i][j].to_string().substr(0,4)).to_ulong();
            auto col=b_4(input[i][j].to_string().substr(4,8)).to_ulong();

            ret[i][j]=b_8(Sbox[row][col]);
        }
    }
    return ret;
};

//逆S盒变换
vv_b8 AES::Inverse_ByteSub(const vv_b8& input)const{
    vv_b8 ret(4,v_b8 (length/8/4));
    for(int i=0; i<4; i++){
        for(int j=0; j<length/8/4; j++){
            auto row=b_4(input[i][j].to_string().substr(0,4)).to_ulong();
            auto col=b_4(input[i][j].to_string().substr(4,8)).to_ulong();

            ret[i][j]=b_8(Inverse_Sbox[row][col]);
        }
    }
    return ret;
};

//行位移
vv_b8 AES::Shift_Row(vv_b8&input)const{
    vv_b8 ret(4,v_b8 (length/8/4));
    for(int i=0; i<4; i++){
        v_b8 temp(length/8/4);
        for(int j=0; j<length/8/4; j++){
            temp[j]=input[i][(j+i)%(length/8/4)];
        }
        ret[i]=temp;
    }
    return ret;
}

//逆行位移
vv_b8 AES::Inverse_Shift_Row(vv_b8&input)const{
    vv_b8 ret(4,v_b8 (length/8/4));
    for(int i=0; i<4; i++){
        v_b8 temp(length/8/4);
        for(int j=0; j<length/8/4; j++){
            temp[j]=input[i][(j-i+length/8/4)%(length/8/4)];
        }
        ret[i]=temp;
    }
    return ret;
}

//轮密钥加密
void AES::XOR(vv_b8& input, const vv_b8&key)const{
    for(int i=0; i<input.size(); i++){
        for(int j=0;j<input[0].size(); j++){
            input[i][j]=input[i][j]^key[i][j];
        }
    }
}

//xtime函数，times是乘的x的次数
b_8 AES::xtime(int times, const b_8 &data)const{
    b_8 ret(data);
    //if(times==0)return 0;
    while(times!=0){
        if(ret[7]==0){
            ret=ret<<1;
        }
        else{
            ret=ret<<1;
            ret=ret^b_8(27);
        }
        times--;
        //cout<<ret<<endl;
    }
    return ret;
}
//有限域上的乘法
b_8 AES::mul(const b_8&data,const b_8&x)const{
    b_8 ret(0);
    int count=0;
    int times=x.to_ulong();
    while(times!=0){
        if(times%2==1){
            auto m=xtime(count,data);
            //cout<<m<<'\t'<<count<<endl;
            ret=ret^m;
        }
        times=times/2;
        count++;
    }
    return ret;
}
//列混淆
void AES::MixColumn(vv_b8 &data)const{
    v_b8  temp(4);
    for(int i=0; i<data[0].size(); i++){
        temp[0]=mul(Bx[0][0],data[0][i])^mul(Bx[0][1],data[1][i])^mul(Bx[0][2],data[2][i])^mul(Bx[0][3],data[3][i]);
        temp[1]=mul(Bx[1][0],data[0][i])^mul(Bx[1][1],data[1][i])^mul(Bx[1][2],data[2][i])^mul(Bx[1][3],data[3][i]);
        temp[2]=mul(Bx[2][0],data[0][i])^mul(Bx[2][1],data[1][i])^mul(Bx[2][2],data[2][i])^mul(Bx[2][3],data[3][i]);
        temp[3]=mul(Bx[3][0],data[0][i])^mul(Bx[3][1],data[1][i])^mul(Bx[3][2],data[2][i])^mul(Bx[3][3],data[3][i]);       
        data[0][i]=temp[0];
        data[1][i]=temp[1];
        data[2][i]=temp[2];
        data[3][i]=temp[3];
    }
}
//列混淆逆变换
void AES::Inverse_MixColumn(vv_b8 &data)const{
    v_b8  temp(4);
    for(int i=0; i<data[0].size(); i++){
        temp[0]=mul(Inverse_Bx[0][0],data[0][i])^mul(Inverse_Bx[0][1],data[1][i])^mul(Inverse_Bx[0][2],data[2][i])^mul(Inverse_Bx[0][3],data[3][i]);
        temp[1]=mul(Inverse_Bx[1][0],data[0][i])^mul(Inverse_Bx[1][1],data[1][i])^mul(Inverse_Bx[1][2],data[2][i])^mul(Inverse_Bx[1][3],data[3][i]);
        temp[2]=mul(Inverse_Bx[2][0],data[0][i])^mul(Inverse_Bx[2][1],data[1][i])^mul(Inverse_Bx[2][2],data[2][i])^mul(Inverse_Bx[2][3],data[3][i]);
        temp[3]=mul(Inverse_Bx[3][0],data[0][i])^mul(Inverse_Bx[3][1],data[1][i])^mul(Inverse_Bx[3][2],data[2][i])^mul(Inverse_Bx[3][3],data[3][i]);       
        data[0][i]=temp[0];
        data[1][i]=temp[1];
        data[2][i]=temp[2];
        data[3][i]=temp[3];
    }
}

//秘钥扩展
vvv_b8 AES::KeyExpansion(const vv_b8& init_key)const{
    vvv_b8 ret(11,vv_b8 (4,v_b8(length/8/4)));
    ret[0]=init_key;
    v_b8 temp(11*length/8);
    int Nk=length/8/4;
    if(Nk<=6)KeyExpansion_Nk6(temp,init_key);
    else KeyExpansion_NK6Plus(temp,init_key);
    int count=16;
    for(int i=1; i<11; i++){
        for(int col=0; col<ret[i].size(); col++){
            for(int row=0; row<ret[i][0].size(); row++){
                ret[i][row][col]=temp[count];
                count++;
            }
        }
    }
    return ret;
}

//列数少于等于6时的扩展方法
void AES::KeyExpansion_Nk6(v_b8 &ret,const vv_b8& init_key)const{
    int count=0;
    int Nk=length/8/4;
    for(int i=0; i<init_key[0].size(); i++){
        for(int j=0; j<4; j++){
            ret[count]=init_key[j][i];
            count++;
        }
    }
    //代表当前第几个字（四个字节为一个字）
    count=count/4;
    for(; count*4<11*length/8; count++){
        if(count%Nk==0){
            v_b8 temp=Rotl(ret,count,Nk);
            ByteSub_Rotl(temp);
            auto rc=b_8(0x01)<<(count/Nk-1);
            //rc=rc>>1;
            v_b8 Rcon={
                Rc[count/Nk-1],0x00,0x00,0x00
            };
            auto rhs=XOR_Word(temp,Rcon);
            XOR_Word(ret,count*4,Nk,rhs);
        }
        else{
            XOR_Word(ret,count*4,Nk);
        }
    }
}

//列数大于6时的扩展方法
void AES::KeyExpansion_NK6Plus(v_b8 &ret,const vv_b8& init_key)const{}
//解密秘钥扩展
void AES::Inverse_KeyExpansion(vvv_b8& key)const{
    for(int i=1; i<key.size()-1; i++)
        Inverse_MixColumn(key[i]);
};
//异或运算，j不是Nk整数倍时的
void AES::XOR_Word(v_b8 &ret,int pos,const int &Nk)const{
    for(int i=0; i<4; i++){
        ret[i+pos]=ret[i+pos-4]^ret[i+pos-Nk*4];
    }
}
//最通用的异或运算
v_b8 AES::XOR_Word( v_b8 &lhs, const v_b8 &rhs)const{
    v_b8 ret(lhs.size());
    for(int i=0; i<lhs.size(); i++){
        ret[i]=lhs[i]^rhs[i];
    }
    return ret;
}
//Rotl运算
v_b8 AES::Rotl(const v_b8 &ret,int pos,const int &Nk)const{
    v_b8 temp(4);
    for(int i=0; i<4; i++){
        temp[i]=ret[(pos-1)*4+(i+1)%4];
        //cout<<hex<<bitset<8>(temp[i].to_string()).to_ulong()<<endl;
    }
    return temp;
}
//异或运算
void AES::XOR_Word(v_b8 &ret, int pos,const int &Nk,const v_b8& rhs)const{
    for(int i=0; i<rhs.size(); i++){
        ret[i+pos]=ret[i+pos-Nk*4]^rhs[i];
    }
}
//用于对任意字节数组进行S盒变换
void AES::ByteSub_Rotl(v_b8& init)const{
    for(int i=0; i<init.size(); i++){
        auto row=b_4(init[i].to_string().substr(0,4)).to_ulong();
        auto col=b_4(init[i].to_string().substr(4,8)).to_ulong();
        init[i]=Sbox[row][col];
    }
}

//输出一个b_8的数
void AES::display(const b_8&data)const{
    cout<<hex<<bitset<8>(data.to_string()).to_ulong()<<'\t';
}
void AES::display(const v_b8&data)const{
    for(int i=0; i<data.size(); i++)
        display(data[i]);
    cout<<endl;
}
void AES::display(const vv_b8&data)const{
    for(int i=0; i<data[0].size(); i++){
        for(int j=0; j<data.size(); j++)
            display(data[j][i]);
    }
    cout<<endl;
}
//运算符重载
b_8 operator^(const b_8&lhs,const b_8&rhs){
    b_8 ret;
    for(int i=0; i<8; i++){
        ret[i]=lhs[i]^rhs[i];
    }
    return ret;
}

//加密
void AES::Encryption(vv_b8&mess,const vv_b8&key)const{
    auto Expansion_Key=KeyExpansion(key);
    XOR(mess,Expansion_Key[0]);
    //cout<<"第0轮"<<endl;
    //display(mess);
    for(int i=1; i<10; i++){
        cout<<"第"<<i<<"轮:"<<endl;
        mess=ByteSub(mess);
        //display(mess);
        mess=Shift_Row(mess);
        //display(mess);
        MixColumn(mess);
        //display(mess);
        XOR(mess,Expansion_Key[i]);
        //display(mess);
    }
    mess=ByteSub(mess);
    //display(mess);
    mess=Shift_Row(mess);
    //display(mess);
    XOR(mess,Expansion_Key[10]);
    //display(mess);
}
//解密
void AES::Decryption(vv_b8&mess,const vv_b8&key)const{
    //cout<<"第0轮"<<endl;
    auto Expansion_Key=KeyExpansion(key);
    Inverse_KeyExpansion(Expansion_Key);
    XOR(mess,Expansion_Key[10]);
    //display(mess);
    //display(Expansion_Key[10]);
    for(int i=9; i>0; i--){
        //cout<<i<<endl;
        mess=Inverse_ByteSub(mess);
        //display(mess);
        mess=Inverse_Shift_Row(mess);
        //display(mess);
        Inverse_MixColumn(mess);
        //display(mess);
        XOR(mess,Expansion_Key[i]);
        //display(Expansion_Key[i]);
        //display(mess);
    }
    mess=Inverse_ByteSub(mess);
    mess=Inverse_Shift_Row(mess);
    XOR(mess,Expansion_Key[0]);
}