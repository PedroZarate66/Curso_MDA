#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//----------------INTERFAZ----------------------------------
class RouteStrategy{
      public:
             virtual void buildRoute(string A, string B)=0;    
};


//-------CLASES CONCRETAS DE LA CLASE ROUTESTRATEGY--------


//----------PRIMERA CLASE CONCRETA ROADSTRATEGY------
class RoadStrategy: public RouteStrategy{
      public:
             void buildRoute(string A, string B){
                  cout<<"Puede tomar la AV. 14 sur para ir de "<<A<<" hasta "<<B<<"\n";
             }      
             
};
//-----------------------------------------------------

//----------SEGUNDA CLASE CONCRETA WALKING STRATEGY----
class WalkingStrategy:public RouteStrategy{
      public:
             void buildRoute(string A, string B){
                  cout<<"Puede tomar la AV. 14 sur para ir de "<<A<<" hasta "<<B<<"\n";
             }            
};
//----------------------------------------------------- 

//----------FIN DE CLASES CONCRETAS--------------------------

//----------CLASE ABSTRACTA CONTEXT---------------------
class Context{
      private:
              RouteStrategy* RS;
     
      public:
             void setRouteStrategy(RouteStrategy* S){
               RS = S;                             
             };      
             
             void calculateRoute(string A, string B){
                  if(RS){
                         RS->buildRoute(A,B);   
                  }
             };
};
//------------------------------------------------------


int main(int argc, char *argv[])
{
    
    //VARIABLES DE LAS CLASES CONCRETAS DE ROUTESTRATEGY
    RoadStrategy rs;
    WalkingStrategy ws;
    //--------------------------------------------------
    
    //VARIABLE DE LA CLASE CONTEXT PARA COMUNICAR CON INTERFAZ Y DEMAS CLASES
    Context ruta;
    //-----------------------------------------------------------------------
    
    //CALCULAR RUTA MEDIANTE CARRETERA
    cout<<"\n";
    cout<<"/------------Por carretera------------"<<"\n";
    ruta.setRouteStrategy(&rs);
    ruta.calculateRoute("Heroes","CU");
    cout<<"/-------------------------------------"<<"\n";
    cout<<"\n";
    //--------------------------------
    
    //CALCULAR RUTA MEDIANTE CAMINATA
    cout<<"\n";
    cout<<"/------------Por caminata--------------"<<"\n";
    ruta.setRouteStrategy(&ws);
    ruta.calculateRoute("CU","Plaza_cristal");
    cout<<"/--------------------------------------"<<"\n";
    cout<<"\n";
    //-------------------------------
    
    system("PAUSE");
}
