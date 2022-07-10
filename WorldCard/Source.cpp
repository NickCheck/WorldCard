#include<GLFW/glfw3.h>
#include<SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1920, 1080), "WorldCard");

    Texture card;
    card.loadFromFile("card.png");

    Sprite a(card);

    bool isMove = false;
    float dx = 0, dy = 0;

    a.setPosition(500, 500);

    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window);


        Event b;
        while (window.pollEvent(b))
        {
            if (b.type == Event::Closed)
            {
                window.close();
            }

            if (b.type == Event::MouseButtonPressed)
            {
                if (b.key.code == Mouse::Left)
                {
                    if (a.getGlobalBounds().contains(pos.x, pos.y))
                    {
                        isMove = true;
                        dx = pos.x - a.getPosition().x;
                        dy = pos.y - a.getPosition().y;
                    }
                }
            }

            if (b.type == Event::MouseButtonReleased)
            {
                if (b.key.code == Mouse::Left)
                {
                    isMove = false;
                    cout << pos.x << '\n' << pos.y << '\n';
                    if ((pos.x >= 100 && pos.x <= 900) && (pos.y >= 100 && pos.y <= 500))
                    {
                        a.setPosition(400, 280);
                    }
                }
            }
        }

        if (isMove) a.setPosition(pos.x - dx, pos.y - dy);

        window.clear();
        window.draw(a);
        window.display();

    }

    return 0;
}