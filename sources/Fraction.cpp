#include "Fraction.hpp"
using namespace std;
using namespace ariel;

// Constructors:

// default:
    Fraction::Fraction(): nom(0), den(1)//, gcd(0)
    {

    };
// reciving to doubles:
    Fraction::Fraction(double nom_other,double den_other) 
    {
        if(den_other == 0)
        {
            throw std::invalid_argument("illeagal value, denominator can not be qeual to zero");
        }
        else if (nom_other == 0)
        {   
            nom_other = 0;
            den_other = 1;
        }
        else
        {
        int gcd_val = __gcd(int(nom_other), int(den_other));
        nom = nom_other/gcd_val;
        den = den_other/gcd_val;   
        }            
         
    };

// copy:
    Fraction::Fraction(const Fraction& other)
    {
        if(this == &other)
        {
            return;
        }
        nom = other.nom;
        den = other.den;      
    };
// Move constructor (for tidy):
    Fraction::Fraction(Fraction&& other)noexcept
    {
        if (this == &other)
        {
            return;
        }
        nom = other.nom;
        den = other.den;        
    };
// Move assignment operator (for tidy):
    Fraction& Fraction::operator=(Fraction&& other)noexcept
    {
        if (this == &other)
        {
            return (*this);
        }
        nom = other.nom;
        den = other.den;
        return (*this);
    };


//  assuming that double does not have more than 3 digits after decimal point 
    Fraction::Fraction(double other)
    {
        if (other == 0)
        {
            nom = 0;
            den = 1;
        }
        else
        {
        int presicion = 1000;
        int numerator = other*presicion;
        int denomerator = 1*presicion;
        int gcd = __gcd(numerator, denomerator);
        nom = numerator/gcd;
        den = denomerator/gcd;
        }
                  
    };

// Destructor:
//    Fraction::~Fraction();

// Getters:
    int Fraction::get_nom()
    {
        return nom;
    };
    int Fraction::get_den()
    {
        return den;
    };

// Convert Fraction to double:
    Fraction::operator double() const
    {   
        double convert = double(nom)/double(den);
        return convert;
    };

// operator =:
    Fraction& Fraction::operator=(const Fraction& other)
    {
        if (this == &other)
        {
            return *this;
        }
        (*this).nom = other.nom;
        (*this).den = other.den;        
        return (*this);         
    };

    Fraction& Fraction::operator=(double other)
    {
        if (*this == other)
        {
            return *this;
        }
        //delete[] this;
        Fraction o = Fraction(other);

        return (*this = o);    
    };    

// operator (+):

    Fraction Fraction::operator+(const Fraction& other) const
    {  
        int denominator = den * other.den;
        int numerator = nom*(other.den) + (other.nom) * den;
        return Fraction(numerator, denominator);
    };

    Fraction Fraction::operator+(double other) const
    {
        // double sum = double(*this) + other;
        //return Fraction(sum);
        return (*this)+(Fraction(other));
    };
    Fraction Fraction::operator+(int other) const // Check if this method is neccesery 
    {                                                 // i did this method beacuse the
          // operator ++(int) creats error
        //Fraction o = Fraction(other);
        return (*this)+Fraction(other);
        
    };
    
    
//The - operator to subtract two fractions and return their 
//difference as another fraction in reduced form.
    
    Fraction Fraction::operator-(const Fraction& other) const
    {
        int denominator = den * other.den;
        int numerator = nom*(other.den) - (other.nom) * den;
        return Fraction(numerator, denominator);
    };
    Fraction Fraction::operator-(double other) const
    {
        return (*this)-(Fraction(other));
    };
    Fraction Fraction::operator-(int other) const
    {
        return (*this)-(Fraction(other));
    };

//The * operator to multiply 
//two fractions and return their product as another fraction in reduced form.
    
    Fraction Fraction::operator*(const Fraction& other) const
    {
        int denominator = den * other.den;
        int numerator = nom*(other.nom);
        return Fraction(numerator, denominator);
    };

    Fraction Fraction::operator*(double other) const
    {   
        return (*this)*Fraction(other);
    };

    Fraction Fraction::operator*(int other) const
    {
        return (*this)*(Fraction(other));
    };
   
//The / operator to divide 
//two fractions and return their quotient as another fraction in reduced form.
    
    Fraction Fraction::operator/(const Fraction& other) const
    {   
         if (other.nom == 0)
         {
             throw std::invalid_argument("can not divide in zero");
         }
        Fraction inverse = Fraction(other.den, other.nom);
        return (*this)*inverse; 
    };
    Fraction Fraction::operator/(double other) const
    {
        if (other == 0)
        {
            throw std::invalid_argument("can not divide in zero");
        }
        Fraction o = Fraction(other);
        return (*this)/o;
    };
    Fraction Fraction::operator/(int other) const
    {
        return (*this)/double(other);
    };                         


//The == operator to compare two fractions for equality and return true or false.

    bool Fraction::operator==(const Fraction& other) const
    {
        double this_frac = double(*this);
        double other_frac = double(other); 
        return (this_frac == other_frac);
    };
    bool Fraction::operator==(double other) const
    {   
        float TOLERANCE = 0.001;
        double frac = double(*this);
        bool ans = ((abs(frac - other) <= TOLERANCE) && (abs(frac - other) >= TOLERANCE));
        return ans;
    };

// != operator
    bool Fraction::operator!=(const Fraction& other) const
    {
        return double(*this) != double(other); 
    };
    bool Fraction::operator!=(double other) const
    {
        return !((*this) == other); 
    };   

    // > :
    bool Fraction::operator>(const Fraction& other) const
    {
        return (double(*this) > double(other));
    };
    bool Fraction::operator>(double other) const
    { 
        double f = double(*this); 
        return (f > other);
    };
    // friend bool operator>(const Fraction& c1, const Fraction& c2);
    // friend bool operator>(const Fraction& c1, double other);
    bool operator>(double other, const Fraction& c2)
    {
        return (other > double(c2));
    };

// < :
    bool Fraction::operator<(const Fraction& other) const
    {
        return (double(*this) < double(other));
    };
    bool Fraction::operator<(double other) const
    {
         return (double(*this) < other);
    };
    // friend bool operator<(const Fraction& c1, const Fraction& c2);
    // friend bool operator<(const Fraction& c1, double other);
    // bool operator<(double other, const Fraction& c2)
    // {
    //     return (other < double(c2));
    // };

// >= :
    bool Fraction::operator>=(const Fraction& other) const
    {
        return (double(*this) >= double(other));
    };
    bool Fraction::operator>=(double other) const
    {
        return (double(*this) >= other);
    };
    // friend bool operator>=(const Fraction& c1, const Fraction& c2);
    // friend bool operator>=(const Fraction& c1, double other);
    // bool operator>=(double other, const Fraction& c2)
    // {
    //     return (other >= double(c2));
    // };

// <= :
    bool Fraction::operator<=(const Fraction& other) const
    {
        return (double(*this) <= double(other));
    };
    bool Fraction::operator<=(double other) const
    {
         return (double(*this) <= other);
    };

//The ++ and -- operator
//that adds (or substracts) 1 to the fraction. implement both pre and post fix.

// prefix: ++n:
    Fraction& Fraction::operator++()
    {
        (*this) = (*this) + 1;
        return (*this);
    };

// postfix: n++:
    const Fraction Fraction::operator++(int)
    {   
        Fraction copy = (*this);
        (*this) = (*this) + 1;
        return copy;
    };

// // prefix: --n:
    Fraction& Fraction::operator--()
    {   
        (*this) = (*this) - 1;
        return (*this);
    };

// postfix: n--:
    const Fraction Fraction::operator--(int)
    {   cout << "enter operator--(int) " << endl;
        Fraction copy = (*this);
         (*this) = (*this) - 1;
        return copy;
    };

// to string
     Fraction::operator string() const       // conversion operator
    {             
		return std::to_string(nom)+"/"+std::to_string(den);
	}

    // string Fraction::nom_to_string() const
    // {
    //     return "" + nom;
    // };
    // string Fraction::den_to_string() const
    // {
    //     return "" + den;
    // };

    
    string Fraction::to_string() const
    {
       return string(*this);
    };

   



    
    
