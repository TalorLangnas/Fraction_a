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
        cout << "enter Fraction(double, double)" << endl;
        if(den_other == 0)
        {
            cout << "enter if(den_other == 0)" << endl;
            throw std::invalid_argument("illeagal value, denominator can not be qeual to zero");
        }
        else if (nom_other == 0)
        {   
            cout << "enter if (nom_other == 0) nom_other = "<< endl;
            nom_other = 0;
            den_other = 1;
        }
        else
        {
        cout << "enter to else " <<endl;

        nom_other = round(nom_other*1000);
        nom_other = nom_other/1000;
        den_other = round(den_other*1000);
        den_other = den_other/1000;
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
        Fraction(other.nom, other.den);     
    };

// recive one double
    Fraction::Fraction(double other)
    {
        cout << " enter to Fraction::Fraction(double other)" << endl;
        if (other == 0)
        {
            nom = 0;
            den = 1;
        }
        else
        {
        double int_val = other - round(other); 
        double frac = get_3_dig(int_val);
        int deno = 1000;
        frac = frac*1000;
        int gcd = __gcd(int(frac), deno);
        int nomo = frac/gcd;
        den = deno/gcd;
        nom = (den*int_val) + nomo; 
        }
                  
    };
    double Fraction::get_3_dig(const double d)
    {
        double ans = floor(d*1000);
        ans = ans/1000;
        return ans;

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
    // int Fraction::get_gcd()
    // {
    //     return gcd;
    // };
    

// Convert Fraction to double:
    Fraction::operator double() const
    {   
        double val = double(nom) / double(den); 
        val = round(val*1000);
        val = val/1000;
        return val;
    };

// operator =:
    Fraction& Fraction::operator=(const Fraction& other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] this;        
        return (*this = Fraction(other));         
    };

    Fraction& Fraction::operator=(const double other)
    {
        if (*this == other)
        {
            return *this;
        }
        delete[] this;  
        return (*this = Fraction(other));    
    };    

// operator (+):

    Fraction Fraction::operator+(const Fraction& other) const
    {
        cout << "enter to operator+(const Fraction& other) " << endl;
        // double sum = double(*this) + double(other);
        // return Fraction(sum);
        Fraction _other = Fraction(other);
        int d = _other.get_den() * den;
        // int x = nom * other.den;
        // int y = other.nom * den;
        int sum = (nom * _other.get_den()) + (_other.get_nom() * den); 
        int gcd = __gcd(sum,d);
        return Fraction((sum/gcd), (d/gcd));

    };

    Fraction Fraction::operator+(const double other) const
    {
        double sum = double(*this) + other;
        return Fraction(sum);
    };
    Fraction Fraction::operator+(const int other) const // Check if this method is neccesery 
    {                                                   // i did this method beacuse the
                                                        // operator ++(int) creats error
        double sum = double(*this) + other;
        return Fraction(sum);
        
    };
    
    
//The - operator to subtract two fractions and return their 
//difference as another fraction in reduced form.
    
    Fraction Fraction::operator-(const Fraction& other) const
    {
        double subtract = double(*this) - double(other);
        return Fraction(subtract);
    };
    Fraction Fraction::operator-(const double other) const
    {
         double subtract = double(*this) - other;
         return Fraction(subtract);
    };
    Fraction Fraction::operator-(const int other) const
    {
        double subtract = double(*this) - other;
        return Fraction(subtract);
    };
    // Fraction operator-(double c1, const Fraction& c2)
    // {
    //     double subtract = c1 - double(c2);
    //     return Fraction(subtract);
    // };
    // Fraction operator-(int c1, const Fraction& c2)
    // {   
    //     double subtract = c1 - double(c2);
    //     return Fraction(subtract);
    //     //return double(c1) - c2; // gives error, why?
    // };

//The * operator to multiply 
//two fractions and return their product as another fraction in reduced form.
    
    Fraction Fraction::operator*(const Fraction& other) const
    {
        double mul = double(*this) * double(other);
        return Fraction(mul);
    };

    Fraction Fraction::operator*(const double other) const
    {
        double mul = double(*this) * other;
        return Fraction(mul);
    };
    Fraction Fraction::operator*(const int other) const
    {
        return (*this)*double(other);
    };

    // Fraction operator*(double c1, const Fraction& c2)
    // {
    //     return c2*c1;
    // };
    // Fraction operator*(int c1, const Fraction& c2)
    // {
    //     return c2*c1;
    // };  
   
//The / operator to divide 
//two fractions and return their quotient as another fraction in reduced form.
    
    Fraction Fraction::operator/(const Fraction& other) const
    {   
        // if (other == 0)
        // {
        //     throw std::invalid_argument("can not divide in zero");
        // }
        
        double quotient = double(*this)/double(other);
        return Fraction(quotient);
    };
    Fraction Fraction::operator/(const double other) const
    {
        if (other == 0)
        {
            throw std::invalid_argument("can not divide in zero");
        }
        double quotient = double(*this)/double(other);
        return Fraction(quotient);
    };
    Fraction Fraction::operator/(const int other) const
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
    bool Fraction::operator==(const double other) const
    {   
        double frac = double(*this);
        bool ans = ((abs(frac - other) <= TOLERANCE) && (abs(frac - other) >= TOLERANCE));
        return ans;
    };

//     bool operator==(const Fraction& c1, const Fraction& c2)
//     {
//         return (c1.operator==(c2));
//     };


// // friend bool operator==(const Fraction& c1, const Fraction& c2);
// // friend bool operator==(const Fraction& c1, double other);
//     bool operator==(double other, const Fraction& c2)
//     {
//         return (c2==other);
//     };

// != operator
    bool Fraction::operator!=(const Fraction& other) const
    {
        return double(*this) != double(other); 
    };
    bool Fraction::operator!=(double other) const
    {
        return double(*this) != other; 
    };
    // bool operator!=(double flt, const Fraction& frac)
    // {
    //     return flt != double(frac);
    // };     

    // > :
    bool Fraction::operator>(const Fraction& other) const
    {
        return (double(*this) > double(other));
    };
    bool Fraction::operator>(const double other) const
    {
        return (double(*this) > other);
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
    // friend bool operator<=(const Fraction& c1, const Fraction& c2);
    // friend bool operator<=(const Fraction& c1, double other);
    // bool operator<=(double other, const Fraction& c2)
    // {
    //     return (other <= double(c2));
    // };

//The ++ and -- operator
//that adds (or substracts) 1 to the fraction. implement both pre and post fix.

// prefix: ++n:
    Fraction& Fraction::operator++()
    {
        double me = double(*this);
        me++;
        *this = Fraction(me);
        return *this;
    };

// postfix: n++:
    const Fraction Fraction::operator++(int harta)
    {
        Fraction other_frac = Fraction(*this);
        other_frac = other_frac + 1;
        return other_frac;
    };

// // prefix: --n:
    Fraction& Fraction::operator--()
    {
        double me = double(*this);
        me--;
        *this = Fraction(me);
        return *this;
    };

// postfix: n--:
    const Fraction Fraction::operator--(int harta)
    {
        Fraction other_frac = Fraction(*this);
        other_frac = other_frac - 1;
        return other_frac;
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

   



    
    
