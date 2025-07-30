#include "button.hpp"
#include "widget.hpp"
#include <SDL2/SDL_opengl.h>

Button::Button(int x, int y, int w, int h, const std::string &text)
    : Widget(x, y, w, h), text(text) {}

Button::Button(int x, int y, int w, int h, const std::string &text, float red,
               float green, float blue)
    : Widget(x, y, w, h), text(text) {}

Button::Button(int x, int y, int w, int h, const std::string &text,
               const std::string &iconPath, int iconWidth, int iconHeight)
    : Widget(x, y, w, h), text(text), iconWidth(iconWidth),
      iconHeight(iconHeight) {
    loadIcon(iconPath);
}

void Button::render() {

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor3f(red, green, blue);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    if (iconTexture) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, iconTexture);
        glColor3f(1.0f, 1.0f, 1.0f);

        float iconX = x + 10;
        float iconY = y + 10;

        glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex2f(iconX, iconY);
        glTexCoord2f(1, 0);
        glVertex2f(iconX + iconWidth, iconY);
        glTexCoord2f(1, 1);
        glVertex2f(iconX + iconWidth, iconY + iconHeight);
        glTexCoord2f(0, 1);
        glVertex2f(iconX, iconY + iconHeight);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void Button::handleEvent(const SDL_Event &e) {
    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
        int mx = e.button.x;
        int my = e.button.y;
        printf("Button clicked at (%d, %d)\n", mx, my);
        if (mx >= x && mx < x + width && my >= y && my < y + height) {
            printf("Button contains click at (%d, %d)\n", mx, my);
            if (onClick) {
                onClick();
            }
        }
    }
}

void Button::loadIcon(const std::string &iconPath) {
    int n;
    unsigned char *icon =
        stbi_load(iconPath.c_str(), &iconWidth, &iconHeight, &n, 4);
    if (icon) {
        glGenTextures(1, &iconTexture);
        glBindTexture(GL_TEXTURE_2D, iconTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, iconWidth, iconHeight, 0,
                     GL_RGBA, GL_UNSIGNED_BYTE, icon);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        stbi_image_free(icon);
    } else {
        printf("could not load icon\n");
    }
}
