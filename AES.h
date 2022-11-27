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
class AES{
public:
    const static vv_b8 Sbox;
    const static vv_b8 Inverse_Sbox;
    const static vv_b8 Bx;
    const static vv_b8 Inverse_Bx;
    const static v_b8 Rcon;
    vv_b8 ByteSub(const vv_b8& input)const;
    vv_b8 Inverse_ByteSub(const vv_b8& input)const;
    vv_b8 Shift_Row(vv_b8& input)const;
    vv_b8 Inverse_Shift_Row(vv_b8& input)const;
    void XOR(vv_b8& input, const vv_b8&key)const;
    b_8 xtime(const b_8 &x, const b_8 &data)const;
    void MixColumn(vv_b8 &data);
    void Inverse_MixColumn(vv_b8 &data);
    vvv_b8 KeyExpansion(const vv_b8& init_key)const;
private:
    void KeyExpansion_Nk6(v_b8& ret,const vv_b8& init_key)const;
    void KeyExpansion_NK6Plus(v_b8&ret,const vv_b8& init_key)const;
    void XOR_Word(v_b8 &ret, int pos,const int &Nk)const;
    v_b8 Rotl(const v_b8 &ret,int pos,const int &Nk)const;
};
#endif