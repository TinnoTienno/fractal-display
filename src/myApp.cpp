#include "myApp.hpp"
#include "imgui.h"
#include "ShowWindows.hpp"
#include <iostream>
#include "imgui_internal.h"

namespace myApp{
    void ShowFullscreen(ImGuiIO& io)
    {
        (void) io;
    }
    void ShowPropertiesWindow(ImGuiIO& io)
    {
        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
        ImGuiViewportP* viewport = (ImGuiViewportP*)(void*)ImGui::GetMainViewport();

        ImGui::SetCurrentViewport(NULL, viewport);
        ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x, main_viewport->WorkPos.y + 19), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowSize(ImVec2(150, ImGui::GetFrameHeight() - 19), ImGuiCond_FirstUseEver);
        ImGui::Begin("properties");
        // const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
        // ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + 650, main_viewport->WorkPos.y + 20), ImGuiCond_FirstUseEver);
        // ImGui::SetNextWindowSize(ImVec2(550, 680), ImGuiCond_FirstUseEver);
        ImGui::Text("%1.f FPS - %.3fms/frame", io.Framerate, 1000.0f / io.Framerate);
        ImGui::End();
    }
    void ShowMovementsWindow(ImGuiIO& io)
    {
        ImGui::Begin("Movements");

        ImGui::End();
    }
    void ShowColorsetWindow(ImGuiIO& io)
    {
        ImGui::Begin("Color Set");
        ImGui::End();
    }
    void ShowViewportWindow(ImGuiIO& io)
    {
        ImGui::Begin("ViewPort");
        ImGui::End();
    }

    void resetWindowProperties(ImGuiIO& io, const char *name)
    {
        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
        ImGui::SetWindowPos(name, ImVec2(main_viewport->WorkPos.x + 650, main_viewport->WorkPos.y + 20), ImGuiCond_None);
        ImGui::SetWindowSize(name, ImVec2(550, 680), ImGuiCond_None);
    }
    
    void ShowMainMenu(ImGuiIO& io, ShowWindow &show_window){
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("Panels"))
            {
                if (ImGui::MenuItem("Properties", NULL, &show_window.show_properties_window))
                    resetWindowProperties(io, "Properties");
                ImGui::MenuItem("Color Set", NULL, &show_window.show_colorset_window);
                ImGui::MenuItem("Movements", NULL, &show_window.show_movements_window);
                ImGui::MenuItem("ViewPort", NULL, &show_window.show_viewport_window);
                if (ImGui::MenuItem("Full-Screen", "F11"))
                    show_window.show_fullscreen = !show_window.show_fullscreen;
                ImGui::EndMenu();
            }
        }
        ImGui::EndMainMenuBar();
    }
    void renderUI(ImGuiIO& io, ShowWindow &show_window){
        ShowMainMenu(io, show_window);
        if (show_window.show_fullscreen)
            ShowFullscreen(io);
        else{
            if (show_window.show_properties_window)
                ShowPropertiesWindow(io);
            if (show_window.show_movements_window)
                ShowMovementsWindow(io);
            if (show_window.show_colorset_window)
                ShowColorsetWindow(io);
            if (show_window.show_viewport_window)
                ShowViewportWindow(io);
        }
    }
}