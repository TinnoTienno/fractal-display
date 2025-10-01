#ifndef MYAPP_HPP
#define MYAPP_HPP
#include "imgui.h"
#include "ShowWindows.hpp"

namespace myApp {
    void renderUI(ImGuiIO& io, ShowWindow &show_window);
    void ShowMainMenu(ImGuiIO& io, ShowWindow &show_window);
    void ShowFullscreen(ImGuiIO& io);
    void ShowPropertiesWindow(ImGuiIO& io);
    void ShowMovementsWindow(ImGuiIO& io);
    void ShowColorsetWindow(ImGuiIO& io);
    void ShowViewportWindow(ImGuiIO& io);
}

#endif