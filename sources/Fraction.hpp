#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

namespace ariel{

class Fraction
{
    int nom;
    int den;
    //int gcd;
  

    public:
// Constructors:

// default:
    Fraction();
// reciving to doubles:
    Fraction(double,double);
// copy:
    Fraction(const Fraction&);
// recive one double
    Fraction(double);
// Destructor:
    ~Fraction() = default;

// Getters:
    int get_nom();
    int get_den();
    //int get_gcd();


//All operators should work on both sides on fractions and doubles type variables.
//on a double var you need use up to 3 digits beyond the desimal point for acuracy.

// operator =:
    Fraction& operator=(const Fraction&);
    Fraction& operator=(const double);


//The + operator to add two fractions and return their sum as another fraction in reduced form.
    
    Fraction operator+(const Fraction& other) const;
    Fraction operator+(const double other) const;
    Fraction operator+(const int other) const;
    friend Fraction operator+(double c1, const Fraction& c2)
    {
        return c2+(c1);
    };
    friend Fraction operator+(int c1, const Fraction& c2)
    {
        return c2+(double(c1));
    };  
    //friend Fraction operator+(const Fraction& c1, const Fraction& c2);
    // friend Fraction operator+(const Fraction& c1, const double c2);
         

//The - operator to subtract two fractions and return their 
//difference as another fraction in reduced form.
    
    Fraction operator-(const Fraction& other) const;
    Fraction operator-(const double other) const;
    Fraction operator-(const int) const;

    friend Fraction operator-(double c1, const Fraction& c2)
    {
        double subtract = c1 - double(c2);
        return Fraction(subtract);
    };
    friend Fraction operator-(int c1, const Fraction& c2)
    {
        return double(c1) - c2;
    };              

//The * operator to multiply 
//two fractions and return their product as another fraction in reduced form.
    
    Fraction operator*(const Fraction&) const;
    Fraction operator*(const double) const;
    Fraction operator*(const int) const;
    friend Fraction operator*(double c1, const Fraction& c2)
    {
       return c2*c1;
    };
    friend Fraction operator*(int c1, const Fraction& c2)
    {
         return c2*c1;
    };        


//The / operator to divide 
//two fractions and return their quotient as another fraction in reduced form.
    
    Fraction operator/(const Fraction& other) const;
    Fraction operator/(const double other) const;
    Fraction operator/(const int other) const;
    friend Fraction operator/(double other, const Fraction& c2)
    {
        double quotient = other/double(c2);
        return Fraction(quotient);
    }; 
    friend Fraction operator/(int other, const Fraction& c2)
    {
        return double(other)/c2;
    };       


//The == operator to compare two fractions for equality and return true or false.

    bool operator==(const Fraction& other) const;
    bool operator==(const double other) const;
    const float TOLERANCE = 0.001;
    // friend bool operator==(const Fraction& c1, const Fraction& c2)
    // {
    //     double d1 = double(c1);
    //     double d2 = double(c2);
    //     return d1 == d2;
    // };
    friend bool operator==(double other, const Fraction& c2)
    {
        // Fraction other_frac = Fraction(other);
        // return other_frac == c2;
        return other==c2;
    };

// != operator
    bool operator!=(const Fraction&) const;
    bool operator!=(double) const;
    friend bool operator!=(double d, const Fraction& f)
    {
        Fraction d_fraction = Fraction(d);
        return d_fraction == f;
    }; 


//All comparison operations (>,<,>=,<=)

// > :
    bool operator>(const Fraction& other) const;
    bool operator>(const double other) const;
    // friend bool operator>(const Fraction& c1, const Fraction& c2);
    // friend bool operator>(const Fraction& c1, double other);
    friend bool operator>(double other, const Fraction& c2)
    {
         return (other > double(c2));
    };

// < :
    bool operator<(const Fraction& other) const;
    bool operator<(double other) const;
    // friend bool operator<(const Fraction& c1, const Fraction& c2);
    // friend bool operator<(const Fraction& c1, double other);
    friend bool operator<(double other, const Fraction& c2)
    {
        return (other < double(c2));
    };

// >= :
    bool operator>=(const Fraction& other) const;
    bool operator>=(double other) const;
    // friend bool operator>=(const Fraction& c1, const Fraction& c2);
    // friend bool operator>=(const Fraction& c1, double other);
    friend bool operator>=(double other, const Fraction& c2)
    {
        return (other >= double(c2));
    };
   

// <= :
    bool operator<=(const Fraction& other) const;
    bool operator<=(double other) const;
    // friend bool operator<=(const Fraction& c1, const Fraction& c2);
    // friend bool operator<=(const Fraction& c1, double other);
    friend bool operator<=(double other, const Fraction& c2)
    {
        return (other <= double(c2));
    };



//The ++ and -- operator
//that adds (or substracts) 1 to the fraction. implement both pre and post fix.

// prefix: ++n:
    Fraction& operator++();

// postfix: n++:
    const Fraction operator++(int);

// // prefix: --n:
    Fraction& operator--();

// postfix: n--:
    const Fraction operator--(int);



//The << operator to print a fraction to an output stream in the format “numerator/denominator”.
    friend std::ostream& operator<< (std::ostream& output, const Fraction& fraction)
    {
        //output << fraction.nom << '/' << fraction.den;
        output << string(fraction);
        return output;
    };

//The >> operator to read a fraction from an input stream by taking two integers as input.
    friend std::istream& operator>> (std::istream& input , Fraction& fraction)
    {
        int x;
        int y;
        string div_line = "/";
        input >> x >> div_line >> y; 
        if (input.good()) 
        {
            if (div_line != "/")
            {
                throw std::invalid_argument("illeagal value");
            }
            fraction = Fraction(x, y);            
        }
        
        return input;

    };

// Convert Fraction to double:
    operator double() const;

// to string 
    operator string() const;
    string to_string() const;
    //string nom_to_string() const;
    //string den_to_string() const;

//  input - double, output - double with 3 digits after the decimal point:
    double get_3_dig(const double);

};
}

#endif