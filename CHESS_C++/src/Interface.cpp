#include "Interface.h"

Interface::Interface()
{
	setSprites();
	setFont();
	setNames();
	setAuthor();
	setResetButton();
	setTexts();
	setMoveSqueres();
	setTimes();
}


void Interface::setSprites()
{
	if (!this->white.loadFromFile("textures/whiteIcon.png"))
	{
		std::cout << "Load texture from file textures failed" << std::endl;
	}
	else
	{
		this->whiteIcon.setTexture(white);
		this->whiteIcon.setPosition(1000, 560);
	}

	if (!this->black.loadFromFile("textures/blackIcon.png"))
	{
		std::cout << "Load texture from file textures failed" << std::endl;
	}
	else
	{
		this->blackIcon.setTexture(black);
		this->blackIcon.setPosition(1000, 160);
	}

	if (!this->logo_tex.loadFromFile("textures/logo.png"))
	{
		std::cout << "Load texture from file textures failed" << std::endl;
	}
	else
	{
		logo.setTexture(logo_tex);
		logo.setPosition(1210, 700);
		logo.setScale(0.2f, 0.2f);
	}
}

void Interface::setTexts()
{
	setTextParameters(login, 40, sf::Color(0, 0, 0), sf::Vector2f(260, 20));
	login.setString("Welcome in Chess Game! Login both player to start...");
	setTextParameters(loginPlayer, 35, sf::Color(0, 0, 0), sf::Vector2f(300, 200));
	loginPlayer.setString("Player white: Enter your username, press Enter to confirm");
	setTextParameters(username, 30, sf::Color(0, 0, 0), sf::Vector2f(300, 400));
	username.setString("Username:");
	setTextParameters(username, 30, sf::Color(0, 0, 0), sf::Vector2f(300, 400));
	setTextParameters(loginError, 20, sf::Color(0, 0, 0), sf::Vector2f(600, 700));
	setTextParameters(timeout_text, 25, sf::Color(0, 0, 0), sf::Vector2f(950, 380));
	setTextParameters(mat, 25, sf::Color(0, 0, 0), sf::Vector2f(910, 380));
}

void Interface::setFont()
{
	this->font.loadFromFile("fonts/Pacifico.ttf");
}

void Interface::setNames()
{
	this->nameWhite.setFont(font);
	this->nameWhite.setString("");
	this->nameWhite.setPosition(1090, 590);
	this->nameWhite.setFillColor(sf::Color(26, 26, 26));
	this->nameWhite.setCharacterSize(25);

	this->nameBlack.setFont(font);
	this->nameBlack.setString("");
	this->nameBlack.setPosition(1090, 190);
	this->nameBlack.setFillColor(sf::Color(26, 26, 26));
	this->nameBlack.setCharacterSize(25);
}

void Interface::setAuthor()
{
	author.setFont(font);
	author.setPosition(1200, 800);
	author.setString("Chess by Adam Warzecha");
	author.setCharacterSize(15);
}

void Interface::createFile(std::string& filename)
{
	std::ofstream outfile(filename + ".txt");
	outfile << filename << std::endl;
	outfile << "700" << std::endl;
	outfile.close();
}

void Interface::readPlayerNameAndRank(std::string filename, bool whiteORblack)
{
	try {
		std::ifstream file(filename + ".txt");
		std::string str;
		file.exceptions(std::ifstream::eofbit | std::ifstream::failbit | std::ifstream::badbit);
		if (std::getline(file, str))
		{
			if (whiteORblack == true)
			{
				nameWhite.setString(str);
				std::getline(file, str);
				whiteRank.setString(str);
			}
			else
			{
				nameBlack.setString(str);
				std::getline(file, str);
				blackRank.setString(str);
			}
		}
		file.close();
	}
	catch (std::exception const& e) {
		std::cout << "There was an error: " << e.what() << std::endl;
	}
}

void Interface::setTextParameters(sf::Text& text, unsigned int size, sf::Color color, sf::Vector2f position)
{
	text.setFont(this->font);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setPosition(position);
}

void Interface::setResetButton()
{
	this->resetButton.setFillColor(sf::Color(255, 102, 102));
	this->resetButton.setPosition(sf::Vector2f(740, 360));
	this->resetButton.setOutlineThickness(1.5);
	this->resetButton.setOutlineColor(sf::Color(51, 51, 51));
	this->resetButton.setSize(sf::Vector2f(160, 80));

	this->resetButtonText.setFont(this->font);
	this->resetButtonText.setString("Restart");
	this->resetButtonText.setCharacterSize(30);
	this->resetButtonText.setFillColor(sf::Color(51, 51, 51));
	this->resetButtonText.setPosition(765, 380);
}


bool Interface::containResetButton(sf::Vector2f mousePosition)
{

	if (this->resetButton.getGlobalBounds().contains(mousePosition))
	{
		return true;
	}
	return false;
}

void Interface::setMoveSqueres()
{
	this->whiteMove.setFillColor(sf::Color(102, 102, 102));
	this->whiteMove.setPosition(sf::Vector2f(800, 460));
	this->whiteMove.setOutlineThickness(1.5);
	this->whiteMove.setOutlineColor(sf::Color(51, 51, 51));
	this->whiteMove.setSize(sf::Vector2f(40, 40));

	this->blackMove.setFillColor(sf::Color(102, 102, 102));
	this->blackMove.setPosition(sf::Vector2f(800, 300));
	this->blackMove.setOutlineThickness(1.5);
	this->blackMove.setOutlineColor(sf::Color(51, 51, 51));
	this->blackMove.setSize(sf::Vector2f(40, 40));
}

void Interface::setTimes()
{
	this->white_time = sf::seconds(20);
	this->timerW.setFillColor(sf::Color(26, 26, 26));
	this->timerW.setString(std::to_string((int)(this->white_time.asSeconds())));
	this->timerW.setPosition(sf::Vector2f(795, 585));
	this->timerW.setFont(font);
	this->timerW.setCharacterSize(35);

	this->black_time = sf::seconds(600);
	this->timerB.setFillColor(sf::Color(26, 26, 26));
	this->timerB.setString(std::to_string((int)(this->black_time.asSeconds())));
	this->timerB.setPosition(sf::Vector2f(795, 185));
	this->timerB.setFont(font);
	this->timerB.setCharacterSize(35);
}

void Interface::changeRanking(bool whiteORblackMat)
{
	std::string tmp = this->whiteRank.getString();
	int wr = std::stoi(tmp);
	tmp = this->blackRank.getString();
	int br = std::stoi(tmp);

	if (whiteORblackMat == true)
	{
		if (wr > br + 100)
		{
			wr += (wr - br) / 10;
			if (br > 0)
				br -= (wr - br) / 15;

		}
		else if (wr <= br + 100 and wr > br)
		{
			wr += 15;
			if (br > 0)
				br -= 15;
		}
		else if (wr == br)
		{
			wr += 20;
			if (br > 0)
				br -= 20;
		}
		else if (wr < br and wr + 100 >= br)
		{
			wr += 25;
			if (br > 0)
				br -= 25;
		}
		else if (wr + 100 < br)
		{
			wr += (br - wr) / 5;
			if (br > 0)
				br -= (br - wr) / 7;
		}
	}
	else
	{
		if (br > wr + 100)
		{
			br += (br - wr) / 10;
			if (wr > 0)
				wr -= (br - wr) / 15;
		}
		else if (br <= wr + 100 and br > wr)
		{
			br += 15;
			if (wr > 0)
				wr -= 15;
		}
		else if (wr == br)
		{
			br += 20;
			if (wr > 0)
				wr -= 20;
		}
		else if (br < wr and br + 100 >= wr)
		{
			br += 25;
			if (wr > 0)
				wr -= 25;
		}
		else if (br + 100 < wr)
		{
			br += (wr - br) / 5;
			if (wr > 0)
				wr -= (wr - br) / 7;
		}
	}
	this->whiteRank.setString(std::to_string(wr));
	this->blackRank.setString(std::to_string(br));
}



void Interface::saveDataToFile()
{
	std::string tmp;

	tmp = nameWhite.getString();
	std::fstream white;
	white.open(tmp + ".txt", std::ios::out | std::ios::trunc);
	white << tmp << std::endl;
	tmp = whiteRank.getString();
	white << tmp << std::endl;
	white.close();

	tmp = nameBlack.getString();
	std::fstream black;
	black.open(tmp + ".txt", std::ios::out | std::ios::trunc);
	black << tmp << std::endl;
	tmp = blackRank.getString();
	black << tmp << std::endl;
	black.close();
}