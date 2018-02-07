// Dark World.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BaseEntity.h"
#include "Human.h"
#include "Player.h"

#include "TextureIds.h"
#include "TextureManager.h"


int main()
{
  //Prepare "globals" for managers

  std::vector<dw::BaseEntity*> entityListGlobal; //Vector of all entities in game
  std::vector<dw::BaseEntity*> selecetedEntityListGlobel; //Vector with all selected entities

  //Create managers
  dw::TextureManager textureManager;
  textureManager.LoadTextures();


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

  dw::Player player(sf::Vector2f(30,30) );
  player.loadTexture(textureManager.GetTexturePtr(TEXTURE::SMILEY));
  dw::Human human(sf::Vector2f(10,10));
  entityListGlobal.push_back(&human);
  entityListGlobal.push_back(&player);

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
    sf::Vector2f movement;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
    {
      movement.y -= 1;
      //mainView.move(0,-10);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
    {
      movement.y += 1;
      //mainView.move(0,10);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
    {
      movement.x -= 1;
      //mainView.move(-10,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
    {
      movement.x += 1;
      //mainView.move(10,0);
    }
    player.SetMovingDirection(movement);
    mainWindow.setView(mainView);


    //No more events, continue with main loop
    mainWindow.clear(sf::Color::White);
    //window cleared, update stuff
    human.Update(deltaTime);
    player.Update(deltaTime);

    //draw stuff
    mainWindow.draw(human);
    mainWindow.draw(player);

    //End of this frame
    mainWindow.display();


  }

  return 0;
}

