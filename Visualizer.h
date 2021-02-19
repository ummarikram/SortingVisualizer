#pragma once

bool StartVisualizing = false;
bool LeftMousePressed = false;
bool QuitApp = false;

class Visualizer
{

private:

    Node* Nodes;
    Point Cursor;
    Point Choices[6];
    int NodeCount;
    const int noOfChoices = 6;

public:

    Visualizer()
    {
        NodeCount = round(Screen_Width * 0.124);
        Nodes = new Node[NodeCount];

        for (int i = 0; i < NodeCount; i++)
        {
            Nodes[i].Position.x = 5;
            Nodes[i].Position.y = round(Screen_Height * 0.707);
        }

        SetChoice(0, "BUBBLE SORT",    Screen_Width * 0.12, Screen_Height * 0.20);
        SetChoice(1, "SELECTION SORT", Screen_Width * 0.42, Screen_Height * 0.20);
        SetChoice(2, "INSERTION SORT", Screen_Width * 0.74, Screen_Height * 0.20);
        SetChoice(3, "QUICK SORT",     Screen_Width * 0.27, Screen_Height * 0.44);
        SetChoice(4, "MERGE SORT",     Screen_Width * 0.61, Screen_Height * 0.44);
        SetChoice(5, "COCKTAIL SORT",  Screen_Width * 0.42, Screen_Height * 0.68);
    }

    void SetCursorPosition(GLFWwindow* window)
    {
        double X, Y;
        glfwGetCursorPos(window, &X, &Y);

        Cursor.x = X; Cursor.y = Y;
    }

    float GetCursorPositionX() const
    {
        return Cursor.x;
    }

    float GetCursorPositionY() const
    {
        return Cursor.y;
    }

    int GetNodesCount() const
    {
        return NodeCount;
    }

    void Copy(Node& Source, Node& Destination)
    {
        Destination.Position.x = Source.Position.x;
        Destination.Position.y = Source.Position.y;
        Destination.Value = Source.Value;
    }

    static void cursorPositionCallBack(GLFWwindow* window, double Xpos, double Ypos)
    {
        // For tracking Mouse Position
        //std::cout << "X : " << Xpos << " , Y : " << Ypos << std::endl;
    }

    bool CheckCollision(float Px, float Py, int& Index)
    {
        float ScaleFactor = float(Screen_Width) / float(1280);

        for (int itr = 0; itr < noOfChoices; itr++)
        {
            // if collides
            if (Px >= Choices[itr].x && Px <= Choices[itr].x + (Choices[itr].length * 14.5 * ScaleFactor)
                && Py >= Choices[itr].y - (20 * ScaleFactor) && Py <= Choices[itr].y)
            {
                Index = itr;
                return false;
            }
        }

        // else
        return true;
    }

    void DrawColorNodes(int index, float Red, float Green, float Blue) const
    {
        glColor4f(Red, Green, Blue, 1);
        glBegin(GL_QUADS);
        glVertex2f(Nodes[index].Position.x + (index * 8), Nodes[index].Position.y);
        glVertex2f(Nodes[index].Position.x + (index * 8), Nodes[index].Position.y - Nodes[index].Value * 10);
        glVertex2f(Nodes[index].Position.x + (index * 8) + 5, Nodes[index].Position.y - Nodes[index].Value * 10);
        glVertex2f(Nodes[index].Position.x + (index * 8) + 5, Nodes[index].Position.y);
        glEnd();
    }

    void DrawNodes()
    {
        for (int i = 0; i < NodeCount; i++)
        {
            // Gray Nodes
            DrawColorNodes(i, 0.6, 0.6, 0.6);
        }
    }

    void SetChoice(int Index, const char* Name, float x, float y)
    {
        Choices[Index].Add(x, y);
        Choices[Index].SetLength(strlen(Name));
    }

    void Swap(Node& A, Node& B)
    {
        Node Temp = A;
        A.Value = B.Value; A.Position.x = B.Position.x; A.Position.y = B.Position.y;
        B.Value = Temp.Value; B.Position.x = Temp.Position.x; B.Position.y = Temp.Position.y;
    }

    void DrawBubbleSort();

    void BubbleSortNodes();

    void DrawSelectionSort();

    void SelectionSortNodes();

    void DrawInsertionSort();

    void InsertionSortNodes();

    int DrawPartition(int low, int high);

    void DrawQuickSort(int low, int high);

    int Partition(int low, int high);

    void QuickSortNodes(int low, int high);

    int min(int x, int y) { return (x < y) ? x : y; }

    void DrawMergeSort(int RunCheckCurrSize, int RunCheckLeftStart);

    // Merge two subarrays L and M into arr
    void Merge(int p, int q, int r);

    // Divide the array into two subarrays, sort them and merge them
    void MergeSortNodes(int& RunCheckCurrSize, int& RunCheckLeftStart);

    // Sorts arrar a[0..n-1] using Cocktail sort 
    void CocktailSortNodes();

    void DrawCocktailSort();

    int Input(GLFWwindow* window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            QuitApp = true;
        }

        if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
        {
            StartVisualizing = true;
        }

        if (LeftMousePressed)
        {
            int Index;
            bool Collison = CheckCollision(Cursor.x, Cursor.y, Index);

            if (!Collison)
            {
                //std::cout << "Collison with Block : " << Index << std::endl;

                LeftMousePressed = false;
                return Index + 1;
            }
            else
            {
                LeftMousePressed = false;
            }
        }

        return 0;
    }

    static void mouseButtonCallBack(GLFWwindow* window, int Button, int action, int mods)
    {
        if (Button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        {
            LeftMousePressed = true;

        }

    }

};
