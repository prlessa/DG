#include "Sword.h"

#include <iostream>
using std::cout;

Sword::Sword( string name ): strength(0), dexterity(0), SIZEINVENTORY(1), MAXSIZENAME(25)
{
   setSwordName( name );
   cout << "Inicializando Sword no constructor.\n";
   //strength = 48;
  // dexterity = 14;
}


int Sword::getDamage()
{
    int random_number = rand() % 8 + 16;
    damage = random_number;
    return damage;
}
/*Sword::Sword( string name )
{
    setSwordName( name );
} */

//Construtor de copia
Sword::Sword( const Sword& other )
:MAXSIZENAME( other.MAXSIZENAME ), SIZEINVENTORY( other.SIZEINVENTORY)
{   
    this->swordName = other.swordName;
    this->strength  = other.strength;
    this->dexterity = other.dexterity;
}


//GETS
string Sword::getSwordName( ) const
{
    return swordName;
}

int Sword::getStrength() const
{
    return strength;
}

int Sword::getDexterity() const
{
    return dexterity;
}

string Sword::getPreName() const
{
    return preName;
}
//SETS
void Sword::setStrength( double strength )
{
    if( strength >= 0 )
    {
        this->strength = strength;
        return;
    }

    this->strength = 0;

}

void Sword::setDexterity( int dexterity )
{
    if( dexterity >= 0 )
    {
        this->dexterity = dexterity;
        return;
    }

    this->dexterity = 0;

}

//limita o numero de carateres do nome de acordo com o definido no .h
void Sword::setSwordName( string name )
{
    if ( name.length( ) > MAXSIZENAME )
        {
            swordName = name.substr( 0, MAXSIZENAME );
            cout << "Nome alterado. Excedeu o valor maximo. \n";
            return;
        }
    preName = swordName;
    swordName = name;
}



void Sword::printNameAlt() const
{
    cout << "Nome anterior: "<< getPreName() <<"\nNovo nome: "  << getSwordName() << '\n';
}

void Sword::print( ) const
{
     cout << getSwordName() << "\n STR: " << getStrength() << " DEX: " << getDexterity() << '\n';
}


