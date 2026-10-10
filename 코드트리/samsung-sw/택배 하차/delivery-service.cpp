#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Box
{
    int id;
    int r, c;
    int height, width;
    bool isRemoved = false;
};

int n, m;
vector<vector<int>> grid;
vector<Box> boxes;

void MarkBox(const Box& box, int val)
{
    for (int i = 0; i < box.height; i++)
    {
        for (int j = 0; j < box.width; j++)
        {
            grid[box.r + i][box.c + j] = val;
        }
    }
}

bool CanPlace(int r, int c, int h, int w)
{
    if (r + h > n)
        return false;

    if (c < 0 || c + w > n)
        return false;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[r + i][c + j] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

void DropBox(Box& b)
{
    while (CanPlace(b.r + 1, b.c, b.height, b.width))
    {
        b.r++;
    }
}

void PushNewBox(int id, int h, int w, int startC)
{
    Box newBox = { id, 0, startC, h, w };

    if (!CanPlace(newBox.r, newBox.c, h, w))
        return;

    DropBox(newBox);
    MarkBox(newBox, id);
    boxes.push_back(newBox);
}

int GetRemainingBoxes()
{
    int cnt = 0;
    for (Box& box : boxes)
    {
        if (!box.isRemoved)
        {
            cnt++;
        }
    }
    return cnt;
}

bool CanExitLeft(const Box& b)
{
    for (int r = b.r; r < b.r + b.height; r++)
    {
        for (int c = 0; c < b.c; c++)
        {
            if (grid[r][c] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

bool CanExitRight(const Box& b)
{
    for (int r = b.r; r < b.r + b.height; r++)
    {
        for (int c = b.c + b.width; c < n; c++)
        {
            if (grid[r][c] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

int FindUnloadBox(bool isLeft)
{
    for (int i = 0; i < m; i++)
    {
        if (boxes[i].isRemoved)
            continue;

        Box& b = boxes[i];

        if (isLeft && CanExitLeft(b))
        {
            return i;
        }
        else if (!isLeft && CanExitRight(b))
        {
            return i;
        }
    }

    return -1;
}

void ApplyGravityAll()
{
    vector<int> aliveBoxes;
    for (int i = 0; i < boxes.size(); i++)
    {
        if (boxes[i].isRemoved)
            continue;

        aliveBoxes.push_back(i);
    }

    sort(aliveBoxes.begin(), aliveBoxes.end(), [](int a, int b)
    {
        return (boxes[a].r + boxes[a].height) > (boxes[b].r + boxes[b].height);
    });

    for (int idx : aliveBoxes)
    {
        MarkBox(boxes[idx], 0);
        DropBox(boxes[idx]);
        MarkBox(boxes[idx], boxes[idx].id);
    }
}

void UnloadAllBoxes()
{
    bool popFromLeft = true;
    
    while (GetRemainingBoxes() > 0)
    {
        int targetIdx = FindUnloadBox(popFromLeft);

        if (targetIdx != -1)
        {
            MarkBox(boxes[targetIdx], 0);
            boxes[targetIdx].isRemoved = true;

            cout << boxes[targetIdx].id << "\n";

            ApplyGravityAll();
        }

        popFromLeft = !popFromLeft;
    }
}

int main()
{
    cin >> n >> m;
    grid.resize(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        int k, h, w, c;
        cin >> k >> h >> w >> c;
        
        PushNewBox(k, h, w, --c);
    }

    sort(boxes.begin(), boxes.end(), [](Box& a, Box& b)
    {
        return a.id < b.id;
    });

    UnloadAllBoxes();

    return 0;
}