#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//----------INTERFAZ------------------
class FlyBehavior{
      public: 
              virtual void fly(string pato) = 0;
};

//CLASES CONCRETAS DE LA CLASE FlyBehavior

//CLASE CONCRETA 1 FLYWITHWINGS
class FlyWithWings: public FlyBehavior{
      public:
             void fly(string pato){
                  cout<<"Este pato "<<pato<<" si vuela"<<"\n";
             };
};
//--------------------------------

//CLASE CONCRETA 2 FLYNOWAY
class FlyNoWay: public FlyBehavior{
      public:
             void fly(string pato){
                  cout<<"Este pato "<<pato<<" no vuela"<<"\n";
             };
};
//-------------------------

//CLASE CONCRETA 3 FLYWITHBALLON
class FlyWithBallon: public FlyBehavior{
      public:
             void fly(string pato){
                  cout<<"Este pato "<<pato<<" vuela con globos"<<"\n";
             };
};
//------------------------------

//------------FIN DE CLASES CONCRETAS----------------




//-------------INTERFAZ-----------------------------
class QuackBehavior{
      public:
             virtual void cuack(string pato)=0;
};

//CLASES CONCRETAS DE LA CLASE QUACKBEHAVIOR

//CLASE CONCRETA 1 QUACK
class Quack: public QuackBehavior{
      public:
             void cuack(string pato) {
                  cout<<"Este pato "<<pato<<" si grazna"<<"\n";     
             };
};
//-----------------------

//CLASE CONCRETA 2 SQUEAK 
class Squeak: public QuackBehavior{
      public:
             void cuack(string pato){
                  cout<<"Este pato "<<pato<<" solo chilla"<<"\n";
             };
};
//-----------------------

//CLASE CONCRETA 3 MUTEQUACK
class MuteQuack: public QuackBehavior{
      public:
             void cuack(string pato){
                  cout<<"Este pato "<<pato<< " no hace ruido"<<"\n";
             };
};
//--------------------------

//FIN DE CLASES CONCRETAS DE QUACK BEHAVIOR




//---------------CLASE ABSTRACTA--------------

class Duck {
      private: 
               FlyBehavior* fb;
               QuackBehavior* qb;
      public: 
              void display(string pato);
              
              void setQuackBehavior(QuackBehavior* q){
                   qb = q;     
              };
              
              void setFlyBehavior(FlyBehavior* f){
                   fb = f;
              };
              
              void perfomQuack(string pato){
                   if(qb){
                          qb->cuack(pato);
                   }     
              };
              
              void performfly(string pato){
                   if(fb){
                          fb->fly(pato);       
                   }
              };
              
              void swim();
              
              
              void showDuck();
              
};


//CLASES CONCRETAS DE CLASE DUCK

//CLASE CONCRETA 1 MALLARDDUCK

class MallarDuck:public Duck{
      public:
             void display(string pato){
                  cout<<"Este es un pato"<<pato<<" llamado pato real"<<"\n";     
             };
};

//----------------------------

//CLASE CONCRETA 2 RUBBERTDUCK

class RubbertDuck:public Duck{
      public:
             void display(string pato){
                  cout<<"Este es un pato "<<pato<<" o sea de hule"<<"\n";     
             };
};

//----------------------------

//CLASE CONCRETA 3 DECOYDUCK

class DecoyDuck:public Duck{
      public:
             void display(string pato){
                  cout<<"Este es y pato "<<pato<<" de decoracion"<<"\n";    
             };
};

//--------------------------

//CLASE CONCRETA 4 READHEADDUCK
class ReadHeadDuck{
  public:
         void display(string pato){
              cout<<"Este es un pato "<<pato<<" de cabeza roja"<<"\n";
         };    
};
//-----------------------------

//FIN DE CLASES CONCRETAS DE CLASE DUCK


//---------FIN DECLASE ABSTRACTA--------------


int main(int argc, char *argv[])
{
    //VARIABLES DE LAS CLASES CONCRETAS DE QUACKBEHAVIOR
    Quack Q;
    Squeak patoS;
    MuteQuack patoMQ;
    MuteQuack patoMQ2;
    //-------------------------------------------------
    
    //VARIABLES DE LAS CLASES CONCRETAS DE FLYBEHAVIOR
    FlyWithWings Q1;
    FlyNoWay patoFN;
    FlyWithBallon patoFB;
    FlyWithBallon patoFB2;
    //------------------------------------------------
    
    //VARIABLES DE LAS CLASES CONCRETAS DE DUCK
    MallarDuck MD;
    RubbertDuck RB;
    DecoyDuck DD;
    ReadHeadDuck RH;
    //------------------------------------------
    
    Duck pato;
    
    //----PATO CABEZA ROJA----
    cout<<"//----------------------------//"<<"\n";
    pato.setQuackBehavior(&Q);
    pato.perfomQuack("Red");

    pato.setFlyBehavior(&Q1);
    pato.performfly("Red");
    
    cout<<"//----------------------------//"<<"\n";
    cout<<"\n";
    //-------------------------
        
    //----PATO MALLARD----
    cout<<"//----------------------------//"<<"\n";
    pato.setQuackBehavior(&patoS);
    pato.perfomQuack("Mallard");
    
    pato.setFlyBehavior(&patoFN);
    pato.performfly("Mallard");
    cout<<"//----------------------------//"<<"\n";
    cout<<"\n";
    //--------------------
    
    //----PATO DE HULE----
    cout<<"//----------------------------//"<<"\n";
    pato.setQuackBehavior(&patoMQ);
    pato.perfomQuack("Rubber");
    
    pato.setFlyBehavior(&patoFB);
    pato.performfly("Rubber");
    cout<<"//----------------------------//"<<"\n";
    cout<<"\n";
    //--------------------
    
    //----PATO DE MADERA----
    cout<<"//----------------------------//"<<"\n";
    pato.setQuackBehavior(&patoMQ2);
    pato.perfomQuack("Decoy");
    
    pato.setFlyBehavior(&patoFB2);
    pato.performfly("Decoy");
    cout<<"//----------------------------//"<<"\n";
    cout<<"\n";
    //----------------------
    cout<<"\n";
    
    system("pause");
}
