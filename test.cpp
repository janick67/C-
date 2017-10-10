#include <iostream>

int rek ()
{
    std::string buf = "";
    std::cin >> buf;
    buf!="0"? rek() : 0;
    std::cout << buf;
return 0;
    }

int main()
{
    rek();
    std::cout << "Test dzialania Code::Blocks";
    return 0;
}
