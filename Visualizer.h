#pragma once

bool StartVisualizing = false;
bool LeftMousePressed = false;

class Visualizer
{

private:

    Node* Nodes;
    Point Cursor;
    Point Choices[5];
    int NodeCount;
    const int noOfChoices = 5;

public:

    Visualizer()
    {
        NodeCount = 159;
        Nodes = new Node[NodeCount];

        for (int i = 0; i < NodeCount; i++)
        {
            Nodes[i].Position.x = 5;
            Nodes[i].Position.y = Screen_Height - 5;
        }

        SetChoice(0, "BUBBLE SORT", 150.0f, 720 - 570);
        SetChoice(1, "SELECTION SORT", 540.0f, 720 - 570);
        SetChoice(2, "INSERTION SORT", 950.0f, 720 - 570);
        SetChoice(3, "QUICK SORT", 350.0f, 720 - 400);
        SetChoice(4, "MERGE SORT", 780.0f, 720 - 400);
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
        for (int itr = 0; itr < noOfChoices; itr++)
        {
            // if collides
            if (Px >= Choices[itr].x && Px <= Choices[itr].x + Choices[itr].length * 15
                && Py >= Choices[itr].y - 20 && Py <= Choices[itr].y)
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

    void DrawBubbleSort()
    {
        for (int i = 0; i < NodeCount; i++)
        {
            bool FoundUnsort = false;

            for (int j = 0; j < NodeCount - i - 1; j++)
            {
                if (Nodes[j].Value > Nodes[j + 1].Value)
                {

                    DrawColorNodes(j, 1, 0, 0);

                    DrawColorNodes(j + 1, 1, 0, 0);

                    FoundUnsort = true;

                }

                else
                {
                    DrawColorNodes(j, 0, 1, 0);

                    DrawColorNodes(j + 1, 0, 1, 0);

                }
            }

            if (FoundUnsort)
            {
                break;
            }
        }

    }

    void BubbleSortNodes()
    {
        for (int i = 0; i < NodeCount; i++)
        {
            bool StepDone = false;

            for (int j = 0; j < NodeCount - i - 1; j++)
            {
                if (Nodes[j].Value > Nodes[j + 1].Value)
                {
                    Swap(Nodes[j], Nodes[j + 1]);

                    StepDone = true;

                }

            }

            if (StepDone)
            {
                break;
            }
        }

    }

    void DrawSelectionSort()
    {
        int min_idx;

        // One by one move boundary of unsorted subarray  
        for (int i = 0; i < NodeCount; i++)
        {
            // Find the minimum element in unsorted array  
            min_idx = i;

            for (int j = i + 1; j < NodeCount; j++)
            {
                if (Nodes[j].Value < Nodes[min_idx].Value)
                {
                    DrawColorNodes(min_idx, 1, 0, 0);

                    min_idx = j;

                    DrawColorNodes(j, 1, 0, 0);

                }
            }

            if (min_idx != i)
            {
                DrawColorNodes(i, 1, 0, 0);

                DrawColorNodes(min_idx, 1, 0, 0);

                break;

            }

            else
            {
                DrawColorNodes(i, 0, 1, 0);

            }

        }
    }

    void SelectionSortNodes()
    {
        int min_idx;

        // One by one move boundary of unsorted subarray  
        for (int i = 0; i < NodeCount - 1; i++)
        {
            // Find the minimum element in unsorted array  
            min_idx = i;

            for (int j = i + 1; j < NodeCount; j++)
            {
                if (Nodes[j].Value < Nodes[min_idx].Value)
                {
                    min_idx = j;
                }

            }

            if (min_idx != i)
            {
                Swap(Nodes[min_idx], Nodes[i]);
                break;
            }


        }
    }

    void DrawInsertionSort()
    {
        for (int i = 1; i < NodeCount; i++)
        {
            Node key = Nodes[i];

            int j = i - 1;

            while (key.Value < Nodes[j].Value && j >= 0)
            {
                --j;
            }

            if (j == i - 1 || j == 0)
            {
                DrawColorNodes(j + 1, 0, 1, 0);

                DrawColorNodes(j, 0, 1, 0);

            }

            else if (j != i - 1)
            {
                DrawColorNodes(j, 1, 0, 0);

                DrawColorNodes(i, 1, 0, 0);

                break;
            }

        }
    }

    void InsertionSortNodes()
    {
        for (int i = 1; i < NodeCount; i++)
        {
            Node key = Nodes[i];
            int j = i - 1;

            // Compare key with each element on the left of it until an element smaller than
            // it is found.
            // For descending order, change key<array[j] to key>array[j].
            while (key.Value < Nodes[j].Value && j >= 0)
            {
                Nodes[j + 1].Value = Nodes[j].Value;
                Nodes[j + 1].Position.x = Nodes[j].Position.x;
                Nodes[j + 1].Position.y = Nodes[j].Position.y;
                --j;
            }

            Nodes[j + 1].Value = key.Value;
            Nodes[j + 1].Position.x = key.Position.x;
            Nodes[j + 1].Position.y = key.Position.y;

            if (j != i - 1)
            {
                break;
            }


        }
    }

    int DrawPartition(int low, int high)
    {
        // Select the pivot element
        int pivot = Nodes[high].Value;

        int i = (low - 1);

        // Put the elements smaller than pivot on the left 
        // and greater than pivot on the right of pivot
        for (int j = low; j < high; j++)
        {
            if (Nodes[j].Value <= pivot)
            {
                i++;

                DrawColorNodes(j, 1, 0, 0);

                DrawColorNodes(i, 1, 0, 0);

                if (i == 0)
                {
                    DrawColorNodes(i, 0, 1, 0);
                }

            }
            else
            {
                DrawColorNodes(j, 0, 1, 0);

                DrawColorNodes(i, 0, 1, 0);

                break;
            }
        }

        if (high != i + 1)
        {
            DrawColorNodes(high, 1, 0, 0);

            DrawColorNodes(i + 1, 1, 0, 0);

        }
        else
        {
            DrawColorNodes(high, 0, 1, 0);
        }

        return (i + 1);
    }

    void DrawQuickSort(int low, int high)
    {
        if (low < high) {
            // Select pivot position and put all the elements smaller 
            // than pivot on left and greater than pivot on right
            int pi = DrawPartition(low, high);

            // Sort the elements on the left of pivot
            DrawQuickSort(low, pi - 1);

            // Sort the elements on the right of pivot
            DrawQuickSort(pi + 1, high);
        }
    }

    int Partition(int low, int high) {
        // Select the pivot element
        int pivot = Nodes[high].Value;

        int i = (low - 1);

        // Put the elements smaller than pivot on the left 
        // and greater than pivot on the right of pivot
        for (int j = low; j < high; j++)
        {
            if (Nodes[j].Value <= pivot)
            {
                i++;
                Swap(Nodes[i], Nodes[j]);
            }
            else
            {
                break;
            }
        }

        if (high != i + 1)
        {
            Swap(Nodes[i + 1], Nodes[high]);
        }

        return (i + 1);
    }

    void QuickSortNodes(int low, int high)
    {
        if (low < high) {
            // Select pivot position and put all the elements smaller 
            // than pivot on left and greater than pivot on right
            int pi = Partition(low, high);

            // Sort the elements on the left of pivot
            QuickSortNodes(low, pi - 1);

            // Sort the elements on the right of pivot
            QuickSortNodes(pi + 1, high);
        }
    }

    int min(int x, int y) { return (x < y) ? x : y; }

    void DrawMergeSort(int RunCheckCurrSize, int RunCheckLeftStart)
    {
        int curr_size;  // For current size of subarrays to be merged 
                    // curr_size varies from 1 to n/2 
        int left_start; // For picking starting index of left subarray 
                        // to be merged 

        if (RunCheckCurrSize > NodeCount - 1)
        {
            for (int i = 0; i < NodeCount; i++)
            {
                DrawColorNodes(i, 0, 1, 0);
            }
        }

        else
        {

            // Merge subarrays in bottom up manner.  First merge subarrays of 
            // size 1 to create sorted subarrays of size 2, then merge subarrays 
            // of size 2 to create sorted subarrays of size 4, and so on. 
            for (curr_size = RunCheckCurrSize; curr_size <= NodeCount - 1; curr_size = 2 * curr_size)
            {
                // Pick starting point of different subarrays of current size 
                for (left_start = RunCheckLeftStart; left_start < NodeCount - 1; left_start += 2 * curr_size)
                {
                    // Find ending point of left subarray. mid+1 is starting  
                    // point of right 
                    int mid = min(left_start + curr_size - 1, NodeCount - 1);

                    int right_end = min(left_start + 2 * curr_size - 1, NodeCount - 1);

                    // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end] 
                    
                    for (int i = 0; i < NodeCount; i++)
                    {
                        if ((i >= left_start && i <= mid) || (i >= mid + 2 && i <= right_end))
                        {
                            DrawColorNodes(i, 0, 1, 0);
                        }
                        else
                        {
                            DrawColorNodes(i, 1, 0, 0);
                        }
                    }

                    break;

                }

                
                break;

            }

        }

    }

    // Merge two subarrays L and M into arr
    void Merge(int p, int q, int r) 
    {
        // Create L ← A[p..q] and M ← A[q+1..r]
        int n1 = q - p + 1;
        int n2 = r - q;

        Node* L = new Node[n1];
        Node* M = new Node[n2];

        for (int i = 0; i < n1; i++)
        {
            Copy(Nodes[p + i], L[i]);
            
        }
        for (int j = 0; j < n2; j++)
        {
            Copy(Nodes[q + 1 + j], M[j]);
        }

        // Maintain current index of sub-arrays and main array
        int i, j, k;
        i = 0;
        j = 0;
        k = p;

        // Until we reach either end of either L or M, pick larger among
        // elements L and M and place them in the correct position at A[p..r]
        while (i < n1 && j < n2)
        {
           
            if (L[i].Value <= M[j].Value)
            {
                Copy(L[i], Nodes[k]);

                i++;

            }

            else
            {
                Copy(M[j], Nodes[k]);

                j++;

            }

            k++;

           
        }

        // When we run out of elements in either L or M,
        // pick up the remaining elements and put in A[p..r]
        while (i < n1) 
        {
            Copy(L[i], Nodes[k]);
            i++;
            k++;
        }

        while (j < n2) 
        {
            Copy(M[j], Nodes[k]);
            j++;
            k++;
        }

        delete[] L; delete[] M;
    }

    // Divide the array into two subarrays, sort them and merge them
    void MergeSortNodes(int& RunCheckCurrSize, int& RunCheckLeftStart)
    {
        int curr_size;  // For current size of subarrays to be merged 
                        // curr_size varies from 1 to n/2 
        int left_start; // For picking starting index of left subarray 
                        // to be merged 


        // Merge subarrays in bottom up manner.  First merge subarrays of 
        // size 1 to create sorted subarrays of size 2, then merge subarrays 
        // of size 2 to create sorted subarrays of size 4, and so on. 
        for (curr_size = RunCheckCurrSize; curr_size <= NodeCount - 1; curr_size = 2 * curr_size)
        {
            // Pick starting point of different subarrays of current size 
            for (left_start = RunCheckLeftStart; left_start < NodeCount - 1; left_start += 2 * curr_size)
            {
                // Find ending point of left subarray. mid+1 is starting  
                // point of right 
                int mid = min(left_start + curr_size - 1, NodeCount - 1);

                int right_end = min(left_start + 2 * curr_size - 1, NodeCount - 1);

                // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end] 
                Merge(left_start, mid, right_end);

                RunCheckLeftStart = left_start + 2 * curr_size;

                break;

            }

            if (RunCheckLeftStart >= NodeCount - 1)
            {
                RunCheckCurrSize = 2 * curr_size;
                RunCheckLeftStart = 0;
            }
            
            break;

        }

    }

    int Input(GLFWwindow* window)
    {
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
