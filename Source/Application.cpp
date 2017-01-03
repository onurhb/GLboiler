
// ---------------- INCLUDES
#include <imgui.h>
#include "Application.h"
#include "Graphics/ImguiBinding.h"
// ----------------


Application::Application()
:window("Window", 1920 / 2, 1080 / 2)
{
    setup();
}

Application::~Application() {

}

/**
 * Sets up everything
 * @return Success / Unsuccess
 */
bool Application::setup() {
    shader.loadFromFile("shader.vert", "shader.frag");
    ImGui_ImplGlfwGL3_Init(window.getWindow(), true);
}

/**
 * Handling rendering here...
 */
void Application::render() const {
    ImGui_ImplGlfwGL3_NewFrame();
    ImGui::Begin("Widget");
    ImGui::Text("Hello World");
    ImGui::End();

    shader.bindShader();
    glBegin(GL_TRIANGLES);
        glVertex3f( 0.0f, 0.5f, 0.0f);
        glVertex3f(-0.5f,-0.5f, 0.0f);
        glVertex3f( 0.5f,-0.5f, 0.0f);
    glEnd();
    shader.unbindShader();
    ImGui::Render();
}

/**
 *  Will destroy application
 * @return Success / Unsuccess
 */
bool Application::clean(){
    ImGui_ImplGlfwGL3_Shutdown();
}

/**
 * When called, the application will run untill window has been closed or destroyed
 * @return Success / Unsuccess
 */
bool Application::start() {
    setup();
    while (!window.closed()) {
        window.clear();
        // - Render
        render();

        window.update();
    }
    clean();
}

