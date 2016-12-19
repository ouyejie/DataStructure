#include<stdlib.h>
#include "../../stack/src/Stack.h"

char mazeMap[10][10] = 
{
	{ '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' },
	{ '1', '0', '0', '1', '0', '0', '0', '0', '0', '1' },
	{ '1', '0', '0', '1', '0', '0', '0', '1', '0', '1' },
	{ '1', '0', '0', '0', '0', '1', '1', '0', '0', '1' },
	{ '1', '0', '1', '1', '0', '0', '0', '0', '0', '1' },
	{ '1', '0', '0', '0', '1', '0', '0', '0', '0', '1' },
	{ '1', '0', '1', '1', '1', '0', '1', '0', '0', '1' },
	{ '1', '0', '1', '0', '1', '0', '1', '1', '0', '1' },
	{ '1', '0', '1', '0', '0', '0', '0', '0', '0', '1' },
	{ '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' } 
};

typedef struct 
{
	int x;
	int y;
}Seat;

typedef struct  
{
	Seat seat;
	int direction;
	int count;
}Block;

bool verifyIsExistStack(Stack<Block>* blockStack, Block curBlock)
{
	Block block;
	blockStack->resetTravel();
	while (blockStack->getTravel(block) == 0)
	{
		if (curBlock.seat.x == block.seat.x && curBlock.seat.y == block.seat.y)
		{
			return true;
		}
	}
	return false;
}

bool IsPassBlock(char maze[10][10], Stack<Block>* blockStack, Block curBlock)
{
	if (maze[curBlock.seat.x][curBlock.seat.y] == '1'|| verifyIsExistStack(blockStack, curBlock))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool NextDirection(Block* block, int* direction)
{
	if (++block->count < 4)
	{
		*direction = ++block->direction % 4;
		block->direction = *direction;
		return true;
	}
	return false;
}

Block NextBlock(Block curBlock, int direction)
{
	curBlock.count = 0;
	switch (direction)
	{
	case 0:	// east
		curBlock.seat.x = curBlock.seat.x;
		curBlock.seat.y = curBlock.seat.y + 1;
		break;
	case 1:// south
		curBlock.seat.x = curBlock.seat.x + 1;
		curBlock.seat.y = curBlock.seat.y;
		break;
	case 2:// west
		curBlock.seat.x = curBlock.seat.x;
		curBlock.seat.y = curBlock.seat.y - 1;
		break;
	case 3:// north
		curBlock.seat.x = curBlock.seat.x - 1;
		curBlock.seat.y = curBlock.seat.y;
		break;
	default:
		break;
	}
	return curBlock;
}

void MarkPrint(char maze[10][10], Block block)
{
	maze[block.seat.x][block.seat.y] = '1';
}

void printPath(Stack<Block>* blockStack)
{

}

void MazePath(char maze[10][10], Seat start, Seat end)
{
	Stack<Block>* blockStack = new Stack<Block>();
	blockStack->InitStack();
	Block curBlock;
	curBlock.seat = start;
	curBlock.direction = 0;
	curBlock.count = 0;
	do
	{
		if (IsPassBlock(maze, blockStack, curBlock))
		{
			blockStack->push(curBlock);
			if (curBlock.seat.x == end.x && curBlock.seat.y == end.y)
			{
				break;
			}
			curBlock = NextBlock(curBlock, curBlock.direction);
		}
		else
		{
			blockStack->GetTop(curBlock);
			Block temp;

 			if(curBlock.count >= 3 && !blockStack->IsEmpty())
			{
				MarkPrint(maze, curBlock);	
				blockStack->pop(temp);
				if (blockStack->IsEmpty()){ break; }
				blockStack->GetTop(curBlock);
			}
			int direction;
			if (NextDirection(&curBlock, &direction))
			{
				blockStack->pop(temp);
				blockStack->push(curBlock);
				curBlock = NextBlock(curBlock, direction);
			}
		}
	} while (!blockStack->IsEmpty());

	printf("return:\n");
	if (blockStack->IsEmpty())
	{
		printf("not way to go...\n");
	}
	while (!blockStack->IsEmpty())
	{
		Block block;
		blockStack->pop(block);
		printf("<%d,%d>\n", block.seat.x, block.seat.y);
	}
}

int main()
{
	Seat start;
	Seat end;
	start.x = 1;
	start.y = 1;
	end.x = 8;
	end.y = 8;
	MazePath(mazeMap, start, end);

	system("pause");
	return 0;
}