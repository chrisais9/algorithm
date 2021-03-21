#include <iostream>
#include <string>
#include <locale>
using namespace std;
int main()
{
    wcin.imbue( locale( "kor" ) );
    wcout.imbue( locale( "kor" ) );
    wstring s;
    wcin>>s;
    if(s==L"사.우.나")wcout<<L"사랑과 우정을 나누자"<<endl;
    else if(s.compare(L"오.징.어"))wcout<<L"오래도록 징그럽게 어울리자"<<endl;
    else if(s.compare(L"사.이.다"))wcout<<L"사랑하자 이 세상 다 바쳐"<<endl;
    else if(s.compare(L"나.가.자"))wcout<<L"나라, 가정, 자신의 발전을 위하여"<<endl;
    else if(s.compare(L"재.개.발"))wcout<<L"재미있고 개성있게 발전적으로 살자"<<endl;
    else if(s.compare(L"우.아.미"))wcout<<L"우아하고 아름다운 미래를 위하여"<<endl;
    else if(s.compare(L"이.기.자"))wcout<<L"이런 기회를 자주 만들자"<<endl;
    else if(s.compare(L"청.바.지"))wcout<<L"청춘은 바로 지금부터"<<endl;
}
