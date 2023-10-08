#ifndef CHAR_H
#define CHAR_H

#include <string>
using std::string;

class Char
{
public:
    
    Char ( );    
    Char( string );
    Char(string, int, int, int, int, int, int);

    Char( const Char & );
    void setCharName( string );

    //Check inventory 
    inline int getInventoryUsed() const { return inventorySize; };

    string getCharName( ) const;
    
    void status( const Char & ) ;
    void print( Char );
    void printNameAlt() const;
    
    int getDamage();
    
    //Character Stats
    void setStrength(double);
    int getStrength() const;
    
    void setDexterity(int);
    int getDexterity() const;
    
    void setConstitution(double);
    int getConstitution() const;

    void setIntelligence(double);
    int getIntelligence() const;

    void setWisdom(double);
    int getWisdom() const;
    
    void setCharisma(double);
    int getCharisma() const;

    int addItem( int );
    
    //END Character Stats
    
    
    
    string getPreName() const;
private:

    string charName;
    string preName;
    const int MAXSIZEINVENTORY;
    const int MAXSIZENAME;
    
    
    static int inventorySize;
    const static bool FULL;

    static bool mainHand;
    static bool offHand;
    
    int damage;
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;

};

#endif // GRADEBOOK_H