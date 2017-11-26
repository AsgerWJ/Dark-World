// Dark World.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Entities.h"
#include "Human.h"

int main()
{

  int gameWidth = 1024;
  int gameHeight = 860;
  // Create the window of the application
  sf::RenderWindow mainWindow(sf::VideoMode(gameWidth, gameHeight, 32), "Dark World", sf::Style::Titlebar | sf::Style::Close);
  mainWindow.setVerticalSyncEnabled(true);

  sf::View mainView = mainWindow.getDefaultView();

  //Attach view to window
  mainWindow.setView(mainView);

  //Set vertical sync
  mainWindow.setVerticalSyncEnabled(true);

  dw::BaseEntity test1(sf::Vector2f(10,10));
  dw::Human human(sf::Vector2f(10,10));

  //Time stuff
  sf::Clock frameClock;
	sf::Time frameTime = frameClock.restart();


  //Main game loop
  while(mainWindow.isOpen() )
  {
    //Get delta time
    sf::Time deltaTime = frameClock.restart();

    sf::Event event;
    while(mainWindow.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      {
        //exit program
        mainWindow.close();
        break;
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

    if(sf::Mouse::isButtonPressed(sf::Mouse::Right) )
    {
      sf::Vector2i pos = sf::Mouse::getPosition(mainWindow);
      human.SetMoveTarget(sf::Vector2f(pos.x, pos.y) );
    }
    mainWindow.setView(mainView);


    //No more events, continue with main loop
    mainWindow.clear(sf::Color::White);
    //window cleared, update stuff
    human.Update(deltaTime);

    mainWindow.draw(human);

    //End of this frame
    mainWindow.display();


  }

  return 0;
}

