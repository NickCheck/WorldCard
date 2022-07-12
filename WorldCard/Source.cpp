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
    a.setTexture(card);
    a.setPosition(1400, 700);

    Image map_image;
    map_image.loadFromFile("1.png");
    Texture map_texture;
    map_texture.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map_texture);

    bool isMove = false;
    float dx = 0, dy = 0;

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
                    if ((pos.x >= 100 && pos.x <= 1500) && (pos.y >= 100 && pos.y <= 700))
                    {
                        a.setPosition(800, 500);
                    }
                }
            }
        }

        if (isMove) a.setPosition(pos.x - dx, pos.y - dy);

        window.clear();
        window.draw(s_map);
        window.draw(a);
        window.display();

    }
    //Hi
    return 0;
}