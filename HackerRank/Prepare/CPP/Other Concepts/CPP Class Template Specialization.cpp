#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

// Define specializations for the Traits class template here.
template<>
struct Traits<Color>
{
    static string name(int e)
    {
        switch(e){
            case static_cast<int>(Color::red): return "red";
            case static_cast<int>(Color::green): return "green";
            case static_cast<int>(Color::orange): return "orange";
        }
        return "unknown";
    }
};

template<>
struct Traits<Fruit>
{
    static string name(int e)
    {
        switch(e){
            case static_cast<int>(Fruit::apple): return "apple";
            case static_cast<int>(Fruit::orange): return "orange";
            case static_cast<int>(Fruit::pear): return "pear";
        }
        return "unknown";
    }
};


int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
