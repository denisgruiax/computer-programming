#include <stdio.h>
#include <stdlib.h>

#define limit(x, y, key) ((key >= x) && (key < y) ? 1 : 0)

char **gameBoard_;

char **allocateBoard(char **gameBoard, unsigned lines, unsigned columns);
void initBoard(char **gameBoard, unsigned lines, unsigned columns);
void setPositions(char **gameBoard, unsigned lines, unsigned columns);
void printBoard(char **gameBoard, unsigned lines, unsigned columns);
unsigned calculateNeighbors(char **gameBoard, unsigned lines, unsigned columns, int line, int column);
unsigned **neighborsBoard(unsigned **neighborsMatrix, unsigned lines, unsigned columns);
void printNeighborsMatrix(unsigned **neighborsMatrix, unsigned lines, unsigned columns);

int main()
{
    unsigned lines, columns;
    unsigned **neighborsMatrix;

    printf("Insert size of lines & columns: ");
    scanf("%u %u", &lines, &columns);

    gameBoard_ = allocateBoard(gameBoard_, lines, columns);
    initBoard(gameBoard_, lines, columns);
    setPositions(gameBoard_, lines, columns);
    printBoard(gameBoard_, lines, columns);

    neighborsMatrix = neighborsBoard(neighborsMatrix, lines, columns);
    printNeighborsMatrix(neighborsMatrix, lines, columns);
}

char **allocateBoard(char **gameBoard, unsigned lines, unsigned columns)
{
    gameBoard = (char **)malloc(sizeof(char *) * lines);
    for (unsigned i = 0; i < columns; i++)
    {
        gameBoard[i] = (char *)malloc(sizeof(char) * columns);
    }

    return gameBoard;
}
void initBoard(char **gameBoard, unsigned lines, unsigned columns)
{
    for (unsigned i = 0; i < lines; i++)
    {
        for (unsigned j = 0; j < columns; j++)
        {
            gameBoard[i][j] = '.';
        }
    }
    puts("\n");
}

void setPositions(char **gameBoard, unsigned lines, unsigned columns)
{
    unsigned line = 0, column = 0;
    char option = 0;
    do
    {
    playerA:
    {
        printf("Player A: ");
        scanf("%u %u", &line, &column);
    }

        if (limit(0, lines, line) && (limit(0, columns, column)))
        {
            if (gameBoard[line][column] = '.')
                gameBoard[line][column] = 'a';
            else
            {
                puts("The position is filled..");
                goto playerA;
            }
        }
        else
        {
            puts("Out of interval");
        }

    playerB:
    {
        printf("Player B: ");
        scanf("%u %u", &line, &column);
    }

        if (limit(0, lines, line) && (limit(0, columns, column)))
        {
            if (gameBoard[line][column] == '.')
                gameBoard[line][column] = 'b';
            else
            {
                puts("The position is filled.");
                goto playerB;
            }
        }
        else
        {
            puts("Out of interval."); //inserati o valoare mai mare din interval pentru a omite o citire
        }

        puts("Fill 2 positions ? (Y/N)");
        scanf(" %c", &option); //be careful on errors!!!
    } while (option != 'N');
}

void printBoard(char **gameBoard, unsigned lines, unsigned columns)
{
    for (unsigned i = 0; i < lines; i++, putchar('\n'))
        for (unsigned j = 0; j < columns; j++)
        {
            printf("%c ", gameBoard[i][j]);
        }
    putchar('\n');
}
unsigned calculateNeighbors(char **gameBoard, unsigned lines, unsigned columns, int line, int column)
{
    unsigned sum = 0;

    for (int i = (line - 1); i <= (line + 1); i++)
    {
        for (int j = (column - 1); j <= (column + 1); j++)
        {
            if ((limit(0, lines, i)) && (limit(0, columns, j)))
            {
                if ((i != line) || (j != column))
                    if ((gameBoard[i][j] == 'b'))
                        sum++;
            }
        }
    }
    return sum;
}
unsigned **neighborsBoard(unsigned **neighborsMatrix, unsigned lines, unsigned columns)
{
    neighborsMatrix = (unsigned **)malloc(sizeof(unsigned *) * lines);
    for (unsigned i = 0; i < columns; i++)
        neighborsMatrix[i] = (int *)malloc(sizeof(unsigned) * columns);

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            neighborsMatrix[i][j] = calculateNeighbors(gameBoard_, lines, columns, i, j);
        }
    }

    return neighborsMatrix;
}

void printNeighborsMatrix(unsigned **neighborsMatrix, unsigned lines, unsigned columns)
{
    for (size_t i = 0; i < lines; i++, putchar('\n'))
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("%u ", neighborsMatrix[i][j]);
        }
    }

    putchar('\n');
}