#pragma once

int Get_Width() { return glfwGetVideoMode(glfwGetPrimaryMonitor())->width; }
int Get_Height() { return glfwGetVideoMode(glfwGetPrimaryMonitor())->height; }

#define Screen_Width Get_Width()
#define Screen_Height Get_Height()

// For FPS & Delay
double previousDelayTime = glfwGetTime();
double PrevDelayMergeSortTime = glfwGetTime();
double previousFPSTime = glfwGetTime();
int frameCount = 0;

int GLInit(GLFWwindow*& window)
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(Screen_Width, Screen_Height, "Sorting Visualizer", glfwGetPrimaryMonitor(), NULL);

    // if error
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
}

// For displaying frames per second
void FPSDisplay(GLFWwindow*& window, std::string AppName, int& FrameCount, double& PreviousTime, double& CurrentTime)
{
    // if 1 second has passed
    if (CurrentTime - PreviousTime >= 1.0)
    {
        std::string Title = AppName + " | FPS : " + std::to_string(FrameCount);
        
        // Display it as window title
        glfwSetWindowTitle(window, Title.c_str());

        // Reset values
        FrameCount = 0;
        PreviousTime = CurrentTime;
    }
}

// Function to delay animation speed
bool Delay(float time, double& PreviousTime, double& CurrentTime)
{
    if (CurrentTime - PreviousTime >= time)
    {
        PreviousTime = CurrentTime;
        return true;
    }
    else
    {
        return false;
    }
}
