#include "GameGUI.h"
#include <iostream>
using namespace std;

GameGUI::GameGUI(int size, int wincondition) : window(sf::VideoMode(800, 600), "Tic Tac Toe"), size(size), wincondition(wincondition)
{
    board = new char* [size];
    for (size_t i = 0; i < size; i++)
    {
        board[i] = new char[size];
        for (size_t j = 0; j < size; j++)
        {
            board[i][j] = ' ';
        }
    }
    maxDepth = 9; // Default value
}

GameGUI::~GameGUI()
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}

void GameGUI::run()
{
    while (window.isOpen())
    {
        EventHandler();
        Draw();
    }
}

void GameGUI::EventHandler()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                size_t x = (event.mouseButton.y) / (window.getSize().y / this->size) ;
                size_t y = (event.mouseButton.x) / (window.getSize().x / this->size);
                if (isValidMove(x, y))
                {
                    board[x][y] = 'X';
                    if (isWin('X'))
                    {
                        cout << "You won!" << endl;
                       // window.close();
                    }
                    else if (isDraw())
                    {
                        cout << "Draw!" << endl;
                       // window.close();
                    }
                    else
                    {
                        AITurn('O', 'X');
                        if (isWin('O'))
                        {
                            cout << "AI won!" << endl;
                           // window.close();
                        }
                        else if (isDraw())
                        {
                            cout << "Draw!" << endl;
                            //window.close();
                        }
                    }
                }
            }
        }
    }
}

void GameGUI::Draw()
{
    window.clear(sf::Color::White);
    float cellWidth = window.getSize().x / static_cast<float>(this->size);
    float cellHeight = window.getSize().y / static_cast<float>(this->size);
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++)
        {
            sf::RectangleShape rectangle(sf::Vector2f(cellWidth, cellHeight));
            rectangle.setPosition(j * cellWidth, i * cellHeight);
            rectangle.setOutlineThickness(2.f);
            rectangle.setOutlineColor(sf::Color::Black);
            rectangle.setFillColor(sf::Color::Transparent);
            window.draw(rectangle);
            if (board[i][j] == 'X')
            {
                sf::RectangleShape xSign(sf::Vector2f(cellWidth / 2, 4.f));
                xSign.setPosition(j * cellWidth + cellWidth / 4, i * cellHeight + cellHeight / 4);
                xSign.setFillColor(sf::Color::Cyan);
                xSign.rotate(45.f);
                window.draw(xSign);
                sf::RectangleShape xSign2(sf::Vector2f(cellWidth / 2, 4.f));
                xSign2.setPosition(j * cellWidth + cellWidth / 4, i * cellHeight +  (3 * cellHeight) / 4);
                xSign2.setFillColor(sf::Color::Cyan);
                xSign2.rotate(-45.f);
                window.draw(xSign2);
            }
            else if (board[i][j] == 'O')
            {
                sf::CircleShape oSign(cellWidth / 3);
                oSign.setPosition(j * cellWidth - cellWidth / 4, i * cellHeight - cellHeight / 4);
                oSign.setFillColor(sf::Color::Magenta);
                oSign.setOutlineThickness(2.f);
                oSign.setOutlineColor(sf::Color::Black);
                oSign.setOrigin(cellWidth / 6 , cellHeight / 6);
                oSign.move(cellWidth / 2, cellHeight / 2);
                window.draw(oSign);
            }
        }
    }
    window.display();
}

bool GameGUI::isValidMove(int x, int y)
{
    return x >= 0 && x < this->size && y >= 0 && y < this->size && board[x][y] == ' ';
}

bool GameGUI::isWin(char sign)
{
    size_t rows = 0;
    size_t columns = 0;
    // Searching rows and columns
    for (size_t i = 0; i < this->size; i++)
    {
        rows = 0;
        columns = 0;
        for (size_t j = 0; j < this->size; j++)
        {
            if (this->board[i][j] == sign) 
            {
                rows++;
                if (rows == this->wincondition) {
                    return true;
                }
            }
            else
            {
                rows = 0;
            }
            if (this->board[j][i] == sign)
            {
                columns++;
                if (columns == this->wincondition) {
                    return true;
                }
            }
            else
            {
                columns = 0;
            }
            
        }
    }
    size_t diagonal1 = 0;
    size_t diagonal2 = 0;
    // Searching diagonals
    for (size_t i = 0; i <= this->size - this->wincondition; i++) {
        for (size_t j = 0; j < this->size; j++) {
            int count1 = 0;
            int count2 = 0;
            for (size_t k = 0; k < this->wincondition; k++) {
                if (i + k < size && j + k < size && board[i + k][j + k] == sign) {
                    count1++;
                    if (count1 == this->wincondition)
                        return true;
                }
                else {
                    count1 = 0;
                }

                if (i + k < size && j >= k && board[i + k][j - k] == sign) {
                    count2++;
                    if (count2 == this->wincondition)
                        return true;
                }
                else {
                    count2 = 0;
                }
            }
        }
    }
    return false;
}

bool GameGUI::isDraw()
{
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void GameGUI::AITurn(char sign, char opponentSign)
{
    int bestScore = INT_MIN;
    int bestRow = -1;
    int bestColumn = -1;

    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j <  this->size; j++)
        {
            if (isValidMove(i,j)) {
                this->board[i][j] = sign;
                int score = minimax(sign, opponentSign, 1, true, INT_MAX, INT_MIN);
                this->board[i][j] = ' ';
                if (score > bestScore)
                {
                    bestScore = score;
                    bestRow = i;
                    bestColumn = j;
                }
            }
        }
    }

    this->board[bestRow][bestColumn] = sign;

}

int GameGUI::minimax(char sign, char opponentSign, size_t depth, bool isMaximizingPlayer, int alpha, int beta)
{
    if (depth == maxDepth || isWin(sign) || isWin(opponentSign) || isDraw()) 
    {
        return EvaluateState(sign, opponentSign, depth);  
    }
    
  
    if (isMaximizingPlayer)
    {
        int bestScore = INT_MAX;
        for (size_t i = 0; i < this->size; i++)
        {
            for (size_t j = 0; j < this->size; j++)
            {
                if (isValidMove(i, j))
                {
                    this->board[i][j] = opponentSign;
                    int score = minimax(sign, opponentSign, depth + 1, false, alpha, beta);
                    this->board[i][j] = ' ';
                    bestScore = min(bestScore, score);
                    alpha = min(alpha, bestScore);
                    if (alpha <= beta)
                        break;
                }
            }
            if (alpha <= beta)
                break;
        }
        return bestScore;
    }
    else
    {
        int bestScore = INT_MIN;
        for (size_t i = 0; i < this->size; i++)
        {
            for (size_t j = 0; j < this->size; j++)
            {
                if (isValidMove(i, j))
                {
                    this->board[i][j] = sign;
                    int score = minimax(sign, opponentSign, depth + 1, true, alpha, beta);
                    this->board[i][j] = ' ';
                    bestScore = max(bestScore, score);
                    beta = max(beta, bestScore);
                    if (alpha <= beta)
                        break;
                }
            }
           if (alpha <= beta)
                break;
        }
        return bestScore;
    }
}

int GameGUI::EvaluateState(char sign, char opponentSign, size_t depth)
{
    size_t rows = 0;
    size_t columns = 0;
    size_t OpponentRows = 0;
    size_t OpponentColumns = 0;
    // Searching rows and columns
    for (size_t i = 0; i < this->size; i++)
    {
        rows = 0;
        columns = 0;
        OpponentColumns = 0;
        OpponentRows = 0;
        for (size_t j = 0; j < this->size; j++)
        {
            if (this->board[i][j] == opponentSign)
            {
                OpponentRows++;
                if (OpponentRows == this->wincondition)
                    return -1 - this->maxDepth + depth;
            }
            else
            {
                OpponentRows = 0;
            }

            if (this->board[i][j] == sign) 
            {
                rows++;
                if (rows == this->wincondition)
                    return 1 + this->maxDepth - depth;
            }
            else
            {
                rows = 0;
            }
            

            if (this->board[j][i] == opponentSign)
            {
                OpponentColumns++;
                if (OpponentColumns == this->wincondition)
                    return -1 - this->maxDepth + depth;
            }
            else
            {
                OpponentColumns = 0;
            }

            if (this->board[j][i] == sign)
            {
                columns++;
                if (columns == this->wincondition)
                    return 1 + this->maxDepth - depth;
            }
            else
            {
                columns = 0;
            }
            

        }
    }
    size_t diagonal1 = 0;
    size_t diagonal2 = 0;
    size_t OpponentDiagonal1 = 0;
    size_t OpponentDiagonal2 = 0;
    // Searching diagonals
    for (size_t i = 0; i <= this->size - this->wincondition; i++) {
        for (size_t j = 0; j < this->size; j++) {
            int count1 = 0;
            int count2 = 0;
            int OpponentCount1 = 0;
            int OpponentCount2 = 0;
            for (size_t k = 0; k < this->wincondition; k++) {
                if (i + k < this->size && j + k < this->size && this->board[i + k][j + k] == opponentSign)
                {
                    OpponentCount1++;
                    if (OpponentCount1 == this->wincondition)
                        return -1 - this->maxDepth + depth;
                }
                else
                {
                    OpponentCount1 = 0;
                }

                if (i + k < this->size && j + k < this->size && this->board[i + k][j + k] == sign) 
                {
                    count1++;
                    if (count1 == this->wincondition)
                        return 1 + this->maxDepth - depth;
                }
                else
                {
                    count1 = 0;
                }

                if (i + k < this->size && j >= k && this->board[i + k][j - k] == opponentSign)
                {
                    OpponentCount2++;
                    if (OpponentCount2 == this->wincondition)
                        return -1 - this->maxDepth + depth;
                }
                else
                {
                    OpponentCount2 = 0;
                }

                if (i + k < this->size && j >= k && this->board[i + k][j - k] == sign)
                {
                    count2++;
                    if (count2 == this->wincondition)
                        return 1 + this->maxDepth - depth;
                }
                else
                {
                    count2 = 0;
                }
       
            }
        }
    }
    return 0;
}