#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <sstream>
#include <stdexcept>
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

    public:
// Constructors:

// default:
    Fraction();
// reciving to doubles:
    Fraction(double,double);
// copy:
    Fraction(const Fraction&);
// Move constructor (for tidy):
    Fraction(Fraction&&) noexcept;     
// recive one double
    Fraction(double);
// Destructor:
    ~Fraction() = default;

// Getters:
    int get_nom();
    int get_den();

//All operators should work on both sides on fractions and doubles type variables.
//on a double var you need use up to 3 digits beyond the desimal point for acuracy.

// operator =:
    Fraction& operator=(const Fraction&);
    Fraction& operator=(double);
// Move assignment operator (for tidy):
    Fraction& operator=(Fraction&& other)noexcept;

//The + operator to add two fractions and return their sum as another fraction in reduced form.
    
    Fraction operator+(const Fraction& other) const;
    Fraction operator+(double other) const;
    Fraction operator+(int other) const;
    friend Fraction operator+(double val1, const Fraction& fraction2)
    {
        return fraction2+(val1);
    };
    friend Fraction operator+(int val1, const Fraction& fraction2)
    {
        return fraction2+(double(val1));
    };  
    //friend Fraction operator+(const Fraction& val1, const Fraction& fraction2);
    // friend Fraction operator+(const Fraction& val1, const double fraction2);
         

//The - operator to subtract two fractions and return their 
//difference as another fraction in reduced form.
    
    Fraction operator-(const Fraction& other) const;
    Fraction operator-(double other) const;
    Fraction operator-(int) const;

    friend Fraction operator-(double val1, const Fraction& fraction2)
    {
        double subtract = val1 - double(fraction2);
        return Fraction(subtract);
    };
    friend Fraction operator-(int val1, const Fraction& fraction2)
    {
        return double(val1) - fraction2;
    };              

//The * operator to multiply 
//two fractions and return their product as another fraction in reduced form.
    
    Fraction operator*(const Fraction&) const;
    Fraction operator*(double) const;
    Fraction operator*(int) const;
    friend Fraction operator*(double val1, const Fraction& fraction2)
    {   
       cout << " enter to friend operator* (double, Fraction)" << endl;
       cout << "double val1 = " << val1 << endl;
       cout << "Fraction& fraction2  = " << fraction2 << endl;
       return fraction2*val1;
    };
    friend Fraction operator*(int val1, const Fraction& fraction2)
    {
         return fraction2*val1;
    };        


//The / operator to divide 
//two fractions and return their quotient as another fraction in reduced form.
    
    Fraction operator/(const Fraction& other) const;
    Fraction operator/(double other) const;
    Fraction operator/(int other) const;
    friend Fraction operator/(double other, const Fraction& fraction2)
    {
        return Fraction(other)/fraction2;
    }; 
    friend Fraction operator/(int other, const Fraction& fraction2)
    {
        return Fraction(other)/fraction2;
    };       


//The == operator to compare two fractions for equality and return true or false.

    bool operator==(const Fraction& other) const;
    bool operator==(double other) const;
    friend bool operator==(double other, const Fraction& fraction2)
    {
        return fraction2==other;
    };

// != operator
    bool operator!=(const Fraction&) const;
    bool operator!=(double) const;
    friend bool operator!=(double value, const Fraction& fraction)
    {
        Fraction d_fraction = Fraction(value);
        return d_fraction == fraction;
    }; 


//All comparison operations (>,<,>=,<=)

// > :
    bool operator>(const Fraction& other) const;
    bool operator>(double other) const;
    friend bool operator>(double other, const Fraction& fraction2)
    {
         return (other > double(fraction2));
    };

// < :
    bool operator<(const Fraction& other) const;
    bool operator<(double other) const;
    // friend bool operator<(const Fraction& val1, const Fraction& fraction2);
    // friend bool operator<(const Fraction& val1, double other);
    friend bool operator<(double other, const Fraction& fraction2)
    {
        return (other < double(fraction2));
    };

// >= :
    bool operator>=(const Fraction& other) const;
    bool operator>=(double other) const;
    // friend bool operator>=(const Fraction& val1, const Fraction& fraction2);
    // friend bool operator>=(const Fraction& val1, double other);
    friend bool operator>=(double other, const Fraction& fraction2)
    {
        return (other >= double(fraction2));
    };
   

// <= :
    bool operator<=(const Fraction& other) const;
    bool operator<=(double other) const;
    // friend bool operator<=(const Fraction& val1, const Fraction& fraction2);
    // friend bool operator<=(const Fraction& val1, double other);
    friend bool operator<=(double other, const Fraction& fraction2)
    {
        return (other <= double(fraction2));
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
        int numerator = 1;
        int denumerator = 1;
        string div_line = "/";
        input >> numerator >> div_line >> denumerator; 
        if (input.good()) 
        {
            if (div_line != "/")
            {
                throw std::invalid_argument("illeagal value");
            }
            fraction = Fraction(numerator, denumerator);            
        }
        
        return input;

    };

// Convert Fraction to double:
    operator double() const;

// to string 
    operator string() const;
    string to_string() const;



};
}

#endif