#include "decode.h"
#include <qDebug>
void decode(QByteArray base64,QString *md5key,QString *date)
{
    char  key[]="816901";

    uchar decode_source[50]={0};
    uchar *result1;
    result1=(uchar*)(QByteArray::fromBase64(base64).data());
    get_DES_ecb3_encrypt(result1,48,key,0,decode_source);

    QString str=QString::fromUtf8(reinterpret_cast<char *>(decode_source), 40);
    //qDebug()<<"str"<<str;
    *md5key=str.left(32);
    *date=str.right(8);
}



int get_DES_ecb3_encrypt(unsigned char *pdata,int pdata_len,char *pkey,int des3_enc,unsigned char *pout)
{

    int i = 0;
    int len = 0;
//   int nlen = 0;
    int klen = 0;
    char ch = '\0';


    unsigned char key[LEN_OF_KEY];
    unsigned char block[8] = {0};
    unsigned char src[1024] = {0};
    DES_key_schedule ks1, ks2, ks3;


    klen = strlen(pkey);
    memcpy(key, pkey, klen);
    memset(key + klen, 0x00, LEN_OF_KEY - klen);

    memcpy(block, key, sizeof(block));
    DES_set_key_unchecked((const_DES_cblock *)block, &ks1);

    memcpy(block, key + 8, sizeof(block));
    DES_set_key_unchecked((const_DES_cblock *)block, &ks2);

    memcpy(block, key + 16, sizeof(block));
    DES_set_key_unchecked((const_DES_cblock *)block, &ks3);

   // pdata_len = strlen(pdata);//pdata_len <1024
    memcpy(src, pdata, pdata_len);

    len = (pdata_len / 8 + 1) * 8;

    ch = 8 - pdata_len % 8;
     memset(src + pdata_len, ch, (8 - pdata_len % 8));

    if(des3_enc){
        for (i = 0; i < len; i += 8) {
            DES_ecb3_encrypt((const_DES_cblock *)(src + i), (DES_cblock *)(pout + i), &ks1, &ks2, &ks3, DES_ENCRYPT);//pout is hex data
        }
    }else{
        for (i = 0; i < len; i += 8){
            DES_ecb3_encrypt((const_DES_cblock *)(src + i), (DES_cblock *)(pout + i), &ks1, &ks2, &ks3, DES_DECRYPT);
        }
    }
    int des3_len =  (pdata_len / 8 + 1) * 8;
    return des3_len;
}



void DES_set_key_unchecked(const_DES_cblock *key, DES_key_schedule *schedule)
{
    static const int shifts2[16] =
        { 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0 };
    register DES_LONG c, d, t, s, t2;
    register const unsigned char *in;
    register DES_LONG *k;
    register int i;


    k = &schedule->ks->deslong[0];
    in = &(*key)[0];

    c2l(in, c);
    c2l(in, d);

    PERM_OP(d, c, t, 4, 0x0f0f0f0fL);
    HPERM_OP(c, t, -2, 0xcccc0000L);
    HPERM_OP(d, t, -2, 0xcccc0000L);
    PERM_OP(d, c, t, 1, 0x55555555L);
    PERM_OP(c, d, t, 8, 0x00ff00ffL);
    PERM_OP(d, c, t, 1, 0x55555555L);
    d = (((d & 0x000000ffL) << 16L) | (d & 0x0000ff00L) |
         ((d & 0x00ff0000L) >> 16L) | ((c & 0xf0000000L) >> 4L));
    c &= 0x0fffffffL;

    for (i = 0; i < ITERATIONS; i++) {
        if (shifts2[i]) {
            c = ((c >> 2L) | (c << 26L));
            d = ((d >> 2L) | (d << 26L));
        } else {
            c = ((c >> 1L) | (c << 27L));
            d = ((d >> 1L) | (d << 27L));
        }
        c &= 0x0fffffffL;
        d &= 0x0fffffffL;

        s = des_skb[0][(c) & 0x3f] |
            des_skb[1][((c >> 6L) & 0x03) | ((c >> 7L) & 0x3c)] |
            des_skb[2][((c >> 13L) & 0x0f) | ((c >> 14L) & 0x30)] |
            des_skb[3][((c >> 20L) & 0x01) | ((c >> 21L) & 0x06) |
                       ((c >> 22L) & 0x38)];
        t = des_skb[4][(d) & 0x3f] |
            des_skb[5][((d >> 7L) & 0x03) | ((d >> 8L) & 0x3c)] |
            des_skb[6][(d >> 15L) & 0x3f] |
            des_skb[7][((d >> 21L) & 0x0f) | ((d >> 22L) & 0x30)];


        t2 = ((t << 16L) | (s & 0x0000ffffL)) & 0xffffffffL;
        *(k++) = ROTATE(t2, 30) & 0xffffffffL;

        t2 = ((s >> 16L) | (t & 0xffff0000L));
        *(k++) = ROTATE(t2, 26) & 0xffffffffL;
    }
}


void DES_ecb3_encrypt(const_DES_cblock *input, DES_cblock *output,
                      DES_key_schedule *ks1, DES_key_schedule *ks2,
                      DES_key_schedule *ks3, int enc)
{
    register DES_LONG l0, l1;
    DES_LONG ll[2];
    const unsigned char *in = &(*input)[0];
    unsigned char *out = &(*output)[0];

    c2l(in, l0);
    c2l(in, l1);
    ll[0] = l0;
    ll[1] = l1;

    if (enc)
        DES_encrypt3(ll, ks1, ks2, ks3);
    else
        DES_decrypt3(ll, ks1, ks2, ks3);
    l0 = ll[0];
    l1 = ll[1];
    l2c(l0, out);
    l2c(l1, out);
}


void DES_encrypt1(DES_LONG *data, DES_key_schedule *ks, int enc)
{
    register DES_LONG l, r, t, u;

    register int i;
    register DES_LONG *s;

    r = data[0];
    l = data[1];

    IP(r, l);

    r = ROTATE(r, 29) & 0xffffffffL;
    l = ROTATE(l, 29) & 0xffffffffL;

    s = ks->ks->deslong;

    if (enc) {

        for (i = 0; i < 32; i += 4) {
            D_ENCRYPT(l, r, i + 0);
            D_ENCRYPT(r, l, i + 2);
        }
    } else {

        for (i = 30; i > 0; i -= 4) {
            D_ENCRYPT(l, r, i - 0);
            D_ENCRYPT(r, l, i - 2);
        }
    }

    l = ROTATE(l, 3) & 0xffffffffL;
    r = ROTATE(r, 3) & 0xffffffffL;

    FP(r, l);
    data[0] = l;
    data[1] = r;
    l = r = t = u = 0;
}

void DES_encrypt2(DES_LONG *data, DES_key_schedule *ks, int enc)
{
    register DES_LONG l, r, t, u;

    register int i;
    register DES_LONG *s;

    r = data[0];
    l = data[1];


    r = ROTATE(r, 29) & 0xffffffffL;
    l = ROTATE(l, 29) & 0xffffffffL;

    s = ks->ks->deslong;

    if (enc) {

        for (i = 0; i < 32; i += 4) {
            D_ENCRYPT(l, r, i + 0);
            D_ENCRYPT(r, l, i + 2);
        }

    } else {

        for (i = 30; i > 0; i -= 4) {
            D_ENCRYPT(l, r, i - 0);
            D_ENCRYPT(r, l, i - 2);
        }

    }
    data[0] = ROTATE(l, 3) & 0xffffffffL;
    data[1] = ROTATE(r, 3) & 0xffffffffL;
    l = r = t = u = 0;
}

void DES_encrypt3(DES_LONG *data, DES_key_schedule *ks1,
                  DES_key_schedule *ks2, DES_key_schedule *ks3)
{
    register DES_LONG l, r;

    l = data[0];
    r = data[1];
    IP(l, r);
    data[0] = l;
    data[1] = r;
    DES_encrypt2((DES_LONG *)data, ks1, DES_ENCRYPT);
    DES_encrypt2((DES_LONG *)data, ks2, DES_DECRYPT);
    DES_encrypt2((DES_LONG *)data, ks3, DES_ENCRYPT);
    l = data[0];
    r = data[1];
    FP(r, l);
    data[0] = l;
    data[1] = r;
}

void DES_decrypt3(DES_LONG *data, DES_key_schedule *ks1,
                  DES_key_schedule *ks2, DES_key_schedule *ks3)
{
    register DES_LONG l, r;

    l = data[0];
    r = data[1];
    IP(l, r);
    data[0] = l;
    data[1] = r;
    DES_encrypt2((DES_LONG *)data, ks3, DES_DECRYPT);
    DES_encrypt2((DES_LONG *)data, ks2, DES_ENCRYPT);
    DES_encrypt2((DES_LONG *)data, ks1, DES_DECRYPT);
    l = data[0];
    r = data[1];
    FP(r, l);
    data[0] = l;
    data[1] = r;
}
