#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define MAXrows 50
#define MAXcolumns 20

struct Point
{
	int x; // -----> rows i
	int y; // -----> columns j
	char body;
};

enum pointsOfInterest
{
	me,
	opp,
	apple,
	middle
};


string DetermineMove(int, int, char table[MAXrows][MAXcolumns]);
void ReadFromInput(int, int, int, char table[MAXrows][MAXcolumns]);
Point GetPosition(string, int, int , char table[MAXrows][MAXcolumns]);
int GetDistance(Point, Point);
bool AmICloser(Point, Point, Point);
vector<string> IdiotProofSnake(vector<string>,Point, int, int, char table[MAXrows][MAXcolumns]);  
string ChooseDirection(vector<string>, Point, Point, int, int, char table[MAXrows][MAXcolumns]);

string SpecifyDirection(vector<string>, string);
string FurtherSpecifyDirection(vector<string>, string, string);

int main()
{
	int r,c,numberOfApples=1;
	char table[MAXrows][MAXcolumns];
	//char table[MAXrows][MAXcolumns] = { { 'c','d','c','f','g','h','i','j','.','.','.','.','.','.' },
	//									{ 'b','a','.','.','.','.','.','.','.','.','.','.','.','.' },
	//									{ '.','.','.','.','.','.','.','.','.','.','.','.','.','.' },
	//									{ '.','.','.','.','.','.','.','.','.','@','.','.','.','.' },
	//									{ '.','.','.','.','B','A','.','.','.','.','.','.','.','.' },
	//									{ '.','.','.','.','C','.','.','.','.','.','.','.','.','.' },
	//									{ '.','.','F','E','D','.','.','.','.','.','.','.','.','.' }
	//};

	while(numberOfApples > 0)
	{
		//ReadFromInput(r, c, numberOfApples, table);

		cin >> r >> c >> numberOfApples;

		for (int i = 0; i < r; i++)
		{
			char tempRow[MAXcolumns];

			for (int j = 0; j < c; j++)
			{
				cin >> tempRow[j];
				table[i][j] = tempRow[j];
			}
		}

		cout << DetermineMove(r, c, table) << endl;

	}
			
	return 0;
}

void ReadFromInput(int r, int c, int numberOfApples, char table[MAXrows][MAXcolumns])
{
	cin >> r >> c >> numberOfApples;

	for (int i = 0; i < r; i++)
	{
		char tempRow[MAXcolumns];

		for (int j = 0; j < c; j++)
		{
			cin >> tempRow[j];
			table[i][j] = tempRow[j];
		}
	}
}

string DetermineMove(int rows, int columns, char table[MAXrows][MAXcolumns])
{
	//vector<string> possibleDirections;
	//possibleDirections.push_back("Up");
	//possibleDirections.push_back("Down");
	//possibleDirections.push_back("Left");
	//possibleDirections.push_back("Right");
	

	Point me = GetPosition("me",rows, columns, table);
	me.body = 'A';
	Point opp = GetPosition("opp", rows, columns, table);
	Point apple = GetPosition("apple", rows, columns, table);
	Point middle = GetPosition("middle", rows, columns, table);
	
	vector<string> temp;
	vector<string> possibleDirections = IdiotProofSnake(temp, me, rows, columns, table);

	//vector<Point> snake

	bool test = AmICloser(me, opp, apple);


	if(AmICloser(me, opp, apple))
	{

			ChooseDirection(possibleDirections, me, apple, rows, columns, table);

		//set the best direction for the APPLE
		
	}
	else
	{

			ChooseDirection(possibleDirections, me, middle, rows, columns, table);
		//set the best direction for the MIDDLE
		
	}
	string p;
	return p;
}



Point GetPosition(string type, int rows, int columns, char table[MAXrows][MAXcolumns])
{
	Point target;
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (type == "me" && table[i][j] == 'A')
			{
				target.x = i;
				target.y = j;

			}
			else if (type == "opp" && table[i][j] == 'a')
			{
				target.x = i;
				target.y = j;
			}
			else if (type == "apple" &&  table[i][j] == '@')
			{
				target.x = i;
				target.y = j;

			}
			else if (type == "middle")
			{
				target.x = rows / 2; 
				target.y = columns / 2;
			}
		}
	}
	return target;
}
	
int GetDistance(Point one, Point two)
{
	int distance;
	distance = abs(one.x - two.x) + abs(one.y - two.y);
	return distance;
}

bool AmICloser(Point me, Point opp, Point apple)
{
	int mee = GetDistance(me, apple);
	int youu = GetDistance(opp, apple);

	if (GetDistance(me, apple) < GetDistance(opp, apple))
		return true;
	else
		return false;
}

vector<string> IdiotProofSnake(vector<string> possibleD, Point me, int rows, int columns, char table[MAXrows][MAXcolumns])
{
	vector<string> impossibleDirections;

	// self collision or collision with the other snake
	bool notOnEdge = me.x > 0 && me.x < rows - 1 && me.y > 0 && me.y < columns - 1;
	if(notOnEdge)
	{
		Point aboveMe;
		aboveMe.x = me.x - 1;
		aboveMe.y = me.y;

		Point belowMe;
		belowMe.x = me.x + 1;
		belowMe.y = me.y;
		Point leftFromMe;
		leftFromMe.x = me.x;
		leftFromMe.y = me.y - 1;
		Point rightFromMe;
		rightFromMe.x = me.x;
		rightFromMe.y = me.y + 1;

		for (int i = 65; i < 123; i++)
		{
			if (table[aboveMe.x][aboveMe.y] == i)
			{
				impossibleDirections.push_back("Up");
			}

			if (table[belowMe.x][belowMe.y] == i)
			{
				impossibleDirections.push_back("Down");
			}

			if (table[leftFromMe.x][leftFromMe.y] == i)
			{
				impossibleDirections.push_back("Left");
			}
			if (table[rightFromMe.x][rightFromMe.y] == i)
			{
				impossibleDirections.push_back("Right");
			}
		}
	}
	else
	{
		//stay in table
		if (me.x == 0)
		{
			if (me.y == 0)
			{
				impossibleDirections.push_back("Up");
				impossibleDirections.push_back("Left");
			}
			else if (me.y == columns - 1)
			{
				impossibleDirections.push_back("Up");
				impossibleDirections.push_back("Right");
			}
			else
			{
				impossibleDirections.push_back("Up");
			}
		}

		else if (me.x == rows - 1)
		{
			if (me.y == 0)
			{
				impossibleDirections.push_back("Down");
				impossibleDirections.push_back("Left");
			}
			else if (me.y == columns - 1)
			{
				impossibleDirections.push_back("Down");
				impossibleDirections.push_back("Right");
			}
			else
			{
				impossibleDirections.push_back("Down");
			}
		}

		else if (me.y == 0)
		{
			impossibleDirections.push_back("Left");
		}
		else if (me.y == columns - 1)
		{
			impossibleDirections.push_back("Right");
		}
	}

	string allDirections[4];
	allDirections[0] = "Up";
	allDirections[1] = "Down";
	allDirections[2] = "Left";
	allDirections[3] = "Right";
	
	for (int i = 0; i < 4; i ++)
	{
		bool flag = false;
		for (int j = 0; j < impossibleDirections.size();j++)
		{
			if (allDirections[i] == impossibleDirections[j])
			{
				flag = true;
				break;
			}

		
		}
		if(flag == false)
			possibleD.push_back(allDirections[i]);
	}
	return possibleD;
}

string SpecifyDirection(vector<string> p, string preferredDirection)
{
	string finalDirection;
	bool flag = false;
	for (int i = 0; i < p.size(); i++)
	{
		if (preferredDirection == p[i])
		{
			finalDirection = preferredDirection;
			flag = true;
		}
	}

	if (flag == false)
		finalDirection = p[0];
	return finalDirection;
}



string ChooseDirection(vector<string> possibleDirections, Point me, Point target, int rows, int columns, char table[MAXrows][MAXcolumns])
{
	string direction;
	//first on x then on y
	//Manhattan distance so it doesn't really matters

	bool northOfTarget = me.x < target.x && me.y == target.y;
	bool southOftarget = me.x > target.x && me.y == target.y;
	bool eastOfTarget = me.x == target.x && me.y > target.y;
	bool westOftarget = me.x == target.x && me.y < target.y;

	bool onPoint = me.x == target.x && me.y == target.y;

	bool northWestOftarget = me.x < target.x && me.y < target.y;
	bool southWestOftarget = me.x > target.x && me.y < target.y;
	bool northEastOftarget = me.x < target.x && me.y > target.y;
	bool southEastOftarget = me.x > target.x && me.y > target.y;

	string preferredDir;
	string okayDir;

	if (onPoint)
	{
		direction = possibleDirections[0];
		//build snek
	}

	if (northOfTarget)
	{
		preferredDir = "Down";
		direction = SpecifyDirection(possibleDirections, preferredDir);
	}

	if (southOftarget)
	{
		preferredDir = "Up";
		direction = SpecifyDirection(possibleDirections, preferredDir);
	}

	if (westOftarget)
	{
		preferredDir = "Right";
		direction = SpecifyDirection(possibleDirections, preferredDir);
	}

	if (eastOfTarget)
	{
		preferredDir = "Left";
		direction = SpecifyDirection(possibleDirections, preferredDir);
	}

	if(northWestOftarget)
	{
		preferredDir = "Down";
		okayDir = "Right";

		direction = FurtherSpecifyDirection(possibleDirections, preferredDir, okayDir);

	}

	if (southWestOftarget)
	{
		preferredDir = "Up";
		okayDir = "Right";

		direction = FurtherSpecifyDirection(possibleDirections, preferredDir, okayDir);

	}

	if (northEastOftarget)
	{
		preferredDir = "Down";
		okayDir = "Left";

		direction = FurtherSpecifyDirection(possibleDirections, preferredDir, okayDir);

	}

	if (southEastOftarget)
	{
		preferredDir = "Up";
		okayDir = "Left";

		direction = FurtherSpecifyDirection(possibleDirections, preferredDir, okayDir);

	}

	return direction;
}

string FurtherSpecifyDirection(vector<string> possibleDirections, string preferredDir, string okayDir)
{
	string direction;
	direction = SpecifyDirection(possibleDirections, preferredDir);
	if (direction != preferredDir)
	{
		direction =  SpecifyDirection(possibleDirections, okayDir);
		if (direction != okayDir)
			direction = possibleDirections[0];
	}
		
	

	return direction;
}