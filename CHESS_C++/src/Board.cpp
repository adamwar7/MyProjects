#include "Board.h"

Board::Board() : BoardPieces()
{
	Player a(true);
	Player b(false);
	this->black = a;
	this->white = b;
}

Board::Board(Player white, Player black) : BoardPieces()
{
	this->black = black;
	this->white = white;
}

void Board::drawFigures(sf::RenderWindow& window)
{
    for (auto i : white.pawns)
    {
        window.draw(i->getSprite());

    }
    window.draw(this->white.ra->getSprite());
    window.draw(this->white.rh->getSprite());
    window.draw(this->white.bc->getSprite());
    window.draw(this->white.bf->getSprite());
    window.draw(this->white.kb->getSprite());
    window.draw(this->white.kg->getSprite());
    window.draw(this->white.queen->getSprite());
    window.draw(this->white.king->getSprite());

    for (auto i : black.pawns)
    {
        window.draw(i->getSprite());

    }
    window.draw(this->black.ra->getSprite());
    window.draw(this->black.rh->getSprite());
    window.draw(this->black.bc->getSprite());
    window.draw(this->black.bf->getSprite());
    window.draw(this->black.kb->getSprite());
    window.draw(this->black.kg->getSprite());
    window.draw(this->black.queen->getSprite());
    window.draw(this->black.king->getSprite());
}

