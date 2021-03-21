#include "BigInteger.h"
#include <iomanip> // setw ���

namespace
{
	const BigInteger _One(1);
	const BigInteger _Zero(0);

	const unsigned long N = 32; // blk �Ѻ��� ��Ʈ ����

	/*
	* radix_a���� radix_d������
	* �Է�, ��� �Լ����� ����ϱ� ���� �ۼ��Ͽ���
	* ������ �� �̷����� ����� ������ �����ϴ�.
	*
	* �Ϲ������� 2������ ���ִ� ���� 10������
	* ����ϱ� ���ؼ��� 2���� ���� bcd�� �ٲ� ��, ����մϴ�.
	* (���⿡ ���� ������ ���ͳݿ���
	* bcd, binary to bcd, shift and add 3, double dabble
	* ���� �˻���� �پ��� ������ ������ �� �ֽ��ϴ�.)
	* ���⼭�� ���� ���� ����� ����Ͽ� ���, �Է��� �ϸ�
	* �� �� �Ϲ����̰� Ȯ��� ������ ����մϴ�.
	*
	* "binary to bcd"("2������ bcd��")
	* bcd�� ������ 10���� �迭�Դϴ�.
	* 0���� 9��� ���ڸ� ��Ÿ���� ���ؼ���
	* �ּ� 4��Ʈ�� �ʿ��ϸ�(2^4=16) 4��Ʈ�� 10������
	* ���ڸ��� ��Ÿ���ٴ� ���� bcd�Դϴ�.
	* ��, bcd�� �ٲ۴ٴ� ���� 2���� ���� 10������ �迭�� �ٲ۴ٴ� �̾߱��̸�
	* �̰��� �Ϲ�ȭ �غ��ٸ� ������ �����ϴ�.
	*
	* "binary to arbitrary radix"("2������ ������ ��������")
	* 2���� ���� n�������� ��� �ϰ��� �Ѵٸ�
	* n������ �迭�� �ٲپ��ָ� �˴ϴ�.
	* �׷� ���⼭ n���� �迭�� ���Ҵ� �ּ� ���Ʈ�� �ʿ��ұ��?
	* �츮�� ǥ���ϰ��� �ϴ� ������
	* 2~36������ �����Դϴ�.
	* ���⼭ 36������ ���ڸ��� �ʿ��� ��Ʈ���� ���� �����ϴ�.
	* �ּ� 6��Ʈ�� �ʿ��մϴ�.(2^6=64)
	* �츮�� ����� �� �ִ� Ÿ�� �� ���� ���� ���� 1����Ʈ(8��Ʈ)�̸�
	* 36�����̶�� ġ�� �� �ڸ��� 2��Ʈ(8-6=2)�� ��ȿ�������� ����մϴ�.
	* �������ڸ� bcd�� �Ϲ�ȭ �� ����
	* 2���� ���� n�������� ����ϴ� ����̸�
	* n���� �迭�� ����Ͽ� ���ڸ����� ǥ���Ѵٴ� ���Դϴ�.
	* �׷��� �̷��� ���ڸ��� ��� ��Ÿ����
	* ū���� ��,����ؾ� �ϴ� ��Ȳ����
	* �޸𸮰� ��ȿ�������� ���� �� �Ӹ� �ƴ϶�
	* 1����Ʈ�� ���� ���� ��Ʈ�� �����ϴ� ������ �Ͽ� �ӵ��� ���� �ʽ��ϴ�.
	* ���� ���⼭ �ѹ� �� ���ư�
	* 32��Ʈ�� ����ȭ ��ŵ�ϴ�.(cpu ��Ʈ��)
	*
	* "binary to arbitrary radix in 32bits("2������ ������ ��������(32��Ʈ ����ȭ)")"
	* �ϴ�, ���� ��ȯ �̾߱⸦ ��¦ �ϰڽ��ϴ�.
	* 9�������� 17�� 3�������� �ٲ۴ٸ� ��� ���ұ��?
	* 9�� 3�� 2���Դϴ�. ��, 9������ ���ڸ��� 3�������� ���ڸ���� ���� �˴ϴ�.
	* (27������ 3�������� ��Ÿ���ٸ� 27(3 ^ 3)������ ���ڸ��� 3�������� 3�ڸ��� �˴ϴ�.)
	* 9���� 1�� 3�������ε� 1, 9���� 7�� 3�������� 21�Դϴ�.
	* ��, 3�������� 121�� �˴ϴ�.
	* ���⼭ �� �� �ִ� ���� ���� ��ȯ�� �־�
	* n������ r�������� ��ȯ�Ѵٰ� �Ͽ��� ��(n > r)
	* n������ r������ ���������� ��Ÿ�� �� �ִٸ�(=> n == r ^ x)
	* n������ r���� ��ȯ�� �߰����� ������ ���� ���̵�
	* �� �ڸ��� �ɰ��� �͸����� ��ȯ�� �����ϴٴ� ���Դϴ�.
	* �� ����, ������ �ؾ� ���� ���� ���ó���?
	* n�� x�� �������� ���ڸ� ���� �� ��,
	* n ^ x�� ���ڸ��� x���� �ڸ��� �ɰ��� ������ ���ڴٴ� �̴ϴ�!
	* �׸��� �� ������ 32��Ʈ�� ����ȭ ��Ű�� ���Դϴ�!
	* �׷� ���� n������ �� �� ������ ��� �ұ��?
	* ���⿡�� radix_a�� ���� ������ ���ɴϴ�.
	* �� ���� ������ �����ϴ�.
	* 2^32 >= n ^ x (n������ x��)�� �����ϴ� ���� ū x
	* 32��Ʈ�� ��Ÿ�� �� �ִ� n������ �ִ� ���� ���ϴ� ���Դϴ�.
	* �̰��� radix_a��� �迭�� ������ �ξ����ϴ�.
	* �׸��� n ^ x ���� radix_b��� �迭�� ������ �ξ�����.
	* ��������� �����غ���
	* 2���� ���� n�������� ��ȯ, ����ϴµ� �־�
	* 32��Ʈ�� ����ȭ ��Ű�� ���ؼ�
	* 2���� ���� n������ x�� �������� ���� ��ȯ�� ��,
	* n������ x�� ������ �� �ڸ��� n���� x���� �ɰ��� ������
	* ����Ѵٸ� �̰��� 2���� ���� n�������� ǥ���ϴ� �Ͱ� ����!
	* ��� ���� �� �� �ֽ��ϴ�.
	* ��... ���� ��� �ؾ� �ϴ��� ������ ���߽��ϴ�.
	* �ٵ� �߰� ������ ������� �ʾҽ��ϴ�.
	* 2���� ���� n ^ x �������� �����Ѵٰ� �ߴµ�
	* ��� �����Ұ��ΰ� �ϴ� �̴ϴ�.
	*
	* "Shift and Add 3(Double Dabble) algorithm"
	* ���� ��ȯ �ϴ� ��� �ƽó���?
	* 10������ 8�������� �ٲܷ���
	* 8�� ����� �� ���������� �������� ���� �ȴٰ� ������ϴ�.
	* ��, ��� ���� n�������� �ٲ۴ٸ� �� ���� n���� �����
	* �� ���������� �������� ���� �˴ϴ�.
	* �̰��� ���� 32��Ʈ ����ȭ�� ���信 �����ϴٸ�
	* ����ϰ��� �ϴ� ���ڸ� n ^ x�� ������
	* �� �������� �������� �����ϸ�
	* 2���� ���� n ^ x�������� �ٲپ� ������ �� �ֽ��ϴ�.
	* �ʱ� ��� �Լ��� �˰��� �׷����ϴ�.
	* n ^ x�� ����� ���� _ltoa_s�Լ��� ����Ͽ�
	* �� �ڸ��� n�������� ��ȯ ����ϴ� ���Դϴ�.
	* �ٵ�, �� ����� Ȯ���� �����ϴ�.
	* ����, ���������ٴ� ����, ������ ������
	* ���� �������ٴ� ��Ʈ, ����Ʈ ������ �����ϴ�.
	* ���⼭ ����� �˰��� �̸���
	* shift and add 3 �˰��� �������� double dabble �˰���(���� ������)�Դϴ�.
	* �̸������� ���� binary�� bcd�� �ٲٴµ� ����Ʈ�� �������� �̿��ϸ�
	* ����� �������� ���ϴ� ����� ���ؼ� ȿ������ �˰����Դϴ�.
	*
	* �Ʒ� ��ũ�� ��Ű�ǵ�ƿ� �ִ� ������ �˰��� ���� ������̸�
	* http://en.wikipedia.org/wiki/Double_dabble
	*
	* ������ ��ũ�� �� ��α׿� ���� ���� �����غ� ���Դϴ�.
	* http://transparenttape.tistory.com/entry/Double-DabbleShift-and-add-3-Algorithm
	* ������ �˰����� �� �𸣽ðڴٸ� �����Ͻñ� �ٶ��ϴ�.
	*
	* "Double Dabble algorithm in 32 bits"
	* radix_a�� ���� 32��Ʈ���� 10�������δ� 9�ڸ��� ǥ�� �� �� ������ �� �� �ֽ��ϴ�.
	* ���� ��� �˰����� ���� �ϼ̴ٸ�, ���⵵ ���ذ� �� ���Դϴ�.
	* 5�̻� 3�� ���ϴ� ����
	* 500000000(5��)�̻� 1647483648�� �����ָ� �˴ϴ�.
	* 5�� �̻��� ���� �� ���ڸ� ���� ��, ����Ʈ�� ���ְ� �Ǹ� 2^32�̻��� �Ǿ�
	* �ڸ��ø��� �߻��ϰ� �˴ϴ�.
	* ������ �����ϸ�, ���ڸ� �ٸ����Դϴ�.
	*
	* "Double Dabble algorithm in 32 bits for arbitrary radix"
	* ���� ������ �˰����� ���������� �����غ��ڽ��ϴ�.
	* 5�̻��� ������ 3�� �����ְ� ����Ʈ ���شٰ� �� �˰����� �ٽ��Դϴ�.
	*
	* 5, 3�̶�� ���ڰ� ���� ������ ������ ���ٸ�
	* 5 = ��ȯ�ϰ��� �ϴ� ������ ��    ... (a)
	* 3 = ( (2 ^ ����Ǵ� ���� �Ѻ��� ��Ʈ ��) - ��ȯ�ϰ��� �ϴ� ���� )/2    ... (b)
	* �� ���� ������ ���°��Դϴ�.
	*
	* 5 = 10 / 2
	* 3 = (2^4 - 10) / 2
	*
	* ���� �� �Ĵ�ζ�� ��� ������ ���ؼ��� �˰����� ������ �� �ֽ��ϴ�.
	* ������, Ȧ�� ���������� (a)���̳� (b)���̳� ��� 0.5�� ����ϴ�.
	* ��������δ� Ȧ�� ������ �ÿ�����, (a)���� �ø�, (b)���� ���� ó���մϴ�.
	* �� �׷��� �ϴ����� �ش� �˰��� �κп��� �ٽ� �����ϰڽ��ϴ�.
	* ���⼭ (b)���� radix_c�� ���� ���Դϴ�. (a)���� radix_b�� ���������� 1 ����Ʈ �ϸ� ������
	* (b)���� ���� �����ϱ� ������ �̸� ���س����ϴ�.
	*
	* ���� �� �����Դϴ�.
	* ����� �ϴµ� �־ 2���� ���� n������ x�� �迭�� ��ȯ ������ ��,
	* �� �迭�� ����Ǿ� �ִ� ���� n������ x���� ���ڷ� �ɰ��� ������ ����� �� ���̸�
	* ���⼭ n������ x�� �迭�� �����ϴ� ����� ������ �˰�����
	* 32��Ʈ�� ����ȭ, ������ �������� ����ǵ��� Ȯ���Ͽ� ����Ѵ�.
	* ��������� �� �����Դϴ�.
	* ���� radix_d�� ���ҽ��ϴ�.
	* radix_d�� n������ x�� �迭�� ũ�⸦ ���ϴ� �Ŀ������� ����Ǿ����ϴ�.
	* 2������ x�ڸ��� ���� 10�����δ�
	* x * log10(2) �� �ø��� �ڸ�����ŭ�� �˴ϴ�.
	* �̰��� 32��Ʈ�� ���� �����غ���
	* 2���� 32 * x�ڸ��� ���� 10������
	* 32 * lgo10(2) * x�ڸ��� �˴ϴ�.
	* ���⼭ ���ϰ��� �ϴ� ���� 10���� �迭�� ũ���̹Ƿ�
	* �� ���ڸ� 9�� ������ �ݴϴ�.
	* �׷��� (32 * lgo10(2) * x) / 9�� �Ǹ�
	* �̰��� n�������� Ȯ���Ϸ��� �� �Ŀ� log10(n)�� ������ �ָ� �˴ϴ�.
	* �׷��� ������ ���� ���� ������
	* ( ( 32 * log10(2) ) / ( log10(n) * radix_a[n]) ) * x
	* radix_d�� ( 32 * log10(2) ) / ( log10(n) * radix_a[n])�� ���ϴ� ���̸�
	* ���� ���� 10000�� ���ϰ� �ø� ó�� �Ͽ����ϴ�.
	*/

	/*
	* 2^32 >= n ^ x (n������ x��)
	* �� �����ϴ� ���� ū x��
	* n�� ���Ͽ� ������������ �����س����� �Դϴ�.
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
	* radix_a�� �̿��� �̸� ���س���
	* 2^32 >= n ^ x (n������ x��)
	* �� �����ϴ� ���� ū  n ^ x��
	* n ^ radix_a[n]�� ���س��� ���Դϴ�.
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
	* radix_b�� �̿��� �̸� ���س���
	* n������ 
	* "(2^32 - radix_b[n])/2"
	* �� ���ϰ� ���� �� ���Դϴ�.(==�Ҽ��� ���� ����)
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
	* radix_a�� �̿��� �̸� ���س���
	* n������
	* ( 32 * log10(2) ) / ( log10(n) * radix_a[n])
	* �� ���� ��, 10000�� ���ϰ� �ø� �� ���Դϴ�.(==�Ҽ��� ���� �ø�)
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
#pragma region ����/�ı�/��ȯ

#pragma region ���������Լ�
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

#pragma region �⺻/�������/���Կ���
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

#pragma region �⺻�����κ��ͻ���/��ȯ
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
		throw "������ Unsigned�� �ٲ� �� �����ϴ�.";
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
	throw "���� �ʹ� Ŀ�� ��ȯ �� �� �����ϴ�.";
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
		throw "���� �ʹ� Ŀ�� ��ȯ �� �� �����ϴ�.";
	}
#endif
	return (sign == Positive) ? x : -x;
}
#pragma endregion

#pragma region ���ڿ��κ��� ����/��ȯ
void BigInteger::DoubleDabble(BigInteger &dest, int radix) const
{
	if ( !( radix >=2 && radix <=36 ) )
	{
#if defined(_DEBUG)
		throw "2 ~ 36���������� �����մϴ�.";
#else
		return;
#endif
	}
	// 0�� �� �Լ��� ȣ���� �Լ����� ���� ó���մϴ�.
	// 0�� ���Ƕ�����, �Ҵ���� ���� �ּҸ� �����ϰ� �Ǿ� ������ ���ϴ�.
	// ����, ���ʿ� ������ ������� 0�� ���ؼ��� ����� �ϰ� �Ͽ���,
	// ���⼭�� 0�� ���ؼ��� �Ű� ���� �ʰ� �Ͽ����ϴ�.
	// �� �˰����� ������ ���α׷��� ������ ��ȹ�̶��
	// ���⿡ 0�� ���� ó���� �� �ʿ䰡 ���� ���� �ֽ��ϴ�.

	// ���� this�� ��� �ƴϸ� �����Դϴ�.

	// ����ϰ��� �ϴ� ������ Ȧ�����
	// DD_Odd�Լ��� �����ϴ�.
	// radix�� Ȧ���� ��,
	// ¦���� ���� ���ؼ�, �߰������� ó���ؾ� �Ұ��� �ʹ� ���Ƽ�
	// �ƿ� ¦���� Ȧ���� ���� �и��Ͽ����ϴ�.
	if (radix & 1)
	{
		DD_Odd(dest, radix);
		return;
	}

	// dest�� �� �� �ִ� �ִ� ���̸� ���մϴ�.
	length maxlen = length(unsigned __int64(len)*radix_d[radix]/10000 + 1);
	dest.Reallocate(maxlen);
	dest.Blkinit();
	dest.len = 1; // �ʱ� dest�� ���̸� 1�� �����մϴ�.
	dest.sign = sign;

	index i, j;
	length bit;
	blocktype bound = blocktype(radix_b[radix]>>1);

	i = len;
	while (i--) // this�� ���� �ڸ��� blk����
	{
		bit = N;
		while (bit--) // blk�� ���� �ڸ�����
		{
			// dest�� ��� blk�� �˻��Ͽ�
			// bound�̻��� ���� ã�� �����ݴϴ�.
			j = dest.len;
			while (j--)
			{
				if (dest.blk[j] >= bound)
					dest.blk[j] += radix_c[radix];
			}

			// dest�� ���̸� �ϳ� �÷��ݴϴ�.
			if (dest.blk[dest.len - 1] & 0x80000000) ++dest.len;

			// dest�� ��� ���� �������� 1 ����Ʈ�մϴ�.
			j = dest.len;
			while (j--)
			{
				dest.blk[j] <<= 1;
				if (j != 0 && dest.blk[j - 1] & 0x80000000)
					dest.blk[j] |= 1;
			}

			// this���� dest�� 1��Ʈ �����մϴ�.
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
	dest.len = 1; // �ʱ� dest�� ���̸� 1�� �����մϴ�.
	dest.sign = sign;

	index i, j, k;
	length bit;
	blocktype rb = blocktype(radix_b[radix]);
	blocktype bound = blocktype(rb >> 1) + 1;
	blocktype **isadd;
	isadd = (blocktype**)malloc(maxlen << 2);

	i = len;
	while (i--) // this�� ���� �ڸ��� blk����
	{
		bit = N;
		while (bit--) // blk�� ���� �ڸ�����
		{
			// dest�� ��� blk�� �˻��Ͽ�
			// bound�̻��� ���� ã�� �����ݴϴ�.
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

			// dest�� ���̸� �ϳ� �÷��ݴϴ�.
			if (dest.blk[dest.len - 1] & 0x80000000) ++dest.len;

			// dest�� ��� ���� �������� 1 ����Ʈ�մϴ�.
			j = dest.len;
			while (j--)
			{
				dest.blk[j] <<= 1;
				if (j != 0 && dest.blk[j - 1] & 0x80000000)
					dest.blk[j] |= 1;
			}

			// this���� dest�� 1��Ʈ �����մϴ�.
			if(blk[i] & (1ul<<bit) )
				dest.blk[0] |= 1;

			// 0.5�� ������ ���Ѱ��� �����մϴ�.
			while (k)
				++(*isadd[--k]);

			// Ȧ�� ���������� ��Ÿ���� ��������
			// ����Ʈ �� �� ��
			// radix_b[raidx]���� ũ�ų� ���� ����
			// �߻� �մϴ�.
			// �̷� ������ ó�����־�� �ٸ� ���� ���ɴϴ�.
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
	// 2~36���� ��η� �Է� �� �� �ֽ��ϴ�.
	// ��, �Է¿��� �߻��� �� �ִ� �Ǽ��� �������� �ʽ��ϴ�!
	// ����.. 1234a324aa32432a�� 10�������� �Է� �Ѵٸ�
	// atoi �Լ������� 1234�� ������ ���⼭�� 4�� �˴ϴ�.
	if ( !( radix >=2 && radix <=36 ) )
	{
#if defined(_DEBUG)
		throw "2 ~ 36���������� �����մϴ�.";
#else
		return *this;
#endif
	}
	// *this�� 0���� �ʱ�ȭ �մϴ�.
	// 0���� �ʱ�ȭ ���� ������ const char *
	// const string & �����ڿ��� ������ ����
	// �� �Լ��� ���� ���ÿ��� ��Ȯ�� ���� ������ ���� �� �ֽ��ϴ�.

	/*Allocate(1);
	blk[0] = 0;
	sign = Zero;*/
	Reset();
	if (str.size() == 1 && str[0] == '0')
		return *this;
	// ���ڿ��� ��� ��� ������ ���մϴ�.
	length read_length = radix_a[radix];
	// �Է��� ����� ������ �����ϸ� �˴ϴ�.
	// �����ڸ����� read_length�� ���� �����Ϳ�
	// base�� j�� ���ؼ� �������� ������� ���ϸ� �˴ϴ�.
	BigInteger base(radix_b[radix]);
	// ���ڿ��� ���̸� ���մϴ�.
	unsigned long offset = str.size();
	// ���� _Copy_s �Լ��� �ʿ�� �մϴ�.
	// ��Ȯ�� ��ġ�� ������ �μ��� �־��
	// ��Ȯ�ϰ� �������� �۵��մϴ�.
	length blocklen = offset / read_length;
	unsigned long rest = offset % read_length;
	// read_length��ŭ �������� ��� �����մϴ�.
	char temp[33] = {0,};
	// ���ڿ��� �����̻��� ����, ���ڰ� �ִ��� �����ϱ� ���ؼ� ����մϴ�.
	char *error_ptr;
	BigInteger x;

	// ���ڿ� �� �տ� ��ȣ�� ���� �� �ֽ��ϴ�.
	// ��ȣ�� ���� ��츦 ó���� �ݴϴ�.
	unsigned long signexist = 0;
	if (str[0] == '+')
	{
		if (str.size() == 2 && str[1] == '0')
			return _Zero;
		// + ��ȣ�� �ִٰ� �ؼ� sign�� ���Թ��� �ʽ��ϴ�.
		signexist = 1;
	}
	else if (str[0] == '-')
	{
		// "-0"�� ���� ����Դϴ�.
		if (str.size() == 2 && str[1] == '0')
			return _Zero;
		// �� �ۿ� ������ ��ȣ�� �����մϴ�.
		signexist = 1;
		sign = Negative;
	}
	if (sign != Negative)
		sign = Positive;
	unsigned long i, j;
	i = 0;
	j = 0;
	// read_length�� �����ϰ� ���� ���� �� �ִ� ���
	// while�������� ���� �˴ϴ�.
	while (blocklen--)
	{
		// offset�� ���ڿ��� �� ������
		// read_length��ŭ ���ݴϴ�.
		offset -= read_length;
		// offset���� read_length��ŭ �о temp�� ����
		str._Copy_s(temp, 33, read_length, offset);
		// strtoul�Լ��� �������� ���ִ� ���ڿ���
		// unsigned long������ �ٲ��ݴϴ�.
		// ���� �����ڷ� x�� �� ���Ե˴ϴ�.
		x = strtoul(temp, &error_ptr, radix);
		// x�� base�� j�� ���մϴ�.
		// �ڸ����� �����ؾ��ϱ� �����Դϴ�.
		while (j--)
			x *= base;
		add(*this, x);
		j = ++i;
		// ���ڿ��� ���� �̻��� ����,���ڰ� ������
		// goto�� �Լ��� �����ŵ�ϴ�.
		// throw�� ������ �ʽ��ϴ�.
		if (*error_ptr != 0)
			return *this;
	}
	// read_length�� �����ϰ� ���� ���� �� �ִ� ���
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
	std::string str; // ���ϵǴ� ���Դϴ�.

	if ( !( radix >=2 && radix <=36 ) )
	{
#if defined(_DEBUG)
		throw "2 ~ 36���������� �����մϴ�.";
#else
		return str;
#endif
	}

	BigInteger dest;
	str.reserve( dest.len * radix_a[radix] );

	// 0 ó��
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
	_ltoa_s(dest.blk[i], prM, radix); // ���� ���� �ڸ� ó��
	str += prM;
	// �� ���ϴ� 00001�� ���� �տ� 0�� ���� ���� �ֱ� ������
	// 0�� �־�� �Ѵٸ� 0�� �߰��� ��, ���� �����ϴ� ������� ó���ؾ� �մϴ�.
	unsigned long j;
	while (i)
	{
		--i;
		memset(prM, 0, 33);
		_ltoa_s(dest.blk[i], prM, radix);
		// ���� 0�� ����
		j = strlen(prM);
		if (j != radix_a[radix])
			while (j != radix_a[radix])
			{
				str += '0';
				j++;
			}
			// 0 ���� ��, str�� prM�� ����
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
		throw "2 ~ 36���������� �����մϴ�.";
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

#pragma region �񱳿���
const int BigInteger::compare(const BigInteger &x) const
{
	if (this == &x)
		return 0;
	if (len < x.len)
		return -1;
	else if (len > x.len)
		return 1;
	else {
		// �Ѻ��� �����ڸ����� ���մϴ�.
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
		// ��� ���� ���� ����̹Ƿ�, ũ�Ⱑ �����ϴ�.
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
		// ��ȣ�� ���� ���ϰ��� �޶����ϴ�.
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
			return false; // �� ���� ���� ����̹Ƿ�
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
			return true; // �� ���� ���� ���
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

#pragma region ��Ʈ����
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
	// �� �� �ϳ��� 0�̶�� ���갪�� 0�Դϴ�.
	if (sign == Zero || x.sign == Zero)
		return temp;

	// temp�� ���̴� �� �� ª�������� ���Ҵ��մϴ�.
	temp.Allocate( (len < x.len) ? len : x.len );

	index i;
	for (i = 0; i < temp.len; i++)
		temp.blk[i] = blk[i] & x.blk[i];

	temp.sign = (sign == Positive || x.sign == Positive) ? Positive : Negative;
	// ���� 0 ���� ���� �մϴ�.
	temp.ZapLeadingZeros();
	// this�� x�� ��Ʈ�� �������� �ϳ��� ������...
	// temp�� 0�Դϴ�.
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
	// �� �� 0�� ���
	if (sign == Zero && x.sign == Zero)
		return temp;
	// this�� 0�� ���
	else if (sign == Zero)
		return x;
	// x�� 0�� ���
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
	// ���� ����� 0�� ���� �� �����ϴ�./
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
	// �� �� 0�� ���
	if (sign == Zero && x.sign == Zero)
		return temp;
	// this�� 0�� ���
	else if (sign == Zero)
		return x;
	// x�� 0�� ���
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
	// ���� ����� 0�� ���� �� �ֽ��ϴ�.
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

#pragma region ����Ʈ����
const BigInteger::blocktype BigInteger::Get_LShiftedBlock(index x, length n) const
{
	// x�� 0~len������ ������ �����ϴ�.
	// n�� 0~31������ ������ �����ϴ�.

	// x �� ����� ���� n��Ʈ�� ���� �մϴ�.
	blocktype lowblk = (x == 0 || n == 0) ? 0 : ( blk[x - 1] >> (N - n) );
	// x ����� �������� n�� ����Ʈ�մϴ�.
	blocktype highblk = (x == len) ? 0 :( blk[x] << n );
	// �� �� ���� �������� �����մϴ�.
	return lowblk | highblk;
}
const BigInteger BigInteger::operator <<(int leftmove) const
{
	// (*this) * 2^(leftmove)�� ����
	BigInteger temp; // ����� ���Ͽ�
	/*
	* Ư�� ��츦 �����մϴ�.
	* 1. *this�� 0�̸�, 0 ����
	* 2. leftmove�� 0�̸�, *this ����
	* 3. leftmove�� ������, >> ����Ʈ�� ����
	*/
	if (sign == Zero)
		return temp;
	if (leftmove == 0)
		return *this;
	else if (leftmove < 0)
		return *this >> (-leftmove);
	length shiftblocks = leftmove / N;
	length shiftbits = leftmove % N;

	// +1�� shitfbits������ ����� �߰��Ǵ� ��� �����
	temp.Allocate(len + shiftblocks + 1);
	temp.Blkinit();

	// �Ѻ��� shiftbits��ŭ ����Ʈ ���� �������ݴϴ�.
	index i, j;
	for (i = 0, j = shiftblocks; i <= len; i++, j++)
		temp.blk[j] = Get_LShiftedBlock(i, shiftbits);

	// Get_LShiftedBlock(len - 1, shiftbits)�� 0�� ���...
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
	// ������� 0�� ������ ���
	if (unsigned __int64(rightmove)  >= bitlength())
		return temp;

	length rightShiftBlocks = (rightmove + N - 1) / N;
	length leftShiftBits = N * rightShiftBlocks - rightmove;
	// ���� (N * rightShiftBlocks - leftShiftBits) == rightmove
	// �׸��� 0 <= leftShiftBits < N �� �����մϴ�.

	// + 1: �ֻ��� �� �����Դϴ�.
	temp.Allocate(len + 1 - rightShiftBlocks);

	index i, j;
	for (j = rightShiftBlocks, i = 0; j <= len; j++, i++)
		temp.blk[i] = Get_LShiftedBlock(j, leftShiftBits);
	if (temp.blk[temp.len - 1] == 0)
		temp.len--;
	// ������ ������� 0�� ������ ���� ���� �Ͽ��� ������
	// �״�� ��ȣ�� �ִ´�.
	temp.sign = sign;
	return temp;
}
const BigInteger &  BigInteger::operator >>=(int rightmove)
{
	return *this = *this >> rightmove;
}
#pragma endregion

#pragma region ��Ģ/������/����
void BigInteger::add(const BigInteger &Left, const BigInteger &Right)
{
	// Left�� Right�� ũ�⸦ ���Ͽ� this�� �����ϴ� �Լ��Դϴ�.

	// stob �Լ�����
	// this->add(*this, x)�� ���� ȣ���ϱ� ������
	if (this == &Left)
	{
		BigInteger Left_temp(Left);
		add(Left_temp, Right);
		return;
	}
	// ȣ�� �Լ��κ��� �����ϰ� �ϱ� ���ؼ�
	if (Left.len < Right.len)
	{
		add(Right, Left);
		return;
	}
	// ����, Left�� Right�� ���̰�����
	// Left.len >= Right.len �� ����
	Reallocate(Left.len + 1);

	blocktype blk_temp = 0; // �� ���� ���� ��� �����ϱ� ����
	// �ڸ��ø� ó����
	// carryIn : ���� �ڸ����� �ڸ��ø� �߻�?
	// carryOut : �� �ڸ����� �������� �ڸ��ø� �߻�?
	bool carryIn, carryOut;
	index i;
	// ���� �ڸ� ��ŭ ������ ���� ���� ����
	for(i = 0, carryIn = false; i < Right.len; i++){
		blk_temp = Left.blk[i] + Right.blk[i];
		// �ڸ� �ø��� �߻��ϸ�
		// blk_temp < Left.blk[i]
		// blk_temp < Right.blk[i]
		// �� �ΰ��� ��� �����Ѵ�.
		// �׷��� �� ���߿� �ϳ��� ����Ͽ� ���� �ָ�ȴ�.
		carryOut = (blk_temp < Left.blk[i]);
		if (carryIn) { // �� �ڸ����� �ڸ��ø� �߻��ߴ°�?
			++blk_temp;
			// CarryIn���� ���� �ڸ��ø� �߻� ���ɼ� ó��
			carryOut |= (blk_temp==0);
		}
		blk[i] = blk_temp;
		carryIn = carryOut;
	}

	// blk[Right.len - 1]���� �ڸ��ø� �߻��ߴ°�?
	// ����, ū ���ɼ��� ������ ���� �ڸ��ø��� �����ϴ�
	// ex) 799 + 1�� ���� ���� ����� �ƶ�
	for(; carryIn && i < Left.len; i++){
		blk[i] = Left.blk[i] + 1;
		carryIn = (blk[i] == 0);
	}

	// �������� �״�� ����
	for(; i < Left.len; i++){
		blk[i] = Left.blk[i];
	}

	// ���� �ڸ��ø��� ������ �Ͼ ����̴�.
	// ������ 799 + 1�� �ƴ� 999 + 1�� ���� ����.
	// ���갪�� �ڸ����� 1 �����ϸ� ������ �ڸ��� ���ڴ� 1�̴�.
	// �ƴ϶�� len 1 ����
	if(carryIn) blk[i]=1;
	else len--;
}
void BigInteger::subtract (const BigInteger &Left, const BigInteger &Right)
{
	// Left�� ũ�⿡�� Right�� ũ�⸸ŭ�� ���� this�� �����ϴ� �Լ��Դϴ�.

	// �� �Լ��� ȣ���ϴ� �Լ����� left�� ũ�Ⱑ �׻� ũ���� ����
	// | Left | - | Right |
	// �� �����Ѵٴ� �����Ͽ� subtract�Լ��� �۵��մϴ�.

	// �ʱ⿡�� divideWithRemainder�Լ�����
	// subtract�Լ��� this->subtract(*this, x)�� ���� ȣ���Ͽ�
	/*
	if (Left.len < Right.len)
	{
	add(Right, Left);
	return;
	}
	*/
	// �� �ʿ��Ͽ�����, divide..�Լ��� �˰����� �ٸ� ������
	// ��ü �ϸ鼭 subtract�Լ��� ȣ������ �ʰԵǾ� �����Ͽ����ϴ�.

	// ���µ� �� ���ִ� ���� �� ���̴� Left.len
	Reallocate(Left.len);

	blocktype blk_temp = 0; // �� ���� ���� ��� �����ϱ� ����
	// �ڸ����� ó����
	// borrowIn : ���� �ڸ����� �ڸ����� �߻�?
	// borrowOut : �� �ڸ����� �������� �ڸ����� �߻�?
	bool borrowIn, borrowOut;
	index i;
	// ���� �ڸ� ��ŭ ������ ���� ���� ����
	for(i = 0, borrowIn = false; i < Right.len; i++){
		blk_temp = Left.blk[i] - Right.blk[i];
		// �ڸ� ������ �߻��ϸ�
		// blk_temp > Left.blk[i]
		// blk_temp > Right.blk[i]
		// �� �ΰ��� ��� �����Ѵ�.
		// �׷��� �� ���߿� �ϳ��� ����Ͽ� ���� �ָ�ȴ�.
		borrowOut = (blk_temp > Left.blk[i]);
		if (borrowIn) { // �� �ڸ����� �ڸ����� �߻��ߴ°�?
			// BorrowIn���� ���� �ڸ����� �߻� ���ɼ� ó��
			borrowOut |= (blk_temp==0);
			blk_temp--;
		}
		blk[i] = blk_temp;
		borrowIn = borrowOut;
	}

	// blk[Right.len - 1]���� �ڸ����� �߻��ߴ°�?
	// ����, ū ���ɼ��� ������ ���� �ڸ������� �����ϴ�
	// ex) 1000 - 1�� ���� ���� ����� �ƶ�
	for(; borrowIn && i < Left.len; i++){
		borrowIn = (Left.blk[i] == 0);
		blk[i] = Left.blk[i] - 1;
	}

	// �������� �״�� ����
	for(; i < Left.len; i++)
		blk[i] = Left.blk[i];

	// ���� ����� ����� ���� 0������ ��� ����
	ZapLeadingZeros();
}
void BigInteger::multiply(const BigInteger &Left, const BigInteger &Right)
{
	// �� ���� ũ�⸦ ���Ͽ� this�� �����ϴ� �Լ��Դϴ�.

	// n�ڸ� * m�ڸ� ���� ����� �ִ� (n+m)�ڸ��� �˴ϴ�.
	Reallocate(Left.len + Right.len);
	Blkinit();

	// �� 32��Ʈ�� �������δ� �ִ� 64��Ʈ�� ���ɴϴ�.
	// ����, �� ����� ���갪�� �����ϱ� ����
	// unsigned __int64������ �ӽ� ���� ������ ����ϴ�.
	unsigned __int64 temp_res;
	// �ӽ� ���尪�� ��Ͽ� �ֱ� ���ؼ��� 64��Ʈ��
	// �ٽ� 32��Ʈ�� ������ ����մϴ�.
	blocktype blk_temp[2] = {0,};
	/*
	* ���� �˰����� �ʵ��б��� ���� ����� ����Ͽ����ϴ�.
	* ��� ���ڸ��� ����ϴ°� �ƴ� 32��Ʈ�� ����ϴ� �ͻ��Դϴ�.
	* ���ͳݿ��� �̷� ����� 'Schoolbook Multiplication' �̶�� �ϳ׿�.
	* Google���� Fast Multiplication�� ġ�� ���� �ڷᰡ ���ɴϴ�.
	*/
	index i,j,k,l;
	for(i = 0; i < Left.len; i++){
		temp_res = 0;
		for(j = 0; j < Right.len; j++){
			// �� ���� ���Ͽ� 32��Ʈ�� �ɰ��� �����մϴ�.
			temp_res = unsigned __int64(Left.blk[i]) * Right.blk[j];
			blk_temp[0] = blocktype(temp_res);
			blk_temp[1] = blocktype(temp_res >> N);

			for (k = i + j, l = 0; l < 2; l++)
			{
				blk[k] += blk_temp[l];
				// ���ߴµ� blk[k]���� �ڸ� �ø��� �߻��Ѵٸ�!!!
				if (blk[k] < blk_temp[l])
				{
					// ���� �ڸ��ø��� ��쵵 �����Ͽ�
					// ���� �ڸ��ø��� �߻����� ���� ������
					// ���� �ڸ����� 1 ������Ų��.
					for (;;)
					{
						blk[++k]++;
						if (blk[k] == 0)
							continue;
						else
							break;
					}
				}
				// blk_temp[0]�� ���� ��� ��,
				// blk_temp[1]�� ������ ����, k ������
				k = i + j + 1;
			}
		}
	}

	// len�� ���̴� '�ִ�' Left.len + Right.len�� �� �� ������
	// Left.len + Right.len - 1�� �� �� �ִ�.
	if (blk[len - 1] == 0)
		len--;
}
void BigInteger::divideWithRemainder(const BigInteger &Divisor, BigInteger &Quotient)
{
	/*
	* ������ ���������� ū ���� �������� �� �ʿ䰡 �����ϴ�.
	* ���� 0, �������� �������� ���״ϱ��.
	* ������ ���� �ʾƵ� �Ǳ� ������, �̿� ���� ����
	* ������ ���ǹ����� �ɷ��ִ°��� ����ӵ��� ������ �� �ټ� �ֽ��ϴ�.
	* ������ �� ���ǹ����� �ð��� ���� ��Ƹ����� �ȵ˴ϴ�.
	* 
	* ���� > ������ �� �Ǻ��� �� �ִ� ������δ�
	* ��Ȯ�� 1������ �뷫���� 2���� ����� �ֽ��ϴ�.
	*
	* 1. compare�Լ��� ����Ͽ� ũ�Ⱑ ū�� �Ǻ��ϱ�
	*     ���� ��Ȯ�� ���������, ���� �ɸ��ϴ�.
	*     ū ������ ���� ������ �������� ũ�Ⱑ ���ٸ�
	*     for���� ���鸸���� �� ���� �ֽ��ϴ�.
	*
	* 2. ������ �������� ��Ʈ ���� üũ�ϱ�
	*     ��Ʈ ���̴� ���� ���� ��Ʈ�� ��� �ִ����� ��Ÿ���� �Ͱ� �����ϴ�.
	*     ����, ���� ���� ��Ʈ�� ������ ������ ū ���� �����ϰ�
	*     ex) ������ : 10(2), ���� : 11(3)
	*     �������� �Ǻ����� �մϴ�.
	*
	* 3. ������ �������� �� ���� ��
	*     ���� ���� ����Դϴ�. �ܼ��ϰ� ������ ��������
	*     len�� ���ϴ� ���̱� �����Դϴ�.
	*     ������, �׸�ŭ ��ġ�� ��쵵 �����ϴ�.
	*
	* �� ���� ������� ������ �������� ũ�⸦ ���� �� �ֽ��ϴ�.
	* �� ��, ���� ���� 3��° ����� ����ϰڽ��ϴ�.
	* �ٽ� �ѹ� �����帮����, �� ������ ������ �ʾƵ�
	* ���� ������ ���� ��� �������� ���� �� �ֽ��ϴ�.
	* �ٸ� ���ʿ��� ���� ������ ��ġ�� �ʱ� ���ؼ�
	* �ɷ����� ���̹Ƿ� ��� ��쿡 ���ؼ�
	* �� ��츦 ���� �ʿ�� �����ϴ�.
	*/
	if (blklength() < Divisor.blklength()) {
		Quotient = _Zero;
		return;
	}

	// ����, (*this).len >= Divisor.len �� �����մϴ�.

	/*
	* �������� �����ϴ� ������ �ǰ��� �����ϴ�.
	* ����� ����� �������� ��� ������
	* ����� ����, ������ ������ ���������� ������ �������
	* ���̰� �ֽ��ϴ�.
	* �� �κ��� �����Ϸ����ٵ� ������� �޶����ٰ� �մϴ�.
	* ǥ���� ���ǵ��� �ʾҴٰ� �ϳ׿�..
	* ---------------------------------
	* 2 / (-3) = 0     2 % (-3) = 2
	* ---------------------------------
	* 2 / (-3) = -1    2 % (-3) = -1
	* ---------------------------------
	*
	* 2 / (-3)�� �Ҽ������� �������� ���ϸ�
	* -0.66666666666666666666... �Դϴ�.
	* ���⼭ �Ҽ����� ������..
	* �ƴϸ� �ø� ó�� ������ ���� ����� �޶����� ���Դϴ�.
	* ��, ���� ���� ���� ����ڽ��ϴ�.
	* vc�� ���� ���� ������ �����Դϴ�.
	* �Ʒ��� Matt���� ����Ϳ��� ������ ����ϴ�.
	*/

	/* �������� ���..
	* �˰����� �ʱ��� �˰���� ����մϴ�.
	* �ʵ��б� ��, ���� ������ ����� �״�� ����մϴ�.
	* �ʱ�� �ٸ� ���� �� �� �����ٴ� ���Դϴ�.
	*
	* (�ʱ� ������ �˰���)
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
	* (���� ������ �˰���)
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
	* �ΰ��� �������� �ƽðڽ��ϱ�?
	* ���� ������ �ٸ��ϴ�.
	* �������� 123456 - 111300�� ���Ѵٸ�
	* �Ʒ������� 1234 - 1113�� ���մϴ�!
	* ū ���ڶ�� ��û�� �ӵ����̰� �ƴ� �� �����ϴ�!!
	*/

	index i, j, k;
	unsigned int i2;
	blocktype temp;
	bool borrowIn, borrowOut;

	BigInteger orig(*this);
	length origLen = len;
	// ����, *this.blk[len]�� �����ؾ� �մϴ�.
	// ����, ������ �������� ���Ҵ� �մϴ�.
	Reallocate(len + 1);
	Blkcopy(orig);
	blk[len-1] = 0;
	//memmove(blk, orig.blk, sizeof(blocktype) * origLen);

	// ���� ���� �����ϱ� ���� ����մϴ�.
	blocktype *subtractBuf = new blocktype[len];
	memset(subtractBuf, 0, sizeof(blocktype) * len);

	// ���� �̸� �Ҵ��մϴ�.
	Quotient.Allocate(origLen - Divisor.len + 1);
	// reallocate���� allocate�� �ٲ� 9.14
	Quotient.Blkinit();

	// ���������� ��Ʈ �ϳ��� ����س����ϴ�.
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
	// Quotient.len != 1���� 0���� �ٲ� 9.14
	if (Quotient.len != 0 && Quotient.blk[Quotient.len - 1] == 0)
		Quotient.len--;
	ZapLeadingZeros();

	delete [] subtractBuf;
	// ��� �������� ��ȣ����
	Quotient.sign = (sign == Divisor.sign) ? Positive : Negative;
	if (Quotient.len == 0 /*&& Quotient.blk[0] == 0*/)
		Quotient.sign = Zero;
	if (len == 0 /*&& blk[0] == 0*/)
		sign = Zero;
	// 0��ȣ ���� ���� �ٲ� 9.14
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
	// �� �� �ϳ��� 0�̸� �ٸ� ���� �����ϸ� �˴ϴ�.
	if (sign == Zero)
		return x;
	if (x.sign == Zero)
		return *this;

	BigInteger temp;

	// ��ȣ�� �������..
	if (sign == x.sign)
	{
		temp.add(*this, x);
		temp.sign = sign;
	}
	// �� ���� ��ȣ�� �ٸ��ٸ�, ������ �����ϴ�.
	else
	{
		int cmp;
		// compare�Լ��� this�� x�� 'ũ��'�� ���մϴ�.
		cmp = compare(x);
		if (cmp == 0)
			; // ���� ���� 0����
		else if (cmp == 1)
		{
			// this > x�� ���
			temp.subtract(*this, x);
			temp.sign = sign;
		}
		else
		{
			// x > this�� ���
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
	// �� �� �ϳ��� 0�� �� ó��
	if (x.sign == Zero)
		return *this;
	if (sign == Zero)
	{
		temp = x;
		return -temp;
	}

	// �� ���� ��ȣ�� �ٸ��ٸ� ũ��� ��������
	// ��ȣ�� this�� ������ �˴ϴ�.
	if (sign != x.sign)
	{
		temp.add(*this, x);
		temp.sign = sign;
	}
	// �� ���� ��ȣ�� ���� ��
	else
	{
		int cmp;
		// this�� x�� 'ũ��'��
		cmp = compare(x);
		if ( cmp == 0 )
			; // ���ٸ� ����� 0
		else if ( cmp == 1 )
		{
			// this > x�� ���
			temp.subtract(*this, x);
			temp.sign = sign;
		}
		else
		{
			// this < x�� ���
			temp.subtract(x, *this);
			// this�� ��ȣ�� ���� ������� ��ȣ�� �޶���
			// Zero�� ������ ���� ������ ó�������Ƿ�
			// Zero�� ���� ���� ����.
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
	// �� ���� 0�� ������ ���ϳ����� 0�Դϴ�.
	if (sign == Zero || x.sign == Zero)
		return temp;
	temp.multiply(*this, x);
	// �� ���� ��ȣ�� ������ +, �ٸ��� -�� �˴ϴ�.
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
		throw "0���� ���� �� �����ϴ�.";
#else
		return q; // 0 ����
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
		throw "0���� ���� �� �����ϴ�.";
#else
		return q; // 0 ����
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

#pragma region ��Ÿ����
BigInteger pow(const BigInteger &x, const BigInteger &y)
{
	// x�� y���� ���մϴ�.
	/*
	*	1. x�� 0�� ��
	*		��. y�� 0�� �� -> ����!
	*		��. ������ -> 0
	*	2. x�� 0�� �ƴ� ��
	*		��. y�� 0�� �� -> 1
	*		��. y�� ���� -> ����!
	*		��. y�� ��� -> x ^ y
	*/
	if (x.sign == BigInteger::Zero)
	{
#if defined(_DEBUG)
		if (y.sign == BigInteger::Zero)
			throw "������ �� �����ϴ�.";
#else
		return _Zero;
#endif
	}
	if (y.sign == BigInteger::Zero)
		return _One;
	else if (y.sign == BigInteger::Negative)
	{
#if defined(_DEBUG)
		throw "������ �����Դϴ�.";
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
	// x! �� ���ϴ� ���丮�� �Լ��Դϴ�.
	// ����� �ܼ��� x * (x-1) * ..... (2) * (1)
	// ó�� ���ϱ� �������� ���Ͽ� x�� ���� Ŀ���� �Ǹ�
	// �ӵ��� ��û���� �������ϴ�.
	// 1000! ������ ����¦�� ���̿� ���� �� �ֽ��ϴ�.
	// computer by computer..

	// 0!�� 1�� �����մϴ�.
	// ������ ���丮�� ���� �� �ְ� �Ͽ����ϴ�.
	// ������ ���丮���� ���Ǵ�...
	// x * (x + 1) * (x + 2) .... (-2) * (-1)
	// �� ���� �Ͽ����ϴ�.
	if (x.sign == BigInteger::Zero)
		return _One;
	BigInteger res(x);
	BigInteger count(x);
	// x�� ����� count�� ������Ű�� ���ϱ�
	// ������ ������Ű�� ���ϱ�
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
	// x�� y�� �ִ� ������� ���ϴ� �Լ��Դϴ�.
	// ��Ŭ���� ȣ���� �˰����� ����մϴ�.
	// �������� �߿��ϸ� ���� �ʿ�����ϴ�.
	// ������ �ִ������� ������ ó���ϸ� ������ �ʽ��ϴ�.
	BigInteger trash;
	if (x.sign == BigInteger::Zero || y.sign == BigInteger::Zero)
		return _Zero;
	if (x.sign == BigInteger::Negative || y.sign == BigInteger::Negative)
	{
#if defined(_DEBUG)
		throw "������ ������ �����մϴ�.";
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
	// �ּҰ������ ���ϴ� �Լ��Դϴ�.
	// gcd�Լ��� �̿��Ͽ� ���ϸ�
	// lcm(x, y) = x * y / gcd(x, y)��
	// �������� �̿��Ͽ� ���մϴ�.
	BigInteger _gcd = gcd(x, y);
	// �ִ� ������� 0�̶��
	// �ִ� ������� 0�Դϴ�.
	if (_gcd.sign == BigInteger::Zero)
		return _Zero;
	return x * y / _gcd;
}
#pragma endregion