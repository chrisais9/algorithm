/*
 * ª˘«√ ƒ⁄µÂ ∆ƒ¿œ¿‘¥œ¥Ÿ.
 * BigInteger ≈¨∑°Ω∫∞°
 * int«¸¿Ã ¡ˆø¯«œ¥¬ ø¨ªÍ¿⁄∏¶ ¡¶ø‹«œ∞Ì ¡ˆø¯«œ¥¬
 * √ﬂ∞°¿˚¿Œ «‘ºˆ∏¶ ∫∏¿Ã±‚ ¿ß«ÿ ∏∏µÈæÓ¡≥Ω¿¥œ¥Ÿ.
 * ø©±‚ø° ≥™ø¿¡ˆ æ ¿∫ ¿œπ›¿˚¿∏∑Œ
 * int«¸¿Ã ¡ˆø¯«œ¥¬ ø¨ªÍ¿⁄ (ªÁƒ¢, ∫Ò∆Æ, Ω¨«¡∆Æ, ∫Ò±≥ ...)
 * ¿« ∏µÁ ø¨ªÍ¿⁄¥¬ ∂»∞∞¿Ã ¡ˆø¯«’¥œ¥Ÿ.
 */


#include <iostream>
#include <string>
using namespace std;
#include "BigInteger.h"

int main()
{
    BigInteger a;
    bigint b("2");
    
    a.stob("-123", 10);
    
    cout << a.btos() << endl;
    
    if (a.getsign() == BigInteger::Negative)
        cout << "a¥¬ ¿Ωºˆ±∫ø‰!" << endl;
    
    cout << a.blklength() << endl;
    
    cout << abs(a) << endl;
    
    cout << -a << endl;
    
    cout << pow(a, b) << endl;
    
    cout << factorial(a) << endl;
    
    a = 123;
    cout << gcd(a, b) << endl;
    
    cout << lcm(a, b) << endl;
    
    return 0;
}
