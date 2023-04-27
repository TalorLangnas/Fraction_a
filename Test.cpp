#include <stdbool.h>
#include <string>
#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/Fraction.hpp"


using namespace std;
using namespace ariel;



// // default:
//     Fraction();
// // reciving to doubles:
//     Fraction(double,double);
// // copy:
//     Fraction(const Fraction&);
// // recive one double
//     Fraction(double);
// // Destructor:
//     ~Fraction() = default;

TEST_CASE("Constructors")
{
// Default:
    Fraction f = Fraction();
    CHECK(f.get_nom()==0);
    CHECK(f.get_den()==1);
// Reciving tow doubles:
    Fraction f2 = Fraction(2,4);
    CHECK(f2.get_nom()==1);
    CHECK(f2.get_den()==2);
// Copy:
    Fraction f3 = Fraction(f2);
    CHECK(f3.get_nom()==1);
    CHECK(f3.get_den()==2);
    CHECK(&f3 != &f2);
// Recive one double:
   Fraction f4 = Fraction(0.5);
   CHECK(f4.get_nom()==1);
   CHECK(f4.get_den()==2); 

}

TEST_CASE("operator (=)")
{
    Fraction c = Fraction(10,2);
    Fraction c_new = Fraction(c);
    CHECK(c.get_nom() == c_new.get_nom());
    CHECK(c.get_den() == c_new.get_den());
    CHECK(&c != &c_new);
    Fraction a = 2.5;
    CHECK(a.get_nom() == 5);
    CHECK(a.get_den() == 2);   
}

TEST_CASE("operator (+)")
{    
    Fraction f1 = Fraction(1,2);
    Fraction f2 = Fraction(4,2);
    CHECK(f1+f2 == 1); // checking sum with other Fraction
    CHECK(f1+1 == 1.5); // checking sum with other int
    CHECK(3.0+f2 == 3.5); // checking sum with other double/int
    CHECK(3+f2 == 3.5); // checking sum with other integer    
}

TEST_CASE("operator (-)")
{    
    Fraction f1 = Fraction(1,2);
    Fraction f2 = Fraction(4,2);
    CHECK(f1-f2 == 0); // checking subtraction with other Fraction
    CHECK(f1-1 == -0.5); // checking subtraction with other int
    CHECK(3.0-f2 == 2.5); // checking subtraction with other double
    CHECK(3-f2 == 2.5); // checking subtraction with other integer    
}

TEST_CASE("operator (*)")
{    
    Fraction f1 = Fraction(1,2);
    Fraction f2 = Fraction(4,2);
    CHECK(f1*f2 == 0.25); // checking multiplication with other Fraction
    CHECK(f1*1.0 == 0.5); // checking multiplication with other double
    CHECK(f1*1 == -0.5); // checking multiplication with other int
    CHECK(3.0*f2 == 1.5); // checking multiplication with other double
    CHECK(3*f2 == 1.5); // checking multiplication with other integer    
}  

TEST_CASE("operator (/)")
{    
    Fraction f1 = Fraction(1,2);
    Fraction f2 = Fraction(4,2);
    CHECK(f1/f2 == 1); // checking division with other Fraction
    CHECK(f1/1.0 == 0.5); // checking division with other double
    CHECK(f1/1 == 0.5); // checking division with other int
    CHECK(3.0/f2 == 1.5); // checking division  of double with Fraction 
    CHECK(3/f2 == 1.5); // checking division of int with Fraction
    CHECK_THROWS(f1/0); // checking throws for division fraction with zero        
}

TEST_CASE("operator (==)")
{
    Fraction f1 = Fraction(1,2);
    Fraction f2 = Fraction(4,2);
    CHECK((f1==f2) == 1);

    double x = 1.000001;
    Fraction f3 = Fraction(5,5);
    CHECK((f3==x) == 1);
    CHECK((x==f3) == 1);
}

TEST_CASE("operator (!=)")
{
    Fraction f1 = Fraction(1,2);
    Fraction f2 = Fraction(4,2);
    CHECK((f1!=f2) == 0);

    double x = 1.000001;
    Fraction f3 = Fraction(5,5);
    CHECK((f3!=x) == 0);
    CHECK((x!=f3) == 0);
}


// // prefix: ++n:
//     Fraction& operator++();

// // postfix: n++:
//     const Fraction operator++(int);

// // // prefix: --n:
//     Fraction& operator--();

// // postfix: n--:
//     const Fraction operator--(int);
TEST_CASE("operator (prefix: ++n)")
{
    Fraction f1 = Fraction(1,2);
    Fraction f2 = Fraction(2,4);
    Fraction f3 = (++f2) + f1;
    CHECK(f3 == 2);
    CHECK(f2 == 1.5);
}

TEST_CASE("operator (postfix: n++)")
{
    Fraction f1 = Fraction(1,2);
    Fraction f2 = Fraction(2,4);
    Fraction f3 = (f2++) + f1;
    CHECK(f3 == 1);
    CHECK(f2 == 1.5);
}

TEST_CASE("operator (prefix: --n)")
{
    Fraction f1 = Fraction(1,2);
    Fraction f2 = Fraction(2,4);
    Fraction f3 = (--f2) + f1;
    CHECK(f3 == 0);
    CHECK(f2 == -0.5);
}

TEST_CASE("operator (postfix: n--)")
{
    Fraction f1 = Fraction(1,2);
    Fraction f2 = Fraction(2,4);
    Fraction f3 = (f2--) + f1;
    CHECK(f3 == 1);
    CHECK(f2 == -0.5);
}