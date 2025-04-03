// library
#include <SFML/Graphics.hpp>


// main program
int main()
{
    // create window
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Title", sf::State::Windowed, settings);

    // create shape
    sf::ConvexShape shape;
    shape.setFillColor(sf::Color(128, 213, 255));
    shape.setOutlineColor(sf::Color(0, 170, 255));
    shape.setOutlineThickness(20.f);
    shape.setPosition({400.f, 300.f});

    // set points
    int   n      = 8 * 6;
    float radius = 200.f;
    float angle  = 360.f / n;
    shape.setPointCount(n);
    for (int i = 0;  i < n;  i++)
    {
        if ((i + 1) % 6 < 3)
            shape.setPoint(i, sf::Vector2f(radius, sf::degrees(i*angle - 90.f)));
        else
            shape.setPoint(i, sf::Vector2f(radius*0.7f, sf::degrees(i*angle - 90.f)));
    }


    // while window is still open
    while (window.isOpen())
    {
        // handle events
        while (std::optional event = window.pollEvent())
        {
            // when close button is clicked
            if (event->is<sf::Event::Closed>())
            {
                // close window
                window.close();
            }
            // when window is resized
            else if (event->is<sf::Event::Resized>())
            {
                // update view
                sf::View view(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                window.setView(view);
            }
        }

        // fill window with color
        window.clear(sf::Color(64, 64, 64));

        // draw
        window.draw(shape);

        // display
        window.display();
    }

    
    // program end successfully
    return 0;
}