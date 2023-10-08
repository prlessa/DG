#ifndef SHIELD_H
#define SHIELD_H

#include <string>
using std::string;

class Shield
{
public:
    
    Shield ( );    
    Shield( string );

    Shield( const Shield & );
    void setShieldName( string );

    string getShieldName( ) const;
    
    void print( ) const;
    void printNameAlt() const;
    string getPreName() const;

    int getArmourClass() const;
    void setArmourClass( int );

    int getDexterity() const;
    void setDexterity(int);

    void subs(string);

    
private:
    string varName;
    string shieldName;
    string preName;
    const int SIZEINVENTORY;
    const int MAXSIZENAME;
    
    int armourClass;
    int dexterity;
};

#endif // GRADEBOOK_H