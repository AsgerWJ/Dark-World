// Dark World.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Man.h"

int _tmain(int argc, _TCHAR* argv[])
{
  sf::RenderWindow mainWindow(sf::VideoMode(1200,800), "Dark World");
  sf::View mainView = mainWindow.getDefaultView();

  //Attach view to window
  mainWindow.setView(mainView);

  //Set vertical sync
  mainWindow.setVerticalSyncEnabled(true);


  //Test things
  sf::RectangleShape rect1(sf::Vector2f(100,100));
  rect1.setFillColor(sf::Color::Red);

  Man man1(10,10);

  //Main game loop
  while(mainWindow.isOpen() )
  {
    sf::Event event;
    while(mainWindow.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      {
        //exit program
        mainWindow.close();
      }
      else if(event.type == sf::Event::KeyPressed)
      {

      }
    }
            //Do key press action!
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
        {
          mainView.move(0,-10);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
        {
          mainView.move(0,10);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
        {
          mainView.move(-10,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
        {
          mainView.move(10,0);
        }
        mainWindow.setView(mainView);


    //No more events, continue with main loop
    mainWindow.clear(sf::Color::Black);
    //window cleared, redraw stuff
    mainWindow.draw(rect1);
    //mainWindow.draw(man1);

    //End of this frame
    mainWindow.display();


  }

  return 0;
}

