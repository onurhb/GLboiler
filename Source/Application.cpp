
// ---------------- INCLUDES
#include "Application.h"
// ----------------


Application::Application()
:window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT)
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
}

/**
 * Handling rendering here...
 */
void Application::render() const {
    shader.bindShader();
    glBegin(GL_TRIANGLES);
        glVertex3f( 0.0f, 0.5f, 0.0f);
        glVertex3f(-0.5f,-0.5f, 0.0f);
        glVertex3f( 0.5f,-0.5f, 0.0f);
    glEnd();
    shader.unbindShader();
}

/**
 *  Will destroy application
 * @return Success / Unsuccess
 */
bool Application::clean(){
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

