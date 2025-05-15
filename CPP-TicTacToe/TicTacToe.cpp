
// Assignment 6 - Tic Tac Toe
// Michael Dessables

#include <iostream>
#include "TicTacToe.h"

// Constructor
TicTacToe::TicTacToe()
{
	m_currentPlayer = 0;

	for (int i = 0; i < 9; i++)
	{
		m_board[i] = ' ';
	}
}

// Display board the baord with player marks and turns
void TicTacToe::Display() const
{
	std::cout << "\n";
	std::cout << " " << m_board[0] << " | " << m_board[1] << " | " << m_board[2] << "\n";
	std::cout << "---|---|---\n";
	std::cout << " " << m_board[3] << " | " << m_board[4] << " | " << m_board[5] << "\n";
	std::cout << "---|---|---\n";
	std::cout << " " << m_board[6] << " | " << m_board[7] << " | " << m_board[8] << "\n";
	std::cout << "\n";

	char symbol = m_currentPlayer == 0 ? 'X' : 'O';
	std::cout << "Player " << (m_currentPlayer + 1) << " (" << symbol << ")'s turn.\n";
}


void TicTacToe::TakeTurn()
{
	int spaceChosen = 0;
	char symbol = m_currentPlayer == 0 ? 'X' : 'O';

	while (true)
	{
		std::cout << "Enter a number between 1 and 9: ";
		std::cin >> spaceChosen;

		if (spaceChosen < 1 || spaceChosen > 9)
		{
			std::cout << "Invalid input. Try again.\n";
		}
		else if (m_board[spaceChosen - 1] != ' ')
		{
			std::cout << "That space is already taken. Try again.\n";
		}
		else
		{
			break;
		}
	}

	m_board[spaceChosen - 1] = symbol;

	// If the game is over, show the result
	if (CheckWin(symbol))
	{
		std::cout << "Game Over!\n";
		std::cout << "Player " << (m_currentPlayer + 1) << " (" << symbol << ") wins!\n";
	}
	else if (CheckTie())
	{
		std::cout << "Game Over!\nIt's a tie!\n";
	}
	else
	{
		SwitchPlayers();
	}
}


bool TicTacToe::IsGameOver() const
{
	return CheckWin('X') || CheckWin('O') || CheckTie();

}

bool TicTacToe::CheckWin(char symbol) const
{
	return (
		(m_board[0] == symbol && m_board[1] == symbol && m_board[2] == symbol) ||
		(m_board[3] == symbol && m_board[4] == symbol && m_board[5] == symbol) ||
		(m_board[6] == symbol && m_board[7] == symbol && m_board[8] == symbol) ||
		(m_board[0] == symbol && m_board[3] == symbol && m_board[6] == symbol) ||
		(m_board[1] == symbol && m_board[4] == symbol && m_board[7] == symbol) ||
		(m_board[2] == symbol && m_board[5] == symbol && m_board[8] == symbol) ||
		(m_board[0] == symbol && m_board[4] == symbol && m_board[8] == symbol) ||
		(m_board[2] == symbol && m_board[4] == symbol && m_board[6] == symbol)
		);
}


bool TicTacToe::CheckTie() const
{
	for (int i = 0; i < 9; i++)
	{
		if (m_board[i] == ' ')
			return false;
	}
	return true;
}

// Switches the current player
void TicTacToe::SwitchPlayers()
{
	m_currentPlayer = (m_currentPlayer == 0) ? 1 : 0;
}
