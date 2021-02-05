#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <time.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include "GLInit.h"
#include "Text-Rendering.h"
#include "Shapes.h"
#include "HoverEffect.h"
#include "Visualizer.h"
#include "Algorithms.h"

int main(int argc, char** argv)
{
    GLFWwindow* window;

    // Random time seed generator
    srand(time(NULL));

    // Create a window   
    GLInit(window);

    // Initialize GLEW
    GLenum err = glewInit();

    // if error in GLEW
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }

    // Start window at center
    glfwSetWindowPos(window, Screen_Width / 20, Screen_Height / 20);

    // Create sorting visualizer object
    Visualizer Sorting;

    // Sorting algorithm choice
    int Choice = 0;

    // Set up mouse inputs  
    glfwSetCursorPosCallback(window, Sorting.cursorPositionCallBack);
    glfwSetMouseButtonCallback(window, Sorting.mouseButtonCallBack);

    // Shader reading
    Shader shader("Shaders/vs.shader", "Shaders/fs.shader");

    // Binding shader with text
    BindText(shader);

    // Loop until choice is selected OR window is not closed
    while (Choice == 0 && !glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // White Background
        glClearColor(1, 1, 1, 0);

        // To draw
        glLoadIdentity();
        glOrtho(0, 1280, 720, 0, 100, -100);

        // Store mouse positions
        Sorting.SetCursorPosition(window);

        // Get Choice
        Choice = Sorting.Input(window);

        int HoverBlock;
        bool isHovering = Sorting.CheckCollision(Sorting.GetCursorPositionX(), Sorting.GetCursorPositionY(), HoverBlock);

        // Play hover effect on rendered text if any.
        CheckHover(shader, HoverBlock, isHovering);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);


        /* Poll for and process events */
        glfwPollEvents();


    }

    // Destroy window
    glfwDestroyWindow(window);

    // if any choice was selected
    if (Choice != 0)
    {
        // Initialize new window
        GLInit(window);

        // Start window at center
        glfwSetWindowPos(window, Screen_Width / 20, Screen_Height / 20);

        // Variables for slowing down merge sort inorder to visualize it
        int RunCheckCurrSize = 1, RunCheckLeftStart = 0;

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            // White Background
            glClearColor(1, 1, 1, 0);

            // To draw
            glLoadIdentity();
            glOrtho(0, 1280, 720, 0, 100, -100);

            // Draw unsorted nodes
            Sorting.DrawNodes();

            // Get input of 'Enter' inorder to start visualizing
            Sorting.Input(window);

            // To track time between renders
            double currentTime = glfwGetTime();
            frameCount++;

            // if 'Enter' Key is pressed
            if (StartVisualizing)
            {
                // Draw according to choosed algorithm
                if (Choice == 1)
                {
                    Sorting.DrawBubbleSort();
                }

                else if (Choice == 2)
                {
                    Sorting.DrawSelectionSort();
                }

                else if (Choice == 3)
                {
                    Sorting.DrawInsertionSort();
                }

                else if (Choice == 4)
                {
                    Sorting.DrawQuickSort(0, Sorting.GetNodesCount() - 1);
                }

                else if (Choice == 5)
                {
                    Sorting.DrawMergeSort(RunCheckCurrSize, RunCheckLeftStart);
                }

                else if (Choice == 6)
                {
                    Sorting.DrawCocktailSort();
                }

                // Display FPS
                FPSDisplay(window, "Sorting Visualizer", frameCount, previousFPSTime, currentTime);

                // If 0.01 second has passed. For animation purpose
                if (Delay(0.02, previousDelayTime, currentTime))
                {
                    // Sort nodes according to choosed algorithm
                    if (Choice == 1)
                    {
                        Sorting.BubbleSortNodes();
                    }

                    else if (Choice == 2)
                    {
                        Sorting.SelectionSortNodes();
                    }

                    else if (Choice == 3)
                    {
                        Sorting.InsertionSortNodes();
                    }

                    else if (Choice == 4)
                    {
                        Sorting.QuickSortNodes(0, Sorting.GetNodesCount() - 1);
                    }

                    else if (Choice == 5)
                    {
                        Sorting.MergeSortNodes(RunCheckCurrSize, RunCheckLeftStart);
                    }

                    else if (Choice == 6)
                    {
                        Sorting.CocktailSortNodes();
                    }

                }

            }

            /* Swap front and back buffers */
            glfwSwapBuffers(window);


            /* Poll for and process events */
            glfwPollEvents();
        }

        glfwTerminate();
    }

    return 0;
}