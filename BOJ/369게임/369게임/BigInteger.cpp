#include "BigInteger.h"
#include <iomanip> // setw 사용

namespace
{
	const BigInteger _One(1);
	const BigInteger _Zero(0);

	const unsigned long N = 32; // blk 한블럭의 비트 길이

	/*
	* radix_a부터 radix_d까지는
	* 입력, 출력 함수에서 사용하기 위해 작성하였고
	* 나오게 된 이론적인 배경은 다음과 같습니다.
	*
	* 일반적으로 2진수로 되있는 값을 10진수로
	* 출력하기 위해서는 2진수 값을 bcd로 바꾼 후, 출력합니다.
	* (여기에 대한 내용은 인터넷에서
	* bcd, binary to bcd, shift and add 3, double dabble
	* 등의 검색어로 다양한 정보를 얻으실 수 있습니다.)
	* 여기서도 물론 같은 방법을 사용하여 출력, 입력을 하며
	* 좀 더 일반적이고 확장된 정리를 사용합니다.
	*
	* "binary to bcd"("2진수를 bcd로")
	* bcd란 간단히 10진법 배열입니다.
	* 0부터 9라는 숫자를 나타내기 위해서는
	* 최소 4비트가 필요하며(2^4=16) 4비트로 10진법의
	* 한자리를 나타낸다는 것이 bcd입니다.
	* 즉, bcd로 바꾼다는 말은 2진수 값을 10진법의 배열로 바꾼다는 이야기이며
	* 이것을 일반화 해본다면 다음과 같습니다.
	*
	* "binary to arbitrary radix"("2진수를 임의의 진법으로")
	* 2진수 값을 n진법으로 출력 하고자 한다면
	* n진법의 배열로 바꾸어주면 됩니다.
	* 그럼 여기서 n진법 배열의 원소는 최소 몇비트가 필요할까요?
	* 우리가 표현하고자 하는 진법은
	* 2~36사이의 진법입니다.
	* 여기서 36진법이 한자리당 필요한 비트수가 제일 많습니다.
	* 최소 6비트가 필요합니다.(2^6=64)
	* 우리가 사용할 수 있는 타입 중 가장 작은 것은 1바이트(8비트)이며
	* 36진법이라고 치면 한 자리당 2비트(8-6=2)를 비효율적으로 사용합니다.
	* 정리하자면 bcd를 일반화 한 것은
	* 2진수 값을 n진법으로 출력하는 방법이며
	* n진법 배열을 사용하여 한자리씩을 표현한다는 것입니다.
	* 그러나 이렇게 한자리씩 끊어서 나타내면
	* 큰수를 입,출력해야 하는 상황에서
	* 메모리가 비효율적으로 낭비 될 뿐만 아니라
	* 1바이트와 같이 작은 비트를 접근하는 연산을 하여 속도도 나지 않습니다.
	* 따라서 여기서 한발 더 나아가
	* 32비트에 최적화 시킵니다.(cpu 비트수)
	*
	* "binary to arbitrary radix in 32bits("2진수를 임의의 진법으로(32비트 최적화)")"
	* 일단, 진법 변환 이야기를 살짝 하겠습니다.
	* 9진법으로 17을 3진법으로 바꾼다면 어떻게 구할까요?
	* 9는 3의 2승입니다. 즉, 9진법의 한자리는 3진법으로 두자리라는 말이 됩니다.
	* (27진법을 3진법으로 나타낸다면 27(3 ^ 3)진법의 한자리는 3진법으로 3자리가 됩니다.)
	* 9진법 1은 3진법으로도 1, 9진법 7은 3진법으로 21입니다.
	* 즉, 3진법으로 121이 됩니다.
	* 여기서 알 수 있는 것은 진법 변환에 있어
	* n진법을 r진법으로 변환한다고 하였을 때(n > r)
	* n진법이 r진법의 지수승으로 나타낼 수 있다면(=> n == r ^ x)
	* n진법의 r진법 변환은 추가적인 나눗셈 연산 없이도
	* 각 자리를 쪼개는 것만으로 변환이 가능하다는 것입니다.
	* 자 이제, 무엇을 해야 할지 감이 오시나요?
	* n의 x승 진법으로 숫자를 저장 한 후,
	* n ^ x승 한자리를 x개의 자리로 쪼개는 전략을 쓰겠다는 겁니다!
	* 그리고 이 전략을 32비트에 최적화 시키는 것입니다!
	* 그럼 과연 n진법의 몇 승 진법을 써야 할까요?
	* 여기에서 radix_a를 구한 이유가 나옵니다.
	* 그 식은 다음과 같습니다.
	* 2^32 >= n ^ x (n진법의 x승)을 만족하는 제일 큰 x
	* 32비트로 나타낼 수 있는 n진법의 최대 승을 구하는 식입니다.
	* 이것을 radix_a라는 배열에 저장해 두었습니다.
	* 그리고 n ^ x 값을 radix_b라는 배열에 저장해 두었구요.
	* 여기까지를 정리해보면
	* 2진수 값을 n진법으로 변환, 출력하는데 있어
	* 32비트에 최적화 시키기 위해서
	* 2진수 값을 n진법의 x승 진법으로 값을 변환한 후,
	* n진법의 x승 진법의 각 자리를 n진법 x개로 쪼개는 식으로
	* 출력한다면 이것은 2진수 값을 n진법으로 표현하는 것과 같다!
	* 라고 정리 할 수 있습니다.
	* 후... 이제 어떻게 해야 하는지 방향은 정했습니다.
	* 근데 중간 과정이 설명되지 않았습니다.
	* 2진수 값을 n ^ x 진법으로 저장한다고 했는데
	* 어떻게 저장할것인가 하는 겁니다.
	*
	* "Shift and Add 3(Double Dabble) algorithm"
	* 진법 변환 하는 방법 아시나요?
	* 10진수를 8진법으로 바꿀려면
	* 8로 나누어서 그 나머지들을 역순으로 쓰면 된다고 배웠습니다.
	* 즉, 어느 수를 n진법으로 바꾼다면 그 수를 n으로 나누어서
	* 그 나머지들을 역순으로 쓰면 됩니다.
	* 이것을 위의 32비트 최적화의 개념에 적용하다면
	* 출력하고자 하는 숫자를 n ^ x로 나누어
	* 그 나머지를 역순으로 저장하면
	* 2진수 값을 n ^ x진법으로 바꾸어 저장할 수 있습니다.
	* 초기 출력 함수의 알고리즘도 그랬습니다.
	* n ^ x로 나누어서 값을 _ltoa_s함수를 사용하여
	* 각 자리를 n진법으로 변환 출력하는 것입니다.
	* 근데, 이 방법은 확실히 느립니다.
	* 곱셈, 나눗셈보다는 덧셈, 뺄셈이 빠르며
	* 덧셈 뺄셈보다는 비트, 쉬프트 연산이 빠릅니다.
	* 여기서 사용할 알고리즘 이름이
	* shift and add 3 알고리즘 같은말로 double dabble 알고리즘(이하 더블대블)입니다.
	* 이름에서와 같이 binary를 bcd로 바꾸는데 쉬프트와 덧셈만을 이용하며
	* 나누어서 나머지를 취하는 방법에 비해서 효율적인 알고리즘입니다.
	*
	* 아래 링크는 위키피디아에 있는 더블대블 알고리즘에 대한 설명글이며
	* http://en.wikipedia.org/wiki/Double_dabble
	*
	* 다음의 링크는 제 블로그에 위의 글을 번역해본 것입니다.
	* http://transparenttape.tistory.com/entry/Double-DabbleShift-and-add-3-Algorithm
	* 더블대블 알고리즘을 잘 모르시겠다면 참고하시기 바랍니다.
	*
	* "Double Dabble algorithm in 32 bits"
	* radix_a를 보면 32비트에는 10진법으로는 9자리를 표현 할 수 있음을 알 수 있습니다.
	* 더블 대블 알고리즘을 이해 하셨다면, 여기도 이해가 될 것입니다.
	* 5이상에 3을 더하던 것을
	* 500000000(5억)이상에 1647483648을 더해주면 됩니다.
	* 5억 이상인 수에 저 숫자를 더한 후, 쉬프트를 해주게 되면 2^32이상이 되어
	* 자리올림이 발생하게 됩니다.
	* 원리는 동일하며, 숫자만 다를뿐입니다.
	*
	* "Double Dabble algorithm in 32 bits for arbitrary radix"
	* 이제 더블대블 알고리즘을 수학적으로 접근해보겠습니다.
	* 5이상인 블럭에는 3을 더해주고 쉬프트 해준다가 이 알고리즘의 핵심입니다.
	*
	* 5, 3이라는 숫자가 나온 이유를 생각해 본다면
	* 5 = 변환하고자 하는 진법의 반    ... (a)
	* 3 = ( (2 ^ 저장되는 블럭의 한블럭의 비트 수) - 변환하고자 하는 진법 )/2    ... (b)
	* 과 같은 식으로 나온것입니다.
	*
	* 5 = 10 / 2
	* 3 = (2^4 - 10) / 2
	*
	* 따라서 저 식대로라면 어느 진법에 대해서든 알고리즘을 적용할 수 있습니다.
	* 하지만, 홀수 진법에서는 (a)식이나 (b)식이나 모두 0.5가 생깁니다.
	* 결과적으로는 홀수 진법일 시에서는, (a)식은 올림, (b)식은 내림 처리합니다.
	* 왜 그래야 하는지는 해당 알고리즘 부분에서 다시 설명하겠습니다.
	* 여기서 (b)식이 radix_c를 구한 식입니다. (a)식은 radix_b를 오른쪽으로 1 쉬프트 하면 되지만
	* (b)식은 조금 복잡하기 때문에 미리 구해놨습니다.
	*
	* 이제 총 정리입니다.
	* 출력을 하는데 있어서 2진수 값을 n진법의 x승 배열에 변환 저장한 후,
	* 각 배열에 저장되어 있는 값을 n진법의 x개의 숫자로 쪼개는 식으로 출력을 할 것이며
	* 여기서 n진법의 x승 배열에 저장하는 방법은 더블대블 알고리즘을
	* 32비트에 최적화, 임의의 진법에도 적용되도록 확장하여 사용한다.
	* 여기까지가 총 정리입니다.
	* 이제 radix_d만 남았습니다.
	* radix_d는 n진법의 x승 배열의 크기를 구하는 식에서부터 도출되었습니다.
	* 2진수로 x자리인 수는 10진수로는
	* x * log10(2) 의 올림값 자리수만큼이 됩니다.
	* 이것을 32비트에 맞춰 생각해보면
	* 2진수 32 * x자리인 수는 10진수로
	* 32 * lgo10(2) * x자리가 됩니다.
	* 여기서 구하고자 하는 것은 10진법 배열의 크기이므로
	* 저 숫자를 9로 나누어 줍니다.
	* 그러면 (32 * lgo10(2) * x) / 9가 되며
	* 이것을 n진법으로 확대하려면 위 식에 log10(n)을 나누어 주면 됩니다.
	* 그래서 다음과 같은 식이 나오며
	* ( ( 32 * log10(2) ) / ( log10(n) * radix_a[n]) ) * x
	* radix_d는 ( 32 * log10(2) ) / ( log10(n) * radix_a[n])을 구하는 식이며
	* 나온 값에 10000을 곱하고 올림 처리 하였습니다.
	*/

	/*
	* 2^32 >= n ^ x (n진법의 x승)
	* 을 만족하는 제일 큰 x를
	* n에 대하여 오름차순으로 정리해놓은것 입니다.
	*/
	const unsigned int radix_a[37] =
	{
		0,  0,
		/* 2 */32, 20, 16, 13, 12,/* 6 */
		/* 7 */11, 10, 10,  9,  9,/* 11 */
		/* 12 */8,  8,  8,  8,  8,/* 16 */
		/* 17 */7,  7,  7,  7,  7,/* 21 */
		/* 22 */7,  7,  6,  6,  6,/* 26 */
		/* 27 */6,  6,  6,  6,  6,/* 31 */
		/* 32 */6,  6,  6,  6,  6 /* 36 */
	};

	/*
	* radix_a를 이용해 미리 구해놓은
	* 2^32 >= n ^ x (n진법의 x승)
	* 을 만족하는 가장 큰  n ^ x로
	* n ^ radix_a[n]을 구해놓은 것입니다.
	*/
	const unsigned __int64 radix_b[37] = 
	{
		0,          0,
		/* 2 */ 4294967296, 3486784401, 4294967296, 1220703125, 2176782336,/* 6 */
		/* 7 */ 1977326743, 1073741824, 3486784401, 1000000000, 2357947691,/* 11 */
		/* 12 */ 429981696,  815730721, 1475789056, 2562890625, 4294967296,/* 16 */
		/* 17 */ 410338673,  612220032,  893871739, 1280000000, 1801088541,/* 21 */
		/* 22 */2494357888, 3404825447,  191102976,  244140625,  308915776,/* 26 */
		/* 27 */ 387420489,  481890304,  594823321,  729000000,  887503681,/* 31 */
		/* 32 */1073741824, 1291467969, 1544804416, 1838265625, 2176782336 /* 36 */
	};

	/*
	* radix_b를 이용해 미리 구해놓은
	* n진법의 
	* "(2^32 - radix_b[n])/2"
	* 을 구하고 내림 한 값입니다.(==소수점 이하 버림)
	*/
	const unsigned long radix_c[37] =
	{
		0,          0,
		/* 2 */          0,  404091447,          0, 1537132085, 1059092480,/* 6 */
		/* 7 */ 1158820276, 1610612736,  404091447, 1647483648,  968509802,/* 11 */
		/* 12 */1932492800, 1739618287, 1409589120,  866038335,          0,/* 16 */
		/* 17 */1942314311, 1841373632, 1700547778, 1507483648, 1246939377,/* 21 */
		/* 22 */ 900304704,  445070924, 2051932160, 2025413335, 1993025760,/* 26 */
		/* 27 */1953773403, 1906538496, 1850071987, 1782983648, 1703731807,/* 31 */
		/* 32 */1610612736, 1501749663, 1375081440, 1228350835, 1059092480 /* 36 */
	};

	/*
	* radix_a를 이용해 미리 구해놓은
	* n진법의
	* ( 32 * log10(2) ) / ( log10(n) * radix_a[n])
	* 을 구한 후, 10000을 곱하고 올림 한 값입니다.(==소수점 이하 올림)
	*/
	const unsigned int radix_d[37] =
	{
		0,     0,
		/* 2 */ 10000, 10095, 10000, 10602, 10317,/* 6 */
		/* 7 */ 10363, 10667, 10095, 10704, 10278,/* 11 */
		/* 12 */11158, 10810, 10506, 10239, 10000,/* 16 */
		/* 17 */11185, 10963, 10762, 10578, 10408,/* 21 */
		/* 22 */10252, 10106, 11633, 11485, 11347,/* 26 */
		/* 27 */11217, 11095, 10979, 10870, 10766,/* 31 */
		/* 32 */10667, 10573, 10484, 10398, 10317 /* 36 */
	};
}
#pragma region 생성/파괴/변환

#pragma region 생성보조함수
void BigInteger::Allocate(length c)
{
	len = c;
	blk = new blocktype[len];
}

void BigInteger::Reallocate(length c)
{
	if (len != c)
	{
		if (blk != NULL)
			delete [] blk;
		Allocate(c);
	}
}

void BigInteger::Blkinit()
{
	memset(blk, 0, len << 2);
}

void BigInteger::Blkcopy(const BigInteger &x)
{
	memcpy(blk, x.blk, x.len << 2);
}
void BigInteger::SetZero()
{
	len = 0;
	blk = NULL;
	sign = Zero;
}
void BigInteger::Reset()
{
	if (blk != NULL)
		delete [] blk;
	SetZero();
}
void BigInteger::ZapLeadingZeros()
{
	while(len > 0 && blk[len-1] == 0)
		len--;
}
#pragma endregion

#pragma region 기본/복사생성/대입연산
BigInteger::BigInteger()
{
	SetZero();
}
BigInteger::~BigInteger()
{
	if (blk != NULL)
		delete [] blk;
}
BigInteger::BigInteger(const BigInteger &x)
{
	if (x.sign == Zero)
		SetZero();
	else
	{
		Allocate(x.len);
		Blkcopy(x);
		sign = x.sign;
	}
}
BigInteger & BigInteger::operator =(const BigInteger &x)
{
	if (this != &x)
	{
		if (x.sign == Zero)
			SetZero();
		else
		{
			Reallocate(x.len);
			Blkcopy(x);
			sign = x.sign;
		}
	}
	return *this;
}

#pragma endregion

#pragma region 기본형으로부터생성/변환
BigInteger::BigInteger(           bool    x)
{
	if (x == true)
	{
		Allocate(1);
		blk[0] = 1;
		sign = Positive;
	}
	else
		SetZero();
}
BigInteger::BigInteger(unsigned   char    x) { ConversionAssist1<unsigned char> (x); }
BigInteger::BigInteger(           char    x) { ConversionAssist2         <char> (x); }
BigInteger::BigInteger(unsigned   short   x) { ConversionAssist1<unsigned short>(x); }
BigInteger::BigInteger(           short   x) { ConversionAssist2         <short>(x); }
BigInteger::BigInteger(unsigned   long    x) { ConversionAssist1<unsigned long> (x); }
BigInteger::BigInteger(           long    x) { ConversionAssist2         <long> (x); }
BigInteger::BigInteger(unsigned   int     x)
{
	if (sizeof(x) == 4)
		ConversionAssist1<unsigned int>  (x);
	else
		ConversionAssist1<unsigned long long>(x);
}
BigInteger::BigInteger(           int     x)
{
	if (sizeof(x) == 4)
		ConversionAssist2         <int>  (x);
	else
		ConversionAssist2<long long>(x);
}
BigInteger::BigInteger(unsigned   long long x) { ConversionAssist1<unsigned long long>(x);}
BigInteger::BigInteger(			long long x) { ConversionAssist2<long long>(x);}


BigInteger::operator		  bool   () const
{
	if (sign == Zero)
		return false;
	return true;
}
BigInteger::operator unsigned char   () const {return ConversionAssist3<unsigned char>  ();}
BigInteger::operator		  char   () const {return ConversionAssist4		    <char>  ();}
BigInteger::operator unsigned short  () const {return ConversionAssist3<unsigned short> ();}
BigInteger::operator		  short  () const {return ConversionAssist4		    <short> ();}
BigInteger::operator unsigned long   () const {return ConversionAssist3<unsigned long>  ();}
BigInteger::operator		  long   () const {return ConversionAssist4		    <long>  ();}
BigInteger::operator unsigned int    () const {return ConversionAssist3<unsigned int>   ();}
BigInteger::operator		  int    () const {return ConversionAssist4		    <int>   ();}
BigInteger::operator unsigned long long() const
{
	unsigned __int64 x = 0;
	if (sign == Zero)
		return x;
	else if (sign == Negative)
	{
#if defined(_DEBUG)
		throw "음수를 Unsigned로 바꿀 수 없습니다.";
#else
		return x;
#endif
	}
	else if (len <= 2)
	{
		x = blk[0];
		if (len == 1) return x;
		x += unsigned __int64(blk[1]) << N;
		return x;
	}
#if defined(_DEBUG)
	throw "값이 너무 커서 변환 할 수 없습니다.";
#else
	return x;
#endif
}
BigInteger::operator		 long long() const
{
	__int64 x = 0;
	if (sign == Zero)
		return x;
	else if (len <= 2)
	{
		x = blk[0];
		if (len == 2 && !(blk[1] >> 31) )
			x += __int64(blk[1]) << N;
	}

#if defined(_DEBUG)
	else
	{
		throw "값이 너무 커서 변환 할 수 없습니다.";
	}
#endif
	return (sign == Positive) ? x : -x;
}
#pragma endregion

#pragma region 문자열로부터 생성/변환
void BigInteger::DoubleDabble(BigInteger &dest, int radix) const
{
	if ( !( radix >=2 && radix <=36 ) )
	{
#if defined(_DEBUG)
		throw "2 ~ 36진법까지만 가능합니다.";
#else
		return;
#endif
	}
	// 0은 이 함수를 호출한 함수에서 먼저 처리합니다.
	// 0의 정의때문에, 할당되지 않은 주소를 접근하게 되어 에러가 납니다.
	// 따라서, 애초에 진법에 상관없이 0에 대해서는 출력을 하게 하였고,
	// 여기서는 0에 대해서는 신경 쓰지 않게 하였습니다.
	// 이 알고리즘을 귀하의 프로그램에 적용할 계획이라면
	// 여기에 0에 대한 처리를 할 필요가 있을 수도 있습니다.

	// 이제 this는 양수 아니면 음수입니다.

	// 출력하고자 하는 진법이 홀수라면
	// DD_Odd함수로 보냅니다.
	// radix가 홀수일 때,
	// 짝수일 때에 비해서, 추가적으로 처리해야 할것이 너무 많아서
	// 아예 짝수와 홀수일 때를 분리하였습니다.
	if (radix & 1)
	{
		DD_Odd(dest, radix);
		return;
	}

	// dest가 될 수 있는 최대 길이를 구합니다.
	length maxlen = length(unsigned __int64(len)*radix_d[radix]/10000 + 1);
	dest.Reallocate(maxlen);
	dest.Blkinit();
	dest.len = 1; // 초기 dest의 길이를 1로 설정합니다.
	dest.sign = sign;

	index i, j;
	length bit;
	blocktype bound = blocktype(radix_b[radix]>>1);

	i = len;
	while (i--) // this의 높은 자리의 blk부터
	{
		bit = N;
		while (bit--) // blk의 높은 자리부터
		{
			// dest의 모든 blk를 검사하여
			// bound이상인 블럭을 찾아 더해줍니다.
			j = dest.len;
			while (j--)
			{
				if (dest.blk[j] >= bound)
					dest.blk[j] += radix_c[radix];
			}

			// dest의 길이를 하나 늘려줍니다.
			if (dest.blk[dest.len - 1] & 0x80000000) ++dest.len;

			// dest의 모든 블럭을 왼쪽으로 1 쉬프트합니다.
			j = dest.len;
			while (j--)
			{
				dest.blk[j] <<= 1;
				if (j != 0 && dest.blk[j - 1] & 0x80000000)
					dest.blk[j] |= 1;
			}

			// this에서 dest로 1비트 복사합니다.
			if(blk[i] & (1ul<<bit) )
				dest.blk[0] |= 1;
		}
	}
}
void BigInteger::DD_Odd(BigInteger &dest, int radix) const
{
	length maxlen = length(unsigned __int64(len)*radix_d[radix]/10000 + 1);
	dest.Reallocate(maxlen);
	dest.Blkinit();
	dest.len = 1; // 초기 dest의 길이를 1로 설정합니다.
	dest.sign = sign;

	index i, j, k;
	length bit;
	blocktype rb = blocktype(radix_b[radix]);
	blocktype bound = blocktype(rb >> 1) + 1;
	blocktype **isadd;
	isadd = (blocktype**)malloc(maxlen << 2);

	i = len;
	while (i--) // this의 높은 자리의 blk부터
	{
		bit = N;
		while (bit--) // blk의 높은 자리부터
		{
			// dest의 모든 blk를 검사하여
			// bound이상인 블럭을 찾아 더해줍니다.
			j = dest.len;
			k = 0;
			while (j--)
			{
				if (dest.blk[j] >= bound)
				{
					dest.blk[j] += radix_c[radix];
					isadd[k++] = &dest.blk[j];
				}
			}

			// dest의 길이를 하나 늘려줍니다.
			if (dest.blk[dest.len - 1] & 0x80000000) ++dest.len;

			// dest의 모든 블럭을 왼쪽으로 1 쉬프트합니다.
			j = dest.len;
			while (j--)
			{
				dest.blk[j] <<= 1;
				if (j != 0 && dest.blk[j - 1] & 0x80000000)
					dest.blk[j] |= 1;
			}

			// this에서 dest로 1비트 복사합니다.
			if(blk[i] & (1ul<<bit) )
				dest.blk[0] |= 1;

			// 0.5를 더하지 못한것을 보정합니다.
			while (k)
				++(*isadd[--k]);

			// 홀수 진법에서만 나타나는 현상으로
			// 쉬프트 한 블럭 중
			// radix_b[raidx]보다 크거나 같은 블럭이
			// 발생 합니다.
			// 이런 블럭들을 처리해주어야 바른 값이 나옵니다.
			for (j = 0; j < dest.len; ++j)
			{
				if (dest.blk[j] >= rb)
				{
					dest.blk[j] -= rb;
					for (k = j + 1; ; ++k)
					{
						if (++dest.blk[k] != 0)
							break;
					}
				}
			}
			if (j != maxlen && dest.blk[j] != 0) ++dest.len;
		}
	}
	free(isadd);
}
BigInteger::BigInteger(const char *str, int radix/* =10 */)
{
	SetZero();
	std::string temp(str);
	stob(temp, radix);
}
BigInteger::BigInteger(const std::string &str, int radix/* =10 */)
{
	SetZero();
	stob(str, radix);
}
const BigInteger & BigInteger::stob(const std::string &str, int radix/* =10 */)
{
	// 2~36진법 모두로 입력 할 수 있습니다.
	// 단, 입력에서 발생할 수 있는 실수는 점검하지 않습니다!
	// 예로.. 1234a324aa32432a를 10진법으로 입력 한다면
	// atoi 함수에서는 1234가 되지만 여기서는 4가 됩니다.
	if ( !( radix >=2 && radix <=36 ) )
	{
#if defined(_DEBUG)
		throw "2 ~ 36진법까지만 가능합니다.";
#else
		return *this;
#endif
	}
	// *this를 0으로 초기화 합니다.
	// 0으로 초기화 하지 않으면 const char *
	// const string & 생성자에서 오류가 나며
	// 이 함수를 따로 사용시에도 정확한 값이 나오지 않을 수 있습니다.

	/*Allocate(1);
	blk[0] = 0;
	sign = Zero;*/
	Reset();
	if (str.size() == 1 && str[0] == '0')
		return *this;
	// 문자열을 몇개씩 끊어서 읽을지 정합니다.
	length read_length = radix_a[radix];
	// 입력은 출력을 역으로 생각하면 됩니다.
	// 낮은자리부터 read_length씩 끊어 읽은것에
	// base를 j번 곱해서 차례차례 결과값에 더하면 됩니다.
	BigInteger base(radix_b[radix]);
	// 문자열의 길이를 구합니다.
	unsigned long offset = str.size();
	// 밑의 _Copy_s 함수가 필요로 합니다.
	// 정확한 위치와 갯수를 인수로 넣어야
	// 정확하고 오류없이 작동합니다.
	length blocklen = offset / read_length;
	unsigned long rest = offset % read_length;
	// read_length만큼 읽은것을 잠시 저장합니다.
	char temp[33] = {0,};
	// 문자열에 진법이상의 숫자, 문자가 있는지 점검하기 위해서 사용합니다.
	char *error_ptr;
	BigInteger x;

	// 문자열 맨 앞에 부호가 있을 수 있습니다.
	// 부호가 있을 경우를 처리해 줍니다.
	unsigned long signexist = 0;
	if (str[0] == '+')
	{
		if (str.size() == 2 && str[1] == '0')
			return _Zero;
		// + 부호가 있다고 해서 sign를 대입받지 않습니다.
		signexist = 1;
	}
	else if (str[0] == '-')
	{
		// "-0"과 같은 경우입니다.
		if (str.size() == 2 && str[1] == '0')
			return _Zero;
		// 그 밖에 음수면 부호를 대입합니다.
		signexist = 1;
		sign = Negative;
	}
	if (sign != Negative)
		sign = Positive;
	unsigned long i, j;
	i = 0;
	j = 0;
	// read_length씩 완전하게 끊어 읽을 수 있는 경우
	// while문안으로 들어가게 됩니다.
	while (blocklen--)
	{
		// offset을 문자열의 맨 끝에서
		// read_length만큼 빼줍니다.
		offset -= read_length;
		// offset에서 read_length만큼 읽어서 temp에 저장
		str._Copy_s(temp, 33, read_length, offset);
		// strtoul함수는 진법으로 되있는 문자열을
		// unsigned long형으로 바꿔줍니다.
		// 대입 연산자로 x에 잘 대입됩니다.
		x = strtoul(temp, &error_ptr, radix);
		// x에 base를 j번 곱합니다.
		// 자리수를 생각해야하기 때문입니다.
		while (j--)
			x *= base;
		add(*this, x);
		j = ++i;
		// 문자열에 진법 이상의 숫자,문자가 있으면
		// goto로 함수를 종료시킵니다.
		// throw를 던지지 않습니다.
		if (*error_ptr != 0)
			return *this;
	}
	// read_length에 부족하게 끊어 읽을 수 있는 경우
	if (rest != 0)
	{
		memset(temp, 0, 33);
		offset -= (rest - signexist);
		if (signexist == 1)
			rest--;
		str._Copy_s(temp, 33, rest, offset);
		x = strtoul(temp, &error_ptr, radix);
		if (j != 0)
		{
			while (j--)
				x *= base;
		}
		add(*this, x);
	}
	return *this;
}

const std::string BigInteger::btos(int radix) const
{
	std::string str; // 리턴되는 값입니다.

	if ( !( radix >=2 && radix <=36 ) )
	{
#if defined(_DEBUG)
		throw "2 ~ 36진법까지만 가능합니다.";
#else
		return str;
#endif
	}

	BigInteger dest;
	str.reserve( dest.len * radix_a[radix] );

	// 0 처리
	if (sign == Zero)
	{
		str += '0';
		return str;
	}

	DoubleDabble(dest, radix);

	if (dest.sign == Negative)
		str += '-';

	char prM[33];

	length i = dest.len - 1;
	_ltoa_s(dest.blk[i], prM, radix); // 제일 높은 자리 처리
	str += prM;
	// 그 이하는 00001과 같이 앞에 0이 있을 수도 있기 때문에
	// 0이 있어야 한다면 0을 추가한 후, 수를 대입하는 방식으로 처리해야 합니다.
	unsigned long j;
	while (i)
	{
		--i;
		memset(prM, 0, 33);
		_ltoa_s(dest.blk[i], prM, radix);
		// 선두 0을 대입
		j = strlen(prM);
		if (j != radix_a[radix])
			while (j != radix_a[radix])
			{
				str += '0';
				j++;
			}
			// 0 대입 후, str에 prM을 대입
			str += prM;
	}
	return str;
}

std::ostream & operator <<(std::ostream &os, const BigInteger &x)
{
	int base;
	long osFlags = os.flags();
	if (x.sign == BigInteger::Negative)
		os << '-';
	else if (x.sign == BigInteger::Positive && os.flags() & os.showpos)
		os << '+';
	if (osFlags & os.dec)
		base = 10;
	else if (osFlags & os.hex)
	{
		base = 16;
		if (osFlags & os.showbase)
			os << "0x";
	}
	else if (osFlags & os.oct)
	{
		base = 8;
		if (osFlags & os.showbase)
			os << '0';
	}
	
	if (x.sign == BigInteger::Zero)
	{
		os << '0';
		return os;
	}
	BigInteger dst;
	BigInteger *pB = (BigInteger *)&x;

	os << std::setfill('0');
	if (base == 10)
	{
		x.DoubleDabble(dst, base);
		os << dst.blk[dst.len - 1];
		for (int i = dst.len - 2; i >= 0; --i)
			os << std::setw(9) << dst.blk[i];
	}
	else if (base == 8)
	{
		x.DoubleDabble(dst, base);
		pB = &dst;
	}
	if (base != 10)
	{
		char prM[11] = {0, };
		_ltoa_s(pB->blk[pB->len - 1], prM, base);
		os << prM;
		for (int i = pB->len - 2; i >= 0; --i)
		{
			memset(prM, 0, 11);
			_ltoa_s(pB->blk[i], prM, base);
			os << std::setw(radix_a[base]) << prM;
		}
	}
	os << std::setfill(' ');

	return os;
}

void BigInteger::print(int radix/* =10 */) const
{
	if ( !( radix >=2 && radix <=36 ) )
	{
#if defined(_DEBUG)
		throw "2 ~ 36진법까지만 가능합니다.";
#else
		return;
#endif
	}
	if (sign == BigInteger::Zero)
	{
		std::cout << '0';
		return;
	}
	else if (sign == BigInteger::Negative)
	{
		std::cout << '-';
	}
	BigInteger temp;
	BigInteger *pB = (BigInteger *)this;
	char prM[33] = {0, };

	if (radix != 2 && radix != 4 && radix != 16)
	{
		DoubleDabble(temp, radix);
		pB = &temp;
	}

	index i = pB->len - 1;
	std::cout << std::setfill('0');
	if (radix == 10)
	{
		std::cout << pB->blk[i];
		while (i--)
			std::cout << std::setw(radix_a[radix]) << pB->blk[i];
	}
	else
	{
		_ltoa_s(pB->blk[i], prM, radix);
		std::cout << prM;
		while (i--)
		{
			memset(prM, 0, 33);
			_ltoa_s(pB->blk[i], prM, radix);
			std::cout << std::setw(radix_a[radix]) << prM;
		}
	}
	std::cout << std::setfill(' ');
}
std::istream & operator >>(std::istream &is, BigInteger &x)
{
	std::string str;
	is >> str;
	x.stob(str);
	return is;
}
#pragma endregion
#pragma  endregion

#pragma region 비교연산
const int BigInteger::compare(const BigInteger &x) const
{
	if (this == &x)
		return 0;
	if (len < x.len)
		return -1;
	else if (len > x.len)
		return 1;
	else {
		// 한블럭씩 높은자리부터 비교합니다.
		length i = len;
		while (i > 0)
		{
			i--;
			if (blk[i] == x.blk[i])
				continue;
			else if (blk[i] > x.blk[i])
				return 1;
			else
				return -1;
		}
		// 모든 블럭이 같은 경우이므로, 크기가 같습니다.
		return 0;
	}
}
const BigInteger::_sign BigInteger::getsign() const
{
	return sign;
};
bool BigInteger::operator ==(const BigInteger &x) const
{
	if (this == &x)
		return true;
	if (sign != x.sign)
		return false;
	if (len != x.len)
		return false;
	length i = len;
	while (i > 0)
	{
		i--;
		if (blk[i] != x.blk[i])
			return false;
	}
	return true;
}
bool BigInteger::operator !=(const BigInteger &x) const
{
	return !( operator ==(x) );
}
bool BigInteger::operator > (const BigInteger &x) const
{
	if (this == &x)
		return false;
	if (sign > x.sign)
		return true;
	else if (sign < x.sign)
		return false;
	else
	{
		// 부호에 따라 리턴값이 달라집니다.
		if (len > x.len)
			if (sign == Positive) return true;
			else return false;
		else if (len < x.len)
			if (sign == Positive) return false;
			else return true;
		else
		{
			length i = len;
			while (i > 0)
			{
				i--;
				if (blk[i] == x.blk[i])
					continue;
				else if (blk[i] > x.blk[i])
					if (sign == Positive) return true;
					else return false;
				else
					if (sign == Positive) return false;
					else return true;
			}
			return false; // 두 수가 같은 경우이므로
		}
	}
}
bool BigInteger::operator >=(const BigInteger &x) const
{
	if (this == &x)
		return true;
	if (sign > x.sign)
		return true;
	else if (sign < x.sign)
		return false;
	else
	{
		if (len > x.len)
			if (sign == Positive) return true;
			else return false;
		else if (len < x.len)
			if (sign == Positive) return false;
			else return true;
		else
		{
			length i = len;
			while (i > 0)
			{
				i--;
				if (blk[i] == x.blk[i])
					continue;
				else if (blk[i] > x.blk[i])
					return true;
				else
					return false;
			}
			return true; // 두 수가 같은 경우
		}
	}
}
bool BigInteger::operator < (const BigInteger &x) const
{
	return !( operator >=(x) );
}
bool BigInteger::operator <=(const BigInteger &x) const
{
	return !( operator >(x) );
}
#pragma endregion

#pragma region 비트연산
unsigned __int64 BigInteger::bitlength() const
{
	if (sign == Zero)
		return 0;
	blocktype LeftMostBlock = blk[len - 1];
	unsigned __int64 LeftMostBlockLen = 0;
	while (LeftMostBlock != 0)
	{
		LeftMostBlock >>= 1;
		LeftMostBlockLen++;
	}
	return LeftMostBlockLen + unsigned __int64( (len - 1) ) * N;
}
BigInteger::length BigInteger::blklength() const
{
	return len;
}
const BigInteger BigInteger::operator &(const BigInteger &x) const
{
	if (this == &x)
		return *this;
	BigInteger temp;
	// 둘 중 하나가 0이라면 연산값은 0입니다.
	if (sign == Zero || x.sign == Zero)
		return temp;

	// temp의 길이는 둘 중 짧은것으로 재할당합니다.
	temp.Allocate( (len < x.len) ? len : x.len );

	index i;
	for (i = 0; i < temp.len; i++)
		temp.blk[i] = blk[i] & x.blk[i];

	temp.sign = (sign == Positive || x.sign == Positive) ? Positive : Negative;
	// 선두 0 블럭을 제거 합니다.
	temp.ZapLeadingZeros();
	// this와 x의 비트의 교집합이 하나도 없으면...
	// temp는 0입니다.
	if (temp.len == 0)
		temp.sign = Zero;
	return temp;
}
const BigInteger & BigInteger::operator &=(const BigInteger &x)
{
	return *this = *this & x;
}
const BigInteger BigInteger::operator |(const BigInteger &x) const
{
	if (this == &x)
		return *this;
	BigInteger temp;
	// 둘 다 0인 경우
	if (sign == Zero && x.sign == Zero)
		return temp;
	// this만 0인 경우
	else if (sign == Zero)
		return x;
	// x만 0인 경우
	else if (x.sign == Zero)
		return *this;

	const BigInteger *pLeft, *pRight;
	if (len >= x.len) {
		pLeft = this;
		pRight = &x;
	} else {
		pLeft = &x;
		pRight = this;
	}
	temp.Allocate(pLeft->len);

	index i;
	for (i =0; i < pRight->len; i++)
		temp.blk[i] = pLeft->blk[i] | pRight->blk[i];
	for (; i < pLeft->len; i++)
		temp.blk[i] = pLeft->blk[i];

	temp.sign = (pLeft->sign == Negative || pRight->sign == Negative) ? Negative : Positive;
	// 연산 결과로 0이 나올 수 없습니다./
	return temp;
}
const BigInteger & BigInteger::operator |=(const BigInteger &x)
{
	return *this = *this | x;
}
const BigInteger BigInteger::operator ^(const BigInteger &x) const
{
	BigInteger temp;
	if (this == &x)
		return temp;
	// 둘 다 0인 경우
	if (sign == Zero && x.sign == Zero)
		return temp;
	// this만 0인 경우
	else if (sign == Zero)
		return x;
	// x만 0인 경우
	else if (x.sign == Zero)
		return *this;

	const BigInteger *pLeft, *pRight;
	if (len >= x.len) {
		pLeft = this;
		pRight = &x;
	} else {
		pLeft = &x;
		pRight = this;
	}
	temp.Allocate(pLeft->len);

	index i;
	for (i =0; i < pRight->len; i++)
		temp.blk[i] = pLeft->blk[i] ^ pRight->blk[i];
	for (; i < pLeft->len; i++)
		temp.blk[i] = pLeft->blk[i];

	temp.sign = (sign == x.sign) ? Positive : Negative;
	temp.ZapLeadingZeros();
	// 연산 결과로 0이 나올 수 있습니다.
	if (temp.len == 0)
		temp.sign = Zero;
	return temp;
}
const BigInteger & BigInteger::operator ^=(const BigInteger &x)
{
	return *this = *this ^ x;
}
const BigInteger BigInteger::operator ~() const
{
	BigInteger temp(*this);
	if (sign == Positive)
		temp.sign = Negative;
	else if (sign == Negative)
		temp.sign = Positive;
	temp -= _One;
	return temp;
}
#pragma endregion

#pragma region 쉬프트연산
const BigInteger::blocktype BigInteger::Get_LShiftedBlock(index x, length n) const
{
	// x는 0~len까지의 범위를 가집니다.
	// n은 0~31까지의 범위를 가집니다.

	// x 전 블록의 상위 n비트를 추출 합니다.
	blocktype lowblk = (x == 0 || n == 0) ? 0 : ( blk[x - 1] >> (N - n) );
	// x 블록을 왼쪽으로 n번 쉬프트합니다.
	blocktype highblk = (x == len) ? 0 :( blk[x] << n );
	// 위 두 블럭의 합집합을 리턴합니다.
	return lowblk | highblk;
}
const BigInteger BigInteger::operator <<(int leftmove) const
{
	// (*this) * 2^(leftmove)를 연산
	BigInteger temp; // 결과값 리턴용
	/*
	* 특수 경우를 제외합니다.
	* 1. *this가 0이면, 0 리턴
	* 2. leftmove가 0이면, *this 리턴
	* 3. leftmove가 음수면, >> 쉬프트로 연산
	*/
	if (sign == Zero)
		return temp;
	if (leftmove == 0)
		return *this;
	else if (leftmove < 0)
		return *this >> (-leftmove);
	length shiftblocks = leftmove / N;
	length shiftbits = leftmove % N;

	// +1은 shitfbits때문에 생기는 추가되는 블록 저장용
	temp.Allocate(len + shiftblocks + 1);
	temp.Blkinit();

	// 한블럭씩 shiftbits만큼 쉬프트 시켜 대입해줍니다.
	index i, j;
	for (i = 0, j = shiftblocks; i <= len; i++, j++)
		temp.blk[j] = Get_LShiftedBlock(i, shiftbits);

	// Get_LShiftedBlock(len - 1, shiftbits)가 0일 경우...
	if (temp.blk[temp.len - 1] == 0)
		temp.len--;
	temp.sign = sign;
	return temp;
}
const BigInteger & BigInteger::operator <<=(int leftmove)
{
	return *this = *this << leftmove;
}
const BigInteger BigInteger::operator >>(int rightmove) const
{
	BigInteger temp;
	if (sign == Zero)
		return temp;
	if (rightmove == 0)
		return *this;
	else if (rightmove < 0)
		return *this << (-rightmove);
	// 결과값이 0이 나오는 경우
	if (unsigned __int64(rightmove)  >= bitlength())
		return temp;

	length rightShiftBlocks = (rightmove + N - 1) / N;
	length leftShiftBits = N * rightShiftBlocks - rightmove;
	// 이제 (N * rightShiftBlocks - leftShiftBits) == rightmove
	// 그리고 0 <= leftShiftBits < N 가 성립합니다.

	// + 1: 최상위 블럭 때문입니다.
	temp.Allocate(len + 1 - rightShiftBlocks);

	index i, j;
	for (j = rightShiftBlocks, i = 0; j <= len; j++, i++)
		temp.blk[i] = Get_LShiftedBlock(j, leftShiftBits);
	if (temp.blk[temp.len - 1] == 0)
		temp.len--;
	// 위에서 결과값이 0이 나오는 것을 제거 하였기 때문에
	// 그대로 부호를 넣는다.
	temp.sign = sign;
	return temp;
}
const BigInteger &  BigInteger::operator >>=(int rightmove)
{
	return *this = *this >> rightmove;
}
#pragma endregion

#pragma region 사칙/나머지/증감
void BigInteger::add(const BigInteger &Left, const BigInteger &Right)
{
	// Left와 Right의 크기를 더하여 this에 저장하는 함수입니다.

	// stob 함수에서
	// this->add(*this, x)와 같이 호출하기 때문에
	if (this == &Left)
	{
		BigInteger Left_temp(Left);
		add(Left_temp, Right);
		return;
	}
	// 호출 함수부분을 간략하게 하기 위해서
	if (Left.len < Right.len)
	{
		add(Right, Left);
		return;
	}
	// 이제, Left와 Right의 길이간에는
	// Left.len >= Right.len 이 성립
	Reallocate(Left.len + 1);

	blocktype blk_temp = 0; // 두 블럭의 합을 잠시 저장하기 위해
	// 자리올림 처리용
	// carryIn : 이전 자리에서 자리올림 발생?
	// carryOut : 현 자리에서 연산으로 자리올림 발생?
	bool carryIn, carryOut;
	index i;
	// 낮은 자리 만큼 루프를 돌며 덧셈 연산
	for(i = 0, carryIn = false; i < Right.len; i++){
		blk_temp = Left.blk[i] + Right.blk[i];
		// 자리 올림이 발생하면
		// blk_temp < Left.blk[i]
		// blk_temp < Right.blk[i]
		// 위 두개를 모두 만족한다.
		// 그래서 두 개중에 하나만 사용하여 비교해 주면된다.
		carryOut = (blk_temp < Left.blk[i]);
		if (carryIn) { // 전 자리에서 자리올림 발생했는가?
			++blk_temp;
			// CarryIn으로 인한 자리올림 발생 가능성 처리
			carryOut |= (blk_temp==0);
		}
		blk[i] = blk_temp;
		carryIn = carryOut;
	}

	// blk[Right.len - 1]에서 자리올림 발생했는가?
	// 또한, 큰 가능성은 없지만 연쇄 자리올림이 가능하다
	// ex) 799 + 1과 같은 경우와 비슷한 맥락
	for(; carryIn && i < Left.len; i++){
		blk[i] = Left.blk[i] + 1;
		carryIn = (blk[i] == 0);
	}

	// 나머지는 그대로 대입
	for(; i < Left.len; i++){
		blk[i] = Left.blk[i];
	}

	// 연쇄 자리올림이 끝까지 일어난 경우이다.
	// 위에서 799 + 1이 아닌 999 + 1과 같은 경우다.
	// 연산값이 자릿수가 1 증가하며 증가한 자리의 숫자는 1이다.
	// 아니라면 len 1 감소
	if(carryIn) blk[i]=1;
	else len--;
}
void BigInteger::subtract (const BigInteger &Left, const BigInteger &Right)
{
	// Left의 크기에서 Right의 크기만큼을 빼서 this에 저장하는 함수입니다.

	// 이 함수를 호출하는 함수에서 left의 크기가 항상 크도록 설정
	// | Left | - | Right |
	// 가 성립한다는 전제하에 subtract함수는 작동합니다.

	// 초기에는 divideWithRemainder함수에서
	// subtract함수를 this->subtract(*this, x)와 같이 호출하여
	/*
	if (Left.len < Right.len)
	{
	add(Right, Left);
	return;
	}
	*/
	// 이 필요하였지만, divide..함수의 알고리즘을 다른 것으로
	// 교체 하면서 subtract함수를 호출하지 않게되어 삭제하였습니다.

	// 빼는데 될 수있는 가장 긴 길이는 Left.len
	Reallocate(Left.len);

	blocktype blk_temp = 0; // 두 블럭의 차를 잠시 저장하기 위해
	// 자리내림 처리용
	// borrowIn : 이전 자리에서 자리내림 발생?
	// borrowOut : 현 자리에서 연산으로 자리내림 발생?
	bool borrowIn, borrowOut;
	index i;
	// 낮은 자리 만큼 루프를 돌며 뺄셈 연산
	for(i = 0, borrowIn = false; i < Right.len; i++){
		blk_temp = Left.blk[i] - Right.blk[i];
		// 자리 내림이 발생하면
		// blk_temp > Left.blk[i]
		// blk_temp > Right.blk[i]
		// 위 두개를 모두 만족한다.
		// 그래서 두 개중에 하나만 사용하여 비교해 주면된다.
		borrowOut = (blk_temp > Left.blk[i]);
		if (borrowIn) { // 전 자리에서 자리내림 발생했는가?
			// BorrowIn으로 인한 자리내림 발생 가능성 처리
			borrowOut |= (blk_temp==0);
			blk_temp--;
		}
		blk[i] = blk_temp;
		borrowIn = borrowOut;
	}

	// blk[Right.len - 1]에서 자리내림 발생했는가?
	// 또한, 큰 가능성은 없지만 연쇄 자리내림이 가능하다
	// ex) 1000 - 1과 같은 경우와 비슷한 맥락
	for(; borrowIn && i < Left.len; i++){
		borrowIn = (Left.blk[i] == 0);
		blk[i] = Left.blk[i] - 1;
	}

	// 나머지는 그대로 대입
	for(; i < Left.len; i++)
		blk[i] = Left.blk[i];

	// 연산 결과로 생기는 선두 0블럭들을 모두 제거
	ZapLeadingZeros();
}
void BigInteger::multiply(const BigInteger &Left, const BigInteger &Right)
{
	// 두 수의 크기를 곱하여 this에 저장하는 함수입니다.

	// n자리 * m자리 곱셈 결과는 최대 (n+m)자리가 됩니다.
	Reallocate(Left.len + Right.len);
	Blkinit();

	// 두 32비트의 연산으로는 최대 64비트가 나옵니다.
	// 따라서, 두 블록의 연산값을 저장하기 위해
	// unsigned __int64형으로 임시 저장 변수를 만듭니다.
	unsigned __int64 temp_res;
	// 임시 저장값을 블록에 넣기 위해서는 64비트를
	// 다시 32비트씩 나누어 줘야합니다.
	blocktype blk_temp[2] = {0,};
	/*
	* 곱셈 알고리즘은 초등학교떄 배우는 방식을 사용하였습니다.
	* 대신 한자리씩 계산하는게 아닌 32비트씩 계산하는 것뿐입니다.
	* 인터넷에서 이런 방식을 'Schoolbook Multiplication' 이라고 하네요.
	* Google에서 Fast Multiplication을 치면 많은 자료가 나옵니다.
	*/
	index i,j,k,l;
	for(i = 0; i < Left.len; i++){
		temp_res = 0;
		for(j = 0; j < Right.len; j++){
			// 두 블럭을 곱하여 32비트씩 쪼개어 저장합니다.
			temp_res = unsigned __int64(Left.blk[i]) * Right.blk[j];
			blk_temp[0] = blocktype(temp_res);
			blk_temp[1] = blocktype(temp_res >> N);

			for (k = i + j, l = 0; l < 2; l++)
			{
				blk[k] += blk_temp[l];
				// 더했는데 blk[k]에서 자리 올림이 발생한다면!!!
				if (blk[k] < blk_temp[l])
				{
					// 연쇄 자리올림의 경우도 생각하여
					// 연쇄 자리올림이 발생하지 않을 때까지
					// 다음 자리들을 1 증가시킨다.
					for (;;)
					{
						blk[++k]++;
						if (blk[k] == 0)
							continue;
						else
							break;
					}
				}
				// blk_temp[0]에 대한 계산 후,
				// blk_temp[1]의 연산을 위해, k 재정의
				k = i + j + 1;
			}
		}
	}

	// len의 길이는 '최대' Left.len + Right.len이 될 수 있지만
	// Left.len + Right.len - 1도 될 수 있다.
	if (blk[len - 1] == 0)
		len--;
}
void BigInteger::divideWithRemainder(const BigInteger &Divisor, BigInteger &Quotient)
{
	/*
	* 제수가 피제수보다 큰 경우는 나눗셈을 할 필요가 없습니다.
	* 몫은 0, 나머지는 피제수가 될테니까요.
	* 연산을 하지 않아도 되기 때문에, 이와 같은 경우는
	* 사전에 조건문으로 걸러주는것이 연산속도를 빠르게 해 줄수 있습니다.
	* 하지만 이 조건문에서 시간을 많이 잡아먹으면 안됩니다.
	* 
	* 제수 > 피제수 를 판별할 수 있는 방법으로는
	* 정확한 1가지와 대략적인 2가지 방법이 있습니다.
	*
	* 1. compare함수를 사용하여 크기가 큰지 판별하기
	*     제일 정확한 방법이지만, 오래 걸립니다.
	*     큰 숫자일 경우는 제수와 피제수의 크기가 같다면
	*     for문을 수백만번을 돌 수도 있습니다.
	*
	* 2. 제수와 피제수의 비트 길이 체크하기
	*     비트 길이는 제일 높은 비트가 어디 있는지를 나타내는 것과 같습니다.
	*     따라서, 제일 높은 비트는 같지만 제수가 큰 경우는 제외하고
	*     ex) 피제수 : 10(2), 제수 : 11(3)
	*     나머지는 판별가능 합니다.
	*
	* 3. 제수와 피제수의 블럭 길이 비교
	*     가장 빠른 방법입니다. 단순하게 제수와 피제수의
	*     len을 비교하는 것이기 때문입니다.
	*     하지만, 그만큼 놓치는 경우도 많습니다.
	*
	* 세 가지 방법으로 제수와 피제수의 크기를 비교할 수 있습니다.
	* 그 중, 가장 빠른 3번째 방법을 사용하겠습니다.
	* 다시 한번 말씀드리지만, 이 조건을 써주지 않아도
	* 연산 과정을 통해 몫과 나머지를 구할 수 있습니다.
	* 다만 불필요한 연산 과정을 거치지 않기 위해서
	* 걸러내는 것이므로 모든 경우에 대해서
	* 그 경우를 살필 필요는 없습니다.
	*/
	if (blklength() < Divisor.blklength()) {
		Quotient = _Zero;
		return;
	}

	// 이제, (*this).len >= Divisor.len 이 성립합니다.

	/*
	* 나눗셈을 정의하는 데에는 의견이 갈립니다.
	* 양수와 양수의 나눗셈은 상관 없지만
	* 양수와 음수, 음수와 음수의 나눗셈에서 구현한 사람마다
	* 차이가 있습니다.
	* 이 부분은 컴파일러마다도 결과값이 달라진다고 합니다.
	* 표준이 정의되지 않았다고 하네요..
	* ---------------------------------
	* 2 / (-3) = 0     2 % (-3) = 2
	* ---------------------------------
	* 2 / (-3) = -1    2 % (-3) = -1
	* ---------------------------------
	*
	* 2 / (-3)의 소수까지의 나눗셈을 구하면
	* -0.66666666666666666666... 입니다.
	* 여기서 소수점을 버릴지..
	* 아니면 올림 처리 할지에 따라 결과가 달라지는 것입니다.
	* 전, 위에 것을 토대로 만들겠습니다.
	* vc가 위와 같이 나오기 때문입니다.
	* 아래는 Matt씨가 만든것에서 저렇게 만듭니다.
	*/

	/* 전반적인 방법..
	* 알고리즘은 초기의 알고리즘과 비슷합니다.
	* 초등학교 때, 배우던 나누기 방법을 그대로 사용합니다.
	* 초기와 다른 점은 좀 더 빠르다는 것입니다.
	*
	* (초기 나누기 알고리즘)
	*                     776
	*               ----------
	*           159 |  123456
	*                  111300
	*                 ------
	*                   12156
	*                   11130
	*                  -------
	*                    1026
	*                     954
	*                   ------
	*                      72
	*
	*
	* (현재 나누기 알고리즘)
	*                     776
	*               ----------
	*           159 |  123456
	*                  1113
	*                 ------
	*                   1215
	*                   1113
	*                  -------
	*                    1026
	*                     954
	*                   ------
	*                      72
	*
	* 두개의 차이점을 아시겠습니까?
	* 뺄셈 과정이 다릅니다.
	* 위에서는 123456 - 111300을 구한다면
	* 아래에서는 1234 - 1113을 구합니다!
	* 큰 숫자라면 엄청난 속도차이가 아닐 수 없습니다!!
	*/

	index i, j, k;
	unsigned int i2;
	blocktype temp;
	bool borrowIn, borrowOut;

	BigInteger orig(*this);
	length origLen = len;
	// 계산상, *this.blk[len]을 접근해야 합니다.
	// 따라서, 오류를 막기위해 재할당 합니다.
	Reallocate(len + 1);
	Blkcopy(orig);
	blk[len-1] = 0;
	//memmove(blk, orig.blk, sizeof(blocktype) * origLen);

	// 빼기 값을 저장하기 위해 사용합니다.
	blocktype *subtractBuf = new blocktype[len];
	memset(subtractBuf, 0, sizeof(blocktype) * len);

	// 몫을 미리 할당합니다.
	Quotient.Allocate(origLen - Divisor.len + 1);
	// reallocate에서 allocate로 바꿈 9.14
	Quotient.Blkinit();

	// 위에서부터 비트 하나씩 계산해나갑니다.
	i = Quotient.len;
	while (i > 0) {
		i--;
		Quotient.blk[i] = 0;
		i2 = N;
		while (i2 > 0) {
			i2--;

			for (j = 0, k = i, borrowIn = false; j <= Divisor.len; j++, k++) {
				temp = blk[k] - Divisor.Get_LShiftedBlock(j, i2);
				borrowOut = (temp > blk[k]);
				if (borrowIn) {
					borrowOut |= (temp == 0);
					temp--;
				}

				subtractBuf[k] = temp; 
				borrowIn = borrowOut;
			}

			for (; k < origLen && borrowIn; k++) {
				borrowIn = (blk[k] == 0);
				subtractBuf[k] = blk[k] - 1;
			}

			if (!borrowIn) {
				Quotient.blk[i] |= (blocktype(1) << i2);
				while (k > i) {
					k--;
					blk[k] = subtractBuf[k];
				}
			} 
		}
	}
	// Quotient.len != 1에서 0으로 바꿈 9.14
	if (Quotient.len != 0 && Quotient.blk[Quotient.len - 1] == 0)
		Quotient.len--;
	ZapLeadingZeros();

	delete [] subtractBuf;
	// 몫과 나머지의 부호지정
	Quotient.sign = (sign == Divisor.sign) ? Positive : Negative;
	if (Quotient.len == 0 /*&& Quotient.blk[0] == 0*/)
		Quotient.sign = Zero;
	if (len == 0 /*&& blk[0] == 0*/)
		sign = Zero;
	// 0부호 변경 조건 바꿈 9.14
}
const BigInteger BigInteger::operator -() const
{
	BigInteger temp(*this);
	if (temp.sign == Zero) return temp;
	temp.sign = (sign == Positive) ? Negative : Positive;
	return temp;
}
const BigInteger abs(const BigInteger &x)
{
	BigInteger temp(x);
	if (temp.sign == BigInteger::Negative)
		temp.sign = BigInteger::Positive;
	return temp;
}
const BigInteger BigInteger::add(const BigInteger &x) const
{
	// 둘 중 하나가 0이면 다른 수를 리턴하면 됩니다.
	if (sign == Zero)
		return x;
	if (x.sign == Zero)
		return *this;

	BigInteger temp;

	// 부호가 같은경우..
	if (sign == x.sign)
	{
		temp.add(*this, x);
		temp.sign = sign;
	}
	// 두 수의 부호가 다르다면, 뺄셈과 같습니다.
	else
	{
		int cmp;
		// compare함수는 this와 x의 '크기'를 비교합니다.
		cmp = compare(x);
		if (cmp == 0)
			; // 연산 없이 0리턴
		else if (cmp == 1)
		{
			// this > x인 경우
			temp.subtract(*this, x);
			temp.sign = sign;
		}
		else
		{
			// x > this인 경우
			temp.subtract(x, *this);
			temp.sign = x.sign;
		}
	}
	return temp;
}
const BigInteger BigInteger::operator +(const BigInteger &x) const
{
	return add(x);
}
const BigInteger & BigInteger::operator +=(const BigInteger &x)
{
	//BigInteger temp(*this);
	return *this = add(x);
}
const BigInteger BigInteger::subtract(const BigInteger &x) const
{
	BigInteger temp;
	// 둘 중 하나가 0일 때 처리
	if (x.sign == Zero)
		return *this;
	if (sign == Zero)
	{
		temp = x;
		return -temp;
	}

	// 두 수의 부호가 다르다면 크기는 더해지고
	// 부호는 this를 따르면 됩니다.
	if (sign != x.sign)
	{
		temp.add(*this, x);
		temp.sign = sign;
	}
	// 두 수의 부호가 같을 때
	else
	{
		int cmp;
		// this와 x의 '크기'비교
		cmp = compare(x);
		if ( cmp == 0 )
			; // 같다면 결과는 0
		else if ( cmp == 1 )
		{
			// this > x인 경우
			temp.subtract(*this, x);
			temp.sign = sign;
		}
		else
		{
			// this < x인 경우
			temp.subtract(x, *this);
			// this의 부호에 따라 결과값의 부호가 달라짐
			// Zero가 나오는 경우는 위에서 처리했으므로
			// Zero가 나올 수는 없다.
			temp.sign = (sign ==Positive) ? Negative : Positive;
		}
	}
	return temp;
}
const BigInteger BigInteger::operator -(const BigInteger &x) const
{
	return subtract(x);
}
const BigInteger & BigInteger::operator -=(const BigInteger &x)
{
	return *this = subtract(x);
}
const BigInteger BigInteger::multiply(const BigInteger &x) const
{
	BigInteger temp;
	// 두 수중 0이 있으면 곱하나마나 0입니다.
	if (sign == Zero || x.sign == Zero)
		return temp;
	temp.multiply(*this, x);
	// 두 수의 부호가 같으면 +, 다르면 -가 됩니다.
	temp.sign = (sign == x.sign) ? Positive : Negative;
	return temp;
}
const BigInteger BigInteger::operator *(const BigInteger &x) const
{
	return multiply(x);
}
const BigInteger & BigInteger::operator *=(const BigInteger &x)
{
	return *this = multiply(x);
}
const BigInteger BigInteger::divide(const BigInteger &x) const
{
	BigInteger q, r(*this);
	if (x.sign == Zero)
	{
#if defined(_DEBUG)
		throw "0으로 나눌 수 없습니다.";
#else
		return q; // 0 리턴
#endif
	}
	r.divideWithRemainder(x, q);
	return q;
}
const BigInteger BigInteger::mod(const BigInteger &x) const
{
	BigInteger q, r(*this);
	if (x.sign == Zero)
	{
#if defined(_DEBUG)
		throw "0으로 나눌 수 없습니다.";
#else
		return q; // 0 리턴
#endif
	}
	r.divideWithRemainder(x, q);
	return r;
}
const BigInteger BigInteger::operator /(const BigInteger &x) const
{
	return divide(x);
}
const BigInteger BigInteger::operator %(const BigInteger &x) const
{
	return mod(x);
}
const BigInteger & BigInteger::operator /=(const BigInteger &x)
{
	return *this = divide(x);
}
const BigInteger & BigInteger::operator %=(const BigInteger &x)
{
	return *this = mod(x);
}
void BigInteger::PlusOne()
{
	index i;
	bool carry = true;
	for (i = 0; i < len && carry; i++) {
		++blk[i];
		carry = (blk[i] == 0);
	}
	if (carry) {
		Reallocate(len + 1);
		Blkinit();
		blk[i] = 1;
	}
}
void BigInteger::MinusOne()
{
	index i;
	bool borrow = true;
	for (i = 0; borrow; i++) {
		borrow = (blk[i] == 0);
		--blk[i];
	}

	if (blk[len - 1] == 0)
		len--;
}
BigInteger & BigInteger::operator ++()
{
	if (sign == Negative) {
		MinusOne();
		if (len == 0)
			sign = Zero;
	} else {
		PlusOne();
		sign = Positive;
	}
	return *this;
}
const BigInteger BigInteger::operator ++(int dummy)
{
	BigInteger temp(*this);
	++(*this);
	return temp;
}
BigInteger & BigInteger::operator --()
{
	if (sign == Positive) {
		MinusOne();
		if (len == 0)
			sign = Zero;
	} else {
		PlusOne();
		sign = Negative;
	}
	return *this;
}
const BigInteger BigInteger::operator --(int dummy)
{
	BigInteger temp(*this);
	--(*this);
	return temp;
}
#pragma endregion

#pragma region 기타연산
BigInteger pow(const BigInteger &x, const BigInteger &y)
{
	// x의 y승을 구합니다.
	/*
	*	1. x가 0일 때
	*		ㄱ. y가 0일 때 -> 에러!
	*		ㄴ. 나머지 -> 0
	*	2. x가 0이 아닐 때
	*		ㄱ. y가 0일 때 -> 1
	*		ㄴ. y가 음수 -> 에러!
	*		ㄷ. y가 양수 -> x ^ y
	*/
	if (x.sign == BigInteger::Zero)
	{
#if defined(_DEBUG)
		if (y.sign == BigInteger::Zero)
			throw "정의할 수 없습니다.";
#else
		return _Zero;
#endif
	}
	if (y.sign == BigInteger::Zero)
		return _One;
	else if (y.sign == BigInteger::Negative)
	{
#if defined(_DEBUG)
		throw "지수가 음수입니다.";
#else
		return _Zero;
#endif
	}
	BigInteger res(x);
	BigInteger count(y);
	while (--count)
		res *= x;
	return res;
}
BigInteger factorial(const BigInteger &x)
{
	// x! 을 구하는 팩토리얼 함수입니다.
	// 현재는 단순히 x * (x-1) * ..... (2) * (1)
	// 처럼 곱하기 연산으로 구하여 x가 많이 커지게 되면
	// 속도가 엄청나게 느려집니다.
	// 1000! 까지는 눈깜짝할 사이에 구할 수 있습니다.
	// computer by computer..

	// 0!은 1로 정의합니다.
	// 음수의 팩토리얼도 구할 수 있게 하였습니다.
	// 음수의 팩토리얼의 정의는...
	// x * (x + 1) * (x + 2) .... (-2) * (-1)
	// 로 정의 하였습니다.
	if (x.sign == BigInteger::Zero)
		return _One;
	BigInteger res(x);
	BigInteger count(x);
	// x가 양수면 count를 감수시키며 곱하기
	// 음수면 증가시키며 곱하기
	if (x.sign == BigInteger::Positive){
		while (--count)
			res *= count;
	} else {
		while (++count)
			res *= count;
	}
	return res;
}
BigInteger gcd(BigInteger x,BigInteger y)
{
	// x와 y의 최대 공약수를 구하는 함수입니다.
	// 유클리드 호제법 알고리즘을 사용합니다.
	// 나머지만 중요하며 몫은 필요없습니다.
	// 음수의 최대공약수는 에러로 처리하며 구하지 않습니다.
	BigInteger trash;
	if (x.sign == BigInteger::Zero || y.sign == BigInteger::Zero)
		return _Zero;
	if (x.sign == BigInteger::Negative || y.sign == BigInteger::Negative)
	{
#if defined(_DEBUG)
		throw "음수의 연산은 금지합니다.";
#else
		return _Zero;
#endif
	}
	for (;;) {
		if (y.sign == BigInteger::Zero)
			return x;
		x.divideWithRemainder(y, trash);
		if (x.sign == BigInteger::Zero)
			return y;
		y.divideWithRemainder(x, trash);
	}
}
BigInteger lcm(BigInteger x,BigInteger y)
{
	// 최소공배수를 구하는 함수입니다.
	// gcd함수를 이용하여 구하며
	// lcm(x, y) = x * y / gcd(x, y)가
	// 성립함을 이용하여 구합니다.
	BigInteger _gcd = gcd(x, y);
	// 최대 공약수가 0이라면
	// 최대 공배수도 0입니다.
	if (_gcd.sign == BigInteger::Zero)
		return _Zero;
	return x * y / _gcd;
}
#pragma endregion