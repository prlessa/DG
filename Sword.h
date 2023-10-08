#ifndef SWORD_H
#define SWORD_H

#include <string>
using std::string;

class Sword
{
public:
    
    Sword ( );    
    Sword( string );

    Sword( const Sword & );
    void setSwordName( string );


    string getSwordName( ) const;
    
    void print( ) const;
    void printNameAlt() const;
    void setStrength(double);
    int getStrength() const;

    int getDamage();

    
    void setDexterity(int);
    int getDexterity() const;
    
    string getPreName() const;
private:

    string swordName;
    string preName;
    const int SIZEINVENTORY;
    const int MAXSIZENAME;

    int damage;
    double strength;
    int dexterity;

};

#endif // GRADEBOOK_H