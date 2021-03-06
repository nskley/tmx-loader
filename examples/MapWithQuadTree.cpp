
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <tmx/MapLoader.hpp>

#include <sstream>

int main()
{
	sf::RenderWindow renderWindow(sf::VideoMode(800u, 600u), "TMX Loader");

	//create map loader and load map
	tmx::MapLoader ml("res/maps/");
	ml.load("desert.tmx");

	//-----------------------------------//

	while(renderWindow.isOpen())
	{
		//poll input
		sf::Event event;
		while(renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				renderWindow.close();
        }

		//build quad tree by querying visible region
		ml.updateQuadTree(sf::FloatRect(0.f, 0.f, 800.f, 600.f));
		//get a vector of MapObjects contained in the quads intersected by query area
		sf::Vector2f mousePos = renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow));
		//NOTE quad tree MUST be updated before attempting to query it
		std::vector<tmx::MapObject*> objects = ml.queryQuadTree(sf::FloatRect(mousePos.x - 10.f, mousePos.y - 10.f, 20.f, 20.f));

		//do stuff with returned objects
		std::stringstream stream;
		stream << "Query object count: " << objects.size();
		renderWindow.setTitle(stream.str());

		//draw
		renderWindow.clear();
		renderWindow.draw(ml);
		ml.drawLayer(renderWindow, tmx::MapLayer::Debug); //draw with debug information shown
		renderWindow.display();
	}

	return 0;
}