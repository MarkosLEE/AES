#ifndef AES_H
#define AES_H
#include<vector>
#include<bitset>
using namespace std;
const int length=128;
typedef bitset<8> b_8;
typedef bitset<4> b_4;
typedef vector<vector<b_8>> vv_b8;
class AES{
public:
    const static vv_b8 Sbox;
    const static vv_b8 Inverse_Sbox;
    const static vv_b8 Bx;
    const static vv_b8 Inverse_Bx;
    vv_b8 ByteSub(const vv_b8& input)const;
    vv_b8 Inverse_ByteSub(const vv_b8& input)const;
    vv_b8 Shift_Row(vv_b8& input)const;
    vv_b8 Inverse_Shift_Row(vv_b8& input)const;
    void XOR(vv_b8& input, const vv_b8&key)const;
    b_8 xtime(const b_8 &x, const b_8 &data)const;
    void MixColumn(vv_b8 &data);
    void Inverse_MixColumn(vv_b8 &data);
};
#endif