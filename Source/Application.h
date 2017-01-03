#ifndef PROJECT_APPLICATION_H
#define PROJECT_APPLICATION_H

// --------------- INCLUDES
#include "Graphics/Window.h"
#include "Graphics/Shader.h"
// ---------------
class Application {

    Window window;
    Shader shader;

public:
    Application();
    ~Application();
    bool start();

private:
    bool setup();
    bool clean();
    void render() const;
};


#endif //PROJECT_APPLICATION_H
