#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dr[] = { -1, 1, 0, 0 };
const int dc[] = { 0, 0, -1, 1 };

enum class Food
{
    None,

    Mint,
    Choco,
    Milk,
    ChocoMilk,
    MintMilk,
    MintChoco,
    MintChocoMilk
};

struct Student
{
    int r = 0, c = 0;
    Food food = Food::None;
    int b = 0;
    bool isDefend = false;
};
vector<vector<Student>> grid;

int n, t;
vector<Student> leader;

int GetFoodTier(Food f)
{
    if (f == Food::Mint || f == Food::Choco || f == Food::Milk)
        return 1;

    if (f == Food::MintChocoMilk)
        return 3;

    return 2;
}

Food CombineFood(Food a, Food b)
{
    bool hasMint = (a == Food::Mint || a == Food::MintMilk || a == Food::MintChoco || a == Food::MintChocoMilk) ||
        (b == Food::Mint || b == Food::MintMilk || b == Food::MintChoco || b == Food::MintChocoMilk);
    bool hasChoco = (a == Food::Choco || a == Food::ChocoMilk || a == Food::MintChoco || a == Food::MintChocoMilk) ||
        (b == Food::Choco || b == Food::ChocoMilk || b == Food::MintChoco || b == Food::MintChocoMilk);
    bool hasMilk = (a == Food::Milk || a == Food::ChocoMilk || a == Food::MintMilk || a == Food::MintChocoMilk) ||
        (b == Food::Milk || b == Food::ChocoMilk || b == Food::MintMilk || b == Food::MintChocoMilk);

    if (hasMint && hasChoco && hasMilk) return Food::MintChocoMilk;
    if (hasMint && hasChoco) return Food::MintChoco;
    if (hasMint && hasMilk) return Food::MintMilk;
    if (hasChoco && hasMilk) return Food::ChocoMilk;
    if (hasMint) return Food::Mint;
    if (hasChoco) return Food::Choco;
    if (hasMilk) return Food::Milk;
    return Food::None;
}

void Morning()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grid[i][j].b++;
            grid[i][j].isDefend = false;
        }
    }
}

void Lunch()
{
    leader.clear();

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (visited[i][j])
                continue;

            vector<Student> group;
            queue<pair<int, int>> q;
            
            q.push({ i, j });
            visited[i][j] = true;
            group.push_back(grid[i][j]);

            while (!q.empty())
            {
                auto [cr, cc] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nr = cr + dr[i];
                    int nc = cc + dc[i];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                        continue;

                    if (visited[nr][nc])
                        continue;

                    if (grid[cr][cc].food != grid[nr][nc].food)
                        continue;

                    q.push({ nr, nc });
                    visited[nr][nc] = true;
                    group.push_back(grid[nr][nc]);
                }
            }

            sort(group.begin(), group.end(), [](const Student& a, const Student& b)
            {
                if (a.b != b.b)
                    return a.b > b.b;  // b 내림차순

                if (a.r != b.r)
                    return a.r < b.r;  // r 오름차순

                return a.c < b.c;      // c 오름차순
            });

            int sz = static_cast<int>(group.size());
            for (int i = 0; i < sz; i++)
            {
                int gr = group[i].r;
                int gc = group[i].c;

                if (i == 0)
                {
                    grid[gr][gc].b += sz - 1;
                }
                else
                {
                    grid[gr][gc].b -= 1;
                }
            }

            leader.push_back(grid[group[0].r][group[0].c]);
        }
    }
}

void Dinner()
{
    sort(leader.begin(), leader.end(), [](const Student& a, const Student& b)
    {
        int tierA = GetFoodTier(a.food);
        int tierB = GetFoodTier(b.food);
        if (tierA != tierB)
            return tierA < tierB;

        if (a.b != b.b)
            return a.b > b.b;

        if (a.r != b.r)
            return a.r < b.r;

        return a.c < b.c;
    });

    for (auto& lead : leader)
    {
        // 다른 대표자에게 전파당해 방어 상태가 된 대표자는 오늘 전파 불가
        if (grid[lead.r][lead.c].isDefend)
            continue;

        Food leadFood = grid[lead.r][lead.c].food;
        int originB = grid[lead.r][lead.c].b;

        int x = originB - 1;
        grid[lead.r][lead.c].b = 1;

        if (x <= 0)
            continue;
        
        int dir = originB % 4;

        int cr = lead.r;
        int cc = lead.c;

        while (true)
        {
            cr += dr[dir];
            cc += dc[dir];

            if (cr < 0 || cr >= n || cc < 0 || cc >= n)
                break;

            if (grid[cr][cc].food == leadFood)
                continue;

            grid[cr][cc].isDefend = true;
            int y = grid[cr][cc].b;

            if (x > y)
            {
                // 강한 전파
                grid[cr][cc].food = leadFood;
                x -= (y + 1);
                grid[cr][cc].b += 1;

                if (x <= 0)
                    break;
            }
            else
            {
                // 약한 전파
                grid[cr][cc].food = CombineFood(grid[cr][cc].food, leadFood);
                grid[cr][cc].b += x;
                x = 0;
                break;
            }
        }
    }
}

int Sum(Food f)
{
    int bSum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j].food == f)
            {
                bSum += grid[i][j].b;
            }
        }
    }

    return bSum;
}

int main()
{
    cin >> n >> t;
    grid.resize(n, vector<Student>(n));
    
    for (int i = 0; i < n; i++)
    {
        string f;
        cin >> f;

        for (int j = 0; j < n; j++)
        {
            grid[i][j].r = i;
            grid[i][j].c = j;

            if (f[j] == 'T')
            {
                grid[i][j].food = Food::Mint;
            }
            else if (f[j] == 'C')
            {
                grid[i][j].food = Food::Choco;
            }
            else if (f[j] == 'M')
            {
                grid[i][j].food = Food::Milk;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j].b;
        }
    }

    for (int i = 0; i < t; i++)
    {
        Morning();

        Lunch();

        Dinner();
        
        cout << Sum(Food::MintChocoMilk) << " "
             << Sum(Food::MintChoco) << " "
             << Sum(Food::MintMilk) << " "
             << Sum(Food::ChocoMilk) << " "
             << Sum(Food::Milk) << " "
             << Sum(Food::Choco) << " "
             << Sum(Food::Mint) << "\n";
    }

    return 0;
}