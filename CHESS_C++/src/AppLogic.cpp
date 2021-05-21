#include "AppLogic.h"

AppLogic::AppLogic(Interface& intf)
{
	Player white(true);
	Player black(false);
	Game createGame(white, black);
	this->game = createGame;
	this->counter = 0;
	this->player = true;
	this->mousePosition.x = 0;
	this->mousePosition.y = 0;
	this->intfc = intf;
}

void AppLogic::startResetGame()
{
	this->game.board.white.ResetFigures();
	this->game.board.black.ResetFigures();
	this->game.board.piecePosition = this->game.board.loadPositions();
	this->game.board.pieces = this->game.board.setArray(this->game.board.piecePosition);
	this->player = true;
	this->counter = 4;
	this->mousePosition.x = 0;
	this->mousePosition.y = 0;
	this->intfc.black_time = sf::seconds(600);
	this->intfc.white_time = sf::seconds(600);
	this->intfc.timerB.setString(std::to_string((int)(this->intfc.black_time.asSeconds())));
	this->intfc.timeout_text.setString("");
	this->intfc.timerB.setFillColor(sf::Color(26, 26, 26));
	this->intfc.timerW.setFillColor(sf::Color(26, 26, 26));
	this->intfc.timerW.setPosition(sf::Vector2f(795, 585));
	this->intfc.timerB.setPosition(sf::Vector2f(795, 185));
	this->intfc.mat.setString("");
	this->setRankandNameForPlayer();
	checkW = 0;
	checkB = 0;
	timeout = false;
}


void AppLogic::play()
{
	setFont();
	sf::Clock clock;
	setTextParameters(input, 30, sf::Color(100, 100, 100), sf::Vector2f(450, 400));
	sf::RenderWindow window(sf::VideoMode(1400, 850), "Chess Game");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (counter)
			{
			case 0:
				if (event.type == sf::Event::TextEntered) {
					if (event.text.unicode < 128 && event.text.unicode != 8) {
						_input += static_cast<char>(event.text.unicode);
						input.setString(_input);
					}
				}
				else if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::BackSpace)
					{
						if (!_input.empty())
						{
							_input.pop_back();
						}
						input.setString(_input);
					}
					if (event.key.code == sf::Keyboard::Return)
					{
						counter = 1;
					}
				}
				break;
			case 1:
			{
				std::regex code("[A-Za-z0-9]{5,20}");
				if (std::regex_match(_input, code))
				{
					if (intfc.fileExist(_input))
					{
						intfc.readPlayerNameAndRank(_input, true);
					}
					else
					{
						intfc.createFile(_input);
						intfc.readPlayerNameAndRank(_input, true);
					}
					_input = "";
					input.setString(_input);
					counter = 2;
				}
				else
				{
					this->intfc.loginError.setString("Wrong username! Try again ...");
					_input = "";
					input.setString("");
					counter = 0;
				}
				break;
			}
			case 2:
			{
				this->intfc.loginError.setString("");
				this->intfc.loginPlayer.setString("Player black: Enter your username, press Enter to confirm");
				if (event.type == sf::Event::TextEntered) {
					if (event.text.unicode < 128 && event.text.unicode != 8) {
						_input += static_cast<char>(event.text.unicode);
						input.setString(_input);
					}
				}
				else if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::BackSpace)
					{
						if (!_input.empty())
						{
							_input.pop_back();
						}
						input.setString(_input);
					}
					if (event.key.code == sf::Keyboard::Return)
					{
						counter = 3;
					}
				}
				break;
			}
			case 3:
			{
				std::regex code("[A-Za-z0-9]{5,20}");
				if (std::regex_match(_input, code))
				{
					if (intfc.fileExist(_input))
					{
						intfc.readPlayerNameAndRank(_input, false);
					}
					else
					{
						intfc.createFile(_input);
						intfc.readPlayerNameAndRank(_input, false);
					}
					_input = "";
					input.setString(_input);
					setRankandNameForPlayer();
					loginPhase = false;
					counter = 4;
				}
				else
				{
					this->intfc.loginError.setString("Wrong username! Try again ...");
					_input = "";
					input.setString("");
					counter = 2;
				}
				break;
			}
			case 4:
			{
				tmp.clear();
				if (player == true)
				{
					this->intfc.whiteMove.setFillColor(sf::Color(112, 219, 112));
					this->intfc.blackMove.setFillColor(sf::Color(102, 102, 102));
				}
				mousePosition = game.selectField(window);
				this->intfc.resetButton.setFillColor(sf::Color(255, 102, 102));
				if (mousePosition.x > 0 and player == true)
				{
					std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
					if (this->intfc.containResetButton(mousePosition))
					{
						startResetGame();
					}
					counter = 5;
				}
				else if (mousePosition.x > 0 and player == false)
				{
					std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
					if (this->intfc.containResetButton(mousePosition))
					{
						startResetGame();
					}
					counter = 8;
				}
				break;
			}
			case 5:
				tmp = game.board.white.showWhiteFigureMove(mousePosition, game.board.piecePosition, game.board.pieces, game.board.black);
				this->intfc.resetButton.setFillColor(sf::Color(102, 102, 102));

				for (auto& move : tmp)
				{
					if (move.x != 0 and move.y != 0)
					{
						badMove++;
					}
				}
				if (badMove > 1)
				{
					counter = 6;
				}
				else if (badMove <= 1 or tmp.empty())
				{
					counter = 4;
					this->game.board.resetColors();
				}
				badMove = 0;
				break;
			case 6:
				mousePosition = game.board.white.Move(tmp, game.board.piecePosition, game.board.pieces, window, game.board.black);
				if (mousePosition.x > 0)
				{
					std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
					counter = 10;
				}
				break;
			case 7:
				tmp.clear();
				game.board.resetColors();
				player = !player;
				counter = 4;
				if (player == true)
				{
					this->intfc.whiteMove.setFillColor(sf::Color(112, 219, 112));
					this->intfc.blackMove.setFillColor(sf::Color(102, 102, 102));
				}
				else
				{
					this->intfc.whiteMove.setFillColor(sf::Color(102, 102, 102));
					this->intfc.blackMove.setFillColor(sf::Color(112, 219, 112));
				}
				break;
			case 8:
				tmp = game.board.black.showBlackFigureMove(mousePosition, game.board.piecePosition, game.board.pieces, game.board.white);
				this->intfc.resetButton.setFillColor(sf::Color(102, 102, 102));

				for (auto& move : tmp)
				{
					if (move.x != 0 and move.y != 0)
					{
						badMove++;
					}
				}
				if (badMove > 1)
				{
					counter = 9;
				}
				else if (badMove <= 1 or tmp.empty())
				{
					counter = 4;
					this->game.board.resetColors();
				}
				badMove = 0;
				break;
			case 9:
				mousePosition = game.board.black.Move(tmp, game.board.piecePosition, game.board.pieces, window, game.board.white);
				if (mousePosition.x > 0)
				{
					std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
					counter = 10;
				}
				break;
			case 10:

				if (this->game.board.white.checkCheck(game.board.piecePosition, game.board.pieces, game.board.black))
				{
					if (checkW == 1)
					{
						checkW = 2;
						this->intfc.setTextParameters(this->intfc.mat, 25, sf::Color(0, 0, 0), sf::Vector2f(910, 380));
						this->intfc.mat.setString("Player with white figures won by checkmate!");
						this->intfc.changeRanking(true);
						counter = 11;
					}
					else if (checkW == 0)
					{
						checkW = 1;
						this->intfc.setTextParameters(this->intfc.mat, 25, sf::Color(0, 0, 0), sf::Vector2f(1010, 380));
						this->intfc.mat.setString("The black king is checked!");
						counter = 7;

					}
				}
				else
				{
					checkW = 0;
					if (this->checkB == 0)
					{
						this->intfc.mat.setString("");
					}
				}
				this->game.board.resetColors();
				if (this->game.board.black.checkCheck(game.board.piecePosition, game.board.pieces, game.board.white))
				{
					if (checkB == 1)
					{
						checkB = 2;
						this->intfc.setTextParameters(this->intfc.mat, 25, sf::Color(0, 0, 0), sf::Vector2f(910, 380));
						this->intfc.mat.setString("Player with black figures won by checkmate!");
						this->intfc.changeRanking(false);
						counter = 11;
					}
					else if (checkB == 0)
					{
						checkB = 1;
						this->intfc.setTextParameters(this->intfc.mat, 25, sf::Color(0, 0, 0), sf::Vector2f(1010, 380));
						this->intfc.mat.setString("The white king is checked!");
						counter = 7;
					}
				}
				else
				{
					if (this->checkW == 0)
					{
						this->intfc.mat.setString("");
					}
					checkB = 0;
				}
				if (checkB != 2 and checkW != 2)
				{
					counter = 7;
				}
				this->game.board.resetColors();
				break;
			case 11:
				this->intfc.saveDataToFile();
				counter = 12;
				break;
			case 12:
				Sleep(2000);
				this->startResetGame();
				break;
			case 13:
				this->intfc.changeRanking(true);
				counter = 11;
				break;
			case 14:
				this->intfc.changeRanking(false);
				counter = 11;
				break;
			default:
				break;
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color(217, 217, 217));
		window.draw(this->intfc.author);
		window.draw(this->intfc.logo);

		if (loginPhase == false and player == true)
		{
			this->intfc.white_time -= clock.getElapsedTime();
			clock.restart();
			if (this->intfc.white_time <= sf::seconds(0) and timeout == 0)
			{
				this->intfc.timeout_text.setString("Player with black figures won by timeout!");
				this->intfc.timerW.setString("time over");
				this->intfc.timerW.setPosition(sf::Vector2f(760, 585));
				timeout = 1;
				counter = 14;
			}
			else if (this->intfc.white_time <= sf::seconds(10) and this->intfc.white_time > sf::seconds(0))
			{
				this->intfc.timerW.setFillColor(sf::Color(255, 102, 102));
				this->intfc.timerW.setString(std::to_string((this->intfc.white_time.asSeconds())));
			}
			else if (this->intfc.white_time > sf::seconds(10))
			{
				this->intfc.timerW.setString(std::to_string((int)(this->intfc.white_time.asSeconds())));
			}
		}
		else if (loginPhase == false and player == false)
		{
			this->intfc.black_time -= clock.getElapsedTime();
			clock.restart();
			if (this->intfc.black_time <= sf::seconds(0) and timeout == 0)
			{
				this->intfc.timeout_text.setString("Player with white figures won by timeout!");
				this->intfc.timerB.setString("time over");
				this->intfc.timerB.setPosition(sf::Vector2f(760, 585));
				timeout = 1;
				counter = 13;
			}
			else if (this->intfc.black_time <= sf::seconds(10) and this->intfc.black_time > sf::seconds(0))
			{
				this->intfc.timerB.setFillColor(sf::Color(255, 102, 102));
				this->intfc.timerB.setString(std::to_string((this->intfc.white_time.asSeconds())));
			}
			else if (this->intfc.black_time > sf::seconds(10))
			{
				this->intfc.timerB.setString(std::to_string((int)(this->intfc.black_time.asSeconds())));
			}
		}
		else if (loginPhase == true)
		{
			clock.restart();
		}

		if (loginPhase == true)
		{
			window.draw(input);
			window.draw(this->intfc.login);
			window.draw(this->intfc.loginPlayer);
			window.draw(this->intfc.username);
			window.draw(this->intfc.loginError);
		}
		else
		{
			game.board.drawBoard(window);
			game.board.drawFigures(window);
			window.draw(this->intfc.mat);
			window.draw(this->intfc.whiteIcon);
			window.draw(this->intfc.blackIcon);
			window.draw(this->intfc.nameWhite);
			window.draw(this->nameAndRankWhite);
			window.draw(this->nameAndRankBlack);
			window.draw(this->intfc.resetButton);
			window.draw(this->intfc.resetButtonText);
			window.draw(this->intfc.whiteMove);
			window.draw(this->intfc.blackMove);
			if (checkB != 2 and checkW != 2)
			{
				window.draw(this->intfc.timerW);
				window.draw(this->intfc.timerB);
				window.draw(this->intfc.timeout_text);
			}
		}
		window.display();
	}
}

void AppLogic::setFont()
{
	this->font.loadFromFile("fonts/Pacifico.ttf");
}

void AppLogic::setTextParameters(sf::Text& text, unsigned int size, sf::Color color, sf::Vector2f position)
{
	text.setFont(this->font);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setPosition(position);
}

void AppLogic::setRankandNameForPlayer()
{
	this->nameAndRankWhite.setString(this->intfc.nameWhite.getString() + " (" + this->intfc.whiteRank.getString() + ")");
	this->nameAndRankBlack.setString(this->intfc.nameBlack.getString() + " (" + this->intfc.blackRank.getString() + ")");
	setTextParameters(this->nameAndRankWhite, 25, sf::Color(26, 26, 26), sf::Vector2f(1090, 590));
	setTextParameters(this->nameAndRankBlack, 25, sf::Color(26, 26, 26), sf::Vector2f(1090, 190));
}