#include "Char.h"

#include <iostream>
#include <math.h>
using std::cout;

bool Char::mainHand = false;
bool Char::offHand = false;
const bool Char:: FULL = false;
int nextEntrieInSpellsBar = 0;


Char::Char( string name ): 
strength(0), 
dexterity(0), 
constitution(0), 
intelligence(0), 
wisdom(0), 
charisma(0), 
MAXSIZEINVENTORY(40), MAXSIZENAME(12)
{
   spellsBarSize = 0;
   spellsBarPtr = 0;
   setCharName( name );
   cout << "Inicializando Char no constructor.\n";

}

Char::Char(string name, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma): MAXSIZEINVENTORY(40), MAXSIZENAME(12),
spellsBarSize(10)
{
    spellsBarSize = 0;
    spellsBarPtr = 0;
    setCharName(name);
    this->strength  = strength;
    this->dexterity = dexterity;
    this->constitution = constitution;
    this->intelligence = intelligence;
    this->wisdom = wisdom;
    this->charisma = charisma;
    
}


//Construtor de copia
Char::Char( const Char& other )
:MAXSIZENAME( other.MAXSIZENAME ), MAXSIZEINVENTORY( other.MAXSIZEINVENTORY)
{   
    this->charName = other.charName;
    this->strength  = other.strength;
    this->dexterity = other.dexterity;
    this->constitution = other.constitution;
    this->intelligence = other.intelligence;
    this->wisdom = other.wisdom;
    this->charisma = other.charisma;

    //copia ptr no construtor
    this->spellsBarSize = other.spellsBarSize;
    this->nextEntrieInSpellsBar = other.nextEntrieInSpellsBar;
    this->spellsBarPtr = new int[this->spellsBarSize];
    for(int i = 0; i < nextEntrieInSpellsBar; i++)
        this->spellsBarPtr[i] = spellsBarPtr[i];
}

Char::~Char(){
    delete [] spellsBarPtr;
}

//no futuro sera adicionado um Tipo Item 
int Char::addItem(int item)
{
    if(inventoryUsed < INVENTORYSIZE )
    {
        for(int i = 1; i < INVENTORYSIZE; i++)
        if(inventory[i] == NULL)
        {
        this-> inventory[i] = item;
        
        }   
        this->inventoryUsed++;
    }
//Checa se o inventario esta cheio e retorna true caso esteja
    if(inventoryUsed == INVENTORYSIZE)
    {
        cout << "O inventario esta cheio" << '\n';
        return FULL == true;
    }
}
//GETS
string Char::getCharName( ) const
{
    return charName;
}

int Char::getStrength() const
{
    return strength;
}

int Char::getDexterity() const
{
    return dexterity;
}

int Char::getConstitution() const
{
    return constitution;
}

int Char::getIntelligence() const
{
    return intelligence;
}

int Char::getWisdom() const
{
    return wisdom;
}

int Char::getCharisma() const
{
    return dexterity;
}
string Char::getPreName() const
{
    return preName;
}

//SETS
void Char::setStrength( double strength )
{
    if( strength >= 0 )
    {
        this->strength = strength;
        return;
    }

    this->strength = 0;

}

void Char::setDexterity( int dexterity )
{
    if( dexterity >= 0 )
    {
        this->dexterity = dexterity;
        return;
    }

    this->dexterity = 0;

}

void Char::setConstitution( double constitution )
{
    if( constitution >= 0 )
    {
        this->constitution = constitution;
        return;
    }

    this->strength = 0;

}

void Char::setIntelligence( double intelligence )
{
    if( intelligence >= 0 )
    {
        this->intelligence = intelligence;
        return;
    }

    this->intelligence = 0;

}

void Char::setWisdom( double wisdom )
{
    if( wisdom >= 0 )
    {
        this->wisdom = wisdom;
        return;
    }

    this->wisdom = 0;

}

void Char::setCharisma( double charisma )
{
    if( charisma >= 0 )
    {
        this->charisma = charisma;
        return;
    }

    this->charisma = 0;

}

//limita o numero de carateres do nome de acordo com o definido no .h
void Char::setCharName( string name )
{
    if ( name.length( ) > MAXSIZENAME )
        {
            charName = name.substr( 0, MAXSIZENAME );
            cout << "Nome alterado. Excedeu o valor maximo. \n";
            return;
        }
    preName = charName;
    charName = name;
}



void Char::printNameAlt() const
{
    cout << "Nome anterior: "<< getPreName() <<"\nNovo nome: "  << getCharName() << '\n';
}

void Char::printInventory() const
{
    for( int i = 0; i < INVENTORYSIZE; i++ )
        cout << this->inventory[ i ] << '\n';


}
void Char::status()
{
    cout << "Nome: " << getCharName() << '\n';
    cout << " STR: " << getStrength() << " DEX: " << getDexterity() << " CON:  " 
          << getConstitution() << " INT: " << getIntelligence() << " WIS " << getWisdom() 
          << " CHA: " << getCharisma() << '\n';
    cout << "Inventario: " << "(" << inventoryUsed << "/" << MAXSIZEINVENTORY << ")" << '\n';
}

//Implementacoes do ptr
void Char::cadastrarRegInSpellsBar(int barSize)
{
    if(nextEntrieInSpellsBar < spellsBarSize){
        spellsBarPtr[nextEntrieInSpellsBar++] = barSize;
        return;
    }
    if(spellsBarSize == 0){
        spellsBarSize = 1;
        spellsBarPtr = new int[spellsBarSize];
        spellsBarPtr[nextEntrieInSpellsBar++] = barSize;
        return;
    }
    alocarSpellsBar(barSize);
}

void Char::alocarSpellsBar(int barSize)
{
    int *spellsBarTemp = new int[spellsBarSize];
    for(int i = 0; i < nextEntrieInSpellsBar; i++)
        spellsBarTemp[i] = spellsBarPtr[i];

    delete [] spellsBarPtr;

    spellsBarSize += int(ceil(spellsBarSize*0.5)); //AUMENTA A MEMORIA EM 50%
    int *spellsBarPtr = new int[spellsBarSize];
    for(int i = 0; i < nextEntrieInSpellsBar; i++)
        spellsBarPtr[i] = spellsBarTemp[ i ];
    spellsBarPtr[nextEntrieInSpellsBar++] = barSize;

    delete[] spellsBarTemp;
    
}

void Char:: printSpellsBar() const
{
    for(int i = 0; i < nextEntrieInSpellsBar; i++ )
    cout << "ta lendo?" << spellsBarPtr[i] << '\n';
    }
