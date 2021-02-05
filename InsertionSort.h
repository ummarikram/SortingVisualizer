#pragma once


void Visualizer::DrawInsertionSort()
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

void Visualizer::InsertionSortNodes()
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
