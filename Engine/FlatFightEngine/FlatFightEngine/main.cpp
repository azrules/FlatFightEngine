#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;
using namespace std;

void createGrid(sf::Sprite grid[160]) {

	for (int i = 0; i < 160; i++)
	{
		//tileset texture size is 16*16  16 * 6.25 =100px
		grid[i].setScale(6.25, 6.25);
		system("Color FA");
		cout << "[Success]:size set to 6.25 on Block -- ";
		cout << i << endl;

	}
	int rowPosition = 0;
	int row = 0;
	for (int i = 0; i < 160; i++)
	{
		// (float)100 * i sets the the row position 1-16, -1600*(row - 1) makes sure that the row dosent go beyond the edge of the window.
		// (float)(100 * row) sets which row the 
		if (rowPosition == 16) {
			rowPosition = 0;
			row++;
		}

		cout << "[Success]:position assigned on Block -- ";
		system("Color FA");
		cout << i << endl;
		cout << ((float)100 * i - (1600 * row));
		cout << ", ";
		cout << ((float)(100 * row)) << endl;
		grid[i].setPosition((float)100 * i - (1600 * row), (float)(100 * row));
		rowPosition++;
		grid[i].setScale(6.25, 6.25);
	}
}



int main() {
	//Variable Declarations
	sf::Sprite gridBlockLayer1[160];
	createGrid(gridBlockLayer1); //Makes Layer One of Grid
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "SFML works!");
	//Sets up grid by creating 160 tiles to fill the 1600 * 1000 grid
	sf::Texture blockTileset;
	sf::IntRect textureRect[48];
	system("Color F9");
	try {
		blockTileset.loadFromFile("Texture/Tiles.png");
	}
	catch (exception) {
		cout << "[Failure]:Could not lpuad " << endl;
	}

	//Texture Rect assignment 
	int column = 0;
	int row = 0;

	for (int i = 0; i < 48; i++)
	{
		if (column > 7) {
			column = 0;
			row++;
		}
		textureRect[i] = sf::IntRect(column * 16, row * 16, 16, 16);
		column++;
		cout << "[success]:texture Rect Assigned" << endl;
	}
	//Sets blocks to black by default
	for (int i = 0; i < 160; i++)
	{
		gridBlockLayer1[i].setTexture(blockTileset);
		gridBlockLayer1[i].setTextureRect(textureRect[0]);
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for (int i = 0; i < 160; i++)
		{
			window.draw(gridBlockLayer1[i]);
		}
		window.display();
	}









}

