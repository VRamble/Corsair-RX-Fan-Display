#include "lighting_panel.hpp"
#include "button.hpp"
#include "label.hpp"

#include <SDL2/SDL_opengl.h>

LightingPanel::LightingPanel(int x, int y, int w, int h,
                             const std::string &executablePath)
    : Panel(x, y, w, h), executablePath(executablePath) {
    auto titleLabel = new Label(
        0, 0, "Lighting Type",
        executablePath + "/gui/assets/Saira-VariableFont_wdth,wght.ttf", 28);

    auto solidButton =
        new Button(0, 75, 60, 45, "Solid",
                   executablePath + "/gui/assets/solid.png", 16, 16);
    auto solidLabel = new Label(
        0, 125, "Solid",
        executablePath + "/gui/assets/Saira-VariableFont_wdth,wght.ttf", 20);

    solidButton->onClick = []() { printf("Solid lighting selected\n"); };

    auto gradientButton =
        new Button(75, 75, 60, 45, "Gradient",
                   executablePath + "/gui/assets/solid.png", 16, 16);
    auto gradientLabel = new Label(
        75, 125, "Gradient",
        executablePath + "/gui/assets/Saira-VariableFont_wdth,wght.ttf", 20);
    gradientButton->onClick = []() { printf("Gradient lighting selected\n"); };

    auto waveButton =
        new Button(0, 160, 60, 45, "Wave",
                   executablePath + "/gui/assets/waves-24.png", 16, 16);
    auto waveLabel = new Label(
        0, 210, "Wave",
        executablePath + "/gui/assets/Saira-VariableFont_wdth,wght.ttf", 20);

    waveButton->onClick = []() { printf("Wave lighting selected\n"); };

    auto textButton =
        new Button(75, 160, 60, 45, "Text",
                   executablePath + "/gui/assets/solid.png", 16, 16);
    auto textLabel = new Label(
        75, 210, "Text",
        executablePath + "/gui/assets/Saira-VariableFont_wdth,wght.ttf", 20);

    textButton->onClick = []() { printf("Text lighting selected\n"); };

    LightingPanel::add(titleLabel);
    LightingPanel::add(solidButton);
    LightingPanel::add(solidLabel);
    LightingPanel::add(gradientButton);
    LightingPanel::add(gradientLabel);
    LightingPanel::add(waveButton);
    LightingPanel::add(waveLabel);
    LightingPanel::add(textButton);
    LightingPanel::add(textLabel);
}
