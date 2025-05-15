#pragma once

#include "Game.h"

class TicTacToe : public Game
{
private:
	char m_board[9];
	int m_currentPlayer;

public:
	TicTacToe();

	virtual bool IsGameOver() const;
	virtual void Display() const;
	virtual void TakeTurn();

	bool CheckWin(char symbol) const;
	bool CheckTie() const;
	void SwitchPlayers();
};