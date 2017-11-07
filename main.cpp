#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include "clases.h"

#define PI 3.14159265

using namespace std;
using namespace sf;

int main(){

  //variables
  const float suelo = 500.0;
  const float gravity =9.8;

   class proyectil{
      public:
          float angle,range;
          float max_height;
          float v_0;
          float time;
          Point V;
          Point C;
          float p;
          Time t1;
          CircleShape proy;
          proyectil(float a, float b,float angle,float v_0){
              proy.setRadius(10);
              C.x=a;
              C.y=b;
              proy.setPosition(C.x,C.y);
              range = (pow(v_0,2) * sin((2 * angle) * PI/180)) / 9.8;
              max_height = (pow(v_0,2) * pow(sin(angle * PI/180),2)) / (2*9.8);
              time=(2*pow(v_0,2) * sin((2 * angle) )) / 9.8;
              t1 = milliseconds(time/(range/0.01));
              V.x = range / 2;
              V.y = 500 - max_height;
              p = pow(V.x, 2) / (4 *(500 - V.y));
              cout << "V( " << V.x << " , " << V.y << " )" << endl;
          }
          void movimiento(){
          C.x+=0.1;
          C.y=(pow(C.x -V.x, 2) + (4 * V.y * p)) / (4*p);
          proy.setPosition(C.x,C.y);
          }

  };


 

  //Point coord(x , y);
  RectangleShape line(Vector2f(800, 5)); //linea base
  line.setPosition(0,suelo);
  CircleShape player1(10);
  player1.setPosition(0.0, suelo-20);



  RenderWindow window(VideoMode(800, 600), "My render");
    float angle, v_0;
  while(window.isOpen()){
    Event event;
    while (window.pollEvent(event))
      {
	// "close requested" event: we close the window
	if (event.type == Event::Closed)
	  window.close();
	/*if(Keyboard::isKeyPressed(Keyboard::Escape))
	  window.close()coord.y = (pow(coord.x - h, 2) + (4 * k * p)) / (4*p);
      }*/}
    window.clear(Color(0,0,0));
    cout << "Inserta el angulo: ";
              cin >> angle;
              cout << "Inserta la velocidad inicial: ";
              cin >> v_0;
    proyectil bomba(0.0,suelo-20,angle,v_0);

    while (bomba.C.x<bomba.range-20){
    // clear the window with black color
    window.clear(Color(0,0,0));
    // draw everything here...
    window.draw(player1);
    window.draw(bomba);
    window.draw(line);
    // end the current frame
    window.display();
    bomba.movimiento();
    sleep(bomba.t1);

    }

    cout<<"end of movement \n";
    break;
  }
  cout<<"end of program";

  return 0;
}
