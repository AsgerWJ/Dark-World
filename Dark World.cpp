// Dark World.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Entities.h"
#include "Human.h"

#include "SelectionManager.h"

int main()
{
  //Prepare "globals" for managers

  std::vector<dw::BaseEntity*> entityListGlobal; //Vector of all entities in game
  std::vector<dw::BaseEntity*> selecetedEntityListGlobel; //Vector with all selected entities

  //Create managers
  dw::SelectionManager selectionManager(&entityListGlobal,&selecetedEntityListGlobel);


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
  entityListGlobal.push_back(&test1);
  entityListGlobal.push_back(&human);

  //Time stuff
  sf::Clock frameClock;
	sf::Time frameTime = frameClock.restart();

  bool leftMousePressed = false;
  sf::Vector2i firstLeftClick, lastLeftClick; //Used for selection detection

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


    bool leftMousePressedLast = leftMousePressed;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) )
    {
      if(!leftMousePressed)
      {//First time press
        firstLeftClick = sf::Mouse::getPosition(mainWindow);
      }
     
      //human.SetMoveTarget(sf::Vector2f(pos.x, pos.y) );
      leftMousePressed = true;
    }
    else
      leftMousePressed = false;

    if(leftMousePressedLast && !leftMousePressed)
    {//left mouse button released
      lastLeftClick = sf::Mouse::getPosition(mainWindow);
      //Check for selections
      selectionManager.SelectEntitiesInArea(firstLeftClick,lastLeftClick,false);

    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
      sf::Vector2i target= sf::Mouse::getPosition();
      auto enIt = selecetedEntityListGlobel.begin();
      for(enIt ; enIt != selecetedEntityListGlobel.end(); enIt++)
      {
        (*enIt)->SetMoveTarget(target);
      }
    }

    mainWindow.setView(mainView);


    //No more events, continue with main loop
    mainWindow.clear(sf::Color::White);
    //window cleared, update stuff
    human.Update(deltaTime);

    //draw stuff
    mainWindow.draw(human);

    //End of this frame
    mainWindow.display();


  }

  return 0;
}

