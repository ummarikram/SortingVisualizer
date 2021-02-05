#pragma once

void Visualizer::DrawSelectionSort()
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

void Visualizer::SelectionSortNodes()
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
