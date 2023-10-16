#include <iostream>
using std::cout;

#include "Sword.h"
#include "Sword.cpp"
#include  "Shield.h"
#include "Shield.cpp"
#include "Char.cpp"
#include "Char.h"


int main()
{
   Sword ritualSword( "Tumulo do lobo" );
   Sword ritualSword2( "Corta franja" );
   //Sword ritualSword3("");
   ritualSword2.setDexterity(48);
   ritualSword2.setStrength(65);
   ritualSword.print( );
   ritualSword2.print( );

   cout << "As espadas sao: " << ritualSword.getSwordName( ) << " e " << ritualSword2.getSwordName( ) << '\n';

   ritualSword2.setSwordName("Papagaio Azul Laminado");

   ritualSword2.printNameAlt();
   
   Sword ritualSword3(ritualSword);

   ritualSword3.print();

   Shield BaronShield("Porta dos Ceus");
   BaronShield.print();
   BaronShield.getPreName();

   Char newChar("Paul", 10,9,8,12,15,17);
   Char newChar2("Neo", 10,9,8,7,6,5);

   Char newChar3("Pipo");

   newChar.status();
   
   newChar.addItem(15);
   newChar.status();
   newChar.getInventoryUsed();
   
   Char *newCharPtr;
   newCharPtr = new Char("Palindromo", 15, 10, 12, 8, 10, 15);
   newCharPtr->status();
}