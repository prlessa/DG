#include "Shield.h"

#include <iostream>
using std::cout;

Shield::Shield( string name ): armourClass(2), dexterity(4), SIZEINVENTORY(1), MAXSIZENAME(3)
{
   
   cout << "Inicializando Shield no constructor.\n";
   setShieldName( name );
   
}

//Construtor de copia
Shield::Shield( const Shield& other )
:MAXSIZENAME( other.MAXSIZENAME ), SIZEINVENTORY( other.SIZEINVENTORY)
{   
    this->shieldName = other.shieldName;

}


//GETS
int Shield::getArmourClass() const
{
    return armourClass;
}

int Shield::getDexterity() const
{
    return dexterity;
}


string Shield::getShieldName( ) const
{
    return shieldName;
}



string Shield::getPreName() const
{
    return preName;
}
//SETS

void Shield::setArmourClass( int armourClass )
{
    if( armourClass >= 0 )
    {
        this->armourClass = armourClass;
        return;
    }

    this->armourClass = 0;

}

void Shield::setDexterity( int dexterity )
{
    if( dexterity >= 0 )
    {
        this->dexterity = dexterity;
        return;
    }

    this->dexterity = 0;

}

//limita o numero de carateres do nome de acordo com o definido no .h
void Shield::subs(string x){
       if ( x.length( ) > MAXSIZENAME )
        {
            varName = x.substr( 0, MAXSIZENAME );
            cout << "Nome alterado. Excedeu o valor maximo. \n";
            return;
        } 
}


void Shield::setShieldName( string name )
{    

    shieldName = name;
    preName = shieldName;
    subs(shieldName);
    shieldName = varName;
}



void Shield::printNameAlt() const
{
    cout << "Nome anterior: "<< getPreName() <<"\nNovo nome: "  << getShieldName() << '\n';
}

void Shield::print( ) const
{
     cout << getShieldName() << "\n AC: " << getArmourClass() << " DEX: " << getDexterity() << '\n';
}
