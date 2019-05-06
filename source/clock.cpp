//
// Created by Erika on 5/6/19.
//

#include "circle.hpp"
#include "vec2.hpp"
#include <cmath>
#include "window.hpp"



int main(int argc, char *argv[]) {
    Window win{std::make_pair(800, 800)};

    Circle clock = Circle(Vec2{250.0f, 250.0f}, 200.0f, Color{1.0f, 1.0f, 1.0f});
    Vec2 hours =   {250.0f, 250.0f};
    Vec2 minutes = {250.0f, 250.0f};
    Vec2 seconds = {250.0f, 250.0f};

    while (!win.should_close()) {

        auto time = win.get_time();

        int thour = time / 3600;
        int tminute = time /60;
        int tsecond = int (time) % 60;

        float angle = 2 * M_PI / 60;


        float anglehour = 0;

        for (int i = 1; i <= 12; i++) {
            win.draw_point(180.0f * cos(anglehour) + 250, 180.0f * sin(anglehour) + 250, 1.0f, 1.0f, 1.0f);
            int ptime = i + 2;
            if (ptime > 12)
            {
                ptime = ptime -12;

            }
            std::string num = std::to_string(ptime);
            win.draw_text(180.0f * cos(anglehour) + 250, 180.0f * sin(anglehour) + 250, 20, num);
            anglehour += 0.523599f;
        }


        std::string text = "Time passed since started program: " + std::to_string(thour) + " :  " + std::to_string(tminute) + " : " + std::to_string(tsecond) + " . ";
        win.draw_text(10.0f, 10.0f, 20, text);

        clock.draw(win, 2.0f);

        win.draw_line(seconds.x, seconds.y, 180.0f * cos(angle * (tsecond - 15)) + 250.0f, 180.0f * sin(angle * (tsecond - 15)) + 250.0f, 1.0f, 1.0f, 0.0f, 1.0f);
        win.draw_line(minutes.x, minutes.y, 150.0f * cos(angle * (tminute - 15)) + 250.0f, 150.0f * sin(angle * (tminute - 15)) + 250.0f, 1.0f, 0.0f, 1.0f, 1.0f);
        win.draw_line(hours.x, hours.y, 90.0f * cos(angle * 5 * (thour - 15)) + 250.0f, 90.0f * sin(angle * 5 * (thour - 15)) + 250.0f, 0.0f, 1.0f, 0.0f, 1.0f);
        win.draw_point(250.0f, 250.0f, 0.0f, 0.0f,0.0f);


        win.update();
    }

}