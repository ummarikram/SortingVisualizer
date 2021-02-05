#pragma once

int Visualizer::DrawPartition(int low, int high)
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

void Visualizer::DrawQuickSort(int low, int high)
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

int Visualizer::Partition(int low, int high) {
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

void Visualizer::QuickSortNodes(int low, int high)
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