#ifndef AES_H
#define AES_H
#include<vector>
#include<bitset>
using namespace std;
const int length=128;
typedef bitset<8> b_8;
typedef bitset<4> b_4;
typedef vector<b_8> v_b8;
typedef vector<v_b8> vv_b8;
typedef vector<vv_b8> vvv_b8;
struct Pos
{
     int state_row,state_col,pos;//改变的明文的位置，行号列号，以及8位中的位置
};

class AES{
public:
    const static vv_b8 Sbox;
    const static vv_b8 Inverse_Sbox;
    const static vv_b8 Bx;
    const static vv_b8 Inverse_Bx;
    const static v_b8 Rc;
    vv_b8 ByteSub(const vv_b8& input)const;
    vv_b8 Inverse_ByteSub(const vv_b8& input)const;
    vv_b8 Shift_Row(vv_b8& input)const;
    vv_b8 Inverse_Shift_Row(vv_b8& input)const;
    void XOR(vv_b8& input, const vv_b8&key)const;
    b_8 xtime(int times, const b_8 &data)const;
    void MixColumn(vv_b8 &data)const;
    void Inverse_MixColumn(vv_b8 &data)const;
    vvv_b8 KeyExpansion(const vv_b8& init_key)const;
    void Inverse_KeyExpansion(vvv_b8& key)const;
    vv_b8 Encryption(const vv_b8&mess,const vv_b8&key)const;
    vv_b8 Decryption(const vv_b8&mess,const vv_b8&key)const;
    void display(const b_8&)const;
    void display(const v_b8&)const;
    void display(const vv_b8&)const;
    b_8 mul(const b_8&,const b_8&)const;
    int Change_Count(vv_b8 &mess,const vv_b8&key,const vv_b8& init_ciphertest,const Pos& p)const;
    void Change_Mess(vv_b8&data,const vv_b8&key)const;//计算明文改变一位，密文改变的平均位数
    void Chang_Sbox()const;//计算S盒输入改变一位，输出平均改变多少位
    int Search(const b_8&)const;//变换多少次出现输入等于输出
private:
    void KeyExpansion_Nk6(v_b8& ret,const vv_b8& init_key)const;
    void KeyExpansion_NK6Plus(v_b8&ret,const vv_b8& init_key)const;
    void XOR_Word(v_b8 &ret, int pos,const int &Nk)const;
    v_b8 XOR_Word(v_b8&lhs,const v_b8&rhs)const;
    void XOR_Word(v_b8 &ret, int pos,const int &Nk,const v_b8& rhs)const;
    v_b8 Rotl(const v_b8 &ret,int pos,const int &Nk)const;
    void ByteSub_Rotl(v_b8& init)const;

};
b_8 operator^(const b_8&lhs,const b_8&rhs);
#endif